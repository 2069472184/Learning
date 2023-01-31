//https://www.acwing.com/problem/content/145/

//��ÿ����ת��Ϊ31λ�������������Ϊ2^32-1 = 0111 1111 1111 1111 1111 1111 1111 1111B
//Ϊ�˱�֤������������������Ҫ�Ӹ�λ(31λ)��ʼ���������Ķ�����λҪ������ͬ
#include <iostream>
using namespace std;

const int N = 3100010;

int n, x[N], ans;

//son�Ķ�ά����ֻ�洢0��1
//ע�⣬ÿ�������������31λ�����ҴӸ�λ���λ�洢
int son[N][2], idx;

void insert ( int u )
{
    int p = 0;
    for ( int i = 30; i >= 0; i-- )
    {
        int k = u >> i & 1;
        if ( !son[p][k] ) son[p][k] = ++idx;
        p = son[p][k];
    }
}

int Search ( int u )
{
    int p = 0, num = 0;
    for ( int i = 30; i >= 0; i-- )
    {
        int k = u >> i & 1;
        if ( !son[p][!k] ) 
        {
            p = son[p][k];
            num += k << i;  //���Ʋ������滻2���ݼ�����ʽ
        }
        else 
        {
            p = son[p][!k];
            num += !k << i;
        }        
    }
    return num;
}

int main ()
{       
    cin >> n;
    for( int i = 0; i < n; i++ ) 
    {
        cin >> x[i];
        insert(x[i]);
    }

    for ( int i = 0; i < n; i++ )
    {
        int k = Search(x[i]);
        ans = max( ans, k ^ x[i] );
    }

    cout << ans;

    return 0;
}