/*Approach1(my approach):
tc is o(1) amortized and O(h) sc for the stack:
tc is o(1)amortized: because every node undergoes 3 states. so o(3n) operations total,hence on avg per node it is o(1)
approach is to maintain second number in stack.
very initally-add non null root,1 to the stack.
for next:
while(top.s!=2){
if stack empty, add root.
if(top.s==1) {do increase top.s by1, add non null left}
if(top.s==3){pop top}
}
if(top.s==2){cout this. do top.s++. add non null right and return}

for hasnext-simpy return true if stack not empty, else false-DO THIS STEP AFTER:
AFTER CLEANSING THE TOP OF STACK OF ALL 3RD STATE NODES.CLEARLY THOSE IN 3RD STATE-ARE JUST WAITING TO BE POPPED,
SO FIRST POP THEM THEN CHECK IF EMPTY OR NOT.
*/

class BSTIteratoriterator{
    private: stack<pair<Node*,int>>me;
    public:
    BSTIterator(TreeNode* root){
        if(root){me.push({root,1});}
    }
    int next() {
        while(!me.empty() && me.top().s!=2){
            if(me.top().s==1){
                me.top().s++; 
                if(me.top().f->left){me.push({me.top().f->left,1});}
            }
            if(me.top().s==3){me.pop();}
        }
        if(me.top().s==2){
            int temp=me.top().f->data; 
            me.top().s++; 
            if(me.top().f->right){me.push({me.top().f->right,1});}
            return temp;
        }
    }
    bool hasNext(){
        while(!me.empty() && me.top().s==3){me.pop();}
        return !me.empty();
    }
}
int main(){
}

/*Approach2:
tc is o(1) amortized and O(h) sc for the stack:
tc is o(1)amortized: because sometimes we are pushing left, sometimes not. same for right child.

In constructor make a stack, push root. and push all its left as much as possible.
In same manner-we push all left child as much as possible, whenever we land at some element as top.
But then who pushes right? Clearly when I have been printed(curr),then only curr->right is added to top.
becuase in INORDER: left,curr, then right.
So save me in temp.print and pop me. then add 1 non null right
and if right is non null-then add all its left as much as possible.
So next-is top. and hasnext- if empty or not.
*/

class BSTIteratoriterator{
    private: stack<Node*>me;
    public:
    BSTIterator(TreeNode* root){
        if(root){me.push(root);}
        Node* curr=root->left; if(curr){me.push(curr);}
        while(curr){if(curr->left){me.push(curr->left);} curr=curr->left;}
    }
    int next(){Node* temp;
        if(!me.empty()){temp=me.top();}
        me.pop();
        if(temp->right){me.push(temp->right);}
        if(temp->right){
            Node*curr=temp->right;
            while(curr){
                if(curr->left){me.push(curr->left);} curr=curr->left;
            }
        }
        return temp->data;
    }
    bool hasNext(){
        return !me.empty();
    }
};
int main(){
}
