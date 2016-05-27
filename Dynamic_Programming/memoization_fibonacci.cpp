/*
by Avinash:
Program to print the nth Fibonacci using memoization technique..
*/

#include<bits/stdc++.h>
using namespace std;
int lookup[10000]={-1};
void Set()
{
  for(int i=0;i<10000;i++)
  {
    lookup[i]=-1;
  }
}
 int fib(int n)
 {
  if(lookup[n]==-1)
  {
    if(n<=1)
    lookup[n]=n;
    else
    lookup[n]=fib(n-1)+fib(n-2);
  }
  return lookup[n];
 }
int main()
{
  Set();
 int n,value=0;
 cin>>n;
 value=fib(n);
 cout<<value<<endl;
}
