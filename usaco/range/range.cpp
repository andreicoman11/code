/*
ID: andreic4
PROG: range
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("range.out");
    ifstream fin ("range.in");
    
    int map[260][260];
    int n;
    
    fin >> n;
    for(int i=0; i<=n; i++)
    {
        map[0][i]=0;
        map[i][0]=0;
    }
    for(int i=0; i<n; i++)
    {
        string tmp;
        fin >> tmp;
        for(int j=0; j<n; j++)
            if( tmp[j]=='1' ) map[i+1][j+1]=1;
            else map[i+1][j+1]=0;
    }
    
    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
        if( map[i][j] ) map[i][j] += map[i][j-1];
    
    unsigned long int size[260]={0};
    
    for(int i=n; i>1; i--)
    for(int j=n; j>1; j--)
        if( map[i][j]>1 )
        {
            int max = map[i][j];
            int t=1;
            int s=1;
            
            while( t && s<max && i-s>0 )
            {
                if( map[i-s][j]>s )
                {
                    if( map[i-s][j]<max ) max = map[i-s][j];
                    s++;
                    size[s]++;
                }
                else t=0;
            }
            //cout << i << " " << j << " " << s << "\n"; system("pause");
        }
    
    
    
    for(int i=2; i<=250; i++)
        if( size[i] ) fout << i << " " << size[i] << "\n";
    
    //system("pause");
    return 0;
}
