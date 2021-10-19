#include <iostream>
#include <cstdio>
#define HEAP_MAX 100
#ifndef _WIN64
#define BLOCKSIZE 8
#elif _WIN32
#define BLOCKSIZE 4
#endif

using namespace std;

typedef struct _NODE{
    int data;
    _NODE* prev;
    _NODE* next;
} NODE;

typedef struct _NODE_HEAP{
    int use;
    NODE node;
} NODE_HEAP;

NODE_HEAP nodeHeap[100];

void InitNodeHeap(void){
    
    for(int i =0; i < HEAP_MAX; i++)
    {
        nodeHeap[i].use = 0;
    }
}

void InitNode(NODE * node){
    node->data =0;
    node->next = node;
    node->prev = node;
}

NODE* GetNode(void){
    for(int i =0; i < HEAP_MAX; i++)
    {
        if(!nodeHeap[i].use)
        {
            nodeHeap[i].use = 1;
            InitNode(&nodeHeap[i].node);
            return &nodeHeap[i].node;
        }
    }
    return NULL;
}

void DestroyNode(NODE* node)
{
    NODE_HEAP* temp = (NODE_HEAP*)(node - BLOCKSIZE);
    temp->use = 0;
}


NODE* AppendNode(NODE* list, int data)
{
    NODE* node = GetNode();
    node->data = data;
    if(list == NULL)
    {
        return node;
    }

    NODE* last = list->prev;
    last->next = node;
    list->prev = node;
    node->prev = last;
    node->next = list;
    return list;
}


NODE* DeleteNode(NODE* list, NODE* node)
{
    if(list->next == list)
    {
        DestroyNode(node);
        return NULL;
    }
    else
    {
        NODE * prev = node->prev;
        NODE * next = node->next;
        prev->next = next;
        next->prev = prev;
        DestroyNode(node);
        return (list == node) ? next : list;
    }
}

NODE* Reverse(NODE* list)
{
    // NODE * currentNode = list;
    // NODE * temp =list->next;
    // NODE * nextNode = temp;
    // while (nextNode != list)
    // {
    //     nextNode = temp;
    //     NODE* next = currentNode->next;
    //     NODE* prev = currentNode->prev;
    //     currentNode->next = prev;
    //     currentNode->prev = next;
    //     temp = temp->next;
    //     currentNode = nextNode;
    // }
    // NODE* next = currentNode->next;
    // NODE* prev = currentNode->prev;
    // currentNode->next = prev;
    // currentNode->prev = next;

    NODE * current = list;
    NODE * temp = NULL;
    while(current->next != list)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    return current;
}

int main()
{
    InitNodeHeap();
    NODE* list = NULL;
    for(int i =1; i <= 5; i++)
    {
        list = AppendNode(list,i);
    }

    for(int i =0; i < 5; i++)
    {
        cout << "data : " << list->data <<"\n";
        list = list->next;
    }
    cout <<"\n";
    list = Reverse(list);
    for(int i =0; i < 5; i++)
    {
        cout << "data : " << list->data <<"\n";
        list = list->next;
    }
    list = Reverse(list);
    cout <<"\n";

    for(int i =0; i < 5; i++)
    {
        cout << "data : " << list->data <<"\n";
        list = list->next;
    }
}