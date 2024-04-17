#include<stdlib.h>

//Our required self referential structure for inplementation of the linked list
struct Node{
  int data;
  struct Node *next;
}typedef List;

//Function to create the linked list
List *createList(int n){
  int val,i=1;
  List *head=(List *)malloc(sizeof(List)),*temp=head;
  printf("\nEnter the data value of the head node : ");
  scanf("%d",&val);
  head->data=val;
  head->next=NULL;

  for(;i<n;i++){
    printf("\nEnter the data value of the node : ");
    scanf("%d",&val);
    temp->next=(List *)malloc(sizeof(List));
    temp->next->data=val;
    temp=temp->next;
    temp->next=NULL;
  }
  return head;
}

//Function to display the linked list
void displayList(List *head){
  List *temp=head;
  while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
  }
}

//Function to insert node at the first of the list
List *insertFront(List *head){
  int val;
  List *temp=(List *)malloc(sizeof(List));
  printf("\nEnter the data the value of the node : ");
  scanf("%d",&val);
  temp->data=val;
  temp->next=head;
  return temp;
}

//Function to insert node at the end of the linked list
List *insertEnd(List *head){
  if(head==NULL)
  head=insertFront(head);
  else{
    int val;
    printf("\nEnter the data value of the node : ");
    scanf("%d",&val);
    List *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=(List *)malloc(sizeof(List));
    temp->next->data=val;
    temp=temp->next;
    temp->next=NULL;
  }
  return head;
}

//Function to insert node after the kth node
List *insetAfterK(List *head){
  int i=1,k,flag=0,val;
  List *temp=head;
  printf("\nEnter the kth node : ");
  scanf("%d",&k);
  while(temp!=NULL && i<=k){
    if(i==k){
      List *newNode=(List *)malloc(sizeof(List));
      printf("\nEnter the data value of the Node : ");
      scanf("%d",&val);
      newNode->data=val;
      newNode->next=temp->next;
      temp->next=newNode;
      flag=1;
      break;
    }
    temp=temp->next;
    i++;
  }
  if(flag==0)
  printf("\nLinked list is either empty or invalid kth node given as input");
  return head;
}

//Function to insert a node after a node with given value
List *insertAfterGivenValue(List *head){
  if(head==NULL)
  printf("\nLinked list is empty!");
  else{
    int k,val;
    printf("\nEnter the data value of the node after which you want to enter your node : ");
    scanf("%d",&k);
    List *temp=head;
    int flag=0;
    while(temp!=NULL){
      if(temp->data==k){
        printf("\nEnter the data value of the node to be inserted : ");
        scanf("%d",&val);
        List *newNode=(List *)malloc(sizeof(List));
        newNode->data=val;
        newNode->next=temp->next;
        temp->next=newNode;
        flag=1;
        break;
      }
      temp=temp->next;
    }
  }
  return head;
}

//Function to insert a node before kth node
List *insertBeforeK(List *head){
  int i=1,k,flag=0,val;
  List *temp=head;
  printf("\nEnter the kth node : ");
  scanf("%d",&k);
  if(k==1){
    head=insertFront(head);
    flag=1;
  }

  else{
    while(temp->next!=NULL && i<k){
    if(i==k-1){
      List *newNode=(List *)malloc(sizeof(List));
      printf("\nEnter the data value of the Node : ");
      scanf("%d",&val);
      newNode->data=val;
      newNode->next=temp->next;
      temp->next=newNode;
      flag=1;
      break;
    }
    temp=temp->next;
    i++;
  }
  }
  if(flag==0)
  printf("\nLinked list is either empty or invalid kth node given as input");
  return head;
}

