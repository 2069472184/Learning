//https://www.acwing.com/problem/content/3959/

#include <iostream>

using namespace std;

const int N = 100010;
typedef long long ll;
typedef unsigned long long ull;

int n, a[N];
long long cnt, res;

int main ()
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) 
    {
        cin >> a[i];
        a[i] += a[i-1];
    }

    if ( n < 3 || a[n] % 3 ) 
    {
        cout << 0;
        return 0;
    }

    int q = a[n] / 3;

    for ( int i = 3; i <= n; i++ )
    {
        if ( a[i - 2] == q ) cnt++;
        if ( a[n] - a[i-1] == q ) res += cnt;
    }
        
    cout << res;

    return 0;
}