/*
ID: andreic4
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    
    int n,s;
    fin >> n >> s;
    long long map[10001][26];
    unsigned int v[26]={0};
    for(int i=0; i<=s; i++)
    for(int j=0; j<=n; j++)
        map[i][j]=0;

    for(int i=1; i<=n; i++)
    {
        fin >> v[i];
        if( v[i]>10000 ) { i--; n--; }
        else map[ v[i] ][ i ]=1;
    }
    /*
    for(int i=1; i<=s; i++)
    {
        for(int j=1; j<=n; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }    
    system("pause");*/

    for(int i=1; i<=s; i++)
    for(int j=1; j<=n; j++)
    {
        long long int sum=0;
        if( v[j]<=i )
        {
            for(int k=0; k<=j; k++)
                sum += map[ i-v[j] ][k];
            map[i][j] += sum;
        }
    }
    
    /*
    for(int i=1; i<=s; i++)
    {
        for(int j=1; j<=n; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }system("pause");*/
    
    unsigned long long ans=0;
    for(int i=1; i<=n; i++)
        ans += map[s][i];
    
    fout << ans << "\n";
    
    //system("pause");
    return 0;
}
