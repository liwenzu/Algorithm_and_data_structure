from numpy import pi
import pandas as pd
import numpy as np


def dim2D_to_dim3D(data):
    
    data = data.values

    # print(type(data))

    data3D = np.reshape(data, (2, 2, 15))






    print(data3D)
    print("原始维度:", data.shape, "转换后维度:", data3D.shape)

def main():
    data = pd.read_csv("./test.csv")

    dim2D_to_dim3D(data[:4])

main()



# a = np.arange(12).reshape(3,4)
# print("******************")
# print(a)
# b=np.reshape(a,(3,4,1))
# print("******************")
# print(b)

# c=np.concatenate([b,b],2)

# print("******************")
# print(c)