// PD liniara metoda INAINTE
// Problema agricultorului
// sa se taie un nr minim de tulpini de porumb, stiind ca dist minima intre 2 tulpini este
// x, si ca prima tulpina NU se taie
#include <fstream.h>

const int DIM = 1000;

ifstream fin  ("file.in");
ofstream fout ("file.out");

int a[DIM];
int L[DIM];   // L[i] - lung cmlsc care se "incepe" pe poz i (e in draeapta poz i) si contine elem a[i]
int t[DIM];   // sirul predecesorilor( t[i] = j - in sc in dreapta lui a[i] este a[j] )
int n;
int x;
int s[DIM];

void Read ();
void SCLM ();
void Write ();
void Write (int i);

int main ()
{
    Read ();
    SCLM ();
    Write ();
    
    fin.close();
    fout.close();
    return 0;
}    

void Read ()
{
    fin >> n >> x;
  
    for (int i = 1; i <= n; i++)
        fin >> a[i];
}

void SCLM ()
{
    for (int i = n; i >= 1; i-- )
    {
        L[i] = 1;
        t[i] = 0;
        for (int j = i + 1; j <= n; j++)
            if (L[i] < L[j] + 1 && a[j] - a[i] >= x)
            {
                L[i] = L[j] + 1;
                t[i] = j;
            }
     } 
 }           

void Write(int i)
{
    for (int j = i; j <= n && j; j = t[j])
        s[j]  = 1;
        
    for (int j = 1; j <= n; j++)
        if (!s[j])
            fout << a[j] << " ";
    fout << "\n";
}    

 void Write ()
 {           
    fout << n - L[1] << "\n";
    Write (1);
}


