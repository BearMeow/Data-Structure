#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int precedence(char c);
char * infix2postfix(char *s);
int postfix(char *s);

int main(void)
{
  /*
  char s[] = "a+(b/c+x)";
  char *t;
  
  printf("infix   = %s\n", s);
  t = infix2postfix(s);
  printf("postfix = %s\n", t);
  */

  char postfi_s[] = "231*+9-";
  printf("231*+9- = %d\n", postfix(postfi_s));

  return 0;
}

int precedence(char c)
{
  /* Return operator precedence only support +, -, *, /, %. */
  if(c == '+' || c == '-')
  {
    return 1;
  }
  else if(c == '*' || c == '/' || c == '%')
  {
    return 2;
  }
  else
  {
    return -1;
  }
}

char * infix2postfix(char *s)
{
  char *t = (char *)malloc(strlen(s)+1);
  char tmp;
  int i = 0;
  stack st;

  stack_init(&st);

  for(; *s != '\0'; s++)
  {
    if (('a' <= *s && *s <= 'z') ||
        ('A' <= *s && *s <= 'Z') ||
        ('0' <= *s && *s <= '9'))
    {
      /* operand */
      t[i++] = *s;
      printf("t[%d] = %c\n", i-1, t[i-1]);
    }
    else if(*s == '(')
    {
      stack_push(&st, '(');
    }
    else if(*s == ')')
    {
      /* Popping out elements from  stack and append them to postfix expression
       * until we encounter an ')' charcater .*/
      while(stack_peek(&st) != '(')
      {
        t[i++] = stack_pop(&st);
      }
      stack_pop(&st);
    }
    else
    {
      /* If the operator has higher precedence than the one on top of the stack, push it in the stack.
       * If the operator has lower or equal precedence than the one on top of the stack, keep popping out 
       * and appending it to the postfix expression. */
      while(!stack_empty(&st) && (precedence(*s) <= precedence(stack_peek(&st))))
      {
        t[i++] = stack_pop(&st);
      }
      stack_push(&st, *s);
    }
  }

  while(!stack_empty(&st))
  {
    t[i++] = stack_pop(&st);
  }
  t[i] = '\0';

  return t;
}

int postfix(char *s)
{
  stack st;
  stack_init(&st);

  for(int i=0; s[i] != '\0'; i++)
  {
    if('0' <= s[i] && s[i] <= '9')
    {
      /* operand: push it into the stack */ 
      stack_push(&st, s[i]-'0');
    }
    else
    {
      /* operator: pop operands for the operator from
       * the stack. Evaluate the operator and push the
       * result back to the stack. */
      int a = stack_pop(&st);
      int b = stack_pop(&st);

      switch(s[i])
      {
      case '+':
        stack_push(&st, b + a);
        break;
      case '-':
        stack_push(&st, b - a);
        break;
      case '*':
        stack_push(&st, b * a);
        break;
      case '/':
        stack_push(&st, b / a);
        break;
      case '%':
        stack_push(&st, b % a);
        break;
      }
    }
  }

  return stack_pop(&st);
}
