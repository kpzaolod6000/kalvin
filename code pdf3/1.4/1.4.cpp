#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s = "Hello " ;
    s += "world!" ;

    if ( s == "Hello world!" ) {
        cout<<"Success!"<<endl;
    }
    cout<<s.substr (6,6)<<endl ; // Prints " world !"
    cout<<s.find ("world"); // ( prints "6")
    cout<<s.find ('l',5); // ( prints "9")
}
