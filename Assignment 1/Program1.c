#include "Functions.c"  //including the file Functions.c 

int main(){
  int n,ch,choice;
  printf("\nEnter the size of the array : ");
  scanf("%d",&n);
  arr=Create(n,100);
  size=n;

  do{
    system("cls");
    
    printf("_ _ _ _ _ _Menu_ _ _ _ _ _\n");
    printf("\n1) Diaplay the list");
    printf("\n2) Count total number of elements");
    printf("\n3) Reverse the list");
    printf("\n4) Index of the given element");
    printf("\n5) Find the element at a perticular index");
    printf("\n6) Insert a element in the list");
    printf("\n7) Delete a element from the list");
    printf("\n8) sort the list");
    printf("\n9) Merge the list with another list");
    printf("\n\nEnter your choice : ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice){
      
      case 1: Display(arr,size); 
              break;

      case 2: printf("Total number of elements in the list is %d",noElements());
              break;

      case 3: Reverse();
              break;

      case 4: printf("\nEnter the element you are looking for : ");
              scanf("%d",&ch);
              indexFound(ch);
              break;

      case 5: printf("\nEnter a valid index : ");
              scanf("%d",&ch);
              valueAtIndex(ch);
              break;

      case 6: printf("\nEnter the element to be inserted : ");
              scanf("%d",&n);
              printf("\nEnter the index at which the element should be inserted : ");
              scanf("%d",&ch);
              insertAtIndex(n,ch);
              Display(arr,size);
              printf("%d",size);
              break;

       case 7: printf("\nEnter the index to be deleted : ");
              scanf("%d",&n);
              deleteElement(n);
              Display(arr,size);
              printf("%d",size);
              break;

       case 8: mergeSort(0,size-1);
               break;

       case 9: printf("\nEnter the size of the list that is to be merged with main list : ");
               scanf("%d",&n);
               printf("\nStart creating the list");
               int *ptr=Create(n,n);
               Merge_Two_List(arr,ptr,size,n);
               size+=n;
               free(ptr);
               break;
        }  
    printf("\nPress 1 to continue and any other key to exit : ");
    fflush(stdin);
    scanf("%d",&choice);
  }while(choice==1);
}