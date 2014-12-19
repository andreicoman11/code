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
#include <stack>
#include <queue>
using namespace std;

//ifstream fin (".in");
//ifstream fin ("C-small.in");
ifstream fin ("C-large.in");
ofstream fout (".out");

const int INF = 0x3f3f3f3f;
const int NMAX = 4005;
map<string, int> dict;
int d[NMAX][6];

vector<pair<string, int> > all(string s) {
   vector<pair<string, int> > dic;
   dic.push_back(make_pair(s,0));

   for(int i=0; i<(int)s.size(); i++) {
      char init = s[i];
      s[i] = '*';
      dic.push_back(make_pair(s,1));
      s[i] = init;
   }

   for(int i=0; i+5<(int)s.size(); i++) {
      char init = s[i];
      s[i] = '*';
      for(int j=i+5; j<(int)s.size(); j++) {
         char init2 = s[j];
         s[j] = '*';
         dic.push_back(make_pair(s,2));
         s[j] = init2;
      }
      s[i] = init;
   }
   return dic;
}

void solve() {
   string s;
   fin >> s;
   int n = s.size();
   memset(d, INF, sizeof(d));
   d[0][0] = d[0][1] = d[0][2] = d[0][3] = d[0][4] = d[0][5] = 0;

   for(int i=1; i<=n; i++)
   for(int j=i; j<=n && j<i+11; j++) {
      auto sall = all(s.substr(i-1,j-i+1));

      for(auto it=sall.begin(); it!=sall.end(); it++) 
         if( dict.find(it->first)!=dict.end() ) {
            int first = 20, last = -1;
            if( it->second )
               for(int i=0; i<(int)it->first.size(); i++)
                  if( it->first[i]=='*' ) {
                     first = min(first, i);
                     last = max(last, i);
                  }

            //cout << it->first << " " << it->second << "\t" << first << " " << last << endl;
            if( last==-1 ) {
               for(int k=1; k<=5; k++) {
                  first = min(5, k + (int)it->first.size());
                  d[j][first] = min(d[j][first], d[i-1][k]);
               }

            } else {
               last = min(5, (int)(it->first.size() - last));

               for(int k=1; k<=5; k++)
                  if( first+k>=5 )
                     d[j][last] = min(d[j][last], d[i-1][k] + it->second);
            }
         }
   }

   //for(int i=0; i<=n; i++) {
   //   for(int k=1; k<=5; k++)
   //      cout << d[i][k] << " ";
   //   cout << endl;
   //}

   int res = d[s.size()][5];
   for(int k=1; k<=5; k++)
      res = min(res, d[s.size()][k]);
   fout << res << endl;
}

void gen_dict() {
   ifstream indic("garbled_email_dictionary.txt");
   string word;
   while( indic>>word ) {
      auto dic = all(word);
      for(auto it=dic.begin(); it!=dic.end(); it++) {
         if( dict.find(it->first)==dict.end() || dict[it->first]>it->second )
            dict[it->first] = it->second;
      }
   }
}

int main() {
   gen_dict();

   int N, N2 = 1;
	fin >> N;
	while( N2<=N ) {
      cout << "Case " << N2 << endl;
      fout << "Case #" << N2++ << ": ";
      solve();
   }

	return 0;
}