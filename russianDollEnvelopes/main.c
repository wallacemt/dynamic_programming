#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *env1 = *(int **)a, *env2 = *(int **)b;
    if (env1[0] == env2[0]) return env2[1] - env1[1];
    return env1[0] - env2[0];
}

int lower_bound(int *dp, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (dp[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    if (envelopesSize == 0) return 0;
    
    qsort(envelopes, envelopesSize, sizeof(int*), compare);

    int *dp = (int*)malloc(envelopesSize * sizeof(int));
    int length = 0;

    for (int i = 0; i < envelopesSize; i++) {
        int height = envelopes[i][1];
        int pos = lower_bound(dp, length, height);
        if (pos == length) length++;
        dp[pos] = height;
    }

    free(dp);
    return length;
}
