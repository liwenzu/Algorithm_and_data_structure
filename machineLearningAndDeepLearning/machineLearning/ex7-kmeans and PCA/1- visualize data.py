import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import scipy.io as sio

def main():
    mat = sio.loadmat('./data/ex7data1.mat')

    data1 = pd.DataFrame(mat.get('X'), columns=['X1', 'X2'])

    # 数据集1可视化
    # sns.set(context = "notebook", style = "white")
    # sns.lmplot('X1', 'X2', data = data1, fit_reg=False)
    # plt.show()

    # 数据集2可视化
    mat = sio.loadmat('./data/ex7data2.mat')
    data2 = pd.DataFrame(mat.get('X'), columns=['X1', 'X2'])
    sns.lmplot('X1', 'X2', data = data2, fit_reg=False)
    plt.show()
main()
