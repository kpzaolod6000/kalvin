#include<iostream>

using namespace std ;
class CDummy
{
    private:
        static int n;
    public:
        CDummy () { ++ n ; }
        ~ CDummy () { --n ; }
        static int getN(){return n;}
        
};

int CDummy :: n = 0;
int main ()
{
    CDummy a ;
    CDummy b [5];
    CDummy * c = new CDummy ;
    cout <<c->getN()<< "\n" ;
    delete c ;
    cout << CDummy :: getN() << "\n";
    return 0;
}