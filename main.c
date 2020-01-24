#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 


void print_matrix();
void clrscr();
void gotoxy(int x, int y);
void delay(int);
int x=50 , y=10;
char map[5][10];

int main()
{
	int i=0 , j=0 ;
	int pacman_r , pacman_c , arrow , fruit=0;
	
	gotoxy(40,10);
	printf("HOW TO PLAY\n");
	gotoxy(40,11);
	printf("YOU ARE THE WHITE SQUARE\n");
	gotoxy(40,12);
	printf("YOU SHOULD EAT ALL OF THE CHERRIES\n");
	gotoxy(40,13);
	printf("YOU SHOULD NOT GO ON THE OSBSTACLES");
	delay(5);
	clrscr();
	gotoxy(40,12);
	printf("ARE U READY?");
	delay(2);
	clrscr();
	gotoxy(40,12);
	printf("NOW ENTER THE CODES FOR THE MAP!");
	delay(2);
	clrscr();
	
	
	for(i=0 ; i<5 ; i++)
	{
		for(j=0 ; j<10 ; j++)
		{
			scanf(" %c" , &map[i][j]);
			if(map[i][j]=='0')
			{
				pacman_r = i;
				pacman_c = j; 
				map[i][j] = 254;	
			}
			
			else if(map[i][j] == '#')
			{
				if(i==0 && j==0) //gushe
					map[i][j] = 201;
					
				else if(i==0 && j==9) //gushe
					map[i][j] = 187;
					
				else if(i==4 && j==0) //gushe
					map[i][j] = 200;
					
				else if(i==4 && j==9) //gushe
					map[i][j] = 188;
					
				else if(i==0 && j>0 && j<10) //khat bala
					map[i][j] = 205;
					
				else if(i==4 && j>0 && j<10) //khat payin
					map[i][j] = 205; 
					
				else if(j==0 && i>0 && i<5) //khat chap
					map[i][j] = 186;
					
				else if(j==9 && i>0 && i<5) //khat rast
					map[i][j] = 186;
				else
					map[i][j] = 240; //mane haye vasat
			}
			
			else if(map[i][j] == '1')
				map[i][j] = 32;
			
			else if(map[i][j] == '*')
			{
				map[i][j] = 235;
				fruit++;
			}
				
		}
	}
	
	delay(1);	
	clrscr();
	

	print_matrix();
	y=10;
	print_matrix();
	
	
	
	
	getchar(); //reading \n
	
	getch(arrow);
	
	if(arrow == '-')
		{
			printf("the game has ended by the player");
		}
	
	while(fruit>0)
	{
		if(arrow = 224)
		{
			arrow = getch();
			if(arrow == 77) //right click
			{
				if(map[pacman_r][pacman_c] == ' ')
				{
					
					
				}
			}
			
		}
		if(arrow == '-')
		{
			printf("the game has ended by the player");
		}
		getch(arrow);
	}
		
		

	
	
		
}
void print_matrix() 
{
	int i , j;
	for(i=0 ; i<5 ; i++)
	{
		gotoxy(x,y);
		for(j=0 ; j<10 ; j++)
		{
			printf("%c" , map[i][j]);
		}
		printf("\n");
		y++;
	}
}

void gotoxy(int x, int y)
{
    HANDLE ConsoleOutput;
    COORD dwCursorPosition;
    dwCursorPosition.X=x;
    dwCursorPosition.Y=y;
    ConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(ConsoleOutput, dwCursorPosition);
}

void clrscr()
{
    system("cls");
}

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds) 
        ; 
} 


