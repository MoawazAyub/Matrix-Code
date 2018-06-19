#include"Header.h"
#include<iostream>
using namespace std;

 matrixtype::matrixtype(int a, int b, int c ){

	 	allocate(a,b);
	assignNumber(c);




 }




 //
 void operator<< (ofstream & out,const matrixtype & obj) {
	 for(int i=0;i<obj.rows;i++){

		 for(int j=0;i<obj.cols;j++)
		 {
			 cout<<obj.mat[obj.rows][obj.cols];
		 }}
};

void matrixtype::deallocate () {
	for (int i = 0; i < rows; i++)
		delete[] mat[i];
	delete[] mat;
};

void matrixtype::allocate(int r, int c) {
	rows = r; cols = c;
	mat = new int*[rows];
	for (int i = 0; i < rows; i++)
		mat[i] = new int[cols];
}

void matrixtype::assignNumber (int a) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mat[i][j] = a;
}


matrixtype::matrixtype () {
	allocate(1,1);
	assignNumber(0);
}

matrixtype::matrixtype (int r, int c) {
	allocate(r,c);
	assignNumber(0);
}

matrixtype::matrixtype (const matrixtype & obj) {
	allocate(obj.rows,obj.cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mat[i][j] = obj.mat[i][j];
}


 matrixtype matrixtype::operator++ () {

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mat[rows][cols]+1;
	 return *this;
}
void matrixtype::makeMatrix(int a, int b) {
	deallocate();
	allocate(a,b);
	assignNumber(0);
}

void matrixtype::getEntries () {
	cout << "Enter Elements Row-Wise : " << endl;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			cin >> mat[i][j];
}

void matrixtype::print () {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

const matrixtype & matrixtype::operator= (const matrixtype & obj) {
	deallocate();
	allocate(obj.rows,obj.cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mat[i][j] = obj.mat[i][j];
	return *this;
};

const matrixtype & matrixtype::operator=(int a) {
	assignNumber(a);
	return *this;
}

matrixtype matrixtype::operator+ (const matrixtype & obj) {
	matrixtype temp;
	if (rows != obj.rows || cols != obj.cols) {
		cout << "Cannot Add both Matrices!" << endl;
		return temp;
	}
	temp.allocate(rows,cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp.mat[i][j] = mat[i][j] + obj.mat[i][j];

	return temp;
}

void matrixtype::operator+= (const matrixtype & obj) {
	*this = *this + obj;
}

matrixtype matrixtype::operator- (const matrixtype & obj) {
	matrixtype temp;
	if (rows != obj.rows || cols != obj.cols) {
		cout << "matrix can not be subtracted!!!!!!" << endl;
		return temp;
	}
	temp.allocate(rows,cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp.mat[i][j] = mat[i][j] - obj.mat[i][j];

	return temp;
}

void matrixtype::operator-= (const matrixtype & obj) {
	*this = *this - obj;
}

bool matrixtype::operator== (const matrixtype & obj) {
	if (rows != obj.rows || cols != obj.cols)
		return false;
	bool equal = true;
	for (int i = 0; i < rows && equal; i++)
		for (int j = 0; j < cols && equal; j++)
			equal = (mat[i][j] == obj.mat[i][j]);
	return equal;
}

bool matrixtype::operator!=(const matrixtype & obj) {
	return !(*this == obj);
}

matrixtype::~matrixtype () {
	deallocate();
	mat = NULL;
}

matrixtype matrixtype::operator* (int a) {
	matrixtype temp;
	temp.makeMatrix(rows,cols);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp.mat[i][j] = a * mat[i][j];

	return temp;
}

matrixtype operator* (int n, matrixtype & obj) {
	matrixtype temp;
	temp = (obj) * (n);
	return temp;
}

matrixtype  matrixtype::operator- () {
	matrixtype temp;
	temp = (-1) * (*this);
	return temp;
}

const matrixtype & matrixtype::transpose () {
	int ** trans = new int*[cols];
	for (int i =0; i < cols; i++)
		trans[i] = new int[rows];
	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++)
			trans[i][j] = mat[j][i];
	deallocate();
	mat = trans;
	int temp = rows;
	rows = cols;
	cols = temp;
	return *this;
}

matrixtype matrixtype::operator* (const matrixtype & obj) {
	matrixtype temp;
	if (cols != obj.rows) {
		cout << "Cannot multiply matrices!" << endl;
		return temp;
	}
	temp.allocate(rows,obj.cols);
	for (int i = 0; i < temp.rows; i++)
		for (int j = 0; j < temp.cols; j++) {
			temp.mat[i][j] = 0;
			for (int k = 0; k < cols; k++)
				temp.mat[i][j] += (mat[i][k] * obj.mat[k][j]);
		}

		return temp;
}







