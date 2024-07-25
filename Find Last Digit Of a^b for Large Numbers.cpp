//cyclic concept and mod 4; imp:res=(res*10 + (b[i]-'0'))%4;
int getLastDigit(string a, string b) {
        // code here
        int last[10]={1,1,5,5,3,2,2,5,5,3};
        int al=a.length();
        int bl=b.length();
        int res=0;
        if(b=="0")
        return 1;
        for(int i=0;i<bl;i++)
        {
            res=(res*10 + (b[i]-'0'))%4;
        }
        res=(res==0)?4:res;
        int ans=pow((a[al-1]-'0'),res);
        return ans%10;
    }
