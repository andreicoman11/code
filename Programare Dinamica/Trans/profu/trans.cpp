#include <fstream>
#ifndef __BORLANDC__
#define huge
#endif
using namespace std;

int huge D[105][105];
int i, j, m, n;
char A[105], B[105];
int ic = 1, ip = 0;   // linia curenta, linia precedenta

int Min(int a, int b, int c)
{
    int m = 32000;
    if (a < m) m = a;
    
    if (b < m) m = b;
               
    if (c < m) m = c;
    
    return m;
}    


void Lowenstein()
{

    for (j = 0; j <= n; j++)   
        D[0][j] = j;
        
    ic = 1, ip = 0;   // linia curenta, linia precedenta
    for (i = 1; i <= m; ic = !ic, ip = !ip, i++)
        for (j = 1, D[ic][0] = i; j <= n; j++)
           if (A[i-1] == B[j-1]) 
                D[ic][j] = D[ip][j-1];
           else 
                D[ic][j] = Min(D[ip][j], D[ic][j-1], D[ip][j-1]) + 1;
}

void Read()
{
    ifstream fin("6.in");
    
    fin >> A >> B;
    
    m = strlen(A);
    n = strlen(B);
    
    fin.close();
}    

void Write()
{
    ofstream fout("trans.out");
    
    fout << D[ip][n] << "\n";
    
    fout.close();
}


int main()
{
    Read();
    Lowenstein();
    Write();
    
    return 0;
}    

    
    
    
               
      
          
                
    
