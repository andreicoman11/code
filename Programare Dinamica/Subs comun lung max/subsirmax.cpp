#include <fstream>
#include <iostream>
using namespace std;

string a,b;
int x[2][100], rs=0, rd=1;

void citire();
void afis();
void subsirmax();

int main()
{
    citire();
    subsirmax();
    afis();
    system("pause");
    return 0;    
}

void subsirmax()
{
 for(int i=0; i< a.size(); i++) x[rs][i]=0;
 
 for(int k=0; k< b.size(); k++, rs = rd, rd = (rs+1)%2, x[rd][0]=0, x[rs][0]=0 )
 for(int i=0; i< a.size(); i++ ) 
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
     ifstream f("subsirmax.in");
     f>>a;
     f>>b;    
     f.close();     
}

void afis()
{
     cout<<x[rs][a.size()];
     cout<<endl;
}





