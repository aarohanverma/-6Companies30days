#include <bits/stdc++.h>
using namespace std;
int fun(int n,int m,int k)
{
    int x=(k+m-1);
    if(x>n)
    {
        if(x%n==0)
        {
            return n;
        }
        return x%n;
    }
    else
    {
        return x;
    }
}
int main()
{
    int n=5;
    int m=3;
    int k=4;
    cout<<fun(n,m,k);
    return 0;
}
