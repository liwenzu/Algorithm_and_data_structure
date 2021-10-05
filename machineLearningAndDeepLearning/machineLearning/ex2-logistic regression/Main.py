from logging import error
import sys
from warnings import filters
from PyQt5.QtWidgets import QApplication, QFileDialog, QMainWindow, QWidget
import Ui_untitled
from PyQt5 import QtCore
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.optimize as opt
# from sklearn import linear_model

class MainQWidget(QWidget):
    def __init__(self, parent = None):
        super(QWidget, self).__init__(parent)
        self.ui = Ui_untitled.Ui_Form()
        self.ui.setupUi(self)
        self.ui.pushButton.clicked.connect(self.openFile)
        self.ui.pushButton_2.clicked.connect(self.normalReg)
        self.ui.pushButton_3.clicked.connect(self.regularizedReg)

    def sigmoid(self, z):
        return 1/(1+np.exp(-z))


    def sigmoidShow(self):
        nums = np.arange(-10, 10, step=1)
        fig, ax = plt.subplots(figsize=(12, 8))
        ax.plot(nums, self.sigmoid(nums), 'y')
        plt.show()

    def cost(self, theta, X, y):
        theta = np.matrix(theta)
        X = np.matrix(X)
        y = np.matrix(y)
        first = np.multiply(-y, np.log(self.sigmoid(X*theta.T)))
        second = np.multiply((1-y), np.log(1-self.sigmoid(X*theta.T)))
        return np.sum(first-second)/(len(X))

    def costReg(self,theta, X, y, learningRate):
        theta = np.matrix(theta)
        X = np.matrix(X)
        y = np.matrix(y)
        first = np.multiply(-y, np.log(self.sigmoid(X*theta.T)))
        second = np.multiply((1-y), np.log(1 - self.sigmoid(X*theta.T)))
        reg = (learningRate / (2*len(X)))*np.sum(np.power(theta[:, 1:theta.shape[1]], 2))
        return np.sum(first - second)/len(X) +reg


    # 梯度计算
    def gradient(self, theta, X, y):
        theta = np.matrix(theta)
        X = np.matrix(X)
        y = np.matrix(y)
        # 参数的个数
        parameters = int(theta.ravel().shape[1])
        # 梯度的个数
        grad = np.zeros(parameters)
        error = self.sigmoid(X*theta.T)-y

        for i in range(parameters):
            term = np.multiply(error, X[:,i])
            grad[i] = np.sum(term)/len(X)
        return grad

    # 正则化梯度下降
    def gradientReg(self, theta, X, y, learningRate):
        theta = np.matrix(theta)
        X = np.matrix(X)
        y = np.matrix(y)
        # 参数的个数
        parameters = int(theta.ravel().shape[1])
        # 梯度的个数
        grad = np.zeros(parameters)
        error = self.sigmoid(X*theta.T) - y

        for i in range(parameters):
            term = np.multiply(error, X[:,i])
            if i  == 0:
                grad[i] = np.sum(term)/len(X)
            else:
                grad[i] = np.sum(term)/len(X) + (learningRate/len(X))*theta[:,i]

        return grad


    # 预测函数
    def predict(self, theta, X):
        probability = self.sigmoid(X*theta.T)
        return [1 if x >= 0.5 else 0 for x in probability]


    # 正则化逻辑回归

    def regularizedReg(self):
        data2 = pd.read_csv(self.path, header=None, names=['Test1', 'Test2', 'Accepted'])

        positive = data2[data2['Accepted'].isin([1])]
        negative = data2[data2['Accepted'].isin([0])]

        # 打印数据分布
        # fig, ax = plt.subplots(figsize=(12,8))
        # ax.scatter(positive['Test1'], positive['Test2'], s=50, c='b', marker='o', label = 'Accepted')
        # ax.scatter(negative['Test1'], negative['Test2'], s=50, c='r', marker='x', label = 'Rejected')
        # ax.legend()
        # ax.set_xlabel('Test1 Score')
        # ax.set_ylabel('Test2 Score')
        # plt.show()

        degree = 5
        x1 = data2['Test1']
        x2 = data2['Test2']
        data2.insert(3, 'Ones', 1)

        # print(data2.head())

        for i in range(1, degree):
            for j in range(0, i):
                data2['F'+str(i)+str(j)] = np.power(x1, i-j)*np.power(x2, j)
        data2.drop('Test1', axis=1, inplace=True)
        data2.drop('Test2', axis=1, inplace=True)

        # print('------------')
        # print(data2.head())

        cols = data2.shape[1]
        X2 = data2.iloc[:,1:cols]
        y2 = data2.iloc[:,0:1]

        X2 = np.array(X2.values)
        y2 = np.array(y2.values)
        theta2 = np.zeros(11)

        learningRate = 1

        self.ui.lineEdit_2.setText(str(self.costReg(theta2, X2, y2, learningRate)))
        # print(self.costReg(theta2, X2, y2, learningRate))

        result2 = opt.fmin_tnc(func=self.costReg, x0=theta2, fprime=self.gradientReg, args=(X2, y2, learningRate))     
    
        # print(result2)


        theta_min = np.matrix(result2[0])
        # 最终代价
        self.ui.lineEdit_3.setText(str(self.costReg(theta_min, X2, y2, learningRate)))

        predictions = self.predict(theta_min, X2)
        correct = [1 if a == b else 0 for (a, b) in zip(predictions, y2)]
        accuracy = (sum(map(int, correct)) % len(correct))
        # 最后的精度
        print ('accuracy = {0}%'.format(accuracy))
        self.ui.lineEdit_4.setText(str('{0}%'.format(accuracy)))

        # print(y2.head())

        # print(data2.head())

    # 普通逻辑回归
    def normalReg(self):
        data = pd.read_csv(self.path, header=None, names=['Exam 1', 'Exam 2', 'Admitted'])  
        self.positive = data[data['Admitted'].isin([1])]
        self.negative = data[data['Admitted'].isin([0])]
        
        # 数据可视化，即成绩和接受性可视化
        # fig, ax = plt.subplots(figsize=(12,8))
        # ax.scatter(self.positive['Exam 1'], self.positive['Exam 2'], s=50, c='b', marker='o', label='Admitted')
        # ax.scatter(self.negative['Exam 1'], self.negative['Exam 2'], s=50, c='r', marker='x', label='Not Admitted')
        # ax.legend()
        # ax.set_xlabel('Exam 1 Score')
        # ax.set_ylabel('Exam 2 Score')
        # plt.show()

        # sigmoidShow可视化函数 
        # self.sigmoidShow()

        # 插入一行数据用于表征theat0
        data.insert(0, 'Ones', 1)
        cols = data.shape[1]
        X = data.iloc[:,0:cols-1]
        y = data.iloc[:,cols-1:cols]

        X = np.array(X.values)
        y = np.array(y.values)
        theta = np.zeros(3)

        # 查看维度
        # print(theta, X.shape, theta.shape, y.shape)

        #计算初始theta为0时的代价
        init_result = self.cost(theta, X, y)
        # 初始的代价值
        self.ui.lineEdit_2.setText(str(init_result))
        # print(init_result)


        # 打印第一步计算的梯度 
        # print(self.gradient(theta, X, y))

        # 使用SciPy方法计算theta值
        result = opt.fmin_tnc(func=self.cost, x0=theta, fprime=self.gradient, args=(X, y))

        # 优化后的代价函数
        # print(self.cost(result[0], X, y))
        self.ui.lineEdit_3.setText(str(self.cost(result[0], X, y)))

        theta_min = np.matrix(result[0])
        predictions = self.predict(theta_min, X)
        correct = [1 if a == b else 0 for (a, b) in zip(predictions, y)]
        accuracy = (sum(map(int, correct)) % len(correct))
        # 最后的精度
        # print ('accuracy = {0}%'.format(accuracy))
        self.ui.lineEdit_4.setText('{0}%'.format(accuracy))


    def openFile(self):
        _translate = QtCore.QCoreApplication.translate
        self.path = QFileDialog.getOpenFileName(self, 'Open file', 'F:\\BSUIR\\算法与数据结构\\machineLearningAndDeepLearning\\machineLearning\\ex2-logistic regression', '*.txt')
        self.path = str(self.path[0])
        self.ui.lineEdit.setText(self.path)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWindow = MainQWidget()
    MainWindow.show()
    sys.exit(app.exec_())