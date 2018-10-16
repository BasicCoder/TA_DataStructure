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

1) 文件结束符(EOF)：
不同的操作系统有不同的约定，在windows系统中，输入文件结束符的方法是先按Ctrl+Z，然后再按Enter；在UNIX系统中，包括Mac OS X系统中，文件结束输入为Ctrl+D;

2) 输入流检查方式：可以参考链接[Reference](https://blog.csdn.net/shiyongraow/article/details/77844536)

3) 关于 ```while(cin >> x) { ... }``` 和 ```while(cin) {cin >> y; ....}``` 区别：
可以参考链接
[Reference](https://stackoverflow.com/questions/19483126/whats-the-difference-between-whilecin-and-whilecin-num) 

```
while(cin){
    cin >> y;
    // code
}
```
```while(cin)``` 表示“当之前所有关于cin的操作都已经成功，继续进入循环”。一旦我们进入循环，我们将尝试将值读入y。这可能会成功，也可能会失败。但是，无论是哪种情况，循环都将继续执行。 这意味着一旦输入了无效数据或者没有更多数据需要读取，循环将使用旧的y值再次执行，因此会得到比需要的多一次的循环迭代。</br>
测试代码：
```
#include <iostream>
#include <vector>
using namespace std; 

int main()
{
	vector<int> num;
	int x = 0;
	
	while (cin)
	{
		cout << "F: " << cin.rdstate() << endl;
		cin >> x;
		cout << "E: " << cin.rdstate() << endl;
		num.push_back(x); 
	}
	
	cout << num.size() << endl; 
	for (int i = 0; i < num.size(); i ++)	cout << num[i] << "  ";
	cout << endl;
	
	return 0;
}
```
输入测试：
```
1 2 3 4
^Z
```
结果输出：
```
F: 0
1 2 3 4
E: 0
F: 0
E: 0
F: 0
E: 0
F: 0
E: 0
F: 0
^Z
E: 6
5
1  2  3  4  4
```
从结果我们可以看到，当我们准备输入数据前，cin 状态为 0 表示正常，所以正常进入循环。然后我们输入数字 1 2 3 4, 点击 Enter, 都得到正确的 cin 输入状态。所以在最后一次之后，又重新进入循环。我们输入 ^Z,并点击 Enter，期望结束输入流, cin 检查输入流，cin >> x 尝试执行，得到输入错误，并且检测到输入流结束，所以 cin 返回状态 6, 程序继续执行, num.push_back(x) 将 x 的旧值放入到数组后面，继续下次循环，循环条件不满足，结束循环。所以我们可以看到，循环总是要比我们想要的循环次数多一次，这里需要特别注意。



条件状态：

IO流有四种条件状态，分别用位来控制。

cin.badbit : 001   1   表示系统级错误，一旦被置位，流就无法再使用了

cin.eofbit : 010   2   表示流已经读完，到达尾部了

cin.failbit: 100   4   可恢复错误，如期望读取数值却读出一个字符等错误，或者已经到达流的尾部

cin.goodbit: 000   0   可用状态


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