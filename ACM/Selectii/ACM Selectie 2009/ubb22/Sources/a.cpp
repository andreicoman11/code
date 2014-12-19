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
#include <map>
 
using namespace std;
 
 
int MOD = 1234567891;
 
int P1[52], P2[52];
int C[26], D[26];
map<vector<int>, int> Hash;
int count(int E[3][3])
{
vector<int> State;
for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
    State.push_back(E[i][j]);
if (Hash.find(State) != Hash.end())
  return Hash[State];
for (int i = 0; i < 3; i++)
  for (int j = 0; j < 3; j++)
    if (i > 0 && E[i][j] > 0)
    {
      int Results = 0;
      for (int u = 0; u < 3; u++)
        for (int v = 0; v < 3; v++)
          if (v > 0 && E[u][v] > 0)
          {
            int multiply = (i == u && j == v) ? (E[u][v] - 1) : E[u][v];
            if (v == 2)
              multiply *= 2;
            if (multiply == 0)
              continue;
            E[i][j]--;
            E[i-1][j]++;
            E[u][v]--;
            E[u][v-1]++;
            int Temporary = count(E);
            Results = ((long long)Results + (long long)Temporary * multiply) % MOD;
            E[i][j]++;
            E[i-1][j]--;
            E[u][v]++;
            E[u][v-1]--;
          }
      return Hash[State] = Results;
    }
return Hash[State] = 1;
}
int count(string S1, string S2)
{
int N = S1.length();
for (int I = 0; I < N; I++)
  if (tolower(S1[I]) == tolower(S2[I]))
    return 0;
memset(P1, 255, sizeof(P1));
memset(P2, 255, sizeof(P2));
for (int I = 0; I < N; I++)
{
  int v1 = (S1[I]<='Z')?(S1[I]-'A'):(26+S1[I]-'a');
  int v2 = (S2[I]<='Z')?(S2[I]-'A'):(26+S2[I]-'a');
  if (P1[v1] >= 0 && P1[v1] != v2)
    return 0;
  if (P2[v2] >= 0 && P2[v2] != v1)
    return 0;
  P1[v1] = v2;
  P2[v2] = v1;
}
memset(C, 0, sizeof(C));
memset(D, 0 ,sizeof(D));
for (int I = 0; I < 52; I++)
{
  if (P1[I] < 0)
    C[I % 26]++;
  if (P2[I] < 0)
    D[I % 26]++;
}
Hash.clear();
int E[3][3];
memset(E, 0, sizeof(E));
for (int I = 0; I < 26; I++)
  E[C[I]][D[I]]++;
int Results = count(E);
return Results;
}

void main()
{
	int test;
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		string n, k;
		cin >> n >> k;
		cout << count(n, k) << endl;
	}
}