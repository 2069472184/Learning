//https://www.acwing.com/problem/content/description/167/

//ÿ�εݹ�ö�ٳ���
#include <iostream>
#include <algorithm>

using namespace std;

int n, w;
int c[20], sum[20];
int ans = 20;

void dfs (int u, int k)
{
    //�����Լ�֦���˴�ֻ��Ϊ >= ����Ϊ ==
    //��Ϊ���ܳ���ĳһ�εݹ������ans��������һ��֮����һ�εݹ���Ҫ�¿�һ��������ͻᵼ��cnt = ans + 1
    //������Ҫ����������������ܵ����� k == ans ʱ��֦
    if (k >= ans) return;
    
    if (u == n)
    {
        ans = k;
        return;
    }
    
    //ö�ٵ�ǰÿһ�����Ƿ��ܹ��ٷ���һֻСè
    for (int i = 0; i < k; i++)
        if (c[u] + sum[i] <= w)
        {
            sum[i] += c[u];
            dfs(u + 1, k);
            sum[i] -= c[u];
        }
        
    //���û�г��ܹ�����Сè����ô���¿�һ��    
    sum[k] = c[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}

int main ()
{
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> c[i];
    
    //�˴�������͵��þ���Ϊ�˽������ص�Сè�ȷŵ����У�Ȼ���ٿ���è�Ƿ��ܹ������
    sort(c, c + n);
    reverse(c, c + n);
    
    dfs(0, 0);
    
    cout << ans << endl;
    
    return 0;
}

//��������ÿ�εݹ鶼ö��Сè������ִ����ظ������ֻ�Ǹı����Ⱥ�˳��