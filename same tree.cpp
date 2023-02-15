class Solution {
public:
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
         if(t1==NULL){
            if(t2!=NULL){
                return false;
            }
            else{
                return true;
            }
        }
        if(t2==NULL){
            if(t1!=NULL){
                return false;
            }
            else{
                return true;
            }
        }
        if(t1->val!=t2->val){
            return false;
        }
        bool left=isSameTree(t1->left,t2->left);
        bool right=isSameTree(t1->right,t2->right);
        return left && right;
    }
};