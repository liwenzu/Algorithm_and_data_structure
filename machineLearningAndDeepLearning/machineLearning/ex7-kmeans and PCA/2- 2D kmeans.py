import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import pandas as pd
import scipy.io as sio

# 随机初始化
def combine_data_C(data, C):
    data_with_c = data.copy()
    data_with_c['C'] = C
    return data_with_c


# k-means fn --------------------------------
def random_init(data, k):
    """choose k sample from data set as init centroids
    Args:
        data: DataFrame
        k: int
    Returns:
        k samples: ndarray
    """
    return data.sample(k).values


def _find_your_cluster(x, centroids):
    """find the right cluster for x with respect to shortest distance
    Args:
        x: ndarray (n, ) -> n features
        centroids: ndarray (k, n)
    Returns:
        k: int
    """
    distances = np.apply_along_axis(func1d=np.linalg.norm,  # this give you l2 norm
                                    axis=1,
                                    arr=centroids - x)  # use ndarray's broadcast
    return np.argmin(distances)


def assign_cluster(data, centroids):
    """assign cluster for each node in data
    return C ndarray
    """
    return np.apply_along_axis(lambda x: _find_your_cluster(x, centroids),
                               axis=1,
                               arr=data.values)


def new_centroids(data, C):
    data_with_c = combine_data_C(data, C)

    return data_with_c.groupby('C', as_index=False).\
                       mean().\
                       sort_values(by='C').\
                       drop('C', axis=1).\
                       as_matrix()


def cost(data, centroids, C):
    m = data.shape[0]

    expand_C_with_centroids = centroids[C]

    distances = np.apply_along_axis(func1d=np.linalg.norm,
                                    axis=1,
                                    arr=data.values - expand_C_with_centroids)
    return distances.sum() / m


def _k_means_iter(data, k, epoch=100, tol=0.0001):
    """one shot k-means
    with early break
    """
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


def k_means(data, k, epoch=100, n_init=10):
    """do multiple random init and pick the best one to return
    Args:
        data (pd.DataFrame)
    Returns:
        (C, centroids, least_cost)
    """

    tries = np.array([_k_means_iter(data, k, epoch) for _ in range(n_init)])

    least_cost_idx = np.argmin(tries[:, -1])

    return tries[least_cost_idx]

def main():
    mat = sio.loadmat('./data/ex7data2.mat')

    data2 = pd.DataFrame(mat.get('X'), columns=['X1', 'X2'])

    # sns.set(context="notebook", style="white")
    # sns.lmplot('X1', 'X2', data=data2, fit_reg=False)
    # plt.show()

    # print(data2)

    # random_init(data2, 3)

    init_centroids = random_init(data2, 3)
    # print(init_centroids)

    x = np.array([1,1])

    # fig, ax = plt.subplots(figsize=(6,4))
    # ax.scatter(x=init_centroids[:,0], y=init_centroids[:,1])

    # for i, node in enumerate(init_centroids):
    #     ax.annotate('{}: ({},{})'.format(i, node[0], node[1]), node)
    # ax.scatter(x[0], x[1], marker='x', s=200)
    # plt.show()

    _find_your_cluster(x, init_centroids)

    C = assign_cluster(data2, init_centroids)
    data_with_c = combine_data_C(data2, C)

    # print(data_with_c)

    sns.lmplot('X1', 'X2', hue='C', data=data_with_c, fit_reg=False)
    plt.show()


    # 2. calculate new centroid


main()