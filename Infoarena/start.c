#include <stdio.h>

int main()
{
    FILE* fin = fopen(".in", "r");
    FILE* fout = fopen(".out", "w");


    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;
}
