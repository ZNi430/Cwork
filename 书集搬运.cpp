#include <stdio.h>
#include <stdlib.h>
#define MAXN 200005

long long a[MAXN];

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n; 
        long long V, C; 
        
        scanf("%d %lld %lld", &n, &V, &C);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        long long num_piles = 1; 
        long long current_sum = 0; 

        for (int i = 0; i < n; i++) {
            if (current_sum + a[i] <= V) {
                current_sum += a[i];
            } else {
                num_piles++;
                current_sum = a[i];  
            }
        }
        long long total_cost = num_piles * C;
        printf("%lld\n", total_cost);
    }

    return 0;
}
