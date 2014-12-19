#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ofstream fout ("A.out");
    ifstream fin  ("A.dat");

    int testnr;
    fin >> testnr;
    
    while( testnr )
    {
        testnr--;
        unsigned long len=0;
        int N;
        fin >> len >> N;
        len *= 100;
        
        unsigned int left[100000]={0}, right[100000]={0}, n=0, m=0, nc=0, mc=0;   
        
        for(int i=0; i<N; i++)
        {
            int a;
            string tmp;
            fin >> a >> tmp;
            
            if( tmp=="left" ) { left[n]=a; n++; }
            else { right[m]=a; m++; }
        }
        
        
        int cur=0; // 0-left, 1-right
        int nr=0; // nr of crossings
        
        while( nc<n || mc<m )
        {
            //cout << nr <<  " " << cur << " " << nc << " " << mc << "\n";
            //system("pause");
            if( cur==0 )
            {
                if( nc<n )
                {
                    int L=left[nc];
                    while( L <= len && nc<=n ) { nc++; L += left[nc]; }
                    cur=1;
                    nr++;
                }
                else
                {
                    if( mc<m )
                    {
                        nr++;
                        cur=1;
                    }
                }
            }
            else
            {
                if( mc<m )
                {
                    int L=right[mc];
                    while( L <= len && mc<=m ) { mc++; L += right[mc]; }
                    cur=0;
                    nr++;
                }
                else
                {
                    if( nc<n )
                    {
                        nr++;
                        cur=0;
                    }
                }
            }
        }
        
        fout << nr << "\n";
        
    }


//system("pause");
 return 0;
}
