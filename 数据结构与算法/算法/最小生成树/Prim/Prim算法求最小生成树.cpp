//https://www.acwing.com/problem/content/860/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510;

int n, m;
int g[N][N]; 
int dist[N];
bool st[N];

int prim ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        //�˴����е�i��ѭ�����ֲ���ͨ��������������һ�ֵĵ���뼯�Ϻ�
        //����δ���뼯�ϵĵ�ȫ���ͼ��ϲ���ͨ����ô��ʱ��С��������
        //�ĵ�����Ȼ����n����������С�������Ķ��壬������Ҫ���С�
        //���⣬res ���Ϊ 1000000000 < 00x3f3f3f3f���������赣�Ĵ���ͬ�����
        if (i && dist[t] == 0x3f3f3f3f)  return 0x3f3f3f3f;
        
        st[t] = true;
        //�˴����У����Ϊ��һ��ѭ������ʱ��Ϊ�գ�
        //û����ν�ĵ��뼯�ϵľ��룬Ҳ�Ͳ���������Ȩֵ���µ����
        //����Ҳ���Խ��ж�ȥ�������Ϊ������һ���Ե�1ΪΨһԪ�صļ���
        //��ʱ����ȨֵΪ0����������dist[1]
        if (i) res += dist[t];
        
        for (int j = 1; j <= n; j++) 
            dist[j] = min(dist[j], g[t][j]);
    }
    
    return res;
}

int main ()
{
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof(g));
    
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        //��Ϊ������ͼ��������Ҫͬʱ������������
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    
    int t = prim();
    
    if (t == 0x3f3f3f3f) puts("impossible");
    else cout << t;
    
    return 0;
}