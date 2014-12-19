/*
ID: andreic4
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool v[125001] = {0};

int main()
{
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    
    int n,m;
    int say=1;
    fin >> n >> m;
    
    for(int i=0; i<=m; i++)
    for(int j=i; j<=m; j++)
        v[ i*i + j*j ] = 1;
    
    /*for(int l=0; l<50; l++)
        cout << l << " " << v[l] << "\n";
    cout << "\n";*/
    
    int rmax = (2*m*m)/(n-1);
    
    for(int i=1; i<=rmax; i++)
    for(int j=0; j<=2*m*m-n*i+i; j++)
    {
        while( !v[j] ) j++;
            int t=1;
            for(int k=1; k<n && t; k++)
                if( v[j+k*i]==0 ) t=0;
            if( t )
            {
                say=0;
                fout << j << " " << i << "\n";
            }
    }
    
    if( say ) fout << "NONE\n";
    system("pause");
    return 0;
}
