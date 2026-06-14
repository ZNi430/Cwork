#include <stdio.h>

int main() {
    int n; 
    scanf("%d", &n);

    int tag = 1; 

    long long current_sum = 0;

    int start = 1;

    for (int end = 1; end <= n; end++) {
        current_sum += end;
        while (current_sum > n && start < end) {
            current_sum -= start;
            start++;
        }
        if (current_sum == n && start != end) {
            tag = 0; 
            // ´òÓ¡
            for (int k = start; k <= end; k++) {
                printf("%d", k);
                if (k != end) {
                    printf(" ");
                }
            }
            printf("\n");
            current_sum -= start;
            start++;
        }
    }

    if (tag) {
        printf("None\n");
    }

    return 0;
}
