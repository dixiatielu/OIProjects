#include <iostream>
#include <cstdio>
const int MAX_INT = 2147483647;
using namespace std;
int n,s,e,k[102],maps[102][102],times[102],distr[102][102];
//路口的数量，电车的起点和终点，第i个路口链接的轨道条数，第i个路口的第j个轨道通向的路口，从起点到达第i个路口改变开关的最小次数，从i路口到j路口的实际下车次数
bool vis[102];//已经取出放入C集合
int main()
{
    scanf("%d %d %d",&n,&s,&e);//n个路口，开始，到达
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            distr[i][j] = MAX_INT;//给任一点到任意点的距离赋值为无限大，表示没有路相连
        }
    }
    for(int i = 1;i <= n;i++)//一个路口
    {
        scanf("%d",&k[i]);
        for(int j = 1;j <= k[i];j++)//一个轨道
        {
            scanf("%d",&maps[i][j]);//输入的是第i个路口的第j个轨道通向的路口
            //开关默认指向maps[i][1]
            if(j != 1)
            {
                distr[i][maps[i][j]] = 1;
            }
            else
            {
                distr[i][maps[i][j]] = 0;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        times[i] = MAX_INT;//赋值给每个点为无穷大
    }
    times[s] = 0;
    int bminNum;
    for(int i = 1;i <= n;i++)
    {
        bminNum = -1;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && (bminNum == -1 || times[j] < times[bminNum]))
            {
                bminNum = j;
            }
        }//从B集合选出开关次数最小的路口
        vis[bminNum] = 1;//标记已经选出（放入C集合）
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && distr[bminNum][j] != MAX_INT)
            {
                times[j] = min(times[j],times[bminNum] + distr[bminNum][j]);
            }
        }
    }
    if(times[e] == MAX_INT)
        printf("-1");
    else
        printf("%d",times[e]);
    return 0;
}
