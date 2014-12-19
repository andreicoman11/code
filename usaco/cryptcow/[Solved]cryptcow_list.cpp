/*
ID: andreic4
PROG: cryptcow
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <list>
#include <map>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;

#define pb push_back
#define sz size()
#define SORT(x) sort(x.begin(), x.end())
#define REVERSE(X) reverse(x.begin(), x.end())
#define REP(x, hi) for (size_t x=0; x<(hi); x++)
#define REPD(x, hi) for (size_t x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (size_t x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (size_t x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "cryptcow.in" 
#define OUTFILE "cryptcow.out"
#define FNVINI 7
#define FNVP 31
#define MAXNR 502973
#define NUMT 97011

ifstream fin (INFILE);
ofstream fout (OUTFILE);

struct hashnod{
  char str[76];
  hashnod* next;
};

hashnod entries[NUMT];

int hashno = 0;
hashnod *hasht[MAXNR];
int vals[256];

struct nod{
  char c;
  nod* prev;
  nod* next;

  nod()
  {
    prev = next = NULL;
    c = ' ';
  }

  void push_back(char c2)
  {
    nod* n = new nod();
    n->c = c2;
    n->next = NULL;
    n->prev = this;
    this->next = n;
  }
};

nod *s, *send, *target, *tend;

bool checkHash();

void prints();

void printstring()
{
  nod* q;
  q = s;
  while( q!=send->next )
  {
    cout << q->c;
    q = q->next;
  }
  cout << "\t";
  q = target;
  while( q!=tend->next )
  {
    cout << q->c;
    q = q->next;
  }
  cout << "\n";
}

bool verif2()
{
  //printstring();
  nod* s2 = s;
  nod* s2end = s;
  nod* p, *q;
  bool ok;
  while( s2end!=send->next )
  {
    s2 = s2end;
    while( s2end!=send->next && s2end->c!='C' && s2end->c!='O' && s2end->c!='W')
    {
      s2end = s2end->next;
    }

    if( s2!=s2end )
    {
      // check if s2->s2end exists in target->tend
      p = target;
      ok = 0;
      while( p!=tend->next && !ok )
      {
        q = s2;
        while( q!=s2end && p!=tend->next && p->c==q->c )
        {
          p = p->next;
          q = q->next;
        }
        if( q==s2end ) ok = 1;
        if(q==s2) p = p->next;
      }
      if( !ok ) return false;
    }
    else s2end = s2end->next;
  }
  return true;
}

bool verif()
{
  //cout << s->c << " " << send->c << endl;
  // verify all characters from start until next C, O or W
  while( s!=send->next && s->c!='C' && s->c!='O' && s->c!='W'  )
  {
    //cout << s->c << " " << send->c << endl;
    if( s->c != target->c ) return false; /* diff chars */
    s = s->next;
    target = target->next;
  }

  if( s==send->next && target==tend->next ) return true;

  // verify all characters from end until prev C, O or W
  while( send!=s->prev && send->c!='C' && send->c!='O' && send->c!='W' )
  {
    //cout << s->c << " " << send->c << endl;
    if( send->c != tend->c ) return false; /* diff chars */
    send = send->prev;
    tend = tend->prev;
  }

  return verif2();
}

