#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int n,k,m,s,t,cul[102],maps[102][102];
//国家个数，文化个数，道路条数，起点，终点,国家i的文化种类，i到j的道路长度
bool pc[102][102];//等于1表示i排斥j
int main()
{
    scanf("%d %d %d %d %d",&n,&k,&m,&s,&t);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&cul[i]);
    }
    for(int i = 1;i <= k;i++)
    {
        for(int j = 1;j <= k;j++)
        {
            cin >> pc[i][j];
        }
    }
    for(int i = i; i <= m;i++)
    {
        int u,v,d;
        scanf("%d %d %d",&u,&v,&d);
        maps[u][v] = min(maps[u][v],d);
        maps[v][u] = maps[u][v];
    }

    return 0;
}
