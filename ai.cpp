  
#include<bits/stdc++.h>
using namespace std;

#define infinity 9999999

void ai_tiger_input();
void  ai_tiger_move();
int tiger_possible_move(int m1,int m2);
int tiger_info();
void  ai_kill_goat();

void goat_input();
void goat_move();

void print_board();

//AI.......METHOD
int generate_move_type ( int counter, struct Move ai_move[21] );
int  ai_tiger_move_type( int row, int col, int counter, struct Move ai_move[21] );
int ai_goat_move_type(int row, int col, int counter, struct Move ai_move[21]);
int ai_goat_minimax(int depth, int alpha, int beta);

int ai_tiger_position_evaluate();
int ai_goat_position_evaluate();

void ai_tiger_move( int counter, struct Move ai_move[21]);
void reverse_ai_tiger_move( int counter, struct Move ai_move[21]);
void ai_tigers_kill_move( int counter, struct Move ai_move[21]);
void reverse_ai_tigers_kill_move(  int counter, struct Move ai_move[21] );

bool ai_tiger_win();
bool ai_goat_win();

int ghost_goats();
int possible_captures();
int trapped_tigers();

void ai_goat_place(  int counter, struct Move ai_move[21] );
void reverse_ai_goat_place( int counter, struct Move ai_move[21]);
void ai_goat_move(  int counter, struct Move ai_move[21]);
void reverse_ai_goat_move(  int counter, struct Move ai_move[21] );



int g1,g2,g3,g4,t1,t2,t3,t4;  //Temporary_variable_for_input
  char board[50][50];
  char ai_board[50][50];
  int g_count=20;       //GOAT NUMBER IS UP TO 20
  int t_count=4;        // TOTAL TIGER IS
  int total_move=0;     //TIGERS POSSIBLE MOVE NUMBER      
  int killed_g=0;       // KILLED GOAT NUMBER  
  int ai_killed_goat=0;

  int move_from[2],move_to[2] ;

  int highest_search_depth=4;

  string ai_turn;

  enum MoveType { GOAT_PLACE, GOAT_MOVE , TIGER_MOVE, TIGERS_KILL_MOVE};

  struct Move{
      MoveType type;
      int from[2],to[2] ;
   };


int main(){
    int value;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            //if( (i==3&&j==4) || (i==4&&j==0)||(i==4&&j==2)){
                ai_board[i][j]='*';
            //}
            //else ai_board[i][j]='G';
        }
    }

    ai_board[0][0]='T';
    ai_board[0][4]='T';
    ai_board[4][0]='T';
    ai_board[4][4]='T';

    
   
     for(;;){
       
        print_board();
        ai_turn="GOAT";
        
        value = ai_goat_minimax(0, -infinity, +infinity);

        if(move_from[0]==999||move_from[1]==999){
            ai_board[ move_to[0] ] [ move_to[1] ]='G';
            g_count--;
        }
        else{
            ai_board[ move_to[0] ] [ move_to[1] ]='G';
            ai_board[ move_from[0] ] [ move_from[1] ]='*';
            g_count=0;
        }
       
        if(value==infinity) {
            print_board();
            cout<<"CONGRATULATIONS!! GOAT WIN THE MATCH!!!";
            break;
        }
        else if(value==(-infinity)){
            print_board();
            cout<<"CONGRATULATIONS!! TIGER WIN THE MATCH!!!"; 
            break;
        }

        print_board();
        ai_tiger_input();
        if( ai_killed_goat==5){
            cout<<"CONGRATULATIONS!! TIGER WIN THE MATCH!!!"; 
            break;
        }
            
        // cout<<endl<<"g_count"<<g_count<<endl;
        // cout<<"ai_killed_goat"<<ai_killed_goat<<endl;
            
           
    }
       
        
        
    
        
    //break;

    



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


void ai_tiger_input(){     
    cout<<"\nInput Index for tiger move:";       
     cin>>t1>>t2>>t3>>t4;
     if(ai_board[t1][t2]!='T') {cout<<"WRONG!!"; ai_tiger_input();}
      else  ai_kill_goat();  
      
   }


