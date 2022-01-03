#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256

int n = 0;
char select;
typedef struct data
{
    char id[10];
    char name[SIZE];
    float score[3];
    float total;
    float averange;
} stu;


stu s[70];

int Menu();
void choice(char inp);
void inputscore();
void search();
void showall();
void showsort_H();
void showsort_L();
void averange();

int Menu()
{
    char select;
    printf("=====menu=====\n");
    printf("e: input data\n");
    printf("f: find specific student data\n");
    printf("s: show all students' data\n");
    printf("d: show the sorted students' data (high to low)\n");
    printf("a: show the sorted students' data (low to high)\n");
    printf("b: show the average score value\n");
    printf("q: quit\n");
    printf("function choice: \n");
    scanf(" %c", &select);
    return select;
}

void choice(char select)
{
    switch (select)
    {
    case 'e':
        inputscore();
    case 'f':
        search();
    case 's':
        showall();
    case 'd':
        showsort_H();
    case 'a':
        showsort_L();
    case 'b':
        averange();
    case 'q':
        exit(0);
    default:
        printf("Error!");
        break;
    }
}

void inputscore()
{
    for (int i = 0; i < n; i++)
    {
        printf("input id\n");
        scanf("%s", s[i].id);
        if (s[i].id == 0)
            break;
        getchar();
        printf("input name\n");
        gets(s[i].name);
        // for(int j=0;j<10;j++){
        //     scnaf("%c",&s[i].name);
        // }
        printf("input score\n");
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &s[i].score[j]);
            s[i].total += s[i].score[j];
        }
    }
}

void search()
{
    char id;
    printf("input id: \n");
    scanf("%s", id);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(id, s[i].id) == 0)
        {
            printf("%s\t", s[i].id);
            for (int j = 0; j < 10; j++)
            {
                printf("%c", s[i].name[j]);
            }
            printf("\t");
            printf("%f\t%f\t%f\t", s[i].score[0], s[i].score[1], s[i].score[2]);
            id = '0';
        }
        if (id != '0')
        {
            printf("No such studen\n");
        }
    }
}

void showall()
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\t", s[i].id);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", s[i].name[j]);
        }
        printf("\t");
        printf("%f\t%f\t%f\t", s[i].score[0], s[i].score[1], s[i].score[2]);
    }
    printf("------------------\n");
}

void showsort_H()
{
    stu tab = {0};
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i].total < s[i + 1].total)
        {
            tab = s[i];
            s[i] = s[i + 1];
            s[i + 1] = tab;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\t", s[i].id);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", s[i].name[j]);
        }
        printf("\t");
        printf("%f\t%f\t%f\t", s[i].score[0], s[i].score[1], s[i].score[2]);
    }
    puts("");
}

void showsort_L()
{
    stu tab = {0};
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i].total > s[i + 1].total)
        {
            tab = s[i];
            s[i] = s[i + 1];
            s[i + 1] = tab;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\t", s[i].id);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", s[i].name[j]);
        }
        printf("\t");
        printf("%f\t%f\t%f\t", s[i].score[0], s[i].score[1], s[i].score[2]);
    }
    puts("");
}

void averange()
{
    float tatal[256] = {0};
    float averange[256] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tatal[i] += s[i].score[j];
        }
        averange[i] = tatal[i] / 3;
        printf("第%d個學生的總分為：%.2f，平均分為%.2f\n", i + 1, tatal[i], averange[i]);
    }
}
int main(void)
{
    stu id[10];

    scanf("%d", &n);
    select = Menu();
    choice(select);
}
