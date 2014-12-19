#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#define LL long long
#define INFILE "ceas2.in" 
#define OUTFILE "ceas2.out"

ifstream fin(INFILE);
ofstream fout(OUTFILE);

string str1, str2;
int v[32];

int getv(char c)
{
   return c - int('a');
}

char getc(int c)
{
   return char(c + int('a'));
}

int main() {
   getline(fin, str1);
   getline(fin, str2);
   
   for(int i=0; i<32; i++)
      v[i] = -1;

   for(int i=0; i<str1.size(); i++)
   {
      int a = getv(str1[i]);
      int b = getv(str2[i]);

      if( v[a]==-1 ) v[a] = b;
      else if( v[a]!=b ) {
         fout << "NU";
         return 0;
      }
   }

   fout << "DA\n";
   for(int i=0; i<26; i++)
      if( v[i]!=i && v[i]!=-1 )
         fout << getc(i) << " " << getc(v[i]) << "\n";

   return 0;
}
