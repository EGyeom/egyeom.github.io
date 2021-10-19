#include <iostream>
#include <cstdio>
#define HEAP_MAX 100
#ifndef _WIN64
#define BLOCKSIZE 8
#elif _WIN32
#define BLOCKSIZE 4
#endif

typedef struct _NODELIST{
    int data;
    _NODELIST * next;
} NODELIST;

typedef struct _NODE_HEAP{
    int use;
    NODELIST node;
} NODE_HEAP;

NODE_HEAP node_heap[100];

void InitNodeHeap(void){
    for(int i =0; i < 100; i++)
    {
        node_heap[i].use =0;
    }
}

void InitNode(NODELIST* node)
{
    node->data = 0;
    node->next = node;
}

NODELIST * GetNode(void){
    for(int i =0; i < 100; i++)
    {
        if(!node_heap[i].use)
        {
            node_heap[i].use =1;
            InitNode(&node_heap[i].node);
            return &node_heap[i].node;
        }
    }
    return NULL;
}

NODELIST * AppendNodeList(NODELIST * list, int data)
{
    NODELIST * next = GetNode();
    next->data = data;
    if(list == NULL)
    {
        return next;
    }
    NODELIST * last = list;
    while(last->next != list)
    {
        last = last->next;
    }
    last->next = next;
    next->next = list;
    return list;
}

void DestroyNodeList(NODELIST * node)
{
    std::cout << node << " " << node - BLOCKSIZE << " " << sizeof(node)<<"\n";
    NODE_HEAP * temp = (NODE_HEAP*)((bool*)node - BLOCKSIZE);
    temp->use = 0;
}

NODELIST * deleteNodeList(NODELIST * list, NODELIST *node)
{
    NODELIST * last = list;

    while (last->next != node)
    {
        last = last->next;
    }

    last->next = node->next;
    if(list == node)
    {
        list = list->next;
    }
    DestroyNodeList(node);
    return list;
}

NODELIST * reverse(NODELIST * list){

    NODELIST * next = list;
    NODELIST * current = list;
    NODELIST * temp =list->next;
    while (temp != list)
    {
        next = temp;
        temp = temp->next;
        next->next = current;
        current = next;
    }
    list->next = current;
    return current;
}

int main()
{
    NODELIST * list = NULL;
    for(int i =1; i <= 5; i++)
    {
        list = AppendNodeList(list,i);
    }
    // while(list->next != list)
    // {
    //     std::cout << list->data << "\n";
    //     list = deleteNodeList(list,list);
    // }
    // std::cout << list->data << "\n";
    for(int i =1; i <=10; i++)
    {
        std::cout << list->data << "\n";
        list = list->next;
    }
    std::cout <<"\n";
    list = reverse(list);

    for(int i =1; i <=10; i++)
    {
        std::cout << list->data << "\n";
        list = list->next;
    }
    list = reverse(list);

    for(int i =1; i <=10; i++)
    {
        std::cout << list->data << "\n";
        list = list->next;
    }
}