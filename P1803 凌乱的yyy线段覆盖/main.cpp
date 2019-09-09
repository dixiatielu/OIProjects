#include <algorithm>
#include <cstdio>
using namespace std;
int n,ans = 1;
struct xd
{
    int st,en;
}ex[1000007];
bool cmp(xd a,xd b)
{
    return a.en < b.en;
}
int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d",&n);
	for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&ex[i].st,&ex[i].en);
    }
    sort(ex + 1,ex + 1 + n,cmp);
    int m = ex[1].en;
    for(int i = 2;i <= n;i++)
    {
        if(ex[i].st >= m)
        {
            ans++;
            m = ex[i].en;
        }
    }
    printf("%d",ans);
    return 0;
}
