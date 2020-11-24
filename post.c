#include<stdio.h>
#include<string.h>
#define stacksize 70
int inputprecedence(char symbol)
{
    switch(symbol)
    {
      case '+':
      case '-': return 1;
      case '*':
      case '%':
      case '/': return 3;
      case '^':
      case '$': return 6;
      case '(': return 9;
      case ')': return 0;
      default: return 7;
    }
}
int stackprecedence(char symbol)
{
  switch(symbol)
  {
    case '+':
    case '-': return 2;
    case '*':
    case '%':
    case '/': return 4;
    case '^':
    case '$': return 5;
    case '(': return 0;
    case '#': return -1;
    default: return 8;
  }
}
void push(char item,int *top,char s[])
{
  if(*top==stacksize-1)
  {
    printf("stack is full\n");
    return;
  }
  *top=*top+1;
  s[*top]=item;
}
char pop(int*top,char s[])
{
  char item;
  if(*top==-1)
  {
    printf("stack is empty\n");
    return ;

  }
  item=s[*top];
  *top=*top-1;
  return item;
}
void infix_postfix(char infix[],char postfix[])
{
  int j,i,n,top;
  char symbol,s[stacksize];
  top=-1;
  j=0;
  n=strlen(infix);
  push('#',&top,s);
  for(i=0;i<n;i++)
  {
    symbol=infix[i];
    while(inputprecedence(symbol)<stackprecedence(s[top]))
    {
        postfix[j]=pop(&top,s);
        j=j+1;
    }
    if(stackprecedence(s[top])!=inputprecedence(symbol))
    {
      push(symbol,&top,s);
    }
    else
    {
        pop(&top,s);
    }
   }
    while(s[top]!='#')
    {
      postfix[j]=pop(&top,s);
      j=j+1;
    }
    postfix[j]='\0';

}
void main()
{
  char infix[70],postfix[70];
  printf("enter the infix expression:\n");
  scanf("%s",infix);
  infix_postfix(infix,postfix);
  printf("postfix expression is %s",postfix);
  getch();
}
