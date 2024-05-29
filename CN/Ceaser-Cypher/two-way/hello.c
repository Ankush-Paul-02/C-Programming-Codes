#include<stdio.h>
#include<string.h>
int main()
{
   
   char str[10];
   int i,key;
   printf("enter the string:- ");
   scanf("%s",str);

   int n=strlen(str);

    printf("enter the key:- ");
   scanf("%d",&key);

  for(i=0;i<n;i++)
  {
    str[i]=(str[i] - 'A' + key) % 26 + 'A';
    printf("%c \n",str[i]);
  }


}