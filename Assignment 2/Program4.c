#include <stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

int josephusCircularLinkedList(int n, int k) {
    // Create a circular doubly linked list of people
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* curr = (Node*)malloc(sizeof(Node));
        curr->data = i;
        prev->next = curr;
        prev = curr;
    }
    prev->next = head;
    
    Node* curr = head;
    while (curr->next != curr) {// continue untill one node is left
        for (int i = 1; i < k-1; i++) {
            curr = curr->next;
        }        
        Node* temp = curr->next;
        curr->next = curr->next->next;
        curr = curr->next;
        free(temp);
    }
    
    int result = curr->data;
    free(curr);
    return result;
}

int josephusCircularDLinkedList(int n, int k) {
    // Create a circular doubly linked list of people
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* curr = (Node*)malloc(sizeof(Node));
        curr->data = i;
        prev->next = curr;
        curr->prev = prev;
        prev = curr;
    }
    prev->next = head;
    head->prev = prev;
    
    Node* curr = head;
    while (curr->next != curr) {// continue untill one node is left
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    int result = curr->data;
    free(curr);
    return result;
}
int josephus_2DArray(int n, int k) {
    int** people = (int**)malloc(2 * sizeof(int*));
    for (int i=0;i<2; i++) {
        people[i]=(int*)malloc(n*sizeof(int));
        for (int j=0;j<n;j++) {
            people[i][j] = j + 1;
        }
    }
    
    int remaining = n;
    int i = 0;
    int temp;
    while (remaining > 1) {
        i = (i + k - 1) % remaining;//ith person to be killed
        people[1][people[0][i]-1] = -1;
        for (int j = i; j < remaining - 1; j++) {
                people[0][j] = people[0][j+1];
        }
        remaining--;
    }
    int result = people[0][0];
    printf("%d\n", result);
    for(int j=0;j<n;j++)
        printf("%d ",people[1][j]);
    printf("\n");
    return result;
}
int main() {
    int n = 5; // Number of people
    int k = 3;  // Elimination pattern
    int result = josephus_2DArray(n, k);
    printf("\n\nThe winner is %d\n", result);
    return 0;
}
