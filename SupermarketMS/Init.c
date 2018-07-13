#include "Super.h"


/*************************************读取文件字符画函数*********************************************/
void show_file() {
        FILE *p = fopen(FILENAME, "r");
        char c;
        int i=0;
        while(fscanf(p,"%c",&c) != EOF)
        {
                if(i == 0)
                        SetConsoleTextAttribute(handle, RED);
                else if(i == 1)
                        SetConsoleTextAttribute(handle, BLUE);
                else if(i == 2)
                        SetConsoleTextAttribute(handle, GREEN);
                else if(i == 3)
                        SetConsoleTextAttribute(handle, CYAN);
                else if(i == 4)
                        SetConsoleTextAttribute(handle, PURPLE);
                else if(i == 5)
                        SetConsoleTextAttribute(handle, YELLOW);
                //else if(i == 6)
                        //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green | red | blue);
                else
                {
                        i=0;
                        SetConsoleTextAttribute(handle, RED);
                }
                printf("%c",c);
                i++;
        }
        fclose(p);
}


/********************************************初始化界面********************************************/
void Init()
{
        handle = GetStdHandle(STD_OUTPUT_HANDLE);
        char color[10] = "color ";
        char srands[16] = "0123456789abcdef";
        int r, i;
        srand(time(0));
        system("title 小型超市管理系统");               //设置cmd窗口标题
        //system("mode con cols=100 lines=35");
        show_file();
        Sleep(2000);
        cls();

        printf("\n\n");
        printf("             ╭══════════欢═迎═使═用═════════╮      \n");
        printf("             ╰╮╭－－－－－－－－－－－－－－－－－－－－－－╮╭╯ \n");
        printf("             ▲╯║～～                                    ～～║╰▲ \n");
        printf("             ◇★║～～           小型超市管理系统         ～～║★◇ \n");
        printf("             ◇★║～～                                    ～～║★◇ \n");
        printf("             ◇★║～～                                    ～～║★◇ \n");
        printf("             ★◇║～～             祝您使用愉快           ～～║◇★ \n");
        printf("             ▼╮║～～                                    ～～║╭▼ \n");
        printf("             ╭╯╰－－－－－－－－－－－－－－－－－－－－－－╯╰╮ \n");
        printf("             ╰══════════使═用═愉═快═════════╯         \n");
        printf("\n");

        SALE = (struct Sale *)malloc(sizeof(struct Sale));
        GOOD = (struct Good *)malloc(sizeof(struct Good));
        SALE->next = NULL;              //初始化账单
        GOOD->next = NULL;              //初始化货物
        SaleReadFromFile();             //读取销售记录
        GoodsReadFromFile();            //读取商品记录

        for(i=0; i<10; i++)             //闪瞎的随机变色
        {
                r = rand()%16;
                color[6] = srands[r];
                r = rand()%16;
                color[7] = srands[r];
                system(color);
                Sleep(100);
        }

        SetConsoleTextAttribute(handle, CYAN | 0);
}

