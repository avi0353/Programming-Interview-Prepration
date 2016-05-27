/*
by Avinash:
Dynamic programming approach to find the longest common subsequence of two strings.
*/
#include<bits/stdc++.h>
using namespace std;
int LCS(string x,string y)
{
 int m,n,k=0,l=0;
 m=x.length();
 n=y.length();
 int table[m+1][n+1];
 string s;

 for(int i=0;i<=m;i++)
  table[i][0]=0;
 for(int i=0;i<=n;i++)
  table[0][i]=0;

 for(int i=1;i<=m;i++)
 {
   for(int j=1;j<=n;j++)
   {
     if(x[i-1]==y[j-1])
     {
       table[i][j]=table[i-1][j-1]+1;
     }
     else
     {
       table[i][j]=max(table[i-1][j],table[i][j-1]);
     }
   }
 }
  k=m;
  l=n;
  while( (k!=0) && (l!=0))
  {
     if(x[k-1]==y[l-1])
     {
       s+=x[k-1];
       k--;
       l--;
     }
     else
     {
      if(table[k-1][l] >=table[k][l-1])
      {
        k--;
      }
      else
      {
        l--;
      }
     }
  }
 reverse(s.begin(),s.end());
 cout<<"longest common subsequence is:- "<<s<<endl;
 return table[m][n];
}
int main()
{
  string x,y;
  int len=0;
  cin>>x>>y;
  len=LCS(x,y);
  cout<<"length is:- "<<len<<endl;
}
