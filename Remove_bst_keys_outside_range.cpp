Node* removekeys(Node* root, int mn, int mx) {
          if(root==NULL) return NULL;
          
         root->left=removekeys(root->left,mn,mx);
         root->right=removekeys(root->right,mn,mx);
          
          if(root->data<mn){
            return root->right;
          }else if(root->data>mx){
            return root->left;
          }else{
              return root;
          }       
    }
