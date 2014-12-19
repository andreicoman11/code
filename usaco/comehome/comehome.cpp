/*
ID: andreic4
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX 100000

using namespace std;

int main()
{
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");
    
    int map[60][60];
    
    for(int i=0; i<60; i++)
    for(int j=0; j<60; j++)
        map[i][j]=MAX;
    
    int q;
    fin >> q;
    for( int j=0; j<q; j++)
    {
        char a,b;
        int c,x,y;
        fin >> a >> b >> c;
        if( isupper(a) ) x = 30 + int(a) - int('A');
        else x = int(a) - int('a');
        if( isupper(b) ) y = 30 + int(b) - int('A');
        else y = int(b) - int('a');
        if( map[x][y]>c ) map[x][y] = map[y][x] = c;
    }
    /*
    for(int i=0; i<60; i++)
    {
        for(int j=0; j<60; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }
    system("pause");*/
    
    vector <int> nodes;
    vector <int> dist;
    int done[60] = {0};
    done[55]=1;
    nodes.push_back(55);
    dist.push_back(0);
    
    int n=55,d=0;
    
    while( n%55<30 )
    {
        int nmin,dmin=MAX;
        for(int i=0; i<nodes.size(); i++)
        for(int j=0; j<60; j++)
        {
            //cout << nodes[i] << j << " " << map[nodes[i]][j] << " " << dist[i] << "\n"; system("pause");
            
            if( map[nodes[i]][j]+dist[i] < dmin && done[j]==0 )
            {
                dmin = map[nodes[i]][j] + dist[i];
                nmin = j;
            }
        }
        n = nmin;
        d = dmin;
        nodes.push_back(n);
        dist.push_back(d);
        done[n]=1;
        cout << char( n + int('a') ) << " " << d << "\n";
        system("pause");
    }
    
    fout << char( nodes[nodes.size()-1] - 30 + int('A') ) << " " << dist[ dist.size()-1 ] << "\n";
    return 0;
}
