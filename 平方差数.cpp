#include <stdio.h>


int main() {
    int T;
    scanf("%d", &T);
	 
    while (T--) {
        long long k;
        scanf("%lld", &k);

        long long a;
        if (k == 1) {
            a = 3;
        } else {
            // k > 1 时， [5, 7, 8], [9, 11, 12], ...
            // 中的第 (k-1) 个数。
            long long k_prime = k - 1;
            long long q = (k_prime - 1) / 3;
            long long r = (k_prime - 1) % 3;

            if (r == 0) {
                // 组里的第1个数 
                a = 4 * q + 5;
            } else if (r == 1) {
                // 2 
                a = 4 * q + 7;
            } else { 
                // 3 
                a = 4 * q + 8;
            }
        }
        printf("%lld\n", a);
    }

    return 0;
}
