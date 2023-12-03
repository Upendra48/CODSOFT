//? Task 3 of C++ Programming Internship at Codsoft

//* Tic-Tac-Toe Game

/*
TASK 3

TIC-TAC-TOE GAME

Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other

Game Board: Create a 3x3 grid as the game board.
Players: Assign "X"and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.
*/

//todo: Using procedural programming

#include <bits/stdc++.h>
using namespace std;

//* Functions
void GameBoard(vector<vector<char>> &board);
void DisplayBoard(vector<vector<char>> &board);
bool UpdateBoard(vector<vector<char>> &board,char currentPlayer,int row,int col);
bool CheckForWin(vector<vector<char>> &board,char currentPlayer);
bool CheckForDraw(vector<vector<char>> &board);
void PlayGame();
bool PlayAgain();

int main(){
    system("cls");
    cout << " Welcome to TIC-TAC-TOE GAME" << endl;
    cout << "-----------------------------" << endl;
    cout << "Player 1: X" << endl;
    cout << "Player 2: O" << endl;
    cout << "------------" << endl;
    
    cout << "Enter the row and column number to place your move:" << endl;
    cout << "Game Board: " << endl<<endl;
    cout<< "0 0 | 0 1 | 0 2" << endl;
    cout << "---------------" << endl; 
    cout<< "1 0 | 1 1 | 1 2" << endl;
    cout << "---------------" << endl; 
    cout<< "2 0 | 2 1 | 2 2" << endl;


    do{
        PlayGame();
    } while (PlayAgain());
    
    cout<<"Thanks for playing Tic-Tac-Toe"<<endl;
    return 0;
}

void GameBoard(vector<vector<char>> &board){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DisplayBoard(vector<vector<char>> &board){
    cout << "Current Board: " << endl << endl;
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;j++){
            cout << board[i][j];
            if(j<2){
                cout<<" | ";
            }
        }
        cout<<endl;
        if(i<2){
            cout<<"---------"<<endl;
        }
            
    }
}

bool UpdateBoard(vector<vector<char>> &board,char currentPlayer,int row,int col){
    if(board[row][col]==' '){
        board[row][col] = currentPlayer;
        return true;
    }
    else{
        return false;
    }
}

bool CheckForWin(vector<vector<char>> &board, char currentPlayer){
    for (int i = 0; i < 3;++i){
        // check for row
        if(board[i][0]==currentPlayer && board[i][1]==currentPlayer && board[i][2]==currentPlayer){
            return true;
        }
        // check for column
        if(board[0][i]==currentPlayer && board[1][i]==currentPlayer && board[2][i]==currentPlayer){
            return true;
        }
    }
    // check for diagonal(top left to bottom right)
    if(board[0][0]==currentPlayer && board[1][1]==currentPlayer && board[2][2]==currentPlayer){
        return true;
    }
    // check for diagonal(top right to bottom left)
    if(board[0][2]==currentPlayer && board[1][1]==currentPlayer && board[2][0]==currentPlayer){
        return true;
    }
    return false;
}

bool CheckForDraw(vector<vector<char>> &board){
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            if(board[i][j]==' '){
                return false;
            }
        }
    }
    return true;
}

bool PlayAgain(){
    char choice;
    cout<<"Do you want to play again? (Y/N) : ";
    cin>>choice;
    if(choice=='Y' || choice=='y'){
        return true;
    }
    else{
        return false;
    }
}
        
void PlayGame(){
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    bool Win = false;
    bool Draw = false;


    GameBoard(board);
    DisplayBoard(board);

    do{
        int row, col;
        cout << endl;
        cout << "Player " << currentPlayer << " turn" << endl;
        cout << "Enter your move (row, col): ";
        cin >> row >> col;

        if(row>=0 && row<3 && col>=0 && col<3 && board[row][col]== ' '){   // check if the move is valid
            if(UpdateBoard(board,currentPlayer,row,col)){
                DisplayBoard(board);
                Win = CheckForWin(board,currentPlayer);
                Draw = CheckForDraw(board);
                if(Win || Draw){
                    break;
                }
                currentPlayer = (currentPlayer == player1) ? player2:player1;
                
            }
            else{
                cout<<"Invalid move!!"<<endl;
            }

        }
        else{   // if the move is invalid
            cout << "Invalid input!! " << endl;
            cout<< "Please enter row and column between 0 and 2 : " << endl;
        }


    } while (true);
    if(Win){
        cout<<"Player "<<currentPlayer<<" wins!!"<<endl;
    }
    else {
        cout<<"It's a draw!!"<<endl;
    }
    
}