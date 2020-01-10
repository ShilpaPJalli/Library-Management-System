#include<stdio.h>
#include<string.h>
#include "fundeclar.h"

void edit_Fun()
{

    int ID,found=0;
    char newname[15];
    printf("\nEntr bookId for which u want to edit book name:");
    scanf("%d",&ID);

    book *temp=head;

    while(temp!=NULL)
    {
        if(temp->bookId==ID)
        {
            printf("enter new book name:");
            scanf(" %30[^\n]",newname);

            strcpy(temp->bookName,newname);
            found=1;
            printf("Book name changed successfully\n");
            return;
        }

        temp=temp->next;
    }
    if(found==0)
    {
        printf("Book is not found with BookId=%d\n",ID);
            return;
    }
}
