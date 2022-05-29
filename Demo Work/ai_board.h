#ifndef ai_board_h
#define ai_board_h

#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream>
#include "board.h"

#define infinity 9999999

int g1,g2,g3,g4,t1,t2,t3,t4;  //Temporary_variable_for_input
  char ai_board[50][50];
  int g_count=20;       //GOAT NUMBER IS UP TO 20
  int ai_killed_goat=0;
  int move_from[2],move_to[2] , tiger_kill_move_flag=0 ;
  int highest_search_depth = 2;
  string ai_turn;

  enum MoveType { GOAT_PLACE, GOAT_MOVE , TIGER_MOVE, TIGERS_KILL_MOVE};

  struct Move{
      MoveType type;
      int from[2],to[2] ;
   };


#endif
