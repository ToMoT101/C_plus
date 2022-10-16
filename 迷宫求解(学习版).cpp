#include <stdio.h>   
#include <stdlib.h>   

#define OK      1   
#define ERROR   0   
#define TRUE    1   
#define FALSE   0   
#define STACK_INIT_SIZE 100   //��ʼջ�Ĵ�С
#define STACKINCREMENT 10     //���ݴ�С
#define COLUMN 10  //10��
#define ROW 10     //10�� 
typedef int Status;           //Status->int
//�Թ� 
typedef struct{
    char **maze;  
    int **footprint;
    int row;  
    int column;  
}MazeType;  
//����
typedef struct{  
    int x;  
    int y;  
}PosType;  
//·��
typedef struct{  
    int ord;       //��¼���� 
    PosType seat;  //����
    int di;        //����
}SElemType;  
//ջ  
typedef struct{   
    SElemType *base;  
    SElemType *top;  
    int stacksize;  
}SqStack; 

Status InitStack(SqStack* S);
Status InitMaze(MazeType* M);
Status DestroyStack(SqStack* S);
Status ClearStack(SqStack* S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType* e);
Status Push(SqStack* S, SElemType e);
Status Pop(SqStack* S, SElemType* e);
Status StackTraverse(const SqStack* S);
Status PrintMaze(MazeType* M);
Status MazePath(SqStack* S, MazeType maze, PosType start, PosType end);
Status FootPrint(MazeType* M, PosType pos);
Status Pass(MazeType* M, PosType pos);
SElemType NewSElem(int step, PosType pos, int d);
PosType NextPos(PosType pos, int d);
Status MarkPrint(MazeType* M, PosType pos);
Status PrintFoot(MazeType* M, SqStack* S);

