#include "queue.h"
#include <stdio.h>
#include "boolean.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q)=IDX_UNDEF;
    IDX_TAIL(*q)=IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    return IDX_HEAD(q)==IDX_UNDEF && IDX_TAIL(q)==IDX_UNDEF;
}

boolean isFull(Queue q)
{
    boolean res;
    if(IDX_TAIL(q)>=IDX_HEAD(q))
        res = IDX_TAIL(q)-IDX_HEAD(q)==CAPACITY-1;
    else
        res = IDX_HEAD(q)-IDX_TAIL(q)==1;
    return res;
}

int length(Queue q)
{
    int res;
    if(isEmpty(q))
        res = 0;
    else if(IDX_TAIL(q)>=IDX_HEAD(q))
        res = IDX_TAIL(q)-IDX_HEAD(q)+1;
    else
        res = IDX_TAIL(q)-IDX_HEAD(q)+1+CAPACITY;
    return res;
}

void enqueue(Queue *q, ElType val)
{
    if(isEmpty(*q)) {
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
    }
    else {
        if(IDX_TAIL(*q) + 1 == CAPACITY) {
            for(int i = 0; i < length(*q); i ++)
                (*q).buffer[i] = (*q).buffer[i+IDX_HEAD(*q)];
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)++;
    }
    TAIL(*q)=val;
}

void dequeue(Queue *q, ElType *val)
{
    *val=HEAD(*q);
    if(IDX_HEAD(*q)==IDX_TAIL(*q)) {
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    }
    else {
        IDX_HEAD(*q)++;
        IDX_HEAD(*q)%=CAPACITY;
    }
}

void displayQueue(Queue q)
{
    int i,l=length(q);
    printf("[");
    for(int i=0;i<l;i++) {
        printf("%d",q.buffer[(i+IDX_HEAD(q))%CAPACITY]);
        if(i<l-1)
            printf(",");
    }
    printf("]\n");
}
