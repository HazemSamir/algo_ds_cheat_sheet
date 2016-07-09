int ST[20][1 << 20];
int lg2[1 << 20];

inline int foo(int a, int b) {
    // what ever associative function
}

void build(int n) {
    for (int j = 1; (1 << j) < n; ++j)
        for(int i = 0; i + (1 << j) - 1 < n; ++i)
            ST[j][i] = foo(ST[j-1][i], ST[j-1][i + (1 << (j-1))]);
    
    // init lg2 array
    for(int i=2; i <= n; ++i)
        lg2[i] = lg[i >> 1] + 1;
}

int query(int l, int r) {
    int lg = lg2[r - l + 1];
    return foo(ST[lg][l], ST[lg][r - (1 << lg) + 1]);
}
