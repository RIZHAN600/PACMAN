#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include <cstdlib>
#include <time.h>
#include <Windows.h>
using namespace std;
class pacman{

private:


	int Score;
	int level;
	
	int dotcount;
	int h = 10;//20//20//55
	int w = 10;//20//26//26
	char arr['h']['w'];
	int gRow;
	int gCol;

	int check;
	int F1, F2;
	int pRow, Row;
	bool loose;

public:
	//initial set for varriables
	pacman()
	{
		
		
		Score = 0;
		level = 1;
		dotcount = 0;
		check = 0;
		F1 = 1, F2 = 1;
		pRow = F1, Row = F2;
		
	}

	//starting conditions level-1
	void start()
	{
		
	HANDLE  hConsole;
		int clr1 = 10;
		int clr2 = 3;
		
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, clr2);
		
		printGrid();
		
		//playing loop
		//while code
		int choice;
		while (check != 1)
		{
			
			choice = _getch();
			move(choice);
		}

		if (loose == true)
		{
			system("CLS");
			cout << "\n\n\n\n\t\t\tYOU LOOSE\n\n\n\n" << endl;
		}
		else
		{
			system("CLS");
			cout << "\n\n\n\n\t\t\tYOU WON\n\n\n\n" << endl;
			printScore();
			resetVars();

			int LvlChoice;
			cout << "Press 1 for next, 2 for Exit" << endl;
			cin >> LvlChoice;

			if (LvlChoice == 1)
			{
				

				
				SetConsoleTextAttribute(hConsole, clr1);
				levelTwo();
			}

			_getch();
		}
	}//Start Ends


	//adjusting printing grid and 
	void printGrid()
	{
		
		//for level one
		//dotcount = 0;
		h = 20;
		w = 20;
		arr['h']['w'] = { ' ' };
		gRow = w - 2;
		gCol = 1;
		//for first line of grid
		cout << "\tPAC MAN GAME\n\n\tBY\n\n\tRIZ & WASIF\n\n ";
		for (int i = 0; i < w; i++)
		{
			arr[0][i] = '1';
        }

		//for bootom line of grid

		for (int j = 0; j < w; j++)
		{
			arr[h - 1][j] = '1';
		}

		//for left line grid
		for (int k = 1; k < h - 1; k++)
		{
			arr[k][0] = '1';
		}

		//for Right line of grid
		for (int l = 1; l < h - 1; l++)
		{
			arr[l][w - 1] = '1';
		}


		//Center Maze Code
		//for center left line
		for (int m = 3; m < h - 6; m++)
		{
			arr[m][5] = '1';
		}

		// for lower line

		for (int ll = 5; ll<w - 6; ll++)
		{
			arr[h - 6][ll] = '1';

		}
		//for center right line
		for (int n = 3; n < h - 6; n++)
		{
			arr[n][w - 4] = '1';
		}

		//for upper line with right

		for (int ul = 8; ul <w - 3; ul++)
		{
			arr[3][ul] = '1';

		}

		//initializin first location
		//int F1 = 1, F2 = 1;
		arr[F1][F2] = '<';

		time_t seconds;
		time(&seconds);
		srand((unsigned int)seconds);

		int randX = w - 1;
		int randY = h - 1;

		int r, c, sterikChck = 0;
		while (sterikChck != 1)
		{
			r = rand() % randX + 0;
			c = rand() % randY + 0; 

			if (arr[r][c] != '<' && arr[r][c] != '1')
			{
				arr[r][c] = '*';
				dotcount++;
				sterikChck = 1;
			}
		}
		//initializing with dots in array
		for (int a = 0; a < h; a++)
		{
			for (int b = 0; b < w; b++)
			{
				if (arr[a][b] != '1' && arr[a][b] != '<' && arr[a][b] != '*')
				{
					arr[a][b] = '.';
					dotcount++;
				}
			}
		}

		arr[gRow][gCol] = '@'; dotcount--;

		//printing array
	
		print();
	}
	

	//reset variables
	void resetVars()
	{
		check = 0;
		level++;
	}

	char currChar = '.';

	//ghostmovement
	void moveGhost(int dir)
	{
		if (dir == 1)
			//left
		{
			//moveghost left
			if (arr[gRow][gCol - 1] == '1')
			{
				//beep
			}
			else if (arr[gRow][gCol - 1] == 'v' || arr[gRow][gCol - 1] == '<' || arr[gRow][gCol - 1] == '>' || arr[gRow][gCol - 1] == '^')
			{
				check = 1;
				loose = true;
			}
			else
			{
				if (arr[gRow][gCol - 1] == '.' || arr[gRow][gCol - 1] == '*')
				{
					dotcount--;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}
			
				arr[gRow][gCol - 1] = '@';
				arr[gRow][gCol] = ' ';
				gCol--;
			}
		}


		if (dir == 2)//right
		{
			//moveghost left
			if (arr[gRow][gCol + 1] == '1')
			{
				//beep
			}
			else if (arr[gRow][gCol + 1] == 'v' || arr[gRow][gCol + 1] == '<' || arr[gRow][gCol + 1] == '>' || arr[gRow][gCol + 1] == '^')
			{

				check = 1;
				loose = true;
			}

			else
			{
				if (arr[gRow][gCol + 1] == '.' || arr[gRow][gCol + 1] == '*')
				{
					dotcount--;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}
				
				arr[gRow][gCol + 1] = '@';
				arr[gRow][gCol] = ' ';
				gCol++;
			}
		}


		if (dir == 3)//up
		{
			//moveghost left
			if (arr[gRow - 1][gCol] == '1')
			{
				//beep
			}
			else if (arr[gRow - 1][gCol] == 'v' || arr[gRow - 1][gCol] == '<' || arr[gRow - 1][gCol] == '>' || arr[gRow - 1][gCol] == '^')
			{
				check = 1;
				loose = true;
			}

			else
			{
				if (arr[gRow - 1][gCol] == '.' || arr[gRow - 1][gCol] == '*')
				{
					dotcount--;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}
				
				arr[gRow - 1][gCol] = '@';
				arr[gRow][gCol] = ' ';
				gRow--;
			}
		}

		if (dir == 4)//down
		{
			//moveghost left
			if (arr[gRow + 1][gCol] == '1')
			{
				//beep
			}
			else if (arr[gRow + 1][gCol] == 'v' || arr[gRow + 1][gCol] == '<' || arr[gRow + 1][gCol] == '>' || arr[gRow + 1][gCol] == '^')
			{
				check = 1;
				loose = true;
			}

			else
			{
				if (arr[gRow + 1][gCol] == '.' || arr[gRow + 1][gCol] == '*')
				{
					dotcount--;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}
			
				arr[gRow + 1][gCol] = '@';
				arr[gRow][gCol] = ' ';
				gRow++;
			}
		}	
	}
	
	//pacmovement default leve1
	void move(int choice)
	{
		
		if (choice == 75)//for left
		{

			if (arr[pRow][Row - 1] == '1')
			{
				//cout << "here is beep" << "\a";
			}

			else
			{
				if (arr[pRow][Row - 1] == '@')
				{
					check = 1;
					loose = true;
				}

				moveGhost(1);

				if (arr[pRow][Row - 1] == '.')
				{
					dotcount--;
					Score++;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}
				if (arr[pRow][Row - 1] == '*')
				{
					dotcount--;
					Score = Score + 5;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}

				arr[pRow][Row] = ' ';
				arr[pRow][Row - 1] = '>';
				Row--;

				if (loose == true)
				{
					cout << "\n\n\n\n\t\t\tYOU LOOSE\n\n\n\n" << endl;
				}
				else
				{
					system("CLS");
					print();
				}
				//system("CLS");
				//print();
			}

		}//1 if
		//choice 2

		if (choice == 77)//for right
		{
			if (arr[pRow][Row + 1] == '1')
			{
				//cout << "here is beep" << "\a";
				cout << "\a";

			}

			else
			{
				if (arr[pRow][Row + 1] == '@')
				{
					check = 1;
					loose = true;
				}

				moveGhost(2);

				if (arr[pRow][Row + 1] == '.')
				{
					dotcount--;
					Score++;

					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}

				if (arr[pRow][Row + 1] == '*')
				{
					dotcount--;
					Score = Score + 5;

					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}

				arr[pRow][Row] = ' ';
				arr[pRow][Row + 1] = '<';
				Row++;
				if (loose == true)
				{
					cout << "\n\n\n\n\t\t\tYOU LOOSE\n\n\n\n" << endl;
				}
				else
				{
					system("CLS");
					print();
				}

				
			}
		}//2if


		//choice upward 3
		if (choice == 72)
		{

			if (arr[pRow - 1][Row] == '1')
			{
				//cout << "here is beep" << "\a";
				cout << "\a";
			}

			else
			{
				if (arr[pRow - 1][Row] == '@')
				{
					check = 1;
					loose = true;
				}

				if (gRow > pRow)
				{
					moveGhost(3);
				}
				else
				{
					moveGhost(4);
				}
				/////////////
				if (arr[pRow - 1][Row] == '.')
				{
					dotcount--;
					Score++;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}

				if (arr[pRow - 1][Row] == '*')
				{
					dotcount--;
					Score = Score + 5;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}

				arr[pRow][Row] = ' ';
				arr[pRow - 1][Row] = 'v';
				pRow--;

				if (loose == true)
				{
					cout << "\n\n\n\n\t\t\tYOU LOOSE\n\n\n\n" << endl;
				}
				else
				{
					system("CLS");
					print();
				}
				//system("CLS");
				//print();

			}
		}//3if

		//choice downward 4
		if (choice == 80)
		{

			if (arr[pRow + 1][Row] == '1')
			{
				//cout << "here is beep" << "\a";
				cout << "\a";
			}

			else
			{
				if (arr[pRow + 1][Row] == '@')
				{
					check = 1;
					loose = true;

				}

				if (gRow > pRow)
				{
					moveGhost(3);
				}
				else
				{
					moveGhost(4);
				}


				if (arr[pRow + 1][Row] == '.')
				{
					dotcount--;
					Score++;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}

				if (arr[pRow + 1][Row] == '*')
				{
					dotcount--;
					Score = Score + 5;
					if (dotcount == 0)
					{
						check = 1;
						//break;
					}
				}

				arr[pRow][Row] = ' ';
				arr[pRow + 1][Row] = '^';
				pRow++;

				if (loose == true)
				{
					cout << "\n\n\n\n\t\t\tYOU LOOSE\n\n\n\n" << endl;
				}
				else
				{
					system("CLS");
					print();
				}


			}
		}//4if

	}

	//print
	void print()
	{
		
		for (int x = 0; x < h; x++)
		{
			cout << "\t\t";
			for (int y = 0; y < w; y++)
			{
				cout << arr[x][y];
			}
			cout << endl;
		}

	
		printScore();
	}
	
	//for level two
	void levelTwo()
	{
		h = 10;
		w = 10;
		arr['h']['w'] = { ' ' };
		gRow = w - 2;//ghostrow
		gCol = 1;//pacmanrow



		//for first line of grid
		for (int i = 0; i < w; i++)
		{
			arr[0][i] = '1';

			
		}

		//for bootom line of grid

		for (int j = 0; j < w; j++)
		{
			arr[h - 1][j] = '1';
		}

		//for left line grid
		for (int k = 1; k < h - 1; k++)
		{
			arr[k][0] = '1';
		}

		//for Right line of grid
		for (int l = 1; l < h - 1; l++)
		{
			arr[l][w - 1] = '1';
		}


		//Center Maze Code

		//for center left line
		for (int m = 3; m < h - 6; m++)
		{
			arr[m][5] = '1';
		}

		// for lower line

		for (int ll = 5; ll<w - 6; ll++)
		{
			arr[h - 6][ll] = '1';

		}
		//for center right line
		for (int n = 3; n < h - 6; n++)
		{
			arr[n][w - 4] = '1';
		}

		//for upper line with right

		for (int ul = 8; ul <w - 3; ul++)
		{
			arr[3][ul] = '1';

		}

		//initializin first location
		
		arr[F1][F2] = '<';
		

		time_t seconds;
		time(&seconds);
		srand((unsigned int)seconds);

		
		int randX = w - 1;
		int randY = h - 1;

		int r, c, sterikChck = 0;
		while (sterikChck != 1)
		{
			r = rand() % randX + 0;
			c = rand() % randY + 0;

		

			if (arr[r][c] != '<' && arr[r][c] != '1')
			{
				arr[r][c] = '*';
				dotcount++;
				sterikChck = 1;
			}
		}
		//initializing with dots in array
		for (int a = 0; a < h; a++)
		{
			for (int b = 0; b < w; b++)
			{
				if (arr[a][b] != '1' && arr[a][b] != '<' && arr[a][b] != '*')
				{
					arr[a][b] = '.';
					dotcount++;
				}
			}
		}

		arr[gRow][gCol] = '@'; dotcount--;



		//printing array
		print();

		cout << "dot cout is:" << dotcount;

		//int check = 0;
		pRow = F1; Row = F2;

		//playing loop
		//while code
		int choice;
		while (check != 1)
		{
			choice = _getch();
			move(choice);


		}
		if (loose == true)
		{
			system("CLS");
			cout << "\n\n\n\n\t\t\tYOU LOOSE\n\n\n\n" << endl;
		}
		else
		{
			system("CLS");
			cout << "\n\n\n\n\t\t\tYOU WON\n\n\n\n" << endl;
			printScore();
			_getch();
		}

		
	}
	
	//score print
	void printScore()
	{
		cout << "\n Your score is: " << Score << "\n";
		cout << "Level: " << level << endl;
		cout << "dotcount is:" << dotcount << endl;

	}



};