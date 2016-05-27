/*
by Avinash:
LCS problem using memoization technique ..
*/
#include<bits/stdc++.h>
using namespace std;
int table[1000][1000];
int get_lcs(string x,string y,int i,int j)
{
  if(table[i][j]==-1)
  {
   if(x[i-1]==y[j-1])
   table[i][j]=get_lcs(x,y,i-1,j-1)+1;
   else
   table[i][j]=max(get_lcs(x,y,i-1,j),get_lcs(x,y,i,j-1));
   return table[i][j];
  }
  return table[i][j];
}
int LCS(string x,string y)
{
 memset(table,-1,sizeof(table[0][0])*1000*1000);
 int m,n;
 m=x.length();
 n=y.length();
 for(int i=0;i<=m;i++)
 table[i][0]=0;
 for(int i=0;i<=n;i++)
   table[0][i]=0;
 return get_lcs(x,y,m,n);
}
int main()
{
 string x,y,lcs="";
 int len=0,i=0,j=0;
 cin>>x>>y;
 i=x.length();
 j=y.length();
 len=LCS(x,y);
 // to print the lcs string..
 while((i!=0) && ( j!=0))
 {
   if(x[i-1]==y[j-1])
   {
    lcs+=x[i-1];
    i--;
    j--;
   }
   else
   {
     if(table[i][j-1] >= table[i-1][j])
     {
      j--;
     }
     else
     i--;
   }
 }
 reverse(lcs.begin(),lcs.end());
 cout<<"lcs String :--"<<lcs<<endl;
 cout<<"length is :-"<<len<<endl;
}
