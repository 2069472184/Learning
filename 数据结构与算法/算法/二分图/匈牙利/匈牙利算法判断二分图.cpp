//https://www.acwing.com/problem/content/863/

#include <iostream>
#include <cstring>

using namespace std;
const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
/*
st��������ã�
����˵�������Ǳ�������kʱ����kϲ��Ůs��
���ǿ�������st[s] = true����ʾŮs�Ѿ�����kԤ����
����Ůs�Ѿ�����jѡ���ˣ�����û��ϵ������ͨ��find(match[s])
��������ȥ��һ�����Ƿ���j����������ѡ����Ϊ��ʱst[s]Ϊ��
����Ůs�����ٱ���jѡ�У���jֻ��ѡ������ϲ����δ��Ԥ����Ů��
�����j����������������Ů��������һ�鷢�ֻ��ǲ�����ԣ�
��ô���ǲ��ı���j��Ůs��ƥ���������kֻ�ܹ¶�һ���ˡ�
*/
bool st[N];
//match[i] = j��ʾ��ǰŮi����j���
int match[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find (int x)
{
    //��������Ů��
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        //�������ϲ����Ů��
        if (!st[j])
        {
            //�Ƚ���Ů��Ԥ��
            st[j] = true;
            //�鿴�Ƿ��Ů����ǰû���˰����ǰ������˻��ܰ�������
            if (match[j] == 0 || find(match[j]))
            {
                //������ԣ���ô����λŮ���ø���x
                match[j] = x;
                return true;
            }
        }
    }

    //�������Ů�����޷�����x��ԣ���ô��x�͹¶�һ��
    return false;
}

int main ()
{
    cin >> n1 >> n2 >> m;

    memset(h, -1, sizeof(h));

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }

    int res = 0;
    //������������
    for (int i = 1; i <= n1; i++)
    {
        //�˴�һ��Ҫ��ʼ��st����
        //��Ϊÿһ����Ů���ѵ�Ԥ������ǲ�һ����
        memset(st, false, sizeof(st));
        if (find(i)) res++;
    }

    cout << res;

    return 0;
}