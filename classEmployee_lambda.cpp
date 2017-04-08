#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Data
{
    int     id;
    string  name;
    double  salary;
};

class Employee
{
        vector <Data>   vData;
    public:
        void setData ( const Data & );
        Data readData ( void );
        void showData ( void ) const;
        void sortData ( bool = true );

        void sendToFile ( string );
};

void Employee::setData ( const Data &data )
{
    vData.push_back ( data );
}

void Employee::showData ( void ) const
{
    for ( auto tData : vData )
    {
        cout << endl << ( tData.id ) << " " << tData.name << " " << tData.salary;
    }
}

void Employee::sortData ( bool order )
{
    auto lambdaA = [] ( Data first, Data second )
    {
        return ( first.id < second.id );
    };

    auto lambdaD = [] ( Data first, Data second )
    {
        return ( first.id > second.id );
    };

    if ( order == true )
    {
        sort ( vData.begin (), vData.end (), lambdaA );
    }
    else
    {
        sort ( vData.begin (), vData.end (), lambdaD );
    }
}

Data Employee::readData ( void )
{
    Data temp;

    cout << "Enter id     : ";
    cin >> temp.id;
    cout << "Enter nanme  : ";
    cin >> temp.name;
    cout << "Enter salary : ";
    cin >> temp.salary;

    return temp;
}

void Employee::sendToFile ( string fName )
{
    ofstream fOut { fName };

    if ( nullptr == fOut )
    {
        cerr << "Failed to create " << fName;
    }
    else
    {
        // transferring data -- text mode
        for ( auto object : vData )
        {
            fOut << object.id       << endl;
            fOut << object.name     << endl;
            fOut << object.salary   << endl;
        }

        fOut.close ();
    }
}

int main ()
{
    Employee emp;
    Data     data[] = { { 1, "raj", 4000 },
                        { 2, "ravi", 5000 },
                        { 3, "raghu", 6000 }
                      };
    // reads user input from standard input device
    emp.setData ( emp.readData ( ) );
    emp.setData ( emp.readData ( ) );

    // pushing data from array data [] to emp
    for ( auto v : data )
        emp.setData ( v );

    emp.showData ();

    emp.sortData ();    // ascending order
    emp.showData ();

    emp.sortData ( false ); // descending order
    emp.showData ();

    emp.sendToFile ( "employee.data" );

    return 0;
}

