/*
ID: andreic4
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n,m;
int v[26];
int g[16][26];
int a[16]={0};
int rez[16]={0};
int jmax=26;

void rec(int i);
void verif();

int main()
{
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    
    fin >> n;
    for(int i=0; i<n; i++)
        fin >> v[i];
    
    fin >> m;
    for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
        fin >> g[i][j];
    
    rec(0);
    
    fout << jmax ;
    
    for( int i=0; i<m; i++)
        if( rez[i] ) fout << " " << i+1;
    fout << "\n";
    
    //system("pause");
    return 0;
}

void rec(int i)
{
    if( i==m )
    {
        verif();
    }
    else
    {
        a[i]=0;
        rec(i+1);
        a[i]=1;
        rec(i+1);
        a[i]=0;
    }
}

void verif()
{
    int k=0;
    int x[26]={0};
    
    for(int i=0; i<n; i++)
        x[i] = v[i];
    for(int i=0; i<m; i++)
        if( a[i] ) k++;
    
    if( k<=jmax )
    {
        //cout << "k=" << k << "\n";
        int t=1;
        for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if( a[i] )
            {
                x[j] -= g[i][j];
            }
        for(int i=0; i<n; i++)
            if( x[i]>0 ) 
            {
                t=0;
                //cout << i << " " << v[i] << " " << x[i] << "\n";
            }
        
        if( t )
        {
            //cout << " " << k << " " << a[0] << " " << a[1] << " " << a[2] << "\n";
            jmax = k;
            for(int i=0; i<m; i++)
                rez[i] = a[i];
        }
    }
}
