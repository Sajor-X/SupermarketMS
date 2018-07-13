#include "Super.h"

/************************************************结账************************************************/
void UserPay(struct Sale *shopping_cart, struct Good *address[])
{
        cls();
        float money = 0;
        struct Sale *sale_pointer = shopping_cart;
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\n安全交易系统已打开！");
        printf("\n\n订单开始处理...\n...\n\n订单审核通过...\n\n正在生成订单...\n\n订单生成完成！");

        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\n\t*************************订单详情**************************");
        SetConsoleTextAttribute(handle, PURPLE);
        printf("\n\n\t商品名称\t商品单价\t购买数量\t消费总价\n");
        SetConsoleTextAttribute(handle, GREEN);
        while (sale_pointer->next != NULL)
        {
                sale_pointer = sale_pointer->next;
                printf("\n\t%s\t\t%.2f\t\t%d\t\t%.2f\t\t", sale_pointer->name,
                       sale_pointer->sell_price, sale_pointer->num, (sale_pointer->sell_price) * (sale_pointer->num));

                money += (sale_pointer->sell_price) * (sale_pointer->num);
        }
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t***********************************************************");
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\t总共消费金额为：%.2f", money);


        printf("\n\n\n\t确定完成交易？\t按【Y】确认支付 【任意键】取消支付\n\t");
        ff();
        time_t timer = time(NULL);              //得到日历时间
        char flag;
        flag = getch();
        if (flag == 'Y' || flag == 'y')
        {
                char name[20];
                printf("\n\n\t请输入您的名字：");
                SetConsoleTextAttribute(handle, CYAN);
                scanf("%s", name);
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n系统正在完成交易，请稍等...");

                int i;
                struct Good *goods_address;                                             //存放商品地址
                sale_pointer = shopping_cart;
                for (i = 0; sale_pointer->next != NULL; i++)
                {
                        sale_pointer = sale_pointer->next;
                        strcpy(sale_pointer->buyer, name);                                      //记录购买者名字

                        strcpy(sale_pointer->time, ctime(&timer));                              //记录购买时间
                        goods_address = address[i];
                        goods_address->num = (goods_address->num) - (sale_pointer->num);        //更改商品数量
                        if (goods_address->num == 0)
                                Delete(goods_address);                                 //清除数量为0的商品记录
                }

                //增加商品销售记录
                sale_pointer = SALE;
                while (sale_pointer->next != NULL)  //定位到销售列表末尾
                        sale_pointer = sale_pointer->next;

                sale_pointer->next = shopping_cart->next;
                printf("\n\n\n\t交易完成，谢谢惠顾！ O(∩_∩)O~\n\n");
                printf("\n\n\t交易系统正在关闭，请稍后");
                sleep(5);
                SetConsoleTextAttribute(handle, CYAN);
        }
}

/********************************************商品销售管理********************************************/
void SaleManage()
{
        cls();
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\n\t\t\t\t销售情况查看及利润统计");
        ShowTip();
        SetConsoleTextAttribute(handle, CYAN);
        printf("\n\n\t***************************************************************************");
        if (SALE->next == NULL)
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n目前暂无销售记录！");
                Sleep(2000);
                SetConsoleTextAttribute(handle, CYAN);
        }
        else
        {
                SetConsoleTextAttribute(handle, PURPLE);
                printf("\n\n\t编号\t名称\t进价\t售价\t数量\t名字\t\t时间\n\n");
                SetConsoleTextAttribute(handle, GREEN);
                int number = 0;//商品数量
                float profit = 0;//商品利润
                struct Sale *sale_pointer = SALE;
                while (sale_pointer->next != NULL)
                {
                        sale_pointer = sale_pointer->next;
                        printf("\t %d\t %s\t %.2f\t %.2f\t %d\t %s\t %s\n", sale_pointer->id, sale_pointer->name,
                               sale_pointer->pur_price, sale_pointer->sell_price, sale_pointer->num, sale_pointer->buyer, sale_pointer->time);

                        profit = profit + ((sale_pointer->sell_price) - (sale_pointer->pur_price)) * (sale_pointer->num);
                        number = number + (sale_pointer->num);
                }
                SetConsoleTextAttribute(handle, CYAN);
                printf("\n\t***************************************************************************");
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t共销售商品%d件，纯利润为%.2f", number, profit);
                printf("\n\n\n\t按任意键继续...");
                getch();
                SetConsoleTextAttribute(handle, CYAN);
        }
}

