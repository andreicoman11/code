/*
ID: andreic4
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool map[8][101];
int lamps[101];

ofstream fout ("lamps.out");

void verif(int,int);

int main()
{
    ifstream fin ("lamps.in");
    
    int n,c;
    fin >> n >> c;
    int a;
    for(int i=1; i<=n; i++)
        lamps[i]=-1;
    do
    {
        fin >> a;
        if(a>0) lamps[a]=1;
    } while( a>0 );
    do
    {
        fin >> a;
        if(a>0) lamps[a]=0;
    } while( a>0 );
    
        
    for(int i=1; i<=100; i++)
        map[0][i] = 1;
    
    for(int i=1; i<=100; i++)
        map[1][i] = 0;
    
    for(int i=1; i<=100; i++)
        if( i%2==0 ) map[2][i] = 1;
        else map[2][i]=0;
    
    for(int i=1; i<=100; i++)
        if( i%2 ) map[3][i] = 1;
        else map[3][i]=0;
    
    for(int i=1; i<=100; i++)
        if( i%3==1 ) map[4][i] = 0;
        else map[4][i]=1;

    for(int i=1; i<=100; i++)
        if( i%3==1 ) map[5][i]=1;
        else map[5][i]=0;
        
    for(int i=1; i<=100; i++)
        if( map[2][i]+map[4][i]==1 ) map[6][i]=1;
        else map[6][i]=0;
    
    for(int i=1; i<=100; i++)
        if( map[3][i]+map[4][i]==1 ) map[7][i]=1;
        else map[7][i]=0;
    
    /*
    for(int j=0; j<8; j++)
    {
        for(int i=1; i<=20; i++)
            cout << map[j][i] << " ";
        cout << "\n";
    }
    for(int i=1; i<=n; i++)
        cout << lamps[i] << " ";
    cout << "\n";*/
    
    verif(c,n);
    
    //system("pause");
    return 0;
}

void verif( int c,int n)
{
    int sol[8]={0};
    if( c==0 )
    {
        int t=1;
        for(int i=1; i<=n; i++)
            if( map[0][i]+lamps[i]==1 ) t=0;
        if( t ) sol[0]=1;
    }
    else if( c==1 )
    {
        int t=1;
        for(int i=1; i<=n; i++)
            if( map[1][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[1]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[2][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[2]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[3][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[3]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[4][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[4]=1;
    }
    else if( c==2 )
    {
        int t=1;
        for(int i=1; i<=n; i++)
            if( map[0][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[0]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[2][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[2]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[3][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[3]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[5][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[5]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[6][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[6]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[7][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[7]=1;
    }
    else
    {
        int t=1;
        for(int i=1; i<=n; i++)
            if( map[0][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[0]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[1][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[1]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[2][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[2]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[3][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[3]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[4][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[4]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[5][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[5]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[6][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[6]=1;
        
        t=1;
        for(int i=1; i<=n; i++)
            if( map[7][i]!=lamps[i] && lamps[i]>=0 ) t=0;
        if( t ) sol[7]=1;
    }
    int total=0;
    if( sol[1] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[1][i];
        fout << "\n";
    }
    if( sol[6] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[6][i];
        fout << "\n";
    }
    if( sol[2] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[2][i];
        fout << "\n";
    }
    if( sol[4] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[4][i];
        fout << "\n";
    }
    if( sol[5] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[5][i];
        fout << "\n";
    }
    if( sol[3] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[3][i];
        fout << "\n";
    }
    if( sol[7] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[7][i];
        fout << "\n";
    }
    if( sol[0] )
    {
        total=1;
        for( int i=1; i<=n; i++)
            fout << map[0][i];
        fout << "\n";
    }
    
    if( total==0 ) fout << "IMPOSSIBLE\n";
}
