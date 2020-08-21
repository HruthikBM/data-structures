#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct stack 
{
    int top;
    unsigned capacity ;
    char *array;
    
};
int isempty(struct stack *stk)
{
    return stk->top==-1;
    
}
struct stack *createstack(int capacity)
{
    struct stack *stk=(struct stack *)malloc(sizeof(struct stack ));
    stk->top=-1;
    stk->capacity=capacity;
     stk->array=(char *)malloc (stk->capacity*sizeof(char));
    return stk;
}
int isfull(struct stack *stk)
{
    return stk->top==stk->capacity-1;
}
void push(struct stack *stk,int x)
{
    if(isfull(stk))
    {
        return; 
    }
    stk->array[++stk->top]=x;
    
}
void print(struct stack *stk)
{
    int i;
    for(i=0;i<=stk->top;i++)
       printf("%c ",stk->array[i]);
}
char pop(struct stack *stk)
{
    if(isempty(stk))
    {
        return 0;
    }
    return stk->array[stk->top--];
}
char peek(struct stack *stk)
{
    return stk->array[stk->top];
}
int pref(char c)
{
    if(c=='^')
      return 3;
    if(c=='*'||c=='/')  
      return 2;
    if(c=='-'||c=='+')  
      return 1;
    if(c=='['||c==']'||c=='('||c==')')  
    return 4;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    struct stack *stk=createstack(200);
    char inp[200];
    scanf("%s",inp);
    int n=strlen(inp),i;
    bool ch;
    for(i=0;i<=n;i++)
    {
        
        if(inp[i]=='(')
            ch=true;
        if(inp[i]==')')
            ch=false;
        
      if(inp[i]>='a'&&inp[i]<='z')
      {
        printf("%c",inp[i]);
      }
      else 
      {
            if(inp[i]=='(')
          {
              push(stk,inp[i]);
          }
          else if (inp[i]==')')
          {
             while(!isempty(stk)&&peek(stk)!='(')
              {
                  printf("{%c}",pop(stk));
              }
            /*   if (!isempty(stk) && peek(stk) != '(') 
                return -1; // invalid expression              
            else
                pop(stk);*/ 
             // printf("%c",pop(stk));
             // push(stk,inp[i]);
            pop(stk);
          }
          else if(pref(peek(stk))<=pref(inp[i])||isempty(stk)==1||peek(stk)=='(')
          {
              push(stk,inp[i]);
          }
         
          else 
          {
              while(!isempty(stk)&&pref(peek(stk))>=pref(inp[i]))
               {
                   printf("%c",pop(stk));
               }
               push(stk,inp[i]);
          }
      }
    }

    while(!isempty(stk))
    {
      printf("%c",pop(stk));
    }
     printf("\n");
    }  
    
}
