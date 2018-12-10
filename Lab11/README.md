# Experiment 11
## 一.班级中朋友圈的数目
### Problem Description
一个班级有N个学生。这些学生中有些是朋友，有些则不是。班级学生的友谊具有转移的特点。例如，假如A是B的直接朋友，同时B是C的直接朋友，那么A是C的间接朋友。这样，“朋友圈”可定义为直接和间接朋友的一个集合。

给定一个N*N的矩阵M来表示一个班级的朋友关系。如果M[i][j]=1,则说明第i个学生和第j个学生互为直接朋友，否则他们不具有朋友关系。例如，有朋友关系矩阵[[1,1,0],[1,1,0],[0,0,1]]，则该班级的朋友圈个数为2，因为学生0和学生1是直接朋友，他们在一个朋友圈内，而学生2自己在一个朋友圈内。又如，对于朋友关系矩阵[[1,1,0],[1,1,1],[0,1,1]]，则该班级的朋友圈个数为1，因为学生0和学生1是直接朋友，学生1和学生2是直接朋友，学生0和学生2是间接朋友，这三个学生处于同一个朋友圈。

### Input
从测试用例文件“data.in”读入不同班级的朋友关系矩阵，每行对应一个班级。
输入样式：
$$ [[1,1,0],[1,1,0],[0,0,1]] $$
$$ [[1,1,0],[1,1,1],[0,1,1]] $$

### Output
对应班级的朋友圈个数，并将结果写到输出文件“output.o”中，每行一个，与输入文件的顺序对应。
输出样式：
```
2
1
```
注意：  
（1）N 的范围是[1,200]  
（2）对所有学生，M[i][i] = 1  
（3）如果M[i][j] = 1，则M[j][i] = 1

## 二.判断图是否连通
### Problem Description
You are given an undirected connected graph with N vertices and M edges that does not contain self-loops and double edges. 
The i-th edge (1≤i≤M) connects Vertex ai and Vertex bi. 
An edge whose removal disconnects the graph is called a bridge. 
Find the number of the edges that are bridges among the M edges.

Notes
A self-loop is an edge i such that ai=bi (1≤i≤M).  
Double edges are a pair of edges i,j such that ai=aj and bi=bj (1≤i ≤ M)


Constraints  
2≤N≤50  
N−1≤M≤min(N(N−1)⁄2,50)  
1≤ai< bi≤N  
The given graph does not contain self-loops and double edges.  
The given graph is connected.  

### Input
7 7  
1 3  
2 7  
3 4  
4 5  
4 6  
5 6  
6 7 
### Output
4 
