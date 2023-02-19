//https://www.acwing.com/problem/content/805/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

vector<PII> item, res;

int main ()
{
    int n;
    cin >> n;
    
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        
        item.push_back({l, r});
    }
    
    //�˴������Զ�����߽���ұ߽簴���ֵ�������
    sort(item.begin(), item.end());
    
    //ע�⣬�˴���ʼ�б߽�Ҳ������Ϊ����С���������max����
    //���������ʼ��߽������ΪС��-1e9����
    int lb = -2e9, rb = -2e9;
    for (auto k : item)
    {
        if (rb < k.first) 
        {
            if (lb != -2e9) res.push_back({lb, rb});
            lb = k.first, rb = k.second;
        }
        else rb = max(rb, k.second);
    }
    
    //�˴�if�жϵ�������ѹ�����һ�����䣬���Ƿ�ֹnΪ0����[-2e9, -2e9]ѹ��res������
    if (lb != -2e9) res.push_back({lb, rb});
    
    cout << res.size() << endl;
     
    return 0;
}
