/*
ID: andreic4
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n;
int p[4] = { 2, 3, 5, 7 };
int v[4] = { 1, 3, 7, 9 };

void rec( int i, long long nr);
bool prime( long long x);
ofstream fout ("sprime.out");

int main()
{
    ifstream fin ("sprime.in");
    
    fin >> n;
    
    rec( 0, 0);    
    
    return 0;
}

void rec( int i, long long nr)
{
    if( i>=n )
    {
        fout << nr << "\n";
    }
    else
    {
        if( i==0 ) 
        {
            for(int j=0; j<4; j++)
            {
                nr = p[j];
                rec(i+1, nr);
            }
        }
        else
        {
            for(int j=0; j<4; j++)
            {
                nr = nr*10 + v[j];
                if( prime(nr) ) rec(i+1, nr);
                nr = nr/10;
            }
        }
    }
}

bool prime( long long x )
{
    for( long long i=3; i*i<=x; i+=2)
        if( x%i==0 ) return 0;
    return 1;
}
