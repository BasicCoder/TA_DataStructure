# Experiment 3

## 二.
### Note
输入未给定数组长度,需要解决数据输入长度不确定的问题：

#### Solution 1):
```
#include <iostream>
using namespace std;

int d;
while(cin >> d){
    ...
}
```
在 while 中使用 ``` cin >> d ```, 通过检测其流的状态来判断结束:
* 若流是有效的，即流未遇到错误，那么检测成功；
* 若遇到文件结束符，或遇到一个无效的输入时（例如例子中输入的值不是一个整数），istream对象的状态会变为无效，条件就为假；

``` cin >> d ``` 返回的是左操作数，也就是返回cin

while(cin) 中有个缓冲机制规定，只有收到回车键，才会将所有输入的数据一次提交到输入处理函数cin里，而这个输入过程，在按下回车之前，是不受cin控制的。

对于正常的输入，用回车和空格没有差别，关键是我们最后往往要输入个ctrl+z来结束输入，这里要特别注意，ctrl+z之前必须要按“回车”，不能是空格，也不能什么都不按。

正确的顺序是：**“正常值输入（以空格或回车间隔都可以）”、“回车”、(ctrl+z)、“回车”**。这样在缓冲机制下 while(cin) 循环就会把ctrl+z作为输入流单独进行判断，cin.eof()为真，即遇到正常的文件结束符，否则，while(cin) 循环判断时以为 ctrl+z 和之前的空格是一起的或者和之前的其他输入是一起的，认为是输入了坏值，认为没有遇到正常的文件结束符。

***扩展***：

1) 文件结束符：
不同的操作系统有不同的约定，在windows系统中，输入文件结束符的方法是先按Ctrl+Z，然后再按Enter；在UNIX系统中，包括Mac OS X系统中，文件结束输入为Ctrl+D;

2) 输入流检查方式：可以参考链接[Reference](https://blog.csdn.net/shiyongraow/article/details/77844536)

3) 关于 ```while(cin >> x) { ... }``` 和 ```while(cin) {cin >> y; ....}``` 区别：
可以参考链接
[Reference](https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num) 


#### Solution 2):
```
#include <stdio.h>

int d;
while(scanf("%d", &d) != EOF){
    ...
}
```
其中 ``` while(~scanf("%d %d",&a,&b)) ``` 和 ``` while(scanf("%d %d",&a,&b)!=EOF)```效果等同。</br>
scanf()函数：</br>
scanf("<格式化字符串>"，<地址表>);返回类型为int， scanf()函数返回成功赋值的数据项数，出错时则返回EOF。</br>

例如scanf("%d %d",&a,&b):
* 如果a和b都被成功读入，那么scanf的返回值就是2
* 如果只有a被成功读入，返回值为1
* 如果a和b都未被成功读入，返回值为0
* 如果遇到错误或遇到end of file，返回值为EOF。