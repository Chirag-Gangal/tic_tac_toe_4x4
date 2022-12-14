// 4x4 tic tac toe game in c++ by Chirag Gangal
#include <iostream>
using namespace std; 

// Define the board
char board[4][4] = {{'1', '2', '3', '4'}, 
                    {'5', '6', '7', '8'}, 
                    {'9', '10', '11', '12'}, 
                    {'13', '14', '15', '16'}};

// Prints the board
void printBoard() 
{ 
    cout << "\n\n"; 
  
    for (int i = 0; i < 4; i++) 
    { 
        for (int j = 0; j < 4; j++) 
            cout << board[i][j] << " "; 
  
        cout << endl; 
    } 
} 

// Checks if the move is valid
bool isMoveValid(int move) 
{ 
    if (move >= 1 && move <= 16) 
    { 
        int row = (move - 1) / 4; 
        int col = (move - 1) % 4; 
  
        if (board[row][col] != 'X' && board[row][col] != 'O') 
            return true; 
    } 
  
    return false; 
} 

// Checks if the game is over
bool isGameOver() 
{ 
    // Check horizontal 
    for (int i = 0; i < 4; i++) 
        if (board[i][0] == board[i][1] && 
            board[i][1] == board[i][2] &&  
            board[i][2] == board[i][3] &&  
            (board[i][0] == 'X' || board[i][0] == 'O')) 
            return true; 
  
    // Check vertical 
    for (int i = 0; i < 4; i++) 
        if (board[0][i] == board[1][i] && 
            board[1][i] == board[2][i] &&  
            board[2][i] == board[3][i] &&  
            (board[0][i] == 'X' || board[0][i] == 'O')) 
            return true; 
  
    // Check diagonal 
    if (board[0][0] == board[1][1] && 
        board[1][1] == board[2][2] &&  
        board[2][2] == board[3][3] &&  
        (board[0][0] == 'X' || board[0][0] == 'O')) 
        return true; 
  
    if (board[0][3] == board[1][2] && 
        board[1][2] == board[2][1] &&  
        board[2][1] == board[3][0] &&  
        (board[0][3] == 'X' || board[0][3] == 'O')) 
        return true; 
  
    // Check if there are any moves left 
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++) 
            if (board[i][j] != 'X' && board[i][j] != 'O') 
                return false; 
  
    // Draw 
    return true; 
} 

// The main function 
int main() 
{ 
    bool playerXTurn = true; 
  
    cout << "Tic-Tac-Toe 4x4\n"; 
    printBoard(); 
  
    while (1) 
    { 
        int move; 
        if (playerXTurn) 
            cout << "Player X turn: "; 
        else
            cout << "Player O turn: "; 
  
        cin >> move; 
  
        if (!isMoveValid(move)) 
        { 
            cout << "Invalid Move!!\n"; 
            continue; 
        } 
  
        int row = (move - 1) / 4; 
        int col = (move - 1) % 4; 
  
        if (playerXTurn) 
            board[row][col] = 'X'; 
        else
            board[row][col] = 'O'; 
  
        printBoard(); 
  
        if (isGameOver()) 
        { 
            if (playerXTurn) 
                cout << "\nPlayer X Wins!!\n"; 
            else
                cout << "\nPlayer O Wins!!\n"; 
            break; 
        } 
  
        playerXTurn = !playerXTurn; 
    } 
  
    return 0; 
}
