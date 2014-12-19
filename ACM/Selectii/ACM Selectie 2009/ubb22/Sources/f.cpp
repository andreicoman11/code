//Source of Charizard

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXS = 27;
const int MODULO = 1234567891;

class Matrix {
public:
  static int size;
  int mat[MAXS][MAXS];

  inline Matrix operator * (const Matrix & other) const {
    Matrix res;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        res.mat[i][j] = 0;
        for (int k = 0; k < size; k++) {
          res.mat[i][j] = (res.mat[i][j] + (long long) mat[i][k] * other.mat[k][j]) % MODULO;
        }
      }
    }
    return res;
  }

  // p > 0
  inline Matrix operator ^ (int k) const {
    Matrix cur(*this);
    int p;
    for (p = 1; (k & p) == 0; p <<= 1) {
      cur = cur * cur;
    }
    Matrix res(cur);
    for (p <<= 1; p <= k; p <<= 1) {
      cur = cur * cur;
      if (k & p) {
        res = res * cur;
      }
    }
    return res;
  }
};

int Matrix::size;


int count(int n, int k) {
  if (n <= 2) {
    return 26 * n;
  }
  Matrix unit;
  Matrix::size = k + 1;
  memset(unit.mat, 0, sizeof(unit.mat));
  for (int i = 1; i <= k; i++) {
    unit.mat[i][i] = i;
    if (i < k) {
      unit.mat[i][i + 1] = 26 - i;
    }
    unit.mat[i][0] = 1;
  }
  unit.mat[0][0] = 1;
  Matrix trans = unit ^ ((n - 1) / 2);
  long long ans = 0;
  if (n & 1) {
    ans = trans.mat[1][0] * 52LL % MODULO;
    for (int i = 1; i <= k; i++) {
      ans = (ans + trans.mat[1][i] * 26LL) % MODULO;
    }
  } else {
    for (int i = 0; i <= k; i++) {
      ans = (ans + trans.mat[1][i] * 52LL) % MODULO;
    }
  }
  return (int) ans;
}

void main()
{
	int test;
	//freopen("f.in", "r", stdin);
	//freopen("f.out", "w", stdout);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		long long n, k;
		cin >> n >> k;
		cout << count(n, k) << endl;
	}
}