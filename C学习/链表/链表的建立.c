#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
    long int num;
    char name[20];
    struct Node *next;
}N;

N *create ( N *head ) 
{
    //���������½ڵ�
    N *newcode = ( N * )malloc( sizeof(N) );
    scanf( "%ld %s", &newcode->num, &newcode->name );
    newcode->next = NULL;

    //���帨���ṹ��ָ��
    N *box;
    head = newcode;  //ִ���������head���൱��newcode���ڳ�Ա��ɺʹ�С�ϣ�
    box = newcode;   //����һ���ṹ��ָ����ʵ���������������ָ��Ҳ�൱��newcode���ڳ�Ա��ɺʹ�С�ϣ�

    //ͨ��boxʵ����������
    while ( newcode->num ) {
        newcode->next = NULL;    //newcodeʼ����һ�����ڵ�
        box->next = newcode;     //����һ���ڵ�ĵ�ַ����box->next      
        box = box->next;         //��boxָ��ڵ����                   
        newcode = ( N * )malloc( sizeof(N) );                         
        scanf( "%ld %s", &newcode->num, &newcode->name );
    }
    /*��һ�μ���ѭ����ʱ��box->next = newcodeִ����head->next��box->next�ĵ�ַ���͵�һ��newcode�ĵ�ַ��ͬ��
    �����ڴ�����ռ��newcode�ĵ�ַ������һ��sizeof(N),�漴����ڶ���ѭ����һ����ڶ���ѭ�����½ڵ�newcode��
    ָ���ָ��NULL����ʱhead->next��box->next�ĵ�ַ��ͬ��ִ��box->next = newcode���ַҲ������sizeof(N),��ִ
    ��box = box->next����Ϊ��box��ָ�ṹ���ڲ���Ա��ַת�������Բ�Ӱ��head��head->next��ָ��.����֮��head��
    head->next�ĵ�ַ�Ͳ��ᶯ�ˣ�headָ��newcode����ڵ�ĵ�ַ��head->nextָ��ڶ���newcode�ڵ�ĵ�ַ����n��ѭ
    ����box��ָ�ṹ��������n���ڵ㣬��head��ָ�ṹ���box��ָ����ͬ���ʿ�����head����ͷ���ÿ���ڵ�����ݡ�*/

    //free��numΪ0�Ľṹ����ռ�ռ�
    free( newcode );

    //����head����ʱhead����ָ���һ���ڵ㣬��������֮�����кö�����ӵĽڵ�
    return head;
}

void print ( N *head )
{
    N *p = head;
    while ( p ) {
        printf( "%ld\t%s\n", p->num, p->name );
        p = p->next;
    }
}

int main ( int argc, char *argv[] )
{
    N *head = NULL;
    head = create( head );
    printf( "�������б���ǣ�\n");
    print( head );
    return 0;
}