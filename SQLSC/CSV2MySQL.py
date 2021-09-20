# -*- coding: utf-8 -*-

# 导入必要模块
import pandas as pd
from sqlalchemy import create_engine
import MySQLdb

import numpy as np
import os



# # 初始化数据库连接，使用pymysql模块
# db_info = {'user': 'root',
#            'password': 'cetc38-Phm',
#            'host': 'localhost',
#            'port': 3306,
#            'database': 'phm_cetc38'
#            }
# engine = create_engine('mysql+pymysql://%(user)s:%(password)s@%(host)s:%(port)d/%(database)s?charset=utf8' % db_info, encoding='utf-8')
# # 直接使用下一种形式也可以
# engine = create_engine('mysql+pymysql://root:123456@localhost:3306/sensor_data')
# # 读取本地CSV文件
# df = pd.read_csv("D:/CETCNewVersion/buildPHM/data/train_FD001.csv", sep=',')
# print(df)
#
# pd.io.sql.to_sql(df, 'sensor_data', con=engine, index=False, if_exists='append')
# # print("Write to MySQL successfully!")


df = pd.read_csv("D:/CETCNewVersion/buildPHM/data/train_FD001.csv", sep=',')

df.columns=["id", 'cycle', 'sersor1','sersor2','sersor3','sersor4','sersor5','sersor6','sersor7','sersor8','sersor9','sersor10','sersor11','sersor12','sersor13','sersor14',"RUL"]
y = df[["id", 'cycle', 'sersor1','sersor2','sersor3','sersor4','sersor5','sersor6','sersor7','sersor8','sersor9','sersor10','sersor11','sersor12','sersor13','sersor14',"RUL"]]

y=np.array(y)

# for ch in x[0]:
#     print(ch)





db = MySQLdb.connect("localhost", "root", "cetc38-Phm", "phm_cetc38", charset='utf8' )


cursor = db.cursor()

# query = "INSERT INTO sensor_data VALUES({0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13},{14},{15},{16});".format(int(x[0][0]),int(x[0][1]),float(x[0][2]),float(x[0][3]),float(x[0][4]),float(x[0][5]),float(x[0][6]),float(x[0][7]),float(x[0][8]),float(x[0][9]),float(x[0][10]),float(x[0][11]),float(x[0][12]),float(x[0][13]),float(x[0][14]),float(x[0][15]),float(x[0][16]))

# "INSERT INTO {0} VALUES({1});".format(table, data)
#cursor.execute("insert into sensor_data (id, cycle, sersor1,sersor2,sersor3,sersor4,sersor5,sersor6,sersor7,sersor8,sersor9,sersor10,sersor11,sersor12,sersor13,sersor14,RUL) values (int(x[0][1]),int(x[0][0]),x[0][2],x[0][3],x[0][4],x[0][5],x[0][6],x[0][7],x[0][8],x[0][9],x[0][10],x[0][11],x[0][12],x[0][13],x[0][14],x[0][15],x[0][16]);")

#cursor.execute("insert into sensor_data values(int(x[0][0]),int(x[0][1]),float(x[0][2]),float(x[0][3]),float(x[0][4]),float(x[0][5]),float(x[0][6]),float(x[0][7]),float(x[0][8]),float(x[0][9]),float(x[0][10]),float(x[0][11]),float(x[0][12]),float(x[0][13]),float(x[0][14]),float(x[0][15]),float(x[0][16]));")


# cursor.execute("insert into sensor_data (id, cycle, sersor1,sersor2,sersor3,sersor4,sersor5,sersor6,sersor7,sersor8,sersor9,sersor10,sersor11,sersor12,sersor13,sersor14,RUL) values (2,1,2388.06,9046.19,1.3,47.47,521.66,2388.02,8138.62,8.4195,0.03,392,2388,100,39.06,23.419,191);")

# cursor.execute(query)


#sql = "INSERT INTO news (news_title,news_href,news_time) VALUES (%(title)s,%(href)s,%(time)s)"

# query = "INSERT INTO sensor_data (id, cycle, sersor1,sersor2,sersor3,sersor4,sersor5,sersor6,sersor7,sersor8,sersor9,sersor10,sersor11,sersor12,sersor13,sersor14,RUL) VALUES (%(x[0][1])i,%(x[0][1])i,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f,%(x[0][1])f)"

#cursor.execute("insert into sensor_data (id, cycle, sersor1,sersor2,sersor3,sersor4,sersor5,sersor6,sersor7,sersor8,sersor9,sersor10,sersor11,sersor12,sersor13,sersor14,RUL) values (x[0][1],x[0][0],x[0][2],x[0][3],x[0][4],x[0][5],x[0][6],x[0][7],x[0][8],x[0][9],x[0][10],x[0][11],x[0][12],x[0][13],x[0][14],x[0][15],x[0][16]);")


db = MySQLdb.connect("localhost", "root", "cetc38-Phm", "phm_cetc38", charset='utf8' )

cursor = db.cursor()

# sql = "INSERT INTO sensor_data1 (id, cycle, sersor1) VALUES (%(title)s,%(href)s,%(time)s)"

# cursor.execute("insert into sensor_data1 (id, cycle, sersor1) values (3,1,2388.06);")

# cursor.execute("insert into sensor_data1 (id, cycle, sersor1) values (10,%(int(x[0][2]))s,%(flaot(x[0][2]))s);")

# a = 30
# b =40
#
# # sql = "insert into test2(url, time) values('%s','%s')" % (Url，Time)
#
# sql = "INSERT INTO sensor_data2 (id, cycle, sersor1) VALUES (1,'%s','%s')" % (x[0][4], x[0][2])
#
# cursor.execute(sql)
#
# db.commit()

#     sql = "INSERT INTO sensor_data(id, cycle, sersor1,sersor2,sersor3,sersor4,sersor5,sersor6,sersor7,sersor8,sersor9,sersor10,sersor11,sersor12,sersor13,sersor14,RUL) VALUES('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')" % (x[0][0], x[0][1], x[0][2], x[0][3], x[0][4], x[0][5], x[0][6], x[0][7], x[0][8], x[0][9], x[0][10], x[0][11], x[0][12], x[0][13], x[0][14], x[0][15], x[0][16])


for x in y:
    sql = "INSERT INTO sensor_data(id, cycle, sersor1,sersor2,sersor3,sersor4,sersor5,sersor6,sersor7,sersor8,sersor9,sersor10,sersor11,sersor12,sersor13,sersor14,RUL) VALUES('%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')" % (x[0], x[1], x[2], x[3], x[4], x[5], x[6], x[7], x[8], x[9], x[10], x[11], x[12], x[13], x[14], x[15], x[16])
    cursor.execute(sql)
    db.commit()







# results = cursor.fetchall()
# for row in results:
#     lru_id= row[0]
#     lru_name = row[1]
#     # 打印结果
#     print(lru_id, lru_name)


print("JJJJJJJJJJJJJJJJJJJJJJJJJJJJJ")