bool dfs(int rem)
{
  /* simplify strings */
  if( !verif() )
      return false;
  /* if string already in hash, don't check */
  if( checkHash() )
    return false;

  if( rem==0 )
  {
    // if no encriptions left, strings should be empty
    if( s==send->next && target==tend->next ) return true;
    return false;
  }
  else
  {
    if( s->c != 'C' ) return false;
    if( send->c != 'W' ) return false;
    nod* i = s;
    nod* j = s;
    nod* k = s;
    nod *saux, *sendaux, *taux, *tendaux;

    // not until null, but until pointer to end of s
    for(; i->next!=send; i = i->next)
      if( i->c=='C' )
      for(j = i->next; j!=send; j = j->next)
        if( j->c=='O' )
        for(k = j->next; k!=send->next; k = k->next)
          if( k->c=='W' )
          {
            // i=C, j=O, k=W
            //printstring();
            saux = s;
            sendaux = send;
            taux = target;
            tendaux = tend;

            nod* ii = i->prev;
            nod* jj = j->prev;
            nod* kk = k->prev;
            
            if( i->next==j && j->next==k )
            {//cout << "Case 1:\n";
              if( ii!=NULL ) ii->next = k->next;
              if( i==s ) s = k->next;
              if( k->next!=NULL ) k->next->prev = i->prev;
              if( k==send ) send = i->prev;
            }
            else if( i->next==j )
            {//cout << "Case 2:\n";
              if( ii!=NULL ) ii->next = j->next;
              j->next->prev = ii;
              k->prev->next = k->next;
              if( k->next!=NULL ) k->next->prev = k->prev;
              if( i==s ) s = j->next;
              if( k==send ) send = k->prev;
            }
            else if( j->next==k )
            {//cout << "Case 3:\n";
              if( k->next!=NULL ) k->next->prev = j->prev;
              jj->next = k->next;
              if( ii!=NULL) ii->next = i->next;
              i->next->prev = i->prev;
              if( i==s ) s = i->next;
              if( k==send ) send = j->prev;
            }
            else
            {
              if( i==s ) s = j->next;
              if( k==send ) send = j->prev;

              if( ii!=NULL ) ii->next = j->next;
              j->next->prev = ii;
              kk->next = i->next;
              i->next->prev = kk;
              jj->next = k->next;
              if( k->next!=NULL ) k->next->prev = jj;
            }

            //printstring();cout << "------------------------------------------------------------\n";
            //aux = aux.substr(0,i) + aux.substr(j+1,k-j-1) + aux.substr(i+1,j-i-1) + aux.substr(k+1);
            if( dfs( rem-1) )
              return true;

            // redo list
            if( ii!=NULL ) ii->next = i;
            i->next->prev = i;
            jj->next = j;
            j->next->prev = j;
            kk->next = k;
            if( k->next!=NULL ) k->next->prev = k;
            s = saux;
            send = sendaux;
            target = taux;
            tend = tendaux;
          
          }
  }
  return false;
}

int main()
{
  char str[128];
  fin.getline( str, 128);
  string sstr = str;

  int c, o, w;
  c = o = w = 0;
  string aux = "";
  
  char targetstr[128] = "Begin the Escape execution at the Break of Dawn\0";

  REP(i, sstr.sz)
    if( sstr[i]=='C' ) c++;
    else if( sstr[i]=='O' ) o++;
    else if( sstr[i]=='W' ) w++;
    else aux += sstr[i];

  SORT(aux);
  string t = targetstr;
  SORT(t);
  if( c!=o || o!=w || w!=c || t!=aux )
  {
    fout << "0 0\n";
    return 0;
  }

  nod* slist = new nod();
  nod* tlist = new nod();
  slist->c = sstr[0];
  tlist->c = targetstr[0];
  nod* sbegin = slist;
  nod* tbegin = tlist;
  FOR(i, 1, sstr.sz)
  {
    slist->pb(sstr[i]);
    slist = slist->next;
  }

  FOR(i, 1, strlen(targetstr))
  {
    tlist->pb(targetstr[i]);
    tlist = tlist->next;
  }

  s = sbegin;
  send = slist;
  target = tbegin;
  tend = tlist;

  int cnr = 0;
  for(char cc = 'a'; cc<='z'; cc++, cnr++)
    vals[cc] = cnr;
  for(char cc = 'A'; cc<='Z'; cc++, cnr++)
    vals[cc] = cnr;
  vals[' '] = cnr+1;

  bool found = dfs(c);
  if( found )
    fout << "1 " << c << endl;
  else
    fout << "0 0\n";
  
	return 0;
}

void prints()
{
  nod* i = s;
  while( i!=send->next )
  {
    cout << i->c;
    i = i->next;
  }
  cout << endl;
}

/* Fowler / Noll / Vo (FNV) Hash */
bool checkHash()
{
  unsigned int hash = FNVINI;
  char *str = entries[hashno].str;
  nod* p = s;
  int k = 0;
  while( p!=send->next )
  {
    hash = ( hash << 5 ) + hash + vals[p->c];
    str[k++] = p->c;
    p = p->next;
  }
  str[k] = '\0';
  while( hash>=MAXNR ) hash -= MAXNR;

  hashnod* h = hasht[hash];
  while( h!=NULL )
  {
    if( strcmp(h->str, str)==0 )
      return true;
    h = h->next;
  }

  // add string if not yet here and can still put in hash table
  if( hashno<NUMT-1 )
  {
    entries[hashno].next = hasht[hash];
    hasht[hash] = &entries[hashno];
    hashno++;
  }

  return false;
}
