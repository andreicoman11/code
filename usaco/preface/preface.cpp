/*
ID: andreic4
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int v[7] = {0};

void paint(int);

int main()
{
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
    
    int n;
    fin >> n;
    
    for(int i=1; i<=n; i++)
        paint( i );
    
    if( v[0] ) fout << "I " << v[0] << "\n";
    if( v[1] ) fout << "V " << v[1] << "\n";
    if( v[2] ) fout << "X " << v[2] << "\n";
    if( v[3] ) fout << "L " << v[3] << "\n";
    if( v[4] ) fout << "C " << v[4] << "\n";
    if( v[5] ) fout << "D " << v[5] << "\n";
    if( v[6] ) fout << "M " << v[6] << "\n";
    
    return 0;
}

void paint( int x )
{
    int a;
    a = x%10;
    x = x/10;
    
    if( a<4 ) v[0] += a;
    else if(a==4 || a==6) { v[0]++; v[1]++; }
    else if( a==5 ) v[1]++;
    else if( a<9 ) { v[1]++; v[0] += a-5; }
    else if( a==9 ) { v[2]++; v[0]++; }
    
    a=x%10;
    x=x/10;
    
    if( a<4 ) v[2] += a;
    else if(a==4 || a==6) { v[2]++; v[3]++; }
    else if( a==5 ) v[3]++;
    else if( a<9 ) { v[3]++; v[2] += a-5; }
    else if( a==9 ) { v[4]++; v[2]++; }
    
    a=x%10;
    x=x/10;
    
    if( a<4 ) v[4] += a;
    else if(a==4 || a==6) { v[4]++; v[5]++; }
    else if( a==5 ) v[5]++;
    else if( a<9 ) { v[5]++; v[4] += a-5; }
    else if( a==9 ) { v[6]++; v[4]++; }
    
    a=x%10;
    x=x/10;
    
    v[6]+=a;
}
