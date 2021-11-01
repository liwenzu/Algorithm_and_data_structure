from numpy import log
from sklearn import svm
from sklearn import metrics
from sklearn.linear_model import LogisticRegression

import scipy.io as sio

def main():
    mat_tr = sio.loadmat('data/spamTrain.mat')
    X, y = mat_tr.get('X'), mat_tr.get('y').ravel()

    # print(X.shape, y.shape)

    mat_test = sio.loadmat('./data/spamTest.mat')
    test_X, test_y = mat_test.get('Xtest'), mat_test.get('ytest').ravel()

    # print(test_X.shape, test_y.shape)

    # 第一种方法
    # svm模型拟合
    svc = svm.SVC()
    svc.fit(X, y)
    pred = svc.predict(test_X)
    # 打印预测报告
    print(metrics.classification_report(test_y, pred))


    # 第二种方法
    # 逻辑回归
    logit = LogisticRegression()
    logit.fit(X, y)
    pred = logit.predict(test_X)
    # 打印预测报告
    print(metrics.classification_report(test_y, pred))

    # ......结果，逻辑回归的结果比svm强多了
main()