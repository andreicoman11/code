//This is the code of tourist

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

#include <stdio.h>

using namespace std; 


int shuffle(int n, int left, int right) 
{ 
  int i, win, lf, rf;
  if (n % 2 == 0) i = 4, win = 2;
  else i = 3, win = 1;
  for (;i<=n;i+=2) {
    lf = left % ((i+1)/2);
    rf = right % (i/2);
    if (win <= rf) win = (i-(i&1))-2*(rf-win); else
    if (win <= i/2-1) win = 2*(win-rf); else
    if (win <= i/2-1+lf) win = (i-1+(i&1))-2*(i/2-1+lf-win);
    else win = 2*(win-i/2+1-lf)-1;
  }
  return win;
} 

void main()
{
	int test;
	//freopen("a.dat", "r", stdin);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		int n, left, right;
		cin >> n >> left >> right;
		cout << shuffle(n, left, right) << endl;
	}
}