/*
ID: andreic4
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("clocks.out");
ifstream fin ("clocks.in");

int a[3][3], rez[10]={0};
int sol[10]={9};

bool done();
void move(int,int);
void bfs(int);
/*void afis()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
    //system("pause");
}*/

int main()
{
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
        fin >> a[i][j];
    
    
    bfs(1);
    
    /*for(int j=0; j<30; j++)
        fout << sol[j] << " ";
    fout << "\n";
    for(int j=0; j<30; j++)
        fout << rez[j] << " ";
    fout << "\n";*/
    
    //system("pause");
    return 0;
}

bool done()
{
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    {
        a[i][j] = a[i][j]%12;
        if( a[i][j]==0 ) a[i][j]=12;
    }
    
   for(int i=0; i<3; i++)
   for(int j=0; j<3; j++)
        if( a[i][j]!=12 ) return 0;
    
    return 1;
}

void move(int x,int q)
{
    if( x==1 )
    {
        a[0][0] += q;
        a[1][0] += q;
        a[0][1] += q;
        a[1][1] += q;
    }
    else if( x==2 )
    {
        a[0][0] += q;
        a[0][1] += q;
        a[0][2] += q;
    }
    else if( x==3 )
    {
        a[0][1] += q;
        a[0][2] += q;
        a[1][1] += q;
        a[1][2] += q;
    }
    else if( x==4 )
    {
        a[0][0] += q;
        a[1][0] += q;
        a[2][0] += q;
    }
    else if( x==5 )
    {
        a[0][1] += q;   
        a[1][0] += q;
        a[1][1] += q;
        a[1][2] += q;
        a[2][1] += q;
    }
    else if( x==6 )
    {
        a[0][2] += q;
        a[1][2] += q;
        a[2][2] += q;        
    }
    else if( x==7 )
    {
        a[1][0] += q;
        a[2][0] += q;
        a[1][1] += q;
        a[2][1] += q;
    }
    else if( x==8 )
    {
        a[2][0] += q;
        a[2][1] += q;
        a[2][2] += q;
    }
    else if( x==9 )
    {
        a[1][1] += q;
        a[1][2] += q;
        a[2][1] += q;
        a[2][2] += q;
    }
    //afis();
}

void bfs( int i)
{
    if( 10==i )
    {
        if( done()==1 ) 
        {
            int j=1;
            while( !rez[j] ) j++;
            fout << j;
            rez[j]--;
            
            for( ; j<10; j++)
            {
                while( rez[j] )
                {
                    fout << " " << j;
                    rez[j]--;
                }
            }
            fout << "\n";
            exit(0);         
        }
    }
    else
    {
        for(int j=0; j<4; j++)
        {
            rez[i]=j;
            move( i, 3*j );
            bfs(i+1);
            move( i, -3*j);
        }            
    }
}

