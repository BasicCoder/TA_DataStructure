#include "stdafx.h"
#include<iostream>
# include<string>
using namespace std;

template <typename T>
class BinTreeNode
{
public:
    T data;
    BinTreeNode *lChild, *rChild;
	BinTreeNode(const T&t):data(t),lChild(NULL),rChild(NULL){}
};

template <typename T>
class BinTree
{
public:
    void create(); // 按层创建二叉树
	BinTreeNode<T>* lowestCommonAncestor(BinTreeNode<T>* root, BinTreeNode<T>* p, BinTreeNode<T>* q);// 最小共同父节点递归求解函数
	void lca(); // 对lowestCommonAncestor的封装，方便调用
	BinTreeNode<T> *root; //二叉树的根节点
	BinTreeNode<T> *p; //所需求解最小共同父节点的一个节点
	BinTreeNode<T> *q; //所需求解最小共同父节点的另一个节点
};

template<typename T>
void BinTree<T>::create()//按层构建二叉树
{	
	cout<<"按层构建二叉树，输入格式[1,2,3,4,null,null,7,4,7]，其中最后两个数为需要求解最小共同父节点的那两个节点:"<<endl;
	char buf[1000]; 
    cin.getline(buf, sizeof(buf));//读入一行 
	int a[100]; // 二叉树节点的值均为正整数
    int cnt = 0;  //初始化”输入数字个数“ 
	a[cnt]=0;
    for(int i = 0; buf[i] != ']'; i++){ 
		if(buf[i]=='['){
			cout<<"开始解析输入的字符串..."<<endl;
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

	int p_value=a[cnt-1];
	int q_value=a[cnt];

    BinTreeNode<T>* (arr[100]) = {}; //辅助指针数组
    /*
      保存指向每个节点的指针，比如建立下面这样的树(括号左边是序号，括号里面节点元素,以整型为例,输入
     0表示为空节点):

                  1(1)
           2(2)         3(3)
       4(0)   5(4)   6(5)  7(6)

       输入时应输入:1 2 3 0 4 5 6
       比如处理节点元素为4时，要改变其双亲节点，令其双亲的rChild指针指向正在处理的节点，所以就定义一个数组保存指针
    */
    for(int i=1;i<=cnt-1;i++) //i表示正在处理的节点的序号，初始化为处理第一个节点
    {	
        if (i==1)//第一个元素，处理根节点
        {
            
            root = new BinTreeNode<T>(a[i-1]);
			arr[i-1] = root;
			if(a[i-1]==p_value) p=root;
			if(a[i-1]==q_value) q=root;
            continue;
        }

        if (a[i-1]==-1)//如果是空节点
        {
            if (i%2 == 0&&(arr[i/2-1]))//能够被2整除，那么该节点为其双亲的左孩子，并且其双亲应该存在，才可以令其双亲的左孩子指针为空
                ((arr[i/2-1]))->lChild = NULL;
            else if(arr[i/2-1])//否咋是其右孩子
                ((arr[i/2-1]))->rChild = NULL;
            arr[i-1] = NULL;//此节点为空
            continue;
        }

        //arr[i-1] = new BinTreeNode<T>;//节点不为空
        BinTreeNode<T> *temp = new BinTreeNode<T>(a[i-1]);
		arr[i-1] = temp;
        if (i%2 == 0&&(arr[i/2-1]))
            (arr[i/2-1])->lChild = temp;//同理
        else (arr[i/2-1])->rChild = temp;
        arr[i-1] = temp;//保存节点指针

		if(a[i-1]==p_value) p=temp;
		if(a[i-1]==q_value) q=temp;
    }
}

template <typename T>
BinTreeNode<T>* BinTree<T>::lowestCommonAncestor(BinTreeNode<T>* root, BinTreeNode<T>* p, BinTreeNode<T>* q) {
	   // root为空，无法继续往下找
	   // 或者找到了某个匹配的，则不继续从root节点往下找，
	   // 因为(1)如果之前已经找到了一个匹配的，现在又找到另一个匹配的，则没必要继续往下找
	   //     (2)如果之前未找到任何匹配的，另一个待匹配的节点一定低于root这个层次，则root已经为两个节点的最小共同父节点
       if (!root || p == root || q == root) return root;

	   // 如果root不为空且不等于待查找节点，则查找root的左子树
	   BinTreeNode<T> *left = lowestCommonAncestor(root->lChild, p, q);
	   // 已经找到最小共同父节点，即最小共同父节点在root的左子树上
       if (left && left != p && left != q) return left;

	   // 左子树为空或者找到一个，查找root右子树
	   BinTreeNode<T> *right = lowestCommonAncestor(root->rChild, p , q);
	   // 已经查找到最小共同父节点，即最小共同父节点在root的右子树上
	   if (right && right != p && right != q) return right;
       
	   // 右子树为空或者找到一个
	   // p和q分别在root的左、右子树上，则root为p和q的最小共同父节点，则返回该层的root
	   if (left && right) return root;
       
	   // 在root这一层的左子树或者右子树找到一个，返回找到的那个
	   // 或者在root这一层未找到任何节点，返回空
	   return left ? left : right;
}

template <typename T>
void BinTree<T>::lca(){
	BinTreeNode<T>* r = lowestCommonAncestor(root, p, q);
	cout<<"节点p="<<p->data<<"和节点q="<<q->data<<"的最小共同父节点为："<<r->data<<endl;
}

int main_tt()
{	
    BinTree<int> myBinTree;
    myBinTree.create();
	myBinTree.lca();

    return 0;
}