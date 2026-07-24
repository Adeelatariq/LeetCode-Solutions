class Solution {
public:
    int maxDepth(TreeNode* root) {
            if(root==nullptr){
                 return 0;
            }
else{
 int l = maxDepth(root->left);
 int r = maxDepth(root->right);
 return max(r,l)+1;

}
        }
        
};
