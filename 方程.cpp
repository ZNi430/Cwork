#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Solution;

int compare(const void *a, const void *b) {
    Solution *s1 = (Solution *)a;
    Solution *s2 = (Solution *)b;
    return s1->x - s2->x;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        long long a, b, c; 
        scanf("%lld %lld %lld", &a, &b, &c);

        long long k = c + a * b; 
        
        Solution sols[10000];
        int count = 0;

        for (long long i = 1; i * i <= k; i++) {
            if (k % i == 0) {
                long long factor1 = i;
                long long factor2 = k / i;

                if (factor1 >= b && factor2 >= a) {
                    sols[count].x = (int)(factor1 - b);
                    sols[count].y = (int)(factor2 - a);
                    count++;
                }
                if (factor1 != factor2) {
                    if (factor2 >= b && factor1 >= a) {
                        sols[count].x = (int)(factor2 - b);
                        sols[count].y = (int)(factor1 - a);
                        count++;
                    }
                }
            }
        }

        printf("%d\n", count);

        if (count > 0) {
            qsort(sols, count, sizeof(Solution), compare);
            
            for (int i = 0; i < count; i++) {
                printf("%d %d\n", sols[i].x, sols[i].y);
            }
        }
    }
    return 0;
}
