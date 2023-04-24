#include<stdio.h>

int main()
{
    char ch,name[10];
    int marks;
    int i,n;
    FILE *fp;

    printf("enter the number of students");
    scanf(" %d",&n);

    i=1;

    fp=fopen("student.txt","w");

    while(i<=n)
    {
        printf("enter the name and marks of student");
        scanf("%s %d",name,&marks);
        fprintf(fp,"%s\t%d\n",name,marks);
        i++;
    }

    fclose(fp);

    fp=fopen("student.txt","r");

    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }

    fclose(fp);

    return 0;
}
