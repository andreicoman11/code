#include <stdio.h>

int isprime(long long p) {
    long long i;
    for(i = 2; i*i <= p; i++) {
        if(p%i == 0) return 0;
    }
    return 1;
}
int main() {
    while(1) {
        long long p, a, ap, pp, aa;

        scanf("%lld %lld", &p, &a);
        if(p == 0) break;
        if(isprime(p)) {
            puts("no");
            continue;
        }
        ap = 1;
        pp = p;
        aa = a;
        while(pp) {
            if(pp&1) ap*= aa;
            ap %= p;
            aa = (aa*aa)%p;
            pp >>= 1;
        }
        //printf("%lld %lld\n", ap%p, a);
        if(ap%p == a) puts("yes"); else puts("no");
    }
}
