#include <stdlib.h>
struct TreeNode** generateTreesHelper(int start, int end, int* returnSize) {
    if (start > end) {
        struct TreeNode** baseResult = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        baseResult[0] = NULL;
        *returnSize = 1;
        return baseResult;
    }

    int totalSize = 0;
    struct TreeNode** result = NULL;

    for (int i = start; i <= end; i++) {
        int leftSize, rightSize;
        struct TreeNode** leftTrees = generateTreesHelper(start, i - 1, &leftSize);
        struct TreeNode** rightTrees = generateTreesHelper(i + 1, end, &rightSize);

        for (int l = 0; l < leftSize; l++) {
            for (int r = 0; r < rightSize; r++) {
                struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                root->val = i;
                root->left = leftTrees[l];
                root->right = rightTrees[r];

                result = (struct TreeNode**)realloc(result, (totalSize + 1) * sizeof(struct TreeNode*));
                result[totalSize] = root;
                totalSize++;
            }
        }

        free(leftTrees);
        free(rightTrees);
    }

    *returnSize = totalSize;
    return result;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesHelper(1, n, returnSize);

}
