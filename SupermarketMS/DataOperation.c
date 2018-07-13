#include "Super.h"

/**********************************************是否有库存********************************************/
int IsHaveGood()
{
        if (GOOD->next == NULL)
                return 0;
        return 1;
}

/********************************************新购商品入库********************************************/
void GoodsAdd()
{
        while (1)
        {
                cls();
                struct Good *goods, *exist;                             // *exist 判断是否已存在该商品
                char choose;

                ShowTip();

                printf("\n\n请输入商品信息：");

                goods = (struct Good *)malloc(sizeof(struct Good));

                printf("\n\n商品编号:");
                scanf("%d", &goods->id);
                exist = GoodsIdFind(goods->id);                         //检查编号是否重复
                if (exist != NULL)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t该商品信息已存在！请选择操作：\n\t [1] 重新输入\t [2] 前往编辑");
                        SetConsoleTextAttribute(handle, CYAN);
                        choose = getch();
                        if (choose == '2')
                                Change(exist);                          //更改
                        free(goods);
                        continue;
                }

                printf("商品名称:");
                scanf("%s", goods->name);
                exist = GoodsNameFind(goods->name);                     //检查名称是否重复
                if (exist != NULL)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t该商品信息已存在！请选择操作：\n\t [1] 重新输入\t [2] 前往编辑");
                        SetConsoleTextAttribute(handle, CYAN);
                        choose = getch();
                        if (choose == '2')
                                Change(exist);                          //更改操作
                        free(goods);
                        continue;
                }

                ff();  //清空缓冲区
                printf("商品类型:");
                scanf("%c", &goods->kind);
                goods->kind = tolower(goods->kind);

                printf("商品数量:");
                scanf("%d", &goods->num);
                while(goods->num<=0)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t输入数量有错误，请重新输入：");
                        SetConsoleTextAttribute(handle, CYAN);
                        scanf("%d", &goods->num);
                }

                printf("进货价格:");
                scanf("%f", &goods->pur_price);
                while(goods->pur_price<=0)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t输入进价有错误，请重新输入：");
                        SetConsoleTextAttribute(handle, CYAN);
                        scanf("%f", &goods->pur_price);
                }

                printf("出售价格:");
                scanf("%f", &goods->sell_price);
                while(goods->sell_price<=0)
                {
                        SetConsoleTextAttribute(handle, YELLOW);
                        printf("\n\n\t输入售价有错误，请重新输入：");
                        SetConsoleTextAttribute(handle, CYAN);
                        scanf("%f", &goods->sell_price);
                }

                printf("生产日期:");
                scanf("%s", goods->date);
                printf("保质期:");
                scanf("%d", &goods->period);

                cls();
                ShowGood(goods);
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t确定录入此商品信息？\t(按[ Y ]确认)\n");
                ff();
                choose = getch();
                if (choose == 'Y' || choose == 'y')
                {
                        Add(goods);
                }
                ff();

                printf("\n\n\t是否继续录入商品信息？\t(按[ Y ]确认)\n");
                choose = getch();
                if (choose != 'Y' && choose != 'y')
                {
                        cls();
                        printf("\n\n\n\n\t正在结束商品信息录入，即将返回主程序");
                        sleep(3);
                        SetConsoleTextAttribute(handle, CYAN);
                        break;
                }

        }
}

/********************************************商品信息查找选择********************************************/
struct Good *GoodsFind()
{
        if (!IsHaveGood())
        {
                SetConsoleTextAttribute(handle, YELLOW);
                printf("\n\n\t\t抱歉，目前商店没有商品信息");
                sleep(3);
                SetConsoleTextAttribute(handle, CYAN);
                return GOOD;
        }
        while (1)
        {
                struct Good *goods;
                char choose;
                cls();
                SetConsoleTextAttribute(handle, CYAN);
                printf("\n\n\n");
                printf("            |                                                     |\n");
                printf("           -+-----------------------------------------------------+-\n");
                printf("            |                 [A] 根据商品编号id选择              |\n");
                printf("            |                 [B] 根据商品名称name选择            |\n");
                printf("            |                 [*] 结束操作                        |\n");
                printf("            |-----------------------------------------------------|\n");
                printf("            |                   ****请选择操作****                |\n");
                printf("           -+-----------------------------------------------------+-\n");
                printf("            |                                                     |\n");
                ff();

                choose = getch();
                choose = tolower(choose);
                SetConsoleTextAttribute(handle, YELLOW);
                switch (choose){
                        case 'a':
                                printf("\n\t请输入商品编号：");
                                int goods_number;
                                SetConsoleTextAttribute(handle, CYAN);
                                scanf("%d", &goods_number);
                                goods = GoodsIdFind(goods_number);
                                break;
                        case 'b':
                                printf("\n\t请输入商品名称：");
                                ff();
                                char goods_name[20];//待输入名称
                                SetConsoleTextAttribute(handle, CYAN);
                                scanf("%s", goods_name);
                                goods = GoodsNameFind(goods_name);
                                break;
                        default:
                                goods = GOOD; break;
                }
                return goods;
        }
}

