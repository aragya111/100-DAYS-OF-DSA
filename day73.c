//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(const char *s) {
    int freq[26] = {0}; // Array to store frequency of each character
    int len = strlen(s);

    // Count frequency of each character
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < len; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    // If no non-repeating character found, return '$'
    return '$';
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    char result = firstNonRepeatingChar(s);
    printf("First non-repeating character: %c\n", result);
    return 0;
}
            