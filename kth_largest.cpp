
class Node{
    public:
    ll data;
    Node* left; 
    Node* right;
    Node(ll val, Node* left1, Node* right1):data(val),left(left1),right(right1){}
    Node(ll val):data(val),left(nullptr),right(nullptr){}
    Node():data(0),left(nullptr),right(nullptr){}
};
/*1st approach: sc is o(h) and tc is o(h+k)since cut short when ans is found.
Here my right child tells me how largest i am. and i tell my left child-how largest it is.
and my left child helps me tell how largest my parent is.
initial myself is =1 and curr=root and ans=nullptr;
myself=func(right,myself) (if right is not null).
else myself=myself.
if(myself==k){ans=curr}
temp=func(left,myself+1)(if left not null)
else return myself+1.
return temp.
to cut short: tc becomes o(h+k): we do if ans has been found, return myself, at very top.
also deals with if k>n.
*/
ll klargest(Node* curr, ll myself,Node*& ans,ll k){
    if(ans){return myself;}
    if(curr->right){myself=klargest(curr->right,myself,ans);}
    if(myself==k){ans=curr; return myself;}
    if(curr->left){return klargest(curr->left,myself+1,ans);}
    return myself+1;
}
int main(){
    Node* ans=nullptr;
    klargest(root,1,ans,k);
}

/*2nd approach: sc is o(h)(if recursive) 
    and tc is o(h+k):since we return when ans is found
    we know inorder is sorted increasing. so why not go right, root, left.
    after we explored right,again check if ans has been found.
    if yes, then return else:
    we do count++. now if count==k, we are the ans and return.
    else further explore left.
*/
ll count=0;
void klargest(Node* curr,Node*& ans,ll k){
    if(!curr || ans){return;}
    klargest(curr->right,ans,k);
    if(ans){return;}
    count++; 
    if(count==k){ans=curr; return;}
    klargest(curr->left,ans,k); return;
}
int main(){
    Node* ans=nullptr;
    klargest(root,ans,k);
}

/*3nd approach: sc is o(1)since  morris and tc is o(n)since we need to:
find the total number of nodes first(if k largest not in k smallest). also we can't escape early from morris.
since morris always explore left first, while for k largest,we needed to go to right first.
so instead of comparing count with k, why not compare with n-k+1. in that way morris's inorde works for k largest too.
WE CAN ALSO DO REVERSE MORRIS IN 1 PASS. IN THAT WE SET CONNECTION BETWEEN LEFTMOST CHILD OF THE RIGHT SUBTREE.
*/
void set1(Node*curr, Node* rg){
    while(rg->right){rg=rg->right;}
    rg->right=curr;
}
void remove1(Node*curr, Node* rg){
    while(rg->right!=curr){rg=rg->right;}
    rg->right=nullptr;
}
bool check(Node*curr, Node* rg){
    while(rg->right && rg->right!=curr){rg=rg->right;}
    if(!rg->right){return false;}
    if(rg->right==curr){return true;}
    return false;
}
int main(){
    ll total=0;
    Node* curr=root;
    while(curr){ // to find total nodes
        if(!curr->left){total++; curr=curr->right;}
        else{
            if(check(curr,curr->left)){
                remove1(curr,curr->left); total++; curr=curr->right; 
            }
            else{
                set1(curr,curr->left); curr=curr->left;
            }
        }
    }
    ll count=0; Node* ans=nullptr; curr=root;
    while(curr){ 
        if(!curr->left){ 
            count++;
            if(count==total-k+1){ans=curr;}//dont put break here-can't escpae early from morris
            curr=curr->right;
        }
        else{
            if(check(curr,curr->left)){
                remove1(curr,curr->left); 
                count++;
                if(count==total-k+1){ans=curr;} //dont put break here-can't escpae early from morris
                curr=curr->right; 
            }
            else{
                set1(curr,curr->left); curr=curr->left;
            }
        }
    }
