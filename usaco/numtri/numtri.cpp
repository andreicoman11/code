/*
ID: andreic4
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    
    int v[2][1000];
    int n;
    fin >> n;
    fin >> v[0][0];
    
    for(int i=1; i<n; i++)
    {
        
        for(int j=0; j<=i; j++)
            fin >> v[1][j];
        
        for(int j=0; j<=i; j++)
        {
            if( j==0 ) v[1][j] += v[0][j];
            else if( j==i ) v[1][j] += v[0][j-1];
            else v[1][j] += max( v[0][j-1], v[0][j] );
        }
        for(int j=0; j<=i; j++)
            v[0][j] = v[1][j];
    }
    
    int max = v[0][0];
    for(int i=1; i<=n; i++)
        if( v[0][i] > max ) max = v[0][i];
    
    fout << max << "\n";
    
    return 0;
}
