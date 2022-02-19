#ifndef AUTO_PTR_H
#define AUTO_PTR_H


#include <stdlib.h>
#include <assert.h>


#define auto_ptr __attribute__((cleanup(sfree)))


struct metadata {
    void (*dtor)(void*);
    void* data;
};


static struct metadata* get_metadata(void* data)
{
    return data - sizeof(struct metadata); 
}

void sfree(void* data)
{
    if( !data ) return;
    data = *(void**)data;
    if( !data ) return;
    struct metadata* ptr =  get_metadata(data);
    assert( ptr->data == data );
    if( ptr->dtor) {
        ptr->dtor(data);
    }
    free(ptr); 
}

__attribute__((malloc))
void* smalloc(size_t size, void (*dtor)(void*)) {
    struct metadata* ptr = (struct metadata*)malloc(sizeof(struct metadata) + size);
    *ptr = (struct metadata){
        .dtor = dtor,
        .data = ptr + 1
    };
    return ptr->data;
}


#endif