#include<stdio.h>
#include "Functions3.c"

int main(){

    int choice,n,n1,n2;
    List *head,*head1,*head2,*head3;
    printf("\nEnter the number of nodes of the doubly linked list : ");
    scanf("%d",&n);
    head=createList(n);
   do{
       system("clear");
       printf("\n_ _ _ _ _ _MENU_ _ _ _ _ _\n");
       printf("\n1) Print the content of the list");
       printf("\n2) Insert an element at the front of the list");
       printf("\n3) Insert an element at the end of the list");
       printf("\n4) Insert a node after the kth node.");
       printf("\n5) Insert a node after the node (first from the start) containing a given value");
       printf("\n6) Insert a node before the kth node");
       printf("\n7) Insert a node before the node (first from the start) containing a given value");
       printf("\n8) Delete the first node");
       printf("\n9) Delete the last node");
       printf("\n10) Delete a node after the kth node");
       printf("\n11) Delete a node before the kth node");
       printf("\n12) Delete the kth node");
       printf("\n13) Delete the node(first from the start) containing a specified value");
       printf("\n14) Reverse the linked list(not just printing in reverse)\n");
       printf("\nenter your choice : ");
       scanf("%d",&choice);

       switch(choice){

         case 1: printf("\nContent of the doubly linked list : ");
                 displayList(head);
                 break;

         case 2: head=insertFront(head);
                 break;

         case 3: head=insertEnd(head);
                 break;

         case 4: head=insetAfterK(head);
                 break;

         case 5: head=insertAfterGivenValue(head);
                 break;

         case 6: head=insertBeforeK(head);
                 break;

         case 7: head=insertBeforeGivenNode(head);
                 break;

         case 8: head=deleteFront(head);
                 break;

         case 9: head=deleteLast(head);
                 break;

         case 10: head=deleteAfterK(head);
                  break;

         case 11: head=deleteBeforeK(head);
                  break;

         case 12: head=deleteKNode(head);
                  break;

         case 13: head=deleteNodeGivenValue(head);
                  break;

         case 14: head=reverse(head);
                  break;         
         
         default: printf("\nInvalid Input!");
                  break;
       }
       printf("\nPress 1 to continue and any other key to exit :");
       scanf("%d",&choice);
   }while(choice==1);
}