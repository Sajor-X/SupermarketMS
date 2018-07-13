#include "Super.h"

int main()
{
        Init();
        while (1)//程序运行
        {
                UserWindows(); //用户员主界面
                InventoryEarlyWarning(); //库存预警
                AdminWindows(); //管理员主界面
        }
        return 0;
}
