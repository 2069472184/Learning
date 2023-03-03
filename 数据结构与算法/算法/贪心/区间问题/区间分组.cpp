//https://www.acwing.com/problem/content/908/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

struct Range
{
    int l, r;
    
    bool operator< (const Range &k)const
    {
        return l < k.l;
    }
}range[N];

int main ()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        range[i] = {a, b};
    }
    
    sort(range, range + n);
    
    //С���Ѵ洢ÿ����������Ҷ˵�
    //�������������鰴���Ҷ˵��С��������
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for (int i = 0; i < n; i++)
    {
        int a = range[i].l, b = range[i].r;
        
        //����Ѷ���������������н�������ô�½�һ��������
        if (heap.empty() || heap.top() >= a) heap.push(b);
        else 
        {
            //���û�н�������ôֱ�Ӹ��¶���������Ҷ˵�
            heap.pop();
            heap.push(b);
        }
    }
    
    cout << heap.size() << endl;
    
    return 0;
}