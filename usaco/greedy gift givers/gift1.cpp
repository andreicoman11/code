/*
ID: andreic4
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    char names[10][15];
    int np;
    int v[10] = {0};
    
    fin >> np;
    
    for(int i=0; i<np; i++)
            fin >> names[i];
            
    for( int i=0; i<np; i++)
    {
         int cur;
         char c[15];
         fin >> c;
         for(int j=0; j<np; j++)
                 if( strcmp(c,names[j])==0 ) cur=j;
         
         int gift,nr;
         
         fin >> gift >> nr;
         v[cur] += gift;
         //cout << names[cur] << " += " << gift << " " << v[cur] << "\n";
         
         for(int j=0; j<nr; j++)
         {
            char name[15];
            fin >> name;
            for(int k=0; k<np; k++)
            {
                
                if( strcmp(name,names[k])==0 )
                {
                    int give = gift/nr;
                    v[cur] -= give;
                    v[k] += give;
                    //cout << names[cur] << " -= " << give << " =+ " << names[k] << " " << v[k] << "\n";
                }
            }
        }
        v[cur] -= gift;
                 
    }
    
    for( int i=0; i<np; i++)
        fout << names[i] << " " << v[i] << "\n";
    
    
    return 0;
}
