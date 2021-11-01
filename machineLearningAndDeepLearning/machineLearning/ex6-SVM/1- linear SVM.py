import numpy as np
import pandas as pd
import sklearn.svm 
import seaborn as sns
import scipy.io as sio
import matplotlib.pyplot as plt

def main():
    mat = sio.loadmat('./data/ex6data1.mat')
    # print(mat.keys())
    data = pd.DataFrame(mat.get('X'), columns=['X1', 'X2'])
    data['y'] = mat.get('y')
    # print(data)

    # 可视化
    # fig, ax = plt.subplots(figsize=(8,6))
    # ax.scatter(data['X1'], data['X2'], s=50, c=data['y'], cmap='Reds')
    # ax.set_title('Raw data')
    # ax.set_xlabel('X1')
    # ax.set_ylabel('X2')
    # plt.show()

    # 尝试c=1
    svc1 = sklearn.svm.LinearSVC(C=1, loss='hinge')
    svc1.fit(data[['X1', 'X2']], data['y'])
    cost = svc1.score(data[['X1', 'X2']], data['y'])
    print("C为1时的最小代价函数", cost)

    data['SVM1 Confidence'] = svc1.decision_function(data[['X1', 'X2']])

    # fig, ax = plt.subplots(figsize=(8,6))
    # ax.scatter(data['X1'], data['X2'], s=50, c=data['SVM1 Confidence'], cmap='RdBu')
    # ax.set_title('SVM (C=1) Decision Confidence')
    # plt.show()

    # 尝试c=100
    svc100 = sklearn.svm.LinearSVC(C=100, loss='hinge')
    svc100.fit(data[['X1', 'X2']], data['y'])
    cost1 = svc100.score(data[['X1', 'X2']], data['y'])
    print("C为100时的代价函数:", cost1)

    data['SVM100 Confidence'] = svc100.decision_function(data[['X1', 'X2']])

    # fig, ax = plt.subplots(figsize=(8,6))
    # ax.scatter(data['X1'], data['X2'], s=50, c=data['SVM100 Confidence'], cmap='RdBu')
    # ax.set_title('SVM (C=100) Decision Confidence')
    # plt.show()

    print(data)
    
main()