void print_board(){ 

//    for(int m=0;m<5;m+=1){ cout<<"  "<<m;}
//    cout<<"\n";          
//     for(int i=0;i<5;i++){
//         cout<<i;
//         for(int j=0;j<5;j++){
//            cout<<" "<<board[i][j]<<" ";
//         }cout<<"\n"; 
//     }

for(int m=0;m<5;m+=1){ cout<<"  "<<m;}
   cout<<"\n";          
    for(int i=0;i<5;i++){
        cout<<i;
        for(int j=0;j<5;j++){
           cout<<" "<<ai_board[i][j]<<" ";
        }cout<<"\n"; 
    }
    
}


void  ai_tiger_move(){
      if((t1==0 && t2==0)||(t1==0 && t2==2)||(t1==0 && t2==4)||(t1==1 && t2==1)||(t1==1 && t2==3)|| (t1==2 && t2==0)||(t1==2 && t2==2)||
      (t1==2 && t2==4)||(t1==3 && t2==1)||(t1==3 && t2==3)|| (t1==4 && t2==0)||(t1==4 && t2==2)||(t1==4 && t2==4)){

           if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
                if( ai_board[t3][t4]=='*'){  ai_board[t3][t4]='T'; ai_board[t1][t2]='*';}
                else {cout<<"WRONG INDEX !!"; ai_tiger_input();}
            }
            
            else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){
              if( ai_board[t3][t4]=='*') {  ai_board[t3][t4]='T'; ai_board[t1][t2]='*';}
                else {cout<<"WRONG INDEX !!"; ai_tiger_input();}
            }

            else if(((t1-1==t3)&&(t2+1==t4))||((t1+1==t3)&&(t2-1==t4))){
             if( ai_board[t3][t4]=='*') {  ai_board[t3][t4]='T'; ai_board[t1][t2]='*';}
             else{cout<<"WRONG INDEX !!"; ai_tiger_input();}
            }

            else if(((t1-1==t3)&&(t2-1==t4))||((t1+1==t3)&&(t2+1==t4))){
             if( ai_board[t3][t4]=='*') {  ai_board[t3][t4]='T'; ai_board[t1][t2]='*';}
             else {cout<<"WRONG INDEX !!"; ai_tiger_input();}
            }

           else {cout<<"WRONG INDEX !!"; ai_tiger_input();}

        } 


     else if((t1==0 && t2==1)||(t1==0 && t2==3)||(t1==1 && t2==0)||(t1==1 && t2==2)||(t1==1 && t2==4)|| (t1==2 && t2==1)||(t1==2 && t2==3)||
            (t1==3 && t2==0)||(t1==3 && t2==2)||(t1==3 && t2==4)|| (t1==4 && t2==1)||(t1==4 && t2==3)){

                if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
                  if( ai_board[t3][t4]=='*'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*';}
                    else {cout<<"WRONG INDEX !!"; ai_tiger_input();}
                }

               else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){

                    cout<<"dhukse in ai t move"<<ai_board[t3][t4];

                    if( ai_board[t3][t4]=='*') { ai_board[t3][t4]='T'; ai_board[t1][t2]='*';}
                    else {cout<<"WRONG INDEX !!"; ai_tiger_input();}
                }

                else {cout<<"WRONG INDEX !!"; ai_tiger_input();}
   
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
void  ai_kill_goat(){ 
     if((t1==0 && t2==0)||(t1==0 && t2==2)||(t1==0 && t2==4)||(t1==1 && t2==1)||(t1==1 && t2==3)|| (t1==2 && t2==0)||(t1==2 && t2==2)||
      (t1==2 && t2==4)||(t1==3 && t2==1)||(t1==3 && t2==3)|| (t1==4 && t2==0)||(t1==4 && t2==2)||(t1==4 && t2==4)){

        if((t1-2==t3)&&(t2==t4)){
                if(ai_board[t1-1][t2]=='G'){
                ai_board[t3][t4]='T'; ai_board[t1-1][t2]='*'; ai_board[t1][t2]='*'; ai_killed_goat++;}
                else { ai_tiger_move();}
            }

        else if((t1+2==t3)&&(t2==t4)){
            if(ai_board[t1+1][t2]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*';ai_board[t1+1][t2]='*'; ai_killed_goat++;}
            else { ai_tiger_move();}
          }  

        else if((t1==t3)&&(t2-2==t4)){
            if(ai_board[t1][t2-1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1][t2-1]='*'; ai_killed_goat++;}
            else { ai_tiger_move();}
          }      
        
        else if((t1==t3)&&(t2+2==t4)){
            if(ai_board[t1][t2+1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1][t2+1]='*'; ai_killed_goat++;}
            else { ai_tiger_move();}
          }  

        else if((t1-2==t3)&&(t2-2==t4)){
            if(ai_board[t1-1][t2-1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1-1][t2-1]='*'; ai_killed_goat++;}
            else { ai_tiger_move();}
          }   

        else if((t1+2==t3)&&(t2+2==t4)){
            if(ai_board[t1+1][t2+1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1+1][t2+1]='*'; ai_killed_goat++;}
            else { ai_tiger_move();}
          }  
         else if((t1-2==t3)&&(t2+2==t4)){
            if(ai_board[t1-1][t2+1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1-1][t2+1]='*'; ai_killed_goat++;}
            else { ai_tiger_move();}
          }   
       else if((t1+2==t3)&&(t2-2==t4)){
            if(ai_board[t1+1][t2-1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1+1][t2-1]='*'; ai_killed_goat++;}
            else { ai_tiger_move();}
          }

        else    ai_tiger_move();
        
    }   

    else if((t1==0 && t2==1)||(t1==0 && t2==3)||(t1==1 && t2==0)||(t1==1 && t2==2)||(t1==1 && t2==4)|| (t1==2 && t2==1)||(t1==2 && t2==3)||
            (t1==3 && t2==0)||(t1==3 && t2==2)||(t1==3 && t2==4)|| (t1==4 && t2==1)||(t1==4 && t2==3)){

            if((t1-2==t3)&&(t2==t4)){
              if(ai_board[t1-1][t2]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1-1][t2]='*'; ai_killed_goat++;}
              else { ai_tiger_move();}
            }
           else  if((t1+2==t3)&&(t2==t4)){
              if(ai_board[t1+1][t2]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1+1][t2]='*'; ai_killed_goat++;}
              else { ai_tiger_move();}
            }  
            else if((t1==t3)&&(t2-2==t4)){
              if(ai_board[t1][t2-1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1][t2-1]='*'; ai_killed_goat++;}
              else { ai_tiger_move();}
            }      
          else if((t1==t3)&&(t2+2==t4)){
             if(ai_board[t1][t2+1]=='G'){ ai_board[t3][t4]='T'; ai_board[t1][t2]='*'; ai_board[t1][t2+1]='*'; ai_killed_goat++;}
             else { ai_tiger_move();}
            } 

          else  ai_tiger_move();
        }

  } 




