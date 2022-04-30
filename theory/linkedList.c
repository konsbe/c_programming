#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>



struct Node {
    int data;
    struct Node* next;
};
void printList(struct Node *n);

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;      // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;
    printf("%p\n", head);
    printf("%p\n", head->next);
    printf("%p\n", second);
    printf("%p\n", malloc(sizeof(struct Node)));
    printf("%p\n", (struct Node*)malloc(sizeof(struct Node)));

    printList(head);

    return 0;
// This function prints contents of linked list starting from
// the given node
}
void printList(struct Node* n){
    while (n != NULL) {
        printf(" %d \n", n->data);
        n = n->next;
    }
}