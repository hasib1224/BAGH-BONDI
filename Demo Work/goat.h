#ifndef goat_h
#define goat_h

#include "tiger.h"

void goat_scope_print(int m1,int m2){

   setlinestyle(0,0,10);
   setcolor(GREEN);
   cordinatew();
   s_track=0; 

   
   if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
      (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){
      if(board2[m1-1][m2+1]=='*'){ 
         rectangle(board[m1-1][m2+1].x-20,board[m1-1][m2+1].y-20,board[m1-1][m2+1].x+20, board[m1-1][m2+1].y+20);
         g_scope_track[s_track].x=m1-1; 
         g_scope_track[s_track].y=m2+1;  
         s_track++;
      }
       
   
      if(board2[m1+1][m2-1]=='*'){ 
         rectangle(board[m1+1][m2-1].x-20,board[m1+1][m2-1].y-20,board[m1+1][m2-1].x+20, board[m1+1][m2-1].y+20);
         g_scope_track[s_track].x=m1+1; 
         g_scope_track[s_track].y=m2-1; 
         s_track++;
      }
        

      if(board2[m1-1][m2-1]=='*'){ 
         rectangle(board[m1-1][m2-1].x-20,board[m1-1][m2-1].y-20,board[m1-1][m2-1].x+20, board[m1-1][m2-1].y+20);
         g_scope_track[s_track].x=m1-1; 
         g_scope_track[s_track].y=m2-1; 
         s_track++;
      }
          

      if(board2[m1+1][m2+1]=='*'){ 
         rectangle(board[m1+1][m2+1].x-20,board[m1+1][m2+1].y-20,board[m1+1][m2+1].x+20, board[m1+1][m2+1].y+20);
         g_scope_track[s_track].x=m1+1; 
         g_scope_track[s_track].y=m2+1; 
         s_track++;
      }
        

      if(board2[m1-1][m2]=='*'){ 
         rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         g_scope_track[s_track].x=m1-1; 
         g_scope_track[s_track].y=m2; 
         s_track++;
      }
        

      if(board2[m1+1][m2]=='*'){ 
         rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         g_scope_track[s_track].x=m1+1; 
         g_scope_track[s_track].y=m2;  
         s_track++;
      }
         

      if(board2[m1][m2+1]=='*'){ 
         rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);  
         g_scope_track[s_track].x=m1; 
         g_scope_track[s_track].y=m2+1;  
         s_track++;
      }
         

      if(board2[m1][m2-1]=='*'){ 
         rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         g_scope_track[s_track].x=m1; 
         g_scope_track[s_track].y=m2-1; 
         s_track++;
      }
       
        
   }   


   else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
      (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){
      if(board2[m1-1][m2]=='*'){ 
         rectangle(board[m1-1][m2].x-20,board[m1-1][m2].y-20,board[m1-1][m2].x+20, board[m1-1][m2].y+20);
         g_scope_track[s_track].x=m1-1; 
         g_scope_track[s_track].y=m2;  
         s_track++;
      }
       
           
      if(board2[m1+1][m2]=='*'){ 
         rectangle(board[m1+1][m2].x-20,board[m1+1][m2].y-20,board[m1+1][m2].x+20, board[m1+1][m2].y+20);
         g_scope_track[s_track].x=m1+1; 
         g_scope_track[s_track].y=m2; 
         s_track++;
      }
        
      if(board2[m1][m2+1]=='*'){
         rectangle(board[m1][m2+1].x-20,board[m1][m2+1].y-20,board[m1][m2+1].x+20, board[m1][m2+1].y+20);
         g_scope_track[s_track].x=m1; 
         g_scope_track[s_track].y=m2+1;  
         s_track++;
      }
           
      if(board2[m1][m2-1]=='*'){
         rectangle(board[m1][m2-1].x-20,board[m1][m2-1].y-20,board[m1][m2-1].x+20, board[m1][m2-1].y+20);
         g_scope_track[s_track].x=m1; 
         g_scope_track[s_track].y=m2-1;  
         s_track++;  
      }
        

   }

    

}


void goat_input_2 (){
   cordinatew();
   int k=0;
   POINT cursor;
   int x,y,q;
   

   while(1){
      cordinatew();
      if(GetAsyncKeyState(VK_LBUTTON)){
         GetCursorPos(&cursor);
         x=cursor.x;
         y=cursor.y-20;

         for(int i=0;i<5;i++){
           for(int j=0;j<5;j++){
              if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                 if(board2[i][j]=='*'){
                    for( q=0;q<=s_track;q++){
                        if(i==g_scope_track[q].x && j==g_scope_track[q].y){

                           board2[i][j]='G';
                           board2[goat_ind.x][goat_ind.y]='*';
                           k=1;
                           goat_suc_input=5; //tiger succes input
                           break;
                          
                        }
                       
                     }   
                     for(q=0;q<=s_track;q++){

                        g_scope_track[q].x=0; 
                        g_scope_track[q].y=0;  
                        goat_ind.x=0; 
                        goat_ind.y=0;
                     }

                     k=1;

                  } 
                  else if(board2[i][j]=='G') k=1;
                  
               }
            }
         }
      }  
      if(k==1) break;      
   }


}


void goat_scope(){
   int k = 0;
   POINT cursor;
   int x=0,y=0;
  

   while(1){
     if(GetAsyncKeyState(VK_LBUTTON)){
        GetCursorPos(&cursor);
        x=cursor.x;
        y=cursor.y-20;

        for(int i=0;i<5;i++){
          for(int j=0;j<5;j++){
              if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                 if(board2[i][j]=='G'){

                    goat_ind.x=i;
                    goat_ind.y=j;
                    cleardevice();
                    board_view();   
                    goat_scope_print(i,j); 
                    goat_input_2();
                    k=1;

                  } 
               }
            }
        }
   
      }  
      
      if(k==1) break;

   }

  
}          


void goat_input(){
   POINT cursor;
   int x,y;

   while(1){

      if(GetAsyncKeyState(VK_LBUTTON)){

        GetCursorPos(&cursor);
        x=cursor.x;
        y=cursor.y-20;
        int k;
        for(int i=0;i<5;i++){
           for(int j=0;j<5;j++){             
              if((x>board[i][j].x-20 && x<board[i][j].x+20) && (y>board[i][j].y-20 && y<board[i][j].y+20)){
                  if(board2[i][j]=='*'){

                     readimagefile("GOAT.jpg",board[i][j].x-20,board[i][j].y-20,board[i][j].x+20, board[i][j].y+20);
                     total_goat--;
                     board2[i][j]='G';
                     goat_suc_input=5;  //goat input successfully
                     k=1;break;

                  } 
               }
            }
         }

        if(k==1) break;
      }              
   }
   
   
}          
 

#endif




