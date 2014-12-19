#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
using namespace std;
  
#define INFILE "parb.in"
#define OUTFILE "parb.out"
#define NMAX 500005
  
ifstream fin(INFILE);
ofstream fout(OUTFILE);
  
string l;
int n;
vector<vector<int> > e;
vector<pair<int, int> > best, best2;
int t[NMAX];
bool vis[NMAX];
  
int main() {
    fin >> n;
    fin >> l;
    char cmax = ' ';
    for(int i=0; i<n; i++)
        if(l[i]==cmax) best.push_back(make_pair(i,i));
        else if( l[i]>cmax) {
            best.clear();
            best.push_back(make_pair(i,i));
            cmax = l[i];
        }
  
    e.resize(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        fin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
  
    queue<int> q;
    q.push(0);
    t[0] = -1;
    while( !q.empty() ) {
        int nod = q.front();
        q.pop();
        vis[nod] = 1;
        for(vector<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
            if( *it!=t[nod] ) {
                q.push(*it);
                t[*it] = nod;
            }
    }
  
    fout << cmax;
    memset(vis, 0, sizeof(vis));
    while( best.size() ) {
        best2.clear();
        cmax = ' ';
        for(int i=0; i<(int)best.size(); i++) {
            int nod = best[i].first;
            int daddy = best[i].second;
            for(vector<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
                if( t[nod]!=*it ) {
                    if( l[*it]==cmax ) best2.push_back(make_pair(*it, daddy));
                    if( l[*it]>cmax ) {
                        best2.clear();
                        best2.push_back(make_pair(*it, daddy));
                        cmax = l[*it];
                    }
                }
        }
        if( cmax==' ') best.clear();
        else {
            fout << cmax;
            best.clear();
            for(int i=0; i<(int)best2.size(); i++)
                vis[best2[i].first] = 1;
  
            for(int i=0; i<(int)best2.size(); i++)
                if( !vis[best2[i].second] )
                    best.push_back(best2[i]);
        }
    }
  
    return 0;
}