/*
ID: andreic4
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    string a,b;
    
    fin>>a>>b;
    int n=1,m=1;
    
    for(int i=0; i<a.size(); i++)
            n *= int(a[i])-int('A')+1;
    
    for(int i=0; i<b.size(); i++)
            m *= int(b[i])-int('A')+1;
    
    if( n%47 == m%47 ) fout << "GO\n";
    else fout << "STAY\n";
    
    return 0;
}
