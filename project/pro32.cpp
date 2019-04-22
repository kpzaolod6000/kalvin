#include<iostream>

using namespace std;

void primo(long n)
{
    int p=0;
    for(long i=2;n>1;++i)
    {
        while(n%i==0)
        {
            n=n/i;
            cout<<i<<endl;
            if(i>p)
            {
                p=i;
            }

        }
    }
    cout<<p<<endl;
}

int main()
{
    long n=600851475143;
    primo(n);
    return 0;
}
