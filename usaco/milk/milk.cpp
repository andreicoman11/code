/*
ID: andreic4
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    
    int n,m, a[5000][2];
    fin >> n >> m;
    
    for( int i=0; i<m; i++)
        fin >> a[i][0] >> a[i][1];
        
    int da=1;
    while( da )
    {
        da=0;
        for( int i=0; i<m-1; i++)
            if( a[i][0]>a[i+1][0] ) 
            {
                da = a[i][0];
                a[i][0] = a[i+1][0];
                a[i+1][0] = da;
                da = a[i][1];
                a[i][1] = a[i+1][1];
                a[i+1][1] = da;
                da=1;
            }
    }
    
    int price=0,i=0;
    
    while( n )
    {
        if( a[i][1]<n )
        {
            n -= a[i][1];
            price += a[i][1]*a[i][0];
        }
        else
        {
            price += n*a[i][0];
            n=0;
        }
        i++;
    }
    
    fout << price << "\n";
    return 0;
}
