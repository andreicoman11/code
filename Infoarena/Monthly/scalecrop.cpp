#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

#define LL long long
#define FORit(it,x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define INFILE "scalecrop.in" 
#define OUTFILE "scalecrop.out"

int main()
{
   freopen(INFILE, "r", stdin);
   freopen(OUTFILE, "w", stdout);

   double hf, wf, hp, wp;

   cin >> wf >> hf >> wp >> hp;

   double k = max(wf/wp, hf/hp);
   cout << setprecision(15) << wp*k << " " << hp*k << endl;

   return 0;
}
