#include<iostream>

using namespace std;

void swap(int *x,int *y)
{
	int tmp=*x;
	*x=*y;
	*y=tmp;
}
int main()
{
	int a=10,b=20;
	cout<<"valor de a: "<<a<<endl;
	cout<<"valor de b: "<<b<<endl;
	swap(&a,&b);
	cout<<"el nuevo valor de a: "<<a<<endl;
	cout<<"el nuevo valor de b : "<<b<<endl;
	
}
