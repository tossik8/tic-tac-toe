#include <iostream>


int acceptInput(char* squares) {
	std::cout << "Enter a number: ";
	int res;
	std::cin >> res;
	if (!res) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return acceptInput(squares);
	}
	
	else if (res < 1 || res > 9 || squares[res-1] == 'X' || squares[res-1] == 'O') {
		return acceptInput(squares);
	}
	
	return res;
}
bool checkDiagonalWin(char* squares) {
	return squares[0] == squares[4] && squares[0] == squares[8] || squares[2] == squares[4] && squares[2] == squares[6];
}
bool checkVerticalWin(char* squares) {
	return squares[0] == squares[3] && squares[0] == squares[6] ||
		squares[1] == squares[4] && squares[1] == squares[7]||
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

int main() {
	using std::cout;
	cout << "Hello, you've started Tic Tac Toe\n";
	char squares[9] = {'1','2','3','4','5','6', '7', '8', '9'};
	bool first = true;
	while (!checkWin(squares) && checkAvailableSquares(squares)){
		if (first) {
			cout << "Player's with 'X' turn\n\n";
		}
		else {
			cout << "Player's with 'O' turn\n\n";
		}
		cout << "   |   |   \n"
			<< " " << squares[0] << " | " << squares[1] << " | " << squares[2] << " \n"
			<< "___|___|___\n"
			<< "   |   |   \n"
			<< " " << squares[3] << " | " << squares[4] << " | " << squares[5] << " \n"
			<< "___|___|___\n"
			<< "   |   |   \n"
			<< " " << squares[6] << " | " << squares[7] << " | " << squares[8] << " \n"
			<< "   |   |   \n\n";
		int square = acceptInput(squares) - 1;
		if (first) {
			squares[square] = 'X';
		}
		else {
			squares[square] = 'O';
		}
		first = !first;
	}
	cout << "   |   |   \n"
		<< " " << squares[0] << " | " << squares[1] << " | " << squares[2] << " \n"
		<< "___|___|___\n"
		<< "   |   |   \n"
		<< " " << squares[3] << " | " << squares[4] << " | " << squares[5] << " \n"
		<< "___|___|___\n"
		<< "   |   |   \n"
		<< " " << squares[6] << " | " << squares[7] << " | " << squares[8] << " \n"
		<< "   |   |   \n\n";
	if (checkWin(squares) && first) {
		cout << "Player 'O' won!!!";
	}
	else if (checkWin(squares) && !first) {
		cout << "Player 'X' won!!!";
	}
	else {
		cout << "It's a draw";
	}

	
}

