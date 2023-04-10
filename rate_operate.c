//活期利率更改
void Change_normal_rate(Head list)
{
    int x=0;//标记变更
    system("cls");
    printf("*********************************************************\n");
    printf("*                                                       *\n");
    printf("*                                                       *\n");
    printf("*              当前活期利率:%.4f                      *\n",RATE.normal_rate);
    printf("*                                                       *\n");
    printf("*                                                       *\n");
    printf("*********************************************************\n");
    printf("\n\n\n");
    printf("请输入更改后活期利率:\n");
    scanf("%lf",&RATE.normal_rate);
    printf("\n");
    system("pause");
    Save_rate();
    printf("\n");
    printf("操作成功！");
    x=1;
    savemark=1;
    Change_remind(x);
    return;
}

//定期利率更改
void Change_regular_rate(Head list)
{
    system("cls");
    int cg=0;
    int x=0;//标记变更
    Show_rate();
    printf("\n\n");
    printf("请输入需要所更改利率对应的定期年限：\n");
    scanf("%d",&cg);
    printf("请输入更改后定期利率:\n");
    if(cg==1)
    {
        scanf("%lf",&RATE.rate_oneY);
    }
    if(cg==2)
    {
        scanf("%lf",&RATE.rate_twoY);
    }
    if(cg==3)
    {
        scanf("%lf",&RATE.rate_threeY);
    }
    if(cg==4)
    {
        scanf("%lf",&RATE.rate_fiveY);
    }
    printf("\n");
    Save_rate();
    printf("\n");
    printf("操作成功！");
    system("pause >nul");
    x=1;
    savemark=1;
    Change_remind(x);
    return;
}

void GetMonth()//
{
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    month=1+p->tm_mon;
}

void Rate_Change_With_Month()//利率随月份变化函数
{
    RATE.normal_rate=0.0020+(double)month*0.0001;
    RATE.rate_oneY=0.0170+(double)month*0.0001;
    RATE.rate_twoY=0.0221+(double)month*0.0001;
    RATE.rate_threeY=0.0270+(double)month*0.0001;
    RATE.rate_fiveY=0.0271+(double)month*0.0001;
}

int get_month()//
{
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    month=1+p->tm_mon;
    return month;
}
int judge_month(Node *p,char u_name,Head list)
{
    if(p->data.nor_month != get_month())
        return 1;
    else return 0;
}
