#include<stdio.h>
#include "Functions2.c"

int main(){
    int choice,n1,n2,head1,head2;
    do{
       system("clear");
       printf("\n_ _ _ _ _ _MENU_ _ _ _ _ _\n");
       printf("\n1) Add two polynomials");
       printf("\n2) Substract two polynomials");
       printf("\n3) Multiply two polynomials\n");
       printf("\nEnter your choice : ");
       scanf("%d",&choice);
       
       switch(choice){
         
         case 1:printf("\nEnter number of terms of the first polynomial");
                scanf("%d",&n1);
                head1=create(n1);
                printf("\nEnter number of terms of the second polynomial");
                scanf("%d",&n2);
                head1=create(n1);
                break;

         default: printf("\nInvalid Input !");
                  break; 
       }

       printf("\nPress 1 to continue and any other key to exit :");
       scanf("%d",&choice);
    }while(choice==1);
}