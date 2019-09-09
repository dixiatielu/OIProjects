#include <bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,ex,ey,zx,zy,num_fa;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};//иообвСср
bool ma[7][7],gone[7][7];
void dfs(int nowx,int nowy)
{
    if(nowx == ex && nowy == ey)
    {
        num_fa++;
        return;
    }
    else
    {
        for(int i = 0;i <= 3;i++)
        {
            if(!gone[nowx + dx[i]][nowy + dy[i]] && ma[nowx + dx[i]][nowy + dy[i]] == 1)
            {
                gone[nowx][nowy] = 1;
                dfs(nowx + dx[i],nowy + dy[i]);
                gone[nowx][nowy] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    for(int i = 1;i <= n;i++)
        for(int j= 1;j <= m;j++)
            ma[i][j] = 1;
    for(int i = 1;i <= t;i++)
    {
        scanf("%d%d",&zx,&zy);
        ma[zx][zy] = 0;
    }
    dfs(sx,sy);
    printf("%d",num_fa);
    return 0;
}
