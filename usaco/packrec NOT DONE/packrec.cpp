/*
ID: andreic4
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    
    int rec[4][2];    
    
    fin >> rec[0][0] >> rec[0][1];
    fin >> rec[1][0] >> rec[1][1];
    fin >> rec[2][0] >> rec[2][1];
    fin >> rec[3][0] >> rec[3][1];
    
    
    
    return 0;
}
