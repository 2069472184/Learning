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

//��ɢ��
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int b[2 * N], idx;

int main ()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        //��˵�洢Ϊż�����Ҷ˵�洢Ϊ����
        b[idx++] = l * 2;
        b[idx++] = r * 2 + 1;
    }
    
    sort(b, b + idx);
    
    //res�洢��������Ҳ���������������ͬʱ���еĻ�������ֵ
    //���ʱ�̶�Ӧ�Ľ���������������Ҫ�Ľ�����
    int res = -0x3f3f3f3f, t = 0;
    for (int i = 0; i < idx; i++)
    {
        //���������˵㣬����+1�����������㣬����-1
        //����Ѱ�ҵ�ǰ�����������ֵ�������
        if (b[i] % 2 == 0) t++;
        else t--;
        res = max(res, t);
    }
    
    cout << res << endl;
    
    return 0;
}