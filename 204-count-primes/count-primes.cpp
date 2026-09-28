class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = isPrime[1] = false;

        int count = n / 2;  // initially count odd numbers

        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    if (isPrime[j]) {
                        isPrime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};