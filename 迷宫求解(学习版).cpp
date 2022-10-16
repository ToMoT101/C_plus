#include <stdio.h>   
#include <stdlib.h>   

#define OK      1   
#define ERROR   0   
#define TRUE    1   
#define FALSE   0   
#define STACK_INIT_SIZE 100   //初始栈的大小
#define STACKINCREMENT 10     //扩容大小
#define COLUMN 10  //10行
#define ROW 10     //10列 
typedef int Status;           //Status->int
//迷宫 
typedef struct{
    char **maze;  
    int **footprint;
    int row;  
    int column;  
}MazeType;  
//坐标
typedef struct{  
    int x;  
    int y;  
}PosType;  
//路径
typedef struct{  
    int ord;       //记录步数 
    PosType seat;  //坐标
    int di;        //方向
}SElemType;  
//栈  
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

//初始化空栈 
Status InitStack(SqStack* S) {
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType)); //为栈开辟空间 
    if (!S->base) //判断是否开辟成功
    {
        printf("分配内存失败.\n");
        exit(0);
    }
    //初始化栈顶和占底及栈的大小
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}
//初始化maze 
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
    //   char ch=getchar();         //回车
    //}
    M->maze = (char**)malloc(sizeof(char*) * ROW);     //为maze开辟空间
    M->footprint = (int**)malloc(sizeof(int*) * ROW);  //为maze的解开辟空间
    //判断开辟空间是否成功
    if (!M->maze || !M->footprint) {
        printf("申请空间失败.\n");
        return ERROR;
        exit(0);
    }
    //为maze的行和列分别开辟空间
    for (i = 0; i < ROW; i++) {
        M->maze[i] = (char*)malloc(sizeof(char) * COLUMN);
        M->footprint[i] = (int*)malloc(sizeof(int) * COLUMN);
        if (!M->maze[i] || !M->footprint[i]) {
            printf("申请空间失败.\n");
            return ERROR;
            exit(0);
        }
    }
    //初始化maze及其解
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
//销毁栈
Status DestroyStack(SqStack* S) {
    if (!S)
    {
        printf("指针为空，释放失败.\n");
        exit(0);
    }
    free(S);   
    return OK;
}
//清空栈
Status ClearStack(SqStack* S) {

    if (!S)
        return FALSE;
    S->top = S->base;
    return OK;
}
//判断栈是否为空
Status StackEmpty(SqStack S) {

    if (S.top == S.base)  //栈顶指向栈底，说明栈空了
        return TRUE;
    else
        return FALSE;
}
//算出栈的长度
int StackLength(SqStack S) {
    return S.stacksize;
}
//获取栈顶元素
Status GetTop(SqStack S, SElemType* e) {

    if (S.top == S.base) {
        printf("栈为空.\n");
        return FALSE;
    }
    else {
        *e = *(S.top - 1);
        printf("栈顶元素：%c\n", *e);
        return OK;
    }
}
//入栈
Status Push(SqStack* S, SElemType e) {

    if (S->top - S->base >= S->stacksize) {
        S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base)
        {
            printf("重新申请空间失败.\n");
            exit(0);
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
    return OK;
}
//出栈
Status Pop(SqStack* S, SElemType* e) {

    if (S->top == S->base) {
        printf("栈为空.\n");
        return ERROR;
    }
    *e = *(--S->top);
    return OK;
}
//遍历栈
Status StackTraverse(const SqStack* S) {
    SElemType* p = S->base;
    if (S->base == S->top)
    {
        printf("栈为空.\n");
        return FALSE;
    }
    printf("栈中元素：");
    while (p != S->top)
    {
        printf("x=%d,y=%d\n", p->seat.x, p->seat.y);
        *p++;
    }
    printf("\n");
    return OK;
}
// 打印maze
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
//判断是否有解
Status MazePath(SqStack* S, MazeType maze, PosType start, PosType end) {

    int curstep = 1;
    SElemType e;       
    PosType curpos = start;  //起始坐标
    InitStack(S);            //初始化栈
    do {
        if (TRUE == Pass(&maze, curpos))   //该位置是解
        {
            FootPrint(&maze, curpos);      //保存路径
            e = NewSElem(curstep, curpos, 1);  //更新路径
            Push(S, e);  //入栈
            if ((curpos.x == end.x) && (curpos.y == end.y)) {   //所有路找完
                printf("路径:\n");
                PrintFoot(&maze, S);   //打印路径
                return TRUE;
            }
            curpos = NextPos(curpos, 1); //进入下一步
            curstep++;   //步数+1
        }
        else   //该位置不是解
        {
            if (!StackEmpty(*S))   //判断是否为空
            {
                Pop(S, &e);   //出栈
                while (e.di == 4 && !StackEmpty(*S)) {   //周围无路可走
                    MarkPrint(&maze, e.seat);       //标记当前位置
                    Pop(S, &e);   //出栈
                }
                if (e.di < 4) {   //向四周探路
                    e.di++;
                    Push(S, e);   //暂时保存路径
                    curpos = NextPos(e.seat, e.di);  //继续探路
                }
            }
        }
   
    } while (!StackEmpty(*S));
    return FALSE;
}
//计算可行路径
Status FootPrint(MazeType* M, PosType pos) {
    if ((pos.x > M->row) || (pos.y > M->column)) //越界
        return FALSE;
    M->footprint[pos.x][pos.y] = 1;      //可行路径
    return TRUE;
}
//判断位置的正确性 
Status Pass(MazeType* M, PosType pos) {
    //判断是否超过边界
    if ((M->row < pos.x) || (M->column < pos.y)) {
        printf("位置越位.\n");
        exit(0);
    }
    //判断当前位置是否为解
    if ((0 == M->footprint[pos.x][pos.y]) && (M->maze[pos.x][pos.y] == ' '))
        return TRUE;
    else
        return FALSE;
}
//路径的更新
SElemType NewSElem(int step, PosType pos, int d) {

    SElemType e;
    e.ord = step;
    e.seat = pos;
    e.di = d;
    return e;
}
//下一个位置的计算
PosType NextPos(PosType pos, int d){
    switch (d) {
    case 1:
        pos.x++;   //向右
        break;
    case 2:
        pos.y++;   //向下
        break;
    case 3:
        pos.x--;   //向左
        break;
    case 4:
        pos.y--;   //向上
        break;
    default:
        printf("出错.\n");
    }
    return pos;
}
//标记路径
Status MarkPrint(MazeType* M, PosType pos) {
    if (pos.x > M->row || pos.y > M->column) {
        printf("位置越位.\n");
        return ERROR;
    }
    M->footprint[pos.x][pos.y] = 1;
    return OK;
}
//打印最短路径
Status PrintFoot(MazeType* M, SqStack* S) {
    int i, j;
    SElemType* p;
    for (i = 0; i < M->row; i++) {      //初始化路径
        for (j = 0; j < M->column; j++) {
            M->footprint[i][j] = 0;
        }
    }
    p = S->base;
    if (S->base == S->top)
    {
        printf("栈为空.\n");
        return FALSE;
    }
    while (p != S->top)   //标记最短路径
    {
        M->footprint[p->seat.x][p->seat.y] = 1;
        *p++;
    }
    for (i = 0; i < M->row; i++) {   //打印路径
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
    start.x=0;start.y=1;    //起始坐标(0,1)
    end.x=8;end.y=9;        //结束坐标(8,9)
    InitMaze(&maze);        //初始化maze
    printf("形状：\n");  
    PrintMaze(&maze);       //打印maze
    if(TRUE==MazePath(&stack,maze,start,end))  //判断maze是否有解  
        printf("可解.\n");  
    else  
        printf("不可解.\n");  
    return 0;  
}  
