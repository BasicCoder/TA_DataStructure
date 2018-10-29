# Experiment 5
## 一.模板
### Problem Description
定义一个单向链表的模版类 ,它分别实现增加(Add),删除(Remove),查找(Find)和打 印(PrintList)操作。
### Input and ouput
<table>
  <tr>
    <th colspan="2">Input</th>
    <th colspan="2">Output</th>
  </tr>
  <tr>
    <td colspan="2">每行为以下四种操作之一:</td>
    <td colspan="2">每种操作对应的返回值:</td>
  </tr>
  <tr>
    <td colspan="2">add Type</td>
    <td colspan="2">add:bool</td>
  </tr>
  <tr>
    <td colspan="2">remove Type</td>
    <td colspan="2">remove:bool</td>
  </tr>
  <tr>
    <td colspan="2">find Type</td>
    <td colspan="2">find:bool</td>
  </tr>
  <tr>
    <td colspan="2">printList</td>
    <td colspan="2">printList:链表中的数值序列</td>
  </tr>
  <tr>
    <td>Sample Input1</td>
    <td>Sample Output1</td>
    <td>Sample Input2</td>
    <td>Sample Output2</td>
  </tr>
  <tr>
    <td>Type 为 int 型</td>
    <td></td>
    <td>Type 为 string 型</td>
    <td></td>
  </tr>
  <tr>
    <td>add 3</td>
    <td>true</td>
    <td>add “ab”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>add 5</td>
    <td>true</td>
    <td>add “cde”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>add 8</td>
    <td>true</td>
    <td>add “fg”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>add 13</td>
    <td>true</td>
    <td>add “ ”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>add 15</td>
    <td>true</td>
    <td>add “hij”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>add -1</td>
    <td>true</td>
    <td>add “fg”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>add 0</td>
    <td>true</td>
    <td>printList</td>
    <td>ab cde&nbsp;&nbsp;&nbsp;fg hij fg</td>
  </tr>
  <tr>
    <td>remove 4</td>
    <td>false</td>
    <td>remove “ab”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>remove 5</td>
    <td>true</td>
    <td>remove “xyz”</td>
    <td>false</td>
  </tr>
  <tr>
    <td>add 8</td>
    <td>true</td>
    <td>printList</td>
    <td>cde&nbsp;&nbsp;&nbsp;fg hij fg</td>
  </tr>
  <tr>
    <td>add 9</td>
    <td>true</td>
    <td>find “xyz”</td>
    <td>false</td>
  </tr>
  <tr>
    <td>add 10</td>
    <td>true</td>
    <td>add “xyz”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>add 11</td>
    <td>true</td>
    <td>find “fg”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>find 10</td>
    <td>true</td>
    <td>remove “fg”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>remove 10</td>
    <td>true</td>
    <td>find “fg”</td>
    <td>true</td>
  </tr>
  <tr>
    <td>find 10</td>
    <td>false</td>
    <td>printList</td>
    <td>cde&nbsp;&nbsp;&nbsp;hij fg xyz</td>
  </tr>
  <tr>
    <td>find 11</td>
    <td>true</td>
    <td>提示：输入不带“”</td>
    <td></td>
  </tr>
  <tr>
    <td>printList</td>
    <td>3 8 13 15 -1 0 8 9 11</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>printList</td>
    <td>3 8 13 15 -1 0 8 9 11</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>find 13</td>
    <td>true</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>add -1</td>
    <td>true</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>printList</td>
    <td>3 8 13 15 -1 0 8 9 11 -1</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>remove 8</td>
    <td>true</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>printList</td>
    <td>3 13 15 -1 0 8 9 11 -1</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td></td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>

## 二.最长回文子串
### Problem Description
你能不能分别在这些字符串中找到它们每一个的最长回文子串呢？
什么叫做最长回文子串呢？</br>
一个字符串中连续的一段就是这个字符串的子串，而回文串指的是 12421 这种从前往 后读和从后往前读一模一样的字符串，所以最长回文子串的意思就是这个字符串中最长的身为回文串的子串。
### Input and ouput
先从标准输入读取一个整数 N（N<=30)，代表我给你的字符串的个数，然后接下来的就是我要给你的那 N 个字符串（字符串长度<=10^6)啦。 而你要给我的答案 只要将你计算出的最长回文子串的长度及其对应的查找过程输出（不同的方法可能对应的过程不一样） ， 按照我给你的顺序依次输出到标准输出就可以了！ 来，看这有一个栗子。</br>
样例输入：</br>
3 </br>
abababa </br>
aaaabaa </br>
acacdas </br>
样例输出：</br>
第一个样例：</br>
更新最大长度为 1， 对应的序列为 a </br>
更新最大长度为 3， 对应序列为 aba </br>
更新最大长度为 5， 对应序列为 ababa </br>
更新最大长度为 7， 对应序列为 abababa </br>
最大长度为 7 </br>
</br>
第二个样例：</br>
更新最大长度为 1， 对应的序列为 a </br>
更新最大长度为 2， 对应序列为 aa </br>
更新最大长度为 3， 对应序列为 aaa </br>
更新最大长度为 4， 对应序列为 aaaa </br>
更新最大长度为 5， 对应序列为 aabaa </br>
最大长度为 5 </br>
</br>
第三个样例：</br>
更新最大长度为 1， 对应的序列为 a </br>
更新最大长度为 3， 对应序列为 aca </br>
最大长度为 3 </br>
</br>
Bonus：</br>
1. O (N3) 60 分
2. O (N2) 85 分
3. O (N) 100 分

## 三.汉诺塔问题的非递归解法
### Problem Description
汉诺塔问题是一个经典的问题。汉诺塔（Hanoi Tower），又称河内塔，源于印度一个古老传说。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着 64 片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，任何时候，在小圆盘上都不能放大圆盘，且在三根柱子之间一次只能移动一个圆盘。问应该如何操作？要求按下列规则将所有圆盘移至C杆：

1. 每次只能移动一个圆盘；
2. 大盘不能叠在小盘上面。

提示：可将圆盘临时置于B杆，也可将从A杆移出的圆盘重新移回A杆，但都必须遵循上述两条规则。  
三个盘的情况:</br>
![](./702782-20161114211933513-1127552732.gif)   
四个盘的情况:</br>
![](./702782-20161114212352576-1869972276.gif)
### Input
3
### Output
Move a to c </br>
Move a to b </br>
Move c to b </br>
Move a to c </br>
Move b to a </br>
Move b to c </br>
Move a to c </br>
### Note:
用非递归解法