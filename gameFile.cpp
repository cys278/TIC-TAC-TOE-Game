#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For srand and rand functions
#include <ctime>   // For time function

using namespace std;

class TicTacToe {
private:
    vector<vector<char> > board;
    string player1Name, player2Name, currentPlayerName;
    char currentPlayerMark;
    int player1Score,player2Score,aiScore; 
    const int boardSize ; 
public:
    TicTacToe();
    void printBoard() const;
    bool checkWin(char player) const;
    bool checkTie() const;
    void playerTurn();
    void play(const int&,const int&);
    void reset();
    void playerVsPlayer();
    void playerVsComputer();
    void setPlayerNames(const string& name1, const string& name2);
    void updateScores(const string& playername,char player);
};

TicTacToe::TicTacToe() :boardSize(3), player1Score(0), player2Score(0), aiScore(0) {
    // Initialize the board with empty spaces
    for (int i = 0; i < boardSize; ++i) {
        vector<char> row(boardSize, ' ');
        board.push_back(row);
    }
}

void TicTacToe::printBoard() const {
    cout << "-------------" << endl;
    for (int i = 0; i < boardSize; ++i) {
        cout << "| ";
        for (int j = 0; j < boardSize; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool TicTacToe::checkWin(char player) const {
    for (int i = 0; i < boardSize; ++i) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] != player) {
                rowWin = false;
            }
            if (board[j][i] != player) {
                colWin = false;
            }
        }
        if (rowWin || colWin) {
            return true;
        }
    }
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 0; i < boardSize; ++i) {
        if (board[i][i] != player) {
            diag1Win = false;
        }
        if (board[i][boardSize - 1 - i] != player) {
            diag2Win = false;
        }
    }
    if (diag1Win || diag2Win) {
        return true;
    }
    return false;
}

bool TicTacToe::checkTie() const {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::playerTurn() {
    int row, col;
    bool validInput = false;

    // Check if the current player is the computer
    if (currentPlayerName == "AI") {
        // Keep generating random coordinates until an empty cell is found
        do {
            row = rand() % boardSize;
            col = rand() % boardSize;
        } while (board[row][col] != ' ');
    } else {
        // Keep asking for input until valid input is entered
        while (!validInput) {
            cout << currentPlayerName << ", enter row (1-" << boardSize << ") and column (1-" << boardSize << ") separated by space: ";
            cin >> row >> col;
            --row; --col;

            // Check if the input is within the valid range and the selected cell is empty
            if (row >= 0 && row < boardSize && col >= 0 && col < boardSize && board[row][col] == ' ') {
                validInput = true;
            } else {
                cout << "Invalid move. Please enter row and column values within the range (1-" << boardSize << ") and select an empty cell." << endl;
            }
        }
    }

    // Set the player's mark on the board
    board[row][col] = currentPlayerMark;
}

void TicTacToe::reset() {
    // Reset the board and player scores to start a new game
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            board[i][j] = ' ';
        }
    }
 }

void TicTacToe::play(const int& game,const int& mode) {
    if (mode == 1) {
        if(game<1)
        {
        cout << "Enter Player 1's name: ";
        cin >> player1Name;
        cout << "Enter Player 2's name: ";
        cin >> player2Name;
        printBoard();
        currentPlayerName = player1Name;
        currentPlayerMark = 'X';
        }
        else {
            printBoard();
        }
    } else if (mode == 2) {
        if(game<1){
            cout << "Enter your name: ";
            cin >> player1Name;
            player2Name = "AI"; // Second player is AI
            printBoard();
            currentPlayerName = player1Name;
            currentPlayerMark = 'X';
            
        }
        else
        {
            printBoard();
        }
        
    } else {
        cout << "Invalid choice! Please enter 1 or 2." << endl;
        return;
    }

    // cout << "Let's play Tic-Tac-Toe!" << endl;
    // printBoard();

    // currentPlayerName = player1Name;
    // currentPlayerMark = 'X';

    while (true) {
        playerTurn();
        printBoard();
        if (checkWin('X')) {
            cout << player1Name << " wins!" << endl;
            updateScores(player1Name, 'X');
            break;
        } else if (checkWin('O')) {
            cout << player2Name << " wins!" << endl;
            updateScores(player2Name, 'O');
            break;
        } else if (checkTie()) {
            cout << "It's a tie!" << endl;
            break;
        }
        // Switch players
        currentPlayerName = (currentPlayerName == player1Name) ? player2Name : player1Name;
        currentPlayerMark = (currentPlayerMark == 'X') ? 'O' : 'X';
    }
}

