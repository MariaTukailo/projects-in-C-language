#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include"Checking.h"
#include"Graphic_elements.h"



void  Menu_game_mode_selection(int position) {

    system("cls");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        WORD savedAttributes = csbi.wAttributes;

        printf("______________________________\n");
        printf("|   \x1b[32m      ¬€¡Œ– –≈∆»Ã¿       \x1b[0m|\n");
        printf("|____________________________|\n");


        if (position == 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|        »√–¿ Õ¿ ƒ¬Œ»’       |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|        »√–¿ Õ¿ ƒ¬Œ»’       |\n");
        }
        if (position == 2) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|        »√–¿ — ¡Œ“ŒÃ        |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|        »√–¿ — ¡Œ“ŒÃ        |\n");
        }

        printf("|____________________________|\n");

        printf("\n\n*ÔÂÂ‰‚ËÊÂÌËÂ ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÒÚÂÎÍ‡ÏË \n");
        printf("*‚˚·Ó ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÍÌÓÔÍÓÈ ENTER \n");

    }
    else {

        printf("\n\x1b[31mÓ¯Ë·Í‡: Õ≈¬Œ«ÃŒ∆ÕŒ œŒÀ”◊»“‹ »Õ‘Œ–Ã¿÷»ﬁ Œ  ŒÕ—ŒÀ» \x1b[0m");

    }



}

int Game_mode_selection() {


    int position = 1;
    int signal;
    Menu_game_mode_selection(position);

    while (1) {

        signal = _getch();

        if (signal == 72) {
            Beep(300, 300);
            position--;
            if (position < 1) {
                position = 2;
            }
            Menu_game_mode_selection(position);
        }
        else if (signal == 80) {
            Beep(300, 300);
            position++;
            if (position > 2) {
                position = 1;
            }
            Menu_game_mode_selection(position);
        }
        else if (signal == 13) {
            if (position == 1) {
                return 1;
            }
            else {
                return 2;
            }

        }



    }



}


void Assigning_a_movePRIORITY1(int priority, int* mov, int* MOV) {

    if (priority == 1) {
        *mov = 1;
        *MOV = 3;
    }
    else {
        *mov = 2;
        *MOV = 4;
    }

}

void Assigning_a_movePRIORITY2(int priority, int* mov, int* MOV) {

    if (priority == 2) {
        *mov = 1;
        *MOV = 3;
    }
    else {
        *mov = 2;
        *MOV = 4;
    }

}


