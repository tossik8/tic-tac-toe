#include <iostream>

const int gridSize = 3;

int* acceptInput(char squares[gridSize][gridSize]) {
	std::cout << "\t\t\tEnter a number: ";
	int res;
	std::cin >> res;
	if (!res) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return acceptInput(squares);
	}
	
	else if (res < 1 || res > 9 || squares[res/3][res%3 - 1] == 'X' || squares[res/3][res%3-1] == 'O') {
		return acceptInput(squares);
	}
	int square[2] = { res / 3, res % 3 - 1 };
	return square;
}
bool checkDiagonalWin(char squares[gridSize][gridSize], size_t rows, size_t cols) {
	for (int row = 1; row < rows; ++row) {
		if (squares[row][row] != squares[0][0] && squares[row][cols-1-row] != squares[0][cols-1]) return false;
	}
	return true;
}
bool checkVerticalWin(char squares[gridSize][gridSize], size_t rows, size_t cols) {
	for (int col = 0; col < cols; ++col) {
		bool line = true;
		for (int row = 1; row < rows; ++row) {
			if (squares[row][col] != squares[0][col]) {
				line = false;
				break;
			}
		}
		if (line) return true;
	
	}
	return false;
}

bool checkHorizontalWin(char squares[gridSize][gridSize], size_t rows, size_t cols) {
	for (int row = 0; row < rows; ++row) {
		bool line = true;
		for (int col = 1; col < cols; ++col) {
			if (squares[row][col] != squares[row][0]) {
				line = false;
				break;
			}
		}
		if (line) return true;
	}
	return false;
}
bool checkWin(char squares[gridSize][gridSize], size_t rows, size_t cols) {
	return checkDiagonalWin(squares, rows, cols) || checkVerticalWin(squares, rows, cols) || checkHorizontalWin(squares,rows,cols);
}

bool checkAvailableSquares(char squares[gridSize][gridSize], size_t rows, size_t cols) {
	for (int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j){
			if (squares[i][j] >= '0' && squares[i][j] <= '9') return true;
		}
	}
	return false;
}

void printGrid(char squares[gridSize][gridSize]) {
	std::cout << "\t\t\t    |    |    \n"
		<< "\t\t\t  " << squares[0][0] << " |  " << squares[0][1] << " |  " << squares[0][2] << " \n"
		<< "\t\t\t____|____|____\n"
		<< "\t\t\t    |    |    \n"
		<< "\t\t\t  " << squares[1][0] << " |  " << squares[1][1] << " |  " << squares[1][2] << " \n"
		<< "\t\t\t____|____|____\n"
		<< "\t\t\t    |    |    \n"
		<< "\t\t\t  " << squares[2][0] << " |  " << squares[2][1] << " |  " << squares[2][2] << " \n"
		<< "\t\t\t    |    |    \n\n";
}

int main() {
	using std::cout;
	cout << "\t\t\tHello, you've started Tic Tac Toe\n";
	char squares[gridSize][gridSize] = {{'1','2','3'}, {'4', '5', '6'}, {'7', '8', '9'}};
	bool first = true;
	while (!checkWin(squares, sizeof(squares) / sizeof(squares[0]), sizeof(squares[0]) / sizeof(char))
		&& checkAvailableSquares(squares, sizeof(squares) / sizeof(squares[0]), sizeof(squares[0]) / sizeof(char))) {
		if (first) {
			cout << "\t\t\tPlayer's with 'X' turn\n\n";
		}
		else {
			cout << "\t\t\tPlayer's with 'O' turn\n\n";
		}
		printGrid(squares);
		
		int* square = acceptInput(squares);
		if (first) {
			squares[square[0]][square[1]] = 'X';
		}
		else {
			squares[square[0]][square[1]] = 'O';
		}
		first = !first;
	}
	printGrid(squares);
	if (checkWin(squares, sizeof(squares) / sizeof(squares[0]), sizeof(squares[0]) / sizeof(char)) && first) {
		cout << "Player 'O' won!!!";
	}
	else if (checkWin(squares, sizeof(squares) / sizeof(squares[0]), sizeof(squares[0]) / sizeof(char)) && !first) {
		cout << "Player 'X' won!!!";
	}
	else {
		cout << "It's a draw";
	}

	
}

