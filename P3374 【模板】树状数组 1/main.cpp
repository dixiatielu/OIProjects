#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[500006],p,q,cz,c[500006];
int lowbit(int x)
{
    return x & -x;
}
void add(int x,int y)
{
    while(x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
}
int sum(int l)
{
    int ans = 0;
    while(l > 0)
    {
        ans += c[l];
        l -= lowbit(l);
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        add(i,a[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&cz,&p,&q);
        if(cz == 1)
        {
            add(p,q);
        }
        else
        {
            printf("%d\n",sum(q) - sum(p - 1));
        }
    }
    return 0;
}
