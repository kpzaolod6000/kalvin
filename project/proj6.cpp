#include<iostream>

using namespace std;

int main()
{
	long acc=0,acc1=0;
	for(int i=1;i<=100;++i)
	{
		acc=acc+(i*i);
	}

	for(int i=1;i<=100;++i)
	{
		acc1+=i;
	}
	cout<<(acc1*acc1)-acc<<endl;
	return 0;


}
