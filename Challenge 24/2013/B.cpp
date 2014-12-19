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
#include <queue>
#include <stack>
#include <list>
using namespace std;

const long long MOD = 1000000007;

#define PROBLEM "B"
ifstream fin;
ofstream fout;

int n, t;
vector<long long> man;
vector<long long> cop[2];

void solve2() {
	fin >> n >> t;
   int sz = (1<<n);
   man.resize(sz);
   cop[0].resize(sz);
   cop[1].resize(sz);
   for(int i=0; i<sz; i++)
      fin >> man[i];
   
   int x = 0;
   for(int i=0; i<sz; i++){
      cop[x][i] = (cop[x][i] + 2 * (man[i] * man[i] - man[i])%MOD ) % MOD;
      for(int j=i+1; j<sz; j++)
         cop[x][i|j] = (cop[x][i|j] + (2 * man[i] * man[j]) % MOD) % MOD;
   }

   for(int t1=1; t1<t; t1++)
   {
      x = 1-x;
      for(int i=0; i<sz; i++)
         cop[x][i] = 0;

      for(int i=0; i<sz; i++)
      {
         //cop[x][i] = (cop[x][i] + (cop[1-x][i] * cop[1-x][i] - cop[1-x][i])%MOD ) % MOD;
         for(int j=0; j<sz; j++)
         {
            cop[x][i|j] = (cop[x][i|j] + 2 * (cop[1-x][i] * man[j]) % MOD) % MOD;
         }
      }

      //long long sum = 0LL;;
      //for(int i=0; i<sz; i++)
      //   sum += cop[x][i];
      //std::cout << sum;
      //return ;
   }
   std:: cout << cop[x][sz-1] % MOD;
   fout << cop[x][sz-1] % MOD;
}

void solve() {
	fin >> n >> t;
   int sz = (1<<n);
   cop[0].resize(sz);
   cop[1].resize(sz);
   for(int i=0; i<sz; i++)
      fin >> cop[0][i];
   
   int x = 0;
   for(int t1=0; t1<t; t1++)
   {
      x = 1-x;
      for(int i=0; i<sz; i++)
         cop[x][i] = 0;

      for(int i=0; i<sz; i++)
      {
         //cop[x][i] = (cop[x][i] + 2 * (cop[1-x][i] * cop[1-x][i] - cop[1-x][i])%MOD ) % MOD;
         for(int j=0; j<sz; j++)
         {
            cop[x][i|j] = (cop[x][i|j] + (cop[1-x][i] * cop[1-x][j])%MOD) % MOD;
         }
      }
   }
   std:: cout << cop[x][sz-1] % MOD;
   fout << cop[x][sz-1] % MOD;
}

int main() {
	for(int i=4; i<=10; i++) {
		ostringstream ins, outs;
		ins << i << ".in";
		outs << PROBLEM << i << ".out";		
		fin.open(ins.str());
		fout.open(outs.str());

		solve();

		fin.close();
		fout.close();
	}

	return 0;
}