int It_a_free_movePLAYER(int i, int j, int playing_field[][8], int* blocking_counter) {

    if (i > 0 && j < 7 && playing_field[i - 1][j + 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i > 0 && j > 0 && playing_field[i - 1][j - 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i > 0 && j < 7 && (playing_field[i - 1][j + 1] == 1 || playing_field[i - 1][j + 1] == 3) && (i - 2 >= 0 && j + 2 <= 7 && playing_field[i - 2][j + 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i > 0 && j > 0 && (playing_field[i - 1][j - 1] == 1 || playing_field[i - 1][j - 1] == 3) && (i - 1 > 0 && j - 1 > 0 && playing_field[i - 2][j - 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else {
        (*blocking_counter)++;
        return 0;
    }
}

int Is_an_opportunity_to_shoot_down_the_right_and_leftPLAYER(int i, int j, int playing_field[][8], int priority) {
    int mov, MOV;
    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if ((i != 0 && i != 1) && (j != 0 && j != 1 && j != 7 && j != 6) && (playing_field[i - 1][j - 1] == mov || playing_field[i - 1][j - 1] == MOV) && playing_field[i - 2][j - 2] == 0 && (playing_field[i - 1][j + 1] == mov || playing_field[i - 1][j + 1] == MOV) && (playing_field[i - 2][j + 2] == 0))
    {
        return 1;
    }
    return 0;

}

void Performing_a_bottom_take(int *i,int *j,int playing_field[][8],int left,int priority) {
   
    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);

    
    if (left) {
        if (playing_field[*i][*j] == MOV) {
            playing_field[*i - 2][*j - 2] = MOV;
        }
        else {
            playing_field[*i - 2][*j - 2] = mov;
        }

        playing_field[*i - 1][*j - 1] = 0;
        playing_field[*i][*j] = 0;

        if (*i - 2 == 0 && priority == 2) {
            playing_field[*i - 2][*j - 2] = 4;

        }
       ( *j) -= 2;
    }
    else {
        if (playing_field[*i][*j] == MOV) {
            playing_field[*i - 2][*j + 2] = MOV;
        }
        else {
            playing_field[*i - 2][*j + 2] = mov;
        }

        playing_field[*i - 1][*j + 1] = 0;
        playing_field[*i][*j] = 0;

        if (*i - 2 == 0 && priority == 2) {
            playing_field[*i - 2][*j + 2] = 4;

        }
        (*j)+=  2;
    }
    (*i)-= 2;



}

void Taking_checkers_and_checking_moves(int i, int j, int playing_field[][8], int* number_of_opponent_checkers, int left, char* name_player, int point, int priority, int* number_of_your_checkers) {

    if (priority == 1) {
        (*number_of_your_checkers)--;
    }
    else {
        (*number_of_opponent_checkers)--;

    }

    Performing_a_bottom_take(&i, &j, playing_field,left, priority);
    int mov, MOV;
    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if (Is_an_opportunity_to_shoot_down_the_right_and_leftPLAYER(i, j, playing_field, priority)) {
        while (1) {
            Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
            int direction = _getch();
            if (direction == 75) {


                Taking_checkers_and_checking_moves(i, j, playing_field, number_of_opponent_checkers, 1, name_player, point, priority, number_of_your_checkers);
                break;
            }
            else if (direction == 77) {
                Taking_checkers_and_checking_moves(i, j, playing_field, number_of_opponent_checkers, 0, name_player, point, priority, number_of_your_checkers);

                break;
            }

        }
    }
    else if ((i != 0 && i != 1) && (j != 0 && j != 1) && (playing_field[i - 1][j - 1] == mov || playing_field[i - 1][j - 1] == MOV) && (playing_field[i - 2][j - 2] == 0)) {
        Taking_checkers_and_checking_moves(i, j, playing_field, number_of_opponent_checkers, 1, name_player, point, priority, number_of_your_checkers);
    }
    else if ((i != 0 && i != 1) && (j != 7 && j != 6) && (playing_field[i - 1][j + 1] == mov || playing_field[i - 1][j + 1] == MOV) && (playing_field[i - 2][j + 2] == 0)) {
        Taking_checkers_and_checking_moves(i, j, playing_field, number_of_opponent_checkers, 0, name_player, point, priority, number_of_your_checkers);
    }



}

int An_impossible_left_move_for_a_player(int i, int j, int playing_field[][8], int priority) {

    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);


    if (j == 0) {
        return 1;
    }
    else if ((playing_field[i - 1][j - 1] == mov || playing_field[i - 1][j - 1] == MOV) && (playing_field[i - 2][j - 2] == mov || playing_field[i - 2][j - 2] == MOV))
    {
        return 1;
    }
    else if ((playing_field[i - 1][j - 1] == mov || playing_field[i - 1][j - 1] == MOV) && j - 1 == 0) {
        return 1;

    }
    return 0;
}

int An_impossible_right_move_for_a_player(int i, int j, int playing_field[][8], int priority) {

    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);


    if (j == 7) {
        return 1;
    }
    else if ((playing_field[i - 1][j + 1] == mov || playing_field[i - 1][j + 1] == MOV) && (playing_field[i + 2][j + 2] == mov || playing_field[i + 2][j + 2] == MOV))
    {
        return 1;
    }
    else if ((playing_field[i - 1][j + 1] == mov || playing_field[i - 1][j + 1] == MOV) && j + 1 == 7) {
        return 1;

    }
    return 0;
}


int An_impossible_left_move_for_a_friend(int i, int j, int playing_field[][8], int priority) {

    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);


    if (j == 0) {
        return 1;
    }
    else if ((playing_field[i + 1][j - 1] == mov || playing_field[i + 1][j - 1] == MOV) && (playing_field[i + 2][j - 2] == mov || playing_field[i + 2][j - 2] == MOV))
    {
        return 1;
    }
    else if ((playing_field[i + 1][j - 1] == mov || playing_field[i + 1][j - 1] == MOV) && j - 1 == 0) {
        return 1;

    }
    return 0;
}

int An_impossible_right_move_for_a_friend(int i, int j, int playing_field[][8], int priority) {

    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);


    if (j == 7) {
        return 1;
    }
    else if ((playing_field[i + 1][j + 1] == mov || playing_field[i + 1][j + 1] == MOV) && (playing_field[i + 2][j + 2] == mov || playing_field[i + 2][j + 2] == MOV))
    {
        return 1;
    }
    else if ((playing_field[i + 1][j + 1] == mov || playing_field[i + 1][j + 1] == MOV) && j + 1 == 7) {
        return 1;

    }
    return 0;
}






void Move_to_the_leftPLAYER(int i, int j, int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int flag) {

    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);

    if (An_impossible_left_move_for_a_player(i, j, playing_field, priority)) {
        printf("\n\t\x1b[31m Õ≈¬Œ«ÃŒ∆ÕŒ —Œ¬≈–ÿ»“‹ ’Œƒ! \x1b[0m");
        Sleep(750);
        return;

    }
    else if (playing_field[i - 1][j - 1] == 0) {
        if (playing_field[i][j] == MOV) {
            playing_field[i - 1][j - 1] = MOV;
        }
        else {
            playing_field[i - 1][j - 1] = mov;
        }
        playing_field[i][j] = 0;


        if (i - 1 == 0 && priority == 2) {
            playing_field[i - 1][j - 1] = MOV;
        }
        return;
    }

    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if ((playing_field[i - 1][j - 1] == mov || playing_field[i - 1][j - 1] == MOV) && playing_field[i - 2][j - 2] == 0) {
        Taking_checkers_and_checking_moves(i, j, playing_field, number_of_opponent_checkers, 1, name_player, point, priority, number_of_your_checkers);
    }



}

void Move_to_the_rightPLAYER(int i, int j, int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int flag) {

    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);


    if (An_impossible_right_move_for_a_player(i, j, playing_field, priority)) {
        printf("\n\t\x1b[31m Õ≈¬Œ«ÃŒ∆ÕŒ —Œ¬≈–ÿ»“‹ ’Œƒ! \x1b[0m");
        Sleep(750);
        return;
    }
    else if (playing_field[i - 1][j + 1] == 0) {
        if (playing_field[i][j] == MOV) {
            playing_field[i - 1][j + 1] = MOV;
        }
        else {
            playing_field[i - 1][j + 1] = mov;
        }
        playing_field[i][j] = 0;

        if (priority == 2 && i - 1 == 0) {
            playing_field[i - 1][j + 1] = 4;
        }
        return;
    }
    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if ((playing_field[i - 1][j + 1] == mov || playing_field[i - 1][j + 1] == MOV) && playing_field[i - 2][j + 2] == 0) {
        Taking_checkers_and_checking_moves(i, j, playing_field, number_of_opponent_checkers, 0, name_player, point, priority, number_of_your_checkers);
    }

}


