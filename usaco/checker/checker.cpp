/*
ID: andreic4
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("checker.out");
ifstream fin ("checker.in");

int n;
int v[14]={0};
int row[14]={0};
int diag1[30]={0};
int diag2[30]={0};
int total=0;
int t[14]={0};

void rec(int);
    
int main()
{
    fin >> n;
    
    rec(0);
    
    total=0;
    for(int i=1; i<=n/2; i++)
        total += 2*t[i];
        
    if( n%2 ) total += t[(n+1)/2];
    
    fout << total << "\n";
    return 0;
}

void rec(int i)
{/*
    cout << "\n";
    for(int p=0; p<14; p++)
        cout << cul[p] << " ";
    system("pause");*/
    if( i>=n )
    {
        if( total<3 )
        {
            fout << v[0]+1;
            for(int k=1; k<n; k++)
                fout << " " << v[k]+1;
            fout << "\n";
        }
        total++;
        t[ v[0]+1 ]++;
    }
    else if( total<3 || v[0]*2<=n-1 )
    {
        for(int j=0; j<n; j++)
            if( row[j]==0 && diag1[15+j-i]==0 && diag2[j+i]==0 )
            {
                v[i] = j;
                row[j]=1;
                diag1[15+j-i]=1;
                diag2[j+i]=1;
                
                rec(i+1);
                
                v[i]=0;
                row[j]=0;
                diag1[15+j-i]=0;
                diag2[j+i]=0;
            }
    }
}
