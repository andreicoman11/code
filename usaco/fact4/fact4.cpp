/*
ID: andreic4
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    
    int n;
    fin >> n;
    int uc = 1;
    
    long long int zece=0;
    
    for(int i=1; i<=n; i++)
    {
        int nr = i;
        while( nr%2==0 ) { zece++; nr /= 2; }
        while( nr%5==0 ) { zece--; nr /= 5; }
        uc = uc*nr;
        uc = uc%10;
    }
    
    zece = zece%4;
    if( zece==0 ) uc *= 6;
    else if( zece==1 ) uc *= 2;
    else if( zece==2 ) uc *= 4;
    else if( zece==3 ) uc *= 8;
    
    uc = uc%10;
    
    if( n==1 ) fout << "1\n";
    else fout << uc << "\n";
    
    //system("pause");
    return 0;
}
