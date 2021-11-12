# 异常检测
import matplotlib.pyplot as plt
import seaborn as sb
sb.set(context="notebook", style="white", palette=sb.color_palette("RdBu"))

import numpy as np
import pandas as pd
import scipy.io as sio
from scipy import stats

def estimate_gaussian(X):
    mu = X.mean(axis=0)
    sigma = X.var(axis=0)
    return mu, sigma

# 选阈值
def select_threshold(pval, yval):
    best_epsilon = 0
    best_f1 = 0
    f1 = 0

    step = (pval.max()-pval.min())/1000

    for epsilon in np.arange(pval.min(), pval.max(), step):
        preds = pval < epsilon

        tp = np.sum(np.logical_and(preds == 1, yval == 1)).astype(float)
        fp = np.sum(np.logical_and(preds == 1, yval == 0)).astype(float)
        fn = np.sum(np.logical_and(preds == 0, yval == 1)).astype(float)
        
        precision = tp / (tp + fp)
        recall = tp / (tp + fn)
        f1 = (2 * precision * recall) / (precision + recall)
        
        if f1 > best_f1:
            best_f1 = f1
            best_epsilon = epsilon
    
    return best_epsilon, best_f1



def main():
    data = sio.loadmat('data/ex8data1.mat')

    X = data['X']

    # 打印数据点
    # fig, ax = plt.subplots(figsize=(12, 8))
    # ax.scatter(X[:,0], X[:,1])
    # plt.show()

    mu, sigma = estimate_gaussian(X)

    # print(mu)
    # print(sigma)

    Xval = data['Xval']
    yval = data['yval']

    # dist = stats.norm(mu[0], sigma[0])
    # print(dist.pdf(X[:,0]))
    p = np.zeros((X.shape[0], X.shape[1]))
    p[:,0] = stats.norm(mu[0], sigma[0]).pdf(X[:,0])
    p[:,1] = stats.norm(mu[1], sigma[1]).pdf(X[:,1])

    pval = np.zeros((Xval.shape[0], Xval.shape[1]))
    pval[:,0] = stats.norm(mu[0], sigma[0]).pdf(Xval[:,0])
    pval[:,1] = stats.norm(mu[1], sigma[1]).pdf(Xval[:,1])

    epsilon, f1 = select_threshold(pval, yval)

    # print(epsilon, f1)
    outliers = np.where(p<epsilon)
    # print(outliers)
    fig, ax = plt.subplots(figsize=(12, 8))
    ax.scatter(X[:,0], X[:, 1])
    ax.scatter(X[outliers[0], 0], X[outliers[0], 1], s=50, color='b', marker='o')
    plt.show()


    # print(X.shape)

# main()

# 推荐系统
# def cost(params, Y, R, num_features):
#     Y = np.matrix(Y)  # (1682, 943)
#     R = np.matrix(R)  # (1682, 943)
#     num_movies = Y.shape[0]
#     num_users = Y.shape[1]
    
#     # reshape the parameter array into parameter matrices
#     X = np.matrix(np.reshape(params[:num_movies * num_features], (num_movies, num_features)))  # (1682, 10)
#     Theta = np.matrix(np.reshape(params[num_movies * num_features:], (num_users, num_features)))  # (943, 10)
    
#     # initializations
#     J = 0
    
#     # compute the cost
#     error = np.multiply((X * Theta.T) - Y, R)  # (1682, 943)
#     squared_error = np.power(error, 2)  # (1682, 943)
#     J = (1. / 2) * np.sum(squared_error)
    
#     return J

# 实现梯度下降
def cost(params, Y, R, num_features, learning_rate):
    Y = np.matrix(Y)  # (1682, 943)
    R = np.matrix(R)  # (1682, 943)
    num_movies = Y.shape[0]
    num_users = Y.shape[1]
    
    # reshape the parameter array into parameter matrices
    X = np.matrix(np.reshape(params[:num_movies * num_features], (num_movies, num_features)))  # (1682, 10)
    Theta = np.matrix(np.reshape(params[num_movies * num_features:], (num_users, num_features)))  # (943, 10)
    
    # initializations
    J = 0
    X_grad = np.zeros(X.shape)  # (1682, 10)
    Theta_grad = np.zeros(Theta.shape)  # (943, 10)
    
    # compute the cost
    error = np.multiply((X * Theta.T) - Y, R)  # (1682, 943)
    squared_error = np.power(error, 2)  # (1682, 943)
    J = (1. / 2) * np.sum(squared_error)
    
    # add the cost regularization
    J = J + ((learning_rate / 2) * np.sum(np.power(Theta, 2)))
    J = J + ((learning_rate / 2) * np.sum(np.power(X, 2)))
    
    # calculate the gradients with regularization
    X_grad = (error * Theta) + (learning_rate * X)
    Theta_grad = (error.T * X) + (learning_rate * Theta)
    
    # unravel the gradient matrices into a single array
    grad = np.concatenate((np.ravel(X_grad), np.ravel(Theta_grad)))
    
    return J, grad

