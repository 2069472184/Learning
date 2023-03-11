//https://www.acwing.com/problem/content/description/2060/

#include <iostream>
#include <unordered_set>

using namespace std;

const int M = 200;

string a, b;

int get (string k, int a)
{
    int res = 0;
    for (auto& p : k) res = (res * a) + p - '0';
    
    return res;
}

int main ()
{
    cin >> a >> b;
    int la = a.size();
    int lb = b.size();
    
    unordered_set<int> m;

    for (int i = 0; i < la; i++)
    {
        //�˴�Ҫ��a[0]���У����a[0]Ϊ0����ض�д����һλ
        //�����Ϊ0��Ҳ���ܸı�������Ϊ�Ϸ��Ķ�������û��ǰ��0
        if (i == 0 && la > 1)
            if (a[0] == '0') 
            {
                a[0] = '1';
                m.insert(get(a, 2));
                break;
            }
            else continue;
        
        a[i] ^= 1;
        m.insert(get(a, 2));
        a[i] ^= 1;
    }
    
    for (int i = 0; i < lb; i++)
    {
        char t = b[i];
        
        for (int j = 0; j <= 2; j++)
            if (t - '0' != j)
            {
                b[i] = j + '0';
                int x = get(b, 3);
                if (m.count(x))
                {
                    cout << x << endl;
                    return 0;
                }
                b[i] = t;
            }
    }
    
    return 0;
}