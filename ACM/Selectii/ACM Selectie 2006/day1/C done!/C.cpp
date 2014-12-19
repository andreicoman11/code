#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("C.DAT");
    ofstream fout("C.OUT");
    
    int m;
    fin >> m;
    
    while(m)
    {
        m--;
        
        int n;
        fin >> n;
        
        if( n<=3 )
        {
            if( n==1 ) fout << "0\n";
            else if( n==2 ) fout << "0\n";
            else if( n==3 ) fout << "1\n";
        }
        else
        {
        
            int k = (n-1)/2 - 1;
            int p = (n/2) - 1;
            
            int s = k+1 + (k*(k+1))/2 + p*(p+1)/2;
            fout << s <<"\n";   
        }        
    }





 return 0;
}