//.......................AIiiiiiiiiiiiiii..................


int generate_move_type ( int counter, struct Move ai_move[21] ){


    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         ai_board[i][j]=board[i][j];
    //     }
    // }

    if(ai_turn=="TIGER"){

        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(ai_board[i][j]=='T'){
                    counter = ai_tiger_move_type( i, j, counter , ai_move);
                }
            }
        }
    }

    else if(ai_turn=="GOAT"){

        if(g_count>0){

            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(ai_board[i][j]=='*'){

                        ai_move[counter].type=GOAT_PLACE; 
                
                        ai_move[counter].to[0]=i; ai_move[counter].to[1]=j;
                        
                        counter++;

                    }
                }
            }
        }

        else if(g_count==0){

            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(ai_board[i][j]=='G'){

                        counter = ai_goat_move_type( i, j, counter ,ai_move);

                    }
                }
            }
        }
 

    }

    return counter;

}

int  ai_tiger_move_type( int row, int col, int counter, struct Move ai_move[21] ){ 
    int  m1=row;
    int m2=col;

    int   move_count=0;
    if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
    (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

        if( ai_board[m1-1][m2+1]=='*'){
            ai_move[counter].type= TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2+1;
            counter++;
        }
        else if( ai_board[m1-1][m2+1]=='G' && ai_board[m1-2][m2+2]=='*'){
            ai_move[counter].type= TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2+2;
            counter++;            

        }

        if( ai_board[m1+1][m2-1]=='*'){ 
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2-1;
            counter++;
        }
        else if( ai_board[m1+1][m2-1]=='G' && ai_board[m1+2][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2-2;
            counter++;

        }

        if( ai_board[m1-1][m2-1]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2-1;
            counter++;
           

            
        }
        else if( ai_board[m1-1][m2-1]=='G' && ai_board[m1-2][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2-2;
            counter++;
           

        }    
        
        if( ai_board[m1+1][m2+1]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2+1;
            counter++;
           
        }
        else if( ai_board[m1+1][m2+1]=='G' && ai_board [m1+2][m2+2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2+2;
            counter++;
            

        }

        if( ai_board[m1-1][m2]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;
            

        }
        else if( ai_board[m1-1][m2]=='G' &&  ai_board[m1-2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2;
            counter++;
            

        }   
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;
             

        }
        else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2;
            counter++;
            

        }  
        if( ai_board[m1][m2+1]=='*'){ 
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;
            
        }
        else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+2;
            counter++;
            

        }        
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;
           

        }
        else if( ai_board[m1][m2-1]=='G' && ai_board[m1][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-2;
            counter++;
            
        } 

        
    }   
    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

        if( ai_board[m1-1][m2]=='*'){ 
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;    
        }
        else if( ai_board[m1-1][m2]=='G' && ai_board[m1-2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-2; ai_move[counter].to[1]=m2;
            counter++;

        }   
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;
        }
        else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+2; ai_move[counter].to[1]=m2;
            counter++;
           
        }  

        if( ai_board[m1][m2+1]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;

        }
        else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+2;
            counter++;

        }        
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=TIGER_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;
            
        }
        else if( ai_board[m1][m2-1]=='G' &&  ai_board[m1][m2-2]=='*'){
            ai_move[counter].type=TIGERS_KILL_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-2;
            counter++;
              
        } 

    }

    return counter;

  }

