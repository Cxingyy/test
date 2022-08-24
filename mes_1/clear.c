#include "address_book.h"

void clear_all_contact(address_book *message)
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
        int choice;
        printf("\t\t\t\t[1]确认清空 [2] 取消 \n");
        scanf("%d", &choice);
        clean();

        if (choice == 1)
        {

            printf("\n\n");
            printf("\t\t\t\t正在清空中......\n");
            printf("\n\n");

            address_book *p = message->next;
            address_book *q = NULL;

            while (p != NULL)
            {
                q = p;
                p = p->next;
                q = message->next;
                message->next = q->next;
                free(q);
                q = NULL;
            }
            save_message(message); 

            printf("\t\t\t\t清空成功！\n");
            printf("\n\n");
            Switch(message);
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