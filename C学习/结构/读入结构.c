//�����ṹ����
/*#include<stdio.h>

struct point{
    int x;
    int y;
};

struct point getStruct(void);
void output(struct point);

int main(){
    struct point y={0,0};
    y=getStruct();
    output(y);
}

struct point getStruct(void){
    struct point p;
    scanf("%d",&p.x);
    scanf("%d",&p.y);
    printf("%d,%d\n",p.x,p.y);
    return p;
}

void output(struct point p){
    printf("%d,%d",p.x,p.y);
}*/

//ָ�뷽��
#include<stdio.h>

struct point{
    int x;
    int y;
};

struct point* getStruct(struct point *);
void output(struct point);
void print(const struct point *p);

int main(){
    struct point y={0,0};
    //��һ�����������ʽ
    getStruct(&y);
    output(y);       
    //�ڶ������������ʽ 
    output(*getStruct(&y));  //����*getStruct(&y)����һ����������������д��*getStruct(&y)=(struct point){1,2}
    //���������������ʽ
    print(getStruct(&y));
    return 0;
}

struct point* getStruct(struct point *p){
    scanf("%d",&p->x);
    scanf("%d",&p->y);
    printf("%d,%d\n",p->x,p->y);
    return p;
}

void output(struct point p){
    printf("%d,%d\n",p.x,p.y);
}

void print(const struct point *p){
    printf("%d,%d\n",p->x,p->y);
}