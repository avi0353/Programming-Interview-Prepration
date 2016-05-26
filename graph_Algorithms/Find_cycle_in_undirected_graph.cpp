#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> vii;
int parent[100000];
int Rank[100000];
int Find(int i)
{
 if(parent[i]!=parent[parent[i]])
  parent[i]=Find(parent[i]);
  return parent[i];
}
bool Union(int x,int y)
{
  int xx=Find(x);
  int yy=Find(y);
  if(xx==yy)
  {
  return false;
  }
  if(Rank[xx]>Rank[yy])
    swap(xx,yy);
  if(Rank[xx]==Rank[yy])
    Rank[yy]++;
    parent[xx]=yy;
    return true;
}
int main()
{
  int n,e,u,v;
  bool flag=false;
  cin>>n;
  cin>>e;
  for(int i=1;i<=n;i++)
  {
     parent[i]=i;
     Rank[i]=0;
  }
  for(int i=0;i<e;i++)
  {
   cin>>u>>v;
   if(!Union(u,v))
   flag=true;
  }
  if(flag)
  cout<<"cycle_found\n";
  else
  cout<<"no cycle found\n";

}
