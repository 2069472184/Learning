//https://www.acwing.com/problem/content/847/

//�ѵ�����δ���״̬��ʾ��stringչ��
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

string start;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

queue<string> q;
unordered_map<string, int> d;

int bfs (string state)
{
    q.push(state);
    //d[state] = 0;
    
    string end = "12345678x";
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        
        if (t== end) return d[t];
        
        //�˴��洢ԭ״̬�µľ��룬��������������������ʹ��
        int distance = d[t];
        
        //���ַ����е�λ��ת��Ϊ��ά����
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        
        for ( int i = 0; i < 4; i++ )
        {
            int a = x + dx[i], b = y + dy[i];
            
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a*3 + b], t[k]);
                //������������û�б����۹�������º�����Ӧ�ľ��룬�ٽ����������
                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                //����һ��Ҫ��ԭ״̬����Ϊ���ܻ�����������״̬
                swap(t[a*3 + b], t[k]);
            }
        }
    }
    
    return -1;
}

int main ()
{
    for ( int i = 0; i < 9; i++ )
    {
        char c;
        cin >> c;
        start += c;
    }
        
    cout << bfs(start) << endl;
    
    return 0;
}