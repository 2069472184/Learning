//https://www.acwing.com/problem/content/description/861/

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 200010;

int n, m;
int p[N];

//�ṹ����Ƕ���������
struct Edge
{
    //��ʾ�� a->b ȨֵΪ c
    int a, b, c;
    
    bool operator< (const Edge &w)const
    {
        return c < w.c;
    }
} edges[N];

//���鼯��·���Ż�
int find (int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int Kruskal ()
{
    //���������������бߣ�����ʹ�ȼ���ı߽϶�
    sort(edges + 1, edges + m + 1);
    
    //��ʼ�����鼯��ÿ������һ��������
    for (int i = 1; i <= n; i++) p[i] = i;
    
    int res = 0, cnt = 0;
    
    //�������б�
    for (int i = 1; i <= m; i++)
    {
        auto t = edges[i];
        //�ж�ÿ�������˵ĵ��Ƿ�����ͬ�����ڽڵ㣬
        //����ǣ��򲻼��������ߣ���Ϊ�������ڵ�
        //�Ѿ��������ˣ�����ӱ߾ͻ���ֻ�
        //����ΪʲôҪֱ�Ӹ�ֵ������Ϊ�˼������������
        //��Ϊfind��������Ϊ���ҵ����ڵ�
        t.a = find(t.a), t.b = find(t.b);
        if (t.a != t.b)
        {
            //���δ��ͨ����a����b�����ڽڵ��
            p[t.a] = t.b;
            //�������·�ͱ���
            res += t.c;
            cnt++;
        }
    }
    
    //�������С�� n - 1��˵���й����㣬��������С������
    if (cnt < n-1) return 0x3f3f3f3f;
    else return res;
}

int main ()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }
    
    int t = Kruskal();
    
    if (t == 0x3f3f3f3f) puts("impossible");
    else cout << t;
    
    return 0;
}