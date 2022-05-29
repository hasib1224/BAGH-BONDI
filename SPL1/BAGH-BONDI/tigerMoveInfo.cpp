
#include"tiger.h"
//#include"twoPlayerMode.h"
#include"globalVariable.h"


int tiger_info(){
   int temp=0;
   total_move=0;
   for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
         if(board2[i][j]=='T'){
            temp=tiger_possible_move(i,j);
            total_move=total_move + temp;
            if(temp==0) {
               setlinestyle(0,0,10); setcolor(RED);
               rectangle(board[i][j].x-28,board[i][j].y-28,board[i][j].x+28, board[i][j].y+28);
            }
         }
      }
   }

   return total_move;

}





