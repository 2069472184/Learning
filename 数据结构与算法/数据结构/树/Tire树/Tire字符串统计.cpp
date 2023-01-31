//https://www.acwing.com/problem/content/837/

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <bitset>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
using namespace std;

const int N = 100010;
typedef long long ll;
typedef unsigned long long ull;

int n;
char h[2], str[N];

//son[i][26]��ʾ�ڵ�i�Ķ��������son[i][3] = k ��ʾ�ڵ�i�ж���'d'���ö��ӵĽڵ���Ϊk��
//���Ե�����Ҫȥ���ö��ӽڵ�Ķ���ʱ���Ϳ����� son[k][] ȥ�ж�
//����˵��son�����һά���ִ洢����һ���ɽڵ��±깹�ɵ�����ÿ���ڵ���ӵĲ�ͬѡ�񶼻��Ӧһ����ͬ��nextָ�룬ָ��ͬ�����ӽڵ�
//cnt�洢�ж��ٸ��Ըýڵ�Ϊĩβ���ַ������൱�ڱ�ǣ�idxΪ�±꣬��ʾ���洢�˶����ַ���Ҳ�൱�����еĽڵ��±�
//���ڵ��û���ӽڵ�Ľڵ��±궼Ϊ0
int son[N][26], cnt[N], idx;

void insert ( char *str )
{
    int p = 0;
    for ( int i = 0; str[i]; i++ )
    {
        //����ǰ�ַ������ֱ�������
        int u = str[i] - 'a';
        //�ж������Ƿ���ڱ��Ϊu�Ķ��ӣ����û�У����Լ�����һ��
        if ( !son[p][u] ) son[p][u] = ++idx;
        //��pָ�����Ƶ����ӽڵ���
        p = son[p][u];
    }

    //���p��λ�þ��Ǹ��ַ�����ĩβ�ַ���λ�ã����ǽ���λ�õı�Ǽ�1
    cnt[p]++;
}

int query ( char *str )
{
    int p = 0;
    for ( int i = 0; str[i]; i++ )
    {
        int u = str[i] - 'a';
        if ( !son[p][u] ) return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main ()
{   
    cin >> n;
    
    while ( n-- )
    {
        cin >> h >> str;
        if ( h[0] == 'I' ) insert(str);
        else cout << query(str) << endl;
    }

    return 0;
}