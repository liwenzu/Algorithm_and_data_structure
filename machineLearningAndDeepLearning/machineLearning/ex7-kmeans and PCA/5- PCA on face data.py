import matplotlib.pyplot as plt
import seaborn as sns
sns.set(context="notebook", style="white")
import numpy as np
import pandas as pd
import scipy.io as sio
from sklearn.decomposition import PCA

# support functions
def plot_n_image(X, n):
    pic_size = int(np.sqrt(X.shape[1]))
    grid_size = int(np.sqrt(n))

    first_n_images = X[:n, :]

    fig, ax_array = plt.subplots(nrows=grid_size, ncols=grid_size,
                                    sharey=True, sharex=True, figsize=(8, 8))

    for r in range(grid_size):
        for c in range(grid_size):
            ax_array[r, c].imshow(first_n_images[grid_size * r + c].reshape((pic_size, pic_size)))
            plt.xticks(np.array([]))
            plt.yticks(np.array([]))

# PCA functions ---------------------------------------
def covariance_matrix(X):
    m = X.shape[0]

    return (X.T @ X) / m

def normalize(X):
    X_copy = X.copy()
    m, n = X_copy.shape

    for col in range(n):
        X_copy[:, col] = (X_copy[:, col] - X_copy[:, col].mean()) / X_copy[:, col].std()

    return X_copy

def pca(X):
    # 1. normalize data
    X_norm = normalize(X)

    # 2. calculate covariance matrix
    Sigma = covariance_matrix(X_norm)  # (n, n)

    # 3. do singular value decomposition
    # remeber, we feed cov matrix in SVD, since the cov matrix is symmetry
    # left sigular vector and right singular vector is the same, which means
    # U is V, so we could use either one to do dim reduction
    U, S, V = np.linalg.svd(Sigma)  # U: principle components (n, n)

    return U, S, V

def project_data(X, U, k):
    m, n = X.shape

    if k > n:
        raise ValueError('k should be lower dimension of n')

    return X @ U[:, :k]

def recover_data(Z, U):
    m, n = Z.shape

    if n >= U.shape[0]:
        raise ValueError('Z dimension is >= U, you should recover from lower dimension to higher')

    return Z @ U[:, :n].T

def loadData():
    mat = sio.loadmat('./data/ex7faces.mat')
    X = np.array([x.reshape((32, 32)).T.reshape(1024) for x in mat.get('X')])
    return X

def main():
    X = loadData()

    # plot_n_image(X, n=64)
    # plt.show()

    U, _, _ = pca(X)
    # print(U.shape)

    # plot_n_image(U, n=36)
    # plt.show()

    Z = project_data(X, U, k = 900)
    # print(Z.shape)
    # plot_n_image(Z, n =64)
    # plt.show()

    # recover from k=100
    X_recover = recover_data(Z, U)
    plot_n_image(X_recover, n=64)
    plt.show()





    # print(mat.get('X').shape)


# main()

def sklPCA():
    X = loadData()
    sk_pca = PCA(n_components=100)
    Z = sk_pca.fit_transform(X)

    # 降维后的图片打印
    # plot_n_image(Z, 64)
    # plt.show()

    X_recover = sk_pca.inverse_transform(Z)
    
    # 还原后的图片打印
    plot_n_image(X_recover, n=64)
    plt.show()
    

sklPCA()