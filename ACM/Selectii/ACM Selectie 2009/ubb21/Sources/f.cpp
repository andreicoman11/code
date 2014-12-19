//Code of marveringius

#include <climits> 
#include <queue> 
#include <cmath> 
#include <stack> 
#include <set> 
#include <cstring> 
#include <cstdio> 
#include <iostream> 
#include <vector> 
#include <string> 
#include <sstream> 
#include <map> 
#include <algorithm> 
#include <cstdlib> 
using namespace std; 

#define ll long long 
#define fe(i,a,n) for(int i = a, __n = (int)n; i < __n; i++) 
#define fi(i,a,n) for(int i = a, __n = (int)n; i <= __n; i++) 
#define all(v) v.begin(),v.end() 
#define DOUBLE_MAX numeric_limits<double>::max() 
#define DOUBLE_MIN numeric_limits<double>::min() 
#define ERRO 1e-10 

string encrypt(string message)  { 
	string a; 
	char c = 'a'; 
	vector<bool> ok(260, false); 
	vector<char> alfa(260, ' '); 
	fe(i,0,message.size()) { 
		if(ok[message[i]]) 
			a.push_back(alfa[message[i]]); 
		else { 
			a.push_back(c); 
			ok[message[i]] = true; 
			alfa[message[i]] = c; 
			c++; 
		} 
	} 
	return a; 
}

void main()
{
	int test;
	freopen("f.dat", "r", stdin);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		string s;
		cin >> s;
		cout << encrypt(s) << endl;
	}
}