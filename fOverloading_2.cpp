// Function Overloading
#include <iostream>

using namespace std;

void printLine ( void );
void printLine ( int );
void printLine ( char );
void printLine ( char, int );

int main ()
{
    printLine ();
    printLine ( 10 );
    printLine ( '$' );
    printLine ( 'a', 20 );

    return 0;
}

void printLine ( void )
{
    int i;
    for ( i = 1; i <= 10; i++ )
        cout << "*";
}

void printLine ( int x )
{
    int i;
    for ( i = 1; i <= x; i++ )
        cout << "*";
}

void printLine ( char c )
{
    int i;
    for ( i = 1; i <= 10; i++ )
        cout << c;
}

void printLine ( char c, int x )
{
    int i;
    for ( i = 1; i <= x; i++ )
        cout << c;
}
