#include<bits/stdc++.h>
using namespace std;

void tiger_input();
void tiger_move();
int tiger_possible_move(int m1,int m2);
int tiger_info();
void kill_goat();

void goat_input();
void goat_move();

void print_board();

int g1,g2,g3,g4,t1,t2,t3,t4;  //Temporary_variable_for_input
  char board[50][50];
  int g_count=20;       //GOAT NUMBER IS UP TO 20
  int t_count=4;        // TOTAL TIGER IS
  int total_move=0;     //TIGERS POSSIBLE MOVE NUMBER      
  int killed_g=0;       // KILLED GOAT NUMBER  


int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            board[i][j]='*';
        }
    }

    board[0][0]='T';
    board[0][4]='T';
    board[4][0]='T';
    board[4][4]='T';

      for(;;){
            print_board();
            goat_input(); 
            print_board();
            if(tiger_info()==0){
                cout<<"CONGRATULATIONS!! GOAT WIN THE MATCH!!!"; break;}
              else  tiger_input();
            if(killed_g==5){cout<<"CONGRATULATIONS!! TIGER WIN THE MATCH!!!"; break;}
         }

      }

//.............END MAIN METHOD...................

//...................GOAT_MOVE.............................
 void goat_input(){                              
     cout<<" Index for goat move:";  

     if(g_count>0){                             //goat_move_when_some goats are still in hand
         cin>>g3>>g4;
          if(board[g3][g4] =='*'){
              board[g3][g4]='G';g_count--;}
          else { cout<<"WRONG INDEX!!!\n";goat_input();}
        }

      else if(g_count==0){                       //goat_move_when_all goats are in field
         cin>>g1>>g2>>g3>>g4;
         goat_move();
        }
    }


void tiger_input(){     
    cout<<"\nInput Index for tiger move:";       
     cin>>t1>>t2>>t3>>t4;
     if(board[t1][t2]!='T') {cout<<"WRONG!!";tiger_input();}
      else kill_goat();  
      
   }


void print_board(){   
   for(int m=0;m<5;m+=1){cout<<"  "<<m;}
   cout<<"\n";          
     for(int i=0;i<5;i++){
        cout<<i;
         for(int j=0;j<5;j++){
           cout<<" "<<board[i][j]<<" ";
             }cout<<"\n"; 
        }
    }



void tiger_move(){
      if((t1==0 && t2==0)||(t1==0 && t2==2)||(t1==0 && t2==4)||(t1==1 && t2==1)||(t1==1 && t2==3)|| (t1==2 && t2==0)||(t1==2 && t2==2)||
      (t1==2 && t2==4)||(t1==3 && t2==1)||(t1==3 && t2==3)|| (t1==4 && t2==0)||(t1==4 && t2==2)||(t1==4 && t2==4)){

           if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
                if(board[t3][t4]=='*'){ board[t3][t4]='T';board[t1][t2]='*';}
                else {cout<<"WRONG INDEX !!";tiger_input();}
            }
            
            else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){
              if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
                else {cout<<"WRONG INDEX !!";tiger_input();}
            }

            else if(((t1-1==t3)&&(t2+1==t4))||((t1+1==t3)&&(t2-1==t4))){
             if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
             else{cout<<"WRONG INDEX !!";tiger_input();}
            }

            else if(((t1-1==t3)&&(t2-1==t4))||((t1+1==t3)&&(t2+1==t4))){
             if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
             else {cout<<"WRONG INDEX !!";tiger_input();}
            }

           else {cout<<"WRONG INDEX !!";tiger_input();}

        } 


     else if((t1==0 && t2==1)||(t1==0 && t2==3)||(t1==1 && t2==0)||(t1==1 && t2==2)||(t1==1 && t2==4)|| (t1==2 && t2==1)||(t1==2 && t2==3)||
            (t1==3 && t2==0)||(t1==3 && t2==2)||(t1==3 && t2==4)|| (t1==4 && t2==1)||(t1==4 && t2==3)){

                if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
                  if(board[t3][t4]=='*'){board[t3][t4]='T';board[t1][t2]='*';}
                    else {cout<<"WRONG INDEX !!";tiger_input();}
                }

               else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){
                 if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
                 else {cout<<"WRONG INDEX !!";tiger_input();}
                }

                else {cout<<"WRONG INDEX !!";tiger_input();}
   
    }
}



