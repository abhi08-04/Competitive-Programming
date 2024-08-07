vector<int> isprime;

void SieveofEratosthenes(int N) {
    isprime.resize(N + 2, 1);
    for (int i = 2; i <= N + 1; i++) {
        if (isprime[i] && (long long) i * i <= N + 1) {
            for (int j = i * i; j <= N + 1; j += i) isprime[j] = 0;
        }
    }
    return;
}


// call as SieveofEratosthenes(N) before test case to precumpute all primes beforehand
