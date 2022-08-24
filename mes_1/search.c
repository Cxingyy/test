#include "address_book.h"

void choose1(address_book *message)
{

    printf("\n\n\n");
    printf("\t\t\t[ 1 ] 继续查找     [ 2 ] 返回目录\n");
    printf("\n\n\n");
    int choice;
    scanf("%d", &choice);
    clean();

    switch (choice)
    {
    case 1:
        search_contact(message);
        break;

    case 2:
        printf("\n\n\n");
        printf("\t\t\t\t\t      已返回到通讯录\n");
        printf("\n\n\n");
        Switch(message);
        return;

    default:
        printf("\t\t\t输入错误，请输入1或2\n");
        choose1(message);
        return;
    }
}

void search_contact(address_book *message)
{

    if (address_book_null(message) == 1)
    {
        printf("\n\n \n");

        printf("\t\t\t\t通讯录为空，请添加联系人\n");
        Switch(message);
        return;
    }
    else
    {

        char name[NAME_MAX] = {0};
        int choice = 0;
        address_book *p = message;

        printf("\n\n");
        printf("\t\t\t\t请输入需要查找号码联系人的姓名：\n");
        scanf("%s", name);
        getchar();

        while (p->next != NULL)
        {
            if (judge(message, name) == -1)
            {
                printf("\n\n");
                printf("\t\t\t\t没有%s这个联系人\n", name);
                printf("\n\n");
                Switch(message);
                return;
            }
            else
            {
                printf("\n\n");
                printf("\t\t\t\t该联系人的信息为:\n");
                print_mem(message, name);
                printf("\n\n");
                choose1(message);
                return;
            }
        }
    }
}