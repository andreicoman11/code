/*
ID: andreic4
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string tmp;
int ispal( int, int, int );

int main()
{
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    
    int base;
    fin >> base;
    
    for(int i=1; i<301; i++)
    {
        if( ispal( i, i*i, base ) ) fout << tmp << "\n";
    }
    
    //system("pause");
    return 0;
}

int ispal( int y, int x, int b)
{
    int pal[100];
    int i=0;
    int v[5];
    int jj=0;
    
    while( x )
    {
        pal[i++] = x%b;
        cout << pal[i-1] << " ";
        x = x/b;
    }
    //cout << "\n";
    for(int j=0; j<i; j++)
        if( pal[j]!=pal[i-j-1] ) return 0;
    
    tmp = "";
    string t;
    
    while( y )
    {
        v[jj++] = y%b;
        y = y/b;
    }
    
    while( jj )
    {
        if( v[--jj]<10 ) tmp += v[jj] + int('0');
        else tmp += v[jj] - 10 + int('A');
    }
    
    tmp += ' ';
    
    while( i )
    {
        if( pal[--i]<10 ) tmp += pal[i] + int('0');
        else tmp += pal[i] - 10 + int('A');
    }
    //cout << tmp << "\n";
    return 1;
}
