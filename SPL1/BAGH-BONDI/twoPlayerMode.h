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


/*
void tiger_scope_print(int m1,int m2);
void tiger_input();
void tiger_scope();
int tiger_info();
int tiger_possible_move(int m1,int m2);


void goat_scope_print(int m1,int m2);
void goat_input_2 ();
void goat_scope();
void goat_input();

*/

int menu();

void tiger_win_screen();
void goat_win_screen();

char* numToString(int num);



#endif












