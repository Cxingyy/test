#include "address_book.h"

//* 定义一个空的通讯录

address_book *address_new()
{
    address_book *message = (address_book *)malloc(sizeof(address_book));
    message->next = NULL;

    return message;
}

//* 判断通讯录是为空

int address_book_null(address_book *message)
{
    if (message->next == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//* 清理垃圾字符

void clean()
{
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n')
        ;
}

//* 功能列表

void Switch(address_book *message)
{
    menu();

    int choice;

    scanf("%d", &choice);
    clean();

    switch (choice)
    {

    case ADD:

        add_contact(message);

        break;

    case SHOW:

        show_address_book(message);

        break;

    case FIND:

        search_contact(message);

        break;

    case DEL:

        delete_contact(message);

        break;

    case MOD:

        revise_contact(message);

        break;

    case CLEAR:

        clear_all_contact(message);

        break;

    case EXIT:

        printf("\t\t\t\t\t已退出通讯录\n");

        return;

    default:

        printf("\t\t\t\t    输入错误，请输入1～7\n");
        Switch(message);
        printf("\n\n\n");

        break;
    }
}

//* 菜单列表

void menu()
{

    printf("\n");
    printf("\t\t\t\t******************************************\n");
    printf("\t\t\t\t*************     通讯录     *************\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t*         [ 1 ] >>> 添加用户信息         *\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t*         [ 2 ] >>> 查看用户信息         *\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t*         [ 3 ] >>> 搜索用户信息         *\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t*         [ 4 ] >>> 删除用户信息         *\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t*         [ 5 ] >>> 修改用户信息         *\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t*         [ 6 ] >>>  清空通讯录          *\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t*         [ 7 ] >>>  退出通讯录          *\n");
    printf("\t\t\t\t*                                        *\n");
    printf("\t\t\t\t******************************************\n");
    printf("\n\n\n\n\n\n");
}

//* 实现my_strcpy函数

char *my_strcpy(char *dest, char *src)
{

    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src;

    return dest;
}

//* 实现my_strcmp函数

int my_strcmp(char *str1, char *str2)
{
    while ((*str1 != '\0') && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    int t;
    t = *str1 - *str2;
    if (t == 0)
        return 0;
    if (t > 0)
        return 1;
    if (t < 0)
        return -1;
}

//* 判断有没有这个输入的姓名

int judge(address_book *message, char *name)
{
    address_book *p = message;

    while (p->next != NULL)
    {
        p = p->next;

        if (my_strcmp(p->name, name) == 0)
        {
            return 1;
        }
    }
    return -1;
}

//* 打印单独联系人

void print_mem(address_book *message, char *name)
{
    address_book *p = message;

    while (p->next != NULL)
    {
        p = p->next;

        if (my_strcmp(p->name, name) == 0)
        {
            printf("\t\t\t\t%s\t%s\n", p->name, p->tel);
            return;
        }
    }
}

//* 打印所有联系人

void print_contact(address_book *message)
{

    if (address_book_null(message) == 1)
    {
        printf("\n\n \n");

        printf("\t\t\t\t通讯录为空，请添加联系人\n");
        printf("\n\n \n");
        Switch(message);
        return;
    }
    address_book *p = message;
    int i = 0;

    printf("\t\t\t\t序号:\t姓名:\t\t电话号码:\n");
    while (p->next != NULL)
    {

        printf("\t\t\t\t%d\t%s\t%s\n", i + 1, p->next->name, p->next->tel);
        p = p->next;
        i++;
    }
}

//* 判断输入的电话号码格式是否正确

int judge_tel(address_book *message, char *tel)
{
    int i = 0;
    while (tel[i] != '\0')
    {
        if ((strlen(tel) > 11) || (tel[i] < '0' || tel[i] > '9'))
        {

            return -1;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

//* 读取文件里的数据存入到通讯录（链表）中
address_book *read_message()
{
    address_book *message = (address_book *)malloc(sizeof(address_book));
    address_book *p = message;
    address_book *tmp;
    FILE *fp = fopen("message.txt", "r");

    if (fp == NULL)
    {
        message->next = NULL;
        return message;
    }

    while (!feof(fp))
    {
        tmp = (address_book *)malloc(sizeof(address_book));
        memset(tmp, 0, sizeof(address_book));
        char a;
        fread(tmp, sizeof(address_book) - sizeof(address_book *), 1, fp);
        fread(&a, 1, 1, fp);

        if (feof(fp))
        {
            break;
        }
        p->next = tmp;
        p = p->next;
    }
    fclose(fp);
    return message;
}

//* 保存数据到文件

void save_message(address_book *message)
{
    address_book *p = message->next;

    FILE *fp = fopen("message.txt", "w");
    while (p != NULL)
    {
        fwrite(p, 1, sizeof(address_book) - sizeof(address_book *), fp);
        fprintf(fp, "\n");
        p = p->next;
    }
    fclose(fp);
}