# 第六次上机内容

1. 求两个整数的最大公约数和最小公倍数。
要求：
	- 两个整数在 `main()` 中输入；
	- 将两个整数作为参数传递给求最大公约数的函数，求出后返回给 `main()` 函数；
	- 将两个整数和求出的最大公约数作为参数传递给求最小公倍数函数，求出后返回给 `main()` 函数；
	- 在 `main()` 函数中输出两个整数和求出的最大公约数、最小公倍数。

[**euclidFunction.c**](./euclidFunction.c)

2. 编写一个函数将键盘输入的一个字符串按反序存放，在 `main()` 函数中输入和输出字符串。

[**reverseString.c**](./reverseString.c)

3. 从键盘输入一段英文存入一个字符数组 `str[50]`，编写函数 `Count_Word(str)` 统计其中有多少个单词，编写函数 `Count_Space(str)` 统计其中有多少个空格，在main函数中输出结果。

[**countString.c**](./countString.c)

4. 用递归法编写函数将一个正整数转换为字符输出，例如输入整数 `2873` 存入一个整型变量，递归函数应按顺序输出字符 `2`、`8`、`7`、`3`，输入整数的位数不定，可以是变量允许范围内的任意正整数。