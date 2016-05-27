/*
by Avinash:
longest increasing subsequence using dynamic programming.
*/

#include<bits/stdc++.h>
using namespace std;
int get_longest(int avi[],int n)
{
   int lis[n],max1=0;
   for(int i=0;i<n;i++)
   lis[i]=1;
   for(int i=1;i<n;i++)
   {
     for(int j=0;j<i;j++)
     {
       if(avi[i] > avi[j] && lis[i]<lis[j]+1)
       {
        lis[i]=lis[j]+1;
        if(max1<lis[i])
        max1=lis[i];
       }

     }
   }
   return max1;
}
int main()
{
  int n,len=0;
  cin>>n;
  int avi[n];
  for(int i=0;i<n;i++)
  {
    cin>>avi[i];
  }
 len=get_longest(avi,n);
 cout<<"length of longest:- "<<len<<endl;
}
