#include "Super.h"


/********************************************货物的删改查********************************************/
void GoodsControl(char* control)
{
        struct Good *goods;
        goods = GoodsFind(); //查找是否存在该商品

        if (goods == NULL)
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t抱歉，不存在该商品！");
                sleep(2);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else if (goods == GOOD)
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\n\t\t正在返回程序，请稍等");
                sleep(3);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else
        {
                if(!strcmp(control, "Detail"))
                {
                        cls();
                        ShowGood(goods);
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t按任意键继续...");
                        getch();
                        SetConsoleTextAttribute(handle, CYAN);
                }
                else if(!strcmp(control, "Change"))
                {
                        Change(goods);
                }
                else if(!strcmp(control, "Delete"))
                {
                        cls();
                        ShowGood(goods);
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n警告：是否确认删除？！(输入【Y】确认)");

                        char choose;
                        ff();
                        choose = tolower(getch());
                        if (choose == 'y') //删除操作
                                Delete(goods);
                        printf("\n\n\t操作成功！");
                        sleep(3);
                        SetConsoleTextAttribute(handle, CYAN);
                }
        }
}
