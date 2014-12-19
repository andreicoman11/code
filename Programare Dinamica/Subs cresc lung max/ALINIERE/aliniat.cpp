#include <fstream>
using namespace std;

float a[1000];
int l[1000],r[1000],n,tl[1000],tr[1000],rezi,rezj;

void cit();
void afis();
void aliniat();
void maxim();

int main()
{
    cit();
    aliniat();
    maxim();
    afis();
    
    return 0;
}

void cit()
{
     ifstream f("aliniat.in");
     f>>n;
     for(int i=1; i<=n; i++)
             f>>a[i];
     f.close();
}

void afis()
{
     ofstream f("aliniat.out");
     
     for(int i=1; i<=n; i++)
             f<<l[i]<<" ";
     f<<endl;
     
     for(int i=1; i<=n; i++)
             f<<r[i]<<" ";
     f<<endl;
     f<< rezi << " " << rezj << endl;
     if(rezi==rezj) f<< n - l[rezi] - r[rezj]+1 << endl;
     else f<< n - l[rezi] - r[rezj]<< endl;
     
     for(int i=1; i<=rezi; i++) if( tl[i] != -1 ) f<<i<<" ";
     for(int i=rezj; i<=n; i++) if( tr[i] != -1 ) f<<i<<" ";
     
     
     f.close();

}

void aliniat()
{
     for(int i=1; i<=n; i++) {l[i]=0; r[i]=0; }
     l[1]=1;
     r[n]=1;
          
     for(int i=2; i<=n; i++ )
     {
             for(int j=1; j<i; j++)
                     if( a[j] < a[i] && l[i]<l[j]+1)   
                         {
                              l[i] = l[j]+1;
                              tl[i] = j;     
                         }
     }
     
     for(int i=n-1; i; i-- )
     {
             for(int j=n; j>i; j--)
                     if( a[j] < a[i] && r[i]<r[j]+1)   
                         {
                              r[i] = r[j]+1;
                              tr[i] = j;
                         }
     }
}

void maxim()
{
     int max=2,imax;
     for(int i=1;i<=n;i++)     
             {
                               imax = i;
                               for(int j=i+1;j<=n;j++)
                                        if( r[j] >= r[i] ) imax=j;
                               if( l[i]+r[imax] > max ) { rezi = i;
                                                          rezj = imax;
                                                          max = l[i]+r[imax];
                                                        }
             }
     int i = rezi,j;
     while( tl[i] )                                     
           {
                  j = i;
                  i = tl[i];
                  tl[j] = -1;
           }
     tl[i] = -1;

     i = rezj;
     while( tr[i] )                                     
           {
                  j = i;
                  i = tr[i];
                  tr[j] = -1;
           }
     tr[i] = -1;
}    



