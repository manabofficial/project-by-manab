
#include"stdio.h"
#include"unistd.h"
int main ()
{
for (int  i = 0; i < 10; i++)
{
    for (int  j = 0; j < 25; j++)
    {
        if (j==0||j==20||(j==2*i&&j<=10)||(j==(19-2*i)&&j>=9))
        {
            printf("💛");
        }
        else  
       printf("💓");
    }
       for (int  j = 0; j < 25; j++)
    {
if(10-i==j||10+i==j||(i==5&&j>4&&j<16))
        {
            printf("💛");
        }
        else  
       printf("💓");

    }
for (int  j = 0; j < 25; j++)
    {
if(j==1||j==19||j==2*i)
        {
            printf("💛");
        }
        else  
       printf("💓");
    }
  
sleep(1);
    printf("\n");

}
for (int  i = 0; i < 10; i++)
{
for (int  j = 0; j < 25; j++)
    {
if(10-i==j||10+i==j||(i==5&&j>4&&j<16))
        {
            printf("💛");
        }
        else  
       printf("💓");

    }
    for (int  j = 0; j < 35; j++)
    {
      if(j==0||(j==15 && i!=5)||(i==0&& j<15)||(i==4&& j<15)||(i==6 && j<15)||(i==9 && j<15))
        {
            printf("💛");
        }
        else  
       printf("💓");
    }
    sleep(1);
    printf("\n");
}


return 0;
}


