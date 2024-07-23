class Solution{   
public:
    struct Node{
        Node* links[26];
        bool flag=false;
        int counts[26]={0};
        bool containsKey(char ch)
        {
            return (links[ch-'a']!=NULL);
        }
        Node* get(char ch){
        return links[ch-'a'];
        }
    };
    void insert(string w, Node* root)
    {
        Node* node=root;
        int l=w.length();
        for(int i=0;i<l;i++){
        if(!node->containsKey(w[i]))
        {
            node->links[w[i]-'a'] = new Node();
        }
    
        node=node->get(w[i]);
        
        node->counts[w[i]-'a']++;
        }
        node->flag=true;
    }
    int ans=0;
    bool search(string w,Node* root)
    {
        Node* node=root;
        int l=w.length();
        for(int i=0;i<l;i++)
        {
            if(!node->containsKey(w[i]))
            return false;
            node=node->get(w[i]);
            ans=node->counts[w[i]-'a'];
        }
        
        return true;
    }
    int klengthpref(string arr[], int n, int k, string str){    
                  
        ans=0; 
        Node* root=new Node();
        for(int i=0;i<n;i++)
        {
            insert(arr[i],root);
        }
        string check="";
        int l=str.length();
        for(int i=0;i<min(l,k);i++)
        check+=str[i];
        if(k>str.length()) return 0;
        return search(check, root)?ans:0;
        
    }
};
