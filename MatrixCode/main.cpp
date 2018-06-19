#include"Header.h"
#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
	matrixtype a(3,4,2);
	++a;
	matrixtype b(a);
	
	b.print();
	cout<<endl;
	cout<<endl;
	matrixtype c=a+b;


	c.print();

	cout<<endl;
	cout<<endl;
	matrixtype d=a*4;


	d.print();

	cout<<endl;
	cout<<endl;
	matrixtype e=a-b;


	e.print();
	a+=b;
	a==b;
	
	//cout<<a.getEntries;







}