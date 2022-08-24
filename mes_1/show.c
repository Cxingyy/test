#include "address_book.h"

void show_address_book(address_book *message)
{
    if (address_book_null(message) == 1)
    {
        printf("\n\n \n");

        printf("\t\t\t\t通讯录为空，请添加联系人\n");
        printf("\n\n \n");
        Switch(message);
        return;
    }

    print_contact(message);
    printf("\n\n\n\n");
    Switch(message);
    return;
}