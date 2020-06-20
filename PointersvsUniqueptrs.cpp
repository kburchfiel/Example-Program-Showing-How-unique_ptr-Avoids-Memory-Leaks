
//AMDG
//This example C++ program compares memory usage of two functions, one of which assigns new characters to a regular pointer, and the other of which assigns new characters to a unique pointer. Running this program on Visual Studio Community and observing the Process Memory window within Diagnostic Tools confirms that the newcharsusingptr() function leaks memory, whereas the newcharsusinguniqueptr() function doesn't.
//Because newcharsusingptr() DOES leak memory, be careful about running it for too long!
//Kenneth Burchfiel, 2020-06-19

#include <iostream>
#include <memory>

using namespace std;

void newcharsusinguniqueptr()
{
    unique_ptr<char> ucp{new char[1]};
    // ucp.release(); //If ucp.release() is added, newcharsusinguniqueptr will indeed leak memory just like newcharsusingptr.
}

void newcharsusingptr()

{
    char *cp = new char[1];
}

int main()
{
    int i = 0;
    cout << "The function has run this many times:\n";
    while (true)
    {
        newcharsusinguniqueptr(); //Set this either to newcharsuninguniqueptr or newcharsusingptr to compare their memory use.
        i++;
        cout << i << "\n";
    }
}