#include <cstring>
#include <cstdio>
#include <algorithm>
#define reg register
#define IL inline
using namespace std;
const int MAXN = 25007;
int ooopppqqq,mx;
int n,ans,mn[MAXN],vis[MAXN];
IL void input()
{
    scanf("%d",&n);
    ans = 0;
    for(reg int i = 1;i <= n;i++)
    {
        scanf("%d",&mn[i]);
    }
}
IL void work()
{
    memset(mn,0,sizeof(mn));
    memset(vis,0,sizeof(vis));
    input();
    sort(mn + 1,mn + n + 1);
    mx = mn[n];
    for(reg int i = 1;i <= n;i++)
    {
        if(vis[mn[i]])
            continue;
        ans++;
        vis[mn[i]] = 1;
        for(reg int j = mn[i];j <= mx;j++)
        {
            if(vis[j - mn[i]])
                vis[j] = 1;
        }
    }
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d",&ooopppqqq);
	while(ooopppqqq--)
    {
        work();
        printf("%d\n",ans);
    }
    return 0;
}