void TicTacToe::playerVsPlayer() {
    
    if (player1Name.empty() || player2Name.empty()) {
        cout << "Enter Player 1's name: ";
        cin >> player1Name;
        cout << "Enter Player 2's name: ";
        cin >> player2Name;
    }

    currentPlayerName = player1Name;
    currentPlayerMark = 'X';

    cout << "Let's play Tic-Tac-Toe!" << endl;
    cout << player1Name << " is X and " << player2Name << " is O." << endl;
    printBoard();
    while (true) {
        playerTurn();
        printBoard();
        if (checkWin('X')) {
            cout << player1Name << " wins!" << endl;
            updateScores(player1Name, 'X');
            break;
        } else if (checkWin('O')) {
            cout << player2Name << " wins!" << endl;
            updateScores(player2Name, 'O');
            break;
        } else if (checkTie()) {
            cout << "It's a tie!" << endl;
            break;
        }
        // Switch players
        currentPlayerName = (currentPlayerName == player1Name) ? player2Name : player1Name;
        currentPlayerMark = (currentPlayerMark == 'X') ? 'O' : 'X';
    }
}

void TicTacToe::playerVsComputer() {
  bool nameEntered = !player1Name.empty(); // Check if the name has already been entered

    if (!nameEntered) {
        cout << "Enter your name: ";
        cin >> player1Name;
        nameEntered = true; // Set the flag to true after entering the name for the first time
    }

    currentPlayerName = player1Name;
    currentPlayerMark = 'X';

    srand(time(NULL)); // Seed for random number generation

    cout << "You are playing against the Computer!" << endl;
    cout << "You are X and the Computer is O." << endl;
    printBoard();
    while (true) {
        // Human player's turn
        playerTurn();
        printBoard();
        if (checkWin('X')) {
            cout << player1Name << " wins!" << endl;
            updateScores(player1Name, 'X');
            break;
        } else if (checkTie()) {
            cout << "It's a tie!" << endl;
            break;
        }
        
        // Computer's turn
        currentPlayerName = "AI";
        currentPlayerMark = 'O';
        playerTurn();
        printBoard();
        if (checkWin('O')) {
            cout << "AI wins!" << endl;
            updateScores("AI", 'O');
            break;
        } else if (checkTie()) {
            cout << "It's a tie!" << endl;
            break;
        }
        
        // Switch back to human player's turn
        currentPlayerName = player1Name;
        currentPlayerMark = 'X';
    }
}

void TicTacToe::setPlayerNames(const string& name1, const string& name2) {
    player1Name = name1;
    player2Name = name2;
}

void TicTacToe::updateScores(const string& playerName, char player) {
    if (player == 'X') {
        player1Score++;
    } else if (player == 'O') {
        if (playerName == "AI") {
            aiScore++;
        } else {
            player2Score++;
        }
    }

    // Display scores based on game mode
    if (player2Name == "AI") {
        cout << "Scores: " << player1Name << ": " << player1Score << " | " << "AI: " << aiScore << endl;
    } else {
        cout << "Scores: " << player1Name << ": " << player1Score << " | " << player2Name << ": " << player2Score << endl;
    }
}

int main() {
    cout << "Let's play Tic-Tac-Toe!" << endl;
    TicTacToe game;
    int totalgames = 0; // Initialize total games counter outside the loop

    int mode;
    cout << "Choose mode:\n1. Double Player Mode \n2. Single Player Mode\nEnter your choice: ";
    cin >> mode;

    while (true) {
        game.play(totalgames,mode);
        totalgames++; // Increment total games counter after playing the first game

        string playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if (playAgain != "Y" && playAgain != "y") {
            break;
        }
        game.reset();
    }

    cout << "Number of games: " << totalgames << endl;
    cout << "Thank You for playing TIC-TAC-TOE!!!" << endl;

    return 0;
}