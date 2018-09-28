#include <iostream>
#include <string.h>
#include "DString.h"
using namespace std;

DString::DString(){
	ch = new char[nInitLen+1];
	if(!ch){cerr <<"Allocate Error! \n"; return;}
	nLen = 0;
	ch[0] = '\0';
}

DString::~DString(){
	delete []ch;
}

DString::DString(const DString &strSrc){
	nLen = strSrc.GetLen();
	if(nLen > nInitLen)
		ch = new char[nLen + 1];
	else
		ch = new char[nInitLen + 1];
	if(!ch){cerr << "Allocate Error! \n"; return;}
	
	strcpy(ch, strSrc.ch);
}

DString::DString(const char* chSrc){
	nLen = strlen(chSrc);
	if(nLen > nInitLen)
		ch = new char[nLen + 1];
	else
		ch = new char[nInitLen + 1];
	
	if(!ch){cerr << "Allocate Error! \n"; return;}
	
	strcpy(ch, chSrc);
}

DString DString::GetSub(int nPos, int nCount)const{
	DString tmpString;
	char* pch;
	if(nPos < 0 || nCount < 0 || nPos + nCount -1 >= nLen){
		tmpString.nLen = 0; tmpString.ch[0] = '\0';
	}else{
		if(nPos + nCount -1 < nLen) nCount = nLen - nPos;
		tmpString.nLen = nCount;
		pch = ch + nPos;
		memcpy(tmpString.ch, pch, nCount);
		tmpString.ch[nCount] = '\0';
	}
	return tmpString;
}

DString& DString::operator = (const DString& str){
	if(&str != this){
		delete []ch;
		nLen = str.nLen;
		if(nLen > nInitLen)
			ch = new char[nLen + 1];
		else
			ch = new char[nInitLen + 1];

		// if(!ch){cerr << "Allocate Error! \n"; return 0;}	
		if(!ch){cerr << "Allocate Error! \n"; throw ;}	
		/* 
		教材中写法为:
		 return 0;
		返回值跟函数返回值不一致，编译错误。
		修改办法：
		a) throw;

		b) nLen = 0;
		   ch[0] = '\0';
		   return *this;

		c) try{

		}catch(){

		}
		*/ 
		
		strcpy(ch, str.ch);
	} 
	return *this;
}

DString& DString::operator += (const DString &str){
	char * temp = ch;
	int n = nLen + str.nLen;
	int m = (nInitLen >= n) ? nInitLen:n;
	
	ch = new char[m+1];
	// if(!ch){cerr << "Allocate Error! \n"; return 0;}	// 与 operator = 中的修改相同。
	if(!ch){cerr << "Allocate Error! \n"; throw ;}
	nLen = n;
	strcpy(ch, temp);
	strcat(ch, str.ch);
	delete []temp;
	return *this;
} 

int DString::operator ==(const DString &str) const{
	return strcmp(ch, str.ch);
}

int DString::Find(DString &strSub) const{
	int n = GetLen();
	int m = strSub.GetLen();
	
	for (int j = 0; j <= n -m; ++j){
		int i = 0;
		for(i = 0; i < m && strSub[i] == ch[i+j]; ++i);
		if(i >= m)
			return j;
	}
	return -1;
} 

char DString::operator[] (int nPos) const{
	if(nPos < 0 && nPos >= nLen){
		cerr << "nPos Out of Bounds!" << endl; return 0;
	}
	return ch[nPos];
} 

ostream& operator << (ostream& stream, const DString& str){
	stream << str.ch;
	return stream;
}
	

