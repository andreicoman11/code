/*
ID: andreic4
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
    
    int n,total=0;    
    fin >> n;
    vector <int> v(n);
    int x[10]={0};
    while( n )
    {
        fin >> v[n-1];
        x[ v[n-1] ]=1;
        //cout << v[n-1] << " ";
        n--;
    }
    n = v.size();
    //cout << "\n";
    
    for(int i1=0; i1<n; i1++)
    for(int i2=0; i2<n; i2++)
    for(int i3=0; i3<n; i3++)
    for(int i4=0; i4<n; i4++)
    for(int i5=0; i5<n; i5++)
    {
        int a = v[i1]*100 + v[i2]*10 + v[i3];
        int b = a*v[i4];
        int c = a*v[i5];
        int d = b + c*10;        
        int t=1;
        
        if( b>999 ) t=0;
        if( c>999 ) t=0;
        if( d>9999 ) t=0;
        while( b )
        {
            if( x[b%10]==0 ) t=0;
            b = b/10;
        }
        
        while( c )
        {
            if( x[c%10]==0 ) t=0;
            c = c/10;
        }
        
        while( d )
        {
            if( x[d%10]==0 ) t=0;
            d = d/10;
        }
        //if( t ) cout << a << " " << v[i4] << " " << v[i5] << " " << d << "\n";
        total += t;
    }
    
    fout << total << "\n";
    //system("pause");
    return 0;
}
