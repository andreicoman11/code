/*
ID: andreic4
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ofstream fout ("inflate.out");
    ifstream fin ("inflate.in");
    
    long long int time[10003]={0};
    
    int m,n;
    fin >> m >> n;
    long long int timp[10003]={0}, scor[10003]={0};
    long long t[10001]={0};
    for(int i=0; i<n; i++)
    {
        int a,b;
        fin >> a >> b;
        if( t[b]==0 ) t[ b ]=a;
        else t[b] = t[b] > a ? t[b] : a;
        /*
        if( timp[i]> m ) { cout << timp[i] << "\n"; system("pause"); }
        else if( t[timp[i]]==1 ) { cout << timp[i] << " second time\n"; system("pause"); }
        else t[ timp[i] ]=1;
        
        if( t[timp[i]]==1 )*/
    }
    /*
    long int r=0;
    for(int i=0; i<=m; i++)
        if( t[i]==0 ) { r++; }
    cout << r << "\n"; system("pause");*/
    n=0;
    for(int i=0; i<=10000; i++)
        if( t[i] )
        {
            scor[n] = t[i];
            timp[n] = i;
            n++;
        }
    
    for(int j=0; j<n; j++)
    {
        for(int i=timp[j]; i<=m; i++)
        {
            time[i] = max( time[i], scor[j] + time[ i-timp[j] ]);
        }
    }
    
    /*for(int i=0; i<=m; i++)
        cout << i << " " << time[i] << "\n";*/
        
    
    
    fout << time[m] << "\n";
    //system("pause");
    return 0;
}
