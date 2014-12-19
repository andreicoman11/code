/*
ID: andreic4
PROG: rect1
LANG: C
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXCOORD 10000
#define MAXN 1000

typedef struct tagLinesTree
{
    int i, j, color;
    struct tagLinesTree *leftchild;
    struct tagLinesTree *rightchild;
} LinesTree;

typedef struct tagMatrix
{
    int llx, lly, urx, ury, color;
} Matrix;

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void release_tree(LinesTree *t)
{
    if (t)
    {
        release_tree(t->leftchild);
        release_tree(t->rightchild);
        free(t);
    }
}

void count_color(const int coord[], int color[], const int y_len, LinesTree *t)
{
    if (t)
    {
        if (t->color > 0)
            color[t->color - 1] += y_len * (coord[t->j] - coord[t->i]);
        else
        {
            count_color(coord, color, y_len, t->leftchild);
            count_color(coord, color, y_len, t->rightchild);
        }
    }
}

void reset_tree(LinesTree *t)
{
    if (t)
    {
        reset_tree(t->leftchild);
        reset_tree(t->rightchild);
        t->color = 0;
    }
}

void delete_duplicate(const int coord_src[], int *coord_len, int coord_dest[])
{
    int i, len, count;

    len = *coord_len;
    coord_dest[0] = coord_src[0];
    count = 0;
    for (i = 1; i < len; ++i)
    {
        if (coord_dest[count] != coord_src[i])
            coord_dest[++count] = coord_src[i];
        else
            --(*coord_len);
    }
}

void build_tree(const int l, const int r, LinesTree *t)
{
    int k;

    t->i = l;
    t->j = r;
    t->color = 0;

    if (r - l > 1)
    {
        k = l + r;
        t->leftchild = (LinesTree *)malloc(sizeof(LinesTree));
        build_tree(l, k / 2, t->leftchild);
        t->rightchild = (LinesTree *)malloc(sizeof(LinesTree));
        build_tree(k / 2, r, t->rightchild);
    }
    else
    {
        t->leftchild = NULL;
        t->rightchild = NULL;
    }
}

void insert_tree(const int l, const int r, const int color, const int coord[], LinesTree *t)
{
    if (l <= coord[t->i] && coord[t->j] <= r)
        t->color = color;
    else
    {
        if (t->color > 0)
        {
            t->leftchild->color = t->color;
            t->rightchild->color = t->color;
            t->color = 0;
        }
        if (l < coord[(t->i + t->j) / 2])
            insert_tree(l, r, color, coord, t->leftchild);
        if (r > coord[(t->i + t->j) / 2])
            insert_tree(l, r, color, coord, t->rightchild);
    }
}

int main()
{
    FILE *fp_in;
    FILE *fp_out;
    int a, b, n, i, j;
    int x_coord0[MAXCOORD], y_coord0[MAXCOORD];
    int x_coord[MAXCOORD], y_coord[MAXCOORD];
    int x_coord_idx = 0, y_coord_idx = 0;
    LinesTree *root;
    Matrix m[MAXN];
    int color[MAXN] = { 0 };

    fp_in = fopen("rect1.in", "r");
    if (NULL == fp_in)
        return EXIT_FAILURE;

    fp_out = fopen("rect1.out", "w");
    if (NULL == fp_out)
        return EXIT_FAILURE;

    fscanf(fp_in, "%d %d %d\n", &a, &b, &n);

    for (i = 0; i < n; ++i)
    {
        fscanf(
            fp_in,
            "%d %d %d %d %d\n",
            &m[i].llx, &m[i].lly, &m[i].urx, &m[i].ury, &m[i].color
        );

        x_coord0[x_coord_idx++] = m[i].llx;
        y_coord0[y_coord_idx++] = m[i].lly;
        x_coord0[x_coord_idx++] = m[i].urx;
        y_coord0[y_coord_idx++] = m[i].ury;
    }

    qsort(x_coord0, x_coord_idx, sizeof(x_coord0[0]), compare);
    qsort(y_coord0, y_coord_idx, sizeof(y_coord0[0]), compare);

    delete_duplicate(x_coord0, &x_coord_idx, x_coord);
    delete_duplicate(y_coord0, &y_coord_idx, y_coord);

    root = (LinesTree *)malloc(sizeof(LinesTree));
    build_tree(0, x_coord_idx - 1, root);

    for (i = 0; i < y_coord_idx - 1; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (m[j].lly <= y_coord[i] && y_coord[i + 1] <= m[j].ury)
            {
                insert_tree(m[j].llx, m[j].urx, m[j].color, x_coord, root);
            }
        }
        count_color(x_coord, color, y_coord[i + 1] - y_coord[i], root);
        reset_tree(root);
    }

    release_tree(root);

    // color 1
    color[0] = 0;
    for (i = 1; i < MAXN; ++i)
    {
        color[0] += color[i];   // other colors
    }
    color[0] = a * b - color[0];// total colors - other colors = color 1

    for (i = 0; i < MAXN; ++i)
    {
        if (color[i])
            fprintf(fp_out, "%d %d\n", i + 1, color[i]);
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