int ai_goat_move_type(int row, int col, int counter, struct Move ai_move[21]){


    int  m1=row;
    int m2=col;

    int   move_count=0;
    if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
    (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

        if( ai_board[m1-1][m2+1]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2+1;
            counter++;
        }
       

        if( ai_board[m1+1][m2-1]=='*'){ 
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2-1;
            counter++;
        }
        

        if( ai_board[m1-1][m2-1]=='*'){
            ai_move[counter].type=GOAT_MOVE;
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2-1;
            counter++;
           

            
        }
        
        if( ai_board[m1+1][m2+1]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2+1;
            counter++;
           
        }
        
        if( ai_board[m1-1][m2]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;
            

        }
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;
             

        }
        if( ai_board[m1][m2+1]=='*'){ 
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;
            
        }
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;
           

        }
        
    }  

    else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
            (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

        if( ai_board[m1-1][m2]=='*'){ 
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1-1; ai_move[counter].to[1]=m2;
            counter++;    
        }
        if( ai_board[m1+1][m2]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1+1; ai_move[counter].to[1]=m2;
            counter++;
        }
        
        if( ai_board[m1][m2+1]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2+1;
            counter++;

        }
        if( ai_board[m1][m2-1]=='*'){
            ai_move[counter].type=GOAT_MOVE; 
            ai_move[counter].from[0]=m1; ai_move[counter].from[1]=m2;
            ai_move[counter].to[0]=m1; ai_move[counter].to[1]=m2-1;
            counter++;
            
        }

    }

    return counter;

  

}




int ai_goat_minimax(int depth, int alpha, int beta){
  

    
   
    int stat_value = ai_goat_position_evaluate();
    // cout<<stat_value;

    if(depth == highest_search_depth || stat_value == infinity || stat_value == (-infinity)){ 
       // cout<< stat_value ;
        return stat_value ;
    }
      

   
    

    int counter=0;
    struct Move ai_move[21];
    counter = generate_move_type ( counter, ai_move); 
    
    
    

    int val;

    for(int i=0; i<counter;i++){

       //cout<<"minmax"<<counter<<" "<<i<<" "<<ai_move[i].type<<" ";
        
       switch (ai_move[i].type){
            case TIGER_MOVE:
           
                ai_tiger_move( i,  ai_move );
                
               val = ai_goat_minimax( depth+1, alpha, beta);  

                if (val < beta){
                    beta = val;
                }
                reverse_ai_tiger_move(i,  ai_move);
                if (alpha >= beta){
                    return beta;
                }
            break;


            case TIGERS_KILL_MOVE:
                ai_tigers_kill_move( i,  ai_move);
                val=ai_goat_minimax( depth+1 ,  alpha,  beta);
                if (val < beta){
                    beta = val;
                }
                reverse_ai_tigers_kill_move(i,  ai_move);
                if (alpha >= beta){
                    return beta;
                }

            break;

            case GOAT_MOVE:
                ai_goat_move(i, ai_move);
                val=ai_goat_minimax(depth+1, alpha, beta);
                
                if (val > alpha){
                    alpha = val;
                    if (depth == 0){
                        move_from[0] = ai_move[i].from[0]; 
                        move_from[1] = ai_move[i].from[1];

                        move_to[0] = ai_move[i].to[0]; 
                        move_to[1] = ai_move[i].to[1];
                    }
                }
                reverse_ai_goat_move(i, ai_move);

                if (alpha >= beta){
                    return alpha;
                }

            break;

            case  GOAT_PLACE:
                ai_goat_place(  i ,ai_move );
                
                val = ai_goat_minimax(depth+1, alpha, beta);
                 
                if (val > alpha){
                    alpha = val;
                    if (depth == 0){
                        move_from[0] = 999 ;
                        move_from[1] = 999 ;

                        move_to[0] = ai_move[i].to[0]; 
                        move_to[1] = ai_move[i].to[1];
                    }
                }

                reverse_ai_goat_place(i, ai_move);
                if (alpha >= beta){
                    return alpha;
                }
            
            break;

        }
    
    }
   

    

    if (ai_turn=="GOAT")
        return alpha;

    else return beta;

}




