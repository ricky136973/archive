#ifndef LIST_H
#define LIST_H

typedef struct _node {
    char ch;
    struct _node *next;
} node_t;

typedef enum{false, true} bool;
node_t *Initialize(char ch);
void PrintList(node_t *head);
void FreeList(node_t **head);
bool IsEmptyList(node_t *head); // Return true if the list is empty, false otherwise
void InsertFirstList(node_t **head, char insert_char); // Prepend a node
void InsertLastList(node_t **head, char insert_char); // Append a node
void DeleteFirstList(node_t **head); // Delete the first element in the list
void DeleteLastList(node_t **head); // Delete the last element in the list
int SizeList(node_t *head); // Return the size of the list
int SearchList(node_t **head, char target); // Count how many times target appears
void SplitList(node_t **head, node_t **tail, int pos); // Split into [0;pos-1] and [pos,end]
void MergeList(node_t **head1, node_t **head2); // Merge two lists

#endif //LIST_H
