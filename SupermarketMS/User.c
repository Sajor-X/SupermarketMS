#include "Super.h"

/********************************************用户主菜单********************************************/
void UserMenu()
{
        cls();
        printf("\n\n");
        printf("             ╭══════════欢═迎═使═用═════════╮      \n");
        printf("             ╰╮╭－－－－－－－－－－－－－－－－－－－－－－╮╭╯ \n");
        printf("             ▲╯║～～              请选择操作            ～～║╰▲ \n");
        printf("             ◇★║～～                                    ～～║★◇ \n");
        printf("             ◇★║～～             [1] 浏览商品           ～～║★◇ \n");
        printf("             ◇★║～～                                    ～～║★◇ \n");
        printf("             ★◇║～～             [2] 购买商品           ～～║◇★ \n");
        printf("             ▼╮║～～                                    ～～║╭▼ \n");
        printf("             ╭╯╰－－－－－－－－－－－－－－－－－－－－－－╯╰╮ \n");
        printf("             ╰══════════使═用═愉═快═════════╯         \n");
        printf("\n");
}

/********************************************用户主程序********************************************/
void UserWindows()
{
        char choose[100] = "";
        while (1)
        {
                UserMenu();  //用户主菜单

                scanf("%s", choose);
                if (!strcmp(choose, "1"))
                        UserBrowse();
                else if (!strcmp(choose, "2"))
                {
                        UserCart();  //进入购物车
                }
                else if (!strcmp(choose, close_passward))
                {
                        SaveAndExit();
                }

                else if (!strcmp(choose, password))
                        break;
        }
}
