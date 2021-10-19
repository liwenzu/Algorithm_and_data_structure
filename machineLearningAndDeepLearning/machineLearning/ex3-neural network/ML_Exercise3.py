from os import error
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.io import loadmat
from scipy.optimize import minimize


# 激活函数
def sigmoid(z):
    return 1 / (1+np.exp(-z))

# 代价函数
def cost(theta, X, y, learningRate):
    theta = np.matrix(theta)
    X = np.matrix(X)
    y = np.matrix(y)
    first = np.multiply(-y, np.log(sigmoid(X*theta.T)))
    second = np.multiply((1-y), np.log(1-sigmoid(X*theta.T)))
    reg = ((learningRate)/(2*len(X)))*np.sum(np.power(theta[:,1:theta.shape[1]], 2))
    return np.sum(first - second)/len(X) + reg

# 使用for循环进行梯度下降(不考虑批次, 只求梯度)
def gradient_with_loop(theta, X, y, learningRate):
    theta = np.matrix(theta)
    X = np.matrix(X)
    y = np.matrix(y)

    pa = int(theta.ravel().shape[1])
    grad = np.zeros(pa)

    error = sigmoid(X*theta.T)-y

    for i in range(pa):
        term = np.multiply(error, X[:,i])
        
        if i == 0:
            grad[i] = np.sum(term)/len(X)
        else:
            grad[i] = np.sum(term)/len(X) + ((learningRate/len(X)*theta[:,i]))
    return grad

# 向量化的梯度函数
def gradient(theta, X, y, learningRate):
    theta = np.matrix(theta)
    X = np.matrix(X)
    y = np.matrix(y)

    pa = int(theta.ravel().shape[1])
    error = sigmoid(X*theta.T) - y

    grad = ((X.T*error)/len(X)).T + ((learningRate/len(X))*theta)
    grad[0, 0] = np.sum(np.multiply(error, X[:,0]))/len(X)
    return np.array(grad).ravel()

# 一对全分类器
def one_vs_all(X, y, num_labels, learning_rate):
    rows = X.shape[0]
    pa = X.shape[1]

    all_theta = np.zeros((num_labels, pa+1))

    X = np.insert(X, 0, values=np.ones(rows), axis=1)

    for i in range(1, num_labels+1):
        theta = np.zeros(pa+1)
        y_i = np.array([1 if label == i else 0 for label in y])
        y_i = np.reshape(y_i, (rows, 1))

        fmin = minimize(fun=cost, x0=theta, args=(X, y_i, learning_rate), method='TNC', jac=gradient)
        all_theta[i-1,:] = fmin.x
    return all_theta

# 预测函数
def predict_all(X, all_theta):
    rows = X.shape[0]
    pa = X.shape[1]
    num_labels = all_theta.shape[0]
    X = np.insert(X, 0, values=np.ones(rows), axis=1)
    X = np.matrix(X)
    all_theta = np.matrix(all_theta)
    h = sigmoid(X*all_theta.T)
    # 取出概率最大的值在数组中的编号
    h_argmax = np.argmax(h, axis=1)
    h_argmax = h_argmax + 1
    return h_argmax

def main():
    data = loadmat('ex3data1.mat')
    # print(data['X'].shape, data['y'].shape)
    # print(data)
    # 维度测试代码
    rows = data['X'].shape[0]
    pa = data['X'].shape[1]
    all_theta = np.zeros((10, pa +1))
    # X = np.insert(data['X'], 0, values=np.ones(rows), axis=1)
    # theta = np.zeros(pa+1)
    # y_0 = np.array([1 if label == 0 else 0 for label in data['y']])
    # y_0 = np.reshape(y_0, (rows, 1))
    all_theta = one_vs_all(data['X'], data['y'], 10, 1)
    # print(all_theta[0])
    # print(np.unique(data['y']))
    y_pred = predict_all(data['X'], all_theta)
    correct = [1 if a==b else 0 for(a,b) in zip(y_pred, data['y'])]
    accuracy = (sum(map(int, correct))) /float(len(correct))
    print('accuracy = {0}%'.format(accuracy*100))

    # print(correct)

    # 打印错误预测的数字
    # for a,b in zip(y_pred, data['y']):
    #     if a != b:
    #         print("{0}:{1}".format(a,b))
    


# main()