#include <stdio.h>
#include <string.h>

int e[500000][2], ee[500000][2];
int grad[100000], g[100000];
int maxg, maxn, m, n;
char was[100000];

void bin_s(int a, int b)
{
     int c = (a+b)/2;
     //printf("%d %d %d\n", a, b, c);
     was[c] = 1;
     memcpy(g, grad, sizeof(grad));
     memcpy(ee, e, sizeof(e));
     int go = 1, i;
     int m2 = m;
     while(go && m2>=0)
     {
          go = 0;
          for(i=0; i<m2; i++)
                  if( g[ee[i][0]]<c || g[ee[i][1]]<c )
                  {
                      //printf("%d - %d, %d + %d\n", ee[i][0], ee[i][1], g[ee[i][0]], g[ee[i][1]]);
                      g[ee[i][0]]--;
                      g[ee[i][1]]--;
                      ee[i][0] = ee[m2-1][0];
                      ee[i][1] = ee[m2-1][1];
                      i--;
                      m2--;
                      go = 1;
                  }
     }
     
     int newn = 0;
     if( m2 )
         for(i=1; i<=n; i++)
             if(g[i]>=c ) newn++;

     if( newn )
     {
         maxg = c;
         maxn = newn;
         if( c<b-1 ) bin_s(c,b);
         if( !was[b] && b<n ) bin_s(b,b+1);
     }
     else
     {
         if( a+1<c ) bin_s(a,c);
     }
}


int main()
{
    FILE* fin = fopen("gminmax.in", "r");
    FILE* fout = fopen("gminmax.out", "w");

    int i;
    fscanf(fin, "%d %d", &n, &m);

    memset( grad, 0, sizeof(grad));
    for(i=0; i<m; i++)
    {
       fscanf(fin, "%d %d", &e[i][0], &e[i][1]);
       grad[e[i][0]]++;
       grad[e[i][1]]++;
    }
    memset(was, 0, sizeof(was));
    bin_s(0, n);
    fprintf(fout, "%d %d\n", maxg, maxn);
       
    fclose(fin);
    fclose(fout);
    //system("pause");
    return 0;
}
