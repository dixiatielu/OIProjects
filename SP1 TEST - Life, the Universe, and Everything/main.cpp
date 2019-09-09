#include <cstdio>
using namespace std;
int a;
int main()
{
    while(1)
    {
        scanf("%d",&a);
        if(a != 42)
        {
            printf("%d\n",a);
        }
        else
            break;
    }
}
