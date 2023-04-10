void Get_NorTime(Node *p,char u_name,Head list)
{
    time_t timep;
    struct tm *pt;
    time (&timep);
    pt=gmtime(&timep);

    p->data.nor_year = 1900+pt->tm_year;
    p->data.nor_month = 1+pt->tm_mon;
    p->data.nor_day = pt->tm_mday;

}
void Get_RegTime(Node *p,char u_name,Head list)
{
    time_t timep;
    struct tm *pt;
    time (&timep);
    pt=gmtime(&timep);

    p->data.reg_year = 1900+pt->tm_year;
    p->data.reg_month = 1+pt->tm_mon;
    p->data.reg_day = pt->tm_mday;

}

void ModifyPswd(Node *p,Head list)
{
    char u_name[12];
    char pswd[12];
    printf("用户名：%s \n",p->data.username);
    printf("  姓名：%s \n",p->data.realname);
    printf("用户原密码为：%s\n",p->data.password);
    printf("用户新的登陆密码为:\n");
    scanf("%s",pswd);
    strcpy(p->data.password,pswd);
    p->data.rank=0;
    printf("\n修改成功!");
    system("pause >nul");
    savemark=1;
    return;
}

//
void Add_Normal(Node *p,char u_name,Head list)
{
    double money;
    printf("用户名：%s \n",p->data.username);
    printf("  姓名：%s \n",p->data.realname);
    printf("活期存款：%.2lf\n",p->data.normal_balance);
    printf("请输入存款金额:\n");
    scanf("%lf",&money);
    p->data.normal_balance=p->data.normal_balance+money;
    p->data.rank=0;
    printf("\n存款成功！");
    Get_NorTime(p,u_name,list);
    savemark=1;
    system("pause >nul");
    return;
}

//活期取款
void Withdraw_Nomal(Node *p,char u_name,Head list)
{
    double money;
    printf("用户名：%s \n",p->data.username);
    printf("  姓名：%s \n",p->data.realname);
    printf("活期存款：%.2lf\n",p->data.normal_balance);
    printf("请输入取款金额:\n");

    scanf("%lf",&money);
    if(p->data.normal_balance-money>=0)
    {
        p->data.normal_balance=p->data.normal_balance-money;
        p->data.rank=0;
        printf("\n取款成功！");
        savemark=1;
    }
    else
        printf("余额不足 \n");
    system("pause >nul");
    return;
}
//
void AccountInfo(Node *p,char u_name,Head list)
{
    system("cls");
    printf("  用户名：%s \n",p->data.username);
    printf("    姓名：%s \n",p->data.realname);
    printf("活期存款：%.2lf\n",p->data.normal_balance);
    printf("定期存款：%.2lf\n",p->data.regular_balance);
    printf("定期年限：%d   ",p->data.regular_year);
    printf("定期到期可获利：%.2lf元\n",p->data.interest);
    printf("定期取款时间：%d年%d月%d日\n",p->data.reg_year+p->data.regular_year,p->data.reg_month,p->data.reg_day);
    system("pause >nul");
    return;
}
//
void ModifyYear(Node *p,char u_name,Head list)
{
    printf("用户名：%s \n",p->data.username);
    printf("  姓名：%s \n",p->data.realname);
    printf("定期存款：%.2lf\n",p->data.regular_balance);
    printf("定期年限：%d\n",p->data.regular_year);
    printf("更改后的定期存款年限为:");
    scanf("%d",&p->data.regular_year);
    while(p->data.regular_year)
    {
        if(p->data.regular_year>=0&&p->data.regular_year<=5)
        {
            break;
        }
        else
        {
            printf("\n定期年限为1-5年,请重新输入\n");
            system("pause >nul");
            printf("定期年限为:");
            scanf("%d",&p->data.regular_year);
        }
    }
    p->data.interest = judge_rate(p->data.regular_year)*p->data.regular_balance;
    p->data.rank=0;
    printf("修改成功");
    printf("预计到期可获利：%.2lf元\n",p->data.interest);
    system("pause >nul");
    savemark=1;
    return;
}
//
double interest(int year,double intere)
{
    return year*intere;
}
void Add_Regular(Node *p,char u_name,Head list)
{
    double intere;
    printf("用户名：%s \n",p->data.username);
    printf("  姓名：%s \n",p->data.realname);
    printf("定期存款：%.2lf\n",p->data.regular_balance);
    printf("定期年限：%d\n",p->data.regular_year);
    printf("请输入存款金额：");
    scanf("%lf",&p->data.regular_balance);
    printf("请输入定期年限：");
    scanf("%d",&p->data.regular_year);
    while(p->data.regular_year)
    {
        if(p->data.regular_year>=0&&p->data.regular_year<=5)
        {
            break;
        }
        else
        {
            printf("\n定期年限为1-5年,请重新输入\n");
            system("pause >nul");
            printf("定期年限为             :");
            scanf("%d",&p->data.regular_year);
        }
    }
    Get_RegTime(p,u_name,list);
    p->data.rank=0;
    printf("\n存款成功！\n");
    expireDate(p->data.regular_year);
    switch(p->data.regular_year)
    {
    case 1:
        printf("届时可获取利息：%.2lf元\n",RATE.rate_oneY*p->data.regular_balance);
        intere = RATE.rate_oneY*p->data.regular_balance;
        break;
    case 2:
        printf("届时可获取利息：%.2lf元\n",RATE.rate_twoY*p->data.regular_balance);
        intere = RATE.rate_twoY*p->data.regular_balance;
        break;
    case 3:
        printf("届时可获取利息：%.2lf元\n",RATE.rate_threeY*p->data.regular_balance);
        intere = RATE.rate_threeY*p->data.regular_balance;
        break;
    case 5:
        printf("届时可获取利息：%.2lf元\n",RATE.rate_fiveY*p->data.regular_balance);
        intere = RATE.rate_fiveY*p->data.regular_balance;
        break;
    default:
        printf("输入年限错误\n");return;
    }
    p->data.interest = intere;
    system("pause >nul");
    savemark=1;
    return;
}

