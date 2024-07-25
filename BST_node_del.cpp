Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(root==NULL) return root;
    if(X<=root->data)
    root->left=deleteNode(root->left,X);
    else
    root->right=deleteNode(root->right,X);
    Node* temp;
    if(X==root->data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left==NULL)
        {
            delete root;
            return root->right;
        }
        else if(root->right == NULL)
        {
            delete root;
            return root->left;
        }
        else
        {
           Node* par=root;
           Node* succ=root->right;
           while(succ->left!=NULL)
           {
               par=succ;
               succ=succ->left;
           }
           root->data=succ->data;
           
        //   if(par->left==succ)
        //   par->left=succ->right;
        //   else
        //   par->right=succ->right;
        if(par==root)
        par->right=succ->right;
        else
        par->left=succ->right;
           
           delete succ;
           return root;
        }
    
    }
    
    return root;
    
}
