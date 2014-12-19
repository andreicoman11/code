#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <list>
using namespace std;

#define INFILE "ctc.in" 
#define OUTFILE "ctc.out"
#define NMAX 100002
int n, m, idx[NMAX], lowidx[NMAX], idxcnt = 0;
vector<list<int> > e, C;
bool vis[NMAX], instack[NMAX];
stack<int> st;

void scc(int nod)
{
   idx[nod] = lowidx[nod] = idxcnt++;
   vis[nod] = instack[nod] = 1;
   st.push(nod);

   for(list<int>::iterator it=e[nod].begin(); it!=e[nod].end(); it++)
      if( !vis[*it] )
      {
         scc(*it);
         lowidx[nod] = min(lowidx[nod], lowidx[*it]);
      }
      else if( instack[*it] )
         lowidx[nod] = min(lowidx[nod], lowidx[*it]);

   if( idx[nod]==lowidx[nod] )
   {
      list<int> comp;
      int stnod;
      do{
         stnod = st.top();
         st.pop();
         comp.push_back(stnod);
         instack[stnod] = 0;
      }while(stnod!=nod);
      C.push_back(comp);
   }
}

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   scanf("%d %d", &n, &m);
   e.resize(n);
   for(int i=0; i<m; i++)
   {
      int a, b;
      scanf("%d %d", &a, &b);
      e[a-1].push_back(b-1);
   }

   for(int i=0; i<n; i++)
      if( !vis[i] )
         scc(i);

   cout << C.size() << "\n";
   for(int i=0; i<C.size(); i++)
   {
      for(list<int>::iterator it=C[i].begin(); it!=C[i].end(); it++)
         printf("%d ", (*it)+1);
      printf("\n");
   }


   return 0;
}
