#include <stdio.h>
#include <stdlib.h> 

int compare_int_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_int_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int m, s, c;
    scanf("%d %d %d", &m, &s, &c);

    int locations[200];
    for (int i = 0; i < c; i++) {
        scanf("%d", &locations[i]);
    }

    if (m >= c) {
        printf("%d\n", c);
        return 0;
    }
    qsort(locations, c, sizeof(int), compare_int_asc);

    int total_cost = locations[c - 1] - locations[0] + 1;

    int gaps[199];
    int gap_count = c - 1;
    for (int i = 0; i < gap_count; i++) {
        gaps[i] = locations[i + 1] - locations[i] - 1;
    }

    qsort(gaps, gap_count, sizeof(int), compare_int_desc);

    int breaks_to_use = m - 1;
    for (int i = 0; i < breaks_to_use; i++) {
        total_cost -= gaps[i];
    }
    printf("%d\n", total_cost);

    return 0;
}