//��ʼ����ջ 
Status InitStack(SqStack* S) {
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType)); //Ϊջ���ٿռ� 
    if (!S->base) //�ж��Ƿ񿪱ٳɹ�
    {
        printf("�����ڴ�ʧ��.\n");
        exit(0);
    }
    //��ʼ��ջ����ռ�׼�ջ�Ĵ�С
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
//��ʼ��maze 
Status InitMaze(MazeType* M) {
    int i, j;
    char mz[ROW][COLUMN] = {
        '#',' ','#','#','#','#','#','#','#','#',
        '#',' ','#','#','#','#',' ','#','#','#',
        '#',' ','#','#','#','#',' ',' ','#','#',
        '#',' ',' ','#','#','#','#',' ','#','#',
        '#','#',' ',' ','#',' ',' ',' ','#','#',
        '#','#',' ',' ','#',' ','#',' ','#','#',
        '#','#','#',' ','#',' ','#',' ','#','#',
        '#','#','#',' ',' ',' ','#',' ',' ','#',
        '#','#','#','#','#','#','#','#',' ',' ',
        '#','#','#','#','#','#','#','#','#','#'
    };
    //for(int i=0;i<ROW;i++)
    // { for(int j=0;j<COLUMN;j++)
    //        mz[i][j]=getchar();       
    //   char ch=getchar();         //�س�
    //}
    M->maze = (char**)malloc(sizeof(char*) * ROW);     //Ϊmaze���ٿռ�
    M->footprint = (int**)malloc(sizeof(int*) * ROW);  //Ϊmaze�Ľ⿪�ٿռ�
    //�жϿ��ٿռ��Ƿ�ɹ�
    if (!M->maze || !M->footprint) {
        printf("����ռ�ʧ��.\n");
        return ERROR;
        exit(0);
    }
    //Ϊmaze���к��зֱ𿪱ٿռ�
    for (i = 0; i < ROW; i++) {
        M->maze[i] = (char*)malloc(sizeof(char) * COLUMN);
        M->footprint[i] = (int*)malloc(sizeof(int) * COLUMN);
        if (!M->maze[i] || !M->footprint[i]) {
            printf("����ռ�ʧ��.\n");
            return ERROR;
            exit(0);
        }
    }
    //��ʼ��maze�����
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            M->maze[i][j] = mz[i][j];
            M->footprint[i][j] = 0;
        }
    }
    M->row = ROW;
    M->column = COLUMN;
    return OK;
}
//����ջ
Status DestroyStack(SqStack* S) {
    if (!S)
    {
        printf("ָ��Ϊ�գ��ͷ�ʧ��.\n");
        exit(0);
    }
    free(S);   
    return OK;
}
//���ջ
Status ClearStack(SqStack* S) {

    if (!S)
        return FALSE;
    S->top = S->base;
    return OK;
}
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S) {

    if (S.top == S.base)  //ջ��ָ��ջ�ף�˵��ջ����
        return TRUE;
    else
        return FALSE;
}
//���ջ�ĳ���
int StackLength(SqStack S) {
    return S.stacksize;
}
//��ȡջ��Ԫ��
Status GetTop(SqStack S, SElemType* e) {

    if (S.top == S.base) {
        printf("ջΪ��.\n");
        return FALSE;
    }
    else {
        *e = *(S.top - 1);
        printf("ջ��Ԫ�أ�%c\n", *e);
        return OK;
    }
}
//��ջ
Status Push(SqStack* S, SElemType e) {

    if (S->top - S->base >= S->stacksize) {
        S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base)
        {
            printf("��������ռ�ʧ��.\n");
            exit(0);
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}
//��ջ
Status Pop(SqStack* S, SElemType* e) {

    if (S->top == S->base) {
        printf("ջΪ��.\n");
        return ERROR;
    }
    *e = *(--S->top);
    return OK;
}
//����ջ
Status StackTraverse(const SqStack* S) {
    SElemType* p = S->base;
    if (S->base == S->top)
    {
        printf("ջΪ��.\n");
        return FALSE;
    }
    printf("ջ��Ԫ�أ�");
    while (p != S->top)
    {
        printf("x=%d,y=%d\n", p->seat.x, p->seat.y);
        *p++;
    }
    printf("\n");
    return OK;
}
// ��ӡmaze
Status PrintMaze(MazeType* M) {

    int i, j;
    for (i = 0; i < M->row; i++) {
        for (j = 0; j < M->column; j++) {
            printf("%c", M->maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return OK;
}
//�ж��Ƿ��н�
Status MazePath(SqStack* S, MazeType maze, PosType start, PosType end) {

    int curstep = 1;
    SElemType e;       
    PosType curpos = start;  //��ʼ����
    InitStack(S);            //��ʼ��ջ
    do {
        if (TRUE == Pass(&maze, curpos))   //��λ���ǽ�
        {
            FootPrint(&maze, curpos);      //����·��
            e = NewSElem(curstep, curpos, 1);  //����·��
            Push(S, e);  //��ջ
            if ((curpos.x == end.x) && (curpos.y == end.y)) {   //����·����
                printf("·��:\n");
                PrintFoot(&maze, S);   //��ӡ·��
                return TRUE;
            }
            curpos = NextPos(curpos, 1); //������һ��
            curstep++;   //����+1
        }
        else   //��λ�ò��ǽ�
        {
            if (!StackEmpty(*S))   //�ж��Ƿ�Ϊ��
            {
                Pop(S, &e);   //��ջ
                while (e.di == 4 && !StackEmpty(*S)) {   //��Χ��·����
                    MarkPrint(&maze, e.seat);       //��ǵ�ǰλ��
                    Pop(S, &e);   //��ջ
                }
                if (e.di < 4) {   //������̽·
                    e.di++;
                    Push(S, e);   //��ʱ����·��
                    curpos = NextPos(e.seat, e.di);  //����̽·
                }
            }
        }
   
    } while (!StackEmpty(*S));
    return FALSE;
}
//�������·��
Status FootPrint(MazeType* M, PosType pos) {
    if ((pos.x > M->row) || (pos.y > M->column)) //Խ��
        return FALSE;
    M->footprint[pos.x][pos.y] = 1;      //����·��
    return TRUE;
}
//�ж�λ�õ���ȷ�� 
Status Pass(MazeType* M, PosType pos) {
    //�ж��Ƿ񳬹��߽�
    if ((M->row < pos.x) || (M->column < pos.y)) {
        printf("λ��Խλ.\n");
        exit(0);
    }
    //�жϵ�ǰλ���Ƿ�Ϊ��
    if ((0 == M->footprint[pos.x][pos.y]) && (M->maze[pos.x][pos.y] == ' '))
        return TRUE;
    else
        return FALSE;
}
//·���ĸ���
SElemType NewSElem(int step, PosType pos, int d) {

    SElemType e;
    e.ord = step;
    e.seat = pos;
    e.di = d;
    return e;
}
//��һ��λ�õļ���
PosType NextPos(PosType pos, int d){
    switch (d) {
    case 1:
        pos.x++;   //����
        break;
    case 2:
        pos.y++;   //����
        break;
    case 3:
        pos.x--;   //����
        break;
    case 4:
        pos.y--;   //����
        break;
    default:
        printf("����.\n");
    }
    return pos;
}
//���·��
Status MarkPrint(MazeType* M, PosType pos) {
    if (pos.x > M->row || pos.y > M->column) {
        printf("λ��Խλ.\n");
        return ERROR;
    }
    M->footprint[pos.x][pos.y] = 1;
    return OK;
}
//��ӡ���·��
Status PrintFoot(MazeType* M, SqStack* S) {
    int i, j;
    SElemType* p;
    for (i = 0; i < M->row; i++) {      //��ʼ��·��
        for (j = 0; j < M->column; j++) {
            M->footprint[i][j] = 0;
        }
    }
    p = S->base;
    if (S->base == S->top)
    {
        printf("ջΪ��.\n");
        return FALSE;
    }
    while (p != S->top)   //������·��
    {
        M->footprint[p->seat.x][p->seat.y] = 1;
        *p++;
    }
    for (i = 0; i < M->row; i++) {   //��ӡ·��
        for (j = 0; j < M->column; j++) {
            printf("%d", M->footprint[i][j]);
        }
        printf("\n");
    }
    return OK;
}

int main()  
{  
    MazeType maze;  
    SqStack stack;  
    PosType start,end;  
    start.x=0;start.y=1;    //��ʼ����(0,1)
    end.x=8;end.y=9;        //��������(8,9)
    InitMaze(&maze);        //��ʼ��maze
    printf("��״��\n");  
    PrintMaze(&maze);       //��ӡmaze
    if(TRUE==MazePath(&stack,maze,start,end))  //�ж�maze�Ƿ��н�  
        printf("�ɽ�.\n");  
    else  
        printf("���ɽ�.\n");  
    return 0;  
}  
