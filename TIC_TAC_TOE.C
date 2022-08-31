#include"stdio.h"

char A[3][3]={'1','2','3','4','5','6','7','8','9'} ;
int c_p1_p2=0,gameover=0,flag=0,game=0,game3=0,evil=0;
 void evil_input()
 {
  for (int  i = 0; i < 3; i++)
  {
for (int  j = 0; j < 3; j++)
{
if (A[i][j]=='0'&&A[i][j+1]=='0')
{
if (j==0&& A[i][j+2]!='*')
{
A[i][2]='*';
game3=1;
}
else if (j==2&&A[i][j]!='*')
{
A[i][0]='*';
game3=1;
}
}
 if (A[i][j]=='0'&&A[i+1][j]=='0')
{
if (i==0&&A[i+2][j]!='*')
{
A[2][j]='*';
game3=1;
}
else if (i==2 && A[i-2][j]=='*')
{
A[0][j]='*';
game3=1;
}
}

}

 }

if(game3==0)
{
for (int  i = 0; i < 3; i++)
{
for (int  j = 0; j < 3; j++)
{
if (A[i][j]!='0'&&A[i][j]!='*')
{
A[i][j]='*';
evil=1;
break;
}

}
if (evil==1)
{
break;
}
}
  
}
evil=0,game3=0;
 }

void super_input()
{
    printf("COMPUTER INPUT\n");
for (int  i = 0; i < 3; i++)
{
for (int  j = 0; j < 3;j++)
{


if (A[i][j]=='0'&& A[i][j+1]=='0')
{
if (j==0&& A[i][j+2]!='*')///
{
A[i][2]='*';
game=1;
break;
}
else if (j==1&& A[i][j-1]!='*')
{
A[i][0]='*';
game=1;
break;
}

}
else if (A[i][j]=='0'&&A[i+1][j]=='0')
{
if (i==0 && A[i+2][j]!='*')
{
A[2][j]='*';
game=1;
break;
}
else if (i==1&& A[i-1][j]!='*')
{
A[0][j]='*';
game =1;
break;
}

}

}
if (game==1)
{
break;
}

}
//############

if (game==0)
{
for (int  i = 0; i < 3; i++)
{
for (int  j = 0; j < 3; j++)
{
if (A[i][j]!='0'&& A[i][j]!='*')
{
A[i][j]='*';
flag=1;
break;
}

}
if (flag==1)
{
break;
}

}

}
game =0;
flag =0;
}

//************
void draw()
{
printf("\n");
for (int  i = 0; i < 3; i++)
{
for (int  j = 0; j < 3; j++)
{
    if (j==1||j==2)
    {
printf(" | ");
    }
    
printf("%c",A[i][j]);
}
printf("\n");
if (i==0||i==1)
{
printf("__________");
}

printf("\n");
}
}

//************
void player1_input()
{
    int a,setposotion ;
    notselect1:
printf("player 1 input \n select posotion");
scanf("%d",&a);
if(A[a/3][a%3-1]!='*'&&A[a/3][a%3-1]!='0')
{   
A[a/3][a%3-1]='0';
}
else
goto notselect1;
}

//************
void player2_input()
{
    int a,setposotion ;
notselect2 :
printf("player 2 input \n select posotion");
scanf("%d",&a);
if(A[a/3][a%3-1]!='0' && A[a/3][a%3-1]!='*')
{
    
A[a/3][a%3-1]='*';
}
else
goto notselect2;
}

//*************
void check()
{
if ((A[0][0]=='*'&&A[0][1]=='*'&&A[0][2]=='*')||(A[1][0]=='*'&&A[1][1]=='*'&&A[1][2]=='*')||(A[2][0]=='*'&&A[2][1]=='*'&&A[2][2]=='*')||(A[0][0]=='*'&& A[1][1]=='*'&& A[2][2]=='*')||(A[0][2]=='*'&& A[1][1]=='*'&& A[2][0]=='*'))
{
 printf("player 2 win ");
 gameover =1;
}
if ((A[0][0]=='0'&&A[0][1]=='0'&&A[0][2]=='0')||(A[1][0]=='0'&&A[1][1]=='0'&&A[1][2]=='0')||(A[2][0]=='0'&&A[2][1]=='0'&&A[2][2]=='0')||(A[0][0]=='0'&& A[1][1]=='0' && A[2][2]=='0')||(A[0][2]=='0'&& A[1][1]=='0'&& A[2][0]=='0'))
{
printf("player 1 win ");
gameover =1 ;
}
}

//*************
int main ()
{
    int choice;
    printf("[\033[32m");
    printf("\n\n##################TIC TAC TOE #######################\n\n\n");
    printf("First player :0\n Second player :*");
draw();

printf("\nEnter your choice\n\n");
printf("1.  WANT TO PLAY WITH SMART COMPUTER\n");
printf("2.  WANT TO PLAY WITH PLAYER \n");
printf("2.  WNAT TO PLAY WITH EVIL COMPUTER \n");
printf("4.  Exit\n");
invalid:
scanf("%d",&choice);
if(choice==1)
{
while (c_p1_p2<9&&gameover==0)
{
    
if (c_p1_p2%2==0)
{
player1_input();
c_p1_p2++;
printf("\033[31m");
}
else
{
    super_input();
    c_p1_p2++;
    printf("\033[33m");
}
draw();
check();

}
}
//#######################
else if(choice==2)
{
while (c_p1_p2<9&&gameover==0)
{
    
if (c_p1_p2%2==0)
{
player1_input();
c_p1_p2++;
printf("\033[31m");
}
else
{
    player2_input();
    c_p1_p2++;
    printf("\033[33m");
}
draw();
check();

}
}
//#####################
else if(choice==3)
{
while (c_p1_p2<9&&gameover==0)
{
    
if (c_p1_p2%2==0)
{
player1_input();
c_p1_p2++;
printf("\033[31m");
}
else
{
    evil_input();
    c_p1_p2++;
    printf("\033[33m");
}
draw();
check();

}
}
//#####################
else if (choice==4)
{
    printf("\033[34m");
printf("you exit from game");
}
else
{
    printf("\033[35m");
printf("Invalid input plese press correct bottum");
goto invalid;
}
if (c_p1_p2==9)
{
printf("Match drawn");
}
return 0;
}
