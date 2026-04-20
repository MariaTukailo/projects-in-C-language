#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include"Checking.h"


void Notification_of_the_course_and_number_of_checkers(char* name_player, int priority, int number_of_opponent_checkers, int number_of_your_checkers) {

    if (priority == 2) {
        printf("\n\t\x1b[35mВаш ход! ( %s) \x1b[0m\n\tКоличество оставшихся шашек: \x1b[35m%d\x1b[0m", name_player, number_of_your_checkers);
    }
    else if (priority == 1) {
        printf("\n\t\x1b[36mХод друга!  \x1b[0m\n\tКоличество оставшихся шашек: \x1b[36m%d\x1b[0m", number_of_opponent_checkers);
    }
    else if (priority == 3) {
        printf("\n\t\x1b[36mХод Бота!  \x1b[0m\n\tКоличество оставшихся шашек: \x1b[36m%d\x1b[0m", number_of_opponent_checkers);
    }

}


void Drawing_arrows_and_choosing_a_checker(int flag) {

    if (flag == 1) {
        printf("\n\t\x1b[32m Совершите ход! \x1b[0m");
        printf("\n\t_______________________________");
        printf("\n\t|              |              |");
        printf("\n\t|     <---     |      --->    |");
        printf("\n\t|______________|______________|");
        printf("\n\t\x1b[32m*ход выполняется нажатием стрелок\x1b[0m");
    }
    else if (flag == 0) {
        printf("\n\t\x1b[32mВыберите шашку! \x1b[0m");
        printf("\n\t_______________________________");
        printf("\n\t|              |              |");
        printf("\n\t|    ПРОБЕЛ    |     ENTER    |");
        printf("\n\t|______________|______________|");
        printf("\n\t\x1b[32m*нажмите пробел ,чтобы изменить выбор\x1b[0m");
        printf("\n\t\x1b[32m*нажмите ENTER ,чтобы подтвердить выбор\x1b[0m");
    }
    else if (flag == 2) {

        printf("\n\t\x1b[32m Выберите направление хода! \x1b[0m");
        printf("\n\t_______________________________");
        printf("\n\t|              |              |");
        printf("\n\t|       |      |       ^      |");
        printf("\n\t|       v      |       |      |");
        printf("\n\t|______________|______________|");
        printf("\n\t\x1b[32m*ход выполняется нажатием стрелок\x1b[0m");

    }
}

void Displaying_the_game_space_on_the_screen(int playing_field[][8], char* name_player, int* point, int priority, int number_of_opponent_checkers, int number_of_your_checkers, int index_i, int index_j, int flag) {

    system("cls");
    printf("\t______________________________\n");
    printf("\t| \x1b[32m       ИГРА НА ДВОИХ  \x1b[0m     |\n");
    printf("\t|____________________________|\n");
    printf("\n\t\x1b[32mигрок:\x1b[0m %s\n\t\x1b[32mбаллы:\x1b[0m %d\n", name_player, *point);
    printf("\n\n\t\033[44m    a  b  c  d  e  f  g  h  \033[0m\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (j == 0) {
                printf("\t\033[44m %d \033[0m", i + 1);
            }


            if (playing_field[i][j] == 0 && (j + i) % 2 == 0) {
                printf("\033[47m   \033[0m");

            }
            else if (priority == 2 && index_i == i && index_j == j && (playing_field[i][j] == 2 || playing_field[i][j] == 4)) {
                if (playing_field[i][j] == 2) {
                    printf("\x1b[35m\033[42m o \033[0m\x1b[0m");
                }
                else {
                    printf("\x1b[35m\033[42m O \033[0m\x1b[0m");
                }

            }
            else if (priority == 1 && index_i == i && index_j == j && (playing_field[i][j] == 1 || playing_field[i][j] == 3)) {
                if (playing_field[i][j] == 1) {
                    printf("\x1b[36m\033[42m o \033[0m\x1b[0m");
                }
                else {
                    printf("\x1b[36m\033[42m O \033[0m\x1b[0m");
                }

            }
            else if (playing_field[i][j] == 1) {
                printf("\x1b[36m o \x1b[0m");

            }
            else if (playing_field[i][j] == 2) {
                printf("\x1b[35m o \x1b[0m");

            }
            else if (playing_field[i][j] == 3) {
                printf("\x1b[36m O \x1b[0m");

            }
            else if (playing_field[i][j] == 4) {
                printf("\x1b[35m O \x1b[0m");

            }
            else {
                printf("   ");
            }
            if (j == 7) {
                printf("\033[44m \033[0m");
            }

        }
        printf("\n");

    }
    printf("\t\033[44m                            \033[0m\n");
    Notification_of_the_course_and_number_of_checkers(name_player, priority, number_of_opponent_checkers, number_of_your_checkers);
    Drawing_arrows_and_choosing_a_checker(flag);
}

