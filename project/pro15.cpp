#include<iostream>

using namespace std;

unsigned long long int fact(int a,int b)
{
    unsigned long long int result1,result2,factrl1=1,factrl2=1,facden1=1,facden2=1;
    for(int i=a*10/13;i>=a/2+1;--i)//30a21
    {
        factrl1 *=i;
    }
    for(int j=a;j>=(a*10/13)+1;--j)//40a31
    {
        factrl2*=j;
    }
    
    for(int k=b;k>=(b/2)+1;--k)//20a11
    {
        facden1*=k;
    }
    for(int l=b/2;l>0;--l)//10a1
    {
        facden2*=l;
    }
    result1=factrl2/facden1;
    result2=factrl1/facden2;
    return result1*result2;
}

long long int result(int n)
{
    unsigned long long int rpta;
    rpta=fact(n,n/2);
    return rpta;
}
int main()
{
    int n=40;
    cout<<result(n)<<endl;
    cout<<40*10/13<<endl;
    return 0;
}