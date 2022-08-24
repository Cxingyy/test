#ifndef _ADDRESS_BOOK_
#define _ADDRESS_BOOK_

#define NAME_MAX 10
#define TEL_MAX 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    ADD = 1,
    SHOW,
    FIND,
    DEL,
    MOD,
    CLEAR,
    EXIT,
};

typedef struct address_book
{
    char name[NAME_MAX];
    char tel[TEL_MAX];
    struct address_book *next;

} address_book;

void Switch(address_book *message);
void menu();
void clean();
address_book *address_new();
char *my_strcpy(char *dest, char *src);
int my_strcmp(char *str1, char *str2);
int address_book_null(address_book *message);
int judge(address_book *message, char *name);
void print_mem(address_book *message, char *name);
void print_contact(address_book *message);
int judge_tel(address_book *message, char *tel);
address_book *read_message();
void save_message(address_book *message);

void add_contact(address_book *message);
void show_address_book(address_book *message);
void search_contact(address_book *message);
void delete_contact(address_book *message);
void revise_contact(address_book *message);
void clear_all_contact(address_book *message);

#endif