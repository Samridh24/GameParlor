#include<windows.h>							//For Sleep()
#include<stdlib.h>							//For fflush() and random
#include<string.h>							//For using string functions
#include<stdio.h>							//For standard input/output
#include<conio.h>							//For getch()
#include<time.h>							//for null timing


int tictactoe();
int snakeandladder();
void handcricket();
void credits();

void mainmenu()
{
	int choice;
	do
	{
		system("cls");
		printf("=========================SDF MINOR PROJECT===========================\n");
		printf("----------------------WELCOME TO GAME PARLOUR------------------------\n");

		printf("\n");

		printf("MainMenu\n");
		printf("\n");

		printf("1. Tic Tac Toe\n");

		printf("2. Snakes and Ladders\n");

		printf("3. Hand Cricket\n");

		printf("4. Credits\n");

		printf("5. Exit\n");

		fflush(stdin);
		scanf("%d",&choice);

		if(choice==1)
			tictactoe();
		else if(choice==2)
			snakeandladder();
		else if(choice==3)
			handcricket();
		else if(choice==4)
		    credits();	
		else if(choice==5)
		{
			printf("Thanks for playing!!Hope you enjoyed\n");
			exit(0);
		}		
			
		else
			system("cls");	
	}while(choice<1||choice>4);
	
}

/*//Some define macros
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4 */

//Function Declarations for Hand cricket
int toss(char name[]);
int batting(int overs,char name[]);
void result(int score_p,int score_c,char name[]);

//Global variables for Hand cricket
int over=0,temp=-1,count=0;

