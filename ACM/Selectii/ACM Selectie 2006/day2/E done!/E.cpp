#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ofstream fout ("E.out");
    ifstream fin  ("E.dat");

    int n;
    fin >> n;
    
    while( n )
    {
        int m;
        fin >> m;
        
        int map[51][51];
        for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            map[i][j]=1000;
        
        for(int i=0; i<m; i++)
        {
            int a,b,c;
            fin >> a >> b >> c;
            map[a][b] = map[b][a] = min( map[a][b], c);
            //cout << map[a][b] << " " << map[b][a] << "\n";
        }
        
        long int minsum = 50000;
        
            vector <int> done;
            bool v[51]={0};
            done.push_back(1);
            v[1]=1;
            
            int sum=0;
            while( done.size()<n )
            {
                int min=1000, minj=-1;
                
                for(int i=0; i<done.size(); i++)
                {
                    for(int j=1; j<=n; j++)
                        if( v[j]==0 && map[done[i]][j]<min ) { min=map[done[i]][j]; minj=j; }
                }
                
                done.push_back(minj);
                sum += min;
                v[minj] = 1;
                //cout << minj << " " << min << "\n"; system("pause");
            }
            
            if( sum<minsum ) minsum = sum;
        
        
        fout << minsum << "\n"; //system("pause");
        
        fin >> n;
    }



 return 0;
}
