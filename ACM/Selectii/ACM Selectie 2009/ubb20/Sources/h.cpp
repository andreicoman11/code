//Code of TTLovePP

#include <cstdlib> 
#include <cctype> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <string> 
#include <iostream> 
#include <sstream> 
#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <fstream> 
#include <numeric> 
#include <iomanip> 
#include <bitset> 
#include <list> 
#include <stdexcept> 
#include <functional> 
#include <utility> 
#include <ctime> 
using namespace std; 
#define pi (3.1415926535897932384626433832795) 
#define sqr(x) ((x)*(x)) 

int score(vector <string> s) 
{ 
int ret=0,n=s.size(); 
for (int i=0;i<n;i++) { 
  if (s[i][0]>='2' && s[i][0]<='9') ret+=s[i][0]-'0'; 
  if (s[i][0]=='T') ret+=10; 
  if (s[i][0]=='J') ret+=10; 
  if (s[i][0]=='Q') ret+=10; 
  if (s[i][0]=='K') ret+=10; 
  if (s[i][0]=='A') ret+=11; 
} 
return ret; 
} 

void main()
{
	int test;
	//freopen("h.dat", "r", stdin);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		int n;
		cin >> n;
		vector <string> aux(n);
		for(int i = 0; i < n; ++i) cin >> aux[i];
		cout << score(aux) << endl;
	}
}