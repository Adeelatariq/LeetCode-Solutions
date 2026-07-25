
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }
        else {
            bool leftSame = isSameTree(p->left, q->left);
            bool rightSame = isSameTree(p->right, q->right);
            return (p->val == q->val) && leftSame && rightSame;
        }
    }
};
