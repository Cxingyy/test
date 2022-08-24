#include "address_book.h"

int main(int argc, const char **argv)
{
    address_book *message = read_message();
    printf("\n\n\n");
    printf("\t\t\t\t\t      欢迎使用通讯录    \n\n\n");
    Switch(message);

    return 0;
}