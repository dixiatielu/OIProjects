#include <iostream>
#include <cstdio>
const int MAX_INT = 2147483647;
using namespace std;
int n,s,e,k[102],maps[102][102],times[102],distr[102][102];
//·�ڵ��������糵�������յ㣬��i��·�����ӵĹ����������i��·�ڵĵ�j�����ͨ���·�ڣ�����㵽���i��·�ڸı俪�ص���С��������i·�ڵ�j·�ڵ�ʵ���³�����
bool vis[102];//�Ѿ�ȡ������C����
int main()
{
    scanf("%d %d %d",&n,&s,&e);//n��·�ڣ���ʼ������
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            distr[i][j] = MAX_INT;//����һ�㵽�����ľ��븳ֵΪ���޴󣬱�ʾû��·����
        }
    }
    for(int i = 1;i <= n;i++)//һ��·��
    {
        scanf("%d",&k[i]);
        for(int j = 1;j <= k[i];j++)//һ�����
        {
            scanf("%d",&maps[i][j]);//������ǵ�i��·�ڵĵ�j�����ͨ���·��
            //����Ĭ��ָ��maps[i][1]
            if(j != 1)
            {
                distr[i][maps[i][j]] = 1;
            }
            else
            {
                distr[i][maps[i][j]] = 0;
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        times[i] = MAX_INT;//��ֵ��ÿ����Ϊ�����
    }
    times[s] = 0;
    int bminNum;
    for(int i = 1;i <= n;i++)
    {
        bminNum = -1;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && (bminNum == -1 || times[j] < times[bminNum]))
            {
                bminNum = j;
            }
        }//��B����ѡ�����ش�����С��·��
        vis[bminNum] = 1;//����Ѿ�ѡ��������C���ϣ�
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && distr[bminNum][j] != MAX_INT)
            {
                times[j] = min(times[j],times[bminNum] + distr[bminNum][j]);
            }
        }
    }
    if(times[e] == MAX_INT)
        printf("-1");
    else
        printf("%d",times[e]);
    return 0;
}
