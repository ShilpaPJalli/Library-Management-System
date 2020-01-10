#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "fundeclar.h"

void issue_Fun()
{

    int found=0,check;
    char Id[10];
    printf("enter book id to issue: ");
    scanf("%s",Id);

    float id=atof(Id);

    if(id==0)
    {
        printf(" *Please enter an integer value\n");
        return;
    }
    else
    {
         check=id;
    }

    if(check!=id)
    {
        printf(" *Please enter an integer value\n");
        return;
    }

    book *temp=head;
    book *prev;

    if(temp==NULL)
    {
        printf(" No books are present in library system to Issue.\n");
        return;
    }

    if(temp->bookId==id)
    {
        if(strcmp(temp->status,"Issued")!=0)
        {
            printf("\nBook issued successfully with id = %d & Book_name = %s \n",temp->bookId,temp->bookName);
            strcpy(temp->status,"Issued");

            //head=temp->next;
            //free(temp);
            return;

        }
        else
        {
            printf(" *Book already issued\n");
            return;
        }
        found=1;
    }

    while(temp!=NULL)
    {
        if(temp->bookId==id)
        {
            if(strcmp(temp->status,"Issued")!=0)
            {
               printf("\n Book issued successfully, with Book_id: %d & Book_name: %s \n",temp->bookId,temp->bookName);
               strcpy(temp->status,"Issued");
                //prev->next=temp->next;
                //free(temp);
            }
            else
            {
                printf(" *Book already issued\n");
                return;
            }
            found=1;

        }
        prev=temp;
        temp=temp->next;
    }
    if(found==0)
    {
        printf("\n Book is not present in this library\n");
        //printf(",so u can't issue the same book\n");
    }
}
