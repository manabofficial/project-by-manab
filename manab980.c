#include"stdio.h"
#include"stdlib.h"
#include"time.h"
int A[16],in=0,B[4][4],gameover=0,flag=0,space;
int x =3 ,y=3,l=0;
void setup ()
{
srand(time(0));
int x ;
for (int  j = 0; j<15; j++)
{
level:
x=rand()%16;
for (int  i = 0; i < 15; i++)
{
if(x==A[i])
{
goto level ;
}
}
A[in]=x;
in++;
}
}
//********
void copy()
{
int count =0;
for (int  i = 0; i < 4; i++)
{
for (int  j = 0; j < 4; j++)
{
B[i][j]=A[count ];
count++;
}

}
}
//**********
void input()
 {
int c ;


   printf("\nENTER ANY NUMBER\n");
   scanf("%d",&c);
   
   switch (c)
   {
      case 1:
      flag =1;
      break;
      case 2:
      flag =2;
      break;
     case 3:
      flag =3;
      break;
      case 4:
      flag =4;
      break;
       case 5:
       flag =5;
       break;
   }

}
//************
void logic ()
{
    int temp ;
switch (flag)
   {
      case 1:
        temp=B[x][y];
        B[x][y]=B[x-1][y];
        B[x-1][y]=temp;
        x--;
      break;
      case 2:
        temp=B[x][y];
        B[x][y]=B[x][y-1];
        B[x][y-1]=temp;
         y--;
      break;
     case 3:
        temp=B[x][y];
        B[x][y]=B[x+1][y];
        B[x+1][y]=temp;
        x++;
      break;
      case 4:
       temp=B[x][y];
        B[x][y]=B[x][y+1];
        B[x][y+1]=temp;
         y++;
      break;
      case 5:
      gameover =1;
      break;

   }
}
//**********
void print()
{
for (int  i = 0; i < 17; i++)
{
printf("-");
}
printf("\n");
for (int  i = 0; i < 4; i++)
{
for (int  j = 0; j < 4; j++)
{  
   if (j==0)
   {
printf("|");
   }
   
printf("%d ",B[i][j]);
if (B[i][j]<10)
printf(" ");
printf("|");
}
printf("\n");
}
for (int  i = 0; i < 17; i++)
{
printf("-");
}
}
//**********
void check()
{
   int temp =1,search =0,count =0;
for (int  i = 0; i < 4; i++)
{
  for (int  j = 0; j < 4; j++)
  {
   if(B[i][j]==temp||(B[i][j]==0&&i==3&&j==3))
   {
    temp++;
    count++;
    continue;
   }
    else
    search=1 ;
    break;
  }
  if (search==1)
  {
    break;
  }
  
}
if (count==16)
{
gameover=1;
}
}


int main ()
{
   int count =400;
char name[50];
setup();
copy();
printf("           RULES OF THE GAME\n\n\n");
printf("MOVE UP :by click 1\n");
printf("MOVE DOWN :by click 3\n");
printf("MOVE LEFT:by click 2\n");
printf("MOVE RIGHT:by click 4\n\n\n\n");
printf("Wining condition\n");
printf("1  2  3  4 \n5  6  7  8 \n9  10 11 12\n13 14 15 0\n");
printf("ENTER YOUR NAME ");

fgets(name,50,stdin);
//printf(" Hello %s",name);
while(!gameover && count!=0)
    {
       printf("Hello %s remain %d\n",name,count--);
      print();
      input();
      logic();
      check();
    }
    

}
