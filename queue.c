#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Create an empty queue */
struct list_head *q_new()
{
    struct list_head *head =
        (struct list_head *) malloc(sizeof(struct list_head));
    if (!head)
        return NULL;
    INIT_LIST_HEAD(head);
    return head;
}

/* Free all storage used by queue */
void q_free(struct list_head *head)
{
    if (!head)
        return;
    struct list_head *node = head->next;
    while (!list_empty(head)) {
        list_del(node);
        // printf("len: %d\n", q_size(head));
        element_t *ele = list_entry(node, element_t, list);
        free(ele->value);
        free(ele);
        node = head->next;
    }
    free(head);
}

/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    // Allocate a new element node
    element_t *node = (element_t *) malloc(sizeof(element_t));
    if (!node)
        return false;

    char *str = (char *) malloc(strlen(s) + 1);
    if (!str) {
        free(node);
        return false;
    }
    memcpy((void *) str, (const void *) s, strlen(s));
    str[strlen(s)] = 0;
    // Insert newly allocated node into queue
    node->value = str;
    struct list_head *cur = &(node->list);
    list_add(cur, head);
    return true;
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    element_t *node = (element_t *) malloc(sizeof(element_t));
    if (!node)
        return false;

    char *str = (char *) malloc(strlen(s) + 1);
    if (!str) {
        free(node);
        return false;
    }
    memcpy((void *) str, (const void *) s, strlen(s));
    str[strlen(s)] = 0;
    // Insert newly allocated node into queue
    node->value = str;
    struct list_head *cur = &(node->list);
    list_add_tail(cur, head);
    return true;
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{
    if (!head || list_empty(head) || !sp)
        return NULL;
    struct list_head *node = head->next;
    list_del(node);
    element_t *s = list_entry(node, element_t, list);
    int len = (bufsize - 1) < strlen(s->value) ? bufsize - 1 : strlen(s->value);
    memcpy((void *) sp, (void *) s->value, len);
    sp[len] = 0;
    return s;
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    if (!head || list_empty(head) || !sp)
        return NULL;
    struct list_head *node = head->prev;
    list_del(node);
    element_t *s = list_entry(node, element_t, list);
    int len = (bufsize - 1) < strlen(s->value) ? bufsize - 1 : strlen(s->value);
    memcpy((void *) sp, (void *) s->value, len);
    sp[len] = 0;
    return s;
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    if (!head)
        return 0;

    int len = 0;
    struct list_head *cursor;
    list_for_each(cursor, head)
        len++;
    return len;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head)
{
    if (list_is_singular(head))
        return;
    struct list_head *cur = head->next;
    struct list_head *next = cur->next;
    while (cur != head) {
        list_move(cur, head);
        cur = next;
        next = cur->next;
    }
}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending/descending order */
void q_sort(struct list_head *head, bool descend) {}

/* Remove every node which has a node with a strictly less value anywhere to
 * the right side of it */
int q_ascend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending/descending
 * order */
int q_merge(struct list_head *head, bool descend)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}
