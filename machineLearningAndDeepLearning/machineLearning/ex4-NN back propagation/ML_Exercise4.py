import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.io import loadmat
from sklearn.preprocessing import OneHotEncoder
from scipy.optimize import minimize
from sklearn.metrics import classification_report

def sigmoid(z):
    return 1/(1+np.exp(-z))

# 前向传播
def forward_propagate(X, theta1, theta2):
    m = X.shape[0]

    a1 = np.insert(X, 0, values=np.ones(m), axis=1)
    z2 = a1*theta1.T
    a2 = sigmoid(z2)
    a2 = np.insert(a2, 0, values=np.ones(m), axis=1)
    z3 = a2*theta2.T
    h = sigmoid(z3)

    return a1, z2, a2, z3, h

# 代价函数，不带正则项
def cost(params, input_size, hidden_size, num_labels, X, y, learning_rate):
    m = X.shape[0]
    X = np.matrix(X)
    y = np.matrix(y)

    theta1 = np.matrix(np.reshape(params[:hidden_size*(input_size+1)], (hidden_size, (input_size+1))))
    theta2 = np.matrix(np.reshape(params[hidden_size*(input_size+1):], (num_labels, (hidden_size+1))))

    a1, z2, a2, z3, h = forward_propagate(X, theta1, theta2)

    # 计算代价函数
    J = 0
    for i in range(m):
        first_term = np.multiply(-y[i,:], np.log(h[i,:]))
        second_term = np.multiply((1-y[i,:]), np.log(1-h[i,:]))
        J += np.sum(first_term - second_term)
    J = J/m

    J+=(float(learning_rate)/(2*m))*(np.sum(np.power(theta1[:,1:], 2)) + np.sum(np.power(theta2[:,1:], 2)))

    return J

# Sigmoid函数的梯度的函数
def sigmoid_gradient(z):
    return np.multiply(sigmoid(z), 1-sigmoid(z))

 # 反向传播
def backprop(params, input_size, hidden_size, num_labels, X, y, learning_rate):
    m = X.shape[0]
    X = np.matrix(X)
    y = np.matrix(y)

    theta1 = np.matrix(np.reshape(params[:hidden_size * (input_size + 1)], (hidden_size, (input_size + 1))))
    theta2 = np.matrix(np.reshape(params[hidden_size * (input_size + 1):], (num_labels, (hidden_size + 1))))

    a1, z2, a2, z3, h = forward_propagate(X, theta1, theta2)

    J = 0
    delta1 = np.zeros(theta1.shape)
    delta2 = np.zeros(theta2.shape)

    # 计算代价
    for i in range(m):
        first_term = np.multiply(-y[i,:], np.log(h[i,:]))
        second_term = np.multiply((1-y[i,:]), np.log(1-h[i,:]))
        J+=np.sum(first_term-second_term)
    J = J/m
    J += (float(learning_rate) / (2 * m)) * (np.sum(np.power(theta1[:,1:], 2)) + np.sum(np.power(theta2[:,1:], 2)))

    # 执行反向传播
    for t in range(m):
        alt = a1[t,:]
        z2t = z2[t,:]
        a2t = a2[t,:]
        ht = h[t,:]
        yt = y[t,:]

        d3t = ht - yt

        z2t = np.insert(z2t, 0, values=np.ones(1))
        d2t = np.multiply((theta2.T*d3t.T).T, sigmoid_gradient(z2t))

        delta1 = delta1 + (d2t[:,1:]).T*alt
        delta2 = delta2 + d3t.T*a2t
    delta1 = delta1/m
    delta2 = delta2/m

    delta1[:,1:] = delta1[:,1:] + (theta1[:,1:]*learning_rate)/m
    delta2[:,1:] = delta2[:,1:] + (theta2[:,1:]*learning_rate)/m
    grad = np.concatenate((np.ravel(delta1), np.ravel(delta2)))

    print(J)

    return J, grad


def main():
    data = loadmat('ex4data1')
    X = data['X']
    y = data['y']
    # 对y进行编码
    encoder = OneHotEncoder(sparse=False)
    y_onehot = encoder.fit_transform(y)


    # 初始化设置
    input_size = 400
    hidden_size = 25
    num_labels = 10
    learning_rate = 1
    # 随机初始化完整网络参数大小的参数数组
    params = (np.random.random(size=hidden_size * (input_size + 1) + num_labels * (hidden_size + 1)) - 0.5) * 0.25
    m = X.shape[0]
    X = np.matrix(X)
    y = np.matrix(y)
    # theta1 = np.matrix(np.reshape(params[:hidden_size*(input_size+1)], (hidden_size, (input_size+1))))
    # theta2 = np.matrix(np.reshape(params[hidden_size*(input_size+1):], (num_labels, (hidden_size+1))))
    # a1, z2, a2, z3, h = forward_propagate(X, theta1, theta2)
    # 打印代价函数
    # print(cost(params, input_size, hidden_size, num_labels, X, y_onehot, learning_rate))

    # J, grad = backprop(params, input_size, hidden_size, num_labels, X, y_onehot, learning_rate)

    # print(J, grad.shape)


    fmin = minimize(fun=backprop, x0=params, args=(input_size, hidden_size, num_labels, X, y_onehot, learning_rate), method='TNC', jac=True, options={'maxiter': 400})

    X = np.matrix(X)
    theta1 = np.matrix(np.reshape(fmin.x[:hidden_size * (input_size + 1)], (hidden_size, (input_size + 1))))
    theta2 = np.matrix(np.reshape(fmin.x[hidden_size * (input_size + 1):], (num_labels, (hidden_size + 1))))

    a1, z2, a2, z3, h = forward_propagate(X, theta1, theta2)
    y_pred = np.array(np.argmax(h, axis=1) + 1)

    correct = [1 if a == b else 0 for (a, b) in zip(y_pred, y)]
    accuracy = (sum(map(int, correct)) / float(len(correct)))
    print ('accuracy = {0}%'.format(accuracy * 100))
    print(fmin.fun)




    # # 打印统计信息
    # print(classification_report(y_pred, y))

main()