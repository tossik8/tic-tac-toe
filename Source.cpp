#include <iostream>

int acceptInput(char* squares) {
	std::cout << "\t\t\t\t\tEnter a number: ";
	int res;
	std::cin >> res;
	if (!res) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return acceptInput(squares);
	}

	else if (res < 1 || res > 9 || squares[res - 1] == 'X' || squares[res - 1] == 'O') {
		return acceptInput(squares);
	}

	return res;
}
bool checkDiagonalWin(char* squares) {
	return squares[0] == squares[4] && squares[0] == squares[8] || squares[2] == squares[4] && squares[2] == squares[6];
}
bool checkVerticalWin(char* squares) {
	return squares[0] == squares[3] && squares[0] == squares[6] ||
		squares[1] == squares[4] && squares[1] == squares[7] ||
		squares[2] == squares[5] && squares[2] == squares[8];
}

bool checkHorizontalWin(char* squares) {
	return squares[0] == squares[1] && squares[0] == squares[2] ||
		squares[3] == squares[4] && squares[3] == squares[5] ||
		squares[6] == squares[7] && squares[6] == squares[8];
}
bool checkWin(char* squares) {
	return checkDiagonalWin(squares) || checkVerticalWin(squares) || checkHorizontalWin(squares);
}

bool checkAvailableSquares(char* squares) {
	for (int i = 0; i < 9; ++i) {
		if (squares[i] >= '0' && squares[i] <= '9') return true;
	}
	return false;
}

void printGrid(char* squares, bool first) {
	system("cls");
	std::cout << "\t\t\t\t\tHello, you've started Tic Tac Toe\n\n";
	if (first) {
		std::cout << "\t\t\t\t\tPlayer's with 'X' turn\n\n\n";
	}
	else {
		std::cout << "\t\t\t\t\tPlayer's with 'O' turn\n\n\n";
	}
	std::cout << 
		   "\t\t\t\t\t    |    |    \n"
		<< "\t\t\t\t\t  " << squares[0] << " |  " << squares[1] << " |  " << squares[2] << " \n"
		<< "\t\t\t\t\t____|____|____\n"
		<< "\t\t\t\t\t    |    |    \n"
		<< "\t\t\t\t\t  " << squares[3] << " |  " << squares[4] << " |  " << squares[5] << " \n"
		<< "\t\t\t\t\t____|____|____\n"
		<< "\t\t\t\t\t    |    |    \n"
		<< "\t\t\t\t\t  " << squares[6] << " |  " << squares[7] << " |  " << squares[8] << " \n"
		<< "\t\t\t\t\t    |    |    \n\n";
}

void printGrid(char* squares) {
	system("cls");
	std::cout <<
		"\n\n\n\n\n\t\t\t\t\t    |    |    \n"
		<< "\t\t\t\t\t  " << squares[0] << " |  " << squares[1] << " |  " << squares[2] << " \n"
		<< "\t\t\t\t\t____|____|____\n"
		<< "\t\t\t\t\t    |    |    \n"
		<< "\t\t\t\t\t  " << squares[3] << " |  " << squares[4] << " |  " << squares[5] << " \n"
		<< "\t\t\t\t\t____|____|____\n"
		<< "\t\t\t\t\t    |    |    \n"
		<< "\t\t\t\t\t  " << squares[6] << " |  " << squares[7] << " |  " << squares[8] << " \n"
		<< "\t\t\t\t\t    |    |    \n\n";
}

int main() {
	using std::cout;
	char squares[9] = { '1','2','3','4','5','6', '7', '8', '9' };
	bool first = true;
	while (!checkWin(squares) && checkAvailableSquares(squares)) {
		printGrid(squares, first);
		int square = acceptInput(squares) - 1;
		if (first) {
			squares[square] = 'X';
		}
		else {
			squares[square] = 'O';
		}
		first = !first;
	}
	printGrid(squares);
	if (checkWin(squares) && first) {
		cout << "\n\t\t\t\t\tPlayer 'O' won!!!\n\n";
	}
	else if (checkWin(squares) && !first) {
		cout << "\n\t\t\t\t\tPlayer 'X' won!!!\n\n";
	}
	else {
		cout << "\n\t\t\t\t\tIt's a draw\n\n";
	}
}
