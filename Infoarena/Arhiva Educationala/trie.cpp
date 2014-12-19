#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(x) reverse(x.begin(), x.end())
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "trie.in"
#define OUTFILE "trie.out"
#define CHARNR 26

struct nod{
  int val, prefs;
  nod* next[CHARNR];
  nod() : val(0), prefs(0) 
  {
    memset(next, NULL, sizeof(next));
  }
};

int getval(char c)
{
  return int(c)-int('a');
}

void add(nod* t, char w[])
{
  if( strlen(w)==0 )
    t->val++;
  else
  {
    int pos = getval(w[0]);
    if( t->next[pos]==NULL )
    {
      t->next[pos] = new nod();
    }
    t->prefs++;
    add( t->next[pos], w+1);
  }
}

void remove(nod* t, char w[])
{
  if( strlen(w)==0 )
  {
    t->val--;
  }
  else
  {
    int pos = getval(w[0]);
    t->prefs--;
    remove(t->next[pos], w+1);
    if( t->next[pos]->prefs==0 && t->next[pos]->val==0 )
    {
      delete t->next[pos];
      t->next[pos] = NULL;
    }
  }
}

int wordcount(nod *t, char w[])
{
  if( strlen(w)==0 )
    return t->val;

  int pos = getval(w[0]);
  if( t->next[pos]==NULL )
    return 0;
  else
    return wordcount(t->next[pos], w+1);
}

int getprefix(nod* t, char w[])
{
  int pos = getval(w[0]);
  if( strlen(w)==0 || t->next[pos]==NULL )
    return 0;
  return 1 + getprefix(t->next[pos], w+1);
}

int main()
{
  char c, word[32];
  FILE* fin = fopen(INFILE, "r");
  FILE* fout = fopen(OUTFILE, "w");

  nod* t = new nod();

  while( !feof(fin) )
  {
    fscanf(fin, "%c %s\n", &c, word);
    switch(c) {
      case '0': 
        add(t, word);
        break;
      case '1': 
        remove(t, word);
        break;
      case '2': 
        //fout << wordcount(t, word) << endl;
        fprintf(fout, "%d\n", wordcount(t, word));
        break;
      case '3': 
        //fout << getprefix(t, word) << endl;
        fprintf(fout, "%d\n", getprefix(t, word));
        break;
      default: 
        break;
    }
  }
	
	return 0;
}
