#include <stdio.h>
#include <stdbool.h> 
#include <string.h>  
int nums[1005]; 
int counts[20005]; 

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool check(int n, int sz) {
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < n; i++) {
        int re= nums[i] % sz; 
        
        counts[re]++; 
        if (counts[re] > 2) {
            return false; 
        }
    }
    return true; 
}

int main() {
    int t;
    if (scanf("%d", &t) != EOF) {
        while (t--) {
            int n;
		    scanf("%d", &n);
		    for (int i = 0; i < n; i++) {
		        scanf("%d", &nums[i]); 
		    }
		    for (int sz = 2; ; sz++) {
		        if (!isPrime(sz)) {
		            continue; 
		        }
		        if (check(n, sz)) {
		            printf("%d\n", sz); 
		            break; 
		        }
		    }
        }
    }
    return 0;
}
