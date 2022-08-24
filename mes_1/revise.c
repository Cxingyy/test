#include "address_book.h"

void revise(address_book *message, char *name, char *tel)
{
    address_book *p = message;

    while (p->next != NULL)
    {
        p = p->next;

        if (my_strcmp(p->name, name) == 0)
        {
            address_book *tmp = p;
            my_strcpy(tmp->tel, tel);
        }
    }
}

void choose3(address_book *message)
{

    printf("\n\n\n");
    printf("\t\t\t[ 1 ] 继续修改    [ 2 ] 返回目录\n");
    printf("\n\n\n");
    int choice;
    scanf("%d", &choice);
    clean();

    switch (choice)
    {
    case 1:
        revise_contact(message);
        break;

    case 2:
        printf("\n\n\n");
        printf("\t\t\t\t\t      已返回到通讯录\n");
        printf("\n\n\n");
        Switch(message);
        return;

    default:
        printf("\t\t\t输入错误，请输入1或2\n");
        choose3(message);
        return;
    }
}

void revise_contact(address_book *message)
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
        char tel[TEL_MAX] = {0};
        int choice = 0;
        address_book *p = message;

        printf("\n\n");
        print_contact(message);
        printf("\n\n");
        printf("\n\n");
        printf("\n\n");
        printf("\t\t\t\t请输入需要修改的联系人姓名：\n");
        scanf("%s", name);
        getchar();

        while (p->next != NULL)
        {
            if (judge(message, name) == -1)
            {
                printf("\n\n");
                printf("\t\t\t\t没有%s这个联系人\n", name);
                printf("\n\n");
                revise_contact(message);
                return;
            }
            else
            {
                printf("\n\n");
                printf("\t\t\t\t是否要修改此联系人?\n");
                printf("\n\n");
                print_mem(message, name);
                printf("\n\n");
                printf("\t\t\t\t [ 1 ]确认修改       [ 2 ]取消\n");
                printf("\n\n");

                scanf("%1d", &choice);
                getchar();
                if (choice == 1)
                {
                    printf("\t\t\t\t请输入修改后的号码：\n");
                    scanf("%s", tel);
                    if (judge_tel(message, tel) == -1)
                    {
                        printf("\n\n");
                        printf("\t\t\t\t号码输入有误！\n");
                        printf("\n\n");
                        revise_contact(message);
                        return;
                    }
                    else
                    {
                        revise(message, name, tel);
                        printf("\n\n\n");
                        printf("\n\n\n");
                        printf("\t\t\t\t已修改联系人\n");
                        printf("\n\n\n");
                        save_message(message); 

                        print_contact(message);
                        printf("\n\n");
                        printf("\n\n\n");
                        choose3(message);
                        return;
                    }
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