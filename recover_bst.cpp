 /* TC IS O(N) AND SC IS O(1). SO MAKES US THINK MORRIS INORDER TRAVERSAL.
 THERE ARE TWO CASES:
 FIRST CASE: WHEN THE NODES TO BE SWAPPED ARE NOT ADJACENT IN THE AS IT INORDER OF THE GIVEN TREE
 Clearly we traverse inorder using morris traversal. if curr<prev- then its a discrepancy. save first=prev.
 the second time a discrepancy occurs- save second=curr. the guilty are first, second.
 SECOND CASE:WHEN THEY ARE ADJACENT:
 for ex: 20 root, 10 is left child, 40 is right child. and 30 is right child of 10.
 here we will only be able to find the first discrepancy. the second discprepancy never happens. so it must be between adjacents nodes. the node which was less than its prev- both curr, prev are guilty. 
 SO TO SOLVE BOTH CASES TOGETHER: WHEN WE GET FIRST DISCREPANCY AT curr, SAVE first=prev, middle=curr.
 Next time a discpreancy occurs, second=prev. ans is then first, second. or first, middle.
 */
class Solution {
public:
    void set1(TreeNode*curr, TreeNode* rg){
    while(rg->right){rg=rg->right;}
    rg->right=curr;
    }
    void remove1(TreeNode*curr, TreeNode* rg){
        while(rg->right!=curr){rg=rg->right;}
        rg->right=nullptr;
    }
    bool check(TreeNode*curr, TreeNode* rg){
        while(rg->right && rg->right!=curr){rg=rg->right;}
        if(!rg->right){return false;}
        if(rg->right==curr){return true;}
        return false;
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev=nullptr, *first=nullptr,*second=nullptr,*middle=nullptr,*curr=root; bool flag=false;
        while(curr){
            if(!curr->left){
                if(prev && prev->val>curr->val){
                    if(!flag){first=prev; middle=curr; flag=true;}
                    else{second=curr;}
                }
                prev=curr;
                curr=curr->right;
            }
            else{
                if(check(curr,curr->left)){
                    remove1(curr,curr->left); 
                    if(prev && prev->val>curr->val){
                        if(!flag){first=prev; middle=curr; flag=true;}
                        else{second=curr;}
                    }
                    prev=curr;
                    curr=curr->right; 
                }
                else{
                    set1(curr,curr->left); curr=curr->left;
                }
            }
        }
        if(second){swap(first->val,second->val);return;}
        swap(first->val,middle->val); return;
    }
};