int ai_tiger_position_evaluate(){ 
    
    if (ai_tiger_win())
        return +infinity;
    if (ai_goat_win( ))
        return -infinity;

    return (1000 * ai_killed_goat - 300 * ghost_goats() + 200 * possible_captures() - 500 * trapped_tigers() );

}

int ai_goat_position_evaluate(){ 
    
    if (ai_tiger_win())
        return -infinity;

    if (ai_goat_win(  )){
       
        return +infinity;
    }

    return (-1000 * ai_killed_goat + 300 * ghost_goats() - 200 * possible_captures() + 500 * trapped_tigers());
    //cout<<"dhukse";
}





void ai_tiger_move(  int counter, struct Move ai_move[21]){

    ai_board [ai_move[counter].to[0]] [ai_move[counter].to[1]] = 'T';
    ai_board [ai_move[counter].from[0]] [ai_move[counter].from[1]] = '*';
    ai_turn = "GOAT";
    

}

void reverse_ai_tiger_move( int counter, struct Move ai_move[21]){

    ai_board [ai_move[counter].to[0]] [ai_move[counter].to[1]] = '*';
    ai_board [ai_move[counter].from[0]] [ai_move[counter].from[1]] = 'T';
    ai_turn="TIGER";

}


void ai_tigers_kill_move( int counter, struct Move ai_move[21]){

    int temp1, temp2;

    temp1 = (ai_move[counter].to[0] + ai_move[counter].from[0] )/2;
    temp2 = (ai_move[counter].to[1] + ai_move[counter].from[1] )/2;


    ai_board [ ai_move[counter].to[0] ] [ ai_move[counter].to[1] ] = 'T' ;

    ai_board [ ai_move[counter].from[0] ] [ ai_move[counter].from[1] ] = '*' ;

    ai_board [temp1] [temp2] = '*' ;    // replacing dead goat position by "*"

    ai_killed_goat++;
    ai_turn="GOAT";

}

void reverse_ai_tigers_kill_move(  int counter, struct Move ai_move[21] ){

    int temp1, temp2;
    temp1 = (ai_move[counter].to[0] + ai_move[counter].from[0] )/2;
    temp2 = (ai_move[counter].to[1] + ai_move[counter].from[1] )/2;

    ai_board [ ai_move[counter].to[0] ] [ ai_move[counter].to[1] ] = '*' ;
    ai_board [ ai_move[counter].from[0] ] [ ai_move[counter].from[1] ] = 'T' ;
    ai_board [temp1] [temp2] = 'G' ;    // reversing dead goat position by "G"

    ai_killed_goat--;
    ai_turn="TIGER";

}




bool ai_tiger_win(){
    if(ai_killed_goat==5){
        return true;
    }
    else {return false; }

}

bool ai_goat_win(){

    if( trapped_tigers()==4){ 
        return true;
    }
    else return false;

            


}



