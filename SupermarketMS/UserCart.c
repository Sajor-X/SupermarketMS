#include "Super.h"

/***********************************************购物车**********************************************/
void UserCart()
{
        if (!IsHaveGood())
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t抱歉，商店商品已全售完，店主正在忙碌进货中.");
                sleep(2);
                SetConsoleTextAttribute(handle, CYAN);
                return ;
        }

        cls();
        SetConsoleTextAttribute(handle, YELLOW);
        printf("\n\n\n\t即将进入选购界面，请稍等.");
        sleep(2);

        struct Sale *shopping_cart; //购物车
        shopping_cart = (struct Sale *)malloc(sizeof(struct Sale));
        shopping_cart->next = NULL;   //初始化购物车列表

        int i;
        struct Good *goods, *address[ShoppingCart_Max]; //address存放商品地址 指针数组  goods货物指针

        for (i=0; i < ShoppingCart_Max; i++)
        {
                goods = GoodsFind();
                //查找商品
                SetConsoleTextAttribute(handle, YELLOW);
                if (goods == NULL)
                {
                        printf("\n\n\n\t\t抱歉，没有您需要的商品！");
                        sleep(2);
                        continue;
                }
                else if (goods == GOOD)  //在选择商品时选择  结束操作
                {
                        cls();
                        if (shopping_cart->next == NULL)
                        {
                                printf("\n\n\n\n\t\t由于您购物车空空的，将结束本次购物！");
                                printf("\n\n\n\t购物系统正在关闭，请稍等");
                                free(shopping_cart);  //销毁购物车
                                sleep(4);
                                SetConsoleTextAttribute(handle, CYAN);
                                break;
                        }
                        else
                        {
                                printf("\n\n\n\t您取消了本次选购，是否前往支付？");
                                printf("\n\n\t【Y】前往支付 【任意键】放弃购物");
                                char choose1;
                                choose1 = getch();
                                if (choose1 == 'Y' || choose1 == 'y')
                                {
                                        UserPay(shopping_cart, address); //结账
                                        SetConsoleTextAttribute(handle, CYAN);
                                        break;
                                }
                                else
                                {
                                        printf("\n\n\n\n\t\t购物系统正在关闭，请稍等");
                                        free(shopping_cart); //销毁购物车
                                        sleep(4);
                                        SetConsoleTextAttribute(handle, CYAN);
                                        break;
                                }
                        }
                }


                cls();
                GoodShow(goods);                        //显示商品信息
                SetConsoleTextAttribute(handle, YELLOW);
                struct Sale *cart_pointer = shopping_cart;
                int judge = 1;                          //判断是否重复购买

                while (cart_pointer->next != NULL)      //遍历购物车 查找购物车是否已存在该商品
                {
                        cart_pointer = cart_pointer->next;
                        judge = strcmp(cart_pointer->name, goods->name);
                        if (judge == 0)
                        {
                                printf("\t【购物车已有%d件该商品！,若要继续购买，将自动为您合并！】\n", cart_pointer->num);
                                break;
                        }
                }


                struct Sale *sale;                      //指针对销售进行操作
                sale = (struct Sale *)malloc(sizeof(struct Sale));
                printf("\n\n请输入要购买的数量：(输入 [0] 将重新选择)\t");
                SetConsoleTextAttribute(handle, CYAN);
                scanf("%d", &sale->num);
                SetConsoleTextAttribute(handle, YELLOW);
                if (sale->num == 0)                     //数量为0
                        continue;


                if (judge == 0)                         //准备合并相同商品
                        sale->num = (cart_pointer->num) + (sale->num);


                if ((sale->num) > (goods->num))         //判断 (合并后) 是否超过最大商品数量
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\n\t【友情提示：很抱歉，该商品由于销售太火爆，目前只剩下%d件了】", goods->num);
                        printf("\n\n\t\t【A】继续，购买%d件  【B】重新选择  【任意键】结束购物\n", goods->num);
                        char choose;
                        ff();
                        choose = getch();

                        if (choose == 'A' || choose == 'a')
                        {
                                sale->num = goods->num;
                                printf("\n\n\n\t【谢谢您的理解和支持！】");
                        }
                        else if (choose == 'B' || choose == 'b')
                                continue;
                        else
                                break;
                }


                if (judge == 0) //购物车存在商品时，合并商品
                {
                        cart_pointer->num = sale->num;
                        printf("\n\n\t【由于购物车存在该商品,已自动为您合并！】\n\n\n");
                }
                else //购物车不存在商品时，添加到购物车
                {
                        address[i] = goods;                     // 记录商品地址
                        strcpy(sale->name, goods->name);        // 记录商品名称
                        sale->id = goods->id;                   // 记录商品编码
                        sale->pur_price = goods->pur_price;     // 记录商品进价
                        sale->sell_price = goods->sell_price;   // 记录商品售价
                        sale->next = NULL;

                        while (cart_pointer->next != NULL)
                                cart_pointer = cart_pointer->next;
                        cart_pointer->next = sale;              // 添加到购物列车中

                        printf("\n\n\t已成功添加商品到购物车！");
                }


                if (i == (ShoppingCart_Max - 1)) //购物车满时操作
                {
                        system("cls");
                        printf("\n\n\n\n\t\t购物车已达到最大容量，将自动为您跳往支付界面！");
                        Sleep(2000);
                        UserPay(shopping_cart, address); //结账
                        break;
                }

                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\n\t\t【1】:前往支付 【2】:继续浏览 【3】:放弃购物\n");
                char choice;
                choice = getch();
                if (choice == '1')
                {
                        UserPay(shopping_cart, address); //结账
                        SetConsoleTextAttribute(handle, CYAN);
                        break;
                }
                else if (choice == '3')
                {
                        free(shopping_cart);
                        cls();
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\n\n\t\t正在退出购物系统，请稍等...");
                        sleep(2);
                        SetConsoleTextAttribute(handle, CYAN);
                        break;
                }

        }
        SetConsoleTextAttribute(handle, CYAN);
}
