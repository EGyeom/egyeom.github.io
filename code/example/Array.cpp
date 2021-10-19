#include <iostream>

class Int;
class Array
{
private:
    friend Int;
    const int dim;
    int * size;
    /* data */
    struct Address
    {
        int level;
        void* next;
        /* data */
    };
    Address * top; 
public:
    Array(int dim, int * array_size) : dim(dim)
    {
        size = new int[dim];
        for(int i =0; i < dim; i++) size[i] = array_size[i];
        top = new Address;
        top->level = 0;
    }
    
    void init_Address(Address* current)
    {
        if(!current) return;
        if(current->level == dim-1){
            current->next = new int[size[current->level]];
            return; 
        }
        
        current->next = new Address[size[current->level]];
        for(int i =0; i < size[current->level]; i++)
        {
            (static_cast<Address*>(current->next)+i)->level = current->level+1;

            init_Address((static_cast<Address*>(current->next)+i));    
        }
    }

    ~Array();
};

class Int{

private:
    int level;
    Array* arr;
    void * data;
public:
    Int(int level= 0, Array* arr = NULL, void* data=NULL) : level(level)
    {
    }
    operator int(){
        return *static_cast<int *>(data); 
    }
};

Array::~Array()
{
}

int main()
{

}