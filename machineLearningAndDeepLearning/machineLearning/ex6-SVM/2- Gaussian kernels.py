from math import cos, gamma
import matplotlib.pyplot as plt
from pandas.io.formats import style
from seaborn import palettes
from sklearn import svm
import numpy as np
import pandas as pd
import seaborn as sns
import scipy.io as sio

def gaussian_kernel(x1, x2, sigma):
    return np.exp(-np.power(x1-x2, 2).sum()/(2*(sigma**2)))

def main():
    # x1 = np.array([1, 2, 1])
    # x2 = np.array([0, 4, -1])
    sigma = 2

    # print(gaussian_kernel(x1, x2, sigma))
    # print(np.exp(-9/8))

    mat = sio.loadmat('./data/ex6data2.mat')
    data = pd.DataFrame(mat.get('X'), columns=['X1', 'X2'])
    data['y'] = mat.get('y')
    # print(data.shape)

    # 可视化
    # sns.set(context="notebook", style="white", palette=sns.diverging_palette(240, 10, n=2))
    # sns.lmplot('X1', 'X2', hue='y', data=data, 
    #        size=5, 
    #        fit_reg=False, 
    #        scatter_kws={"s": 10}
    #       )
    # plt.show()

    # 创建高斯核函数(内置)
    svc = svm.SVC(C=100, kernel='rbf', gamma=10, probability=True)
    svc.fit(data[['X1', 'X2']], data['y'])
    cost = svc.score(data[['X1', 'X2']], data['y'])

    # print(cost)

    predict_prob = svc.predict_proba(data[['X1', 'X2']])[:,0]

    fig, ax = plt.subplots(figsize=(8,6))
    ax.scatter(data['X1'], data['X2'], s=50, c=predict_prob, cmap='Reds')
    plt.show()
    
main()