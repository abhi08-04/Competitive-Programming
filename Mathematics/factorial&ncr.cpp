vector<int> fact, invfact;
void factorial(int N) {
    fact.resize(N + 2, 1); invfact.resize(N + 2, 1);
    for (int i = 2; i <= N; i++) fact[i] = fact[i - 1] * i % mod;
    invfact[N] = expo(fact[N], mod - 2, mod);
    for (int i = N - 1; i > 1; i--) invfact[i] = invfact[i + 1] * (i + 1) % mod;
    return;
}

int ncr(int n, int r) {
    if (n < r) return 0;
    return fact[n] * invfact[r] % mod * invfact[n - r] % mod;
}


// call as factorial(N); int he main function before the test cases to precompute all values as use directly for all test cases
