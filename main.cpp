#include<bits/stdc++.h>
using namespace std;

void tiger_input();
void goat_input();
void kill_goat(int x,int y);
void tiger_move();
void print_board();
void goat_move();


 int g1,g2,g3,g4,t1,t2,t3,t4;//Temporary_variable_for_input
  char board[50][50];
  int g_count=20;
  int t_count=5;
  int key;

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

     for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
           cout<< board[i][j]<<" ";
        }
        cout<<endl;
     }

   for(;;){
       goat_input(); 
       tiger_input();
        print_board();
        cin>>key;
        if(key==0) break;
    }


}


 void goat_input(){                              //...................GOAT_MOVE.............................
     cout<<" Index for goat move:";  

     if(g_count>0){                             //goat_move_when_some goats are still in hand
         cin>>g3>>g4;
          if(board[g3][g4] =='*'){
              board[g3][g4]='G';g_count--;}
          else { cout<<"WRONG!!! INPUT INDEX FOR GOAT MOVE\n";goat_input();}
        }

      else if(g_count==0){                       //goat_move_when_all goats are in field
         cin>>g1>>g2>>g3>>g4;
         goat_move();
        }
    }


void tiger_input(){     
    cout<<"\nInput Index for tiger move:";        //..........TIGER_MOVE.............
     cin>>t1>>t2>>t3>>t4;
     if(board[t1][t2]!='T') {cout<<"WRONGG!!";tiger_input();}
      else tiger_move();  
   }


void print_board(){                                //........PRINTING _BOARD........
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
           cout<< board[i][j]<<" ";
        }
        cout<<endl;
    }
}



void tiger_move(){
    if((t1==0 && t2==0)||(t1==0 && t2==2)||(t1==0 && t2==4)||(t1==1 && t2==1)||(t1==1 && t2==3)|| (t1==2 && t2==0)||(t1==2 && t2==2)||
    (t1==2 && t2==4)||(t1==3 && t2==1)||(t1==3 && t2==3)|| (t1==4 && t2==0)||(t1==4 && t2==2)||(t1==4 && t2==4)){

        if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
            if(board[t3][t4]=='*'){ board[t3][t4]='T';board[t1][t2]='*';}
            else if(board[t3][t4]=='T') {cout<<"WRONG INDEX !!";tiger_input();}
             else if(board[t3][t4]=='G') kill_goat(t3,t4);
             else {cout<<"WRONG INDEX !!";tiger_input();}
        }
        else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){
             if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
            else if(board[t3][t4]=='T') {cout<<"WRONG INDEX !!";tiger_input();}
             else if(board[t3][t4]=='G') kill_goat(t3,t4);
             else {cout<<"WRONG INDEX !!";tiger_input();}
        }
        else if(((t1-1==t3)&&(t2+1==t4))||((t1+1==t3)&&(t2-1==t4))){
             if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
            else if(board[t3][t4]=='T') {cout<<"WRONG INDEX !!";tiger_input();}
             else if(board[t3][t4]=='G') kill_goat(t3,t4);
             else{cout<<"WRONG INDEX !!";tiger_input();}
        }
        else if(((t1-1==t3)&&(t2-1==t4))||((t1+1==t3)&&(t2+1==t4))){
             if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
            else if(board[t3][t4]=='T') {cout<<"WRONG INDEX !!";tiger_input();}
             else if(board[t3][t4]=='G') kill_goat(t3,t4);
             else {cout<<"WRONG INDEX !!";tiger_input();}
        }
        else {cout<<"WRONG INDEX !!";tiger_input();}

    } 

    else if((t1==0 && t2==1)||(t1==0 && t2==3)||(t1==1 && t2==0)||(t1==1 && t2==2)||(t1==1 && t2==4)|| (t1==2 && t2==1)||(t1==2 && t2==3)||
            (t1==3 && t2==0)||(t1==3 && t2==2)||(t1==3 && t2==4)|| (t1==4 && t2==1)||(t1==4 && t2==3)){

        if(((t1-1==t3)&&(t2==t4))||((t1+1==t3)&&(t2==t4))){
            if(board[t3][t4]=='*'){ board[t3][t4]='T';board[t1][t2]='*';}
            else if(board[t3][t4]=='T') {cout<<"WRONG INDEX !!";tiger_input();}
             else if(board[t3][t4]=='G') kill_goat(t3,t4);
             else {cout<<"WRONG INDEX !!";tiger_input();}
        }
        else if(((t1==t3)&&(t2-1==t4))||((t1==t3)&&(t2+1==t4))){
             if(board[t3][t4]=='*') { board[t3][t4]='T';board[t1][t2]='*';}
            else if(board[t3][t4]=='T') {cout<<"WRONG INDEX !!";tiger_input();}
             else if(board[t3][t4]=='G') kill_goat(t3,t4);
             else {cout<<"WRONG INDEX !!";tiger_input();}
        }
        else {cout<<"WRONG INDEX !!";tiger_input();}

        
    }

}

void kill_goat(int x,int y){

   // ................

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










