//https://www.acwing.com/problem/content/127/

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 50010;

PII com[N];

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int w, s;
        scanf("%d%d", &w, &s);
        com[i] = {w + s, w};
    }
    
    sort(com, com + n);
    
    //sum�洢��ǰ��ţ�Ϸ�����ţ������֮��
    //res�洢������ֵ��̰���㷨ʹ�������С
    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int w = com[i].second, s = com[i].first - w;
        res = max(res, sum - s);
        //����sum
        sum += w;
    }
    
    cout << res << endl;
    
    return 0;
}