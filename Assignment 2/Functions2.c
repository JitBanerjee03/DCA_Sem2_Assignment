#include<stdlib.h>

//Self referential structure to represent the Polynomial 
struct Node{
  int coefficient;
  int power;
  struct Node *next;
}typedef polynomial;

//Function to create the polynomial
polynomial *create(int n){
  int i=1;
  polynomial *head=NULL,*temp;
  if(n<=0)
  printf("\nInvalid Input !");

  else{
    int i=1;
    
  }
}

void displayPolynomial(polynomial *head){
   
}