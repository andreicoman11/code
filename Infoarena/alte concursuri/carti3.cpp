#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <deque>
using namespace std;

#define LL long long
#define INFILE "carti3.in" 
#define OUTFILE "carti3.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

deque<int> l;

int main() {
   int n, c;
   fin >> n >> c;
   for(int i=0; i<c; i++)
   {
      int aux; 
      fin >> aux;
      l.push_back(aux);
   }

   int dir = 0;
   for(int i=0; i<n; i++)
   {
      int aux;
      fin >> aux;
      if( aux==-1 ) dir = 1 - dir;
      else {
         if( dir==1 ) l.push_back(aux);
         else        l.push_front(aux);
      }
   }

   if( dir==0 ) {
      for(deque<int>::iterator it=l.begin(); it!=l.end(); it++)
         fout << *it << "\n";
   } else {
      for(deque<int>::reverse_iterator it=l.rbegin(); it!=l.rend(); it++)
         fout << *it << "\n";
   }

   return 0;
}
