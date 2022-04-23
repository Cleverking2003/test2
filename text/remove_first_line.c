#include "_text.h"
#include "text.h"

void remove_first_line(text txt) {
    if (txt->length == 0) return;
    txt->length--;
    node *first = txt->begin;
    txt->begin = first->next;
    if (txt->cursor->line == first) {
        txt->cursor->line = txt->begin;
        txt->cursor->position = 0;
    }
    free(first);
}
