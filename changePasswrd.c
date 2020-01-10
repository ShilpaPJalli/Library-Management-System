#include<stdio.h>
#include<string.h>

extern char UserName[20];
extern char PassWord[20];

void changPassword()
{
    char password[10],new_Password[10];
    printf("Enter existing password: ");
    scanf("%s",password);

    if(strcmp(PassWord,password)==0)
    {
        printf("Enter new password: ");
        scanf("%s",new_Password);

        strcpy(PassWord,new_Password);

        printf("\nPassword changed successfully\n");

        printf("\n Login again to continue:\n");

        char username[20],passw[20],c;
        printf(" Enter username: ");
        scanf("%s",username);

        int i=0;
        printf(" Enter password: ");
        while((c=getch())!= '\r')
        {
            passw[i]=c;
            printf("*");
            i++;
        }

        if(strcmp(UserName,username)== 0 && strcmp(PassWord,passw)== 0)//if username & password matches then enters into system
        {
            printf("\nWelcome to Library Management System\n\n");
            return;
        }
        else
        {
            printf("\n *Wrong password\n");
            exit(0);
        }
    }
    else
    {
        printf(" *Entered password is wrong\n");
        return;
    }

}
