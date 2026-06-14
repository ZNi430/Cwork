#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(const char *)a - *(const char *)b);
}

int main() {
    char a[21], b[21], c[21], d[21];
    while (scanf("%s %s", a, b) != EOF) {
        int p = strlen(a);
        strcpy(c, a);
        strcpy(d, b);
        qsort(c, p, sizeof(char), compare);
        qsort(d, p, sizeof(char), compare);
        
        if (strcmp(a, b) == 0) {
            printf("Equal\n");
        } else {
            if (a[0] == b[0] && a[p-1] == b[p-1] && strcmp(c, d) == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}
