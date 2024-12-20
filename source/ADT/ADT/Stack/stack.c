#include <stdio.h> 
#include "stack.h" 

void CreateEmptyStack(Stack *S){
    Top(*S) = Nil; 
}

boolean IsEmptyStack(Stack S){
    return Top(S)==Nil; 
}

boolean IsFull(Stack S){
    return Top(S)==MaxEl-1; 
}

void Push(Stack * S, infotype X){
    if(IsEmptyStack(*S)){ 
        Top(*S)=0; 
    }
    else{ 
        Top(*S)++; 
    }
    InfoTop(*S) = X; 
}

void Pop(Stack * S, infotype* X){
    *X = InfoTop(*S); 
    if(Top(*S)==0){ 
        Top(*S) = Nil; 
    }
    else{ 
        Top(*S)--; 
    }
}