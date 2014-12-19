/*
ID: andreic4
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int a[50][50];
int a2[50][50];
int x[50][50];
int vals[2501]={0};
int n,m;

void color(int,int,int);

int main()
{
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");   
    
    fin >> m >> n;
    
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)    
    {
        fin >> a[i][j];
        a2[i][j]=a[i][j];
        x[i][j]=0;
        //cout << a[i][j] << " ";
        //if( j==m-1 ) cout << "\n";
    }
        
    int cul=1;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        if( x[i][j]==0 )
        {
            x[i][j]=cul;
            //system("pause");
            color(i,j,cul);
            cul++;
            //system("pause");
        } 
    cul--;
    /*
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << a2[i][j] << " ";
        cout << "\n";
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }*/
    
    fout << cul << "\n";
    int largest=0;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
        vals[ x[i][j] ]++;
        if( vals[ x[i][j] ]>largest ) largest = vals[ x[i][j] ];
    }
    
    fout << largest << "\n";
    
    /*for(int i=1; i<=cul; i++)
        cout << vals[i] << " ";*/
    
    int resi,resj,t,maxarea=0;
    
    for(int j=0; j<m; j++)
    for(int i=n-1; i>=0; i--)
    {
        //cout << "coord " << i << " " << j << "\n";
        if( a2[i][j]>=8 ) a2[i][j]-=8;
        //if( j==10 ) cout << i << " " << a[i][j] << "\n";
        if( a2[i][j]>=2 && a2[i][j]!=4 && i>0 )
        {
            int area = vals[ x[i][j] ] + vals[ x[i-1][j] ];
            if( x[i][j]  == x[i-1][j] ) area = area/2;
            if( area>maxarea )
            {
                maxarea = area;
                resi = i;
                resj = j;
                t=1;
                //cout << "2 " << area << "\n";
            }
        }
        if( a2[i][j]>=4 && j<m-1 )
        {                 
            int area = vals[ x[i][j] ] + vals[ x[i][j+1] ];
            if( x[i][j] == x[i][j+1] ) area = area/2;
            //if( j==10 ) cout << "max1 " << i << " " << j << " " << area << "\n";            
            if( area>maxarea )
            {
                maxarea = area;
                resi = i;
                resj = j;
                t=0;
                //cout << "1 " << area << "\n";
            }
            a2[i][j] -=4;
        }
        
    }
    
    fout << maxarea << "\n";
    fout << resi+1 << " " << resj+1 << " ";
    if( t==0 ) fout << "E\n";
    else fout << "N\n";
    
    //system("pause");
    return 0;
}

void color(int i,int j,int cul)
{
    /*for(int i2=0; i2<n; i2++)
    {
        for(int j2=0; j2<m; j2++)
            cout << x[i2][j2] << " ";
        cout << "\n";
    }
    system("pause");*/
    int v[4]={0};
    if( a[i][j]>=8 ) { v[3]++; a[i][j]-=8; }
    if( a[i][j]>=4 ) { v[2]++; a[i][j]-=4; }
    if( a[i][j]>=2 ) { v[1]++; a[i][j]-=2; }
    if( a[i][j]>=1 ) { v[0]++; a[i][j]-=1; }
    a[i][j]=a2[i][j];
    if( v[3]==0 && i<n-1 && x[i+1][j]==0 )
    {
        x[i+1][j]=cul;
        color(i+1,j,cul);
        a[i][j] -= 8;
    }
    if( v[2]==0 && j<m-1 && x[i][j+1]==0 )
    {
        x[i][j+1]=cul;
        color(i,j+1,cul);
        a[i][j] -= 4;
    }
    if( v[1]==0 && i>0 && x[i-1][j]==0 )
    {
        x[i-1][j]=cul;
        color(i-1,j,cul);
        a[i][j] -= 2;
    }
    if( v[0]==0 && j>0 && x[i][j-1]==0 )
    {
        x[i][j-1]=cul;
        color(i,j-1,cul);
        a[i][j] -= 1;
    }
}
