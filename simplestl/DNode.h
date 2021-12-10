/*
    A node class that has references to the data and to the next and previous nodes
*/

#ifndef DNODE_H_
#define DNODE_H_

template <typename DataType>
struct DNode
{
    DataType data;      // copy of the data
    DNode* next;        // pointer to the next DNode
    DNode* prev;        // pointer to the previous DNode;

    DNode(const DataType& the_data, 
        DNode* prev_val = NULL,
        DNode* next_val = NULL) : data(the_data),next(next_val), prev(prev_val){} 
};



#endif
