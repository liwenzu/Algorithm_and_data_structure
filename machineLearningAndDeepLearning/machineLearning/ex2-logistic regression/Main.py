from logging import error
import sys
from PyQt5.QtWidgets import QApplication, QFileDialog, QMainWindow, QWidget
import Ui_untitled
from PyQt5 import QtCore
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy.optimize as opt

class MainQWidget(QWidget):
    def __init__(self, parent = None):
        super(QWidget, self).__init__(parent)
        self.ui = Ui_untitled.Ui_Form()
        self.ui.setupUi(self)
        self.ui.pushButton.clicked.connect(self.openFile)

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


    # 预测函数
    def predict(self, theta, X):
        probability = self.sigmoid(X*theta.T)
        return [1 if x >= 0.5 else 0 for x in probability]







    def openFile(self):
        _translate = QtCore.QCoreApplication.translate
        self.path = QFileDialog.getOpenFileName(self, 'Open file', 'F:\\BSUIR\\算法与数据结构\\machineLearningAndDeepLearning\\machineLearning\\ex2-logistic regression', '*.txt')
        self.path = str(self.path[0])
        self.ui.lineEdit.setText(self.path)
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
        print(init_result)


        # 打印第一步计算的梯度 
        # print(self.gradient(theta, X, y))

        # 使用SciPy方法计算theta值
        result = opt.fmin_tnc(func=self.cost, x0=theta, fprime=self.gradient, args=(X, y))

        # 优化后的代价函数
        print(self.cost(result[0], X, y))

        theta_min = np.matrix(result[0])
        predictions = self.predict(theta_min, X)
        correct = [1 if a == b else 0 for (a, b) in zip(predictions, y)]
        accuracy = (sum(map(int, correct)) % len(correct))
        print ('accuracy = {0}%'.format(accuracy))





if __name__ == '__main__':
    app = QApplication(sys.argv)
    MainWindow = MainQWidget()
    MainWindow.show()
    sys.exit(app.exec_())