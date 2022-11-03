#include <iostream>

std::string grid[9];

int index = 0;
int moves = 0;

bool gameOver = false;
bool circleTurn = true;

int combinations[8][3] = {
	{ 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 }
};

void InitializeGrid()
{
	for (int i = 0; i < 9; i++)
	{
		grid[i] = "_";
	}
}

void DisplayGrid()
{
	system("cls");
	for (int i = 0; i < 9; i++)
	{
		if (i != 0 && i % 3 == 0) std::cout << std::endl;
		std::cout << grid[i] << " ";
	}
	std::cout << std::endl;
}

void SwapTurns()
{
	if (circleTurn)
		circleTurn = !circleTurn;
	else
		circleTurn = true;
}

void PlaceMark(std::string value)
{
	if (grid[index] == "_") grid[index] = value;
	else
	{
		SwapTurns();
		moves--;
	}
}


bool IsDraw()
{
	bool draw = false;
	if (moves == 9)
	{
		draw = true;
	}
	return draw;
}

bool IsWinning(std::string currentTurn)
{
	bool win = false;
	for (int i = 0; i < 8; i++)
	{
		if (grid[combinations[i][0]] == currentTurn && grid[combinations[i][1]] == currentTurn && grid[combinations[i][2]] == currentTurn)
		{
			win = true;
		}
	}
	return win;
}

void StartGame()
{
	InitializeGrid();
	DisplayGrid();
}

int main()
{
	StartGame();
	while (!gameOver)
	{
		DisplayGrid();
		std::string currentTurn = circleTurn ? "O" : "X";
		std::cout << currentTurn << ": ";
		std::cout << "Grid index: ";
		std::cin >> index;
		PlaceMark(currentTurn);
		if (IsWinning(currentTurn))
		{
			DisplayGrid();
			std::cout << currentTurn << " won!";
			gameOver = true;
		}
		moves++;
		if (IsDraw())
		{
			DisplayGrid();
			std::cout << "Draw!";
			gameOver = true;
		}
		if (index < 9) SwapTurns();
	}
}
