#include"twoPlayerMode.h"
#include"globalVariable.h"

//extern char board2[50][50];

void board_initialize(){
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
         board2[i][j]='*';
      }
   }
   board2[0][0]='T';
   board2[0][4]='T';
   board2[4][0]='T';
   board2[4][4]='T';
}