int It_a_free_moveFRIEND(int i, int j, int playing_field[][8], int* blocking_counter) {

    if (i < 7 && j < 7 && playing_field[i + 1][j + 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i < 7 && j > 0 && playing_field[i + 1][j - 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i < 7 && j < 7 && (playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4) && (i + 2 <= 7 && j + 2 <= 7 && playing_field[i + 2][j + 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i < 7 && j >0 && (playing_field[i + 1][j - 1] == 2 || playing_field[i + 1][j - 1] == 4) && (i + 1 < 7 && j - 1 > 0 && playing_field[i + 2][j - 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else {
        (*blocking_counter)++;
        return 0;
    }
}


int Is_an_opportunity_to_shoot_down_the_right_and_leftFRIEND(int i, int j, int playing_field[][8], int priority) {

    int mov, MOV;
    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if ((i != 6 && i != 7) && (j != 0 && j != 1 && j != 7 && j != 6) && (playing_field[i + 1][j - 1] == mov || playing_field[i + 1][j - 1] == MOV) && playing_field[i + 2][j - 2] == 0 && (playing_field[i + 1][j + 1] == mov || playing_field[i + 1][j + 1] == MOV) && (playing_field[i + 2][j + 2] == 0))
    {
        return 1;
    }
    return 0;

}


void Performing_the_upper_capture(int* i, int* j, int playing_field[][8], int left, int priority) {
    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);


    if (left) {
        if (playing_field[*i][*j] == MOV) {
            playing_field[*i + 2][*j - 2] = MOV;
        }
        else {
            playing_field[*i + 2][*j - 2] = mov;
        }
        playing_field[*i + 1][*j - 1] = 0;
        playing_field[*i][*j] = 0;

        if (*i + 2 == 7 && priority == 1) {
            playing_field[*i + 2][*j - 2] = 3;
        }
        (*j)-=2;
    }
    else {
        if (playing_field[*i][*j] == MOV) {
            playing_field[*i + 2][*j + 2] = MOV;
        }
        else {
            playing_field[*i + 2][*j + 2] = mov;
        }

        playing_field[*i + 1][*j + 1] = 0;
        playing_field[*i][*j] = 0;
        if (*i + 2 == 7 && priority == 1) {
            playing_field[*i + 2][*j + 2] = 3;
        }

        (*j)+= 2;
    }

    (*i)+= 2;




}

void Taking_checkers_and_checking_movesFRIEND(int i, int j, int playing_field[][8], int* number_of_opponent_checkers, int left, char* name_player, int point, int priority, int* number_of_your_checkers) {

    if (priority == 2) {

        (*number_of_opponent_checkers)--;
    }
    else {
        (*number_of_your_checkers)--;

    }
    Performing_the_upper_capture(&i, &j, playing_field, left, priority);
    int mov, MOV;
    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if (Is_an_opportunity_to_shoot_down_the_right_and_leftFRIEND(i, j, playing_field, priority)) {
        while (1) {
            Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
            int direction = _getch();
            if (direction == 75) {


                Taking_checkers_and_checking_movesFRIEND(i, j, playing_field, number_of_opponent_checkers, 1, name_player, point, priority, number_of_your_checkers);
                break;
            }
            else if (direction == 77) {
                Taking_checkers_and_checking_movesFRIEND(i, j, playing_field, number_of_opponent_checkers, 0, name_player, point, priority, number_of_your_checkers);

                break;
            }

        }
    }
    else if ((i != 6 && i != 7) && (j != 0 && j != 1) && (playing_field[i + 1][j - 1] == mov || playing_field[i + 1][j - 1] == MOV) && (playing_field[i + 2][j - 2] == 0)) {
        Taking_checkers_and_checking_movesFRIEND(i, j, playing_field, number_of_opponent_checkers, 1, name_player, point, priority, number_of_your_checkers);
    }
    else if ((i != 6 && i != 7) && (j != 7 && j != 6) && (playing_field[i + 1][j + 1] == mov || playing_field[i + 1][j + 1] == MOV) && (playing_field[i + 2][j + 2] == 0)) {
        Taking_checkers_and_checking_movesFRIEND(i, j, playing_field, number_of_opponent_checkers, 0, name_player, point, priority, number_of_your_checkers);
    }



}


void Move_to_the_leftFRIEND(int i, int j, int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int flag) {


    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);

    if (An_impossible_left_move_for_a_friend(i, j, playing_field, priority)) {
        printf("\n\t\x1b[31m Õ≈¬Œ«ÃŒ∆ÕŒ —Œ¬≈–ÿ»“‹ ’Œƒ! \x1b[0m");
        Sleep(750);
        return;

    }
    else if (playing_field[i + 1][j - 1] == 0) {
        if (playing_field[i][j] == MOV) {
            playing_field[i + 1][j - 1] = MOV;
        }
        else {
            playing_field[i + 1][j - 1] = mov;
        }

        playing_field[i][j] = 0;




        if (i + 1 == 7 && priority == 1) {
            playing_field[i + 1][j - 1] = 3;
        }
        return;
    }

    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if ((playing_field[i + 1][j - 1] == mov || playing_field[i + 1][j - 1] == MOV) && playing_field[i + 2][j - 2] == 0) {

        Taking_checkers_and_checking_movesFRIEND(i, j, playing_field, number_of_opponent_checkers, 1, name_player, point, priority, number_of_your_checkers);
    }



}

void Move_to_the_rightFRIEND(int i, int j, int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int flag) {


    int mov, MOV;
    Assigning_a_movePRIORITY1(priority, &mov, &MOV);


    if (An_impossible_right_move_for_a_friend(i, j, playing_field, priority)) {
        printf("\n\t\x1b[31m Õ≈¬Œ«ÃŒ∆ÕŒ —Œ¬≈–ÿ»“‹ ’Œƒ! \x1b[0m");
        Sleep(750);
        return;

    }
    else if (playing_field[i + 1][j + 1] == 0) {
        if (playing_field[i][j] == MOV) {
            playing_field[i + 1][j + 1] = MOV;
        }
        else {
            playing_field[i + 1][j + 1] = mov;
        }
        playing_field[i][j] = 0;

        if (i + 1 == 7 && priority == 1) {
            playing_field[i + 1][j + 1] = 3;
        }
        return;
    }

    Assigning_a_movePRIORITY2(priority, &mov, &MOV);

    if ((playing_field[i + 1][j + 1] == mov || playing_field[i + 1][j + 1] == MOV) && playing_field[i + 2][j + 2] == 0) {
        Taking_checkers_and_checking_movesFRIEND(i, j, playing_field, number_of_opponent_checkers, 0, name_player, point, priority, number_of_your_checkers);
    }

}




int It_a_free_moveQUEEN(int i, int j, int playing_field[][8], int priority, int* blocking_counter)
{
    if (i > 0 && j < 7 && playing_field[i - 1][j + 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i > 0 && j > 0 && playing_field[i - 1][j - 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i < 7 && j < 7 && playing_field[i + 1][j + 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i < 7 && j > 0 && playing_field[i + 1][j - 1] == 0) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i < 7 && j < 7 && ((priority == 1 && (playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4)) || (priority == 2 && (playing_field[i + 1][j + 1] == 1 || playing_field[i + 1][j + 1] == 3))) && (i + 1 < 7 && j + 1 < 7 && playing_field[i + 2][j + 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i < 7 && j >0 && (((priority == 1 || priority == 3) && (playing_field[i + 1][j - 1] == 2 || playing_field[i + 1][j - 1] == 4)) || (priority == 2 && (playing_field[i + 1][j - 1] == 1 || playing_field[i + 1][j - 1] == 3))) && (i + 1 < 7 && j - 1 > 0 && playing_field[i + 2][j - 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i > 0 && j < 7 && ((((priority == 1 || priority == 3) && (playing_field[i - 1][j + 1] == 2 || playing_field[i - 1][j + 1] == 4)) || (priority == 2 && (playing_field[i - 1][j + 1] == 1 || playing_field[i - 1][j + 1] == 3)))) && (i - 1 > 1 && j + 1 < 7 && playing_field[i - 2][j + 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else if (i > 0 && j > 0 && (((priority == 1 || priority == 3) && (playing_field[i - 1][j - 1] == 2 || playing_field[i - 1][j - 1] == 4)) || (priority == 2 && (playing_field[i - 1][j - 1] == 1 || playing_field[i - 1][j - 1] == 3))) && (i - 1 > 0 && j - 1 > 0 && playing_field[i - 2][j - 2] == 0)) {
        *blocking_counter = 0;
        return 1;
    }
    else {
        (*blocking_counter)++;
        return 0;
    }
}

int Checking_the_upper_direction(int i, int j, int playing_field[][8], int priority) {

    if (i > 0 && j < 7 && playing_field[i - 1][j + 1] == 0) {
        return 1;
    }
    else if (i > 0 && j > 0 && playing_field[i - 1][j - 1] == 0) {
        return 1;
    }
    else if (i > 0 && j < 7 && (((priority == 1 && (playing_field[i - 1][j + 1] == 2 || playing_field[i - 1][j + 1] == 4)) || (priority == 2 && (playing_field[i - 1][j + 1] == 1 || playing_field[i - 1][j + 1] == 3)))) && (i - 1 > 1 && j + 1 < 7 && playing_field[i - 2][j + 2] == 0)) {

        return 1;
    }
    else if (i > 0 && j > 0 && ((priority == 1 && (playing_field[i - 1][j - 1] == 2 || playing_field[i - 1][j - 1] == 4)) || (priority == 2 && (playing_field[i - 1][j - 1] == 1 || playing_field[i - 1][j - 1] == 3))) && (i - 1 > 0 && j - 1 > 0 && playing_field[i - 2][j - 2] == 0)) {
        return 1;
    }
    else {
        printf("\n\t\x1b[31m Õ≈¬Œ«ÃŒ∆ÕŒ —Œ¬≈–ÿ»“‹ ’Œƒ! \x1b[0m");
        Sleep(750);
        return 0;
    }


}

int Checking_the_lower_direction(int i, int j, int playing_field[][8], int priority)
{
    if (i < 7 && j < 7 && playing_field[i + 1][j + 1] == 0) {
        return 1;
    }
    else if (i < 7 && j > 0 && playing_field[i + 1][j - 1] == 0) {
        return 1;
    }
    else if (i < 7 && j < 7 && ((priority == 1 && (playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4)) || (priority == 2 && (playing_field[i + 1][j + 1] == 1 || playing_field[i + 1][j + 1] == 3))) && (i + 1 < 7 && j + 1 < 7 && playing_field[i + 2][j + 2] == 0)) {

        return 1;
    }
    else if (i < 7 && j >0 && ((priority == 1 && (playing_field[i + 1][j - 1] == 2 || playing_field[i + 1][j - 1] == 4)) || (priority == 2 && (playing_field[i + 1][j - 1] == 1 || playing_field[i + 1][j - 1] == 3))) && (i + 1 < 7 && j - 1 > 0 && playing_field[i + 2][j - 2] == 0)) {
        return 1;
    }
    else {
        printf("\n\t\x1b[31m Õ≈¬Œ«ÃŒ∆ÕŒ —Œ¬≈–ÿ»“‹ ’Œƒ! \x1b[0m");
        Sleep(750);
        return 0;
    }



}


int —hecking_the_move_up_to_the_right(int i, int j, int playing_field[][8], int priority) {

    if (i > 0 && j < 7 && playing_field[i - 1][j + 1] == 0) {
        return 1;
    }
    else if (i > 0 && j < 7 && (((priority == 1 && (playing_field[i - 1][j + 1] == 2 || playing_field[i - 1][j + 1] == 4)) || (priority == 2 && (playing_field[i - 1][j + 1] == 1 || playing_field[i - 1][j + 1] == 3)))) && (i - 1 > 1 && j + 1 < 7 && playing_field[i - 2][j + 2] == 0)) {

        return 1;
    }
    else {
        return 0;
    }

}

int —hecking_the_move_up_to_the_left(int i, int j, int playing_field[][8], int priority) {

    if (i > 0 && j > 0 && playing_field[i - 1][j - 1] == 0) {
        return 1;
    }
    else if (i > 0 && j > 0 && ((priority == 1 && (playing_field[i - 1][j - 1] == 2 || playing_field[i - 1][j - 1] == 4)) || (priority == 2 && (playing_field[i - 1][j - 1] == 1 || playing_field[i - 1][j - 1] == 3))) && (i - 1 > 0 && j - 1 > 0 && playing_field[i - 2][j - 2] == 0)) {
        return 1;
    }
    else {
        return 0;
    }

}

int Checking_the_move_up_to_the_right(int i, int j, int playing_field[][8], int priority) {

    if (i < 7 && j < 7 && playing_field[i + 1][j + 1] == 0) {
        return 1;
    }
    else if (i < 7 && j < 7 && ((priority == 1 && (playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4)) || (priority == 2 && (playing_field[i + 1][j + 1] == 1 || playing_field[i + 1][j + 1] == 3))) && (i + 1 < 7 && j + 1 < 7 && playing_field[i + 2][j + 2] == 0)) {

        return 1;
    }
    else {
        return 0;
    }
}

int Checking_the_move_down_to_the_right(int i, int j, int playing_field[][8], int priority) {

    if (i < 7 && j < 7 && playing_field[i + 1][j + 1] == 0) {
        return 1;
    }
    else if (i < 7 && j < 7 && ((priority == 1 && (playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4)) || (priority == 2 && (playing_field[i + 1][j + 1] == 1 || playing_field[i + 1][j + 1] == 3))) && (i + 1 < 7 && j + 1 < 7 && playing_field[i + 2][j + 2] == 0)) {

        return 1;
    }
    else {
        return 0;
    }
}

int Checking_the_move_down_to_the_left(int i, int j, int playing_field[][8], int priority) {

    if (i < 7 && j > 0 && playing_field[i + 1][j - 1] == 0) {
        return 1;
    }
    else if (i < 7 && j >0 && ((priority == 1 && (playing_field[i + 1][j - 1] == 2 || playing_field[i + 1][j - 1] == 4)) || (priority == 2 && (playing_field[i + 1][j - 1] == 1 || playing_field[i + 1][j - 1] == 3))) && (i + 1 < 7 && j - 1 > 0 && playing_field[i + 2][j - 2] == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

void The_queens_move_is_down_to_the_left(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int i, int j) {

    Move_to_the_leftPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
    i = i - 1;
    j = j - 1;
    while (1) {

        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
        if (—hecking_the_move_up_to_the_left(i, j, playing_field, priority)) {
            while (1) {
                int move = _getch();
                if (move == 13) {
                    Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, INT_MIN);
                    Sleep(500);
                    break;

                }
                else if (move == 75) {
                    int buf1 = *number_of_opponent_checkers, buf2 = *number_of_your_checkers;
                    Move_to_the_leftPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
                    i = i - 1;
                    j = j - 1;
                    if ((*number_of_opponent_checkers == buf1 || *number_of_your_checkers == buf2) && —hecking_the_move_up_to_the_left(i, j, playing_field, priority)) {

                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                        continue;
                    }
                    else {
                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, INT_MIN);
                        Sleep(500);
                        break;
                    }
                }

            }
            break;
        }
        else {
            break;
        }
    }



}

void The_queens_move_is_down_to_the_right(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int i, int j) {

    while (1) {

        Move_to_the_rightPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
        i = i - 1;
        j = j + 1;
        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
        if (—hecking_the_move_up_to_the_right(i, j, playing_field, priority)) {
            while (1) {
                int move = _getch();
                if (move == 13) {
                    Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, INT_MIN);
                    Sleep(500);
                    break;

                }
                else if (move == 77) {
                    int buf1 = *number_of_opponent_checkers, buf2 = *number_of_your_checkers;
                    Move_to_the_rightPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
                    i = i - 1;
                    j = j + 1;
                    if ((*number_of_opponent_checkers == buf1 || *number_of_your_checkers == buf2) && —hecking_the_move_up_to_the_right(i, j, playing_field, priority)) {

                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                        continue;

                    }
                    else {
                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, INT_MIN);
                        Sleep(500);
                        break;
                    }
                }
            }
            break;
        }
        else {
            break;
        }
    }


}


void The_queens_move_is_upp_to_the_left(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int i, int j) {


    while (1) {
        Move_to_the_leftFRIEND(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
        i = i + 1;
        j = j - 1;
        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
        if (Checking_the_move_down_to_the_left(i, j, playing_field, priority)) {
            while (1) {
                int move = _getch();
                if (move == 13) {
                    Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, INT_MIN);
                    Sleep(500);
                    break;

                }
                else if (move == 75) {
                    int buf1 = *number_of_opponent_checkers, buf2 = *number_of_your_checkers;
                    Move_to_the_leftFRIEND(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
                    i = i + 1;
                    j = j - 1;
                    if ((*number_of_opponent_checkers == buf1 || *number_of_your_checkers == buf2) && Checking_the_move_down_to_the_left(i, j, playing_field, priority)) {
                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                        continue;

                    }
                    else {
                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, INT_MIN);
                        Sleep(500);
                        break;
                    }
                }
            }
            break;
        }
        else {
            break;
        }
    }



}


void The_queens_move_is_upp_to_the_right(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int i, int j) {


    while (1) {
        Move_to_the_rightFRIEND(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
        i = i + 1;
        j = j + 1;
        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
        if (Checking_the_move_down_to_the_right(i, j, playing_field, priority)) {
            while (1) {
                int move = _getch();
                if (move == 13) {
                    Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, number_of_your_checkers, i, j, INT_MIN);
                    Sleep(500);
                    break;

                }
                else if (move == 77) {
                    int buf1 = *number_of_opponent_checkers, buf2 = *number_of_your_checkers;
                    Move_to_the_rightFRIEND(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, 1);
                    i = i + 1;
                    j = j + 1;
                    if ((*number_of_opponent_checkers == buf1 || *number_of_your_checkers == buf2) && Checking_the_move_down_to_the_right(i, j, playing_field, priority)) {
                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                        continue;
                    }
                    else {
                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, INT_MIN);
                        Sleep(500);
                        break;
                    }
                }
            }
            break;
        }
        else {
            break;
        }
    }


}

void Make_a_queens_move(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers, int i, int j) {

    while (1) {
        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 2);

        int signal = _getch(), direction;

        if (signal == 72 && Checking_the_upper_direction(i, j, playing_field, priority))
        {
            while (1) {

                Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                direction = _getch();
                if (direction == 75) {
                    The_queens_move_is_down_to_the_left(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, i, j);
                    break;
                }
                else if (direction == 77) {


                    The_queens_move_is_down_to_the_right(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, i, j);
                    break;

                }
            }
            break;
        }
        else if (signal == 80 && Checking_the_lower_direction(i, j, playing_field, priority)) {

            while (1) {

                Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                direction = _getch();
                if (direction == 75) {

                    The_queens_move_is_upp_to_the_left(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, i, j);
                    break;
                }
                else if (direction == 77) {

                    The_queens_move_is_upp_to_the_right(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, i, j);
                    break;



                }
            }
            break;


        }

    }

}




void Players_turn(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers) {

    int blocking_counter = 0;
    int flag = 0;
    int counter = 0;

    for (int i = 7; i >= 0; i--) {
        if (blocking_counter == *number_of_your_checkers) {
            break;
        }
        for (int j = 7; j >= 0; j--) {

            if (playing_field[i][j] == 2 || playing_field[i][j] == 4) {
                counter++;

                if ((playing_field[i][j] == 2 && It_a_free_movePLAYER(i, j, playing_field, &blocking_counter)) || (playing_field[i][j] == 4 && It_a_free_moveQUEEN(i, j, playing_field, priority, &blocking_counter))) {
                    while (1) {

                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, flag);
                        int signal = _getch();
                        if (signal == 32) {
                            Beep(400, 300);
                            break;
                        }
                        else if (signal == 13) {
                            Beep(500, 300);
                            flag = 1;
                            if (playing_field[i][j] == 4) {
                                Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 2);
                                Make_a_queens_move(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, i, j);
                            }
                            else {
                                while (1) {
                                    Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, flag);
                                    int direction = _getch();
                                    if (direction == 75) {
                                        Move_to_the_leftPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, flag);
                                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                                        Sleep(500);
                                        break;
                                    }
                                    else if (direction == 77) {
                                        Move_to_the_rightPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, flag);
                                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                                        Sleep(500);
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }

                }

            }

            if (counter == *number_of_your_checkers) {
                i = 8;
                counter = 0;
            }
            if (flag) {
                break;
            }

        }
        if (flag) {
            break;
        }
    }


}


void Friends_turn(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers) {

    int flag = 0;
    int counter = 0;
    int blocking_counter = 0;

    for (int i = 0; i <= 7; i++) {
        if (blocking_counter == *number_of_opponent_checkers) {
            break;
        }
        for (int j = 0; j <= 7; j++) {

            if (playing_field[i][j] == 1 || playing_field[i][j] == 3) {
                counter++;

                if ((playing_field[i][j] == 1 && It_a_free_moveFRIEND(i, j, playing_field, &blocking_counter)) || (playing_field[i][j] == 3 && It_a_free_moveQUEEN(i, j, playing_field, priority, &blocking_counter))) {
                    while (1) {

                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, flag);
                        int signal = _getch();
                        if (signal == 32) {
                            Beep(400, 300);
                            break;
                        }
                        else if (signal == 13) {
                            Beep(500, 300);
                            flag = 1;
                            if (playing_field[i][j] == 3) {
                                Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 2);
                                Make_a_queens_move(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, i, j);

                            }
                            else {
                                while (1) {
                                    Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, flag);
                                    int direction = _getch();
                                    if (direction == 75) {
                                        Move_to_the_leftFRIEND(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, flag);
                                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                                        Sleep(500);
                                        break;
                                    }
                                    else if (direction == 77) {
                                        Move_to_the_rightFRIEND(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, flag);
                                        Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                                        Sleep(500);
                                        break;
                                    }

                                }
                            }
                            break;
                        }
                    }

                }

            }


            if (counter == *number_of_opponent_checkers) {
                i = -1;
                counter = 0;
            }
            if (flag) {
                break;
            }

        }

        if (flag) {
            break;
        }
    }

}


void A_game_for_two(int playing_field[][8], char* name_player, int* point) {

    int number_of_opponent_checkers = 12;
    int number_of_your_checkers = 12;

    int priority = 2;


    Displaying_the_game_space_on_the_screen(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);



    while (number_of_opponent_checkers != 0 && number_of_your_checkers != 0)
    {
        if (priority == 2) {
            Players_turn(playing_field, name_player, point, priority, &number_of_opponent_checkers, &number_of_your_checkers);

            priority = 1;

        }
        else if (priority == 1) {
            Friends_turn(playing_field, name_player, point, priority, &number_of_opponent_checkers, &number_of_your_checkers);

            priority = 2;
        }


    }

    if (number_of_opponent_checkers == 0) {

        (*point) += 5;
        Victory_screen();
    }
    else {
        (*point) -= 5;
        Loss_screen();
    }


}

void Initializing_the_downward_stroke(int i, int j, int* number_of_your_checkers, int playing_field[][8], int flag) {

    if (i + 2 == 7) {
        if (flag) {
            playing_field[i + 2][j + 2] = 3;
        }
        else {
            playing_field[i + 2][j - 2] = 3;
        }
    }
    else if (playing_field[i][j] == 3) {
        if (flag) {
            playing_field[i + 2][j + 2] = 3;
        }
        else {
            playing_field[i + 2][j - 2] = 3;
        }
    }
    else {
        if (flag) {
            playing_field[i + 2][j + 2] = 1;
        }
        else {
            playing_field[i + 2][j - 2] = 1;
        }
    }
    playing_field[i][j] = 0;
    (*number_of_your_checkers)--;


}


int It_is_possible_to_shoot_down(int i, int j, int playing_field[][8], int* number_of_your_checkers) {

    if (i < 7 && j < 7 && (playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4) && playing_field[i + 2][j + 2] == 0) {
        playing_field[i + 1][j + 1] = 0;

        Initializing_the_downward_stroke(i, j, number_of_your_checkers, playing_field, 1);
        i += 2;
        j += 2;
        It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);
        return 1;

    }
    else if (i < 7 && j >1 && (playing_field[i + 1][j - 1] == 2 || playing_field[i + 1][j - 1] == 4) && playing_field[i + 2][j - 2] == 0) {

        playing_field[i + 1][j - 1] = 0;

        Initializing_the_downward_stroke(i, j, number_of_your_checkers, playing_field, 0);
        i += 2;
        j -= 2;
        It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);
        return 1;

    }
    else if (playing_field[i][j] == 3 && i > 1 && j > 1 && (playing_field[i - 1][j - 1] == 2 || playing_field[i - 1][j - 1] == 4) && playing_field[i - 2][j - 2] == 0) {

        playing_field[i - 1][j - 1] = 0;
        playing_field[i][j] = 0;
        playing_field[i - 2][j - 2] = 3;
        (*number_of_your_checkers)--;
        i -= 2;
        j -= 2;
        It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);
        return 1;
    }
    else if (playing_field[i][j] == 3 && i > 1 && j < 6 && (playing_field[i - 1][j + 1] == 2 || playing_field[i - 1][j + 1] == 4) && playing_field[i - 2][j + 2] == 0) {

        playing_field[i - 1][j + 1] = 0;
        playing_field[i][j] = 0;
        playing_field[i - 2][j + 2] = 3;
        (*number_of_your_checkers)--;
        i -= 2;
        j += 2;
        It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);
        return 1;


    }
    return 0;


}



void Initializing_the_downward_strokeQUEEN(int i, int j, int x, int y, int* number_of_your_checkers, int playing_field[][8], int flag) {

    if (flag) {
        playing_field[i + 1][j + 1] = 0;
        playing_field[i + 2][j + 2] = 3;


    }
    else if (flag == 2) {
        playing_field[i - 1][j - 1] = 0;
        playing_field[i - 2][j - 2] = 3;

    }
    else if (flag == 3) {
        playing_field[i - 1][j + 1] = 0;
        playing_field[i - 2][j + 2] = 3;
    }
    else {
        playing_field[i + 1][j - 1] = 0;
        playing_field[i + 2][j - 2] = 3;
    }

    playing_field[i][j] = 0;
    playing_field[x][y] = 0;
    (*number_of_your_checkers)--;


}

int It_is_possible_to_shoot_downQUEEN(int x, int y, int playing_field[][8], int* number_of_your_checkers) {


    if (x < 7 && y < 7 && playing_field[x + 1][y + 1] == 0) {
        int i = x, j = y;
        for (i, j; j < 6 && i < 6; i++, j++) {

            if ((playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4) && playing_field[i + 2][j + 2] == 0) {
                Initializing_the_downward_strokeQUEEN(i, j, x, y, number_of_your_checkers, playing_field, 1);

                i += 2;
                j += 2;

                It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);
                return 1;

            }
            else if ((playing_field[i + 1][j + 1] == 2 || playing_field[i + 1][j + 1] == 4) && (playing_field[i + 2][j + 2] == 2 || playing_field[i + 2][j + 2] == 4)) {

                return 0;
            }
            else {
                continue;
            }

        }



    }
    else if (x < 7 && y >1 && playing_field[x + 1][y - 1] == 0) {

        int i = x, j = y;
        for (i, j; i < 6 && j>1; i += 2, j -= 2) {

            if ((playing_field[i + 1][j - 1] == 2 || playing_field[i + 1][j - 1] == 4) && playing_field[i + 2][j - 2] == 0) {
                Initializing_the_downward_strokeQUEEN(i, j, x, y, number_of_your_checkers, playing_field, 0);
                i += 2;
                j -= 2;
                It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);
                return 1;

            }
            else if ((playing_field[i + 1][j - 1] == 2 || playing_field[i + 1][j - 1] == 4) && (playing_field[i + 2][j - 2] == 2 || playing_field[i + 2][j - 2] == 4)) {
                return 0;
            }
            else {
                continue;
            }

        }

    }
    else if (x > 1 && y > 1 && playing_field[x - 1][y - 1] == 0) {

        int i = x, j = y;
        for (i, j; i > 1 && j > 1; i -= 2, j -= 2) {

            if ((playing_field[i - 1][j - 1] == 2 || playing_field[i - 1][j - 1] == 4) && playing_field[i - 2][j - 2] == 0) {
                Initializing_the_downward_strokeQUEEN(i, j, x, y, number_of_your_checkers, playing_field, 2);
                i -= 2;
                j -= 2;

                It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);

                return 1;
            }
            else if ((playing_field[i - 1][j - 1] == 2 || playing_field[i - 1][j - 1] == 4) && (playing_field[i - 2][j - 2] == 2 || playing_field[i - 2][j - 2] == 4)) {
                return 0;
            }
            else {
                continue;
            }

        }


    }
    else if (x > 1 && y < 1 && playing_field[x - 1][y + 1] == 0) {

        int i = x, j = y;
        for (i, j; i > 1 && j < 6; i -= 2, j += 2) {

            if (i > 1 && j < 1 && (playing_field[i - 1][j + 1] == 2 || playing_field[i - 1][j + 1] == 4) && playing_field[i - 2][j + 2] == 0) {
                Initializing_the_downward_strokeQUEEN(i, j, x, y, number_of_your_checkers, playing_field, 3);
                i -= 2;
                j += 2;
                It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers);
                return 1;
            }

            else if ((playing_field[i - 1][j + 1] == 2 || playing_field[i - 1][j + 1] == 4) && (playing_field[i - 2][j + 2] == 2 || playing_field[i - 2][j + 2] == 4)) {
                return 0;
            }
            else {
                continue;
            }

        }

    }
    return 0;


}



