#include<stdlib.h>
#define ENLARGESIZE 10

struct staticStackNode
{
    int val;
    int next;
};
typedef struct static_Stack
{
    struct staticStackNode *array;
    int top;
    int button;
    int size;
}staticStack;

staticStack* creatStack(int size){
    staticStack* stk = (staticStack*)malloc(sizeof(staticStack));
    stk->size = size;
    stk->top = 0;
    stk->array = (struct staticStackNode*)malloc(sizeof(struct staticStackNode)*size);
    return stk;
}
int getNextEmptyIndex(staticStack* stk){
    staticStackNode* arrray = stk->array;
    int res = 0;
    for(;res < stk->size && arrray[res] != 0;res++);
    return res;
}
int push(staticStack* stk,int val){
    int flag = 1;
    if(stk->top >= stk->size){
        realloc(stk->array,stk->size+ENLARGESIZE);
        stk->size += ENLARGESIZE;
        flag = 0;
    }
    struct staticStackNode* tmp = stk->array;
    tmp[stk->top].next = getNextEmptyIndex(stk);
    stk->top = tmp[stk->top].next;
    tmp[stk->top].val = val;
    return flag;
}
int pop(staticStack* stk){
    int res = (stk->array)[stk->top].val;
    (stk->array)[stk->top].val = 0;
    int before = stk->button;
    while((stk->array)[before].next != stk->top && (stk->array)[before].next !=-1 )
        before = (stk->array)[before].next;
    (stk->array)[before].next = -1;
    return res;
}
int getSize(staticStack* stk){
    return stk->size;
}