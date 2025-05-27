class Solution {
    int total = 0; // To store the total number of valid paths

    // Recursive function to find all paths starting from the current node
    // whose sum equals targetSum
    void findPathSum(TreeNode* root, int targetSum, long long currentSum) {
        if (root == NULL) {
            return; // Base case: reached a null node
        }

        // Add the current node's value to the running sum
        currentSum += root->val;

        // If current path sum equals targetSum, increment the counter
        if (targetSum == currentSum) {
            total++;
        }

        // Recurse to left and right children
        findPathSum(root->left, targetSum, currentSum);
        findPathSum(root->right, targetSum, currentSum);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0; // No paths if tree is empty
        }

        long long currentSum = 0;

        // Find all paths starting from the current root
        findPathSum(root, targetSum, currentSum);

        // Recursively call pathSum on the left and right subtrees
        // to consider paths that start from each child as root
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return total; // Return the final count of all valid paths
    }
};
