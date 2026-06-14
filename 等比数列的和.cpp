#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int s;
        scanf("%d", &s);
        
        long long cnt = 0;
        long long ac[10000], pc[10000], kc[10000];
        
        for (int p = 2; p < 1000; p++) {
            // ±éÀúk
            for (int k = 2; k < 1000; k++) {
                long long p_pow_k = 1;
                
                // ¼ÆËãp^k
                for (int m = 0; m < k; m++) {
                    p_pow_k *= p;
                    if (p_pow_k > 1e12) break;
                }
                
                if (p_pow_k <= 1) continue;
                
                // ¼ÆËãa
                long long numerator = (long long)s * (p - 1);
                long long denominator = p_pow_k - 1;
                
                if (denominator <= 0) continue;
                if (numerator % denominator == 0) {
                    long long a = numerator / denominator;
                    
                    if (a > 0) {
                        ac[cnt] = a;
                        pc[cnt] = p;
                        kc[cnt] = k;
                        cnt++;
                        
                        if (cnt >= 10000) {
                            break;
                        }
                    }
                }
                if (p_pow_k > 1e9) break;
            }
            
            if (cnt >= 10000) break;
        }
        
        printf("Case %d\n", i);
        printf("%lld\n", cnt);
        for (int j = 0; j < cnt; j++) {
            printf("%lld %lld %lld\n", ac[j], pc[j], kc[j]);
        }
    }
}
