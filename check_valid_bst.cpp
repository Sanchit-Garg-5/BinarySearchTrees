
class Node{
    public:
    ll data;
    Node* left; 
    Node* right;
    Node(ll val, Node* left1, Node* right1):data(val),left(left1),right(right1){}
    Node(ll val):data(val),left(nullptr),right(nullptr){}
    Node():data(0),left(nullptr),right(nullptr){}
};
/*check if a tree is bst or bt:
let mini be LLONG_MIN, maxi=LLONG_MAX.
if(!curr){return true;}
if(curr doesnt lie in range)return false.
else return func(curr->left,mini,curr-data) && func(curr->right,curr-data,maxi).
It runs in O(N) time by visiting each node exactly once, and O(h) space for the recursion stack.
*/
bool check(Node* curr,ll mini,ll maxi){
    if(!curr){return true;}
    if(curr->data<mini || curr->data>maxi){return false;}
    return (check(curr->left,mini,curr->data) && check(curr->right,curr->data,maxi));
}
int main(){
    check(root,LLONG_MIN,LLONG_MAX);
}
class Node{
    public:
    ll data;
    Node* left; 
    Node* right;
    Node(ll val, Node* left1, Node* right1):data(val),left(left1),right(right1){}
    Node(ll val):data(val),left(nullptr),right(nullptr){}
    Node():data(0),left(nullptr),right(nullptr){}
};
/*or we can do inorder traversal. clearly any node has to be greater than its prev node.
prev initally is nullptr(compare with non null prev only). 
call left(with same prev as mine), check me, update prev=me. call right.
if left had returned false, i return false then and there. if i didnt satisfy-i return false then and there.
It runs in O(N) time by visiting each node exactly once, and O(h) space for the recursion stack.
*/
bool check(Node* curr,Node*& prev){ //IT IS BY REFERENCE
    //OTHERWISE THINK OF A CASE WHERE ROOT IS LESS THAN LEFT CHILD-IT WILL GET PASSED IF NOT BY REFERENCE
    if(!curr){return true;}
    if(!check(curr->left,prev)){return false;}
    if(prev && curr->data<prev->data){return false;}
    prev=curr;
    return check(curr->right,prev);
}
int main(){
    Node* prev=nullptr;
    check(root,prev);
}
