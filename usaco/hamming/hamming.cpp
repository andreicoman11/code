/*
ID: andreic4
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int dist( int a, int b);

int main()
{
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    
    int n,b,d;
    vector <int> v;
    v.push_back(0);
    fin >> n >> b >> d;
    
    fout << "0 ";
    n--;
    int put=1;
    
    for(int i=1; i<256 && n; i++)
    {
        int t=1;
        for(int j=0; j<v.size(); j++)
            if( dist( i,v[j] ) < d ) t=0;
        if ( t )
        {
            n--;
            v.push_back(i);
            fout << i;
            if( put==9 || n==0 ) { fout << "\n"; put=0; }
            else { fout << " "; put++; }
        }
    }
    
    
    return 0;
}

int dist( int a, int b)
{
    int t=0;
    while( a + b )
    {
        if( a%2 != b%2 ) t++;
        a /= 2;
        b /= 2;
    }
    return t;
}
