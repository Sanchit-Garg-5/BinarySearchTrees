/*In a normal 2sum on  increaisng sorted array, num1 initlaly on smallest and num2 on largest. then accoridng to their sum beign smallest or largest-we either icnreased num1 or decreased num2. 
and since we dont want same node's sum to be the ans, we stop when num1>=num2.
so we do the same here in o(n) tc and o(H) SC: using next, prev iterators. 
The next iterator responds to us and tells us the next largest number(or next guy in INORDER or left curr right) in o(1) for one operation and ofc o(n) overall.
The prev iterator responds to us and tells us the next smallest number(or next guy in REVERSE INORDER or right curr left) in o(1) for one operation and ofc o(n) overall.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        class iterator{
            public:
            stack<TreeNode*>inc; stack<TreeNode*>dec;
            void setup1(TreeNode* root){
                TreeNode* curr = root;
                while(curr){
                    inc.push(curr); curr=curr->left;
                }
            }
            void setup2(TreeNode* root){
                TreeNode* curr=root;
                while(curr){
                    dec.push(curr); curr=curr->right;
                }
            }            
            void next(){
                TreeNode* temp = inc.top();
                inc.pop();
                if (temp->right){
                    TreeNode*curr=temp->right;
                    while(curr){
                        inc.push(curr);
                        curr=curr->left;
                    }
                }
            }
            int nextprint(){
                if(!inc.empty()){return inc.top()->val;}
                return INT_MAX;
            }
            void prev(){
                TreeNode* temp = dec.top();
                dec.pop();
                if (temp->left){
                    TreeNode*curr=temp->left;
                    while(curr){
                        dec.push(curr);
                        curr=curr->right;
                    }
                }
            }
            int prevprint(){
                if(!dec.empty()){return dec.top()->val;}
                return INT_MIN;
            }
        };
        iterator obj1,obj2; obj1.setup1(root); obj2.setup2(root);
        while(true){
            int num1=obj1.nextprint(),num2=obj2.prevprint();
            if(num1>=num2){return false;}
            if(num1+num2<k){obj1.next();}
            if(num1+num2>k){obj2.prev();}
            if(num1+num2==k){return true;}

        }
        return false;
    }
};
