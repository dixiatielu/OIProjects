#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int n,k,m,s,t,cul[102],maps[102][102];
//���Ҹ������Ļ���������·��������㣬�յ�,����i���Ļ����࣬i��j�ĵ�·����
bool pc[102][102];//����1��ʾi�ų�j
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
