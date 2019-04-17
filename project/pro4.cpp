#include <iostream>
using namespace std;

int main()
{
	bool pr = false;
	long m;
	int i=999;
	while(i>99)
	//for(int i=999;i>99;--i)
	{
		int j=999;
		while(j>99)
	//for(int j=999;j>99;--j)
		{
		m=i*j;
	       	int b=m/100000%10;
	        int c=m/10000%10;
	        int d=m/1000%10;
	        int e=m/100%10;
	        int f=m/10%10;
	        int g=m%10;
		if (m>99999 && m<1000000)
		{	if (b==g && c==f && d==e)
			{
				cout<<m<<endl;
				pr=true;
			}
			else
			{
				pr=false;
			}
		}
		/*else if (m>9999 && m<100000)
		{
			if (d==f && g==c)
  	         	{
  	             		cout<<m<<endl;
				break;
			}
		
		}*/
		if(pr==true)
		{
			break;
		}
		--j;
		}
	--i;
	}
	
	return 0;
}
