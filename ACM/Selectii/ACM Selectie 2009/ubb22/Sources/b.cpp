//Source of xreborner

#include <iostream> 
#include <memory> 
#include <vector> 
#include <algorithm> 
#include <string> 
#include <utility> 
#include <functional> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cmath> 
#include <cassert> 
#include <sstream> 
 
using namespace std;
 
string check(int n, long long k)
{
if (n == 1)
  return (k == 1) ? "0" : "1";
else
{
  long long m = (long long)1 << (n - 1);
  if (k <= m)
    return "0" + check(n - 1, k);
  else
    if (k == m + 1)
      return "1" + check(n - 1, m);
    else
      return "1" + check(n - 1, k - m - 1);
}
}
string password(int n, long long k)
{
if (n == 1)
  return (k == 1) ? "0" : "1";
else
{
  long long m = (long long)1 << (n - 1);
  if (k <= m)
    return "0" + password(n - 1, k);
  else
    if (k == m + 1)
      return "1" + check(n - 1, m);
    else
    {
      string s = "1" + check(n - 1, m);
      string t = "1" + password(n - 1, k - m - 1);
      return (s > t) ? s : t;
    }
}
}

void main()
{
	int test;
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		long long n, k;
		cin >> n >> k;
		cout << password(n, k) << endl;
	}
}