#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <list>
using namespace std;

ifstream fin ("balanced_smileystxt.txt");
ofstream fout (".out");

void solve() {
   string str;
   getline(fin, str);
   int pmin = 0, pmax = 0;
   bool ok = 1;
   for(int i=0; i<str.size(); i++) {
      if( str[i]==':' ) {

            if( i+1<str.size() && str[i+1]=='(' ) {
               pmax++;
               i++;
            }

            if (i+1<str.size() && str[i+1]==')' ) {
               pmin--;
               i++;
            }

      } else if( str[i]=='(' ) {
            pmin++;
            pmax++;

      } else if( str[i]==')' ) {
            pmin--;
            pmax--;
      }

      if( pmax<0 ) {
         ok = 0; 
         break;
      }
   }
   if( pmin>0 ) ok = 0;

   if( ok ) fout << "YES\n";
   else fout << "NO\n";
}

int main() {
   int N, N2 = 1;
	fin >> N;
   string str;
   getline(fin, str);
	while( N2<=N ) {
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}