//Code of ACRush

#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 

#define SIZE(X) ((int)(X.size())) 
typedef long long int64; 

const int64 MODE=1234567891; 

struct TPoint 
{ 
  int64 state,result; 
  TPoint *next; 
}; 
int memoryId=0; 
TPoint memory[3000000]; 
TPoint  *hash[1000003]; 

map<int64,int64> M; 
int64 solve(int C[3][3],int side,int si,int sj) 
{ 
int total_left=0; 
for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (i+j>0) total_left+=C[i][j]; 
if (total_left==0) return 1; 
int64 state=0; 
for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (i+j>0) state=state*13+C[i][j];//state.push_back(C[i][j]);
state=state*2+side;//state.push_back(side); 
state=state*4+si;//state.push_back(si); 
state=state*4+sj;//state.push_back(sj); 
int address=(int)(state%1000003); 
TPoint *p; 
for (p=hash[address];p!=NULL;p=p->next) 
  if (p->state==state) 
    return p->result; 
p=&memory[memoryId++]; 
p->state=state; 
p->next=hash[address]; 
hash[address]=p; 
int64 &ret=p->result; 
for (int i=0;i<3;i++) for (int j=0;j<3;j++) if (i+j>0 && C[i][j]>0) 
{ 
  if (i>0 && (i==si && j==sj || side==0)) 
  { 
    int64 s=0; 
    if (side==0) s=C[i][j]*i; 
    else s=i; 
    C[i][j]--; 
    C[i-1][j]++; 
    ret=(ret+solve(C,0,i-1,j)*s)%MODE; 
    C[i-1][j]--; 
    C[i][j]++; 
  } 
  if (j>0 && (i==si && j==sj || side==1)) 
  { 
    int64 s=0; 
    if (side==1) s=C[i][j]*j; 
    else s=j; 
    C[i][j]--; 
    C[i][j-1]++; 
    ret=(ret+solve(C,1,i,j-1)*s)%MODE; 
    C[i][j-1]--; 
    C[i][j]++; 
  } 
} 
return ret; 
} 
int count(vector <string> cards) 
{ 
memoryId=0;
memset(hash,0,sizeof(hash)); 
memset(memory,0,sizeof(memory)); 
int C[3][3]; 
memset(C,0,sizeof(C)); 
int C1[256],C2[256]; 
memset(C1,0,sizeof(C1)); 
memset(C2,0,sizeof(C2)); 
for (int i=0;i<SIZE(cards);i++) 
{ 
  string s=cards[i]; 
  if (s[1]=='S' || s[1]=='C') 
    C2[(int)s[0]]++; 
  else 
    C1[(int)s[0]]++; 
} 
for (int i=0;i<256;i++) 
  C[C1[i]][C2[i]]++; 
M.clear(); 
int64 ret=0; 
for (int i=0;i<3;i++) 
  for (int j=0;j<3;j++) if (i+j>0 && C[i][j]>0) 
  { 
    if (i>0) 
    { 
      int64 s=C[i][j]*i; 
      C[i][j]--; 
      C[i-1][j]++; 
      ret=(ret+solve(C,0,i-1,j)*s)%MODE; 
      C[i-1][j]--; 
      C[i][j]++; 
    } 
    if (j>0) 
    { 
      int64 s=C[i][j]*j; 
      C[i][j]--; 
      C[i][j-1]++; 
      ret=(ret+solve(C,1,i,j-1)*s)%MODE; 
      C[i][j-1]--; 
      C[i][j]++; 
    } 
  } 
/* 
  printf("SUM  = %d\n",(int)sum); 
printf("RET  = %d\n",(int)ret); 
if (sum!=ret) 
  exit(0); 
*/ 
return (int)ret; 
} 


void main()
{
	int test;
	//freopen("c.dat", "r", stdin);
	cin >> test;
	for(int t = 0; t < test; ++t)
	{
		int n;
		cin >> n;
		vector <string> aux(n);
		for(int i = 0; i < n; ++i) cin >> aux[i];
		cout << count(aux) << endl;
	}
}