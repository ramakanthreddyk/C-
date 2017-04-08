#include <iostream>

using namespace std;

void order ( float *, int );
void order ( int *, int );

void display ( float *, int );
void display ( int *, int );

int main ()
{
    float x[10] = { 1.1, 10.2, 2.0, 3.1, 5.4, 6.2 };
    int i[10] = { 20, 30, 0, 20, 10, 20, 30, 40, 40, 30 };

    order ( x, 10 );
    order ( i, 10 );

    display ( x, 10 );
    display ( i, 10 );

    return 0;
}

void order ( float *s, int n )
{
    int i, j;
    float t;

    for ( i = 0; i < n - 1; i++ )
    {
        for ( j = 0; j < n - i - 1; j++ )
        {
            if ( s[j] > s[j+1] )
            {
                t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
}

void display ( float *s, int n )
{
    int i;

    for ( i = 0; i < n; i++ )
    {
        cout << " " << s[i];
    }
}

void order ( int *s, int n )
{
    int i, j;
    int t;

    for ( i = 0; i < n - 1; i++ )
    {
        for ( j = 0; j < n - i - 1; j++ )
        {
            if ( s[j] > s[j+1] )
            {
                t = s[j];
                s[j] = s[j+1];
                s[j+1] = t;
            }
        }
    }
}

void display ( int *s, int n )
{
    int i;

    for ( i = 0; i < n; i++ )
    {
        cout << " " << s[i];
    }
}
