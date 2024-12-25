#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top =-1;

void push(int item){
    if(top == MAX -1){
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top]=item;
}

int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int Evalpost(char * exp){
    int i;
    for(i=0;exp[i];++i){
        if(isdigit(exp[i])){
            push((exp[i]-'0'));
        }
        else{
            int val1=pop();
            int val2=pop();

            switch(exp[i]){
             
             case '+':
             push(val2+val1);
             break;
            
             case '-':
             push(val2-val1);
             break;
             
             case '/':
             push(val2/val1);
             break;
             
             case '*':
             push(val2*val1);
             break;
             
             case '%':
             push(val2%val1);
             break;
             
             case '^':
             push(val2^val1);
             break;
            }

        }
    }
            return pop();
}

int main(){
    char exp[MAX];
    printf("Enter Postfix Expression\n");
    scanf("%s",exp);
    printf("Value of Expression is %d \n",Evalpost(exp));
    return 0;
}