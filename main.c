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
    system("title ���д�����ϵͳ-NEUCSE2008  --By ���� and ��γ�");
    GetMonth();//ʶ��ǰ�·�
    Load_rate();//��������
    Loading();//���ؽ���
    system("color 3f");
    list=(Node *)malloc(sizeof(Node));
    if(!list)
    {
        printf("\n���ļ������ڴ�ʱ�����޷���ϵͳ��");
        system("pause >nul");
        return 0;
    }
    list->next=NULL;
    Load_userdata(list);
    while(1)
    {
        Menu();
        printf("\n  ������1-5���в�����");
        char select=getch();
        if(select=='5')
        {
            if(savemark==1)
            {
                printf("\n�Ƿ񱣴��ļ�?|y or n|:");
                scanf("%s",&c);
                if(c=='y'||c=='Y')
                {
                    Save_userdata(list);
                    printf("\n\nллʹ�ã�\n");
                    system("pause >nul");
                    exit(0);
                }
                else
                {
                    printf("\n\nллʹ�ã�\n");
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
