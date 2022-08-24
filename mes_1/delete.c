#include "address_book.h"

void delete (address_book *message, char *name)
{
    address_book *p = message;
    address_book *q = NULL;

    while (p->next != NULL)
    {
        q = p;
        p = p->next;

        if (my_strcmp(p->name, name) == 0)
        {
            address_book *tmp = p;
            q->next = p->next;
            free(tmp);
            tmp = NULL;
            return;
        }
    }
}

void choose2(address_book *message)
{

    printf("\n\n\n");
    printf("\t\t\t[ 1 ] 继续删除     [ 2 ] 返回目录\n");
    printf("\n\n\n");
    int choice;
    scanf("%d", &choice);
    clean();

    switch (choice)
    {
    case 1:
        delete_contact(message);
        break;

    case 2:
        printf("\n\n\n");
        printf("\t\t\t\t\t      已返回到通讯录\n");
        printf("\n\n\n");
        Switch(message);
        return;

    default:
        printf("\t\t\t输入错误，请输入1或2\n");
        choose2(message);
        return;
    }
}

void delete_contact(address_book *message)
{
    if (address_book_null(message) == 1)
    {
        printf("\n\n \n");

        printf("\t\t\t\t通讯录为空，请添加联系人\n");
        printf("\n\n \n");
        Switch(message);
        return;
    }
    else
    {

        char name[NAME_MAX] = {0};
        int choice = 0;
        address_book *p = message;

        printf("\n\n");
        print_contact(message);
        printf("\n\n");
        printf("\n\n");
        printf("\n\n");
        printf("\t\t\t\t请输入需要删除的联系人姓名：\n");
        scanf("%s", name);
        getchar();

        while (p->next != NULL)
        {
            if (judge(message, name) == -1)
            {
                printf("\n\n");
                printf("\t\t\t\t没有%s这个联系人\n", name);
                printf("\n\n");
                delete_contact(message);
                return;
            }
            else
            {
                printf("\n\n");
                printf("\t\t\t\t是否要删除此联系人?\n");
                printf("\n\n");
                print_mem(message, name);
                printf("\n\n");
                printf("\t\t\t\t [ 1 ]确认删除       [ 2 ]取消\n");
                printf("\n\n");

                scanf("%1d", &choice);
                getchar();

                if (choice == 1)
                {

                    delete (message, name);

                    printf("\n\n\n");
                    printf("\n\n\n");
                    printf("\t\t\t\t已删除联系人\n");
                    printf("\n\n\n");
                    save_message(message); 

                    print_contact(message);
                    printf("\n\n");
                    printf("\n\n\n");
                    choose2(message);
                    return;
                }
                else if (choice == 2)
                {
                    Switch(message);
                    return;
                }
                else
                {
                    printf("\t\t\t\t输入错误，请输入1或2\n");
                }
            }
        }
    }
}