void goat_move(){
    if((t1==0 && t2==0)||(t1==0 && t2==2)||(t1==0 && t2==4)||(t1==1 && t2==1)||(t1==1 && t2==3)|| (t1==2 && t2==0)||(t1==2 && t2==2)||
    (t1==2 && t2==4)||(t1==3 && t2==1)||(t1==3 && t2==3)|| (t1==4 && t2==0)||(t1==4 && t2==2)||(t1==4 && t2==4)){

        if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
            if(board[t3][t4]=='*') {board[t3][t4]='G';board[t1][t2]='*';g_count--;}
            else { cout<<"WRONG INDEX!!!";goat_input();}
        }

         else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){
             if(board[t3][t4]=='*') {board[t3][t4]='G';board[t1][t2]='*';g_count--;}
             else { cout<<"WRONG INDEX!!!";goat_input();}
            }
           else if(((t1-1==t3)&&(t2+1==t4))||((t1+1==t3)&&(t2-1==t4))){
             if(board[t3][t4]=='*') {board[t3][t4]='G';board[t1][t2]='*';g_count--;}
             else { cout<<"WRONG INDEX!!!";goat_input();}
            }
            else if(((t1-1==t3)&&(t2-1==t4))||((t1+1==t3)&&(t2+1==t4))){
             if(board[t3][t4]=='*'){board[t3][t4]='G';board[t1][t2]='*';g_count--;}
             else { cout<<"WRONG INDEX!!!";goat_input();}
            }

           else {cout<<"WRONG INDEX !!";goat_input();}

    } 

     else if((t1==0 && t2==1)||(t1==0 && t2==3)||(t1==1 && t2==0)||(t1==1 && t2==2)||(t1==1 && t2==4)|| (t1==2 && t2==1)||(t1==2 && t2==3)||
            (t1==3 && t2==0)||(t1==3 && t2==2)||(t1==3 && t2==4)|| (t1==4 && t2==1)||(t1==4 && t2==3)){

         if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
           if(board[t3][t4]=='*') {board[t3][t4]='G';board[t1][t2]='*';g_count--;}
            else { cout<<"WRONG INDEX!!!";goat_input();}
         }
         else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){
             if(board[t3][t4]=='*') {board[t3][t4]='G';board[t1][t2]='*';g_count--;}
             else { cout<<"WRONG INDEX!!!";goat_input();}
            }

         else {cout<<"WRONG INDEX !!";goat_input();}
        }

    }



 //....................TIGERS' POSSIBLE MOVE COUNTING AND PRINTING............
 int tiger_possible_move(int m1,int m2){ 
   
     int   move_count=0;
     if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
     (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

        if(board[m1-1][m2+1]=='*'){ cout<<" "<<m1-1<<","<<m2+1;move_count++;}
        else if(board[m1-1][m2+1]=='G'){
            if(board[m1-2][m2+2]=='*') cout<<" "<<m1-2<<","<<m2+2;move_count++;}

        if(board[m1+1][m2-1]=='*'){ cout<<" "<<m1+1<<","<<m2-1;move_count++;}
        else if(board[m1+1][m2-1]=='G'){
            if(board[m1+2][m2-2]=='*') cout<<" "<<m1+2<<","<<m2-2;move_count++;}

        if(board[m1-1][m2-1]=='*'){ cout<<" "<<m1-1<<","<<m2-1;move_count++;}
        else if(board[m1-1][m2-1]=='G'){
            if(board[m1-2][m2-2]=='*') cout<<" "<<m1-2<<","<<m2-2;move_count++;}    
        
        if(board[m1+1][m2+1]=='*'){ cout<<" "<<m1+1<<","<<m2+1;move_count++;}
        else if(board[m1+1][m2+1]=='G'){
            if(board[m1+2][m2+2]=='*') cout<<" "<<m1+2<<","<<m2+2;move_count++;}

        if(board[m1-1][m2]=='*'){ cout<<" "<<m1-1<<","<<m2;move_count++;}
        else if(board[m1-1][m2]=='G'){
            if(board[m1-2][m2]=='*') cout<<" "<<m1-2<<","<<m2;move_count++;}   


        if(board[m1+1][m2]=='*'){ cout<<" "<<m1+1<<","<<m2;move_count++;}
        else if(board[m1+1][m2]=='G'){
            if(board[m1+2][m2]=='*') cout<<" "<<m1+2<<","<<m2;move_count++;}  

         if(board[m1][m2+1]=='*'){ cout<<" "<<m1<<","<<m2+1;move_count++;}
         else if(board[m1][m2+1]=='G'){
            if(board[m1][m2+2]=='*') cout<<" "<<m1<<","<<m2+2;move_count++;}      
          
        if(board[m1][m2-1]=='*'){ cout<<" "<<m1<<","<<m2-1;move_count++;}
        else if(board[m1][m2-1]=='G'){
         if(board[m1][m2-2]=='*') cout<<" "<<m1<<","<<m2-2;move_count++;} 
        
    }   


    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

                if(board[m1-1][m2]=='*'){ cout<<" "<<m1-1<<","<<m2;move_count++;}
        else if(board[m1-1][m2]=='G'){
            if(board[m1-2][m2]=='*') cout<<" "<<m1-2<<","<<m2;move_count++;}   

        if(board[m1+1][m2]=='*'){ cout<<" "<<m1+1<<","<<m2;move_count++;}
        else if(board[m1+1][m2]=='G'){
            if(board[m1+2][m2]=='*') cout<<" "<<m1+2<<","<<m2;move_count++;}  

         if(board[m1][m2+1]=='*'){ cout<<" "<<m1<<","<<m2+1;move_count++;}
         else if(board[m1][m2+1]=='G'){
            if(board[m1][m2+2]=='*') cout<<" "<<m1<<","<<m2+2;move_count++;}      
          
        if(board[m1][m2-1]=='*'){ cout<<" "<<m1<<","<<m2-1;move_count++;}
        else if(board[m1][m2-1]=='G'){
         if(board[m1][m2-2]=='*') cout<<" "<<m1<<","<<m2-2;move_count++;} 

    }
    return move_count;

  }