void Displaying_the_game_space_on_the_screenBOT(int playing_field[][8], char* name_player, int* point, int priority, int number_of_opponent_checkers, int number_of_your_checkers, int index_i, int index_j, int flag) {

    system("cls");
    printf("\t______________________________\n");
    printf("\t| \x1b[32m       ИГРА С  БОТОМ  \x1b[0m     |\n");
    printf("\t|____________________________|\n");
    printf("\n\t\x1b[32mигрок:\x1b[0m %s\n\t\x1b[32mбаллы:\x1b[0m %d\n", name_player, *point);
    printf("\n\n\t\033[44m    a  b  c  d  e  f  g  h  \033[0m\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            if (j == 0) {
                printf("\t\033[44m %d \033[0m", i + 1);
            }


            if (playing_field[i][j] == 0 && (j + i) % 2 == 0) {
                printf("\033[47m   \033[0m");

            }
            else if (priority == 2 && index_i == i && index_j == j && (playing_field[i][j] == 2 || playing_field[i][j] == 4)) {
                if (playing_field[i][j] == 2) {
                    printf("\x1b[35m\033[42m o \033[0m\x1b[0m");
                }
                else {
                    printf("\x1b[35m\033[42m O \033[0m\x1b[0m");
                }

            }
            else if (priority == 1 && index_i == i && index_j == j && (playing_field[i][j] == 1 || playing_field[i][j] == 3)) {
                if (playing_field[i][j] == 1) {
                    printf("\x1b[36m\033[42m o \033[0m\x1b[0m");
                }
                else {
                    printf("\x1b[36m\033[42m O \033[0m\x1b[0m");
                }

            }
            else if (playing_field[i][j] == 1) {
                printf("\x1b[36m o \x1b[0m");

            }
            else if (playing_field[i][j] == 2) {
                printf("\x1b[35m o \x1b[0m");

            }
            else if (playing_field[i][j] == 3) {
                printf("\x1b[36m O \x1b[0m");

            }
            else if (playing_field[i][j] == 4) {
                printf("\x1b[35m O \x1b[0m");

            }
            else {
                printf("   ");
            }
            if (j == 7) {
                printf("\033[44m \033[0m");
            }

        }
        printf("\n");

    }
    printf("\t\033[44m                            \033[0m\n");
    Notification_of_the_course_and_number_of_checkers(name_player, priority, number_of_opponent_checkers, number_of_your_checkers);
    Drawing_arrows_and_choosing_a_checker(flag);
}

void Victory_screen() {

    system("cls");

    printf("\t______________________________\n");
    printf("\t|      \x1b[32m      ПОБЕДА!!! \x1b[0m       |\n");
    printf("\t|____________________________|\n");

    printf("\n\n\n\n\t\x1b[35mВЫ ПОБЕДИЛИ!!! +5 баллов :)\x1b[0m\n");

    Sleep(1500);

}


void Loss_screen() {

    system("cls");

    printf("\t______________________________\n");
    printf("\t|     \x1b[31m     ПРОИГРЫШ :(  \x1b[0m     |\n");
    printf("\t|____________________________|\n");

    printf("\n\n\n\n\t\x1b[36mВЫ ПРОИГРАЛИ... -5 баллов :(\x1b[0m\n");

    Sleep(1500);

}
