import matplotlib.pyplot as plt
from scipy.sparse import compressed
import seaborn as sns 
import numpy as np
import pandas as pd
from skimage import data, io
from sklearn.cluster import KMeans

def k_means(data, k, epoch=100, n_init=10):
    tries = np.array([_k_means_iter(data, k, epoch) for _ in range(n_init)])
    least_cost_idx = np.argmin(tries[:, -1])
    return tries[least_cost_idx]

# support fn
def combine_data_C(data, C):
    data_with_c = data.copy()
    data_with_c['C'] = C
    return data_with_c

# k-means fn
def random_init(data, k):
    return data.sample(k).values

def _find_your_cluster(x, centroids):
    distances = np.apply_along_axis(func1d=np.linalg.norm,
                                    axis=1,
                                    arr=centroids-x)
    return np.argmin(distances)

def assign_cluster(data, centroids):
    return np.apply_along_axis(lambda x: _find_your_cluster(x, centroids),
                               axis=1,
                               arr=data.values)

def new_centroids(data, C):
    data_with_c = combine_data_C(data, C)

    return data_with_c.groupby('C', as_index=False).\
                       mean().\
                       sort_values(by='C').\
                       drop('C', axis=1).\
                       values

def cost(data, centroids, C):
    m = data.shape[0]
    expand_C_with_centroids = centroids[C]
    distances = np.apply_along_axis(func1d=np.linalg.norm,
                                    axis=1,
                                    arr=data.values - expand_C_with_centroids)
    return distances.sum()/m

def _k_means_iter(data, k, epoch=100, tol=0.0001):
    centroids = random_init(data, k)
    cost_progress = []

    for i in range(epoch):
        print('running epoch {}'.format(i))

        C = assign_cluster(data, centroids)
        centroids = new_centroids(data, C)
        cost_progress.append(cost(data, centroids, C))

        if len(cost_progress) > 1:  # early break
            if (np.abs(cost_progress[-1] - cost_progress[-2])) / cost_progress[-1] < tol:
                break

    return C, centroids, cost_progress[-1]





 


def main():
    pic = io.imread('data/bird_small.png')/255
    
    data = pic.reshape(128*128, 3)

    # C, centroids, cost = k_means(pd.DataFrame(data), 16, epoch=10, n_init=3)

    model = KMeans(n_clusters=16, n_init=100, n_jobs=-1)
    model.fit(data)
    centroids = model.cluster_centers_

    # print(centroids.shape)
    C = model.predict(data)
    
    # print(centroids[C])
    compressed_pic = centroids[C].reshape((128, 128, 3))

    fig, ax = plt.subplots(1,2)
    ax[0].imshow(pic)
    ax[1].imshow(compressed_pic)
    plt.show()

    

    



    # print(pic.shape)
    # print(io.imshow(pic))


main()
