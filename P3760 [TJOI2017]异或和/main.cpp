#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100008],c[100008],xorans;
int lowbit(int x)
{
    return x & -x;
}
void add(int i,int k)//把a[i]加上k
{
    while(i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}
int ask(int x)//查询1到x区间中所有数字的和
{
    int ans = 0;
    while(x)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
int qjh(int l,int r)
{
    return ask(r) - ask(l - 1);
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&a[1]);
    xorans = a[1];
    add(1,a[1]);
    for(int i = 2;i <= n;i++)
    {
        scanf("%d",&a[i]);
        xorans ^= a[i];
        add(i,a[i]);//建树
    }
    for(int i = 1;i <= n;i++)//层数
    {
        for(int j = 1;j <= n - i;j++)
        {
            xorans ^= qjh(j,j + i);
        }
    }
    printf("%d",xorans);
    return 0;
}
