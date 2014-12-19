int memo[40][10];

main() {
    int n;
    int i;
    memo[0][0] = 1;

    for( i = 1; i < 32; i++ ) {
        memo[i][0] = memo[i-1][1] + memo[i-1][4] + memo[i-1][7];
        memo[i][1] = memo[i-1][0] + memo[i-1][6];
        memo[i][2] = memo[i-1][5];
        memo[i][3] = memo[i-1][4];
        memo[i][4] = memo[i-1][0] + memo[i-1][3];
        memo[i][5] = memo[i-1][2];
        memo[i][6] = memo[i-1][1];
        memo[i][7] = memo[i-1][0];
    }
    while(1 == scanf("%d", &n)) {
        printf("%d\n", memo[n][0]);
    }
}
