from math import cos
import numpy as np
from numpy.lib.function_base import insert
import scipy.io as sio
import scipy.optimize as opt
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

def load_data():
    d = sio.loadmat('ex5data1.mat')
    return map(np.ravel, [d['X'], d['y'], d['Xval'], d['yval'], d['Xtest'], d['ytest']])

def cost(theta, X, y):
    m = X.shape[0]
    
    inner = X@theta -y
    square_sum = inner.T@inner
    cost = square_sum/(2*m)
    return cost

def regularized_cost(theta, X, y, la=1):
    m = X.shape[0]
    regularized_term = (la/(2*m))*np.power(theta[1:], 2).sum()

    # print(cost(theta, X, y) + regularized_term)
    return cost(theta, X, y) + regularized_term


def gradient(theta, X, y):
    m = X.shape[0]
    inner = X.T@(X@theta-y)
    return inner/m

def regularized_gradient(theta, X, y, la=1):
    m = X.shape[0]

    regularized_ter = theta.copy()
    regularized_ter[0] = 0

    regularized_ter = (la/m)*regularized_ter
    return gradient(theta, X, y) + regularized_ter

# 拟合数据
def linear_regression_np(X, y, la=1):
    theta = np.ones(X.shape[1])
    res = opt.minimize(fun=regularized_cost, x0=theta, args=(X, y, la),  method='TNC', jac=regularized_gradient, options={'disp': True})
    return res

# 创建多项式特征
def prepare_poly_data(*args, power):
    """
    args: keep feeding in X, Xval, or Xtest
        will return in the same order
    """
    def prepare(x):
        # expand feature
        df = poly_features(x, power=power)

        # normalization
        ndarr = normalize_feature(df).to_numpy()
        # ndarr = df.to_numpy()

        # add intercept term
        return np.insert(ndarr, 0, np.ones(ndarr.shape[0]), axis=1)

    return [prepare(x) for x in args]

def poly_features(x, power, as_ndarray=False):
    data = {'f{}'.format(i): np.power(x, i) for i in range(1, power + 1)}
    df = pd.DataFrame(data)

    return df.to_numpy() if as_ndarray else df

def normalize_feature(df):
    """Applies function along input axis(default 0) of DataFrame."""
    return df.apply(lambda column: (column - column.mean()) / column.std())   

def plot_learning_curve(X, y, Xval, yval, la=0):
    training_cost, cv_cost = [], []
    m = X.shape[0]

    for i in range(1, m + 1):
        # regularization applies here for fitting parameters
        res = linear_regression_np(X[:i, :], y[:i], la)

        # remember, when you compute the cost here, you are computing
        # non-regularized cost. Regularization is used to fit parameters only
        tc = cost(res.x, X[:i, :], y[:i])
        cv = cost(res.x, Xval, yval)

        training_cost.append(tc)
        cv_cost.append(cv)

    plt.plot(np.arange(1, m + 1), training_cost, label='training cost')
    plt.plot(np.arange(1, m + 1), cv_cost, label='cv cost')
    plt.legend(loc=1)

def main():
    X, y, Xval, yval, Xtest, ytest = load_data()

    # df = pd.DataFrame({'water_level':X, 'flow':y})

    # sns.lmplot('water_level', 'flow', data=df, fit_reg=False, size=7)
    # plt.show()

    # X, Xval, Xtest = [np.insert(x.reshape(x.shape[0],1), 0, np.ones(x.shape[0]), axis=1) for x in (X, Xval, Xtest)]

    # theta = np.ones(X.shape[1])

    # print(cost(theta, X, y))
    # print(gradient(theta, X, y))
    # print(regularized_gradient(theta, X, y))

    # final_theta = linear_regression_np(X, y, 0).get('x')

    # b = final_theta[0]
    # m = final_theta[1]

    # plt.scatter(X[:,1], y, label = "Training data")
    # plt.plot(X[:,1], X[:,1]*m + b, label = "Prediction")
    # plt.legend(loc=2)
    # plt.show()

    # 使用训练集的子集拟合数据
    # training_cost, cv_cost = [], []
    # m = X.shape[0]
    # for i in range(1, m+1):
    #     res = linear_regression_np(X[:i,:], y[:i], 0)

    #     tc = regularized_cost(res.x, X[:i,:], y[:i], 0)
    #     cv = regularized_cost(res.x, Xval, yval,0)
    #     training_cost.append(tc)
    #     cv_cost.append(cv)
    
    # # 画图观察
    # plt.plot(np.arange(1,m+1), training_cost, label='training cost')
    # plt.plot(np.arange(1,m+1), cv_cost, label='cv cost')
    # plt.legend(loc=1)
    # plt.show()
    
    # print(poly_features(X, 2))
    X_poly, Xval_poly, Xtest_poly = prepare_poly_data(X, Xval, Xtest, power=8)

    # print(X_poly[:3,:])

    # plot_learning_curve(X_poly, y, Xval_poly, yval, 100)
    # plt.show() 

    # plot_learning_curve(X_poly, y, Xval_poly, yval, 1)
    # plt.show()  


    # print(X_poly)

    l_candidate = [0, 0.001, 0.003, 0.01, 0.03, 0.1, 0.3, 1, 3, 10]
    training_cost, cv_cost = [], []

    for l in l_candidate:
        res = linear_regression_np(X_poly, y, l)
        
        tc = cost(res.x, X_poly, y)
        cv = cost(res.x, Xval_poly, yval)
        
        training_cost.append(tc)
        cv_cost.append(cv)

    plt.plot(l_candidate, training_cost, label='training')
    plt.plot(l_candidate, cv_cost, label='cross validation')
    plt.legend(loc=2)

    plt.xlabel('lambda')

    plt.ylabel('cost')
    plt.show()

    print(l_candidate[np.argmin(cv_cost)])
    
    for l in l_candidate:
        theta = linear_regression_np(X_poly, y, l).x
        print('******************************************************')
        print('test cost(l={}) = {}'.format(l, cost(theta, Xtest_poly, ytest)))


main()