#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <queue>
using namespace std;

#define MMAX 128
ifstream fin ("security.txt");
ofstream fout (".out");

int e[MMAX][MMAX], m, pre[MMAX], sink, source;
bool vis[MMAX];

int flux() {
   memset(vis, 0, sizeof(vis));
   queue<int> q;
   q.push(source);
   vis[source] = true;
   pre[source] = -1;
   bool issink = false;
   while( !q.empty() && !issink )
   {
      int node = q.front();
      q.pop();
      for(int i=0; i<sink+1; i++)
      if( e[node][i]==1 && !vis[i] )
      {
         q.push(i);
         vis[i] = 1;
         pre[i] = node;
         if( i==sink) issink = true;
      }
   }

   if( issink==false ) return 0;

   int node = sink;
   while( pre[node]!=-1 )
   {
      e[ pre[node] ][node] = -1;
      e[node][ pre[node] ] = 1;
      node = pre[node];
   }
   return 1;
}

bool match_str(string a, string b) {
   for(int i=0; i<a.size(); i++)
      if( a[i]!=b[i] && a[i]!='?' && b[i]!='?' )
         return 0;
   return 1;
}

string get_match(string a, string b) {
   for(int i=0; i<a.size(); i++)
      if( a[i]=='?' )
         a[i] = (b[i]=='?' ? 'a' : b[i]);
   return a;
}

void printe() {
   for(int i=0; i<2*m+2; i++)
   {
      for(int j=0; j<2*m+2; j++)
         cout << e[i][j] << " ";
      cout << endl;
   }
}

void solve() {
   string k1, k2;
   fin >> m >> k1 >> k2;
   int n = k1.size();

   memset(e, 0, sizeof(e));
   for(int i=0; i<m; i++)
   for(int j=0; j<m; j++)
      if( match_str(k1.substr(i*n/m, n/m), k2.substr(j*n/m, n/m)) )
         e[i][m+j] = 1;

   source = 2*m, sink = 2*m+1;
   for(int i=0; i<m; i++)
      e[source][i] = e[i+m][sink] = 1;
   //printe();

   int tflow = 0, flow;
   while( flow = flux() ) tflow+=flow;
   //cout << flow << '\n';
   if( tflow<m ) {
      fout << "IMPOSSIBLE\n";
      return;
   }
   //printe();
   string res = "";
   for(int i=0; i<m; i++)
   {
      int ij = -1;
      for(int j=m; j<2*m; j++)
         if( e[i][j]==-1 ) {
            ij = j-m;
            break;
         }
      //cout << i << " " << ij << endl;
      res += get_match(k1.substr(i*n/m, n/m), k2.substr(ij*n/m, n/m));
   }
   fout << res << '\n';
}

int main() {
   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}