 int missingNumber(int arr[], int n) 
    { 
        // Your code here
       int in=0;
       for(int i=0;i<n;i++)
       {
           if(arr[i]>0)
           {
               swap(arr[i],arr[in]);
               in++;
           }
       }
       
       for(int i=0;i<in;i++)
       {
           int val=abs(arr[i]);
           if(val-1 < in && arr[val-1]>0)
           arr[val-1]*=-1;
       }
       
       for(int i=0;i<in;i++)
       {
           if(arr[i]>0)
           return i+1;
       }
       return in+1; 
    } 
