void Save_userdata(Head list)
{
    FILE *fp;
    Node *p;
    int count=0;
    fp=fopen(".\\BankData_NEUCSE2008\\userdata.dat","wb");
    if(fp==NULL)
    {
        system("cls");
        printf("打开文件失败！\n\n");
        system("pause >nul");
        return;
    }
    p=list->next;
    while(p)
    {
        if(fwrite(p,sizeof(Node),1,fp)==1)
        {
            p=p->next;
            count++;
        }
        else break;
    }
    if(count>0)
    {
        printf("\n\n数据保存成功！");
        system("pause >nul");
        savemark=0;
    }
    else
    {
        printf("没有发现用户信息被保存！\n");
        system("pause >nul");
    }
    fclose(fp);
    Save_rate();
}

void Load_userdata(Head list)
{
    FILE *fp;
    Node *p,*r;
    int count=0;
    r=list;
    system("mkdir .\\BankData_NEUCSE2008");
    system("cls");
    fp=fopen(".\\BankData_NEUCSE2008\\userdata.dat","ab+");
    if(fp==NULL)
    {
        system("cls");
        printf("\n不能正常打开文件！\n");
        system("pause >nul");
        exit(0);
    }

    while(!feof(fp))
    {
        p=(Node *)malloc(sizeof(Node));
        if(!p)
        {
            printf("分配内存时出错！");
            system("pause >nul");
            exit(0);
        }
        if(fread(p,sizeof(Node),1,fp)==1)
        {
            p->next=NULL;
            r->next=p;
            r=p;
            count++;
        }
    }

    fclose(fp);
    system("cls");
    printf("\n\t\t初始化成功！共有 %d 条信息被录入！\n",count);
    Sleep(1000);
    return;
}

void Load_rate()
{
    system("color e0");
    FILE *fp;
    system("mkdir .\\BankData_NEUCSE2008");
    system("cls");
    fp = fopen(".\\BankData_NEUCSE2008\\rateinfo.dat","rb");
    if(fp==NULL)
    {
        Rate_Change_With_Month();
    }
    else
    {
        fread(&RATE,sizeof(struct all_rate),1,fp);
    }
    fclose(fp);
}

void Save_rate()//保存利率信息
{
    FILE *fp;
    fp=fopen(".\\BankData_NEUCSE2008\\rateinfo.dat","wb");
    if(fp==NULL)
    {
        printf("利率信息文件打开失败！");
        system("pause >nul");
        return;
    }
    else
    {
        fwrite(&RATE,sizeof(struct all_rate),1,fp);
    }

    fclose(fp);
}
