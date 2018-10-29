#include <iostream>
#include <stack>

using namespace std;

void hanoi_recursion(int n, char a, char b, char c){
	if(n>0){
		hanoi_recursion(n-1, a, c, b);
		cout << "Move " << a << " to " << c << endl;
		hanoi_recursion(n-1, b, a, c);
	}
}
struct hanoiunrec{
	hanoiunrec();
	hanoiunrec(int _n, char _a, char _b, char _c):n(_n), a(_a), b(_b), c(_c){}
	int n;
	char a, b, c;
};


void hanoi(int n, char a, char b, char c){
	stack<hanoiunrec> s;
	s.push(hanoiunrec(n, a, b, c));
	while(!s.empty()){
		hanoiunrec q = s.top();
		s.pop();
		n = q.n;
		a = q.a;
		b = q.b;
		c = q.c;
		if(n == 1){
			cout << "Move " << q.a << " to " << q.c << endl;
		}else{
			s.push(hanoiunrec(n-1, b, a, c));
			s.push(hanoiunrec(1, a, b, c));
			s.push(hanoiunrec(n-1, a, c, b));
		}
	}
}

int main(){
	int n;
	cin >> n;
	hanoi_recursion(n, 'A', 'B', 'C');
	cout << "--------" << endl;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
