/*
ID: andreic4
PROG: picture
LANG: C++
*/
#include    <stdio.h>
#include    <stdlib.h>
#include    <memory.h>

#define START   (1)
#define FINISH  (-1)

typedef struct
{
    int x1, x2;
    int y;
    int flag;
}   LINE;

int P;
LINE    vertical[10000];
LINE    horizontal[10000];

int L;

void Read(void) {
    FILE    *in;
    int p;
    int x1, x2, y1, y2;

    in = fopen("picture.in", "r");
    fscanf(in, "%d ", &P);
    for (p=0; p<P; p++) {
        fscanf(in, "%d %d %d %d ", &x1, &y1, &x2, &y2);
        
        horizontal[p*2].y = y1;
        horizontal[p*2].x1 = x1;
        horizontal[p*2].x2 = x2;
        horizontal[p*2].flag = START;
        
        horizontal[p*2 + 1].y = y2;
        horizontal[p*2 + 1].x1 = x1;
        horizontal[p*2 + 1].x2 = x2;
        horizontal[p*2 + 1].flag = FINISH;
        
        vertical[p*2].y = x1;
        vertical[p*2].x1 = y1;
        vertical[p*2].x2 = y2;
        vertical[p*2].flag = START;
        
        vertical[p*2 + 1].y = x2;
        vertical[p*2 + 1].x1 = y1;
        vertical[p*2 + 1].x2 = y2;
        vertical[p*2 + 1].flag = FINISH;
    }

    P *= 2;
    fclose(in);
}

int compare(const void *a, const void *b) {
    LINE    la;
    LINE    lb;
    la = *((LINE *)a);
    lb = *((LINE *)b);
    return la.y - lb.y;
}

int Perimeter(LINE *line) {
    int grid[2][20001];
    int l, x, y, g;
    int p = 0;
        
    memset(grid, 0, sizeof(int) * 2 *  20001);
    
    l = 0;
    while (l<P) {
        y = line[l].y;
        memcpy(grid[0], grid[1], sizeof(int) * 20001);
        
        while (line[l].y == y) {
            for (x=line[l].x1 + 10000; x < line[l].x2+10000; x++)
                grid[1][x] += line[l].flag;
            l++;
            if (l==P)   break;
        }
                    
        for (x=0; x<=20000; x++) {
            if ((grid[0][x]==0) && (grid[1][x]>0))  p++;
            if ((grid[1][x]==0) && (grid[0][x]>0))  p++;
        }
    }
    return p;
}

void Compute(void) {
    qsort(horizontal, P, sizeof(LINE), compare);
    qsort(vertical, P, sizeof(LINE), compare);
    L = Perimeter(horizontal) + Perimeter(vertical);
}

void Write(void) {
    FILE    *out;
    out = fopen("picture.out", "w");
    fprintf(out, "%d\n", L);
    fclose(out);
}

int main(void) {
    Read();
    Compute();
    Write();
    return 0;
}