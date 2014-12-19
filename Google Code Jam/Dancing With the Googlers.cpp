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

//ifstream fin ("B-small.in");
//ofstream fout ("B-small.out");
ifstream fin ("B-large.in");
ofstream fout ("B-large.out");

int N, N2 = 1;

int main()
{
	fin >> N;
	while( N2<=N )
	{
      int n, s, p;
      fin >> n >> s >> p;
      vector<int> v(n);      
      for(int i=0; i<n; i++)
         fin >> v[i];
      sort(v.begin(), v.end());

      int tp = 0;
      for(int i=n-1; i>=0; i--)
         if( v[i]>=p && v[i]>= p*3-2 ) tp++;
         else if( v[i]>=p && v[i]>=p*3-4 && s>0 ) tp++, s--;

		fout << "Case #" << N2++ << ": " << tp << endl;
	}

	return 0;
}