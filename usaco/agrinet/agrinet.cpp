/*
ID: andreic4
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int n, map[100][100];

int main()
{
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");
    
    fin >> n;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        fin >> map[i][j];
    
    int t=0;
    for(int k=0; k<n; k++)
    {
        vector <int> nodes;
        vector <int> dist;
        int v[100]={0};
        nodes.push_back(k);
        dist.push_back(0);
        v[k]=1;
        
        for(int q=1; q<n; q++)
        {
            int m,d=100001;
            for(int i=0; i<nodes.size(); i++)    
            for(int j=0; j<n; j++)
            {
                //cout << nodes[i] << " " << j << "\n";
                if( i!=j && v[j]==0 && map[ nodes[i] ][j] < d )
                {
                    //cout << j << " " << d << "\n";
                    m = j;
                    d = map[ nodes[i] ][j];   
                }
            }
            nodes.push_back(m);
            dist.push_back(d);
            v[m]=1;
        }
        
        int total=0;
        for(int i=0; i<n; i++)
        {
            //cout << nodes[i] << " " << dist[i] << " " << v[i] << "\n";
            total += dist[i];
        }
        if( t==0 || t>total ) t=total;
    }    
    fout << t << "\n";
    //system("pause");
    return 0;
}
