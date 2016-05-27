#include<bits/stdc++.h>
using namespace std;
 int values[1000][1000];
 int table[1000][1000];
int longest_incre_sub(int avi[],int n)
{
 memset(values,-1,sizeof(values[0][0])*(1000)*(1000));
 memset(table,0,sizeof(table[0][0])* (1000)*(1000));
 for(int i=1;i<=n;i++)
 {
   table[i][i]=1;
   values[i][i]=avi[i-1];
 }
 int k=n-1,l=1,m=1;
  for(int i=0;i<n-1;i++)
  {
     m=l;
    for(int j=1;j<=k && m<=n ;j++)
    {
       if(values[j][m]<avi[m])
       {
       table[j][m+1]=table[j][m]+1;
       values[j][m+1]=avi[m];
       }
       else
       {
        table[j][m+1]=table[j][m];
        values[j][m+1]=values[j][m];
       }
       m++;
    }
    l++;
    k--;
  }
 return table[1][n];
}
int main()
{
  int n;
  cin>>n;
  int avi[n],len=0;
  for(int i=0;i<n;i++)
  {
    cin>>avi[i];
  }
  len=longest_incre_sub(avi,n);
  cout<<"length is:-"<<len<<endl;
}
