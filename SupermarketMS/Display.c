#include "Super.h"

/********************************************商品信息显示********************************************/
void GoodShow(struct Good *goods)
{
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t***************商品信息******************");
        SetConsoleTextAttribute(handle, GREEN);
        printf("\n\t商品编号...%30d\n", goods->id);
        printf("\n\t-----------------------------------------");
        printf("\n\t商品名称...%30s\n", goods->name);
        printf("\n\t-----------------------------------------");
        printf("\n\t商品数量...%30d\n", goods->num);
        printf("\n\t-----------------------------------------");
        printf("\n\t出售价格...%30.2f\n", goods->pur_price);
        printf("\n\t-----------------------------------------");
        printf("\n\t生产日期...%30s\n", goods->date);
        printf("\n\t-----------------------------------------");
        printf("\n\t保质期...%32d\n", goods->period);
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\t-----------------------------------------\n\n");
        SetConsoleTextAttribute(handle, CYAN);
}

/*****************************************浏览某个商品***********************************************/
void ShowGood(struct Good *goods)
{

        printf("\n\n\t************************************************************************");
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t编号\t名称\t类型\t数量\t进价\t售价\t生产日期\t保质期 \n\n");
        SetConsoleTextAttribute(handle, GREEN);
        show;
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t************************************************************************");
}

/*****************************************浏览所有商品***********************************************/
void ShowGoods(struct Good *goods, char type)
{
        printf("\n\n\t************************************************************************");
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t编号\t名称\t类型\t数量\t进价\t售价\t生产日期\t保质期 \n\n");
        while (goods->next != NULL) {
                goods = goods->next;
                if(type == '0')
                {
                    if(goods->num < StockMin)                   //库存预警 red
                                SetConsoleTextAttribute(handle, RED);
                    else
                                SetConsoleTextAttribute(handle, GREEN);
                        show;
                }

                else {
                        if(goods->kind == type)
                                show;
                }
        }
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t************************************************************************");
}
