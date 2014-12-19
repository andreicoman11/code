/*
ID: andreic4
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ispal( int );
int pal( int, int);

int main()
{
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    
    int n,s;
    fin >> n >> s;
    
    while( n )
    {
        s++;
        if( ispal(s) ) { n--; fout << s << "\n"; }
    }
    
    //system("pause");
    return 0;
}

int ispal( int x )
{
    int t=0;
    
    for(int j=2; j<=10 && t<2; j++)
        if( pal(x,j) ) { t++; cout << x << " base " << j << "\n"; }
        
    if( t==2 ) return 1;
    return 0;
}

int pal(int x, int b)
{
    int pal[100];
    int i=0;
    
    while( x )
    {
        pal[i++] = x%b;
        cout << pal[i-1] << " ";
        x = x/b;
    }
    //cout << "\n";
    for(int j=0; j<i; j++)
        if( pal[j]!=pal[i-j-1] ) return 0;
    
    //cout << tmp << "\n";
    return 1;
}
