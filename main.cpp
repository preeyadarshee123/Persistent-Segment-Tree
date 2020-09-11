class node{
    public :
    ll s;
    node *left=NULL,*right=NULL;
};
class PersistentSegTree{
    public :
    node* create_root(){
        node *root=new node;
        return root;
    }
    void build(node* root,int l,int r){
        if(l==r){
            root->s = arr[l];
            return ;
        }
        int mid=(l+r)/2;
        node *left = new node;
        node *right = new node;
        build(left,l,mid);
        build(right,mid+1,r);
        root->left = left;
        root->right = right;
        root->s = root->left->s + root->right->s;
    }
    node* update(node* prev,int l,int r,int idx,ll val){
        if(l == r){
            node* cur = new node;
            cur->s = val;
            return cur;
        }
        int mid = (l+r)/2;
        node *cur = new node;
        if(idx <= mid){
            cur->left = update(prev->left,l,mid,idx,val);
            cur->right = prev->right;
        }
        else{
            cur->right = update(prev->right,mid+1,r,idx,val);
            cur->left = prev->left;
        }
        cur->s = cur->left->s + cur->right->s;
        return cur;
    }
    ll query(node* root,int l,int r,int a,int b){
        if(l > r || l > b || r < a){
            return 0;
        }
        if(l>=a && r<=b){
            return root->s;
        }
        return query(root->left,l,(l+r)/2,a,b) + query(root->right,(l+r)/2+1,r,a,b);
    }
};

