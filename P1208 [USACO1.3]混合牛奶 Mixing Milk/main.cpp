#include <algorithm>
#include <cstdio>
using namespace std;
int n,m,nownum,neednum,miw;
struct nm
{
    int dj,zs;
}fm[5002];
bool cmp(nm a,nm b)
{
    return a.dj < b.dj;
}
int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&fm[i].dj,&fm[i].zs);
    }
    sort(fm + 1,fm + 1 + m,cmp);
    for(int i = 1;i <= m;i++)
    {
        nownum += fm[i].zs;
        if(nownum > n)
        {
            neednum = i;
            break;
        }
        else if(nownum == n)
        {
            neednum = i;
            break;
        }
    }
    int havenum = 0;
    for(int i = 1;i < neednum;i++)
    {
        miw += fm[i].dj * fm[i].zs;
        havenum += fm[i].zs;
    }
    for(int i = 1;i <= fm[neednum].zs;i++)
    {
        havenum++;
        miw += fm[neednum].dj;
        if(havenum == n)
        {
            break;
        }
    }
    printf("%d",miw);
    return 0;
}
