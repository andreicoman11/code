#include <cstdlib>
#include <iostream>
using namespace std;

#define INFILE "hashuri.in" 
#define OUTFILE "hashuri.out"
#define MOD 660053

struct nod{
  int val;
  nod* next;
};

nod* table[MOD];

int contains(int x)
{
  nod* n = table[x % MOD];
  while( n!=NULL && n->val!=x )
    n = n->next;
  
  return (n!=NULL);
}

void add(int x)
{
  if( contains(x) )
    return;
  int key = x % MOD;
  nod* nx = new nod();
  nx->val = x;
  nx->next = table[key];
  table[key] = nx;
}

void del(int x)
{
  int key = x % MOD;
  nod* n = table[key];
  nod* m = NULL;
  while( n!=NULL)
  {
    if( n->val==x )
    {
      if( m==NULL )
        table[key] = n->next;
      else
        m->next = n->next;
      delete n; 
      return;
    }
    m = n; 
    n = n->next;
  }
}

int main()
{
  int n, nr;
  int op;
  FILE* fin = fopen(INFILE, "r");
  FILE* fout = fopen(OUTFILE, "w");
  memset(table, NULL, sizeof(table));
  fscanf(fin, "%d", &n);
  while( n-- )
  {
    fscanf(fin, "%d %d", &op, &nr);
    if( op==1 ) add(nr);
    else if( op==2 ) del(nr);
    else fprintf(fout, "%d\n", contains(nr));
  }
	
	return 0;
}
