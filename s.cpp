#include <stdio.h>
#include <stdlib.h>

int main() {
    long long w, d;
    int n;
    while (scanf("%lld %d %lld", &w, &n, &d) != EOF) {
        long long *pos = (long long *)malloc((n + 2) * sizeof(long long));
        
        pos[0] = 1;      
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &pos[i]);
        }
        pos[n + 1] = w;  

        int min_remove = 1e9;
        int r = 0;

        for (int l = 0; l <= n; l++) {
            while (r <= n + 1 && pos[r] - pos[l] <= d) {
                r++;
            }
            if (r <= n + 1) {
                int current_remove = r - l - 1;
                if (current_remove < min_remove) {
                    min_remove = current_remove;
                }
            }
        }

        if (min_remove > n) printf("-1\n");
        else printf("%d\n", min_remove);

        free(pos); 
    }
    return 0;
}
