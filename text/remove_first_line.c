#include "_text.h"
#include "text.h"

void remove_first_line(text txt) {
    node *first = txt->begin;
    if (first) {
        txt->begin = first->next;
        if (txt->cursor->line == first) {
            txt->cursor->line = txt->begin;
            txt->cursor->position = 0;
        }
        free(first);
    }
}
