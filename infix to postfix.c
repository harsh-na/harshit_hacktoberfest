#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack{
char data;
struct stack *next;
}stack;
stack *head = NULL, *temp;

int checkOptr(char op){
    switch (op)
    {
    case '+':
    case '-':
    case '/':
    case '*':
    case '(':
    case ')':
    case '^':
        return 1;
        break;
    }

    return 0;
}

int chkPre(char op){
    switch (op)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    
    default:
        break;
    }
}

int associativity(char op){
    switch (op)
    {
    case '/':
    case '*':
    case '-':
    case '+':
        return 1;
        break;
    case '^':
        return 0;
    }
    return -1;
}

void push(char ch){
    stack* newStack;
    newStack = (stack*)malloc(sizeof(stack));
    newStack->data = ch;
    if(head == NULL){
        head = newStack;
        newStack->next = NULL;
    }
    else{
        newStack->next = head;
        head = newStack;
    }
}

void pop(){
    temp = head;
    head = head->next;
    free(temp);
}

void printData(){
    printf("\nStack data: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%c  ", temp->data);
        temp = temp->next;
    }
}



int main(){
    int count = 0;
    char infix[25];
    char postfix[25];
    gets(infix);
    
    for (int i = 0; infix[i] != '\0'; i++)
    {
        
        if(checkOptr(infix[i])){
            loop:
            if(head == NULL || head->data == '(')
                push(infix[i]);
            
            else if(infix[i] == '(')
                push(infix[i]);

            else if(infix[i] == ')'){
                while(head->data != '('){
                    postfix[count] = head->data;
                    count++;
                    pop();
                }
                if(head->data == '(')
                    pop();
            }

            else if(chkPre(infix[i]) > chkPre(head->data)){
                push(infix[i]);
            }

            else if(chkPre(infix[i]) == chkPre(head->data)){
                if(associativity(infix[i])==0){
                    push(infix[i]);
                }
                else if(associativity(infix[i] == 1)){
                    postfix[count] = head->data;
                    count++;
                    pop();
                    goto loop;
                }
            }
            
            else if(chkPre(infix[i]) < chkPre(head->data)){
                postfix[count] = head->data;
                count++;
                pop();
                goto loop;
            }


        }
        else if(infix[i]==' '){
            continue;
        }
        else{
            postfix[count] = infix[i];
            count++;
        }
    }
    while (head!=NULL)
    {
        postfix[count] = head->data;
        count++; 
        pop();
    }
    postfix[count] = '\0';

    printData();
    printf("\n\nPostfix: %s\n", postfix);
    
    return 0;
}
