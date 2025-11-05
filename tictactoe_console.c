//This program implements a console-based Tic-Tac-Toe game for two players on a 3×3 board. Key features include:

//Dynamic board allocation: The board is stored as a dynamically allocated 2D array of characters.

//Gameplay mechanics:

//Players take turns entering row and column numbers to place their marker (O for Player 1, X for Player 2).

//The program checks for invalid moves (out-of-bounds or already occupied cells).

//Players can quit by entering -1 -1.

//Winner detection: The win() function checks for a winning row, column, or diagonal.

//Board display: The printboard() function prints the board after each move if the user chooses output mode.

//Endgame outcomes: Announces Player 1 or Player 2 as the winner or declares a draw if the board is full.

//Memory management: Frees all dynamically allocated memory at the end.


#include <stdio.h>
#include <stdlib.h>


void printboard (char **board, int rows, int cols){
  for(int i=0;i<rows;i++){
    printf("-------------\n");
    printf("|");
    for( int j=0;j<cols;j++){
      printf(" %c |", board[i][j]);
    }
    printf("\n");
  }
    printf("-------------\n");

}
char win(char **board, int rows, int cols){
    for( int i = 0; i < rows; i++) {
      if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
    return board[i][0];}
    }
    for (int j = 0; j < cols; j++) {
      if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]){
    return board[0][j];
      }}
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
      return board[0][0];}
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
      return board[0][2];}
    return ' ';
}
    
int main(){
  int rows = 3;
  int cols = 3;
  char winner = ' ';
  int move = 0;
  char mode;
  int player=1;
  char **board = malloc(rows*sizeof(char *));
  for(int i=0;i<rows;i++){
    board[i]=malloc(cols*sizeof(char));
  }
  for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++)
      board[i][j]=' ';
  
  printf("Output Play (y/n):\n");
  scanf(" %c",&mode);
  printf("You entered %c.\n",mode);
  printf("Starting game with 3 x 3 board.\n");
  printf("Each player should enter\na row and col num (eg: 2 0).\n");
  int row,col;
  
  while(winner==' ' && move<9){
     
      printf("Player %d:\n",player);
      scanf("%d %d",&row,&col);
      if(row==-1 || col ==-1){
          printf("Quit\n");
          break;
      }
      if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != ' '){
          printf("Incorrect value, try again.\n");
          continue;
      }
    
      if (player ==1)
          board[row][col]='O';
      else
          board[row][col]='X';
      printf("Player %d entered %d %d.\n", player, row, col);

      winner = win(board, rows, cols);
      move++;
      if(mode=='y')
        printboard(board,rows,cols);
      
      if(player==1){
        player=2;}
      else
        player=1;
  }
  
  if(winner =='O')
    printf("Player 1 is the winner.\n");
  else if(winner =='X')
    printf("Player 2 is the winner.\n");
  else
    printf("It's a draw.\n");
  printboard(board, rows, cols);

  for(int i=0;i<rows;i++){
      free(board[i]);}
  free(board);

  return 0;
}
    
