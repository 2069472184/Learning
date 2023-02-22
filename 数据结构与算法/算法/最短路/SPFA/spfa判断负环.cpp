//https://www.acwing.com/problem/content/description/854/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N];
int st[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa ()
{
    //�����½���һ������Դ�㣬���е㵽���Դ��ľ��붼��0��
    //����������ͼ�ĸ������������������Ӱ��
    //������ֻ����Ҫһ��dist�����½������ƣ�����������ƣ���ʹcnt+1
    //memset(dist, 0x3f, sizeof(dist));
    //dist[1] = 0;
    //��ʵҲ����дΪ��
    memset(dist, 0, sizeof(dist));
    dist[0] = 0; //����ûɶ����
    
    queue<int> q;
    q.push(0);
    
    //��Ϊ���ǲ�ȷ���ǲ����в���ͨ�ĵ㣬
    //���������ڽ�����ڵ�������к���Ҫ�����е㶼���������
    for ( int i = 1; i <= n; i++ )
    {
        st[i] = true;
        q.push(i);
    }
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        //��Ϊ���ڸ���������û�б������ƣ�����������ڸ���
        //һ���ᵼ��cnt > n�������Դ�Ϊ�ж�����
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if (cnt[j] > n) return true;
                
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return false;    
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    } 
    
    if (spfa()) puts("Yes");
    else puts("No");
     
    return 0;
}

/*һ��С�Ż���Ϊ�˸�����ø����е�ĳ����� cnt �ﵽ n + 1��
����һ�ǿ��Բ�ʹ��st���飬���������ö����кܿ���������ڸ����еĵ�
����Щ�����ȱ����Ϳ��Խ�ʡʱ�䣻���ǿ�����ջ���洢*/

//ջ��st�����Ż�
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;
const int N = 2010, M = 10010;

int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N];
int st[N];

void add (int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa ()
{
    stack<int> s;
    for ( int i = 0; i <= n; i++ ) s.push(i);
    
    while (s.size())
    {
        int t = s.top();
        s.pop();
        
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                
                if (cnt[j] > n) return true;
                
                s.push(j);
            }
        }
    }
    
    return false;    
}

int main ()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof(h));
    
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    } 
    
    if (spfa()) puts("Yes");
    else puts("No");
     
    return 0;
}