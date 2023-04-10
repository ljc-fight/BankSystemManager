void Save_userdata(Head list)
{
    FILE *fp;
    Node *p;
    int count=0;
    fp=fopen(".\\BankData_NEUCSE2008\\userdata.dat","wb");
    if(fp==NULL)
    {
        system("cls");
        printf("���ļ�ʧ�ܣ�\n\n");
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
        printf("\n\n���ݱ���ɹ���");
        system("pause >nul");
        savemark=0;
    }
    else
    {
        printf("û�з����û���Ϣ�����棡\n");
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
        printf("\n�����������ļ���\n");
        system("pause >nul");
        exit(0);
    }

    while(!feof(fp))
    {
        p=(Node *)malloc(sizeof(Node));
        if(!p)
        {
            printf("�����ڴ�ʱ����");
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
    printf("\n\t\t��ʼ���ɹ������� %d ����Ϣ��¼�룡\n",count);
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

void Save_rate()//����������Ϣ
{
    FILE *fp;
    fp=fopen(".\\BankData_NEUCSE2008\\rateinfo.dat","wb");
    if(fp==NULL)
    {
        printf("������Ϣ�ļ���ʧ�ܣ�");
        system("pause >nul");
        return;
    }
    else
    {
        fwrite(&RATE,sizeof(struct all_rate),1,fp);
    }

    fclose(fp);
}
