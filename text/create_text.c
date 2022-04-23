/**
 * create_text.c -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{  
    /* Создаем структуру описания текста */
    text txt = (list *) malloc(sizeof(list));
    
    assert(txt && "Not enough memory!");
    /* Создаем структуру описания курсора */
    txt->cursor = (crsr *) malloc(sizeof(crsr));

    assert(txt->cursor && "Not enough memory!");
    
    /* Только что созданный текст не содержит ни одной строки */
    txt->begin = NULL;
    txt->end = NULL;
    txt->length = 0;
    
    /* Курсор не настроен ни на какой символ текста */
    txt->cursor->line = NULL;
    txt->cursor->position = 0;
    
    return txt;
}
