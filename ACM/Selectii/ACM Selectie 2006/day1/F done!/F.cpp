#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ofstream  fout ("F.out");
    ifstream  fin  ("F.dat");
    
    int n, rlen;
    while( fin >> n >> rlen )
    {
        int rmax, qmax=-1, qmin=10001, p=1;
        bool remove[10001]={0};
        int q[10001] = {0};
        
        for(int i=0; i<rlen; i++)
        {
            int tmp;
            fin >> tmp;
            remove[ tmp] = 1;
            rmax = max( rmax, tmp);
        }
        
        int r = 0, curr=0;
        char x;
        fin >> x;
        
        while( x!='e' && r<=rmax )
        {
            if( x=='r' )
            {
                r++;
                    if( p==2 )
                    {
                        if( qmax>=0 )
                        {
                            if( remove[r] ) fout << qmax << "\n";
                            q[ qmax ]--;
                            if( qmax==qmin ) while( q[ qmin ]==0 && qmin<=10000 ) qmin++;
                            while( q[ qmax ]==0 && qmax>=0 ) qmax--;
                        }
                        else fout << "-1\n";
                    }
                    else if( p==1 )
                    {
                        if( qmin<=10000 )
                        {
                            if( remove[r] ) fout << qmin << "\n";
                            q[ qmin ]--;
                            if( qmax==qmin ) while( q[ qmax ]==0 && qmax>=0 ) qmax--;
                            while( q[ qmin ]==0 && qmin<=10000 ) qmin++;
                        }
                        else fout << "-1\n";
                    }
            }
            else if( x=='a' )            
            {
                int tmp;
                fin >> tmp;
                q[ tmp ]++;
                if( tmp>qmax ) qmax = tmp;
                if( qmin>tmp ) qmin = tmp;
                
            }
            else if( x=='p' )
            {
                int tmp;
                fin >> tmp;
                p = tmp;
            }
            
            fin >> x;
        }
        fout << "\n";
    }





 return 0;
}
