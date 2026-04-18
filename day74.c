//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 100

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][NAME_LEN];

    
    for(int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    
    int count[MAX] = {0};
    int used[MAX] = {0};

    int maxVotes = 0;
    char winner[NAME_LEN];

    for(int i = 0; i < n; i++) {
        if(used[i]) continue;

        int freq = 1;
        for(int j = i + 1; j < n; j++) {
            if(strcmp(votes[i], votes[j]) == 0) {
                freq++;
                used[j] = 1;
            }
        }

        
        if(freq > maxVotes) {
            maxVotes = freq;
            strcpy(winner, votes[i]);
        } else if(freq == maxVotes) {
            if(strcmp(votes[i], winner) < 0) {
                strcpy(winner, votes[i]);
            }
        }
    }

    printf("%s\n", winner);

    return 0;
}
