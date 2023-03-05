//https://www.acwing.com/problem/content/842/

//��ϣ�������ڶ�����������ʾ��

//������
//��Ӧ˼����2022�����ű�ʡ��C����λ����
#include<stdio.h>
#include<string.h>
#define N 100003   //ȡģ�����ڷ�Χ�ĵ�һ�����������鳤��������ͬ

int h[N], e[N], ne[N], idx;  
int n, x;
char c[2];

void insert ( int x )
{
    int k = ( x % N + N ) % N;   //��֤����������
    e[idx] = x;     
    ne[idx] = h[k];  
    h[k] = idx;    
    idx++;
}

int find ( int x )
{
    int k = ( x % N + N ) % N;
    for ( int i = h[k]; i != -1; i = ne[i] )   
        if ( e[i] == x )
            return 1;

    return 0;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );
    memset( h, -1, sizeof(h) );    

    while ( n-- )
    {
        scanf( "%s%d", &c, &x );
        if ( c[0] == 'I' ) insert( x );
        else 
        {
            if ( find( x ) ) puts( "Yes" );
            else puts( "No" );
        }
    }

    return 0;   
}

//����Ѱַ��
#include<stdio.h>
#include<string.h>
#define N 200003       //���鳤��Ҫ��Ϊ���ݷ�Χ��2~3����Ϊ�����������ģ��������ͬ
#define null 0x3f3f3f3f   //�涨�����λ��Ϊһ������10^9�����ĸ��ֽ���ͬ�����ֽ����������������null==x�����

int h[N];  //�洢ȡģ���ֵ
int n, x;
char c[2];

int find ( int x )
{
    int k = ( x % N + N ) % N;

    //����ѭ����������ʾ���˵��ģ��Ϊk���±괦�Ѿ���ԭ��ֵ��ţ�������������֪�����ֿ�λ��
    //�� h[k] != null �����ڴ�Ų����ĵ�ַѡȡ
    //�� h[k] != x �����ڲ��Ҳ����ĵ�ַѡȡ
    while ( h[k] != null && h[k] != x )  
    {
        //����һ��ȡģ��������Ϊk��������ֻ��һ���±���֮��Ӧ����k������ŵ�һ��ȡģΪk��������
        //������ֳ�ͻ������Ҫ��k+1�����±�k+1��ŵľ��ǵڶ���ȡģΪk����
        k++;       
        if ( k == N ) k = 0;   //�����ڻ�״���飬k�Ĵ洢�ǿ��Կ�Խ��β�Դﵽ�����洢��Ŀ��
    }

    return k;
}

int main ( int argc, char *argv[] )
{
    scanf( "%d", &n );

    memset( h, 0x3f, sizeof(h) );   //���ĩβ����

    while ( n-- ) 
    {
        scanf( "%s%ld", &c, &x );
        if ( c[0] == 'I' ) h[find(x)] = x;
        else 
        {
            if ( h[find(x)] == null ) puts( "No" );
            else puts( "Yes" );
        }
    }

    return 0;
}
/*
const int null = 0x3f3f3f3f ��  memset(h, 0x3f, sizeof h)֮��Ĺ�ϵ��
���ȣ�����Ҫ���memset������������ι�����
�ȿ���һ�����⣬Ϊʲômemset��ʼ����ѭ�����죿
�𰸣�memset���죬Ϊʲô����Ϊmemset��ֱ�Ӷ��ڴ���в�����memset�ǰ��ֽڣ�byte�����и��Ƶ�

void * memset(void *_Dst,int _Val,size_t _Size);
����memset�ĺ�������
��һ������Ϊһ��ָ�룬��Ҫ���г�ʼ�����׵�ַ
�ڶ��������ǳ�ʼ��ֵ��ע�⣬������ֱ�Ӱ����ֵ����һ�����鵥Ԫ����int��˵����������
������������Ҫ��ʼ���׵�ַ����ٸ��ֽ�
h��int���ͣ���Ϊ4���ֽڣ� �ڶ�������0x3f��λΪһ���ֽڣ�����0x3f * 4(�Ӹߵ��͸���4��) = 0x3f3f3f3f

��Ҳ˵����Ϊʲô��memset�в����ó���-1�� 0���ⳣ����ֵ������������Ϊ*4֮��͸ı���ֵ
0��*4��ֵ����ܺ���⣻-1�Ĳ�����11111111��*4��32λ����1��ת��Ϊԭ�����-1
�����������������
����1, �ֽڱ�ʾΪ00000001��memset(h, 1, 4)���ʾΪ0x01010101


Ϊʲô����Ϊ0x7fffffff��32��1����
������������ÿ���ֽڶ���ͬ����Σ�������ӷ��Ļ������������ֵ���磬��ɸ�ֵ��
�ٴΣ���Ȼ���ܴ󣬵�Ҳ��0x3f3f3f3fһ��������
*/