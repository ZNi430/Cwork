#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_PRIMES 10000

int is_prime(int n, int primes[], int count) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    int limit = sqrt(n) + 1;
    for (int i = 0; i < count; i++) {
        if (primes[i] > limit) break;
        if (n % primes[i] == 0) return 0;
    }
    return 1;
}

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int primes[MAX_PRIMES] = {2, 3};  
    int count = 2;  
    
    for (int i = 5; i <= 10000; i += 2) {
        if (is_prime(i, primes, count)) {
            if (count < MAX_PRIMES) {
                primes[count] = i;
                count++;
            } else {
                break;
            }
        }
    }
    
    long x;
    while (scanf("%ld", &x) != EOF) {  // 修正了这里的scanf
        if (x == 0) break;
        if(x==1){
        	printf("0\n");
        	continue;
		}
        
        // 找出所有质因数
        int ci[1000] = {0};  // 减小数组大小，1000足够
        int k = 0;
        long temp = x;
        
        for (int i = 0; i < count && primes[i] <= temp; i++) {
            if (temp % primes[i] == 0) {
                ci[k] = primes[i];
                k++;
                while (temp % primes[i] == 0) {
                    temp /= primes[i];
                }
            }
        }
        
        if (temp > 1) {
            ci[k] = temp;
            k++;
        }
        
        // 计算欧拉函数 φ(n) = n * ∏(1 - 1/p_i)
        long long zi = x;  // 使用long long防止溢出
        long long mu = 1;
        
        for (int i = 0; i < k; i++) {
            zi = zi * (ci[i] - 1);
            mu = mu * ci[i];
            
            // 约分防止溢出
            int d = gcd(zi, mu);
            zi /= d;
            mu /= d;
        }
        
        printf("%lld\n", zi / mu);
    }
    
    return 0;
}
