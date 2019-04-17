#include<iostream>

using namespace std;

int main()
{
	int N=1000,sum=0;
	for(int i=1;i<N;++i)
	{
		if((i%3==0) || (i%5==0))
		{	
			cout<<i<<" ";
			sum+=i;
		}
	}
	cout<<endl<<sum<<endl;
	return 0;
}
