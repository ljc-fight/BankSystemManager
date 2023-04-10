void Inputdata(char *t,int lenth,char *msg)
{
    char str[16];
    do
    {
        printf(msg);
        scanf("%s",str);
        if(strlen(str)>lenth)
            printf("\n输入有误!\n");
    }
    while(strlen(str)>lenth);
    strcpy(t,str);
}

double InputMoney(char *msg)
{
    double t=0;
    do
    {
        printf(msg);
        scanf("%lf",&t);
        if(t<0) printf("\n请输入正确的金额！\n");
    }
    while(t<0);
    return t;
}
