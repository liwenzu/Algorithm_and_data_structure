import matplotlib.pyplot as plt
import seaborn as sns
sns.set(context="notebook", style="white")
import numpy as np
import pandas as pd
import scipy.io as sio

def get_X(df):
    ones = pd.DataFrame({'ones':np.ones(len(df))})
    data = pd.concat([ones, df], axis=1)
    return data.iloc[:,:-1].values

def get_y(df):
    return np.array(df.iloc[:,-1])

def normalize_feature(df):
    return df.apply(lambda column: (column - column.mean()) / column.std())

# normalize data
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

# PCA functions
def covariance_matrix(X):
    m = X.shape[0]
    return (X.T@X)/m

def normalize(X):
    X_copy = X.copy()
    m, n = X_copy.shape
    for col in range(n):
        X_copy[:, col] = (X_copy[:, col] - X_copy[:, col].mean()) / X_copy[:, col].std()
    return X_copy

def pca(X):
    # 1. normalize data
    X_norm = normalize(X)
    # 2. 协方差矩阵
    Sigma = covariance_matrix(X_norm)  # (n, n)
    # 3. 做信号值分解
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

def main():
    mat = sio.loadmat('./data/ex7data1.mat')

    X = mat.get('X')

    # sns.lmplot('X1', 'X2', data=pd.DataFrame(X, columns=['X1', 'X2']),
    #             fit_reg=False)
    # plt.show()

    X_norm = normalize(X)

    # 正则化后的数据
    # sns.lmplot('X1', 'X2', 
    #             data=pd.DataFrame(X_norm, columns=['X1', 'X2']),
    #             fit_reg= False)
    # plt.show()

    U, S, V = pca(X_norm)
    # 得到一维的值
    Z = project_data(X_norm, U, 1)

    # fig, (ax1, ax2) = plt.subplots(ncols=2, figsize=(12, 4))

    # sns.regplot('X1', 'X2', 
    #         data=pd.DataFrame(X_norm, columns=['X1', 'X2']),
    #         fit_reg=False,
    #         ax=ax1)
    # ax1.set_title('Original dimension')

    # sns.rugplot(data=Z, ax=ax2)
    # ax2.set_xlabel('Z')
    # ax2.set_title('Z dimension')
    # plt.show()

    # recover data to original dimension
    X_recover = recover_data(Z, U)


    fig, (ax1, ax2, ax3) = plt.subplots(ncols=3, figsize=(12, 4))


    sns.rugplot(data=Z, ax=ax1)
    ax1.set_title('Z dimension')
    ax1.set_xlabel('Z')

    sns.regplot('X1', 'X2', 
            data=pd.DataFrame(X_recover, columns=['X1', 'X2']),
            fit_reg=False,
            ax=ax2)
    ax2.set_title("2D projection from Z")

    sns.regplot('X1', 'X2', 
            data=pd.DataFrame(X_norm, columns=['X1', 'X2']),
            fit_reg=False,
            ax=ax3)
    ax3.set_title('Original dimension')
    plt.show()


    # print(X.shape)

main()

