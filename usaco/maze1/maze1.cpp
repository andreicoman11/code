/*
ID: andreic4
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int n,m;
int map[300][300];
int x[300][300];

void cul(int,int,int);

int main()
{
    ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    
    vector <string> m2;
    
    fin >> m >> n;
    
    for(int i=0; i<=n; i++)
    for(int j=0; j<=m; j++)
        map[i][j]=0;
    for(int i=0; i<=2*n+1; i++)
    {
        char line[300];
        fin.getline( line, 300, '\n' );
        if(i) m2.push_back( line );
    }
    
    //for(int i=0; i<2*n+1; i++)
    //    cout << m2[i] << "\n";
        
    for(int i=0; i<2*n+1; i++)
    for(int j=0; j<2*m+1; j++)
        if( m2[i][j]==' ' && (i+j)%2==0 )
        {
            //cout << i << " " << j << "\n";
            //system("pause");
            int nr=0;
            if( m2[i][j-1]=='|' )  nr +=1;
            if( m2[i-1][j]=='-' )  nr +=2;
            if( m2[i][j+1]=='|' )  nr +=4;
            if( m2[i+1][j]=='-' )  nr +=8;
            map[i/2][j/2] = nr;
        }
    
    /*
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }*/
    
    vector <int> start;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
        x[i][j]=0;
        if( i==0 && x[i][j]==0 )
        {
            int nr = map[i][j];
            if( nr>=8 ) nr-=8;
            if( nr>=4 ) nr-=4;
            if( nr<2 ) x[i][j]=1;
        }
        if( i==n-1 && x[i][j]==0 )
        {
            int nr = map[i][j];
            if( nr<8 ) x[i][j]=1;
        }
        if( j==0 && x[i][j]==0 )
        {
            int nr = map[i][j];
            if( nr>=8 ) nr-=8;
            if( nr>=4 ) nr-=4;
            if( nr>=2 ) nr-=2;
            if( nr<1 ) x[i][j]=1;
        }
        if( j==m-1 && x[i][j]==0 )
        {
            int nr = map[i][j];
            if( nr>=8 ) nr-=8;
            if( nr<4 ) x[i][j]=1;
        }
        if( x[i][j]==0 ) x[i][j]=-1;
        if( x[i][j]==1 ) { start.push_back(i); start.push_back(j); }
    }
    
    //cout << start[0] << " " << start[1] << " " << start[2] << " " << start[3] << "\n";
    
    cul( start[2], start[3], 1);
    cul( start[0], start[1], 1);
    
    int max=0;
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
        if( x[i][j]>max )
        {
            max = x[i][j];
        }
    
    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << x[i][j] << " ";
        cout << "\n";
    }*/
    
    fout << max << "\n";
    //system("pause");
    return 0;
}

void cul(int i, int j, int c)
{
    int nr = map[i][j];
    
    //cout << i << " " << j << " " << nr << "\n"; system("pause");
    
    if( nr<8 && i<n-1 && (x[i+1][j]==-1 || x[i+1][j]>c+1) )
    {
        x[i+1][j] = c+1;
        cul( i+1, j, c+1);
    }
    if(nr>=8) nr-=8;
    
    //cout << i << " " << j << " " << nr << "\n"; system("pause");
    
    if( nr<4 && j<m-1 && (x[i][j+1]==-1 || x[i][j+1]>c+1) )
    {
        x[i][j+1] = c+1;
        cul( i, j+1, c+1);
    }
    if(nr>=4) nr-=4;
    
    //cout << i << " " << j << " " << nr << "\n"; system("pause");
    
    if( nr<2 && i>0 && (x[i-1][j]==-1 || x[i-1][j]>c+1) )
    {
        x[i-1][j] = c+1;
        cul( i-1, j, c+1);
    }
    if(nr>=2) nr-=2;
    
    //cout << i << " " << j << " " << nr << "\n"; system("pause");
    
    if( nr<1 && j>0 && (x[i][j-1]==-1 || x[i][j-1]>c+1) )
    {
        x[i][j-1] = c+1;
        cul( i, j-1, c+1);
    }
    if(nr>=1) nr-=1;
    
    //cout << i << " " << j << " " << nr << "\n"; system("pause");
        
}
