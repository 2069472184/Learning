//https://www.acwing.com/problem/content/833/

//STL --- 15/16 --- TLE
/* #include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int n, m;
string a, b;
int num[N], tem, count;

int main ()
{
    cin >> n >> a >> m >> b;

    while ( b.find(a) >= 0 && b.find(a) < b.size() )
    {
        num[++count] = tem + b.find(a);
        tem += b.find(a)+1;
        b = b.substr(b.find(a)+1);
    }
    
    for ( int i = 1; i <= count; i++ ) cout << num[i] << ' ';
    
    return 0;
}
 */
//KMP�㷨
/*
KMP�㷨���൱��һ���ò��ķ��������Ӵ���ĸ��ƥ�䵽������ƥ��ʱ��������������ֱ������ƶ�һλ��
���Ǻܶ�ʱ���ǲ���Ҫһλһά���ƶ��ģ�ֻ��Ҫ�ҵ��Ӵ�[1,j]�ϵ�һ������[1,k] = [j-k+1,j]�ĵ�k����,ne[j] = k
���k������һ������˺�ĸ��ƥ��ĵ㣬֮����������ж�k+1�Ƿ��ĸ����Ӧλ��ƥ�䡣
*/
//�±�Ϊ1
#include <iostream>
using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    //��p�ַ�����next���飬ʵ���Ͼ����Ӵ��Լ����Լ�ƥ��Ĺ��� 
    //i����p����2��ʼ�����г��������j��λ�þ���ÿ�����������Ӧ�Ĳ���ƥ��ֵ��Ҳ����next�����Ԫ��ֵ
    for (int i = 2, j = 0; i <= n; i ++ ) 
    {
        //�����ǰλ�ò�ƥ����j��Ϊ0���������Ӵ���ǰ��j��ne[j]��
        while (j && p[i] != p[j + 1]) j = ne[j];

        //�����ǰλ��ƥ�䣬�����j
        if (p[i] == p[j + 1]) j ++ ;

        //�����Ӵ���ÿ�����ȵ����Ӵ�����Ҫ�洢һ������ƥ��ֵ
        ne[i] = j;
    }

    //KMPƥ�����
    for (int i = 1, j = 0; i <= m; i ++ )
    {
        //�����ʱj+1��ĸ��ʧ���ˣ����Ӵ����ƣ�j��Ϊ����ߵ�ne[j]��һֱѭ��ֱ��j+1�ܹ��ɹ�ƥ��
        while (j && s[i] != p[j + 1]) j = ne[j];

        //���j+1�ܹ��ɹ�ƥ��,�������Ӵ�ƥ�䳤�ȵ�j+1
        if (s[i] == p[j + 1]) j ++ ;

        //������ƺ����ִ�ƥ�䳤�ȵ����ִ����ȣ���˵����ȫƥ�䣬�����������ִ��������Ƶ���һ������ƥ���λ��
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}

//�±�Ϊ0�����Ƽ�
/* #include <iostream>
using namespace std;

const int M = 100010;

string a, b;
int n, m;
int ne[M];

int main ()
{   
    cin >> n >> a >> m >> b;

    ne[0] = -1;
    for ( int i = 1, j = -1; i < n; i++ )
    {
        while ( j >= 0 && a[i] != a[j+1] ) j = ne[j];
        if ( a[i] == a[j+1] ) j++;
        ne[i] = j;
    } 

    for ( int i = 0, j = -1; i < m; i++ )
    {
        while ( j != -1 && b[i] != a[j+1] ) j = ne[j];
        if ( b[i] == a[j+1] ) j++;
        if ( j + 1 == n )
        {
            cout << i - n + 1 << ' ';
            j = ne[j];
        }
    }

    return 0;
} */