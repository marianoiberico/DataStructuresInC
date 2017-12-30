// C program for array implementation of stack
#include<stdio.h>
#include<stdlib.h>
#define bool int
 
/* structure of a stack node */
struct sNode
{
   char data;
   struct sNode *next;
};
 
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
  /* allocate node */
  struct sNode* new_node =
            (struct sNode*) malloc(sizeof(struct sNode));
 
  if (new_node == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }           
 
  /* put in the data  */
  new_node->data  = new_data;
 
  /* link the old list off the new node */
  new_node->next = (*top_ref);  
 
  /* move the head to point to the new node */
  (*top_ref)    = new_node;
}
 
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
  char res;
  struct sNode *top;
 
  /*If stack is empty then error */
  if (*top_ref == NULL)
  {
     printf("Stack overflow n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
