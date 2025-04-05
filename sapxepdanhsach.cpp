#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
} SinhVien;
int compareHoTen(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->hoTen, sv2->hoTen);
}

int compareDiaChi(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->diaChi, sv2->diaChi);
}

int compareLop(SinhVien* sv1, SinhVien* sv2) {
    return strcmp(sv1->lop, sv2->lop);
}

int compareKhoa(SinhVien* sv1, SinhVien* sv2) {
    return sv1->khoa - sv2->khoa;
}

void nhapSinhVien(SinhVien* sv) {
    printf("Nhap ho ten: ");
    scanf(" %[^\n]", sv->hoTen);
    printf("Nhap dia chi: ");
    scanf(" %[^\n]", sv->diaChi);
    printf("Nhap lop: ");
    scanf(" %[^\n]", sv->lop);
    printf("Nhap khoa: ");
    scanf("%d", &sv->khoa);
}

void xuatSinhVien(SinhVien* sv) {
    printf("Ho ten: %s, Dia chi: %s, Lop: %s, Khoa: %d\n", sv->hoTen, sv->diaChi, sv->lop, sv->khoa);
}

B
// Định nghĩa cấu trúc NodeSV
typedef struct NodeSV {
    SinhVien data;
    struct NodeSV* next;
} NodeSV;
typedef struct {
    NodeSV* head;
} ListSV;
void initListSV(ListSV* list) {
    list->head = NULL;
}

void destroyListSV(ListSV* list) {
    NodeSV* current = list->head;
    NodeSV* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

void addElementSV(ListSV* list, SinhVien sv) {
    NodeSV* newNode = (NodeSV*)malloc(sizeof(NodeSV));
    newNode->data = sv;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        NodeSV* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void removeElementSV(ListSV* list, char* hoTen) {
    NodeSV* temp = list->head;
    NodeSV* prev = NULL;

    while (temp != NULL && strcmp(temp->data.hoTen, hoTen) != 0) {
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
void addListSV(ListSV* list, ListSV* otherList) {
    NodeSV* temp = otherList->head;
    while (temp != NULL) {
        addElementSV(list, temp->data);
        temp = temp->next;
    }
}
void printListSV(ListSV* list) {
    NodeSV* temp = list->head;
    while (temp != NULL) {
        xuatSinhVien(&temp->data);
        temp = temp->next;
    }
}
void sortListSV(ListSV* list, int (*compare)(SinhVien*, SinhVien*)) {
    NodeSV* i, *j;
    SinhVien temp;

    for (i = list->head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (compare(&i->data, &j->data) > 0) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    ListSV list;
    initListSV(&list);

    printf("Nhap 10 sinh vien:\n");
    for (int i = 0; i < 10; i++) {
        SinhVien sv;
        nhapSinhVien(&sv);
        addElementSV(&list, sv);
    }
    printf("Danh sach sinh vien:\n");
    printListSV(&list);

    removeElementSV(&list, "Nguyen Van Teo");

    NodeSV* temp = list.head;
    NodeSV* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->data.diaChi, "Nguyen Van Cu") == 0) {
            if (prev == NULL) {
                list.head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    SinhVien svMoi = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009};
    addElementSV(&list, svMoi);
    printf("Danh sach sinh vien sau khi them va xoa:\n");
    printListSV(&list);
    sortListSV(&list, compareHoTen);
    printf("Danh sach sinh vien sau khi sap xep theo ho ten:\n");
    printListSV(&list);
    destroyListSV(&list);

    return 0;
}
