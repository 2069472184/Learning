//https://www.acwing.com/problem/content/855/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct 
{
    int a, b, w;
} edges[M];

void bellman_ford ()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    //����k�α�ʾ����������k���ߵ����յ����̾���
    //����k�β�����k�������̾���Ҳ��ȷ����
    for ( int i = 0; i < k; i++ )
    {
        //ÿ��k�����ж������е�ͬʱ�����ڵĵ����������Ҫ�洢��һ��kѭ�����dist������
        memcpy(backup, dist, sizeof(dist));
        
        for ( int j = 0; j < m; j++ )
        {
            auto q = edges[j];
            dist[q.b] = min(dist[q.b], backup[q.a] + q.w);
        }
    }
}

int main ()
{
    cin >> n >> m >> k;
    
    for ( int i = 0; i < m; i++ )
    {
        int x, y, z;
        cin >> x >> y >> z;
        //�洢x��y��һ����Ϊz�ı�
        edges[i] = {x, y, z};
    }
    
    bellman_ford();
    
    //�˴�-1Ҳ�����Ǵ𰸣����Բ����ں�����ֱ���ж� dist[n]�����Բ����� -1 ��Ϊ���޽���ж�����
    //�˴����ж��ٽ������������·�����ֵ
    if (dist[n] > N*M) puts("impossible");
    else cout << dist[n];
    
    return 0;
}