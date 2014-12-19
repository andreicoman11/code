/*
ID: andreic4
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");
    
    int map[101][201];
    for(int i=0; i<101; i++)
    for(int j=0; j<201; j++)
        map[i][j]=0;
    
    int nr = 9901;
    
    for(int i=1, temp=2; i<=7; i++)
    {
        map(temp-1,i)=1;
        temp *= 2;
    }        
    
    for(int i=1; i<101; i++)
    for(int j=1; j<201; j++)
        if( map[i-2][j-1] && map[i][j]==0 )
        {
            map[i][j] = ( 2*map[i-2][j-1] ) % nr;
        }
    
    
    
    int n,k;
    fin >> n >> k;
    
    if( n%2==0 ) fout << "0\n";
    else
    {
        long long int tmp=1;
        int fact = (n-2*k+1)/2;
        int ter = k-2;
        for(int i=0; i<=fact; i++)
            tmp *= (ter+i)
    }
    
    return 0;
}
