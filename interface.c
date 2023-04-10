
void PrintDataTitle()
{
    printf("����       �û���     �˺�       ���ڴ��   ���ڴ��   �������� \n");

}

void PrintUserData(Node *p)
{
    printf("%-10s %-10s %-10lld %-10.2lf %-10.2lf %d��\n",p->data.realname,p->data.username,p->data.account,p->data.normal_balance,p->data.regular_balance,p->data.regular_year);
}

void Show_rate()
{
    printf("\t\t*************************************************************\n");
    printf("\t\t��ǰ�����������£�                                                 \n");
    printf("\t\t                                                                   \n");
    printf("\t\t              <1> һ��(����Ϊ��%.4f)                 \n",RATE.rate_oneY);
    printf("\t\t              <2> ����(����Ϊ��%.4f)                   \n",RATE.rate_twoY);
    printf("\t\t              <3> ����(����Ϊ��%.4f)                 \n",RATE.rate_threeY);
    printf("\t\t              <4> ����(����Ϊ��%.4f)                  \n",RATE.rate_fiveY);
    printf("\t\t                                                                      \n");
    printf("\t\t*************************************************************\n");
    return;
}

void Loading()
{
    int z;
    system("color e0");
    printf("\t\t =====================================================\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||             ��ӭʹ�����д�����ϵͳ!             ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t||                                                   ||\n");
    printf("\t\t =====================================================\n");
    printf("\n\n\n\n\n\n");
    printf("\t\t��������ϵͳ�����Ժ�...\n");
    printf("\t\t");
    printf(".......................................................\r");
    printf("\t\t");
    for(z=16; z<71; z++)
    {
        Sleep(8);
        printf(">");
    }
}

void Change_remind(int x)
{
    if(x==1)
    {
        system("cls");
        printf("�����ѷ����䶯���ڴ���ʾ��,������Ҫ��ǰ�����и��Ĵ�ʽ\n\n");
        printf("\n��ǰ������Ϣ���£�\n");
        printf("\t\t*************************************************************\n");
        printf("\t\t                                                           \n");
        printf("\t\t                  ��ǰ��������:%.4f                      \n",RATE.normal_rate);
        printf("\t\t                                                           \n");
        printf("\t\t                                                           \n");
        Show_rate();
        system("pause >nul");
    }
    return;
}


void Help()
{
    system("cls");
    printf("\t\t\t ----------------------------------------------------\n");
    printf("\t\t\t|                  ���д�����ϵͳ                  |\n");
    printf("\t\t\t|                        v2.0                        |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|   Tips:                                            |\n");
    printf("\t\t\t|   <1> ���ܽ���ִ����Ϻ����������               |\n");
    printf("\t\t\t|   <2> ������Ϣ�䶯�˳�ǰ�뱣�����Ϣ               |\n");
    printf("\t\t\t|   <3> �������޷�ΧΪ1-5��                          |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t|                                                    |\n");
    printf("\t\t\t ----------------------------------------------------\n");
    system("pause >nul");
    return;
}


void Menu()
{
    system("cls");
    printf("\t\t                ��ӭʹ�����д�����ϵͳ\n\n");
    printf("\t\t��--------------------------�˵�-----------------------��\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t|                    <1>  �����û�����                  |\n");
    printf("\t\t|                    <2>  �������Ա����                |\n");
    printf("\t\t|                    <3>  �û�����                      |\n");
    printf("\t\t|                    <4>  ������Ϣ                      |\n");
    printf("\t\t|                    <5>  �˳�ϵͳ                      |\n");
    printf("\t\t|                                                       |\n");
    printf("\t\t��-----------------------------------------------------��\n");
}

void UserCreat(Head list)
{
    int choice;
    system("cls");
    printf("\t\t                  ��ӭʹ���û�����ϵͳ\n\n");
    printf("\t\t��-------------------------�˵�-----------------------��\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|      <1> �û���½                                    |\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|      <2> �û�ע��                                    |\n");
    printf("\t\t|                                                      |\n");
    printf("\t\t|      <3> ������һ����                                |\n");
    printf("\t\t��----------------------------------------------------��\n");
    printf("������ָ��:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        UserLogin(list);
        break;
    case 2:
        AddUser(list);
        break;
    case 3:
        return;
        break;
    default:break;
    }
}
void UsersOper(Node *p,char u_name,char pswd,Head list)
{
    if((judge_month(p,u_name,list))&&p->data.normal_balance!=0)
        {
            char ch;
            printf("ϵͳ��ⶨ�ڴ�����ʷ����䶯���������л������Ƿ���л���ת���ڲ�������y or n��\n\n\n");
            ch  = getch();
            if(ch=='y'||ch=='Y')
                Modify_NR(p,u_name,list);
        }
    while(1){
        system("cls");
        printf("\t\t                  ��ӭʹ���û�����ϵͳ\n\n");
        printf("\t\t��-------------------------�˵�-----------------------��\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <1> �˻���ϸ                                    |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <2> ���ڴ��                                    |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <3> ���ڴ��                                    |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <4> ����ȡ��                                    |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <5> �޸Ķ��ڴ������                            |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <6> ���ڸĶ���                                  |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <7> �޸�����                                    |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <8> ������һ����                                |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t��----------------------------------------------------��\n");
        printf("������ָ��:");
        char choice;
        choice = getch();
        switch(choice)
        {
        case '1':
            AccountInfo(p,u_name,list);
            break;
        case '2':
            Add_Normal(p,u_name,list);
            break;
        case '3':
            Add_Regular(p,u_name,list);
            break;
        case '4':
            Withdraw_Nomal(p,u_name,list);
            break;
        case '5':
            ModifyYear(p,u_name,list);
            break;
        case '6':
            Modify_NR(p,u_name,list);
            break;
        case '7':
            ModifyPswd(p,list);
            break;
        }
        if(choice=='8')break;
    }
}

void AdminLogin(Head list)
{
    system("cls");
    char password[7];
    char adminpswd[]={"123456"};
    printf("���������Ա��½���룺\n");
    scanf("%s",password);
    if(strcmp(adminpswd,password)==0)
    {
        Administrator(list);
    }
    else
    {
        printf("����������󣬼���������һ���棡");
        Sleep(1000);
        return;
    }
}

void Administrator(Head list)
{
    while(1){
        char choice;
        system("cls");
        printf("\t\t                 ��ӭʹ�ù���Ա����ϵͳ\n\n");
        printf("\t\t��-------------------------�˵�-----------------------��\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <1> �г������û�          <2> ɾ���û���Ϣ      |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <3> �����û���Ϣ          <4> ���������      |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <5> ���������޸�          <6> ���������޸�      |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t|      <7> ������һ����                                |\n");
        printf("\t\t|                                                      |\n");
        printf("\t\t��----------------------------------------------------��\n");
        printf("������ָ��:");
        scanf("%c",&choice);
        switch(choice)
        {
            case '1':
                ListAllUser(list);
                break;
            case '2':
                DeleteUser(list);
                break;
            case '3':
                FindUser(list);
                break;
            case '4':
                SortNormal(list);
                break;
            case '5':
                Change_normal_rate();
                break;
            case '6':
                Change_regular_rate();
                break;
        }
        if(choice=='7') return;
    }
}
