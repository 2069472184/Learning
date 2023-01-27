//https://www.acwing.com/problem/content/4656/

//��λ��С����ǰ����λ�����ʱ��ֵС����ǰ

//C�������ƣ������޷������ܺõ��Ż�����50%����
/* #include<stdio.h>
#define N 1000010

long n, m;
long sum[N], w[N];

int main ( int argc, char *argv[] )
{   
    scanf( "%ld", &n );
    getchar();
    scanf( "%ld", &m );
    getchar();

    for ( long i = 1; i <= n; i++ )
    {
        w[i] = i;
        long box = i;
        while ( box )
        {
            sum[i] += box % 10;
            box /= 10;
        } 
    }

    for ( int i = 1; i < n; i++ )   
        for ( int j = i + 1; j <= n; j++ )
        {
            if ( sum[i] > sum[j] )
            {
                long box = sum[i];
                sum[i] = sum[j];
                sum[j] = box;
                box = w[i];
                w[i] = w[j];
                w[j] = box;
            }
            if ( sum[i] == sum[j] && w[i] > w[j] )
            {
                long box = sum[i];
                sum[i] = sum[j];
                sum[j] = box;
                box = w[i];
                w[i] = w[j];
                w[j] = box;
            }
        }

    printf( "%ld\n", w[m] );

    return 0;
} */

//�������Ż�(�����ڹ�ϣ��)
#include<stdio.h>
#include<string.h>
#define N 1000010

int head[N], e[N], ne[N], idx;   //�˴���head[N]��ʾһ��������������һ���ڵ��±������
int num[N], count;
int n, m;

//ÿһ����λ�ͣ�key����������һ������
//��������ԭ��ֵ��value���Ӵ�С��˳�����ģ������ڱ�����ʱ��ԭ��ֵС���ȱ�����
void add ( int key, int value )   
{
    e[idx] = value;
    ne[idx] = head[key];
    head[key] = idx;
    idx++;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d%d", &n, &m );
    memset( h, -1, sizeof(h) );  //��ʼ�����е�ͷ�ڵ�ָ��

    //�˴�ѭ���ķ�ʽ�;�����ÿ����λ�Ͷ�Ӧ�������дӵ�һ���ڵ㿪ʼԭ��ֵ��С�������е�˳��
    for ( int i = n; i >= 1; i-- )  
    {
        int box = i;
        int sum = 0;   //sum��ʾ��i��λ����
        while ( box )
        {
            sum += box % 10;
            box /= 10;
        }
        add( sum, i );
    }

    for ( int i = 1; i <= n; i++ )   //������λ��
        for ( int j = head[i]; j != -1; j = ne[j] )  //����ÿ�������еĽڵ�
            num[++count] = e[j];

    printf( "%d\n", num[m] );

    return 0;
}