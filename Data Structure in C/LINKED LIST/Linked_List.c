//
// Created by Sumit Suman on 09-09-2021.
//

#include <stdio.h>
#include <stdlib.h>

//struct Node *head = NULL;
struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = (*head_ref);

    // Move head to new node
    (*head_ref) = new_node;
}

void insertAt(struct Node* head_ref, int data, int pos){
    struct Node *new_node = head_ref;
    struct Node *new_node_2 = malloc(sizeof(struct Node));
    new_node_2->data = data;
    new_node_2->next = NULL;
    pos--;

    while(pos != 1){
        new_node = new_node->next;
        pos--;
    }
    new_node_2->next = new_node->next;
    new_node->next = new_node_2;
}

// Insert the the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) last = last->next;

    last->next = new_node;
    return;
}

// Delete a node
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL) return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}

// Search a node
int searchNode(struct Node** head_ref, int key) {
    struct Node* current = *head_ref;

    while (current != NULL) {
        if (current->data == key) return 1;
        current = current->next;
    }
    return 0;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
    struct Node *current = *head_ref, *index = NULL;
    int temp;

    if (head_ref == NULL) {
        return;
    } else {
        while (current != NULL) {
            //index points to the node next to current
            index = current->next;

            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}


void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

void recursive_reverse(struct Node** head)
{
    struct Node* first;
    struct Node* rest;
    if (*head == NULL)
        return;
    first = *head;
    rest = first->next;
    if (rest == NULL)
        return;
    recursive_reverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *head = rest;
}


int main() {
    struct Node* head = NULL;
    int n1,n2,n3,n4,pos1,item_to_find;
    printf("1.Insert at beginning \n2.Insert at end \n3.Insert at desired location \n4.Deletion \n5.Display \n6.Searching \n7.Sorting \n8.Reversing \n9.Exit\n");
    int choice;
    while(choice != 10)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter value to be inserted at beginning:");
                scanf("%d",&n1);
                insertAtBeginning(&head,n1);
                break;
            case 2:
                printf("Enter value to be inserted at end:");
                scanf("%d",&n2);
                insertAtEnd(&head,n2);
                break;
            case 3:
                printf("Enter value to be inserted:");
                scanf("%d",&n3);
                printf("Enter position where to be inserted:");
                scanf("%d",&pos1);
                insertAt(&head,n3,pos1);
                break;
            case 4:
                printf("Enter node to be deleted:");
                scanf("%d",&n4);
                deleteNode(&head,n4);
                break;
            case 5:
                printList(head);
                printf("\n");
                break;
            case 6:
                printf("Enter item to search:");
                scanf("%d",&item_to_find);
                if (searchNode(&head, item_to_find)) {
                    printf("\n%d is found", item_to_find);
                } else {
                    printf("\n%d is not found", item_to_find);
                }
                printf("\n");
                break;
            case 7:
                printf("Sorted Linked List:");
                sortLinkedList(&head);
                printList(head);
                printf("\n");
                break;
            case 8:
                printf("Reversed Linked List:");
                recursive_reverse(&head);
                printList(head);
                printf("\n");
                break;

            case 9:
                exit(1);

            default:
                printf("\nInvalid Choice");
        }
    }
}


/*
insertAtEnd(&head, 1);
//insertAtBeginning(&head, 2);
//insertAtBeginning(&head, 3);
insertAtEnd(&head, 4);
insertAtEnd(&head, 9);
insertAtEnd(&head, 8);
//insertAfter(head->next, 7);
//insertAfter(head->next, 12);
insertAtEnd(&head, 13);
insertAt(head,4, 2);

printf("Linked list: ");
printList(head);

printf("\nAfter deleting an element: ");
deleteNode(&head, 3);
printList(head);

//int item_to_find = 3;
if (searchNode(&head, item_to_find)) {
    printf("\n%d is found", item_to_find);
} else {
    printf("\n%d is not found", item_to_find);
}

sortLinkedList(&head);
printf("\nSorted List: ");
printList(head);
*/