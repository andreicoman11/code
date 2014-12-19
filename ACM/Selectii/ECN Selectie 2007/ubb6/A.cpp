#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

ifstream fin("A2.in");
ofstream fout("A.out");

int n, v[100001];

int main()
{
    fin >> n;
    while( n )
    {
        for(int i=1;i<=n; i++)
        {
            fin >> v[i];
        }
             
        int ok = 1;
        for(int i=1; i<=n && ok; i++)
            if( i != v[ v[i] ] ) ok = 0;
        
        if( ok ) fout << "ambiguous\n";
        else fout << "not ambiguous\n";
        
        fin >> n;
    }
    return 0;
}
