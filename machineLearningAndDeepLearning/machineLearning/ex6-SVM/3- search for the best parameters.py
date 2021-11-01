# 寻找最优参数
from sklearn import svm
from sklearn.model_selection import GridSearchCV
from sklearn import metrics
import numpy as np
import pandas as pd
import scipy.io as sio

def main():
    mat = sio.loadmat('./data/ex6data3.mat')

    training = pd.DataFrame(mat.get('X'), columns=['X1', 'X2'])
    training['y'] = mat.get('y')

    cv = pd.DataFrame(mat.get('Xval'), columns=['X1', 'X2'])
    cv['y'] = mat.get('yval')

    # print(cv)

    # 方法1
    # 手动网格搜素
    candidate = [0.01, 0.03, 0.1, 0.3, 1, 3, 10, 30, 100]
    combination = [(C, gamma) for C in candidate for gamma in candidate]

    # print(combination)

    search = []
    for C, gamma in combination:
        svc = svm.SVC(C=C, gamma=gamma)
        svc.fit(training[['X1', 'X2']], training['y'])
        search.append(svc.score(cv[['X1', 'X2']], cv['y']))
    # 精确度，召回率以及相似度
    best_score = search[np.argmax(search)]
    best_param = combination[np.argmax(search)]

    best_svc = svm.SVC(C= 100, gamma=0.3)
    best_svc.fit(training[['X1', 'X2']], training['y'])
    ypred = best_svc.predict(cv[['X1', 'X2']])
    # print(metrics.classification_report(cv['y'], ypred))



    # 方法2
    # sklearn GridSearchCV (网格搜索)自动选择
    parameters = {'C':candidate, 'gamma':candidate}
    svc = svm.SVC()
    clf = GridSearchCV(svc, parameters, n_jobs=-1)
    clf.fit(training[['X1', 'X2']], training['y'])
    best_pa = clf.best_params_
    best_sco = clf.best_score_
    # print(best_sco)
    ypred = clf.predict(cv[['X1', 'X2']])
    print(metrics.classification_report(cv['y'], ypred))

main()