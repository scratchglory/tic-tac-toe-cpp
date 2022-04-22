#include <iostream> // cin/cout
#include <iomanip> // setprecision, setw
#include <string> // string
using namespace std;


// Function Definitions
void welcome();
void displayBoard(char board[][3]);
void playerInput(char board[][3], char mark);
bool checkWinner(char board[][3], char player, char p2);

int main(){
  // delclare board, players, results
  char board[][3] = {{'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'}};
  char p1 = 'X', p2 = 'O';
  int results = 0;
  string winner = "";

  // Welcome message
    cout << "Hello Players! Welcome to T-T-T.\n";
  // Display board using nested loops
    displayBoard(board);
  // Ask for player input to initialize
    playerInput(board, p1);
    displayBoard(board);
   // checking for a winner

      // iterate through for each turn while checking for winner
      for (int i = 0; i < 4; i++) {
        playerInput(board, p2);
        displayBoard(board);
        // If returned true, return winner
        if(checkWinner(board, p1, p2)){
        break;
        }

        playerInput(board, p1);
        displayBoard(board);
        // If returned true, return winner
        if(checkWinner(board, p1, p2)){
        break;
        }
        cout << endl;
      } // end of for loop
    
  
    
  return 0;
}

// Functions Defined
// Display board
void displayBoard(char board[][3]){
  // Nested loops to fill the arrway with numbers
  cout << setw(15) << "COLUMNS" << endl;
  cout <<  setw(18) << "0   1   2 " << endl;
  // iterate through rows
  for (int row = 0; row < 3; row++) {
    cout << "row " << row << " | ";
    // iterate through columns
    for (int col = 0; col < 3; col++){
      cout << board[row][col] << " | ";
      }
      cout << endl;
      cout << "      -------------" << endl;
  }
}
// Player input and board validations, true or false
void playerInput(char board[][3], char player){
  int row, col;
  bool space = false;
  // display message to players to select a spot
  cout << "Choose a row and column to place your " << player << endl;
  
  do {
    cout << "row: " << endl;
    cin >> row;
    cout << "col: " << endl;
    cin >> col;

  // check if the space is available, if not try again
    if (board[row][col] == '*'){
      board[row][col] = player;
      space = true;
    } else {
      cout << "Try a another space\n";
    }
    system("cls");
  
  } while (space == false);
}; // end of playerInput()

// checking for a winner, true or false
bool checkWinner(char board[][3], char p1, char p2) {
    string theWinner = "";
     bool winner = false;
    // check if "X" is the winner

    if (
        // check across row 0
        board[0][0] == p1 && board[0][1] == p1 && board[0][2] == p1 ||
        // check across row 1
        board[1][0] == p1 && board[1][1] == p1 && board[1][2] == p1 ||
        // check across row 2
        board[2][0] == p1 && board[2][1] == p1 && board[2][2] == p1 ||
        // check down column 0
        board[0][0] == p1 && board[1][0] == p1 && board[2][0] == p1 ||
        // check down column 1
        board[0][1] == p1 && board[1][1] == p1 && board[2][1] == p1 ||
        // check down column 2
        board[0][2] == p1 && board[1][2] == p1 && board[2][2] == p1 ||
        // check diagonal backward slash
        board[0][0] == p1 && board[1][1] == p1 && board[2][2] == p1 ||
        // check diagonal forward slash 
        board[2][0] == p1 && board[1][1] == p1 && board[0][2] == p1
    ){
        theWinner = "Player 1 wins!\n";
        cout << theWinner;
        winner = true;
        return winner;
    } else if (
        // check across row 0
        board[0][0] == p2 && board[0][1] == p2 && board[0][2] == p2 ||
        // check across row 1
        board[1][0] == p2 && board[1][1] == p2 && board[1][2] == p2 ||
        // check across row 2
        board[2][0] == p2 && board[2][1] == p2 && board[2][2] == p2 ||
        // check down column 0
        board[0][0] == p2 && board[1][0] == p2 && board[2][0] == p2 ||
        // check down column 1
        board[0][1] == p2 && board[1][1] == p2 && board[2][1] == p2 ||
        // check down column 2
        board[0][2] == p2 && board[1][2] == p2 && board[2][2] == p2 ||
        // check diagonal backward slash
        board[0][0] == p2 && board[1][1] == p2 && board[2][2] == p2 ||
        // check diagonal forward slash 
        board[2][0] == p2 && board[1][1] == p2 && board[0][2] == p2
    ){
    theWinner = "Player 2 wins!\n";
        cout << theWinner;
        winner = true;
        return winner;
    } else {
        theWinner = "No Winner. It's a tie!\n";
        cout << theWinner;
        winner = false;
        return winner;
    }
}
