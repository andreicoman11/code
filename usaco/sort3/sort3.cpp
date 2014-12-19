/*
ID: andreic4
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    
    int v[4]={0};
    int x[4]={0};
    int a[1001];
    int n;
    int changes=0;
    fin >> n;
    for(int i=1; i<=n; i++)
    {
        fin >> a[i];
        v[ a[i] ]++;
    }
    
    //cout << v[1] << " " << v[2] << " " << v[3] <<"\n";
        
    for(int i=1; i<=v[1]; i++)
    {
        if( a[i]>1 )
        {
            changes++;
            x[ a[i] ]++;
        }
    }
    
    //cout << x[1] << " " << x[2] << " " << x[3] <<"\n";
    
    int j=2;
    for(int i=v[1]+1; i<=n; i++)
        if( a[i]==1 )
        {
            if( x[j] )
            {
                a[i]=j;
                x[j]--;
            }
            else
            {
                while( x[j]==0 ) j++;
                a[i]=j;
                x[j]--;
            }
        }

    //cout << x[1] << " " << x[2] << " " << x[3] <<"\n";
    
    for(int i=v[1]+1; i<=v[1]+v[2]; i++)
        if( a[i]>2 )
        {
            changes++;
            x[ a[i] ]++;
        }

    //cout << x[1] << " " << x[2] << " " << x[3] <<"\n";    
    
    fout << changes << "\n";
    
    //system("pause");
    return 0;
}
