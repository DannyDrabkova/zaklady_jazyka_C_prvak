#include<stdio.h>
#include<string.h>
struct tag{
    char name[10];
    int rno;
};
typedef struct tag node;
node s[5];
sort(int no){
    int i,j;
    node temp;
    for(i=0;i<no-1;i++)
        for(j=i+1;j<no;j++)
            if(strcmp(s[i].name,s[j].name)>0){
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
}
void main(){
    int no,i;
    fflush(stdin);
    printf("Enter The Number Of Students:");
    scanf("%d",&no);
    for(i=0;i<no;i++){
        printf("Enter The Name:");
        fflush(stdin);
        gets(s[i].name);
        printf("Enter the Roll:");
        scanf("%d",&s[i].rno);
    }
    sort(no);
    for(i=0;i<no;i++){
        printf("%s\t",s[i].name);
        printf("%d\n",s[i].rno);
    }
}