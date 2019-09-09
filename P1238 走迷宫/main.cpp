#include <iostream>
#include <cstdio>
using namespace std;
int ma[20][20],m,n,sx,sy,ex,ey,step[200000][2],nowstep;
bool gone[20][20];
int dx[4] = {0,-1,0,1},dy[4] = {-1,0,1,0};//左上右下
bool cg;
void output()
{
    for(int g = 0;g < nowstep;g++)
    {
        printf("(%d,%d)->",step[g][0],step[g][1]);
    }
    printf("(%d,%d)\n",ex,ey);
}
void dfs(int nowx,int nowy)
{
    if(nowx == ex && nowy == ey)
    {
        cg = 1;
        output();
        return;
    }
    for(int i = 0;i <= 3;i++)
    {
        if(ma[nowx + dx[i]][nowy + dy[i]] && !gone[nowx + dx[i]][nowy + dy[i]])
        {
            step[nowstep][0] = nowx;
            step[nowstep][1] = nowy;
            gone[nowx][nowy] = 1;
            nowstep++;
            dfs(nowx + dx[i],nowy + dy[i]);
            gone[nowx][nowy] = 0;
            nowstep--;
        }
    }
}
int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&m,&n);
	for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            scanf("%d",&ma[i][j]);//1可以走，0不能走
        }
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    dfs(sx,sy);
    if(!cg)
    {
        printf("-1");
    }
    return 0;
}
