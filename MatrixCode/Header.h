
	
	#include <iostream>

using namespace std;

class matrixtype {
	int ** mat;
	int rows;
	int cols;
	void deallocate();
	void allocate(int , int);
	void assignNumber(int);
public:

	matrixtype(int , int ,int);
	matrixtype();
	
	matrixtype(int , int);
	matrixtype(const matrixtype &);
	void makeMatrix(int , int);
	void getEntries();
	void print();
	
	const matrixtype & operator=(const matrixtype &);
	const matrixtype & operator=(int);
	matrixtype operator+(const matrixtype &);
	void operator+=(const matrixtype &);
	friend void  operator<<(ofstream &,const matrixtype &);
	 matrixtype operator++();
	 matrixtype operator-(const matrixtype &);
	void operator-=(const matrixtype &);
	matrixtype operator-();
	bool operator==(const matrixtype &);
	bool operator!=(const matrixtype &);
	matrixtype operator* (int);
	const matrixtype & transpose();
	matrixtype operator* (const matrixtype &);
	~matrixtype();
};

matrixtype operator* (int , matrixtype &);
//matrixtype operator++(int x=0);













