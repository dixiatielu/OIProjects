#include <cstdio>
using namespace std;
int stx,sty,edx,edy,nowx,nowy;
bool cango[100007][16],gone[100007][16];
void dfs(int st1,int st2)
{
    if(cango[st1][st2 - 1] && )
    {
        nowy --;
        dfs(nowx,nowy)
    }
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for(int i = 1;i <= m;i++)
		for (int j = 1; j <= n; j++)
		{
            scanf("%d",&cango[i][j]);
		}
    scanf("%d %d",&stx,&sty);
    scanf("%d %d",&edx,&edy);
    printf("(%d,%d)->",stx,sty);
    nowx = stx;
    nowy = sty;
    gone[stx][sty] = 1;
    dfs(stx,sty,edx,edy)
    print();
}
