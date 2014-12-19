/*
ID: andreic4
PROG: fence
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");
    
    int m;
    fin >> m;
  
    int v[501] = {0};
    stack <int> s;
    int cur=0;
    
    int map[1050][3];
    
    for(int i=0; i<m; i++)
    {
        fin >> map[i][0] >> map[i][1];
        v[ map[i][0] ]++;
        v[ map[i][1] ]++;
        map[i][2]=1;
    }
    
    for(int i=0; i<501 && cur==0; i++)
        if( v[i]%2 ) cur=i;
    
    if( !cur ) cur=1;

    vector <int> ans;
    
    while( ans.size()<m )
    {
        bool done=0;
        int mini=1000, minval=1000;
        for(int i=0; i<m ; i++)
            if( map[i][2] && (map[i][0]==cur || map[i][1]==cur))
            {
                done=1;
                int val = map[i][0];
                if( val==cur ) val = map[i][1];
                
                if( val<minval ) { mini=i;  minval=val; }
            }
        
        if( !done ) { ans.push_back(cur); cur = s.top(); s.pop(); }
        else
        {
            map[mini][2]=0;
            s.push(cur);
            cur = minval;
        }
    }
    
    ans.push_back(cur);
    for(int i= ans.size()-1; i>=0; i--)
        fout << ans[i] << "\n";
    
    return 0;
}
