#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player = 'X';
int chance = 1;
int choice;

void display()
{
	system("cls");
	cout<<"\n\t!! WELCOME TO TIC-TAC-TOE GAME !!\n\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<"  \n";
	cout<<"\t\t     |     |     \n\n";

}

void input()
{

	while(1)
	{
		cout<<"\tPlayer "<<chance<<" ["<<player<<"] turn :\n\tenter your choice in the Grid : ";
		cin>>choice;
		cin.clear();
		cin.ignore(INT_MAX,'\n');

		int temp = 0;
		switch (choice)
		{
			case 1: if(grid[0][0] != 'X' && grid[0][0] != 'O')
						grid[0][0] = player;
					else
						temp=1;
					break;
			case 2: if(grid[0][1] != 'X' && grid[0][1] != 'O')
						grid[0][1] = player;
					else
						temp=1;
					break;
			case 3: if(grid[0][2] != 'X' && grid[0][2] != 'O')
						grid[0][2] = player;
					else
						temp=1;
					break;
			case 4: if(grid[1][0] != 'X' && grid[1][0] != 'O')
						grid[1][0] = player;
					else
						temp=1;
					break;
			case 5: if(grid[1][1] != 'X' && grid[1][1] != 'O')
						grid[1][1] = player;
					else
						temp=1;
					break;
			case 6: if(grid[1][2] != 'X' && grid[1][2] != 'O')
						grid[1][2] = player;
					else
						temp=1;
					break;
			case 7: if(grid[2][0] != 'X' && grid[2][0] != 'O')
						grid[2][0] = player;
					else
						temp=1;
					break;
			case 8: if(grid[2][1] != 'X' && grid[2][1] != 'O')
						grid[2][1] = player;
					else
						temp=1;
					break;
			case 9: if(grid[2][2] != 'X' && grid[2][2] != 'O')
						grid[2][2] = player;
					else
						temp=1;
					break;

			default:temp=1;
					break;
		}

		if(temp == 1)
			cout<<"\n\tinvalid entry, Try again !!\n";
		if(choice > 0 && choice <10 && temp == 0)
		{
			if(player == 'O')
				player = 'X';
			else
				player = 'O';

			if(chance == 2)
				chance = 1;
			else
				chance = 2;
			break;
		}
	}

}

int result()
{
	int test = 0;

	for(int i=0; i<3; i++)
	{
		if(grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2])
			test = 1;

		if(grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i])
			test = 2;

		if(test == 1 || test == 2)
			{
				int winner;

				if(grid[i][i] == 'X')
					winner = 1;
				else
					winner = 2;

				display();
				cout<<"\n\n\tCongratulations !! Player "<<winner<<" ["<<grid[i][0]<<"] Won the Game\n";

				return 1;
			}
	}

	if(grid[0][0] == grid[1][1] && grid[0][0] ==grid[2][2])
		test = 3;
	if(grid[1][1] == grid[0][2] && grid[1][1] ==grid[2][0])
		test = 4;

	if(test == 3 || test == 4)
	{
		int winner;

		if(grid[1][1] == 'X')
			winner = 1;
		else
			winner = 2;

		display();
		cout<<"\n\n\tCongratulations !! Player "<<winner<<" ["<<grid[1][1]<<"] Won the Game\n";

			return 1;
	}


	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
			if(grid[i][j] != 'X' && grid[i][j] != 'O')
				return 0;
	}
	display();
	cout<<"\n\n\t\t Game Draw !!";
	return 1;

}

int main()
{
	while(1)
	{

		display();
		input();
		int r = result();
		if(r==1)
			break;
	}
	cout<<"\n\tThank you for playing !!";
	cout<<"\n\tEnter any key to exit";

	return 0;
}

