#include<iostream>
using namespace std;
int main()
{

    long n=1000000,m=1,max=0,pos=0;
    for(int i=2;i<n;++i)
    {
        cout<<i<<" ";
        long num=i;
        while(num>1)
        {
            if(num%2==0)
            {
                num=num/2;
                m++;
            }
            else
            {
                num=(3*num)+1;
                m++;
            }
        }
        cout<<m<<endl;
        if(m>max)
        {
            max=m;
            pos=i;
        }
        m=1;
    }
    cout<<"posicion: "<<pos<<" terminos: "<<max<<endl;
    cout<<endl;
    return 0;
}