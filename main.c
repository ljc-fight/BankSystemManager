#include "allhead.h"
#include "inputdata.c"
#include "file_operate.c"
#include "function.c"
#include "interface.c"
#include "rate_operate.c"
#include "ModifyInfo.c"

void main()
{
    Head list;
    char c;
    system("title 银行存款管理系统-NEUCSE2008  --By 柳浩 and 李嘉成");
    GetMonth();//识别当前月份
    Load_rate();//加载利率
    Loading();//加载界面
    system("color 3f");
    list=(Node *)malloc(sizeof(Node));
    if(!list)
    {
        printf("\n给文件分配内存时出错，无法打开系统！");
        system("pause >nul");
        return 0;
    }
    list->next=NULL;
    Load_userdata(list);
    while(1)
    {
        Menu();
        printf("\n  请输入1-5进行操作：");
        char select=getch();
        if(select=='5')
        {
            if(savemark==1)
            {
                printf("\n是否保存文件?|y or n|:");
                scanf("%s",&c);
                if(c=='y'||c=='Y')
                {
                    Save_userdata(list);
                    printf("\n\n谢谢使用！\n");
                    system("pause >nul");
                    exit(0);
                }
                else
                {
                    printf("\n\n谢谢使用！\n");
                    exit(0);
                }
            }
            else exit(0);
        }
        switch(select)
        {
        case '1':
            UserCreat(list);
            break;
        case '2':
            AdminLogin(list);
            break;
        case '3':
            Help();
            break;
        case '4':
            Save_userdata(list);
            break;
        default:
            break;
        }
    }
    return 0;
}
