#include "Super.h"

/********************************************管理员主菜单********************************************/
void AdminMenu()
{
        cls();
        printf("\n\n");
        printf("             ╭══════════欢═迎═使═用═════════╮      \n");
        printf("             ╰╮╭－－－－－－－－－－－－－－－－－－－－－－╮╭╯ \n");
        printf("             ▲╯║～～                                      ～║╰▲ \n");
        printf("             ◇★║～～           小型超市管理系统           ～║★◇ \n");
        printf("             ◇★║～～                                      ～║★◇ \n");
        printf("             ◇★║～～  [1]      【  新购商品入库  】       ～║★◇ \n");
        printf("             ★◇║～～  [2]      【  商品信息详情  】       ～║◇★ \n");
        printf("             ★◇║～～  [3]      【  商品信息更改  】       ～║◇★ \n");
        printf("             ★◇║～～  [4]      【  商品信息删除  】       ～║◇★ \n");
        printf("             ◇★║～～  [5]      【  商品信息浏览  】       ～║★◇\n");
        printf("             ◇★║～～  [6]      【  商品销售管理  】       ～║★◇ \n");
        printf("             ◇★║～～  [7]      【  进入用户界面  】       ～║★◇ \n");
        printf("             ★◇║～～  [0]      【  保存退出程序  】       ～║◇★ \n");
        printf("             ★◇║～～                                      ～║◇★ \n");
        printf("             ◇★║～～                                      ～║★◇ \n");
        printf("             ╭╯╰－－－－－－－－－－－－－－－－－－－－－－╯╰╮ \n");
        printf("             ╰══════════使═用═愉═快═════════╯         \n");
        printf("\n\n\t\tPress key to continue your choice ....");
}

/********************************************管理员主程序********************************************/
void AdminWindows()
{
        int flag = 1;                           //判断是否进入用户界面的标志
        char choose;
        while (flag)
        {
                AdminMenu();
                choose = getch();
                cls();

                switch (choose) {

                        case '1':
                                GoodsAdd();             //新购商品入库
                                break;

                        case '2':
                                GoodsControl("Detail"); //商品信息详情
                                break;

                        case '3':
                                GoodsControl("Change"); //商品信息更改
                                break;

                        case '4':
                                GoodsControl("Delete"); //商品信息删除
                                break;

                        case '5':
                                GoodsBrowse();          //商品信息浏览
                                break;

                        case '6':
                                SaleManage();           //商品销售管理
                                break;

                        case '7':
                                cls();
                                flag = 0;               //flag 设为0，准备进入用户界面
                                printf("\n\n\n\t即将进入用户界面，请稍等");
                                sleep(3);
                                break;                  //进入用户界面

                        case '0':
                                SaveAndExit();          //保存并退出
                                exit(0);
                }
                ff();
        }
}
