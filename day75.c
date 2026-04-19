//Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int sum;
    int index;
} Pair;

int maxLen(int arr[], int n) {
    int prefix_sum = 0;
    int max_length = 0;

    
    Pair hash[MAX];
    int hashSize = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        
        if (prefix_sum == 0) {
            max_length = i + 1;
        }

       
        int found = 0;
        for (int j = 0; j < hashSize; j++) {
            if (hash[j].sum == prefix_sum) {
                int length = i - hash[j].index;
                if (length > max_length)
                    max_length = length;
                found = 1;
                break;
            }
        }

        
        if (!found) {
            hash[hashSize].sum = prefix_sum;
            hash[hashSize].index = i;
            hashSize++;
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest zero sum subarray: %d\n", maxLen(arr, n));

    return 0;
}
