#include<stdio.h>

struct node{
  unsigned short data;  // 16 bit information
  struct node *next;    // pointer to the next
};
typedef struct node node_t;
node_t *HeadPt;

int StoreData(unsigned short info){ node_t *pt;
  pt=malloc(sizeof(node_t));  // create a new entry
  if(pt){
    pt->data=info;              // store data
    pt->next=HeadPt;            // link into existing
    HeadPt=pt;
    return(1);
  }
  return(0);      // out of memory
};

node_t *Search(unsigned short info){node_t *pt;
  pt=HeadPt;
  while(pt){
    if(pt->data==info)
        return (pt);
    pt=pt->next;   // link to next
  }
  return(pt);      // not found
};
unsigned short Count(void){ node_t *pt;
  unsigned short cnt;
  cnt = 0;
  pt = HeadPt;
  while(pt){
    cnt++;
    pt = pt->next;   // link to next
  }
  return(cnt);
};

//If faced with a sorted list, and want to keep it that way
int InsertData(unsigned short info){ 
node_t *firstPt,*secondPt,*newPt;
  newPt = malloc(sizeof(node_t));  // create a new entry
  if(newPt){
    newPt->data = info;              // store data
    if(HeadPt==0){   // case 1
      newPt->next = HeadPt;   // only element
      HeadPt = newPt;
      return(1);
    }
    if(info<=HeadPt->data){ // case 2
      newPt->next = HeadPt;   // first element in list
      HeadPt = newPt;
      return(1);
    }
    firstPt = HeadPt;   // search from beginning
    secondPt = HeadPt->next; 
    while(secondPt){
      if(info <= secondPt->data){ // case 3
        newPt->next = secondPt;   // insert element here
        firstPt->next = newPt;
        return(1);
      }
      firstPt = secondPt;   // search next
      secondPt = secondPt->next; 
    }
    newPt->next = secondPt;   // case 4, insert at end
    firstPt->next = newPt;
    return(1);
  }
  return(0);      // out of memory
};

int Remove(unsigned short info){ 
node_t *firstPt,*secondPt;
  if(HeadPt==0)  // case 1
    return(0);   // empty list
  firstPt = HeadPt;
  secondPt = HeadPt->next;
  if(info==HeadPt->data){  // case 2
    HeadPt = secondPt; // remove first element in list
    free(firstPt);     // return unneeded memory to heap
    return(1);
  }
  while(secondPt){
    if(secondPt->data==info){  // case 3
      firstPt->next=secondPt->next; // remove this one
      free(secondPt);   // return unneeded memory to heap
      return(1);
    }
    firstPt = secondPt;   // search next
    secondPt = secondPt->next; 
  }
  return(0);    // case 4, not found
};
