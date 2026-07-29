
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidHelper(TreeNode* node, long lowerBound, long upperBound) {
        if (node == nullptr) {
            return true;
        }
        
        if (node->val <= lowerBound || node->val >= upperBound) {
            return false;
        }
        
        bool leftValid = isValidHelper(node->left, lowerBound, node->val);
        bool rightValid = isValidHelper(node->right, node->val, upperBound);
        
        return leftValid && rightValid;
    }
};
