#include <iostream>
#include <queue>
#include <vector>
using namespace std;

main() {
  int n, m, x;
  while (cin >> n >> m && n) {
    priority_queue<int, vector<int>, greater<int> > dh, kh;
    for (int i = 0; i < n; i++) {cin >> x; dh.push(x);}
    for (int i = 0; i < m; i++) {cin >> x; kh.push(x);}
    long long cost = 0;
    while (dh.size()) {
      while (kh.size() && kh.top() < dh.top()) kh.pop();
      if (!kh.size()) goto fail;
      cost += kh.top();
      kh.pop(); dh.pop();
    }
    cout << cost << endl;
    continue;
fail:
    cout << "Loowater is doomed!" << endl;
  }
}
