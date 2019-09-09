#include <cstring>
#include <cstdio>
using namespace std;
int tme;
char fin[11];
char arti[11][1000001];
char d_x(char fg)
{
    if(fg >= 'A' && fg <= 'Z')
        fg = fg - 'A' + 'a';
    return fg;
}
int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%s",fin);
    for(int i = 0;i < strlen(fin);i++)
    {
        fin[i] = d_x(fin[i]);
    }
    int cnt = 0;
	while(~scanf("%s",arti[++cnt]))
	{
	    for(int i = 0;i < strlen(arti[cnt]);i++)
            arti[i][cnt] = d_x(arti[i][cnt]);
	    if(arti[cnt] == fin)
            tme++;
	}
	if(!tme)
        printf("-1");
    else
        printf("%d",tme);
    return 0;
}