int There_is_a_safe_passage(int i, int j, int playing_field[][8]) {

    if (((i < 7 && j < 7 && j != 6 && (playing_field[i + 2][j + 2] == 0 || (playing_field[i + 2][j + 2] == 1 || playing_field[i + 2][j + 2] == 3)) || (j == 6 && i < 7))) && playing_field[i + 1][j + 1] == 0) {

        if (playing_field[i][j] == 3) {
            playing_field[i + 1][j + 1] = 3;
        }
        else {
            playing_field[i + 1][j + 1] = 1;
        }
        playing_field[i][j] = 0;
        return 1;
    }
    else if (((i < 7 && j >0 && j != 1 && (playing_field[i + 2][j - 2] == 0 || (playing_field[i + 2][j - 2] == 1 || playing_field[i + 2][j - 2] == 3))) || (j == 1 && j > 0)) && playing_field[i + 1][j - 1] == 0) {

        if (playing_field[i][j] == 3) {
            playing_field[i + 1][j - 1] = 3;
        }
        else {
            playing_field[i + 1][j - 1] = 1;
        }
        playing_field[i][j] = 0;
        return 1;
    }
    else if (((i > 0 && j > 0 && j != 1 && (playing_field[i - 2][j - 2] == 0 || (playing_field[i - 2][j - 2] == 1 || playing_field[i - 2][j - 2] == 3))) || (j == 1 && i > 0)) && playing_field[i][j] == 3 && playing_field[i - 1][j - 1] == 0) {


        playing_field[i - 1][j - 1] = 3;
        playing_field[i][j] = 0;
        return 1;
    }
    else if (((i > 0 && j < 7 && j != 6 && (playing_field[i - 2][j + 2] == 0 || (playing_field[i - 2][j + 2] == 1 || playing_field[i - 2][j + 2] == 3))) || (i > 0 && j == 6)) && playing_field[i][j] == 3 && playing_field[i - 1][j + 1] == 0)
    {
        playing_field[i - 1][j + 1] = 3;
        playing_field[i][j] = 0;
        return 1;
    }
    return 0;

}

