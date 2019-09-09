#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,ans,fa[1007],cnt;
struct gl
{
    int x,y,t;
    bool operator <(const gl & other)const
    {
        return t < other.t;
    }
}g[100007];
int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool cmp(int d,int f)
{
    return d > f;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d %d",&g[i].x,&g[i].y,&g[i].t);
    }
    for(int i = 1;i <= n;i++)
    {
        fa[i] = i;
    }
    sort(g + 1,g + 1 + m);
    for(int i = 1;i <= m ;i++)
    {
        if(cnt == n - 1)
            break;
        int a = find(g[i].x);
        int b = find(g[i].y);
        if(a != b)
        {
            cnt ++;
            fa[a] = b;
            ans = max(g[i].t,ans);
        }
    }
    if(cnt == n - 1)
    {
        printf("%d",ans);
    }
    else
    {
        printf("-1");
    }
    return 0;
}
