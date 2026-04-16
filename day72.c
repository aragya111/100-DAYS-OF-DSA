//Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>
#include <string.h>

char firstRepeated(char *s) {
    int freq[26] = {0};
    int n = strlen(s);
    int minIndex = n;

    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a';
        if (freq[index] == 1) {
            if (i < minIndex) {
                minIndex = i;
            }
        } else {
            freq[index] = 1;
        }
    }

    if (minIndex == n) {
        return '\0'; // No repeated character found
    }

    return s[minIndex];
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    char result = firstRepeated(s);
    if (result != '\0') {
        printf("First repeated character: %c\n", result);
    } else {
        printf("No repeated character found.\n");
    }
    return 0;
}
