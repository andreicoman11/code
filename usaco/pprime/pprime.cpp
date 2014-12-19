/*
ID: andreic4
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool prime( long long x );
bool good( long long, long long, long long);

int main()
{
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");
    
    int nr[5]={1,3,5,7,9};

    long long a,b;
    fin >> a >> b;
    
    for(int i=0; i<5; i++)
        if( prime(nr[i]) && good( nr[i],a,b) ) fout << nr[i] << "\n";

    
    for(int i=0; i<5; i++)
        if( prime(nr[i]*11)  && good( nr[i]*11,a,b) ) fout << nr[i]*11 << "\n";

    for(int i=0; i<5; i++)
    for(int j=0; j<10; j++)
    {
        long long p = nr[i] * 100 + j * 10 + nr[i];
        if( prime(p)  && good( p,a,b) ) fout << p << "\n";
    }
    
    for(int i=0; i<5; i++)
    for(int j=0; j<10; j++)
    {
        long long p = nr[i] * 1000 + j * 110 + nr[i];
        if( prime(p) && good( p,a,b) ) fout << p << "\n";
    }
    
    for(int i=0; i<5; i++)
    for(int j=0; j<10; j++)
    for(int k=0; k<10; k++)
    {
        long long p = nr[i] * 10000 + j * 1000 + k* 100 + j* 10 + nr[i];
        if( prime(p) && good( p,a,b) ) fout << p << "\n";
    }
    
    for(int i=0; i<5; i++)
    for(int j=0; j<10; j++)
    for(int k=0; k<10; k++)
    {
        long long p = nr[i] * 100000 + j * 10000 + k* 1000 + k*100 + j* 10 + nr[i];
        if( prime(p) && good( p,a,b) ) fout << p << "\n";
    }
    
    for(int i=0; i<5; i++)
    for(int j=0; j<10; j++)
    for(int k=0; k<10; k++)
    for(int l=0; l<10; l++)
    {
        long long p = nr[i] * 1000000 + j * 100000 + k* 10000 + l*1000 + k*100 + j* 10 + nr[i];
        if( prime(p) && good( p,a,b) ) fout << p << "\n";
    }
    
    for(int i=0; i<5; i++)
    for(int j=0; j<10; j++)
    for(int k=0; k<10; k++)
    for(int l=0; l<10; l++)
    {
        long long p = nr[i] * 10000000 + j * 1000000 + k* 100000 + l*10000 + l*1000 + k*100 + j* 10 + nr[i];
        if( prime(p) && good( p,a,b) ) fout << p << "\n";
    }
    
    return 0;
}

bool prime( long long x )
{
    for( long long i=3; i*i<=x; i+=2)
        if( x%i==0 ) return 0;
    return 1;
}

bool good(long long p, long long a, long long b)
{
    if( p<a ) return 0;
    if( p>b ) return 0;
    return 1;
}