/********************************************根据id查找good********************************************/
struct Good *GoodsIdFind(int good_id)
{
        struct Good *goods = GOOD;
        while (goods->next != NULL)
        {
                goods = goods->next;
                if (goods->id == good_id)
                        return goods;
        }
        return NULL;
}

/********************************************根据名称查找********************************************/
struct Good *GoodsNameFind(char goods_name[])
{
        struct Good *goods = GOOD;
        while (goods->next != NULL)
        {
                goods = goods->next;
                if (!strcmp(goods->name, goods_name))
                        return goods;
        }
        return NULL;
}

/********************************************更改操作 ********************************************/
void Change(struct Good *goods)
{
        int flag = 0;
        char choose;
        struct Good *good_temp;
        good_temp = (struct Good *)malloc(sizeof(struct Good));
        goodscopy(goods, good_temp);
        while (1)
        {
                cls();
                ShowGood(goods);
                ShowTip();
                printf("           -+-----------------------------------------------------------------+-\n");
                printf("            |  [1]商品编号\t[2]商品名称\t[3]商品类型\t[4]商品数量   |\n");
                printf("            |  [5]进货价格\t[6]出售价格\t[7]生产日期\t[8]保质期     |\n");
                printf("            |                   [0]取消修改\t[*]保存退出                   |\n");
                printf("            |-----------------------------------------------------------------|\n");
                printf("            |                         ****请选择操作****                      |\n");
                printf("           -+-----------------------------------------------------------------+-\n");

                choose = getch();
                switch (choose) {
                        case '1':
                        {
                                int temp;
                                printf("\n\t请输入商品编号:");
                                scanf("%d", &temp);
                                if(!GoodsIdFind(temp))
                                        goods->id = temp;
                                else
                                {
                                        printf("\n\t编号重复，修改失败.");
                                        sleep(2);
                                }

                                break;
                        }
                        case '2':
                        {
                                char temp[20];
                                printf("\n\t请输入商品名称:");
                                scanf("%s", temp);
                                if(!GoodsNameFind(temp))
                                        strcpy(goods->name, temp);
                                else
                                {
                                        printf("\n\t名称重复，修改失败.");
                                        sleep(2);
                                }

                                break;
                        }
                        case '3':
                        {
                                printf("\n\t请输入商品类型:");
                                scanf("%c", &goods->kind);
                                break;
                        }
                        case '4':
                        {
                                printf("\n\t请输入商品数量:");
                                scanf("%d", &goods->num);
                                break;
                        }
                        case '5':
                        {
                                printf("\n\t请输入进货价格:");
                                scanf("%f", &goods->pur_price);
                                break;
                        }
                        case '6':
                        {
                                printf("\n\t请输入出售价格:");
                                scanf("%f", &goods->sell_price);
                                break;
                        }
                        case '7':
                        {
                                printf("\n\t请输入生产日期:");
                                scanf("%s", goods->date);
                                break;
                        }
                        case '8':
                        {
                                printf("\n\t请输入保质期:");
                                scanf("%d", &goods->period);
                                break;
                        }
                        case '0':
                        {
                                goodscopy(good_temp, goods);
                                printf("\n\n\t正在取消，请稍等");
                                sleep(3);
                                flag = 1;
                                break;
                        }
                        default:
                        {
                                printf("\n\n\t正在保存，请稍等");
                                if (goods->num == 0)
                                        Delete(goods);                                 //清除数量为0的商品记录
                                sleep(3);
                                flag = 1;
                                break;
                        }
                } // switch
                if (flag)
                        break;
        }
        free(good_temp);
}

/********************************************增添操作链表********************************************/
void Add(struct Good *goods)
{
        struct Good *goods_pointer = GOOD;
        while (goods_pointer->next != NULL)
                goods_pointer = goods_pointer->next;    //定位到商品列表末尾

        goods->next = goods_pointer->next;              //添加节点
        goods_pointer->next = goods;
}

/********************************************删除操作链表********************************************/
void Delete(struct Good *goods)
{
        struct Good *goods_pointer = GOOD;

        while (goods_pointer->next != goods)            //找到节点前一个位置
                goods_pointer = goods_pointer->next;

        goods_pointer->next = goods->next;              //删除节点
        free(goods);                                    //释放空间

}

/********************************************  库存预警  ********************************************/
void InventoryEarlyWarning()
{
        char message[1000]="", str[100];
        int f=0;
        struct Good *goods = GOOD;
        while(goods->next != NULL)
        {
                goods = goods->next;
                if(goods->num <= StockMin)
                {
                        sprintf(str, "编号:%d   商品名:%s  的商品还有 %d 件 \n", goods->id, goods->name, goods->num);
                        strcat(message, str);
                        f=1;
                }
        }
        if(f)       //没有时就不报警
        {
                strcat(message, "请抓紧进货!!!");
                MessageBox(NULL,message,"库存预警",MB_OK);
        }
}

