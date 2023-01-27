//����������
#ifndef _ARRAY_H_
#define _ARRAY_H_

//����Array�ṹ��
typedef struct{
    int *array;   //��������ָ��  
    int size;                                
}Array;  //�˴�������ֱ�Ӷ���ָ��

Array array_create(int init_size);  //����һ������
void array_free(Array *a);   //������ռ����
int array_size(const Array *a);   //��֪�����л��ж��ٵ�Ԫ������
int* array_at(Array *a,int index);  //���������е�ĳ����Ԫ
void array_inflate(Array *a,int more_size);  //�����鳤��

#endif