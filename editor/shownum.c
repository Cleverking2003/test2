/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"

static void shownum_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void shownum(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, shownum_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void shownum_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    printf("%d: ", index);
    if (cursor != -1) {
        char temp = contents[cursor];
        contents[cursor] = '\0';
        printf("%s", contents);
        printf("|");
        contents[cursor] = temp;
        printf("%s\n", contents + cursor);
        return;
    }
    
    /* Выводим строку на экран */
    printf("%s\n", contents);
}
