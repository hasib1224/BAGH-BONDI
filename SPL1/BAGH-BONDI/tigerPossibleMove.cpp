
#include"tiger.h"
//#include"twoPlayerMode.h"
#include"globalVariable.h"

int tiger_possible_move(int m1,int m2){

   int   move_count=0;
   if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
     (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

      if(board2[m1-1][m2+1]=='*'){
         move_count++;
      }
      else if(board2[m1-1][m2+1]=='G'){
         if(board2[m1-2][m2+2]=='*') move_count++;
      }

      if(board2[m1+1][m2-1]=='*'){
         move_count++;
      }
      else if(board2[m1+1][m2-1]=='G'){
         if(board2[m1+2][m2-2]=='*') move_count++;
      }


      if(board2[m1-1][m2-1]=='*'){
         move_count++;
      }
      else if(board2[m1-1][m2-1]=='G'){
         if(board2[m1-2][m2-2]=='*') move_count++;
      }


      if(board2[m1+1][m2+1]=='*'){
         move_count++;
      }
      else if(board2[m1+1][m2+1]=='G'){
         if(board2[m1+2][m2+2]=='*') move_count++;
      }


      if(board2[m1-1][m2]=='*'){
         move_count++;
      }
      else if(board2[m1-1][m2]=='G'){
         if(board2[m1-2][m2]=='*') move_count++;
      }


      if(board2[m1+1][m2]=='*'){
         move_count++;
      }
      else if(board2[m1+1][m2]=='G'){
         if(board2[m1+2][m2]=='*') move_count++;
      }


      if(board2[m1][m2+1]=='*'){
        move_count++;
      }
      else if(board2[m1][m2+1]=='G'){
         if(board2[m1][m2+2]=='*') move_count++;
      }


      if(board2[m1][m2-1]=='*'){
         move_count++;
      }
      else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') move_count++;
      }


   }


   else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
      (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

      if(board2[m1-1][m2]=='*'){
         move_count++;
      }
      else if(board2[m1-1][m2]=='G'){
         if(board2[m1-2][m2]=='*') move_count++;
      }


      if(board2[m1+1][m2]=='*'){
         move_count++;
      }
      else if(board2[m1+1][m2]=='G'){
         if(board2[m1+2][m2]=='*') move_count++;
      }


      if(board2[m1][m2+1]=='*'){
         move_count++;
      }
      else if(board2[m1][m2+1]=='G'){
         if(board2[m1][m2+2]=='*') move_count++;
      }

      if(board2[m1][m2-1]=='*'){
         move_count++;
      }
      else if(board2[m1][m2-1]=='G'){
         if(board2[m1][m2-2]=='*') move_count++;
      }


   }


   return move_count;

  }





