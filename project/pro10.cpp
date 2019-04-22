#include<iostream>
using namespace std;
int verif(long m)
{
    for(int i=3;i<m/2;i+=2)
    {
        if(m%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void primo(long n)
{
    long sum=0;
    for(long i=3;i<n;i+=2)
    {
        if(verif(i)==1)
        {
            sum+=i;
        }
    }
    cout<<2+sum<<endl;

}
int main()
{
    int n=2000000;
    primo(n);
    return 0;
}