#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ClassName
{

};

int main ()
{
    vector <int> v = { 1, 3, 2, 1, 5, 4, 6, 8, 1, 0 , -1 };
    auto ascending = []( int x, int y )
                     {
                         return ( x < y );
                     };     // NOTE : function is not called - it's defined -- address will be stored in variable ascending
    auto descending = []( int x, int y ) { return ( x > y ); };     // NOTE : function is not called
    sort ( v.begin (), v.end () );
    cout << "\nsorted - default comparison " << endl;
    for ( auto x : v )
        cout << " " << x;

    sort ( v.begin (), v.end (), ascending );
    cout << "\nsorted - calling ascending " << endl;
    for ( auto x : v )
        cout << " " << x;

    sort ( v.begin (), v.end (), descending );
    cout << "\nsorted - calling descending " << endl;
    for ( auto x : v )
        cout << " " << x;

    return 0;

}
