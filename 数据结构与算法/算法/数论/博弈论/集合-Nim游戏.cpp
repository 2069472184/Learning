//https://www.acwing.com/problem/content/895/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
const int N = 110, M = 10010;

int n, k;
//s�����ȡ��ȡ��
//f����洢ÿ��ͼ��SGֵ
int s[N], f[M];

int sg (int x)
{
    //���仯����
    if (f[x] != -1) return f[x];
    
    //set�����Զ�������ÿ��ͼ��set����������ͬ
    set<int> S;
    for (int i = 0; i < k; i++)
    {
        int sum = s[i];
        //�Ȳ��ϵݹ鵽ͼ���յ㣬����ǰ����
        if (x >= sum) S.insert(sg(x - sum));
    }
    
    //��С����ѭ������ÿһ��ݹ��ж������ҳ������в����ڵ���С��
    for (int i = 0;; i++)
        if (!S.count(i)) 
        {
            f[x] = i;
            return f[x];
        }
}

int main ()
{
    cin >> k;
    for (int i = 0; i < k; i++) scanf("%d", &s[i]);
    cin >> n;
    
    memset(f, -1, sizeof(f));
    
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    
    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}