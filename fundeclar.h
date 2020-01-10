#ifndef FUNDECLAR_H_INCLUDED
#define FUNDECLAR_H_INCLUDED

typedef struct node
{
    int bookId;
    char bookName[20];
    char authorName[20];
    char status[10];
    struct book *next;
}book;

book *head;
book *tail;
//struct book *newBook;
char UserName[20];
char PassWord[20];


void add_Fun();
void delet_Fun();
void edit_Fun();
void search_Fun();
void issue_Fun();
void view_Fun();
void return_Fun();
void changPassword();

#endif // FUNDECLAR_H_INCLUDED
