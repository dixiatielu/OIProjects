#include <cstring>
#include <cstdio>
using namespace std;
char hx[10];
char xz[10];
int x = 1,h = 1;
int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%s%s",hx,xz);
	for(int i = 0;i < strlen(hx);i++)
    {
        h *= hx[i] - 'A' + 1;
    }
    h %= 47;
    for(int i = 0;i < strlen(xz);i++)
    {
        x *= xz[i] - 'A' + 1;
    }
    x %= 47;
    if(x == h)
        printf("GO");
    else
        printf("STAY");
    return 0;
}
