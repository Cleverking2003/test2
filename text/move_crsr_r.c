#include "_text.h"
#include "text.h"

void move_crsr_right(text txt) {
    int len = strlen(txt->cursor->line->contents);
    if (txt->cursor->position + 1 <= len) txt->cursor->position++;
}
