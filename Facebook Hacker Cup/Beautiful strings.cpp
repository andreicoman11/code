#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

#define LL long long
#define INFILE "beautiful_stringstxt.txt" 
#define OUTFILE ".out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

void solve() {
   string str;
   getline(fin, str);
   vector<int> c(26);
   for(int i=0; i<str.size(); i++)
      if( isalpha(str[i]) ) c[ toupper(str[i]) - 'A' ]++;
   sort(c.begin(), c.end());
   int sum = 0;
   for(int i=25; i>=0; i--)
      sum += c[i] * (1+i);
   fout << sum << '\n';
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
