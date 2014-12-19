#include <fstream>
#include <iostream>
using namespace std;

char a[5050],b[5050];
int x[2][100], rs=0, rd=1, n;

void citire();
void afis();
void subsirmax();

int main()
{
    citire();
    subsirmax();
    afis();
    return 0;    
}

void subsirmax()
{
 for(int i=0; i< n; i++) x[rs][i]=0;
 
 for(int k=0; k< n; k++, rs = rd, rd = (rs+1)%2, x[rd][0]=0, x[rs][0]=0 )
 for(int i=0; i< n; i++ ) 
         {
              if( b[k]==a[i] )  x[rd][i+1] = x[rs][i]+1 ; 
              else { x[rd][i+1] = x[rd][i];
                     if( x[rd][i+1] < x[rs][i+1] ) x[rd][i+1]=x[rs][i+1];
                     }  
              //cout<<i<<" "<<k<<" "<<x[rd][i+1]<<endl;               
         } 
}

void citire()
{
     ifstream f("palin.in");
     f>>n;
     for(int i=0; i<n; i++)   f>>a[i]; 
     for(int i=0; i<n; i++)   b[n-i-1] = a[i];
     f.close();     
}

void afis()
{
     ofstream f("palin.out");
     f<<n-x[rs][n];
     f.close();
}





