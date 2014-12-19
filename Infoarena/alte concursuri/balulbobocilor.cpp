#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

#define LL long long
#define INFILE "balulbobocilor.in" 
#define OUTFILE "balulbobocilor.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

int main() {
   int d;
   int v1, v2, v3, aux;
   fin >> d;
   fin >> v1 >> aux >> aux;
   fin >> v2 >> aux >> aux;
   fin >> v3;

   fout << std::fixed << setprecision(6) << (double(d) / double(v1+v2)) * double(v3);

   return 0;
}
