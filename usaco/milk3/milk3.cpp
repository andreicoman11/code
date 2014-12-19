/*
ID: andreic4
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool v[202021]={0};
int A,B,C;

void rec(int a, int b, int c);

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
    
    fin >> A >> B >> C;
    int a=0,b=0,c=C;
    v[c]=1;
    
    rec(a,b,c);
    
    int rez[21]={0};
    for(int i=1; i<=2020; i++)
        if( v[i] )
        {
            //cout << i << "\n";
            rez[ i%100 ] = 1;
        }
    
    int j=0;
    while( rez[j]==0 ) j++;
    fout << j++;
    for(; j<=20; j++)
        if( rez[j] )
        fout << " " << j;
    fout << "\n";
    //system("pause");
    return 0;
}

void rec(int a, int b, int c)
{
    //cout << a << " " << b << " " << c << "\n";
    //system("pause");
    int a2,b2,c2;
    long long nr;
    if( a<A && b )
    {
        if( a+b<A ) { a2 = a+b; b2 = 0; }
        else
        {
            b2 = b - (A-a);
            a2 = A;
        }
        c2 = c;
        nr = ( a2*100+b2 )*100 + c2;
        if( v[nr]==0 )
        {
            v[nr]=1;
            rec( a2, b2, c2);
        }
    }
    if( a<A && c )
    {
        if( a+c<A ) { a2 = a+c; c2 = 0; }
        else
        {
            c2 = c - (A-a);
            a2 = A;
        }
        b2 = b;
        nr = ( a2*100+b2 )*100 + c2;
        if( v[nr]==0 )
        {
            v[nr]=1;
            rec( a2, b2, c2);
        }
    }
    if( b<B && a )
    {
        if( b+a<B ) { b2 = b+a; a2 = 0; }
        else
        {
            a2 = a - (B-b);
            b2 = B;
        }
        c2 = c;
        nr = ( a2*100+b2 )*100 + c2;
        if( v[nr]==0 )
        {
            v[nr]=1;
            rec( a2, b2, c2);
        }
    }
    if( b<B && c )
    {
        if( b+c<B ) { b2 = b+c; c2 = 0; }
        else
        {
            c2 = c - (B-b);
            b2 = B;
        }
        a2 = a;
        nr = ( a2*100+b2 )*100 + c2;
        if( v[nr]==0 )
        {
            v[nr]=1;
            rec( a2, b2, c2);
        }
    }
    if( c<C && a )
    {
        if( c+a<C ) { c2 = c+a; a2 = 0; }
        else
        {
            a2 = a - (C-c);
            c2 = C;
        }
        b2 = b;
        nr = ( a2*100+b2 )*100 + c2;
        if( v[nr]==0 )
        {
            v[nr]=1;
            rec( a2, b2, c2);
        }
    }
    if( c<C && b )
    {
        if( c+b<C ) { c2 = c+b; b2 = 0; }
        else
        {
            b2 = b - (C-c);
            c2 = C;
        }
        a2 = a;
        nr = ( a2*100+b2 )*100 + c2;
        if( v[nr]==0 )
        {
            v[nr]=1;
            rec( a2, b2, c2);
        }
    }
}
