class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, result);
        
        return result[k - 1];
    }
    
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, result);
        result.push_back(node->val);
        inorder(node->right, result);
    }
};
