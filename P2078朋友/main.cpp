#include <bits/stdc++.h>
using namespace std;
int n,m,p,q,af,bf;
map<int,int> fa;
int find(int x)
{
    if(fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void unin(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        fa[x] = y;
    }
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&p,&q);
    for(int i = -1 * m;i <= n;i++)
    {
        fa[i] = i;
    }//¸¸Ç×³õÊ¼»¯
    int a,b;
    for(int i = 1;i <= p + q;i++)
    {
        scanf("%d %d",&a,&b);
        unin(a,b);
    }
    for(int i = 1;i <= n;i++)
    {
        if(find(1) == find(fa[i]))
            af++;
    }
    for(int i = -1 * m;i <= -1;i++)
    {
        if(find(-1) == find(fa[i]))
            bf++;
    }
    printf("%d",min(af,bf));
    return 0;
}
