//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    
    // Read size of first log
    scanf("%d", &m);
    int* log1 = (int*)malloc(m * sizeof(int));
    
    // Read first log
    for (int i = 0; i < m; i++) {
        scanf("%d", &log1[i]);
    }
    
    // Read size of second log
    scanf("%d", &n);
    int* log2 = (int*)malloc(n * sizeof(int));
    
    // Read second log
    for (int i = 0; i < n; i++) {
        scanf("%d", &log2[i]);
    }
    
    // Merge the two sorted logs using two-pointer technique
    int* merged = (int*)malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;
    
    // Traverse both logs and add smaller element to merged
    while (i < m && j < n) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    
    // Add remaining elements from log1
    while (i < m) {
        merged[k++] = log1[i++];
    }
    
    // Add remaining elements from log2
    while (j < n) {
        merged[k++] = log2[j++];
    }
    
    // Print the merged chronological log
    for (int i = 0; i < m + n; i++) {
        printf("%d", merged[i]);
        if (i < m + n - 1) printf(" ");
    }
    printf("\n");
    
    // Free allocated memory
    free(log1);
    free(log2);
    free(merged);
    
    return 0;
}
