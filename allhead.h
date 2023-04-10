#ifndef ALL_H_INCLUDED
#define ALL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int savemark=0;//是用于标记数据是否被修改
int month=0;    //月份
int fuzzymark=0;//模糊查询标识

//数据结构
typedef struct all_rate//定义结构体储存利率信息
{
    double normal_rate;         //活期利率
    double rate_oneY;           //一年利率
    double rate_twoY;           //两年利率
    double rate_threeY;         //三年利率
    double rate_fiveY;          //五年利率
    long long int first_account;//账号变量
} all_rate;
struct all_rate RATE;//定义结构体RATE，用于储存利率
typedef struct User          //定义结构体储存用户信息
{
    char realname[12];        //姓名
    char username[12];        //用户名
    char password[12];        // 用户密码
    long long int account;   //银行卡账号
    double normal_balance;   //用户活期存款余额
    int nor_year;            //活期年
    int nor_month;           //活期月
    int nor_day;             //活期日
    double regular_balance;  //用户定期存款余额
    int reg_year;            //定期年
    int reg_month;           //定期月
    int reg_day;             //定期日
    double interest;         //定期到期可获利息
    int regular_year;        //定期存款年限
    int rank;                //用户排序标记
} User;
typedef struct Node
{
    User data;//数据域
    struct node *next;//指针域
} Node,*Head;

//函数声明
void AccountInfo(Node *p,char u_name,Head list); //账户明细
void Administrator(Head list);                //管理员菜单
void AdminLogin(Head list);                   //管理员登录
void AddUser(Head list);                     //添加用户函数
void Add_Normal(Node *p,char u_name,Head list);//活期存款
void Add_Regular(Node *p,char u_name,Head list);//定期存款
void Withdraw_Nomal(Node *p,char u_name,Head list);//活期取款
void Modify_NR(Node *p,char u_name,Head list);    //活改定
void modify_nr(Node *p,char u_name,Head list);
void Change_normal_rate();                   //活期利率变更函数
void Change_regular_rate();                  //定期利率变更函数
void Change_remind(int x);                   //利率变更提醒函数
void DeleteUser(Head list);                  //删除用户函数
void FindUser(Head list);                    //查找用户函数
void GetMonth();                             //获取月份
void GetTime(Node *p,char u_name,Head list);//获取时间
void Help();                                 //帮助
double InputMoney(char *msg);                //数据输入函数
void Inputdata(char *t,int lenth,char*msg);  //信息录入函数
int judge_month(Node *p,char u_name,Head list);
double judge_rate(int x);
void ListAllUser(Head list);                 //显示所有用户函数
void Loading();                              //载入界面
void Load_rate();                            //加载利率信息
void Load_userdata(Head list);               //初始化用户数据
void Menu();                                 //菜单
void ModifyUser(Head list);                  //更改用户信息
void ModifyPswd(Node *p,Head list);          //修改密码
void PrintUserData(Node *p);                 //打印用户信息函数
void PrintDataTitle();                       //打印标题信息
void ReadMonth();                            //加载当前月份
void Rate_Change_With_Month();               //利率随时间变化函数
void Show_rate();                            //显示当前利率
void SortNormal(Head list);                  //按活期存款排序函数
void Searchls(Head list);                    //模糊查找
void Save_userdata(Head list);               //保存用户信息到储存盘函数
void Save_rate();                            //保存利率信息到储存盘函数
void UserCreat(Head list);                   //用户操作（登录，注册）
void UsersOper(Node *p,char u_name,char pswd,Head list);//用户菜单
int expireDate(int date);                    //定期存款到期时间
#endif // ALL_H_INCLUDED
