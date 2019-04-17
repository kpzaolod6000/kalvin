#include<iostream>

using namespace std;

int main()
{	
	int a=0,N=1,c,acc=0;
	do
	{
		if (N%2==0)
  		{
			acc+=N;
		}
		c=a+N;
		a=N;
		N=c;
	}
	while(N<4000000);
	
	cout<<acc<<endl;
	return 0;
	
}
