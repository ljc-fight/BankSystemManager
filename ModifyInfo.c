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
    printf("�û�����%s \n",p->data.username);
    printf("  ������%s \n",p->data.realname);
    printf("�û�ԭ����Ϊ��%s\n",p->data.password);
    printf("�û��µĵ�½����Ϊ:\n");
    scanf("%s",pswd);
    strcpy(p->data.password,pswd);
    p->data.rank=0;
    printf("\n�޸ĳɹ�!");
    system("pause >nul");
    savemark=1;
    return;
}

//
void Add_Normal(Node *p,char u_name,Head list)
{
    double money;
    printf("�û�����%s \n",p->data.username);
    printf("  ������%s \n",p->data.realname);
    printf("���ڴ�%.2lf\n",p->data.normal_balance);
    printf("����������:\n");
    scanf("%lf",&money);
    p->data.normal_balance=p->data.normal_balance+money;
    p->data.rank=0;
    printf("\n���ɹ���");
    Get_NorTime(p,u_name,list);
    savemark=1;
    system("pause >nul");
    return;
}

//����ȡ��
void Withdraw_Nomal(Node *p,char u_name,Head list)
{
    double money;
    printf("�û�����%s \n",p->data.username);
    printf("  ������%s \n",p->data.realname);
    printf("���ڴ�%.2lf\n",p->data.normal_balance);
    printf("������ȡ����:\n");

    scanf("%lf",&money);
    if(p->data.normal_balance-money>=0)
    {
        p->data.normal_balance=p->data.normal_balance-money;
        p->data.rank=0;
        printf("\nȡ��ɹ���");
        savemark=1;
    }
    else
        printf("���� \n");
    system("pause >nul");
    return;
}
//
void AccountInfo(Node *p,char u_name,Head list)
{
    system("cls");
    printf("  �û�����%s \n",p->data.username);
    printf("    ������%s \n",p->data.realname);
    printf("���ڴ�%.2lf\n",p->data.normal_balance);
    printf("���ڴ�%.2lf\n",p->data.regular_balance);
    printf("�������ޣ�%d   ",p->data.regular_year);
    printf("���ڵ��ڿɻ�����%.2lfԪ\n",p->data.interest);
    printf("����ȡ��ʱ�䣺%d��%d��%d��\n",p->data.reg_year+p->data.regular_year,p->data.reg_month,p->data.reg_day);
    system("pause >nul");
    return;
}
//
void ModifyYear(Node *p,char u_name,Head list)
{
    printf("�û�����%s \n",p->data.username);
    printf("  ������%s \n",p->data.realname);
    printf("���ڴ�%.2lf\n",p->data.regular_balance);
    printf("�������ޣ�%d\n",p->data.regular_year);
    printf("���ĺ�Ķ��ڴ������Ϊ:");
    scanf("%d",&p->data.regular_year);
    while(p->data.regular_year)
    {
        if(p->data.regular_year>=0&&p->data.regular_year<=5)
        {
            break;
        }
        else
        {
            printf("\n��������Ϊ1-5��,����������\n");
            system("pause >nul");
            printf("��������Ϊ:");
            scanf("%d",&p->data.regular_year);
        }
    }
    p->data.interest = judge_rate(p->data.regular_year)*p->data.regular_balance;
    p->data.rank=0;
    printf("�޸ĳɹ�");
    printf("Ԥ�Ƶ��ڿɻ�����%.2lfԪ\n",p->data.interest);
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
    printf("�û�����%s \n",p->data.username);
    printf("  ������%s \n",p->data.realname);
    printf("���ڴ�%.2lf\n",p->data.regular_balance);
    printf("�������ޣ�%d\n",p->data.regular_year);
    printf("���������");
    scanf("%lf",&p->data.regular_balance);
    printf("�����붨�����ޣ�");
    scanf("%d",&p->data.regular_year);
    while(p->data.regular_year)
    {
        if(p->data.regular_year>=0&&p->data.regular_year<=5)
        {
            break;
        }
        else
        {
            printf("\n��������Ϊ1-5��,����������\n");
            system("pause >nul");
            printf("��������Ϊ             :");
            scanf("%d",&p->data.regular_year);
        }
    }
    Get_RegTime(p,u_name,list);
    p->data.rank=0;
    printf("\n���ɹ���\n");
    expireDate(p->data.regular_year);
    switch(p->data.regular_year)
    {
    case 1:
        printf("��ʱ�ɻ�ȡ��Ϣ��%.2lfԪ\n",RATE.rate_oneY*p->data.regular_balance);
        intere = RATE.rate_oneY*p->data.regular_balance;
        break;
    case 2:
        printf("��ʱ�ɻ�ȡ��Ϣ��%.2lfԪ\n",RATE.rate_twoY*p->data.regular_balance);
        intere = RATE.rate_twoY*p->data.regular_balance;
        break;
    case 3:
        printf("��ʱ�ɻ�ȡ��Ϣ��%.2lfԪ\n",RATE.rate_threeY*p->data.regular_balance);
        intere = RATE.rate_threeY*p->data.regular_balance;
        break;
    case 5:
        printf("��ʱ�ɻ�ȡ��Ϣ��%.2lfԪ\n",RATE.rate_fiveY*p->data.regular_balance);
        intere = RATE.rate_fiveY*p->data.regular_balance;
        break;
    default:
        printf("�������޴���\n");return;
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
    printf("�û�����%s \n",p->data.username);
    printf("  ������%s \n",p->data.realname);
    printf("���ڴ�%.2lf\n",p->data.normal_balance);
    printf("����Ҫ���붨�ڴ���");
    scanf("%lf",&money);
    if(p->data.normal_balance-money>=0)
    {
        p->data.regular_balance = p->data.regular_balance + money;
        p->data.normal_balance = p->data.normal_balance-money;
        if(p->data.regular_year==0)
        {
            printf("���ڴ������Ϊ:");
            scanf("%d",&p->data.regular_year);
            while(p->data.regular_year)
            {
                if(p->data.regular_year>=0&&p->data.regular_year<=5)
                {
                    break;
                }
                else
                {
                    printf("\n��������Ϊ1-5��,����������\n");
                    system("pause >nul");
                    printf("��������Ϊ:");
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
        printf("���ڸĶ��ڽ�%.2lf\n",money);
        printf("�Ѵ��붨�ڽ�%.2lf\n",p->data.regular_balance);
        printf("��������Ϊ:%d\n",p->data.regular_year);
        p->data.interest = judge_rate(p->data.regular_year)*p->data.regular_balance;
        printf("���ڴ����%d��%d��%d�յ��ڣ�",p->data.reg_year+p->data.regular_year,p->data.reg_month,p->data.reg_day);
        printf("Ԥ�Ƶ��ڿɻ���%.2lf\n",p->data.interest);
        p->data.rank=0;
        system("pause >nul");
        savemark=1;
        return;
    }
    else
        printf("����!");
    system("pause >nul");
    return;
}
void modify_nr(Node *p,char u_name,Head list)
{
    double money;
    printf("�û�����%s \n",p->data.username);
    printf("  ������%s \n",p->data.realname);
    printf("���ڴ�%.2lf\n",p->data.normal_balance);
    while(1){
        printf("����Ҫ���붨�ڴ���");
        scanf("%lf",&money);
        if(p->data.normal_balance-money>=0)
        {
            p->data.regular_balance = p->data.regular_balance + money;
            p->data.normal_balance = p->data.normal_balance-money;
            if(p->data.regular_year==0)
            {
                printf("���ڴ������Ϊ:");
                scanf("%d",&p->data.regular_year);
                while(p->data.regular_year)
                {
                    if(p->data.regular_year>=0&&p->data.regular_year<=5)
                    {
                        break;
                    }
                    else
                    {
                        printf("\n��������Ϊ1-5��,����������\n");
                        system("pause >nul");
                        printf("��������Ϊ:");
                        scanf("%d",&p->data.regular_year);
                    }
                }
            }

            printf("���ڸĶ��ڽ�%.2lf\n",money);
            printf("�Ѵ��붨�ڽ�%.2lf\n",p->data.regular_balance);
            printf("��������Ϊ:%d",p->data.regular_year);
            p->data.rank=0;
            system("pause >nul");
            savemark=1;
            break;
        }
        else    {printf("����!\n");}
    }
}