void There_is_a_dangerous_move(int i, int j, int playing_field[][8]) {

    if (i < 7 && j < 7 && playing_field[i + 1][j + 1] == 0) {

        if (playing_field[i][j] == 3) {
            playing_field[i + 1][j + 1] = 3;
        }
        else {
            playing_field[i + 1][j + 1] = 1;
        }
        playing_field[i][j] = 0;

    }
    else if (i < 7 && j >0 && playing_field[i + 1][j - 1] == 0) {

        if (playing_field[i][j] == 3) {
            playing_field[i + 1][j - 1] = 3;
        }
        else {
            playing_field[i + 1][j - 1] = 1;
        }
        playing_field[i][j] = 0;

    }
    else if (i > 0 && j > 0 && playing_field[i - 1][j - 1] == 0 && playing_field[i][j] == 3) {


        playing_field[i - 1][j - 1] = 3;
        playing_field[i][j] = 0;

    }
    else if (i > 0 && j < 7 && playing_field[i - 1][j + 1] == 0 && playing_field[i][j] == 3)
    {
        playing_field[i - 1][j + 1] = 3;
        playing_field[i][j] = 0;

    }



}


void Players_turn_with_a_BOT(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers) {

    int blocking_counter = 0;
    int flag = 0;
    int counter = 0;

    for (int i = 7; i >= 0; i--) {
        if (blocking_counter == *number_of_your_checkers) {
            break;
        }
        for (int j = 7; j >= 0; j--) {

            if (playing_field[i][j] == 2 || playing_field[i][j] == 4) {
                counter++;

                if ((playing_field[i][j] == 2 && It_a_free_movePLAYER(i, j, playing_field, &blocking_counter)) || (playing_field[i][j] == 4 && It_a_free_moveQUEEN(i, j, playing_field, priority, &blocking_counter))) {
                    while (1) {

                        Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, flag);
                        int signal = _getch();
                        if (signal == 32) {
                            Beep(400, 300);
                            break;
                        }
                        else if (signal == 13) {
                            Beep(500, 300);
                            flag = 1;
                            if (playing_field[i][j] == 4) {
                                Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 2);
                                Make_a_queens_move(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, i, j);
                            }
                            else {
                                while (1) {
                                    Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, flag);
                                    int direction = _getch();
                                    if (direction == 75) {
                                        Move_to_the_leftPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, flag);
                                        Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                                        Sleep(500);
                                        break;
                                    }
                                    else if (direction == 77) {
                                        Move_to_the_rightPLAYER(i, j, playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, flag);
                                        Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                                        Sleep(500);
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }

                }

            }

            if (counter == *number_of_your_checkers) {
                i = 8;
                counter = 0;
            }
            if (flag) {
                break;
            }

        }
        if (flag) {
            break;
        }
    }


}


