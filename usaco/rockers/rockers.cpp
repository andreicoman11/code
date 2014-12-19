/*
ID: andreic4
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int n,t,m;
int len[21]={0};
int maxs=0;
int s[25]={0};

void rec(int,int,int);

int main()
{
    ofstream fout ("rockers.out");
    ifstream fin ("rockers.in");
    
    fin >> n >> t >> m;
    for(int i=0; i<n; i++)
        fin >> len[i];
    
    rec(0, 0, 0);
    
    
    fout << maxs << "\n";
    return 0;
}

void rec(int i, int songs,int j)
{
    /*for(int j=0; j<m; j++)
        cout << s[j] << " ";
    cout << "\n" << i << " " << songs << " " << maxs << "\n";
    system("pause");*/
    
    maxs = max( songs, maxs);
    if( i<n && maxs<songs+n-i )
    {
        if( s[j]+len[i]<=t )
        {
            s[j] += len[i];
            rec(i+1, songs+1,j);
            s[j] -= len[i];
        }
        if( j<m-1 && len[i]<=t )
        {
            j++;
            s[j] += len[i];
            rec(i+1, songs+1,j);
            s[j] -= len[i];
            j--;
        }
        rec( i+1, songs,j);
    }
}
