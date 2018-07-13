#include "Super.h"

/********************************************保存并退出********************************************/
void SaveAndExit()
{
        SaleSaveToFile();//保存销售信息
        GoodsSaveToFile();//保存商品信息
        cls();
        printf("\n\n\n\n\n\n");

        printf("\n\t\t      ＃〓§〓〓〓〓〓§〓〓〓〓〓〓§〓〓〓〓〓§〓＃ ");
        printf("\n\t\t      ↓　　　　　↓　　　　　　↓　　　　　↓ ");
        printf("\n\t\t     ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆ ");
        printf("\n\t\t       ☆　谢　☆　☆　谢　☆　　☆　使　☆　☆　用　☆ ");
        printf("\n\t\t       ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆ ");
        printf("\n\t\t     ↓　　　　　↓　　　　　　↓　　　　　↓ ");
        printf("\n\t\t        ※　　　　　※　　　　　　※　　　　　※ ");
        printf("\n");
        Sleep(3000);
        exit(0);
}

/********************************************保存商品信息********************************************/
int GoodsSaveToFile()
{
        FILE *fp;
        if ((fp = fopen(GOODS_PATH, "wb+")) == NULL)
                return 0;

        struct Good *goods_pointer = GOOD;              //定位到链表头部
        while (goods_pointer->next != NULL)
        {
                goods_pointer = goods_pointer->next;
                fwrite(goods_pointer, sizeof(struct Good), 1, fp);//逐个保存到文件
        }
        fclose(fp);
        return 1;
}

/********************************************保存销售信息********************************************/
int SaleSaveToFile()
{
        FILE *fp;
        if ((fp = fopen(SALE_PATH, "wb+")) == NULL)
                return 0;

        struct Sale *sale_pointer = SALE;       //定位到链表头部
        while (sale_pointer->next != NULL)
        {
                sale_pointer = sale_pointer->next;
                fwrite(sale_pointer, sizeof(struct Sale), 1, fp);//逐个保存到文件
        }
        fclose(fp);
        return 1;
}

/********************************************读取商品记录********************************************/
int GoodsReadFromFile()
{
        FILE *fp;

        if ((fp = fopen(GOODS_PATH, "rb+")) == NULL)
                return 0;

        int number, i;
        fseek(fp, 0, SEEK_END);                         //定位到文件末尾
        number = ftell(fp) / sizeof(struct Good);       //求出总结点数
        fseek(fp, 0, SEEK_SET);                         //定位到文件的开始处


        struct Good *goods;
        for (i = 0; i < number; i++)
        {
                goods = (struct Good *)malloc(sizeof(struct Good));
                fread(goods, sizeof(struct Good), 1, fp);
                Add(goods);
        }
        fclose(fp);//关闭文件
        return 1;
}

/********************************************读取销售记录********************************************/
int SaleReadFromFile()
{
        FILE *fp;

        if ((fp = fopen(SALE_PATH, "rb+")) == NULL)
                return 0;

        int number, i;
        fseek(fp, 0, SEEK_END);                         //定位到文件末尾
        number = ftell(fp) / sizeof(struct Sale);       //求出总结点数
        fseek(fp, 0, SEEK_SET);                         //定位到文件的开始处

        struct Sale *sale_pointer = SALE, *sale;
        for (i = 0; i < number; i++)
        {
                sale = (struct Sale *)malloc(sizeof(struct Sale));
                fread(sale, sizeof(struct Sale), 1, fp);
                sale->next = NULL;

                while (sale_pointer->next != NULL)      //定位到销售列表末尾
                        sale_pointer = sale_pointer->next;

                sale_pointer->next = sale;              //插入到链表当中
        }
        fclose(fp);  //关闭文件
        return 1;
}

