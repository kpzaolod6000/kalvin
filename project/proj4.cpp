#include <iostream>

using namespace std;

int palindromo(long multi) 
{
	long invertir=0, n=multi,max=0;
	while(n>0) 
	{
		invertir=invertir*10+n%10;
		n/=10;	
	}
	return multi == invertir;
}

int main()
{
	long max=0;
	for(int i=100;i<=999;++i)
        {
        	for(int j=100;j<=999;++j)
        	{
        	        long m=i*j;
			if(palindromo(m) && m >max);
			{
				max=m;
			}
		
		}
	}
	cout<<max<<endl;
	return 0;
}
