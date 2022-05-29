

#ifndef ai_board_h
#define ai_board_h

#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>
#include<windows.h>
#include<iostream>

#define infinity 9999999

enum MoveType { GOAT_PLACE, GOAT_MOVE , TIGER_MOVE, TIGERS_KILL_MOVE};

struct Move{
  MoveType type;
  int from[2],to[2] ;
};

void ai_mode();
void ai_goat();
void ai_tiger();

#endif

