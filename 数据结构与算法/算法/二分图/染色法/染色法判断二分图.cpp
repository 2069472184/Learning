//https://www.acwing.com/problem/content/description/862/

//dfs��
#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010, M = 2*N;  
//�˴�һ��Ҫ��2����e�����ne���飬��Ϊ�������Ҫ����ͬʱ�洢��������

int n, m;
int h[N], e[M], ne[M], idx;
//color����1��2��ʾ������ɫ
int color[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs (int u, int c)
{
    //����Ⱦɫ
    color[u] = c;
    
    //������u�������ͨ�ĵ㲢��δȾɫ�ĵ�Ⱦɫ
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        //�ж��Ƿ��ѱ�Ⱦɫ
        //����ǣ����ж��Ƿ����ɫ�����u����ɫ�������
        //������أ���˵��ì�ܣ�����false
        //������ǣ���Ⱦɫ3 - c�ı�ţ������ݹ�
        //���ң������һ��ݹ鷵���������Ǹ�ֵ����Ҳ���ظ�ֵ
        if (!color[j])
        {
            //�ж�j�����ͨ�����Ƿ����ì�ܣ�ͬʱδȾɫ��Ⱦɫ
            if (!dfs(j, 3 - c)) return false;
        }
        else if (color[j] == c) return false;
    }
    
    return true;
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    //�������е㣬���ûȾɫ����Ⱦɫ������ͳһ�ӱ��1��ʼȾɫ
    //��Ϊ��������û�б�Ⱦɫ����ô���϶���ǰ������ĵ�
    //������ͨ�鲻��ͨ������ֱ�Ӵ�1 �� 2��ʼȾɫ����
    for (int i = 1; i <= n; i++)
        if (!color[i])
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
    
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}

//bfs��
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 100010, M = 2*N;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add (int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool bfs (int u)
{
    queue<int> q;
    q.push(u);
    color[u] = 1;
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!color[j])
            {
                color[j] = 3 - color[t];
                q.push(j);
            }
            else if (color[j] == color[t]) return false;
        }
    }
    
    return true;
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    
    bool flag = true;
    
    for (int i = 1; i <= n; i++)
        if (!color[i] && !bfs(i))
        {    
            flag = false;
            break;
        }
            
    if (flag) puts("Yes");
    else puts("No");
    
    return 0;
}