#include <stdio.h> 
#include "stack.h" 

void CreateEmptyStack(Stack *S){
    Top(*S) = Nil; 
    S->size = 0;
}

boolean IsEmptyStack(Stack S){
    return Top(S)==Nil; 
}

boolean IsFull(Stack S){
    return Top(S)==MaxEl-1; 
}

void Push(Stack *S, NamaBarang X){
    if(IsEmptyStack(*S)){ 
        Top(*S)=0; 
    }
    else{ 
        Top(*S)++; 
    }
    InfoTop(*S) = X;
    S->size++; 
}

void Pop(Stack *S, NamaBarang *X){
    *X = InfoTop(*S); 
    if(Top(*S)==0){ 
        Top(*S) = Nil; 
    }
    else{ 
        Top(*S)--; 
    }
    S->size--;
}