#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int>&a,vector<int>&b)
{
  return a[2]<b[2];
}
int find(int x,vector<int>&parent)
{
  if(parent[x]==x)
  return x;
  return parent[x]=find(parent[x],parent);
}
void unions(int a,int b,vector<int> &parent,vector<int> &rank)
{
  int par_a=find(a,parent);
  int par_b=find(b,parent);
  if(par_a!=par_b)
  {
    if(rank[par_a]<rank[par_b])
    parent[par_a]=par_b;
    else if(rank[par_a]>rank[par_b])
    parent[par_b]=par_a;
    else
    {
      parent[par_b]=par_a;
      rank[par_a]=rank[par_a]+1;
    }
  }
}
int minimumSpanningTree(vector<vector<int>>& adj, int V)
{
  /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */

  vector<int>parent(V);
  vector<int>rank(V);
  for(int i=0;i<V;i++)
  {
      parent[i]=i;
      rank[i]=1;
  }
  int ans=0;
  sort(adj.begin(),adj.end(),comp);
  for(int i=0;i<adj.size();i++)
  {
      
          if(find(adj[i][0],parent)!=find(adj[i][1],parent))
          {
            unions(adj[i][0],adj[i][1],parent,rank);
            ans+=adj[i][2];
          }
      
  }
  return ans;
}
