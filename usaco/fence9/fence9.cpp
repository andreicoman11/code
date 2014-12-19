/*
ID: andreic4
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("fence9.out");
    ifstream fin ("fence9.in");
    
    int a,b,c;
    fin >> b >> c >> a;
    int n = c;
    int m = max(a,b);
    unsigned long long nr=0;
    
    if( c==0 ) { fout << "0\n"; return 0; }
    if( a==0 ) { fout << "0\n"; return 0; }
    
    for(int i=1; i<m; i++)
    for(int j=1,t=0; j<n && t<2; j++)
    {
        int da = 1;
        if( b*j < c*i && j*(a-b)+c*i<c*a ) nr++;
        else da = 0;
        if( da ) t=1;
        if( !da && t ) t=2;
        //cout << i << " " << j << " " << da << " " << nr << "\n";
        //system("pause");
        
        int j2=j;
        j2 += 10000;
        if( da && j2<n && b*j2 < c*i && j2*(a-b)+c*i<c*a ) { nr+=10000; j+=10000; }
        j2=j;
        j2 += 1000;
        if( da && j2<n && b*j2 < c*i && j2*(a-b)+c*i<c*a ) { nr+=1000; j+=1000; }
        j2=j;
        j2 += 100;
        if( da && j2<n && b*j2 < c*i && j2*(a-b)+c*i<c*a ) { nr+=100; j+=100; }
        
    }
    
    fout << nr << "\n";
    //system("pause");
    return 0;
}
