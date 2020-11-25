# 第七次上机内容

## 数组 + 函数 综合练习

实现一个数组运算程序，程序运行后先显示菜单：
```
--------------menu----------------
1.输入数组数据
2.显示数组（输出数组数据）
3.求最大值和最小值
4.求平均值
5.冒泡排序
6.选择排序
7.查找指定元素
8.删除指定元素
9.判断数组是否有序
0.退出
-----------------------------------
```

运行后显示菜单并显示提示 `请选择菜单功能：` 然后通过键盘输入数字选择相应菜单项执行功能。

说明：	
1. 可以定义一个较大的数组以便于插入数据，初始输入 `10` 个数组数据；
2. 要求每个菜单功能执行完后能返回主菜单继续执行，直到选择输入 `0` 结束整个程序；
3. 查找指定元素由用户输入，如果查到输出该数据在数组中的位置，如果没有输出 `未查到`；
4. 待删除数据由用户输入，如果存在该数据则将该数据从数组中删除并将数组前移一位，如果没有输出 `无此数据`；
5. 函数的功能尽量用指针和 `*` 的方式来实现；
6. 该次上机要求完成前五项功能，后面的功能可以先写成空函数放在程序里，下次上机继续实现。