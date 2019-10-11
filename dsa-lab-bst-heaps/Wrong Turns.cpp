#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct Node
{
    int data;
    int lmax,rmin;
    Node* left;
    Node* right;
    Node(int n){
        data = n;
        lmax = n;
        rmin = n;
        left = right = nullptr;
    }
};

void insert(Node* root, int val){
    if(root->data<val){
        if(root->right==nullptr){
            root->right = new Node(val);
        }
        else{
            insert(root->right, val);
        }
        if(root->rmin == root->data) root->rmin = val;
        else root->rmin = min(val, root->rmin);
    }
    else{
        if(root->left==nullptr){
            root->left = new Node(val);
        }
        else{
            insert(root->left, val);
        }
        if(root->lmax == root->data) root->lmax = val;
        else root->lmax = max(val, root->lmax);
    }
}

double solve(Node* root, int val){
    double ans = val;
    double count = 1;
    while(root->data!=val){
        if(root->data<val){
            if(root->lmax!=root->data){
                ans += root->lmax;
                count++;
            }
            root = root->right;
        }
        else{
            if(root->rmin!=root->data){
                ans += root->rmin;
                count++;
            }
            root = root->left;
        }
    }
    return (ans/count);
}

void print(Node* root){
    if(root==nullptr) return;
    cout<<root->data<<" "<<root->lmax<<" "<<root->rmin<<endl;
    print(root->left);
    print(root->right);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,q,a;
    cout<<setprecision(10)<<fixed;
    cin>>n>>q;
    cin>>a;
    Node* root = new Node(a);
    for(int i=1;i<n;i++){
        cin>>a;
        insert(root, a);
    }
    //print(root);
    while(q--){
        cin>>a;
        cout<<solve(root,a)<<endl;
    }
}