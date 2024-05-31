#include<stdio.h>
#include<stdlib.h>

int *arr;
void linearSearch(int,int);
void binarySearch(int,int);
int linearSearchRecursive(int,int);
int binarySearchRecursive(int,int);

int main(){

    int n,choice,val;
    printf("\nEnter the size of the array : ");
    scanf("%d",&n);

    if(n>0){

      arr=(int *)malloc(sizeof(n));        
      printf("\nStart entering the values in the array !\n");

      for(int i=0;i<n;i++){
        printf("\nArr[%d] : ",i);
        scanf("%d",&arr[i]);
        }

      do
      {
        printf("\n_ _ _ _ _ _MENU_ _ _ _ _ _\n");
        printf("\n1) Linear search (Iterative way)");
        printf("\n2) Binary search (Iterative way)");
        printf("\n3) Linear search (Recursive way)");
        printf("\n4) Binary search (Recursive way)");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: printf("\nEnter the key you are looking for : ");
                scanf("%d",&val);
                break;
        
        case 2: printf("\nEnter the key you are looking for : ");
                scanf("%d",&val);
                break;
        
        case 3: printf("\nEnter the key you are looking for : ");
                scanf("%d",&val);
                break;
        
        case 4: printf("\nEnter the key you are looking for : ");
                scanf("%d",&val);
                break;
        
        default: printf("\nInvalid input !");
                 break;
        }

        printf("\nPress 1 to continue and any other key to exit : ");
        scanf("%d",&choice);
      } while (choice==1);
                
    }

    else
    printf("\nInvalid input !");
}

void linearSearch(int size,int val){
  int i=0,flag=0;
  for(i=0;i<size;i++){
    if(arr[i]==val){
        printf("\nElement found at index %d",i);
        flag=1;
        break;
    }
  }

  if(flag==0)
  printf("\nElement does not exist in the given array !");
}

void binarySearch(int size,int val){
}

int linearSearchRecursive(int size,int val){

}

int binarySearchRecursive(int size,int val){

}
