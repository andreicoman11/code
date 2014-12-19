/*
ID: andreic4
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    
    int v[200]={0},n,m,a[200]={0};
    fin >> n >> m;
    fin >> m;
    
    for( int i=0; i<m; i++)
        fin >> v[i];
    
    int da=1;
    while( da )
    {
        da=0;
        for(int i=0; i<m-1; i++)
            if( v[i+1] < v[i] )
            {
                da = v[i];
                v[i] = v[i+1];
                v[i+1] = da;
                da = 1;
            }
    }
    
    
    n--;
    while( n )
    {
        int max=0,jmax=0;
        
        for(int i=0; i<m-1; i++)
            if( v[i+1]-v[i]>max && a[i+1]==a[i] )
            {
                max = v[i+1] - v[i];
                jmax = i+1;
            }
        int j=jmax, cul=a[jmax];
        while( a[j]==cul && j<m )
        {
            a[j]=n;
            j++;
        }            
        
        n--;
    }
    
    int begin=0;
    int total=0;
    
    for(int i=0; i<m; i++)
        if( a[i]!=a[begin] )
        {
            total += v[i-1] - v[begin]+1;
            //cout << i-1 << " " << begin << " " << total << "\n";
            begin = i;
        }
    total += v[m-1] - v[begin]+1;
    
    /*for( int i=0; i<m; i++)
        cout << v[i] << " ";
    cout << "\n";
    
    for( int i=0; i<m; i++)
        cout << a[i] << " ";
    cout << "\n";
    system("pause");*/
    fout << total << "\n";
    return 0;
}
