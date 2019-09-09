#include <bits/stdc++.h>
using namespace std;
int t,n,h,fa[1001];//数据的组数，每组中：空洞个数，奶酪高度，空洞半径，每个球：球心半径
typedef long long ll;
ll x[100007],y[100007],z[100007],r;
int No1[100007],No2[100007];//顶面与底面序号
double dist(ll x2,ll y2,ll z2,ll x3,ll y3,ll z3)
{
    return sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3) + (z2 - z3) * (z2 - z3));
}//空间俩个点距离公式
int find(int x)
{
    if(fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void unin(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
        fa[x] = y;
}
int main()
{
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        int numdin = 0;//顶相交的洞
        int numdi = 0;//底相交的洞
        scanf("%d %d %lld",&n,&h,&r);
        for(int j = 1;j <= n;j++)
        {
            fa[j] = j;
        }
        for(int j = 1;j <= n;j++)
        {
            scanf("%lld %lld %lld",&x[j],&y[j],&z[j]);//输入球心
            if(z[j] + r >= h)
            {
                numdin ++;
                No1[numdin] = j;
            }
            if(z[j] - r <= 0)
            {
                numdi ++;
                No2[numdi] = j;
            }
            for(int v = 1;v <= j;v++)
            {
                if(dist(x[j],y[j],z[j],x[v],y[v],z[v]) <= r * 2)
                {
                    unin(j,v);
                }
            }
        }
        bool tag = 0;
        for(int j = 1;j <= numdin;j++)
        {
            for(int v = 1;v <= numdi;v++)
            {
                if(find(No1[j]) == find(No2[v]))
                {
                    tag = 1;
                    break;
                }
            }
            if(tag)
                break;
        }
        if(tag)
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
