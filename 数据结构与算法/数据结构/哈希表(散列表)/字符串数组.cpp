//https://www.acwing.com/problem/content/843/

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

const int N = 100010, P = 131;
typedef unsigned long long ull;

int n, m;
string str;
//p����洢��Ӧǰ׺����p�Ĵ��ݣ�ǰ׺����Ϊ1��PΪ1����
ull h[N], p[N];
int x, y, a, b;

int main ()
{
    cin >> n >> m >> str;

    str = ' ' + str;

    p[0] = 1;

    for ( int i = 1; i <= n; i++ )
    {
        p[i] = p[i-1] * P;  
        h[i] = h[i-1] * P + str[i]; //ֱ����ASCII��ֵ��ʾp������
    }

    while ( m-- )
    {
        cin >> x >> y >> a >> b;
        ull ans = h[y] - h[x-1] * p[y-x+1];
        ull res = h[b] - h[a-1] * p[b-a+1];
        if ( ans == res ) puts("Yes");
        else puts("No");
    }

    return 0;
}