//..................STATUS FOR MOVING TIGER..........
   int tiger_info(){
       int temp=0;
       for(int i=0;i<5;i++){
             for(int j=0;j<5;j++){ 
                  if(board[i][j]=='T'){
                     cout<<i<<","<<j<<" TIGER CAN MOVE IN:";
                      temp=tiger_possible_move(i,j); cout<<"\n";
                      total_move=total_move + temp;
                      if(temp==0) {cout<<i<<" "<<j<<" TIGER IS IN TRAP!!"; cout<<"\n";}
                    }
                }
        }
        return total_move;
   }    

 //...............killing goat and changing the index.........
void kill_goat(){ 
     if((t1==0 && t2==0)||(t1==0 && t2==2)||(t1==0 && t2==4)||(t1==1 && t2==1)||(t1==1 && t2==3)|| (t1==2 && t2==0)||(t1==2 && t2==2)||
      (t1==2 && t2==4)||(t1==3 && t2==1)||(t1==3 && t2==3)|| (t1==4 && t2==0)||(t1==4 && t2==2)||(t1==4 && t2==4)){

        if((t1-2==t3)&&(t2==t4)){
                if(board[t1-1][t2]=='G'){
                board[t3][t4]='T'; board[t1-1][t2]='*';board[t1][t2]='*'; killed_g++;}
                else {tiger_move();}
            }

        else if((t1+2==t3)&&(t2==t4)){
            if(board[t1+1][t2]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1+1][t2]='*';killed_g++;}
            else {tiger_move();}
          }  

        else if((t1==t3)&&(t2-2==t4)){
            if(board[t1][t2-1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1][t2-1]='*';killed_g++;}
            else {tiger_move();}
          }      
        
        else if((t1==t3)&&(t2+2==t4)){
            if(board[t1][t2+1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1][t2+1]='*';killed_g++;}
            else {tiger_move();}
          }  

        else if((t1-2==t3)&&(t2-2==t4)){
            if(board[t1-1][t2-1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1-1][t2-1]='*';killed_g++;}
            else {tiger_move();}
          }   

        else if((t1+2==t3)&&(t2+2==t4)){
            if(board[t1+1][t2+1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1+1][t2+1]='*';killed_g++;}
            else {tiger_move();}
          }  
         else if((t1-2==t3)&&(t2+2==t4)){
            if(board[t1-1][t2+1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1-1][t2+1]='*';killed_g++;}
            else {tiger_move();}
          }   
       else if((t1+2==t3)&&(t2-2==t4)){
            if(board[t1+1][t2-1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1+1][t2-1]='*';killed_g++;}
            else {tiger_move();}
          }

        else   tiger_move();
        
    }   

    else if((t1==0 && t2==1)||(t1==0 && t2==3)||(t1==1 && t2==0)||(t1==1 && t2==2)||(t1==1 && t2==4)|| (t1==2 && t2==1)||(t1==2 && t2==3)||
            (t1==3 && t2==0)||(t1==3 && t2==2)||(t1==3 && t2==4)|| (t1==4 && t2==1)||(t1==4 && t2==3)){

            if((t1-2==t3)&&(t2==t4)){
              if(board[t1-1][t2]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1-1][t2]='*';killed_g++;}
              else {tiger_move();}
            }
           else  if((t1+2==t3)&&(t2==t4)){
              if(board[t1+1][t2]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1+1][t2]='*';killed_g++;}
              else {tiger_move();}
            }  
            else if((t1==t3)&&(t2-2==t4)){
              if(board[t1][t2-1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1][t2-1]='*';killed_g++;}
              else {tiger_move();}
            }      
          else if((t1==t3)&&(t2+2==t4)){
             if(board[t1][t2+1]=='G'){ board[t3][t4]='T';board[t1][t2]='*';board[t1][t2+1]='*';killed_g++;}
             else {tiger_move();}
            } 

          else tiger_move();
       }

  } 










