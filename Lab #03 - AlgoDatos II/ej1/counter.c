#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "counter.h"

struct _counter {
    unsigned int count;
};

counter init(void) {
    counter c = (counter)malloc(sizeof(struct _counter));
    assert(c != NULL);
    c -> count = 0;
    return c;
}

void inc(counter c) {
    assert(c != NULL);
    c->count = c->count+1;
}

bool is_init(counter c) {
   assert(c!=NULL);
   return c->count == 0; 
}

void dec(counter c) {
    assert(!is_init(c));
    c -> count--;
}

int convert_to_int(counter c){
    assert(c != NULL);
    return c->count;
}
counter copy_counter(counter c) {
    counter copy = (counter)malloc(sizeof(struct _counter));
    assert(copy != NULL);
    copy -> count = c -> count;
    return copy;    
}

void destroy_counter(counter c) {
    free(c);
}
