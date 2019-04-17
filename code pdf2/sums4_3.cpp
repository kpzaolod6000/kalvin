#include<iostream>

using namespace std;

int sum ( const int x,const int y,const int z)
{
	return x+y+z;
}
int sum ( const int a,const int b,const int c,const int d) 
{
	return a+b+c+d;
}
int main()
{
	int a=10,b=20,c=30,d=40;
	cout<<sum(1,2,3)<<endl;
	cout<<sum(a,b,c,d)<<endl;
}
