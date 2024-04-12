#include<stdlib.h>
#include<stdio.h>
int *arr,size=0;

//functions to create the list
int *Create(int n,int capacity){
  int i,*ptr; 
  //capacity=100;
  //size=n;
  ptr=(int *)malloc(100*sizeof(int));
  for(i=0;i<n;i++){
    printf("\nEnter the value of arr[%d] : ",i);
    scanf("%d",&ptr[i]);
  }
  return ptr;
}

//Display function
void Display(){
  
  if(size==0)
  printf("\nThe list does not contain any elements");

  else{
    int i;
    printf("[ ");
    for(i=0;i<size;i++)
    printf("%d ",arr[i]);
    printf("]");
  }
}

//total number of elements in the list
int noElements(){
    return size;
}

//Function to reverse the list using two pointers approach 
void Reverse(){
  int i=0,j=size-1,temp;
  while(i<j){
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
    i++;
    j--;
  }
}

//Function to find the index of a perticular elements
void indexFound(int n){
  if(size==0)
  printf("\nList is empty");
  else{
    int flag=0,i;
    for(i=0;i<size;i++){
    if(arr[i]==n){
        flag=1;
        printf("\nElement found at index %d",i);
    }
  }
   if(flag==0)
   printf("\nElement does not exits in the list");
  }
}

//Function to find the element of a perticular index
void valueAtIndex(int i){
  
  if(size==0)
  printf("\nList is empty");

  else{
    if(i<0 || i>=size)
    printf("\nInvalid index!!");

    else
    printf("\nElement at index %d is %d",i,arr[i]);
  }
}

//Function to insert a element at a perticular index
void insertAtIndex(int n,int i){
  if(i<0 || i>size)
  printf("\nThe given index is a invalid index!!");

  else{
    int j=size-1;
    while(j>=i){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=n;
    size++;
  }
}

//function to delete an element from the list
void deleteElement(int i){
  int j=0;
  
  if(i<0 || i>=size)
  printf("\nGiven index is a invalid index");
  
  else{
    while(j<i)
    j++;

    while(j<size){
    arr[j]=arr[j+1];
    j++;
  }
  size--;
  }
}

//merge function required for merge sort algorithm
void merge(int l,int mid,int u){
  int *temp=(int *)malloc((u-l+1)*sizeof(int)),i=l,j=mid+1,k=0;
  
  while(i<=mid && j<=u){
    
    if(arr[i]<=arr[j])
    temp[k++]=arr[i++];
    
    else
    temp[k++]=arr[j++];
  }

  while(i<=mid)
  temp[k++]=arr[i++];

  while(j<=u)
  temp[k++]=arr[j++];
  
  i=l;
  k=0;
  
  while(i<=u)
  arr[i++]=temp[k++];

  free(temp);  //Resolving the dynamically created memory
}

//This function uses merge sort algorithm to sort an array
void mergeSort(int l,int u){
  
  if(l==u)
  return;

  int mid=(l+u)/2;
  mergeSort(l,mid);
  mergeSort(mid+1,u);

  merge(l,mid,u);
}

//function to merge two lists
void Merge_Two_List(int *ptr1,int *ptr2,int size1,int size2){
  int i=size1,j;
  for(j=0;j<size2;j++)
  ptr1[i++]=ptr2[j];
}