int ghost_goats(){
    int ghost_goats=0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(ai_board[i][j]=='T'){

                if((i==0 && j==0)||(i==0 && j==2)||(i==0 && j==4)||(i==1 && j==1)||(i==1 && j==3)|| (i==2 && j==0)||(i==2 && j==2)||
                 (i==2 && j==4)||(i==3 && j==1)||(i==3 && j==3)|| (i==4 && j==0)||(i==4 && j==2)||(i==4 && j==4)){

        
                    if(ai_board[i-1][j+1]=='G' && ai_board[i-2][j+2]=='G'){
                        ghost_goats++;
                    }

                    if(ai_board[i+1][j-1]=='G' && ai_board[i+2][j-2]=='G'){
                        ghost_goats++;
                    }

        
                    if(ai_board[i-1][j-1]=='G' && ai_board[i-2][j-2]=='G'){
                        ghost_goats++;
                    }    
        
        
                    if(ai_board[i+1][j+1]=='G' && ai_board[i+2][j+2]=='G'){
                      ghost_goats++;
                    }

        
                    if(ai_board[i-1][j]=='G' && ai_board[i-2][j]=='G'){
                        ghost_goats++;
                    }   


                    if(ai_board[i+1][j]=='G' && ai_board[i+2][j]=='G'){
                     ghost_goats++;
                    }  

    
                    if(ai_board[i][j+1]=='G' && board[i][j+2]=='G'){
                     ghost_goats++;
                    }      
          
                    if(ai_board[i][j-1]=='G' && ai_board[i][j-2]=='G' ){
                        ghost_goats++;
                    } 
        
                }   

                else if((i==0 && j==1)||(i==0 && j==3)||(i==1 && j==0)||(i==1 && j==2)||(i==1 && j==4)|| (i==2 && j==1)||(i==2 && j==3)||
                    (i==3 && j==0)||(i==3 && j==2)||(i==3 && j==4)|| (i==4 && j==1)||(i==4 && j==3)){
    
                    if(board[i-1][j]=='G' && board[i-2][j]=='G'){
                        ghost_goats++;
                    }  

                    if(board[i+1][j]=='G' && board[i+2][j]=='G' ){
                        ghost_goats++;
                    }  


                    if(board[i][j+1]=='G' && board[i][j+2]=='G'){
                      ghost_goats++;
                    }      
          
                    if(board[i][j-1]=='G' && board[i][j-2]=='G'){
                        ghost_goats++;
                    } 

                }

            }
        }
    }

    return ghost_goats;

}


int possible_captures(){
    int possible_captures=0;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(ai_board[i][j]=='T'){

                if((i==0 && j==0)||(i==0 && j==2)||(i==0 && j==4)||(i==1 && j==1)||(i==1 && j==3)|| (i==2 && j==0)||(i==2 && j==2)||
                 (i==2 && j==4)||(i==3 && j==1)||(i==3 && j==3)|| (i==4 && j==0)||(i==4 && j==2)||(i==4 && j==4)){

        
                    if(ai_board[i-1][j+1]=='G' && ai_board[i-2][j+2]=='*'){
                        possible_captures++;
                    }

                    if(ai_board[i+1][j-1]=='G' && ai_board[i+2][j-2]=='*'){
                        possible_captures++;
                    }

        
                    if(ai_board[i-1][j-1]=='G' && ai_board[i-2][j-2]=='*'){
                        possible_captures++;
                    }    
        
        
                    if(ai_board[i+1][j+1]=='G' && ai_board[i+2][j+2]=='*'){
                      possible_captures++;
                    }

        
                    if(ai_board[i-1][j]=='G' && ai_board[i-2][j]=='*'){
                        possible_captures++;
                    }   


                    if(ai_board[i+1][j]=='G' && ai_board[i+2][j]=='*'){
                     possible_captures++;
                    }  

    
                    if(ai_board[i][j+1]=='G' && board[i][j+2]=='*'){
                     possible_captures++;
                    }      
          
                    if(ai_board[i][j-1]=='G' && ai_board[i][j-2]=='*' ){
                        possible_captures++;
                    } 
        
                }   

                else if((i==0 && j==1)||(i==0 && j==3)||(i==1 && j==0)||(i==1 && j==2)||(i==1 && j==4)|| (i==2 && j==1)||(i==2 && j==3)||
                    (i==3 && j==0)||(i==3 && j==2)||(i==3 && j==4)|| (i==4 && j==1)||(i==4 && j==3)){
    
                    if(board[i-1][j]=='G' && board[i-2][j]=='*'){
                       possible_captures++;
                    }  

                    if(board[i+1][j]=='G' && board[i+2][j]=='*' ){
                        possible_captures++;
                    }  


                    if(board[i][j+1]=='G' && board[i][j+2]=='*'){
                      possible_captures++;
                    }      
          
                    if(board[i][j-1]=='G' && board[i][j-2]=='*'){
                       possible_captures++;
                    } 

                }

            }
        }
    }

    return possible_captures;

}


