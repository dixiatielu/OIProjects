#include <iostream>
#include <cstdio>
#define reg register
#define IL inline
using namespace std;
const int MAXN = 107;
const int MAXM = 10007;
int n,m,ans;
int d[MAXN][MAXN],mg[MAXM];
void input()
{
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&mg[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            scanf("%d",&d[i][j]);
        }
    }
}
void floyd()
{
    for(int k = 1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(i != j && j != k && k != i && d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
	input();
	floyd();
	for(int i = 2;i <= m;i++)
    {
        ans += d[mg[i - 1]][mg[i]];
    }
    printf("%d\n",ans);
    return 0;
}
