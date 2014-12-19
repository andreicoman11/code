#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
ifstream fin ("C-large-practice.in");
ofstream fout (".out");
const int MOD = 10000;

int main()
{
  string gcj = "welcome to code jam";
  int runs;
	fin >> runs;
  char buf[512];
  fin.getline(buf, 512);
	for(int r = 1; r<=runs; r++)
	{
    fin.getline(buf, 512);
    string s = buf;

    int occ[2][512] = {0};
    int cur = 0, maxocc = 0;

    for(int j=0; j<s.size(); j++)
        {
          occ[cur][j] = (j > 0 ? occ[cur][j-1] : 0) + (gcj[0] == s[j] ? 1 : 0);
        }

    for(int i=1; i<gcj.size(); i++)
    {
      cur = 1-cur;
      for(int j=0; j<s.size(); j++)
        {
          occ[cur][j] = (j>0 ? occ[cur][j-1] : 0) + 
              (gcj[i] == s[j] ? (j > 0 ? occ[1-cur][j-1] : 0) : 0);
          occ[cur][j] = (occ[cur][j]) % MOD;
        }
    }
    maxocc = occ[cur][s.size()-1];
	
		fout << "Case #" << r << ": ";
    if( maxocc<10 ) fout << "000";
    else if( maxocc<100 ) fout << "00";
    else if( maxocc<1000 ) fout << "0";
    fout << maxocc << endl;
	}

  return 0;
}
