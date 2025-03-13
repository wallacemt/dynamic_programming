
int cmp(const void* a, const void* b) {
    return (*(int**)a)[1] - (*(int**)b)[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    qsort(pairs, pairsSize, sizeof(int*), cmp);

    int cur = INT_MIN, res = 0;
    for (int i = 0; i < pairsSize; i++) {
        if (cur < pairs[i][0]) {
            cur = pairs[i][1];
            res++;
        }
    }
    return res;
}

