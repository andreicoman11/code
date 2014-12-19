#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define INFILE "tastatura.in" 
#define OUTFILE "tastatura.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);
static const int XMAX = 1005;
struct nod{
   bool isend;
   nod *c[10];
   nod() {
      isend = 0;
      for(int i=0; i<10; i++)
         c[i] = NULL;
   }
};

nod *tree;
int n;
string x;
int d[XMAX];

int main() {
   tree = new nod();
   fin >> x;
   fin >> n;
   for(int i=0; i<n; i++) {
      string aux;
      fin >> aux;
      nod * node = tree;
      for(int j=0; j<aux.size(); j++)
         if( node->c[int(aux[j]-'0')] == NULL ) {
            node->c[int(aux[j]-'0')] = new nod();
            node = node->c[int(aux[j]-'0')];
         } else
            node = node->c[int(aux[j]-'0')];
      node->isend = 1;
   }

   for(int i=0; i<x.size(); i++) {
      d[i] = i+1;
   }

   for(int i=0; i<x.size(); i++) {
      if(i)
         d[i] = min(d[i], d[i-1] + 1);
      nod* node = tree;
      int j = 0;
      while( node!=NULL && i+j<x.size() ) {
         node = node->c[ int(x[i+j] - '0') ];
         if( node!=NULL && node->isend )
            d[i+j] = min(d[i+j], (i ? d[i-1] : 0) + 1);
         j++;
      }
   }

   fout << d[x.size()-1];

   return 0;
}