double judge_rate(int x)
{
    while(1){
        switch(x){
        case 1:
            return RATE.rate_oneY;
        case 2:
            return RATE.rate_twoY;
        case 3:
            return RATE.rate_threeY;
        case 5:
            return RATE.rate_fiveY;
        }
    if(x<1||x>5||x==4) break;
    }
}

void Modify_NR(Node *p,char u_name,Head list)
{
    double money;
    printf("用户名：%s \n",p->data.username);
    printf("  姓名：%s \n",p->data.realname);
    printf("活期存款：%.2lf\n",p->data.normal_balance);
    printf("输入要存入定期存款金额：");
    scanf("%lf",&money);
    if(p->data.normal_balance-money>=0)
    {
        p->data.regular_balance = p->data.regular_balance + money;
        p->data.normal_balance = p->data.normal_balance-money;
        if(p->data.regular_year==0)
        {
            printf("定期存款年限为:");
            scanf("%d",&p->data.regular_year);
            while(p->data.regular_year)
            {
                if(p->data.regular_year>=0&&p->data.regular_year<=5)
                {
                    break;
                }
                else
                {
                    printf("\n定期年限为1-5年,请重新输入\n");
                    system("pause >nul");
                    printf("定期年限为:");
                    scanf("%d",&p->data.regular_year);
                    time_t timep;
                    struct tm *tp;
                    time (&timep);
                    tp=gmtime(&timep);
                    p->data.reg_day = tp->tm_mday;
                    p->data.reg_month = 1+tp->tm_mon;
                    p->data.reg_year = 1900+tp->tm_year;
                }
            }
        }
        printf("活期改定期金额：%.2lf\n",money);
        printf("已存入定期金额：%.2lf\n",p->data.regular_balance);
        printf("定期年限为:%d\n",p->data.regular_year);
        p->data.interest = judge_rate(p->data.regular_year)*p->data.regular_balance;
        printf("定期存款于%d年%d月%d日到期！",p->data.reg_year+p->data.regular_year,p->data.reg_month,p->data.reg_day);
        printf("预计到期可获利%.2lf\n",p->data.interest);
        p->data.rank=0;
        system("pause >nul");
        savemark=1;
        return;
    }
    else
        printf("余额不足!");
    system("pause >nul");
    return;
}
void modify_nr(Node *p,char u_name,Head list)
{
    double money;
    printf("用户名：%s \n",p->data.username);
    printf("  姓名：%s \n",p->data.realname);
    printf("活期存款：%.2lf\n",p->data.normal_balance);
    while(1){
        printf("输入要存入定期存款金额：");
        scanf("%lf",&money);
        if(p->data.normal_balance-money>=0)
        {
            p->data.regular_balance = p->data.regular_balance + money;
            p->data.normal_balance = p->data.normal_balance-money;
            if(p->data.regular_year==0)
            {
                printf("定期存款年限为:");
                scanf("%d",&p->data.regular_year);
                while(p->data.regular_year)
                {
                    if(p->data.regular_year>=0&&p->data.regular_year<=5)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n定期年限为1-5年,请重新输入\n");
                        system("pause >nul");
                        printf("定期年限为:");
                        scanf("%d",&p->data.regular_year);
                    }
                }
            }

            printf("活期改定期金额：%.2lf\n",money);
            printf("已存入定期金额：%.2lf\n",p->data.regular_balance);
            printf("定期年限为:%d",p->data.regular_year);
            p->data.rank=0;
            system("pause >nul");
            savemark=1;
            break;
        }
        else    {printf("余额不足!\n");}
    }
}
