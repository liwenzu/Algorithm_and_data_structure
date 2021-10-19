import matplotlib.pyplot as plt
import numpy as np
import scipy.io as sio
import matplotlib
import scipy.optimize as opt
from sklearn.metrics import classification_report

def load_weight(path):
    data = sio.loadmat(path)
    return data['Theta1'], data['Theta2']

def load_data(path, trans = True):
    data = sio.loadmat(path)
    y = data.get('y')
    y = y.reshape(y.shape[0])
    X = data.get('X')
    if trans:
        X = np.array([im.reshape((20, 20)).T for im in X])
        X = np.array([im.reshape(400) for im in X])
    return X, y 

def sigmoid(z):
    return 1 / (1 + np.exp(-z))


def main():
    # 初始的权重值theta
    theta1, theta2 = load_weight('ex3weights.mat')
    X, y = load_data('ex3data1.mat', False)
    X = np.insert(X, 0, values=np.ones(X.shape[0]), axis = 1)

    a1 = X
    z2 = a1@theta1.T

    # z2 = np.insert(z2, 0, values=np.ones(z2.shape[0]), axis=1)

    a2 = sigmoid(z2)    

    a2 = np.insert(a2, 0, values=np.ones(a2.shape[0]), axis = 1) 

    z3 = a2@theta2.T

    a3 = sigmoid(z3)

    y_pred = np.argmax(a3, axis=1) + 1

    print(classification_report(y, y_pred))

    # print(theta1.shape, theta2.shape)

main()