// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

// Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

// Input: root = [3,4,5,1,3,null,1]
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rob(struct TreeNode* root) {
    int result[2] = {0};
    helper(root, result);
    return fmax(result[0], result[1]);
}

void helper(struct TreeNode* root, int result[]) {
    if (root == NULL) return;

    int left[2] = {0}, right[2] = {0};

    helper(root->left, left);
    helper(root->right, right);

    result[0] = left[1] + right[1] + root->val;
    result[1] = fmax(left[0], left[1]) + fmax(right[0], right[1]);
}

