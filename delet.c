#include<stdio.h>
#include<stdlib.h>
#include "fundeclar.h"
#include<string.h>
#include<assert.h>

void delet_Fun()
{
    char Id[10];
    int check,sfval;
    int Del=0;
    printf("Enter book id to delete book:");
    //sfval=scanf("%f",&Id);
    scanf("%s",Id);

    /*if((sfval=(scanf("%f",&Id)))==0)
    {
        return;
    }*/

    float Id_val=atof(Id);

    if(Id_val==0)//checking whether it is string
    {
        printf(" *Warning: Please enter an integer value\n");
        return;
    }
    else
    {
        check=Id_val;
    }
    /*printf("id_val=%f\n",Id_val);
    printf("check=%d\n",check);*/

    if(check!=Id_val)//condition for checking float or int
    {
        printf(" *Invalid input: please enter an integer value\n");
        return;
    }


    book *temp=head;
    book *prev;

    if(temp==NULL)//if list is empty
    {
        printf(" *No books in library to delete\n");
        return;
    }

    if(temp->bookId==Id_val)//if deleting node is the first node
    {
        if(strcmp(temp->status,"Available")==0)
        {
            head=temp->next;
            printf("\nBook deleted successfully\n");
            return;
        }
        Del=1;
    }

    while(temp!=NULL)
    {

        if(temp->bookId==Id_val)
        {
            Del=1;
            if(strcmp(temp->status,"Available")==0)
            {
                prev->next=temp->next;
                free(temp);
                printf("\nBook is deleted successfully\n");
            }
            else
            {
                printf("  *Unsuccessful deletion: Issued book cannot be deleted\n");
            }

        }
        prev=temp;
        temp=temp->next;
    }
    if(Del==0)
    {
        printf("\n Unsuccessful deletion: Book is not in the library to delete\n ");
    }
}
