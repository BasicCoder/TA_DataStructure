#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
using namespace std;

template <typename T>
class BinTreeNode
{
public:
    BinTreeNode(const T&t):data(t),lChild(NULL),rChild(NULL){}
    T data;
    BinTreeNode *lChild, *rChild;
};

template <typename T>
class BinTree
{
public:
	BinTreeNode<T> *root;//二叉树的根节点

    void create();
	void recursive_f(BinTreeNode<T> *);
	void recursive_flatten();
	void non_recursive_f(BinTreeNode<T> *);
	void non_recursive_flatten();
	void printBinTreeList();
};

template<typename T>
void BinTree<T>::create()//按层次建立树
{	
	cout<<"按层构建二叉树，输入格式[1,2,3,4,null,null,7]:"<<endl;
	char buf[1000]; 
    cin.getline(buf, sizeof(buf));//读入一行 
	int a[100]; // 二叉树节点的值均为正整数
    int cnt = 0;  //初始化”输入数字个数“ 
	a[cnt]=0;
    for(int i = 0; buf[i] != ']'; i++){ 
		if(buf[i]=='['){
			cout<<"开始解析输入的字符串 ..."<<endl;
		}else if(buf[i] == ','){  //下一个数，初始化相关变量 
            a[++cnt] = 0; 
        }else if(buf[i]=='n'){
			a[cnt]=-1;
		}else if(isdigit(buf[i])){ //处理数字
                a[cnt] *= 10;  //当前数值整体*10 
                a[cnt] += buf[i] - '0'; //加上该位数字 
		}
    } 

	cout<<"输入序列为：";
	for(int i = 0; i <=cnt; i++) 
		cout << a[i]<<" "; 
	cout<<endl;

    BinTreeNode<T>** (arr[100]) = {};
    /*
      保存指向每个节点的指针，比如建立下面这样的树(括号左边是序号，括号里面节点元素,以整型为例,输入
     0表示为空节点):

               1(1)
          2(2)        3(3)
       4(0)   5(4)   6(5)  7(6)

       输入时应输入:1 2 3 0 4 5 6
       比如处理节点元素为4时，要改变其双亲节点，对吧，令其双亲的rChild指针指向正在处理的节点，所以
       我就定义一个数组保存指针
    */
    for(int i=1;i<=cnt+1;i++) //i表示正在处理的节点的序号，初始化为处理第一个节点
    {	

        if (i==1)//第一个元素，处理根节点
        {
            arr[i-1] = &root;
            root = new BinTreeNode<T>(a[i-1]);
            continue;
        }

        if (a[i-1]==-1)//如果是空节点
        {
            if (i%2 == 0&&(arr[i/2-1]))//能够被2整除，那么该节点为其双亲的左孩子，并且其双亲应该存在，才可以令其双亲的左孩子指针为空
                ((*arr[i/2-1]))->lChild = NULL;
            else if(arr[i/2-1])//否咋是其右孩子
                ((*arr[i/2-1]))->rChild = NULL;
            arr[i-1] = NULL;//此节点为空
            continue;
        }

        arr[i-1] = new BinTreeNode<T> *;//节点不为空
        BinTreeNode<T> *temp = new BinTreeNode<T>(a[i-1]);
        if (i%2 == 0&&(arr[i/2-1]))
            (*arr[i/2-1])->lChild = temp;//同理
        else (*arr[i/2-1])->rChild = temp;
        *arr[i-1] = temp;//保存节点指针
    }
}

template <typename T>
void BinTree<T>::recursive_f(BinTreeNode<T> *root){
        if (!root) return;
		if (root->lChild) recursive_f(root->lChild);
		if (root->rChild) recursive_f(root->rChild);
		BinTreeNode<T> *tmp = root->rChild;
		root->rChild = root->lChild;
		root->lChild = NULL;
		while (root->rChild) root = root->rChild;
		root->rChild = tmp;
}

template <typename T>
void BinTree<T>::non_recursive_f(BinTreeNode<T>* root) {
    if (!root) return;
    stack<BinTreeNode<T>*> s;
    s.push(root);
    while (!s.empty()) {
        BinTreeNode<T> *t = s.top(); s.pop();
		if (t->lChild) {
			BinTreeNode<T> *r = t->lChild;
			while (r->rChild) r = r->rChild;
			r->rChild = t->rChild;
			t->rChild = t->lChild;
			t->lChild = NULL;
        }
		if (t->rChild) s.push(t->rChild);
    }
}

template <typename T>
void BinTree<T>::recursive_flatten() {
	recursive_f(root);
}

template <typename T>
void BinTree<T>::non_recursive_flatten() {
	non_recursive_f(root);
}

template<typename T>
void BinTree<T>::printBinTreeList(){
	auto *p = root;
	while(p){
		cout<<p->data<<' ';
		p = p->rChild;
	}
	cout<<endl;
}

int main()
{	
    BinTree<int> myBinTree;
    myBinTree.create();
	//myBinTree.non_recursive_flatten();
	myBinTree.recursive_flatten();
	myBinTree.printBinTreeList();
    return 0;
}