//Code for Hand Cricket
void handcricket()
{
	system("cls");
	int choice,choose;
	char name[50],ch;
	srand(time(NULL));
	printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
	lb:
	
	printf("Choose the option\n");
	printf("\n");
	printf("\n");
	printf("1.Play until out\n");
	printf("\n");
	printf("2.Play for limited over\n");
	printf("\n");
	printf("3.How to play\n");
	printf("\n");
	printf("4.Exit\n");
	fflush(stdin);
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1:	printf("------------------------------GAMEPLAY------------------------------\n");
				printf("Enter your name-");
				fflush(stdin);
				gets(name);
				choose=toss(name);
				break;
		case 2:	printf("------------------------------GAMEPLAY------------------------------\n");
				printf("Enter your name-");
				fflush(stdin);
				gets(name);
				printf("Enter number of overs-");
				scanf("%d",&over);
				
				choose=toss(name);
			
				
				break;
		case 3:	printf("---------------------------------INSTRUCTIONS---------------------------------\n");
				printf("This game is build to refresh your memories of childhood.\n");
				printf("Let's go through the basic rules:\n");
				printf("The game is simple,you just have to beat the computer with more runs and make \n");
				printf("the computer feel inferior, to win you have to make more runs than the computer\n");
				printf("or don't let the computer to make more runs than you unless you want computer \n");
				printf("to win.\n");
				printf("To start the game,Toss will be done between you and the computer. You can choose");
				printf("head or tail for the toss and if you won the toss it is your call to bat or ball");
				printf("if you lose let computer make the decision for itself.\n");
				printf("\nAfter the toss is done;\n");
				printf("You have to either bat/bowl according to the result.\n");
				printf("For playing,you have to choose a number between 1 to 6 and then a number is \n");
				printf("choosen by the computer.\n");
				printf("In case,both choose a different number then score of the player batting is equal");
				printf("to the number choosen by him. The total score keeps on adding until both comes \n");
				printf("up with the same number. After that,batsman will out.\n");
				printf("Thus, a target is set for the bowler to chase while batting in the next inning.\n");
				printf("\nNow,Press any key to start the game\n");
				getch();
				system("cls");
				printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
				goto lb;
				break;
		case 4:	printf("Thanks for playing,Hope you enjoyed!!!\n");
				Sleep(1000);
				mainmenu();
				break;
		default:printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
				goto lb;
	}
	printf("-------------------------------------------------------------------------\n");
	printf("Do you want to play again(Y/N)-");
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='Y'||ch=='y')
	{	system("cls");
		printf("------------------------WELCOME TO HAND CRICKET------------------------\n");
		goto lb;
	}		
	else
		printf("\nThanks for playing the game!!");
		printf("Hope you enjoyed!!!  :) \n");
		mainmenu();
}
int toss(char name[])											//Toss function
{	
	int t,x,choose,score_p=0,score_c=0;
	printf("\n%s,Let's Toss!" ,name);
	printf("Select your choice\n1.Head 2.Tail\n",name);
	do
	{	
		fflush(stdin);
		scanf("%d",&t);
		if(t==1)
			printf("You choose Head\n");
		else if(t==2)
			printf("You choose Tail\n");
		else{
			system("cls");
			printf("%s,Enter your choice for toss\n1.Head 2.Tail\n",name);}
	}while(t<1||t>2);
	x=rand()%(2)+1;
	if(x==t)
	{	
		tos:
		printf("%s,You won the toss\n",name);
		printf("Choose\n1.Batting\n2.Bowling\n");
		fflush(stdin);
		scanf("%d",&choose);
		if(choose==1)
		{
			printf("You chooses to Bat\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			result(score_p,score_c,name);
		}
		else if(choose==2)
		{
			printf("You chooses to Bowl\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			result(score_p,score_c,name);
		}
		else
		{
			system("cls");
			printf("Invalid choice!!!Try once again\n");
			printf("---------------------------------------------------\n");
			goto tos;
		}
	}
	else
	{
		printf("%s,You lose the toss\n",name);
		choose=x;
		if(x==1)
		{
			printf("Computer chooses to Bat\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			result(score_p,score_c,name);
		}
		else
		{
			printf("Computer chooses to Ball\n");
			printf("\nEnter any key to start the game\n");
			getch();
			system("cls");
			printf("Let's start the game..............\n");
			score_p=batting(over,name);
			printf("\n%s,your total score is %d\n",name,score_p);
			score_c=batting(over,"Computer");
			printf("\nComputer's total score is %d\n",score_c);
			result(score_p,score_c,name);
		}
	}
}

int batting(int overs,char name[])								//function for game
{
	int score=0,i=0,j=1;
	char decide[5];
	count++;
	if(strcmp(name,"Computer")==0)
	{
		printf("-----------------------You are going to bowl now-------------------------\n");	
		strcpy(decide,"Bowl");
	}
	
	else
	{
		printf("-----------------------You are going to bat now-------------------------\n");
		strcpy(decide,"Bat");
	}
	again:
	printf("Enter from 1-6");
	int bat,bowl;
	if(overs>0)
	{
		for(i=0;i<overs;i++)
		{
			for(j=1;j<=6;j++)
			{
				printf("\n\t\tCurrent score=%d\n",score);
				printf("%d.%d Bowl\n",i,j);
				printf("%s : ",decide);
				fflush(stdin);
				scanf("%d",&bat);
				if(bat>0&&bat<7)
				{
					bowl=rand()%6+1;
					printf("Computer : %d",bowl);
					if(bat==bowl)
					{
						if(score==0)
							printf("\nOhhhhh!!Duck out");
						else
							printf("\nOhhh!! It's Out");
						temp=score;
						return score;
					}
					else
					{
						if(strcmp(name,"Computer")==0)
						{
							if(bowl==6)
								printf("\nOhhhhh!!Its a six");
							else if(bowl==4)
								printf("\nIt's boundary!!");
							score+=bowl;
						}
						else
						{
							if(bat==6)
								printf("\nSixerrrrrr!!Go ahead");
							else if(bat==4)
								printf("\nIt's a four!Keep it up");
							score+=bat;
						}
					}
					if(count%2==0&&temp<score)
						return score;
				}
				else
				{
					printf("Invalid input!!!Try once again\n");
					printf("---------------------------------------------------\n");
					goto again;
				}
			}
		printf("\n%d over completed\n",i+1);
		}
		return score;
	}
	else
	{	
		while(1)
		{
			printf("\n\t\tCurrent score=%d\n",score);
			printf("%d.%d Bowl\n",i,j);
			if(j!=6)
				j++;
			else{
				j=1;
				++i;
			}
			printf("%s : ",decide);
			fflush(stdin);
			scanf("%d",&bat);
			if(bat>0&&bat<7)
			{
				bowl=rand()%6+1;
				printf("Computer : %d",bowl);
				if(bat==bowl)
				{
					if(score==0)
						printf("\nOhhhhh!!Duck out");
					else
						printf("\nOhhh!! It's Out");
					temp=score;
					return score;
				}
				else
				{
					if(strcmp(name,"Computer")==0)
					{
						if(bowl==6)
							printf("\nOhhh its a six!!");
						else if(bowl==4)
							printf("\nIts a boundary!!");
						score+=bowl;
					}
					else
					{
						if(bat==6)
							printf("\nSixerrrrrr!!Go ahead");
						else if(bat==4)
							printf("\nIt's a four!Keep it up");
						score+=bat;
					}
				}
				if(count%2==0&&temp<score)
						return score;
			}
			else
			{
				printf("Invalid input!!!Try once again\n");
				printf("---------------------------------------------------\n");
				j--;
				goto again;
			}		
		}	
	}
}

void result(int score_p,int score_c,char name[])				//Result function
{
	printf("-----------------------------------------------------------------------\n");
	printf("\nScores are counting wait..........\n");
	Sleep(2000);
	printf("\nResults are ready!!Enter any key to see the results\n");
	getch();
	system("cls");
	printf("-----------------------Time for result-----------------------\n");

	if(score_p>score_c)

		printf("Hurray!!!You win by %d runs\n\n",score_p-score_c);

	else if(score_p<score_c)

		printf("Oops!You lose by %d runs\n\n",score_c-score_p);

	else
		printf("Match is draw.Both scored %d\n\n",score_c);
}

//End for Hand Cricket

//Using ansi colour codes

#define Y "\e[43m"
#define O "\e[44m"

#define RESET "\e[0m"

// Function to roll a six-sided die 

int rollDie() {
     return rand() % 6 + 1;
      } 

// global variables to store postions of player1 and player2 

int player1 = 0, player2 = 0; 

// Function to print the board 

void printBoard() 
{ 
	// logic to print a snake-ladder Game board 
	// way to print a snake ladder board.

    system("cls");

    printf("---------------SNAKE AND LADDERS GAME-------------\n");
    printf("\n");

	printf("---------INSTRUCTIONS---------\n");
	printf("\n");

    printf("This is the list of LADDERS on the board : 6 -> 46 , 26 -> 34 , 48 -> 58 77 -> 82 , 89 -> 93 \n");
    printf("\nThis is the list of all SNAKES on the board : 23 -> 13 , 45 -> 38 , 61 -> 43 , 65 -> 57 , 95 -> 30 , 98 -> 88 \n");
    printf("\n");

    printf("\nplayer one you are YELLOW "Y"  "RESET);

    printf("\nplayer two you are BLUE "O"  \n"RESET);
    
    printf("\n");
    printf("\n");

    int board[101]; 
	for (int i = 1; i <= 100; i++) { 
		board[i] = i; 
	} 

	int alt = 0; // to switch between the alternate nature of the board 
	int iterLR = 101; // iterator to print from left to right 
	int iterRL = 80; // iterator to print from right to left 
	int val = 100;	

	while (val--) { 
		if (alt == 0) { 
			iterLR--; 
			if (iterLR == player1) { 
                // THIS IS P1
                // P1 IS YELLOW
				printf(" "Y"  "RESET" "); 

			} 
			else if (iterLR == player2) { 
                // THIS IS P2 
                // P2 IS BLUE
				printf(" "O"  "RESET" "); 

			} 
			else
				printf("%d ", board[iterLR]); 

			if (iterLR % 10 == 1) { 
				printf("\n\n"); 
				alt = 1; 
				iterLR -= 10; 
			} 
		} 
		else { 
			iterRL++; 
			if (iterRL == player1) { 
				printf(" "Y"  "RESET" "); 
                 
			} 
			else if (iterRL == player2) { 
				printf(" "O"  "RESET" "); 
                
			} 
			else
				printf("%d ", board[iterRL]); 

			if (iterRL % 10 == 0) { 
				printf("\n\n"); 
				alt = 0; 
				iterRL -= 30; 
			} 
		} 
		if (iterRL == 10) 
			break; 
	} 
	printf("\n"); 
} 

// Function to move the player 

int movePlayer(int currentPlayer, int roll) 
{ 
	int newPosition = currentPlayer + roll; 
	// Define the positions of snakes and ladders on the 
	// board 
	int snakesAndLadders[101]; 

	for (int i = 0; i <= 100; i++) { 
		snakesAndLadders[i] = 0; 
	} 
	
	// here positive weights represent a ladder 
	// and negative weights represent a snake. 

	snakesAndLadders[7] = 40; 
	snakesAndLadders[23] = -10; 
	snakesAndLadders[45] = -7; 
	snakesAndLadders[61] = -18; 
	snakesAndLadders[65] = -8; 
	snakesAndLadders[77] = 5; 
	snakesAndLadders[98] = -10; 
    snakesAndLadders[26] = 8;
    snakesAndLadders[48] = 10;
    snakesAndLadders[89] = 4;
    snakesAndLadders[95] = -60;


	int newSquare 
		= newPosition + snakesAndLadders[newPosition]; 

	if (newSquare > 100) { 
		return currentPlayer; // Player cannot move beyond 
							// square 100 
	} 

	return newSquare; 
} 

int snakeandladder() 
{ 
	srand(time(0)); // Initialize random seed 
	int currentPlayer = 1; 
	int won = 0; 

	printf("Snake and Ladder Game\n"); 

	while (!won) { 

		printf( 
			"\nPlayer %d, press Enter to roll the die...", 
			currentPlayer); 
		getchar(); // Wait for the player to press Enter 
		int roll = rollDie(); 
		printf("You rolled a %d.\n", roll); 
        getchar();
		if (currentPlayer == 1) { 
			player1 = movePlayer(player1, roll); 
			printf("Player 1 is now at square %d.\n\n", 
				player1); 
			printBoard(); 
			if (player1 == 100) { 
				printf("Player 1 wins!\n"); 
                printf("GAME OVER!!!\n");
				won = 1; 
			} 
		} 
		else { 
			player2 = movePlayer(player2, roll); 
			printf("Player 2 is now at square %d.\n\n", player2); 

			printBoard(); 

			if (player2 == 100) { 
				printf("Player 2 wins!\n"); 
                printf("GAME OVER!!!\n");
				won = 1; 
			} 
		} 

		
		

		// Switch to the other player 

		currentPlayer = (currentPlayer == 1) ? 2 : 1; 

	} 
    mainmenu();
	return 0; 
}

// TIC TAC TOE GAME FUNCTION
// Globally declared 2D-array

char board[3][3];
 
// Function to initialize the game board

void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    int count = 1;
    printf("\n\n\t  ");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d", count++);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}
 
// Function shows the game board

void showBoard(int x, int y)
{
    printf("\n\n\t  ");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c", board[i][j]);
            if (j < 2)
            {
                printf("  |  ");
            }
        }
        if (i < 2)
        printf("\n\t----------------\n\t  ");
    }
    printf("\n\n\n");
}
 
// Function to update the game board

int updateBoard(int cell, char playerSign)
{
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    int isValid = 1;
 
    // accessing already played cell number

    if (board[row][col] != ' ')
    {
        printf("\nInvalid: Cell is already Filled!\n");
        isValid = 0;
    }
 
    // valid cell position

    else
    {
        board[row][col] = playerSign;
    }
    showBoard(row, col);
 
    return isValid;
}
 
// Function to check the winner of the game

int checkWinner(char sg)
{
    // check all rows

    if (board[0][0] == sg && board[0][1] == sg && board[0][2] == sg ||
      board[1][0] == sg && board[1][1] == sg && board[1][2] == sg ||
      board[2][0] == sg && board[2][1] == sg && board[2][2] == sg)
    {
        return 1;
      }
      // check all columns

    else if (board[0][0] == sg && board[1][0] == sg && board[2][0] == sg ||
           board[0][1] == sg && board[1][1] == sg && board[2][1] == sg ||
           board[0][2] == sg && board[1][2] == sg && board[2][2] == sg)
    {
        return 1;
    }
    // check both diagonals

    else if (board[0][0] == sg && board[1][1] == sg && board[2][2] == sg ||
           board[0][2] == sg && board[1][1] == sg && board[2][0] == sg)
    {
        return 1;
    }
 
    // There is no winner

    return 0;
}
 
// Start your game from here

void playTicTacToe()
{
    int gameResult = 0;
    int cell = 0;
    int playCount = 0;
    int updationResult = 1;
 
    char playerSign = ' ';
 
    // start playing the game
    while (!gameResult && playCount < 9)
    {
        if (playCount % 2 == 0)
        {
            // player 1
            printf("\nPlayer 1 [ X ] : ");
            playerSign = 'X';
        }
        else
        {
            // player 2
            printf("\nPlayer 2 [ O ] : ");
            playerSign = 'O';
        }
        scanf("%d", &cell);
        if (cell > 0 && cell < 10)
        {
            updationResult = updateBoard(cell, playerSign);
            // if updation is possible
            if (updationResult)
            {
                gameResult = checkWinner(playerSign);
                // print the winner of the game
                if (gameResult)
                {
                    printf("\t *** Player %d Won!! ***\n", playerSign == 'X' ? 1 : 2);
                }
                playCount++;
            }
        }
        else if (cell == -1)
        {
            printf("\n\tGame Terminated\n");
            return;
        }
        else
        {
            printf("\nPlease Enter a valid cell value\n");
        }
    }
 
    // no one won the game

    if (!gameResult && playCount == 9)
    {
        printf("\n\t *** Draw...  ***\n");
    }
    printf("\n\t --- Game Over --- \n");
}
 
int tictactoe()

{
    printf("--------- Tic Tac Toe ----------\n\n");
 
    printf("\n* Instructions \n\n");
    printf("\tPlayer 1 sign = X\n");
    printf("\tPlayer 2 sign = O");
    printf("\n\tTo exit from game, Enter -1\n");
 
    printf("\n\n* Cell Numbers on Board\n");
    initializeBoard();
 
    char start = ' ';
    printf("\n> Press Enter to start...");
 
    scanf("%c", &start);
 
    if (start)
    {
        int userChoice = 1;
        // restart the game
        while (userChoice)
        {
            playTicTacToe();
            printf("\n* Menu\n");
            printf("\nPress 1 to Restart");
            printf("\nPress 0 for Exit");
            printf("\n\nChoice: ");
            scanf("%d", &userChoice);
            if (userChoice)
            {
                initializeBoard();
            }
            printf("\n");
        }
    }
    printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");

   mainmenu();

 return 0;
}

void credits(){
    
	printf("--------------------CREDITS---------------------\n");
	printf("\n");

	printf("This game is developed for the minor project of the \n");
	printf("software fundamental lab subject.\n");
	printf("The game parlour is made by Samridh as the first semester minor prject in 2023.\n");
    printf("\n");

	int back;

	printf("Press 0 to go back to main menu :\n");
	scanf("%d",&back);

	if(back==0)
	{
       mainmenu();
	}
}

void main(){

	printf("    __     __     ____");
	printf("   /  '\'   |  '\'   |");
	printf("   '\'      |   '\'  |");
	printf("    '\'     |   |  |____");
	printf("     '\'    |   |  |");
	printf("      '\'   |   /  |");
	printf("   '\'__/   |__/   |");
	mainmenu();
}