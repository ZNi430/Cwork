#include <stdio.h>

int main() {
    long long fib_nums[50]; 

    fib_nums[1] = 1;
    fib_nums[2] = 2;
    int max_fib_idx = 2;
    for (int i = 3; i < 50; i++) {
        fib_nums[i] = fib_nums[i - 1] + fib_nums[i - 2];
        if (fib_nums[i] > 1000000000L) { 
            max_fib_idx = i;
            break;
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int tag = 0;

        for (int i = 1; i <= max_fib_idx; i++) {
            if (fib_nums[i] > n) break; 

            for (int j = i; j <= max_fib_idx; j++) { 
                if (fib_nums[i] + fib_nums[j] > n) break; 

                for (int k = j; k <= max_fib_idx; k++) { 
                    if (fib_nums[i] + fib_nums[j] + fib_nums[k] > n) break; // ”≈ªØ

                    if (fib_nums[i] + fib_nums[j] + fib_nums[k] == n) {
                        tag++;
                    }
                }
            }
        }
        printf("%d\n", tag);
    }
    return 0;
}
