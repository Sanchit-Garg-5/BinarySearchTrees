/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    int ans=1;
//vector contains number of nodes, maxi,mini
    vector<int>func(Node* curr){
        if(!curr){return {0,INT_MIN,INT_MAX};}
        //I don't want to cause any hindrance hence return maxi as int_min, similarly size and mini
        vector<int>left1=func(curr->left);
        vector<int>right1=func(curr->right);
        if(curr->data>left1[1] && curr->data<right1[2]){
            ans=max(ans,left1[0]+right1[0]+1);
            return {left1[0]+right1[0]+1,max(curr->data,right1[1]),min(curr->data,left1[2])};
        }
        return {0,INT_MAX,INT_MIN};
//I wasn't compatible with my left, or right, or both-so return such values of mini,maxi, such that
//everyone ancestor of mine also fails on comparison.
    }
  public:
    int largestBst(Node *root) {
        func(root);
        return ans;
        
    }
};
