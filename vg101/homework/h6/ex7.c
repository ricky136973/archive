#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ex7() {
    node_t *a = Initialize('1');
    node_t *b = NULL;
    PrintList(a);

    InsertFirstList(&a, 'V');
    InsertFirstList(&a, 'M');
    PrintList(a);

    InsertLastList(&a, 'C');
    PrintList(a);

    SplitList(&a, &b, 2);
    PrintList(a);
    PrintList(b);

    DeleteFirstList(&a);
    PrintList(a);

    InsertLastList(&a, 'G');
    DeleteLastList(&b);
    PrintList(b);

    InsertLastList(&b,'0');
    PrintList(b);

    InsertLastList(&b, '1');
    PrintList(b);

    MergeList(&a,&b);
    PrintList(a);

    char target='G';
    printf("Count '%c': %d\n",target, SearchList(&a,target));
    target='1';
    printf("Count '%c': %d\n",target, SearchList(&a,target));
    FreeList(&a);

    return 0;
}

node_t *_Tail(node_t *head) {
    if (!head) return NULL;
    node_t *tail;
    for (tail = head; tail->next != NULL; tail = tail->next);
    return tail;
}

node_t *Initialize(char ch) {
    node_t *head = (node_t*)calloc(1, sizeof(node_t));
    if (!head) {
        fprintf(stderr, "Failed to assign memory!\n");
        exit(-1);
    }
    head->next = NULL;
    head->ch = ch;
    return head;
}

void PrintList(node_t *head) {
    node_t *temp = head;
    printf("***Print Linked List***\n");
    while (temp != NULL) {
        printf("%c ", temp->ch);
        temp = temp->next;
    }
    printf("\n****Print Finished****\n\n");
}

void FreeList(node_t **head) {
    node_t *tmp = NULL;
    node_t *pHead = *head;
    while (pHead->next != NULL) {
        tmp = pHead;
        pHead = pHead->next;
        free(tmp);
    }
    free(pHead);
}

bool IsEmptyList(node_t *head) {
    return head == NULL;
}

void InsertFirstList(node_t **head, char insert_char) {
    node_t *pHead = *head;
    node_t *pNew = Initialize(insert_char);
    pNew->next = pHead;
    *head = pNew;
}

void InsertLastList(node_t **head, char insert_char) {
    node_t *pHead = *head;
    node_t *pNew = Initialize(insert_char);
    if (IsEmptyList(pHead)) {
        pNew->next = pHead;
        *head = pNew;
        return;
    }
    node_t *pTail = _Tail(pHead);
    pTail->next = pNew;
}

void DeleteFirstList(node_t **head) {
    node_t *pHead = *head;
    *head = pHead->next;
    free(pHead);
}

void DeleteLastList(node_t **head) {
    node_t *pHead = *head;
    if (pHead->next == NULL) {
        free(pHead);
        *head = NULL;
        return;
    }
    node_t *pTail;
    for (pTail = pHead; pTail->next->next != NULL; pTail = pTail->next);
    free(pTail->next);
    pTail->next = NULL;
}

int SizeList(node_t *head) {
    int count = 0;
    for (node_t *ptr = head; ptr != NULL; ptr = ptr->next) {
        ++count;
    }
    return count;
}

int SearchList(node_t **head, char target) {
    int count = 0;
    for (node_t *ptr = *head; ptr != NULL; ptr = ptr->next) {
        ptr->ch == target ? ++count : 0;
    }
    return count;
}

void SplitList(node_t **head, node_t **tail, int pos) {
    node_t *ptr = *head;
    if (!ptr) return;
    if (pos == 0) {
        *tail = *head;
        *head = NULL;
        return;
    }
    for (int i = 1; i < pos; ++i) {
        ptr = ptr->next;
        if (!ptr) {
            *tail = NULL;
            return;
        }
    }
    *tail = ptr->next;
    ptr->next = NULL;
}

void MergeList(node_t **head1, node_t **head2) {
    node_t *pHead1 = *head1;
    node_t *pHead2 = *head2;
    if (!pHead2) return;
    if (!pHead1) {
        *head1 = pHead2;
        *head2 = NULL;
        return;
    }
    node_t *pTail1 = _Tail(pHead1);
    pTail1->next = pHead2;
    *head2 = NULL;
}
