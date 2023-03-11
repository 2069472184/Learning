//https://www.acwing.com/problem/content/description/3488/

//��������+Trie��
#include <iostream>

using namespace std;

const int N = 100010, M = 3100010;

int n, m, a[N];
//cnt����洢��ǰ�ڵ��±���ֵĴ���
//�ڴ����г��ֵ�cntֵһ����Ϊ0
int son[M][2], idx, cnt[M];
int ans;

void insert (int x, int v)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = x >> i & 1;
        if (!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
        cnt[p] += v;
    }
}

int search (int x)
{
    int p = 0;
    
    int num = 0;
    for (int i = 30; i >= 0; i--)
    {
        int t = x >> i & 1;
        //�����ǰ�����д��ڵ�ǰλ��ͬ����
        if (cnt[son[p][!t]])
        {
            p = son[p][!t];
            //�����ǰλ��ͬ��˵���������õ�1
            //num����ʵ�ֳ˶���+1 ˵����λ�����Ϊ1
            num = (num << 1) + 1;
        }
        else
        {
            p = son[p][t];
            //�����ǰλ��ͬ����ֻ��Ҫ����һλ���³��ֵ�һλ������0
            num <<= 1;
        }
    }
    
    return num;
}

int main ()
{
    //��Ŀ����һ������Ϊ m �Ļ�������
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    
    //�ڶ������� 1 ��ʾ���룬-1 ��ʾɾ��
    insert(a[0], 1);
    //�ӵ�һ������ʼ������Ѱ������Ϊ�Ҷ˵�Ļ����������������ֵ������
    for (int i = 1; i <= n; i++)
    {
        //�����������п�ȣ��򽫳�������ɾ��
        if (i - m - 1 >= 0) insert(a[i - m - 1], -1);
        ans = max(ans, search(a[i]));
        //���³��ֵ����ʹ����е�ĳ�����ֽ���������֮��
        //Ҫ���������봰����
        insert(a[i], 1);
    }
            
    cout << ans << endl;
    
    return 0;
}