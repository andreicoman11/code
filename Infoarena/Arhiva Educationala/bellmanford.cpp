#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

#define INFILE "bellmanford.in" 
#define OUTFILE "bellmanford.out"
#define NMAX 50001
#define INF 0x3f3f3f3f
ofstream fout (OUTFILE);

int n, m, a[NMAX];
vector<list<pair<int,int> > > e;

void read() {
   FILE* fin = fopen(INFILE, "r");
   fscanf(fin, "%d %d", &n, &m);
   e.resize(n);
   int es, ee, ec;
   for(int i=0; i<m; i++) {
      fscanf(fin, "%d %d %d", &es, &ee, &ec);
      e[es-1].push_back(make_pair<int,int>(ee-1, ec));
   }
}

void BellmanFord() {
   memset(a, INF, sizeof(a));
   list<int> nodes, newn;
   bool used[NMAX];
   a[0] = 0;
   newn.push_back(0);
   int nod, vecin, cost;
   for(int c=0; !newn.empty() && c<n-1; c++) {
      nodes = newn;
      newn.clear();
      memset(used, 0, sizeof(used));
      for(list<int>::iterator it = nodes.begin(); it!=nodes.end(); it++) {
         nod = *it;
         for(list<pair<int,int> >::iterator it2 = e[nod].begin(); it2!=e[nod].end(); it2++) {
            vecin = it2->first;
            cost = it2->second;
            if( a[vecin] > a[nod] + cost ) {
               a[vecin] = a[nod] + cost;
               if( !used[vecin] ) used[vecin] = 1, newn.push_back(vecin);
            }
         }
      }
   }

   if( !newn.empty() ) {
      nodes = newn;
      for(list<int>::iterator it = nodes.begin(); it!=nodes.end(); it++) 
         for(list<pair<int,int> >::iterator it2 = e[*it].begin(); it2!=e[*it].end(); it2++) 
            if( a[it2->first] > a[*it] + it2->second ) {
               fout << "Ciclu negativ!" << endl;
               return ;
            }
   }

   for(int i=1; i<n; i++)
      fout << a[i] << " ";
   fout << endl;
}

int main()
{
   read();

   BellmanFord();

	return 0;
}