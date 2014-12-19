#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#define INFILE "paginatie.in" 
#define OUTFILE "paginatie.out"

vector<string> vs;

int main()
{
   FILE* fin = fopen(INFILE, "r");
   freopen(OUTFILE, "w", stdout);
   
   int cuv, l, lin, x, y, len;
   fscanf(fin, "%d %d", &x, &y);

   char buf[64];
   fgets(buf, 64, fin);
   fgets(buf, 64, fin);
   l = strlen(buf)-1;
   if( buf[l]=='\n' ) buf[l] = '\0';
   else len++;
   cuv = 1;
   lin = 0;
   vs.push_back(buf);

   while( !feof(fin) )
   {
      if( lin==x )
      {
         lin = 0;
         printf("\n");
      }
      buf[0] = '\0';
      fgets(buf, 64, fin);
      if( strlen(buf)<1 ) break;
      len = strlen(buf) - 1;
      if( buf[len]=='\n' ) buf[len] = '\0';
      else len++;
      if( l+len+cuv<=y )
      {
         l += len;
         vs.push_back(buf);
         cuv++;
      }
      else
      {
         printf("%s", vs[0].c_str());
         cuv--;
         int spaces = y - l;
         for(int i=1; i<=cuv; i++)
         {
            for(int j=0; j<spaces/cuv + (int)(spaces%cuv>i-1); j++)
               printf(" ");
            printf("%s", vs[i].c_str());
         }
         printf("\n");
         lin++;
         vs.clear();
         l = len;
         vs.push_back(buf);
         cuv = 1;
      }
   }

   if( lin==x )
   {
      lin = 0;
      printf("\n");
   }
   printf("%s", vs[0].c_str());
   cuv--;
   int spaces = y - l;
   for(int i=1; i<=cuv; i++)
   {
      for(int j=0; j<spaces/cuv + (int)(spaces%cuv>i-1); j++)
         printf(" ");
      printf("%s", vs[i].c_str());
   }
   


   return 0;
}
