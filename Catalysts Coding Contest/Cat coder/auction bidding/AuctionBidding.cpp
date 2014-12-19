#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

#define LL long long
#define INFILE ".in" 
#define OUTFILE ".out"
#define INF 10000000
ifstream fin(INFILE);
ofstream fout(OUTFILE);

char buf[512];

struct bid{
   string bidder;
   int actual_bid;
   int max_bid;
   int buy_now;
};

int main() {

   while( fin.getline(buf, 512) ) {
      string str = buf;
      istringstream in(buf);

      bid b;
      in >> b.max_bid >> b.buy_now >> b.bidder >> b.actual_bid;
      if( b.buy_now==0 ) b.buy_now = INF;
      fout << "-," << b.max_bid << "," << b.bidder << "," << b.max_bid;
      string bidder;
      int price;
      while( in >> bidder >> price ) {
         if( price > b.actual_bid ) {
            if( b.bidder == bidder ) {
               b.actual_bid = price;
            } else {
               b.bidder = bidder;
               b.max_bid = b.actual_bid + 1;
               b.actual_bid = price;
               fout << "," << b.bidder << ",";
               if( b.max_bid>=b.buy_now ) {
                  fout << b.buy_now;
                  break;
               }
               fout << b.max_bid;
            }
         } else if(price >= b.max_bid ) {
            b.max_bid = min(price + 1, b.actual_bid);
            fout << "," << b.bidder << ",";
            if( b.max_bid>=b.buy_now ) {
               fout << b.buy_now;
               break;
            }
            fout << b.max_bid;
         }
      }
      fout << endl;
   }

   return 0;
}
