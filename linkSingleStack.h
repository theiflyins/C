#include<stdlib.h>

struct linkSingleStackNode
{
    int val;
    struct linkSingleStackNode *next;
};
typedef struct linkSingleStack
{
    struct linkSingleStackNode *head;
    int size;
}SingleStack;

SingleStack* creatLinkSingleStackNode(){
    SingleStack *stack = (SingleStack*)malloc(sizeof(SingleStack));
    stack ->head->next = NULL;
    stack ->size = 0;
    return stack;
}
int push(SingleStack* stk,int val){
    linkSingleStackNode *head = stk->head;
    while(head->next != NULL)
        head = head->next;
    head->next = (struct linkSingleStackNode *)malloc(sizeof(struct linkSingleStackNode));
    head->next->val = val;
    head->next->next = NULL;
    stk->size++;
    return 1;
}
int pop(SingleStack* stk){
    if(stk->size <= 0)
        return 0;
    linkSingleStackNode *head = stk->head;
    while(head->next->next != NULL)
        head = head->next;
    int res = head->next->val;
    head->next = NULL;
    stk->size--;
    return res;
}
int getSize(SingleStack* stk){
    return stk->size;
}