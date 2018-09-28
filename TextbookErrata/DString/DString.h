#include <iostream>


#ifndef DSTRING_INCLUDED_
#define DSTRING_INCLUDED_

const int nInitLen = 1024;
class DString{
	public:
		DString();
		~DString();
		DString(const DString& strSrc);
		DString(const char* chSrc);
		int GetLen() const{return nLen;}
		int IsEmpty() {return nLen? 0: 1;}
		void Empty() {nLen = 0; ch[0] ='\0';}
		DString GetSub(int nPos, int nCount) const;
		char operator [] (int nPos) const;
		DString& operator = (const DString &str);
		DString& operator += (const DString &str);
		int operator == (const DString &str) const;
		int Find(DString &strSub) const;
		
		friend std::ostream &operator << (std::ostream &stream, const DString& str);
		
	
	private:
		int nLen;
		char* ch;
		
};

#endif // DSTRING_INCLUDED_