int A_bot_pass_aimed_at_taking_checkers(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers) {


    int counter = 0;
    int blocking_counter = 0;


    for (int i = 0; i <= 7; i++) {
        if (blocking_counter == *number_of_opponent_checkers) {
            return 1;
        }
        for (int j = 0; j <= 7; j++) {

            if (playing_field[i][j] == 1 || playing_field[i][j] == 3) {
                counter++;

                if ((playing_field[i][j] == 1 && It_a_free_moveFRIEND(i, j, playing_field, &blocking_counter)) || (playing_field[i][j] == 3 && It_a_free_moveQUEEN(i, j, playing_field, priority, &blocking_counter))) {

                    Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                    Beep(300, 300);
                    Sleep(300);


                    if (It_is_possible_to_shoot_down(i, j, playing_field, number_of_your_checkers)) {
                        Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                        Sleep(300);
                        return 1;

                    }
                    else if (playing_field[i][j] == 3 && It_is_possible_to_shoot_downQUEEN(i, j, playing_field, number_of_your_checkers)) {
                        Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                        Sleep(300);
                        return  1;


                    }

                }

            }

        }
        if (counter == *number_of_opponent_checkers) {
            return 0;
        }
    }


}


int The_passage_of_the_bot_aimed_at_safe_passage(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers) {



    int counter = 0;
    int blocking_counter = 0;

    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {

            if (playing_field[i][j] == 1 || playing_field[i][j] == 3) {
                counter++;

                if ((playing_field[i][j] == 1 && It_a_free_moveFRIEND(i, j, playing_field, &blocking_counter)) || (playing_field[i][j] == 3 && It_a_free_moveQUEEN(i, j, playing_field, priority, &blocking_counter))) {
                    Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                    Sleep(300);
                    Beep(300, 300);


                    if (There_is_a_safe_passage(i, j, playing_field)) {
                        Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                        Sleep(300);
                        return 1;

                    }




                }

            }



        }

        if (counter == *number_of_opponent_checkers) {
            return 0;
        }
    }




}


