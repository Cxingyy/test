#include "address_book.h"

void choose(address_book *message)
{

    printf("\n\n\n");
    printf("\t\t\t[ 1 ] 再次添加     [ 2 ] 返回目录\n");
    printf("\n\n\n");
    int choice;
    scanf("%d", &choice);
    clean();

    switch (choice)
    {
    case 1:
        add_contact(message);
        break;

    case 2:
        printf("\n\n\n");
        printf("\t\t\t\t\t      已返回到通讯录\n");
        printf("\n\n\n");
        Switch(message);
        return;

    default:
        printf("\t\t\t输入错误，请输入1或2\n");
        choose(message);
        return;
    }
}

void add_contact(address_book *message)
{
    address_book *tmp = (address_book *)malloc(sizeof(address_book));
    char name[NAME_MAX] = {0};
    char tel[TEL_MAX] = {0};

    printf("\t\t\t\t请输入\n");
    printf("\t\t\t\t姓名:\n");
    scanf(" %s", name);

    if (judge(message, name) == 1)
    {
        printf("\n\n");
        printf("\t\t\t\t姓名重复!\n");
        printf("\n\n");
    }
    else
    {

        address_book *p = message;
        while (p->next != NULL && my_strcmp(p->next->name, name) == -1)
        {
            p = p->next;
        }

        my_strcpy(tmp->name, name);
        getchar();

        int num;
        if (strlen(tmp->name) < NAME_MAX)
        {
            num = NAME_MAX - strlen(tmp->name);
            for (int i = 0; i < num - 1; i++)
            {
                strcat(tmp->name, " ");
            }
        }

        printf("\t\t\t\t请输入\n");
        printf("\t\t\t\t电话:\n");
        scanf(" %s", tel);
        if (judge_tel(message, tel) == -1)
        {
            printf("\n\n");
            printf("\t\t\t\t号码输入有误！  请重新添加\n");
            printf("\n\n");
            Switch(message);
            return;
        }
        else
        {

            my_strcpy(tmp->tel, tel);
            getchar();

            int num1;
            if (strlen(tmp->tel) < TEL_MAX)
            {
                num1 = TEL_MAX - strlen(tmp->tel);
                for (int i = 0; i < num1 - 1; i++)
                {
                    strcat(tmp->tel, " ");
                }
            }

            tmp->next = p->next;
            p->next = tmp;
        }
    }

    save_message(message); 
    choose(message);
    return;
}