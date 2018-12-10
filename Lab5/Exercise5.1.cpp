#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

template<class Type>
class List;

template<class Type>
class Node{
	friend class List<Type>;
	public:
		Node():link(NULL){
		}
		Node(const Type &v):data(v), link(NULL){
		}
	private:
		Type data;
		Node<Type> * link;
};

template<class Type>
class List{
	public:
		List():head(NULL), tail(NULL){
		}
		bool add(const Type& v);
		bool remove(const Type& v);
		bool find(const Type& v);
		void printList();
	private:
		Node<Type> *head, *tail;
};

template<class Type> 
bool List<Type>::add(const Type& v){
	if(head == NULL){
		head = new Node<Type>(v);
		tail = head;
	}else{
		tail -> link = new Node<Type>(v);
		tail = tail-> link; 
	}
	return true;
}

template<class Type> 
bool List<Type>::remove(const Type& v){
	Node<Type>* fake_h = new Node<Type>();
	fake_h -> link = head;
	Node<Type>* p = fake_h;
	while(p -> link != NULL && p -> link -> data != v){
		p = p -> link;
	}
	if(p -> link == NULL){
		return false;
	}
	Node<Type>* p0 = p -> link;
	if(p0 == tail){
		tail = p;
	}
	p -> link = p -> link -> link;
	head = fake_h -> link;
	return true;
}

template<class Type>
bool List<Type>::find(const Type& v){
	Node<Type>* p = head;
	while(p != NULL && p -> data != v){
		p = p -> link;
	}
	if(p == NULL){
		return false;
	}
	return true;
}

template<class Type>
void List<Type>::printList(){
	Node<Type>* p = head;
	while(p != NULL){
		cout << p -> data;
		if(p -> link == NULL){
			cout << endl;
		}else{
			cout << ' ';
		}
		p = p -> link;
	}
}

vector<string> split(const string &str){
	vector<string> res;
	for(int i=0;i<str.length(); ++i){
		if (str[i]==' ') {
			res.push_back(str.substr(0,i));
			res.push_back(str.substr(i+1,str.length()-i));
		}
	}
	return res; 
}

int main(){
	string str;
	string op,value;
	List<int> intList;
	while(getline(cin,str)){
		vector<string> vec_str = split(str);
		op = vec_str[0];
		value = vec_str[1];
		if(op=="add") cout<< intList.add(atoi(value.c_str())) << endl;
		if(op=="printList") intList.printList();
	}
	
}