# 协同过略
def filter():
    data = sio.loadmat('data/ex8_movies.mat')

    # print(data)
    Y = data['Y']
    R = data['R']

    # print(Y.shape, R.shape)
    Y[1, np.where(R[1,:]==1)[0]].mean()

    # print(Y[1, np.where(R[1,:]==1)[0]].mean())

    # 数据可视化
    # fig, ax = plt.subplots(figsize=(12, 12))
    # ax.imshow(Y)
    # ax.set_xlabel('Users')
    # ax.set_ylabel('Movies')
    # fig.tight_layout()
    # plt.show()

    params_data = sio.loadmat('data/ex8_movieParams.mat')
    X = params_data['X']
    Theta = params_data['Theta']

    # print(X.shape, Theta.shape)

    users = 4
    movies = 5
    features = 3

    X_sub = X[:movies, :features]
    Theta_sub = Theta[:users, :features]
    Y_sub = Y[:movies, :users]
    R_sub = R[:movies, :users]

    # 把所有特征都合并为一维中
    params = np.concatenate((np.ravel(X_sub), np.ravel(Theta_sub)))
    # cost(params, Y_sub, R_sub, features)

    # print(cost(params, Y_sub, R_sub, features))


    J, grad = cost(params, Y_sub, R_sub, features, 1.5)
    # print(J, grad)

    movie_idx = {}
    f = open('data/movie_ids.txt',encoding= 'gbk')
    for line in f:
        tokens = line.split(' ')
        tokens[-1] = tokens[-1][:-1]
        movie_idx[int(tokens[0]) - 1] = ' '.join(tokens[1:])

    # print(movie_idx[0])

    ratings = np.zeros((1682, 1))

    ratings[0] = 4
    ratings[6] = 3
    ratings[11] = 5
    ratings[53] = 4
    ratings[63] = 5
    ratings[65] = 3
    ratings[68] = 5
    ratings[97] = 2
    ratings[182] = 4
    ratings[225] = 5
    ratings[354] = 5

    print('Rated {0} with {1} stars.'.format(movie_idx[0], str(int(ratings[0]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[6], str(int(ratings[6]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[11], str(int(ratings[11]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[53], str(int(ratings[53]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[63], str(int(ratings[63]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[65], str(int(ratings[65]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[68], str(int(ratings[68]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[97], str(int(ratings[97]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[182], str(int(ratings[182]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[225], str(int(ratings[225]))))
    print('Rated {0} with {1} stars.'.format(movie_idx[354], str(int(ratings[354]))))

    R = data['R']
    Y = data['Y']

    Y = np.append(Y, ratings, axis=1)
    R = np.append(R, ratings != 0, axis=1)

    movies = Y.shape[0]  # 1682
    users = Y.shape[1]  # 944
    features = 10
    learning_rate = 10.

    X = np.random.random(size=(movies, features))
    Theta = np.random.random(size=(users, features))
    params = np.concatenate((np.ravel(X), np.ravel(Theta)))

    Ymean = np.zeros((movies, 1))
    Ynorm = np.zeros((movies, users))

    for i in range(movies):
        idx = np.where(R[i,:] == 1)[0]
        Ymean[i] = Y[i,idx].mean()
        Ynorm[i,idx] = Y[i,idx] - Ymean[i]

    # print(Ynorm.mean())
    from scipy.optimize import minimize

    fmin = minimize(fun=cost, x0=params, args=(Ynorm, R, features, learning_rate), 
                    method='CG', jac=True, options={'maxiter': 100})


    X = np.matrix(np.reshape(fmin.x[:movies * features], (movies, features)))
    Theta = np.matrix(np.reshape(fmin.x[movies * features:], (users, features)))

    predictions = X * Theta.T 
    my_preds = predictions[:, -1] + Ymean

    sorted_preds = np.sort(my_preds, axis=0)[::-1]

    idx = np.argsort(my_preds, axis=0)[::-1]

    print("Top 10 movie predictions:")
    for i in range(10):
        j = int(idx[i])
        print('Predicted rating of {0} for movie {1}.'.format(str(float(my_preds[j])), movie_idx[j]))

filter()