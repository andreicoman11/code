#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define INFILE "cezar.in" 
#define OUTFILE "cezar.out"
#define NMAX 10001

int n, k;
vector<short> e[NMAX];
vector<short> d;

struct comp {
   bool operator()(const short& a, const short& b) {
      return d[a] > d[b];
   }
};

priority_queue<short, vector<short>, comp > q;

int main() {
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   scanf("%d %d", &n, &k);
   d.resize(n);

   for(int i=0; i<n-1; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      e[a-1].push_back(b-1);
      e[b-1].push_back(a-1);
   }
   
   for(int i=0; i<n; i++)
      if( e[i].size()==1 )
         q.push(i);

   int res = 0;
   while(k<n-1) {
      k++;
      int nod = q.top();
      res += 1 + d[nod];
      int v = e[nod][0];
      e[nod].pop_back();
      q.pop();
      
      d[v] += 1 + d[nod];
      for(auto it = e[v].begin(); it!=e[v].end(); it++)
         if( *it==nod ) {
            e[v].erase(it);
            break;
         }
      if( e[v].size()==1 )
         q.push(v);
   }

   printf("%d\n", res);

   return 0;
}
