//Code of Storm-Spirit

#include <map>  
#include <set>  
#include <deque>  
#include <vector>  
#include <string>  
#include <cstdio>  
#include <cstring>  
#include <sstream>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
template <class T> void out(T A[], int n) {for (int i = 0; i<n; i++) cout << A[i] << ' '; cout << endl;}   
template <class T> void out(vector<T> A, int n) {for (int i = 0; i<n; i++) cout << A[i] << ' '; cout << endl;}  

int a[2000], N; 
string s, ss; 

void ch(int a) { 
	s = ""; 
	for (int i=0; i<N; i++) { 
		if (a & 1) s = "1"+s; else s = "0"+s; 
		a /= 2; 
	} 
} 

int ava(int a, int b) { 
	if (a == b) return 0; 
	ch(a); ss = s; 
	ch(b); 
	int c0 = 0, c1 = 0; 
	for (int i=0; i<N; i++) 
		if (s[i] == '1' && ss[i] == '0') c0 = 1; 
	for (int i=0; i<N; i++) 
		if (s[i] == '0' && ss[i] == '1') c1 = 1; 
	return c0+c1 != 2; 
} 

string password(int n, int k) {   
	memset(a, 0, sizeof(a)); 
	a[0] = 1; N = n; 
	int cur = 0; 
	for (int i=1; i<k; i++) { 
		for (int j=1; j<(1 << n); j++) 
			if (!a[j] && ava(cur, j)) { 
				cur = j; 
				a[j] = 1; 
				break; 
			} 
	} 
	ch(cur); 
	return s; 
}   

void main()
{
	int test;
	freopen("g.dat", "r", stdin);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		int n, k;
		cin >> n >> k;
		cout << password(n, k) << endl;
	}
}