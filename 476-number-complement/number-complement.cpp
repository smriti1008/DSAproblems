class Solution {
public:
    int findComplement(int num) {
        if (num == 0)
            return 1;

        long long ans = 0, mul = 1;

        while (num) {
            int rem = num % 2;
            rem ^= 1;
            ans += rem * mul;
            mul *= 2;
            num /= 2;
        }

        return (int)ans;
    }
};