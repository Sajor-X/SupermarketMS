#include "Super.h"

/******************************************清空缓冲区************************************************/
void ff()
{
        fflush(stdin);          //时刻需要用一用
}

/**********************************************清屏**************************************************/
void cls()
{
        system("cls");
        ff();                   //时刻需要用一用
}

/********************************************显示提示*************************************************/
void ShowTip()
{
        SetConsoleTextAttribute(handle, RED); //设置当前输出为红色
        printf("\n\n\t\t\t r:日用品 w:文化用品 s:食品 d:电子产品\n\n");
        SetConsoleTextAttribute(handle,  CYAN);
}

/********************************************睡眠函数********************************************/
void sleep(int num)
{
        int i;
        for(i=0; i<num; i++)
        {
                Sleep(1000);
                printf(".");            //假装在加载
        }
}

/********************************************货物拷贝函数********************************************/
void goodscopy(struct Good *s1, struct Good *s2)
{
        s2->id  = s1->id;
        s2->num = s1->num;
        s2->kind= s1->kind;
        s2->period = s1->period;
        s2->pur_price  = s1->pur_price;
        s2->sell_price = s1->sell_price;
        strcpy(s2->name, s1->name);
        strcpy(s2->date, s1->date);
}
