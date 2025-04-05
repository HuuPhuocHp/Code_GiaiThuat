#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} ListInt;
void initList(ListInt* list) {
    list->head = NULL;
}

void destroyList(ListInt* list) {
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

void addElement(ListInt* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeElement(ListInt* list, int value) {
    Node* temp = list->head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void addList(ListInt* list, ListInt* otherList) {
    Node* temp = otherList->head;
    while (temp != NULL) {
        addElement(list, temp->data);
        temp = temp->next;
    }
}

void printList(ListInt* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    ListInt list1, list2;
    initList(&list1);
    initList(&list2);


    printf("Nhap 10 so nguyen vao danh sach 1:\n");
    for (int i = 0; i < 10; i++) {
        int value;
        scanf("%d", &value);
        addElement(&list1, value);
    }

    printf("Danh sach 1: ");
    printList(&list1);
    int k;
    printf("Nhap so k can xoa: ");
    scanf("%d", &k);
    removeElement(&list1, k);

    printf("Danh sach 1 sau khi xoa %d: ", k);
    printList(&list1);
    printf("Nhap 5 so nguyen vao danh sach 2:\n");
    for (int i = 0; i < 5; i++) {
        int value;
        scanf("%d", &value);
        addElement(&list2, value);
    }

1
    addList(&list1, &list2);

    
    printf("Danh sach 1 sau khi them danh sach 2: ");
    printList(&list1);

    destroyList(&list1);
    destroyList(&list2);

    return 0;
}
