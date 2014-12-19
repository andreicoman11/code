//Source of ktuan

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(a,b) memset( (a), (b), sizeof(a))
#define pb push_back
#define MP make_pair
 
 
double distance(vector <int> x, vector <int> y, int k) {
  int n = x.size();
  Rep(i,n) {
    x[i] *= 2;
    y[i] *= 2;
  }
  int best = 1000000000;
  For(u,-100,100) {
    For(v,-100,100) {
      vector<int> dist;
      Rep(i,n) {
        dist.pb( abs(x[i] - u) + abs(y[i] - v));
        
      }
      sort( dist.begin(), dist.end());
      int r = dist[k-1];
      if(best > r) best = r;
    }
  }  
  return best * 0.5;
}

void main()
{
	int test;
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		int n, k;
		cin >> n;
		vector <int> a(n), b(n);
		For(i, 0, n - 1) cin >> a[i];
		cin >> n;
		For(i, 0, n - 1) cin >> b[i];
		cin >> k;
		cout << fixed << setprecision(1) << distance(a, b, k) << endl;
	}
}