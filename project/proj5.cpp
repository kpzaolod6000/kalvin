#include<iostream>

using namespace std;

int main()
{
	long long m=0,g=10000000000;
	for(long long j=1000000000;j>100000000;--j)
	{
		m=0;
		for(int i=1;i<=20;++i)
		{
			if(j%i==0)
			{
				m++;
			}
		}

		if (m==20)
		{
			if(j<g)
			{
				g=j;
			}
		}
	}
	cout<<g<<endl;
}