int trapped_tigers(){
    int trapped_tiger_num=0;
    int move_counter=0;

    for(int m1=0;m1<5;m1++){
        for(int m2=0;m2<5;m2++){
           if(ai_board[m1][m2]=='T'){
                move_counter=0;


             if((m1==0 && m2==0)||(m1==0 && m2==2)||(m1==0 && m2==4)||(m1==1 && m2==1)||(m1==1 && m2==3)|| (m1==2 && m2==0)||(m1==2 && m2==2)||
                 (m1==2 && m2==4)||(m1==3 && m2==1)||(m1==3 && m2==3)|| (m1==4 && m2==0)||(m1==4 && m2==2)||(m1==4 && m2==4)){

                    

                    if( ai_board[m1-1][m2+1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1-1][m2+1]=='G' && ai_board[m1-2][m2+2]=='*'){
                        move_counter++;            
                    }

                    if( ai_board[m1+1][m2-1]=='*'){ 
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2-1]=='G' && ai_board[m1+2][m2-2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1-1][m2-1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1-1][m2-1]=='G' && ai_board[m1-2][m2-2]=='*'){
                        move_counter++;
                    }    
        
                    if( ai_board[m1+1][m2+1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2+1]=='G' && ai_board [m1+2][m2+2]=='*'){
                        move_counter++;
                    }

                    if( ai_board[m1-1][m2]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1-1][m2]=='G' &&  ai_board[m1-2][m2]=='*'){
                        move_counter++;
                    }   
                    if( ai_board[m1+1][m2]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
                        move_counter++;
                    }  
                    if( ai_board[m1][m2+1]=='*'){ 
                        move_counter++;
                    }
                    else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
                        move_counter++;
                    }        
                    if( ai_board[m1][m2-1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1][m2-1]=='G' && ai_board[m1][m2-2]=='*'){
                        move_counter++;
                    } 

        
                } 

             else if((m1==0 && m2==1)||(m1==0 && m2==3)||(m1==1 && m2==0)||(m1==1 && m2==2)||(m1==1 && m2==4)|| (m1==2 && m2==1)||(m1==2 && m2==3)||
                    (m1==3 && m2==0)||(m1==3 && m2==2)||(m1==3 && m2==4)|| (m1==4 && m2==1)||(m1==4 && m2==3)){

                    if( ai_board[m1-1][m2]=='*'){ 
                        move_counter++;   
                    }
                    else if( ai_board[m1-1][m2]=='G' && ai_board[m1-2][m2]=='*'){
                        move_counter++;
                    }  

                    if( ai_board[m1+1][m2]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1+1][m2]=='G' && ai_board[m1+2][m2]=='*'){
                        move_counter++;
                    }  

                    if( ai_board[m1][m2+1]=='*'){
                       move_counter++;
                    }
                    else if( ai_board[m1][m2+1]=='G' && ai_board[m1][m2+2]=='*'){
                        move_counter++;
                    }  

                    if( ai_board[m1][m2-1]=='*'){
                        move_counter++;
                    }
                    else if( ai_board[m1][m2-1]=='G' &&  ai_board[m1][m2-2]=='*'){
                        move_counter++;
                    } 

                }

                if(move_counter==0){
                    trapped_tiger_num++;
                }

            }
        }

    }
    return trapped_tiger_num;

}





void ai_goat_place(  int counter, struct Move ai_move[21] ){
     
    ai_board[ ai_move[counter].to[0] ] [ ai_move[counter].to[1] ]='G';
    ai_turn = "TIGER";
   
}

void reverse_ai_goat_place( int counter, struct Move ai_move[21]){

    ai_board[ai_move[counter].to[0] ] [ai_move[counter].to[1] ]= '*';
    ai_turn = "GOAT";

}


void ai_goat_move(  int counter, struct Move ai_move[21]){

    ai_board [ai_move[counter].to[0]] [ai_move[counter].to[1]] = 'G';
    ai_board [ai_move[counter].from[0]] [ai_move[counter].from[1]] = '*';
    ai_turn="TIGER";

}

void reverse_ai_goat_move(  int counter, struct Move ai_move[21] ){

    ai_board [ ai_move[counter].to[0]   ] [ ai_move[counter].to[1] ] = '*';
    ai_board [ ai_move[counter].from[0] ] [ ai_move[counter].from[1] ] = 'G';
    ai_turn="GOAT";

}

