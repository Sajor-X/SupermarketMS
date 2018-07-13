#include "Super.h"


/********************************************商品信息浏览********************************************/
void GoodsBrowse()
{
        cls();
        if (!IsHaveGood())
        {
                printf("\n\n\t\t抱歉，目前商店没有商品信息");
                sleep(3);
        }
        else
        {
                printf("\n\n\n\t\t请选择浏览方式：\n\n\t [1] 全部浏览\t  [2] 按类型浏览\n\n");
                char choose;
                ff();
                while (1)
                {
                        choose = getch();
                        if (choose == '1')
                        {
                                cls();
                                ShowGoods(GOOD, '0');                           //0代表全部类型
                                break;
                        }
                        else if (choose == '2')
                        {
                                cls();
                                ShowTip();
                                SetConsoleTextAttribute(handle, YELLOW);
                                printf("\n\n\n请选择要浏览的商品类型：");
                                SetConsoleTextAttribute(handle, CYAN);
                                char type;
                                type = tolower(getch());
                                cls();
                                ShowGoods(GOOD, type);                          //查看type类型的商品
                                break;
                        }
                }
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\n\t按任意键继续...");
                SetConsoleTextAttribute(handle, CYAN);
                getch();
        }
}

/***********************************************用户浏览********************************************/
void UserBrowse()
{
        if (!IsHaveGood())
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t抱歉，商店商品已全部售完，可爱的店主正在忙碌进货中.");
                sleep(2);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else
        {
                cls();
                struct Good *goods_pointer = GOOD;
                while (goods_pointer->next != NULL)
                {
                        goods_pointer = goods_pointer->next;
                        GoodShow(goods_pointer);
                }
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\t是否购买商品？（按 [Y] 确认）");
                SetConsoleTextAttribute(handle, CYAN);
                ff();
                char flag;
                flag = getch();
                if (flag == 'Y' || flag == 'y')
                {
                        UserCart();             //进入购物车
                }
        }
}
