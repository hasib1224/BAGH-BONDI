#ifndef twoPlayerMode_h
#define twoPlayerMode_h

#include<bits/stdc++.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
using namespace std;

#include "globalVariable.h"

struct cordin{
   int x;
   int y;
};


void two_player_mode();
void cordinatew();
void board_initialize();
void welcome();
void board_view();

void goats_turn_print();
void tigers_turn_print();

int menu();

void tiger_win_screen();
void goat_win_screen();

char* numToString(int num);



#endif












