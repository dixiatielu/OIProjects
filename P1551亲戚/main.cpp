#include <bits/stdc++.h>
using namespace std;
int n,m,p,fa[5007],mi,mj,pi,pj;
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
}//ºÏ²¢
int main()
{
    scanf("%d %d %d",&n,&m,&p);
    for(int i = 1;i <= n;i++)
    {
        fa[i] = i;
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d",&mi,&mj);
        unin(mi,mj);
    }
    for(int i = 1;i <= p;i++)
    {
        scanf("%d %d",&pi,&pj);
        if(find(pi) == find(pj))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
