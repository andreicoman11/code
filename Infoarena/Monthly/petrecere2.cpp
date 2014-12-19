#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <list>
#include <queue>
using namespace std;

#define LL long long
#define INFILE "petrecere2.in" 
#define OUTFILE "petrecere2.out"
#define NMAX 100010

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int n, m, difm, dife[NMAX][2], comp[NMAX], nr_comp, comp_sz[NMAX], rez;
bool comp_viz[NMAX];
list<int> ne[NMAX], comp2[NMAX];

void read_graf() {
   fin >> n >> m;
   difm = 0;
   for(int i=0; i<m; i++) {
      int a, b, c;
      fin >> a >> b >> c;
      comp[b] = comp[c] = -1;
      if( a==0 ) {
         ne[b].push_back(c);
         ne[c].push_back(b);
      } else {
         dife[difm][0] = b;
         dife[difm][1] = c;
         difm++;
      }
   }
}

void find_comp() {
   int cul = 0;
   for(int i=1; i<=n; i++)
      if( comp[i]==-1 ){
         comp[i] = ++cul;
         comp_sz[cul]++;
         comp_viz[cul] = 1;
         queue<int> q; // dfs pe i
         q.push(i);
         while( !q.empty() ) {
            int nod = q.front();
            q.pop();
            for(list<int>::iterator it=ne[nod].begin(); it!=ne[nod].end(); it++) 
               if( comp[*it]==-1 ) {
                  comp[*it] = cul;
                  q.push(*it);
                  comp_sz[cul]++;
               }
         }
      }
   nr_comp = cul;
}

void make_comp_graf() {
   for(int i=0; i<difm; i++) {
      int a = dife[i][0];
      int b = dife[i][1];
      // a<->b, so compa <-> compb
      comp2[ comp[a] ].push_back( comp[b] );
      comp2[ comp[b] ].push_back( comp[a] );
   }
}

void traverse_comp() {
   rez = n;
   for(int i=1; i<=nr_comp; i++)
      if( comp_viz[i]==1 ) {
         int sizes[2] = {0, 0};

         queue< pair<int,int> > q; // dfs pe i
         q.push( make_pair(i, 0) );
         while( !q.empty() ) {
            int nod = q.front().first;
            int par = q.front().second;
            q.pop();
            comp_viz[nod] = 0;
            sizes[par] += comp_sz[nod];

            for(list<int>::iterator it=comp2[nod].begin(); it!=comp2[nod].end(); it++)
               if( comp_viz[*it]==1 ) {
                  comp_viz[*it] = 0;
                  q.push( make_pair(*it, 1-par) );
               }
         }
         rez -= min( sizes[0], sizes[1]);
      }
}

int main() {
   read_graf();
   find_comp();
   make_comp_graf();
   traverse_comp();
   fout << rez;
   return 0;
}
