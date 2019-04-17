#include<iostream>

using namespace std;

void swap(int &x, int &y) 
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int a=10,b=20;
 
	cout<<"valor de a: "<<a<<endl;
	cout<<"valor de b: "<<b<<endl;
	
	swap(a, b);

	cout<<"nuevo valor de a: " <<a<< endl;
	cout<<"nuevo valor de b: " <<b<< endl;
 	return 0;
}
