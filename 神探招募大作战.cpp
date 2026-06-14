#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[151];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    int count = 0;
    int i = n - 1;
    
    while(i >= 0) {
        int required = a[i];
        if(i + 1 >= required) {
            count++;
            i -= required;
        } else {
            i--;
        }
    }
    
    printf("%d\n", count);
    return 0;
}
