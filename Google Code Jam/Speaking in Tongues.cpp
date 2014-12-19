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

ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small.out");

int N, N2 = 1;

map<char, char> m;
string ins = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv",
         outs = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char buf[128];

int main()
{
   for(int i=0; i<ins.size(); i++)
      m[ins[i]] = outs[i];
   m['q'] = 'z';
   m['z'] = 'q';
	fin >> N;
   fin.getline(buf, 128, '\n');
	while( N2<=N )
	{
      fin.getline(buf, 128, '\n');
      fout << "Case #" << N2++ << ": ";
      for(int i=0; i<strlen(buf); i++)
         fout << m[buf[i]];
      fout << "\n";		
	}

	return 0;
}