void The_bots_passage_on_a_dangerous_move(int playing_field[][8], char* name_player, int* point, int priority, int* number_of_opponent_checkers, int* number_of_your_checkers) {


    int blocking_counter = 0;


    for (int i = 7; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {

            if (playing_field[i][j] == 1 || playing_field[i][j] == 3) {


                if ((playing_field[i][j] == 1 && It_a_free_moveFRIEND(i, j, playing_field, &blocking_counter)) || (playing_field[i][j] == 3 && It_a_free_moveQUEEN(i, j, playing_field, priority, &blocking_counter))) {
                    Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, i, j, 1);
                    Sleep(300);
                    Beep(300, 300);


                    There_is_a_dangerous_move(i, j, playing_field);
                    Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, *number_of_opponent_checkers, *number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);
                    Sleep(300);

                    return;




                }

            }



        }


    }



}




void Playing_with_a_bot(int playing_field[][8], char* name_player, int* point) {

    int number_of_opponent_checkers = 12;
    int number_of_your_checkers = 12;

    int priority = 2;


    Displaying_the_game_space_on_the_screenBOT(playing_field, name_player, point, priority, number_of_opponent_checkers, number_of_your_checkers, INT_MIN, INT_MIN, INT_MIN);


    while (number_of_opponent_checkers != 0 && number_of_your_checkers != 0)
    {
        if (priority == 2) {

            Players_turn_with_a_BOT(playing_field, name_player, point, priority, &number_of_opponent_checkers, &number_of_your_checkers);
            priority = 3;

        }
        else if (priority == 3) {
            int flag = A_bot_pass_aimed_at_taking_checkers(playing_field, name_player, point, priority, &number_of_opponent_checkers, &number_of_your_checkers);
            if (flag == 0) {

                flag = The_passage_of_the_bot_aimed_at_safe_passage(playing_field, name_player, point, priority, &number_of_opponent_checkers, &number_of_your_checkers);
                if (flag == 0)
                {
                    The_bots_passage_on_a_dangerous_move(playing_field, name_player, point, priority, &number_of_opponent_checkers, &number_of_your_checkers);

                }

            }


            priority = 2;
        }


    }

    if (number_of_opponent_checkers == 0) {

        (*point) += 5;
        Victory_screen();
    }
    else {
        (*point) -= 5;
        Loss_screen();
    }


}


void Game(char* name_player, int* point) {


    int playing_field[8][8] = { {0,1,0,1,0,1,0,1},
                                {1,0,1,0,1,0,1,0},
                                {0,1,0,1,0,1,0,1},
                                {0,0,0,0,0,0,0,0},
                                {0,0,0,0,0,0,0,0},
                                {2,0,2,0,2,0,2,0},
                                {0,2,0,2,0,2,0,2},
                                {2,0,2,0,2,0,2,0} };



    if (Game_mode_selection() == 1) {

        A_game_for_two(playing_field, name_player, point);

    }
    else
    {
        Playing_with_a_bot(playing_field, name_player, point);


    }
}

