#ifndef _STACK_H
#define _STACK_H
#include "dict.h"
#include <stdio.h>

typedef void*  DataType;               //自定义数据类型,假定为整型

struct Node;                        //单链表结点类型
typedef struct Node *PNode;         //结点指针类型

typedef struct Node                 //单链表结点结构
{   
    DataType info;                  //结点数据域
    PNode link;                     //结点指针域
}Node;

typedef struct LinkStack           //链表栈定义
{
    PNode top;        //栈顶指针
}LinkStack;

typedef struct LinkStack * PLinkStack;    //链表栈的指针类型

//创建一个空栈
PLinkStack createEmptyStack( void );

//判断栈是否为空栈
int isEmptyStack(PLinkStack stack);

//进栈,成功返回1，失败返回0
int push(PLinkStack stack,DataType x);

//出栈，成功返回1，失败返回0
int pop(PLinkStack stack);

//取栈顶元素
DataType getTop(PLinkStack stack);


//把栈置空
void setEmpty(PLinkStack stack);

//把栈销毁
void destroyStack(PLinkStack stack);
#endif
