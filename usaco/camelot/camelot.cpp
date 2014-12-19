/*
ID: andreic4
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int neb[1050][2][41][27];
int rege[41][27];
int n,m;
int king[2], knight[1050][2];
int dx[]={1,2,-1,-2,-1,-2,1,2};
int dy[]={2,1,2,1,-2,-1,-2,-1};
int ax[]={-1,0,1,-1,0,1,-1,1};
int ay[]={-1,1,0,0,-1,-1,1,1};
int nrk;
int regi[1050]={0};

void afis();
void erase();
//void drawking(int,int,int);
//void drawknight(int,int,int,int,int);
void drawknights();
void drawkings();
void drawk();
void knights();

int main()
{
    ofstream fout ("camelot.out");
    ifstream fin ("camelot.in");
    
    fin >> n >> m;
    
    int nr;
    char a;
    
    fin >> a >> nr;
    king[1] = int(a)-int('A');
    king[0] = nr-1;
    
    int ii=0;
    while( fin >> a >> nr )
    {
        knight[ii][1] = int(a)-int('A');
        knight[ii][0] = nr-1;
        ii++;
    }
    nrk = ii;
    
    erase();
    for(int i=0; i<nrk; i++)
    {
        neb[i][0][knight[i][0]][knight[i][1]]=0;
    }
    //cout << "erase\n"; system("pause");
    //afis();
    rege[ king[0] ][ king[1] ]=0;
    //drawking(king[0],king[1],0);
    //cout << "drawking\n";
    //afis();
    //cout << "king found\n";
    //afis();
    //system("pause");
    /*for(int i=0; i<nrk; i++)
    {
        drawknight(i,0,knight[i][0],knight[i][1],0);
    }*/
    drawk();
    //drawknights();
    knights();
    for(int i=0; i<nrk; i++)
    {
        neb[i][1][king[0]][king[1]] = neb[i][0][king[0]][king[1]];
        regi[i] = neb[i][1][king[0]][king[1]];
    }
    drawkings();
    //system("pause");
    /*for(int i=0; i<nrk; i++)
    {
        drawknight(i,1,king[0],king[1],neb[i][0][king[0]][king[1]]);
    }*/
    //system("pause");
    //cout << "knight drawn\n";
    //afis();
    
    int mmin = 10000;
    
    for(int k=0; k<n; k++)
    for(int l=0; l<m; l++)
    {
        int s = 0;
        int t=1;
        for(int i=0; i<nrk && t; i++)
            if( neb[i][0][k][l]==-1 ) t=0;
            else s += neb[i][0][k][l];
        if( t && s+rege[k][l] < mmin ) mmin = s+rege[k][l];
        
        for(int i=0; i<nrk && t; i++)
        {
            int s2;
            if( neb[i][1][k][l]>=0 )
            {
                s2 = s + neb[i][1][k][l] - neb[i][0][k][l];
                if( s2 < mmin ) mmin = s2;
            }
            s2 = s + rege[ knight[i][0] ][ knight[i][1] ];
            if( s2 < mmin ) mmin = s2;
        }
        //cout << k << " " << l << " " << s << " " << mmin << "\n";
        //system("pause");
    }
    
    //if( mmin==4487 ) mmin--;
    fout << mmin << "\n";
    //system("pause");
    return 0;
}

void erase()
{
    for(int i=0; i<nrk; i++)
    for(int j=0; j<2; j++)
    for(int k=0; k<n; k++)
    for(int l=0; l<m; l++)
    {
        neb[i][j][k][l]=-1;
        rege[k][l]=-1;
    }
}
/*void drawking(int a, int b, int cul)
{
    rege[a][b]=cul;
    //cout << a << " " << b << " " << cul << "\n"; system("pause");
    int amin=a-1,amax=a+1,bmin=b-1,bmax=b+1;
    if( amin<0 ) amin=0;
    if( bmin<0 ) bmin=0;
    if( amax>=n ) amax=n-1;
    if( bmax>=m ) bmax=m-1;
    for(int i=amin; i<=amax; i++)
    for(int j=bmin; j<=bmax; j++)
        if( rege[i][j]==-1 || rege[i][j]>cul+1 )
            drawking(i,j,cul+1);
}

void drawknight(int i,int j, int x, int y, int cul)
{
    neb[i][j][x][y]=cul;
    for(int p=0; p<8; p++)
    {
        int ax = x+dx[p];
        int ay = y+dy[p];
        if( ax>=0 && ax<n && ay>=0 && ay<m && (neb[i][j][ax][ay]==-1 || neb[i][j][ax][ay]>neb[i][j][x][y]+1) )
            drawknight(i,j,ax,ay,cul+1);
    }
}*/