//..............for AI METHOD............NEWLY ADDED...........



void GenerateMoveList(int & counter, Move move[])
{
    counter = 0;

    //for efficiency of ab pruning
    int replaceCounter = 0;
    int initialPossibleCaptures = PossibleCaptures();
    int tempTigerPos;
    int a;

    //for tiger
    if (aiTurn == Tiger)
    {
        //capture conditions
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int x = aiTigerPos[i];
                int y = direction[j];

                if (x+2*y > 0 && x+2*y < 26)
                {
                    if (tigerPlayer->CanCapture(board, x+2*y, x))
                    {
                        move[counter].from = x;
                        move[counter].to = x+2*y;
                        move[counter].type = TIGER_CAPTURE;
                        counter++;
                    }
                }

                if (x-2*y > 0 && x-2*y < 26)
                {
                    if (tigerPlayer->CanCapture(board, x-2*y, x))
                    {
                        move[counter].from = x;
                        move[counter].to = x-2*y;
                        move[counter].type = TIGER_CAPTURE;
                        counter++;
                    }
                }
            }
        }

        replaceCounter = counter;//to avoid replacing the capture moves.

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int x = aiTigerPos[i];
                int y = direction[j];

                if (x+y > 0 && x+y < 26)
                {
                    if (tigerPlayer->IsMovable(board, x+y, x))
                    {
                        move[counter].from = x;
                        move[counter].to = x+y;
                        move[counter].type = TIGER_MOVE;

                        //for efficiency of ab pruning
                        board->point[move[counter].to].SetState(T);
                        board->point[move[counter].from].SetState(N);

                        for (int j = 0; j < 4; j++)
                        {
                            if (aiTigerPos[j] == move[counter].from)
                            {
                                aiTigerPos[j] = move[counter].to;
                                tempTigerPos = j;
                                break;
                            }
                        }

                        a = PossibleCaptures();

                        board->point[move[counter].to].SetState(N);
                        board->point[move[counter].from].SetState(T);
                        aiTigerPos[tempTigerPos] = move[counter].from;

                        if (a > initialPossibleCaptures)
                        {
                            Move temp = move[replaceCounter];
                            move[replaceCounter] = move[counter];
                            move[counter] = temp;

                            replaceCounter++;
                        }
                        counter++;
                    }
                }

                if (x-y > 0 && x-y < 26)
                {
                    if (tigerPlayer->IsMovable(board, x-y, x))
                    {
                        move[counter].from = x;
                        move[counter].to = x-y;
                        move[counter].type = TIGER_MOVE;

                        //for efficiency of ab pruning
                        board->point[move[counter].to].SetState(T);
                        board->point[move[counter].from].SetState(N);

                        for (int j = 0; j < 4; j++)
                        {
                            if (aiTigerPos[j] == move[counter].from)
                            {
                                aiTigerPos[j] = move[counter].to;
                                tempTigerPos = j;
                                break;
                            }
                        }

                        a = PossibleCaptures();

                        board->point[move[counter].to].SetState(N);
                        board->point[move[counter].from].SetState(T);
                        aiTigerPos[tempTigerPos] = move[counter].from;

                        if (a > initialPossibleCaptures)
                        {
                            Move temp = move[replaceCounter];
                            move[replaceCounter] = move[counter];
                            move[counter] = temp;

                            replaceCounter++;
                        }
                        counter++;
                    }
                }
            }
        }
    }  

  //................GOAT WILL BE ADDED ............


}




















int TigerEvaluatePosition()
{
    if (TigerWinCheck())
        return +INF;
    if (GoatWinCheck(board))
        return -INF;

    return (1000 * aiDeadGoats - 300 * GhostGoats() + 200 * PossibleCaptures() - 500 * TigersTrapped(board) + 50 * cornersOccupied);
}

int GoatEvaluatePosition(int depth)
{
    if (TigerWinCheck())
        return -INF;
    if (GoatWinCheck(board))
        return +INF - depth;

    return -(1000 * aiDeadGoats - 300*GhostGoats() + 100 * PossibleCaptures() - 200 * TigersTrapped(board) + depth);
}

bool TigerWinCheck()
{
    if (aiDeadGoats == 5)
    {
        return true;
    }
    return false;
}

bool GoatWinCheck(Board * b)
{
    if (!tigerPlayer->CanTigersMove(aiTigerPos, b))
    {
        return true;
    }
    return false;
}




int PossibleCaptures()
{
    int possibleCaptureNumber = 0;

    //.............................
        
}


int TigersTrapped(Board * brd)
{

    //................
}

int AI::GhostGoats()
{


    //........................
}






