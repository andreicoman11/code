#include <fstream>
using namespace std;
int a[1000],l[1000],n,t[1000];

void cit();
void afis(int);
void subsir();

int main()
{
    cit();
    subsir();

}

void cit()
{
     ifstream f("subsircresc.in");
     f>>n;
     for(int i=1;i<=n;i++)
             f>>a[i];
     f.close();
}

void subsir()
{
     for(int i=1;i<=n;i++) l[i]=0;
     int lmax=1;
     
     l[1]=1;
     for(int i=2; i<=n; i++)
     {
             for(int j=i-1; j; j-- )
                  if( a[j]<a[i] && l[i]<l[j]+1 ) { 
                                                    l[i] = l[j]+1 ;
                                                    t[i] = j ;
                                                    if( lmax<j ) lmax=j;
                                                 }
     }
     
     afis( lmax );
}

void afis( int lmax )
{
     ofstream f("subsircresc.out");
     
     for(int i=1; i<=n; i++)
             f<<a[i]<<" ";
     f<<endl;
     
     for(int i=1; i<=n; i++)
             f<<l[i]<<" ";
     f<<endl;
     
     for(int i=1; i<=n; i++)
             f<<t[i]<<" ";
             
     f<< endl;
     f<< lmax;
     f.close();
}
