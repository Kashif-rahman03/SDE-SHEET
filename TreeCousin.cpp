class Solution {
public:
    TreeNode* find(TreeNode* root,int key){
        if(root==NULL)return NULL;
        if(root->val==key)return root;
        TreeNode* n=find(root->left,key);
        if(n!=NULL)return n;
        return find(root->right,key);
        
    }

    bool isSibling(TreeNode* root,TreeNode* x,TreeNode* y){
        if(root==NULL)return false;
        if(root->left==x&&root->right==y)return true;
        if(root->left==y&&root->right==x)return true;
        return isSibling(root->left,x,y)||isSibling(root->right,x,y);
    }
    int level(TreeNode* root,TreeNode* k,int lev){
        if(root==NULL)return 0;
        if(root==k)return lev;
        return max(level(root->left,k,lev+1),level(root->right,k,lev+1));
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* xx=find(root,x);
        TreeNode* yy=find(root,y);
        return (level(root,xx,0)==level(root,yy,0))&&(!isSibling(root,xx,yy));
    }
};
