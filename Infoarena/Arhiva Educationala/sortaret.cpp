#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define INFILE "sortaret.in" 
#define OUTFILE "sortaret.out"
#define NMAX 50001
#define MMAX 50001

int n, m;

struct list{
  int nod;
  list* next;
};

list *nodes[NMAX] = {NULL};;
int outgoing[NMAX] = {0};

int main()
{
  freopen(INFILE, "r", stdin);
  freopen(OUTFILE, "w", stdout);

  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    list* node = new list();
    node->nod = a;
    outgoing[a]++;
    if( nodes[b]==NULL )
    {
      nodes[b] = node;
      node->next = NULL;
    }
    else
    {
      node->next = nodes[b];
      nodes[b] = node;
    }
  }

  int coada[NMAX] = {0};
  int head = 0, tail = -1;

  for(int i=0; i<n; i++)
    if( outgoing[i]==0 )
    {
      coada[++tail] = i;
    }

  while( head<=tail )
  {
    list* node = nodes[coada[head]];
    while( node!=NULL )
    {
      outgoing[node->nod]--;
      if( outgoing[node->nod]==0 )
      {
        coada[++tail] = node->nod;
      }
      list* aux = node;
      node = node->next;
      delete aux;
    }

    head++;
  }

  printf("%d", coada[tail--]+1);
  while(tail>=0)
  {
    printf("% d", coada[tail--]+1);
  }
	
	return 0;
}