void afis()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << rege[i][j] << " ";
        cout << "\n";
    }
    system("pause");
    for(int i=0; i<nrk; i++)
    for(int j=0; j<2; j++)
    {
        cout << i << " " << j << "\n";
        for(int k=0; k<n; k++)
        {
            for(int l=0; l<m; l++)
                cout << neb[i][j][k][l] << " ";
            cout << "\n";
        }
        system("pause");
    }
}

void drawknights()
{
    bool t = true;
    int cul=0;
    while(t)
    {
        t=false;
        
        for(int k=0; k<n; k++)
        for(int l=0; l<m; l++)
        {
            for(int i=0; i<nrk; i++)
                if( neb[i][0][k][l]==cul )
                {
                    for(int p=0; p<8; p++)
                    {
                        int ax = k+dx[p];
                        int ay = l+dy[p];
                        if( ax>=0 && ax<n && ay>=0 && ay<m && (neb[i][0][ax][ay]==-1 || neb[i][0][ax][ay]>cul+1) )
                        {
                            neb[i][0][ax][ay]=cul+1;
                            t=true;
                        }                            
                    }
                }
        }
        cul++;
    }
}

void drawkings()
{
    bool t = true;
    int cul=0;
    while(t)
    {
        t=false;
        
        for(int k=0; k<n; k++)
        for(int l=0; l<m; l++)
        {
            for(int i=0; i<nrk; i++)
                if( neb[i][1][k][l]==regi[i]+cul && regi[i]>=0 )
                {
                    for(int p=0; p<8; p++)
                    {
                        int ax = k+dx[p];
                        int ay = l+dy[p];
                        if( ax>=0 && ax<n && ay>=0 && ay<m && (neb[i][1][ax][ay]==-1 || neb[i][1][ax][ay]>neb[i][1][k][l]+1) )
                        {
                            neb[i][1][ax][ay]=neb[i][1][k][l]+1;
                            t=true;
                        }                            
                    }
                }
        }
        cul++;
    }
}

void drawk()
{
    int cul=0;
    bool t = true;
    while(t)
    {
        t=false;        
        for(int k=0; k<n; k++)
        for(int l=0; l<m; l++)
        if( rege[k][l]==cul )
        {
            for(int p=0; p<8; p++)
            {
                int i = k+ax[p];
                int j = l+ay[p];   
                if( rege[i][j]==-1 || rege[i][j]>cul+1 )
                {
                    rege[i][j] = cul+1;
                    t=true;
                }
            }
        }
        cul++;
    }
}

void knights()
{
    for(int i=0; i<nrk; i++)
    {
        int heap[1000][2]={0};
        int last=1;
        int cul=1;
        heap[0][0] = knight[i][0];
        heap[0][1] = knight[i][1];
        neb[i][0][ heap[0][0] ][ heap[0][1] ]=0;
        
        while( last )
        {
            int first=0;
            int last2=0;
            int heap2[1000][2]={0};
            
            while( first<last )
            {
                int a = heap[first][0];
                int b = heap[first][1];
                for(int p=0; p<8; p++)
                {
                    int ax = a + dx[p];
                    int ay = b + dy[p];
                    if( ax>=0 && ay>=0 && ax<n && ay<m && neb[i][0][ax][ay]==-1 )
                    {
                        neb[i][0][ax][ay] = cul;
                        heap2[last2][0] = ax;
                        heap2[last2][1] = ay;
                        last2++;
                    }
                }
                first++;
            }
            
            for(int j=0; j<last2; j++)
            {
                heap[j][0] = heap2[j][0];
                heap[j][1] = heap2[j][1];
            }
            last = last2;
            cul++;
        }
    }
    
}
