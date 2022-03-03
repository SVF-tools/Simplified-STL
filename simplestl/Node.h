/* A Node for a singly-linked list */

#ifndef NODE_H_
#define NODE_H_

template<typename T>
struct Node{
    T data;         // The data
    Node* next;     // The pointer to the next node

    Node(const T& data_item, Node* next_ptr = NULL): data(data_item), next(next_ptr) {}
};

#endif