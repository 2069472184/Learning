//https://www.acwing.com/problem/content/848/

#include <iostream>
#include <cstring>

using namespace std;
const int N =100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
int ans = N;
bool st[M];

//ͷ�壬��b����a�У�a��Ϊ������������ͷ
//������ʱ��Ӹ��ڵ㿪ʼ�ݹ飬�ݹ鵽��ĩ�ӽڵ���㷵��
void add (int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

//�����Ա��uΪ���ڵ�������нڵ�����
int dfs (int u)
{
    //�����������飬��ʾ��ǰ�ڵ��ѱ�������
    st[u] = true;
    
    int size = 0, sum = 0;
    //����u�����������нڵ����
    for ( int i = h[u]; i != -1; i = ne[i] )
    {
        if (st[e[i]]) continue;
        
        //s����e[i]Ϊ���ڵ�������нڵ���
        int s = dfs(e[i]);
        size = max(size, s);
        
        //sum��ʾ��uΪ���ڵ�������г����ڵ�����������ڵ������
        sum += s;
    }
    
    //����forѭ����size��ʾ����u�ڵ�����������нڵ��������ֵ
    //n - (sum + 1) ��ʾ��u�ڵ�֮�ϵ����нڵ������������ȡ���ֵ
    size = max(size, n - sum - 1);
    //�����ȡ���ֵ�������Сֵ
    ans = min(ans, size);
    
    //���ظ��ڵ�+�����ڵ���
    return sum + 1;
}

int main () 
{
    cin >> n;
    
    memset(h, -1, sizeof(h));
    
    for ( int i = 0; i < n - 1; i++ )
    {
        int a, b;
        cin >> a >> b;
        //��Ϊ������ߣ�������Ҫ��������
        add(a, b), add(b, a);
    }
    //�ӱ��1�Ľ�㿪ʼ������Ľڵ��ſ�������
    dfs(1);
    
    cout << ans;
    
    return 0;
}