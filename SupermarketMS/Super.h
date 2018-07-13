#ifndef SUPER_H_INCLUDED
#define SUPER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define password "123" //管理员密码 最长100位
#define close_passward  "000000" //用户关闭程序密码
#define show printf("\t%d\t%s\t%c\t%d\t%.2f\t%.2f\t  %s \t\t  %d\n", goods->id, goods->name, goods->kind, goods->num, goods->pur_price, goods->sell_price, goods->date, goods->period)
#define ShoppingCart_Max 10
#define StockMin 20
#define FILENAME "file.txt"
#define GOODS_PATH "Goods.dat"
#define SALE_PATH "Sale.dat"

//商品信息
struct Good
{
        int id;                 //商品编号
        char name[20];          //商品名称
        char kind;              //商品类型
        int num;                //商品数量
        float pur_price;        //进货价格
        float sell_price;       //出售价格
        char date[128];         //生产日期
        int period;             //保质期
        struct Good *next;
}*GOOD;

//销售信息
struct Sale
{
        int id;                 //商品编号
        char name[20];          //商品名称
        float pur_price;        //进货价格
        float sell_price;       //出售价格
        int num;                //购买数量
        char buyer[20];         //顾客名字
        char time[128];         //购买时间
        struct Sale *next;
}*SALE;

void ff();                                                      //清空缓冲区
void show_file();                                               //显示欢迎界面
void sleep(int num);                                            //休息函数
void Init();                                                    //初始化文件
void AdminWindows();                                            //管理员控制
void UserMenu();                                                //管理员菜单
void UserWindows();                                             //用户控制
void AdminMenu();                                               //管理员菜单
void UserBrowse();                                              //用户浏览

void ShowTip();                                                 //提示
void cls();                                                     //清屏函数
void ShowGood(struct Good *goods);                              //显示单个物品
void ShowGoods(struct Good *goods, char type);                  //显示所有物品
void GoodShow(struct Good *goods);                              //用户展示一个物品
int IsHaveGood();                                               //是否还有货物

void GoodsAdd();                                                //货物添加
void GoodsControl(char control[]);                              //删改查控制函数
void Change(struct Good *goods);                                //更改
void Add(struct Good *goods);                                   //添加
void Delete(struct Good *goods);                                //删除
void GoodsBrowse();                                             //货物浏览

struct Good *GoodsFind();                                       //查找货物
struct Good *GoodsIdFind(int good_id);                          //通过ID查
struct Good *GoodsNameFind(char goods_name[]);                  //通过名字查
void UserPay(struct Sale *shopping_cart, struct Good *address[]);//用户支付
void UserCart();                                                //购物车
void SaleManage();                                              //账单管理

void SaveAndExit();                                             //保存退出
int GoodsSaveToFile();                                          //货物保存
int GoodsReadFromFile();                                        //货物读取
int SaleSaveToFile();                                           //账单保存
int SaleReadFromFile();                                         //账单读取
void InventoryEarlyWarning();                                   //库存预警
void goodscopy(struct Good *s1, struct Good *s2);               //结构体拷贝

enum ConsoleTextColor{  RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
                        GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
                        BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
                        YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
                        PURPLE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
                        CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
                        WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
                        BLACK = 0};
HANDLE handle;
#endif // SUPER_H_INCLUDED
