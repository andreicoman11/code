#include <stdio.h>

struct point {
    int x;
    int y;
    int v;
    int h;
};
struct point p[110000];

struct point *pv[110000];
struct point *ph[110000];
int pts;

int comp1(const struct point** p1, const struct point** p2) {
    if((*p1)->x != (*p2)->x) return (*p1)->x - (*p2)->x;
    return (*p1)->y - (*p2)->y;
}
int comp2(const struct point** p1, const struct point** p2) {
    if((*p1)->y != (*p2)->y) return (*p1)->y - (*p2)->y;
    return (*p1)->x - (*p2)->x;
}
int findv(struct point* pp) {
    struct point** ret = bsearch(&pp, pv, pts, sizeof(pv[0]), comp1);
    //printf("%p\n", ret);
    return ret - pv;
}
int findh(struct point* pp) {
    struct point** ret = bsearch(&pp, ph, pts, sizeof(ph[0]), comp2);
    //printf("%p\n", ret);
    return ret - ph;
}

main() {
    int cases;
    int i;
    int x;
    int y;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &pts);
        for(i = 0; i < pts; i++) {
            scanf("%d %d", &x, &y);
            p[i].x = x;
            p[i].y = y;
            pv[i] = &p[i];
            ph[i] = &p[i];
        }
        qsort(pv, pts, sizeof(pv[0]), comp1);
        qsort(ph, pts, sizeof(ph[0]), comp2);
        if(pts % 2) goto impossible;
        for(i = 0; i < pts; i+=2) {
            pv[i]->v = 1;
            pv[i+1]->v = -1;
            if(pv[i]->x != pv[i+1]->x) goto impossible;
            ph[i]->h = 1;
            ph[i+1]->h = -1;
            if(ph[i]->y != ph[i+1]->y) goto impossible;
        }
        int j = 0;
        int len = 0;
        for(i = 0; i < pts; i+=2) {
            //printf("%d %d\n", p[j].x, p[j].y);
            int h = findh(p+j);
            int oldh = h;
            if(p[j].h == 1) h++; else h--;
            len += abs(ph[h]->x- ph[oldh]->x);
            //printf("%d\n", abs(ph[h]->x- ph[oldh]->x));
            j = ph[h] - p;
            //printf("%d %d\n", p[j].x, p[j].y);
            int v = findv(p+j);
            int oldv = v;
            if(p[j].v == 1) v++; else v--;
            len += abs(pv[v]->y- pv[oldv]->y);
            //printf("%d\n", abs(pv[v]->y- pv[oldv]->y));
            j = pv[v] - p;
            if(j == 0 && i != pts-2) goto impossible;
        }
        printf("%d\n", len);
        continue;
impossible:
        printf("-1\n");
    }
}
