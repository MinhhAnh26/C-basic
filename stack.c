#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Book{
    char author[100];
    int page;
    double cost;
    int year;
    struct Book* next;
} Book;
Book* top;
Book* makeBook(char* author, int page, double cost, int year){
    Book* p = (Book*)malloc(sizeof(Book));
    strcpy(p->author, author);
    p->page = page;
    p->cost = cost;
    p->year = year;
    p->next = NULL;
    return p;
}

void initStack(){
    top = NULL;
}

void push(char *author, int page, double cost, int year){
    Book* p = makeBook(author, page, cost, year);
    p->next = top;
    top = p;
}

int stackEmpty(){
    return top == NULL;
}

Book* pop(){
    if(stackEmpty()) return NULL;
    Book* p = top;//p tro den phan tu dau tien cua Stack
    top = top->next;//top tro den phan tu tiep theo trong Stack
    p->next = NULL;//p->next khong tro den phan tu nao nua
    return p;
}

//Tot nhat la xay dung ham duyet sach surf
void surf(){
    Book *p = top;
    while(p != NULL){
        printf("Sach cua tac gia %s, co %d trang, gia %0.2lf $, nam xuat ban: %d\n"
        , p->author, p->page, p->cost, p->year
        );
        p = p->next;
    }
}

int findYear(int year){
    Book *p = top;
    while(p != NULL){
        if(p->year == year)
            return 1;
        p = p->next;
    }
    return 0;
}

int findAuthor(char* name){
    int count = 0;
    int found = 0;
    Book *p = top;
    while(p != NULL){
        if(strcmp(p->author, name) == 0)//giong het nhau
        {
            found = 1;
            break;
        }
        count++;
        p = p->next;
    }
    if(found)
        return count;
    return -1;
}

int main()
{
    int N;
    printf("Nhap vao gia tri N: "); scanf("%d", &N);
    initStack();
    int p, y; double cost;
    for(int i = 0; i < N; i++){
        char name[100];
        printf("Ten tac gia: "); scanf("%s", name);
        printf("So trang cua sach: "); scanf("%d", &p);
        printf("Nam xuat ban cua sach: "); scanf("%d", &y);
        printf("Gia tien cua sach: "); scanf("%lf", &cost);
        push(name, p, cost, y);
    }
    surf();
    int publishedYear = 0;
    printf("Nhap vao mot nam: "); scanf("%d", &publishedYear);
    if(findYear(publishedYear) == 1){
        printf("Co quyen sach xuat ban vao nam %d\n", publishedYear);
    }
    else{
        printf("khong co\n");
    }
    char inputName[100];
    printf("Nhap vao ten: "); scanf("%s", inputName);
    int count = findAuthor(inputName);
    if(count == 0){
        printf("Quyen sach can tim o ngay dau danh sach\n");
    }
    else if(count > 0){
        printf("Ta phai nhac %d quyen sach de tim\n", count);
    }
    else{
        printf("khong thay quyen sach");
    }

    return 0;
}