//Function to insert a node before a given node by value
List *insertBeforeGivenNode(List *head){
  if(head==NULL)
  printf("\nLinked list is empty");
  else{
    int val,flag=0;
    printf("\nEnter the data value of the node before which you want to insert your node : ");
    scanf("%d",&val);
    if(head->data==val)
    head=insertFront(head);
    else{
      List *temp=head;
      while(temp->next!=NULL){
        if(temp->next->data==val){
          List *newNode=(List *)malloc(sizeof(List));
          int data;
          printf("\nEnter the data value of the node : ");
          scanf("%d",&data);
          newNode->data=data;
          newNode->next=temp->next;
          temp->next=newNode;
          flag=1;
          break;
        }
        temp=temp->next;
      }
      if(flag==0)
      printf("\nCould not found the given data value!"); 
    }
  }
  return head;
}

//Function to delete the first node
List *deleteFront(List *head){
  if(head==NULL)
  printf("\nLinked list is empty");
  
  else{
    List *temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
  }
  return head;
}

//Function to delete the last node of the linked list
List *deleteLast(List *head){
  if(head==NULL){
    printf("\nLinked list is empty");
    return head;
  }

  else if(head->next==NULL){
    free(head);
    return NULL;
  }

  List *temp=head;
  while (temp->next->next!=NULL)
  temp=temp->next;
  List *ptr=temp->next;
  temp->next=NULL;
  free(ptr);
  return head;
}

//Function to delete the node after the kth node 
List *deleteAfterK(List *head){
  if(head==NULL){
    printf("\nLinked list is empty !");
    return head;
  }

  int i=0,k,flag=0;
  List *temp=head;
  printf("\nEnter the kth node : ");
  scanf("%d",&k);
  while(temp->next!=NULL && i<k){
    if(i==k-1){
      List *ptr=temp->next;
      temp->next=temp->next->next;
      ptr->next=NULL;
      free(ptr);
      flag=1;
      break;
    }
    temp=temp->next;
    i++;
  }
  if(flag==0)
  printf("\nLinked list is either empty or invalid kth node given as input");
  return head;
}

//Function to delete before the kth node
List *deleteBeforeK(List *head)
{
  int flag=0;
  
  if(head!=NULL){
    int k;
    printf("\nEnter the value of the kth node : ");
    scanf("%d",&k);
    if(k!=1){
      if(k==2){
        List *ptr=head;
        head=head->next;
        ptr->next=NULL;
        free(ptr);
        flag=1;
      }
      else{
        int i=1;
        List *temp=head;
        while(temp->next->next!=NULL && i<k-1){
          if(i==k-2){
            List *ptr=temp->next;
            temp->next=temp->next->next;
            ptr->next=NULL;
            free(ptr);
            flag=1;
            break;
          }
          temp=temp->next;
          i++;
        }
      }
    }
  }
  if(flag==0)
  printf("\nLinked list is either empty or invalid kth node given as input");
  return head;
}

//Function to delete the kth node
List *deleteKNode(List *head){
  int flag=0;
  if(head!=NULL){
    int k;
    printf("\nEnter the value of the kth node : ");
    scanf("%d",&k);
    if(k==1){
      head=deleteFront(head);
      flag=1;
    }
    else{
      int i=1;
      List *temp=head;
      while(temp->next!=NULL && i<=k-1){
        if(i==k-1){
          List *ptr=temp->next;
          temp->next=temp->next->next;
          ptr->next=NULL;
          free(ptr);
          flag=1;
          break;
        }
        temp=temp->next;
        i++;
      }
    }
  }
  if(flag==0)
  printf("\nLinked list is either empty or invalid kth node given as input");
  return head; 
}

//Function to Delete the node(first from the start) containing a specified value"
List *deleteNodeGivenValue(List *head){
  int flag=0;
  if(head!=NULL){
    int val;
    printf("\nEnter the value of the node to be deleted : ");
    scanf("%d",&val);
    if(head->data==val){
      head=deleteFront(head);
      flag=1;
    }
    else{
      List *temp=head;
      while(temp->next!=NULL){
        if(temp->next->data==val){
          List *ptr=temp->next;
          temp->next=temp->next->next;
          ptr->next=NULL;
          free(ptr);
          flag=1;
          break;
        }
        temp=temp->next;
      }
    }
  }
  if(flag==0)
  printf("\nLinked list is either empty or non of the nodes in the linked list have the given data value!");
  return head;
}