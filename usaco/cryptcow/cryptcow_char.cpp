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
#define REP(x, hi) for (int x=0; x<(hi); x++)
#define REPD(x, hi) for (int x=((hi)-1); x>=0; x--)
#define FOR(x, lo, hi) for (int x=(lo); x<(hi); x++)
#define FORD(x, lo, hi) for (int x=((hi)-1); x>=(lo); x--)
#define FORALL(it,x) for (typeof(x.begin()) it=x.begin(); it!=x.end(); it++)
#define INFILE "cryptcow.in" 
#define OUTFILE "cryptcow.out"

ifstream fin (INFILE);
ofstream fout (OUTFILE);

int total[16] = {0};
const int HashSize=131071;

bool hashtable[HashSize]={false};

int hashing(char str[128]);

/* verify if the sequence given from s is in target */
bool has(char s[128], char target[128], int j, int k)
{
  for(int i=0; i<=strlen(target)-k; i++)
    if( strncmp(s+j,target+i,k)==0 )
      return true;

  return false;
}

bool verif(char *s[128], char *target[128])
{
  int i = 0;
  while( i<strlen((*s)) && (*s)[i]!='C' && (*s)[i]!='O' && (*s)[i]!='W' ) i++;
  if( (*s)[i]=='O' || (*s)[i]=='W' ) return false;
  //if( (*s).substr(0,i)!=(*target).substr(0,i) )
  if( strncmp( (*s), (*target), i)!=0 )
  {
    return false;
  }

  int k = strlen((*s)) - 1;
  int j = strlen((*target)) - 1;
  while( j>=0 && k>=0 && (*s)[k]!='C' && (*s)[k]!='O' && (*s)[k]!='W') {k--;j--;}
  if( (*s)[k]=='O' || (*s)[k]=='C' ) return false;
  //if( (*s).substr(k+1)!=(*target).substr(j+1) )
  if( j>=0 && k>=0 && strcmp((*s)+k+1, (*target)+j+1)!=0 )
  { 
    return false;
  }
  //strncpy((*s), (*s)+i, k+1-i);
  //(*s)[k+1-i] = '\0';
  //cout << *s << endl;
  //(*s) = (*s).substr(i,k+1-i);
  //strncpy((*target), (*target)+i, j+1-i);
  //(*target)[j+1-i] = '\0';
  //(*target) = (*target).substr(i,j+1-i);
  //cout << *target << endl;

  // verify that already computed parts in s actually exist in target
  i = 0;
  while( i<strlen(*s) )
  {
    j = i;
    k = 0;
    while( i<strlen(*s) && (*s)[i]!='W' && (*s)[i]!='C' && (*s)[i]!='O')
    {
      k++;
      i++;
    }
    if( k )
    {
      if( !has(*s, *target, j, k) )
        return false;
    }
    else i++;
  }

  return true;
}

bool dfs(int rem, char s[128], char target[128])
{
  int index=hashing(s);
  if(hashtable[index])
    return false;

  total[rem]++;
  //cout << s << " " << rem << "\t";
 
  if( rem==0 )
  {
    if( strcmp(s,target)==0 ) return true;
    return false;
  }
  else
  {
    /* simplify strings */
    if( !verif(&s, &target) )
      return false;
    //cout << rem << " " << s << " " << target << endl;

    //if( s[0]!='C' ) return false;
    //if( s[strlen(s)-1]!='W' ) return false;
    
    FOR(i, 0, strlen(s)-2)
      if( s[i]=='C' )
      FOR(j, i+1,strlen(s)-1)
        if( s[j]=='O' )
        FOR(k, j+1, strlen(s))
          if( s[k]=='W' )
          {
            char s2[128];
            strncpy( s2, s, i);
            s2[i] = '\0';
            strncat( s2, s+j+1, k-j-1 );
            s2[k+i-j-1] = '\0';
            strncat( s2, s+i+1, j-i-1 );
            s2[k-2] = '\0';
            strcat( s2, s+k+1);
            /*string aux = s;
            aux = aux.substr(0,i) + aux.substr(j+1,k-j-1) + aux.substr(i+1,j-i-1) + aux.substr(k+1);
            string aux2 = s2;
            if( aux !=aux2 )
              cout << "here\n";*/
            //if( dfs( rem-1, s.substr(0,i) + s.substr(j+1,k-j-1) + s.substr(i+1,j-i-1) + s.substr(k+1), target) )
            if( dfs( rem-1, s2, target) )
              return true;
          }
  }
  return false;
}

int main()
{
  char str[128];
  fin.getline( str, 128);
  string s = str;

  int c, o, w;
  c = o = w = 0;
  string aux = "";
  
  char target[128] = "Begin the Escape execution at the Break of Dawn\0";

  REP(i, s.sz)
    if( s[i]=='C' ) c++;
    else if( s[i]=='O' ) o++;
    else if( s[i]=='W' ) w++;
    else aux += s[i];

  SORT(aux);
  string t = target;
  SORT(t);
  if( c!=o || o!=w || w!=c || t!=aux )
  {
    fout << "0 0\n";
    return 0;
  }

  bool found = dfs(c, str, target);
  if( found )
    fout << "1 " << c << endl;
  else
    fout << "0 0\n";
  
  REP(i, c)
    cout << total[i] << endl;

	return 0;
}

int hashing(char str[128])
{
  unsigned long h=0,g;
  for (int i=0; i<strlen(str); i++)
  {
    h=(h<<4)+str[i];
    g=h &0xf0000000l;
    if (g)
    {
      h^=g>>24;
    }
    h&=~g;
    }
  return h%HashSize;
}