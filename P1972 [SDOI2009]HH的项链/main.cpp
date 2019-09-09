#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e6 + 23;
int m,n,tpe[N],c[N],v[N],an[N];
bool have[1000001];
struct weheaj
{
    int l,r,id;
}ask[N];
bool cmp(weheaj a,weheaj b)
{
    return a.r < b.r;
}
void input()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&tpe[i]);
    }
    scanf("%d",&m);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&ask[i].l,&ask[i].r);
        ask[i].id = i;
    }
}
int lowbit(int x)
{
    return x & -x;
}
void add(int o,int ff)
{
    while(o <= n)
    {
        c[o] += ff;
        o += lowbit(o);
    }
}
int sum(int x)
{
    int ans = 0;
    while(x)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
signed main()
{
    input();
    sort(ask + 1,ask + 1 + m,cmp);
    int t1 = 1;
	for(int i = 1;i <= m;i++)
	{
		for(int j = t1;j <= ask[i].r;j++)
		{
			if(v[tpe[j]])
			{
				add(v[tpe[j]],-1);
			}
			add(j,1);
			v[tpe[j]]=j;
		}
		t1 = ask[i].r + 1;
		an[ask[i].id] = sum(ask[i].r) - sum(ask[i].l - 1);
	}
	for(int i = 1;i <= m;i++)
        printf("%d\n",an[i]);
    return 0;
}
