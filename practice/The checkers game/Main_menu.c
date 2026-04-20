#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include"Checking.h"
#include"Game_implementation.h""


void Menu_display(int position) {
    system("cls");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        WORD savedAttributes = csbi.wAttributes;

        printf("______________________________\n");
        printf("|   \x1b[32m         ÿ¿ÿ »           \x1b[0m|\n");
        printf("|____________________________|\n");


        if (position == 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|            »√–¿“‹          |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|            »√–¿“‹          |\n");
        }
        if (position == 2) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|         œ–¿¬»À¿ »√–€       |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|         œ–¿¬»À¿ »√–€       |\n");
        }
        if (position == 3) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|            ¬€…“»           |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|            ¬€…“»           |\n");
        }
        printf("|____________________________|\n");

        printf("\n\n*ÔÂÂ‰‚ËÊÂÌËÂ ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÒÚÂÎÍ‡ÏË \n");
        printf("*‚˚·Ó ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÍÌÓÔÍÓÈ ENTER \n");

    }
    else {

        printf("\n\x1b[31mÓ¯Ë·Í‡: Õ≈¬Œ«ÃŒ∆ÕŒ œŒÀ”◊»“‹ »Õ‘Œ–Ã¿÷»ﬁ Œ  ŒÕ—ŒÀ» \x1b[0m");

    }

}

void Displaying_the_game_rules_on_the_screen() {
    
    while (1) {

    int signal;
    system("cls");

    printf("______________________________\n");
    printf("|   \x1b[35m      œ–¿¬»À¿ »√–€ \x1b[0m      |\n");
    printf("|____________________________|\n");

    printf("≈ÒÚ¸ ‰‚‡ ÂÊËÏ‡ Ë„˚:\n");
    printf("- Õ‡ ‰‚ÓËı\n");
    printf("- — ·ÓÚÓÏ\n");

    printf("\nÿ‡„Ë ÓÒÛ˘ÂÒÚ‚Îˇ˛ÚÒˇ ÔÓÓ˜Â∏‰ÌÓ\n");
    printf("- ÔÂ‚˚Â ıÓ‰ˇÚ \x1b[35mÓÁÓ‚˚Â\x1b[0m \n");
    printf("- Ó·˚˜ÌÓÈ ¯‡¯ÍÂ ÌÂÎ¸Áˇ ıÓ‰ËÚ¸ Ì‡Á‡‰ Ë ·ËÚ¸ Ì‡Á‡‰ \n");
    printf("- ÂÒÎË ıÓ‰ ÌÂ‚ÓÁÏÓÊÂÌ, Ó˜ÂÂ‰¸ ÔÂÂıÓ‰ËÚ ÍÓ ‚ÚÓÓÏÛ Ë„ÓÍÛ \n");
    printf("- ‰‡ÏÍÓÈ ÒÚ‡ÌÓ‚ËÚÒˇ Ú‡ ¯‡¯Í‡ ,ÍÓÚÓ‡ˇ ‰Ó¯Î‡ ‰Ó ÔÓÚË‚ÓÔÓÎÓÊÌÓ„Ó ÍÓÌˆ‡ ÔÓÎˇ\n");

    printf("\n»„‡ Á‡‚Â¯‡ÂÚÒˇ , ÍÓ„‰‡ ¯‡¯ÍË Ó‰ÌÓ„Ó ËÁ Ë„ÓÍÓ‚ ‚ÒÂ Ò·ËÚ˚\n");
    printf("- ÂÒÎË ‚˚ ÔÓË„‡ÎË Û ‚‡Ò ÓÚÌËÏÂÚÒˇ 5 ·‡ÎÎÓ‚ \n");
    printf("- ÂÒÎË ‚˚ ‚˚Ë„‡ÎË ‚‡Ï ‰Ó·‡‚ËÚÒˇ 5 ·‡ÎÎÓ‚ \n");

   
        printf("\n\n¬€’Œƒ ------------->\x1b[32m ENTER\x1b[0m  \n");
        signal = _getch();
        if (signal == 13) {
            break;
        }
        else {
            printf("\n\n\x1b[31mÕ¿∆Ã»“≈ ¬≈–Õ”ﬁ  À¿¬»ÿ”!\x1b[0m  \n");
            Sleep(700);

        }

    }

}


struct PLAYER {

    char* name;
    int  point;

};


int Reading_and_calculating_the_size(FILE* fp, char* buffer) {

    fgets(buffer, 256, fp);
    int size = strlen(buffer);
    buffer[size - 1] = '\0';

    return size;

}


int Memory_allocation_and_data_recording(struct PLAYER** player, FILE* fp) {

    int count_players = 0;
    fscanf_s(fp, "%d", &count_players, sizeof(int));
    Fseek_and_checkingCUR(fp, 1);
    *player = malloc(sizeof(struct PLAYER) * count_players);
    Checking_memory_allocationPLAYER(player);

    char buffer[256];

    for (int i = 0; i < count_players; i++) {

        int size = Reading_and_calculating_the_size(fp, buffer);
        (*player)[i].name = malloc(sizeof(char) * size);
        Checking_memory_allocation((*player)[i].name);
        strcpy_s((*player)[i].name, size, buffer);

        fscanf_s(fp, "%d", &(*player)[i].point, sizeof(int));
        Fseek_and_checkingCUR(fp, 2);
    }


    return  count_players;
}


struct PLAYER* Opening_the_file_and_rewriting_the_players(char* filepath, int* count_players) {

    struct PLAYER* player = NULL;
    FILE* fp = fopen(filepath, "r");
    Checking_the_file_open(fp);

    *count_players = Memory_allocation_and_data_recording(&player, fp);


    Fclose_and_checking(fp);
    return player;
}


void  Menu_player_display(int position) {

    system("cls");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        WORD savedAttributes = csbi.wAttributes;

        printf("______________________________\n");
        printf("|   \x1b[32m      ¬€¡Œ– »√–Œ ¿       \x1b[0m|\n");
        printf("|____________________________|\n");


        if (position == 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|        ¬€¡–¿“‹ »√–Œ ¿      |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|        ¬€¡–¿“‹ »√–Œ ¿      |\n");
        }
        if (position == 2) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|       ƒŒ¡¿¬»“‹ »√–Œ ¿      |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|       ƒŒ¡¿¬»“‹ »√–Œ ¿      |\n");
        }
        if (position == 3) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            printf("|        ”ƒ¿À»“‹ »√–Œ ¿      |\n");
            SetConsoleTextAttribute(hConsole, savedAttributes);
        }
        else {
            printf("|        ”ƒ¿À»“‹ »√–Œ ¿      |\n");
        }
        printf("|____________________________|\n");

        printf("\n\n*ÔÂÂ‰‚ËÊÂÌËÂ ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÒÚÂÎÍ‡ÏË \n");
        printf("*‚˚·Ó ÓÒÛ˘ÂÒÚ‚ÎˇÂÚÒˇ ÍÌÓÔÍÓÈ ENTER \n");

    }
    else {

        printf("\n\x1b[31mÓ¯Ë·Í‡: Õ≈¬Œ«ÃŒ∆ÕŒ œŒÀ”◊»“‹ »Õ‘Œ–Ã¿÷»ﬁ Œ  ŒÕ—ŒÀ» \x1b[0m");

    }

}



void Displaying_the_player_on_the_screen(struct PLAYER** player, int* count_players) {

    for (int i = 0; i < *count_players; i++) {

        printf("\n \x1b[32m%d.\x1b[0m %s", i + 1, (*player)[i].name);
        printf("\n ·‡ÎÎ˚: \x1b[32m%d\x1b[0m ", (*player)[i].point);

    }


}


int Player_withdrawal_and_selection(struct PLAYER** player, int* count_players) {

    system("cls");

    printf("______________________________\n");
    printf("|   \x1b[32m      ¬€¡Œ– »√–Œ ¿       \x1b[0m|\n");
    printf("|____________________________|\n");

    Displaying_the_player_on_the_screen(player, count_players);

    printf("\n\n \x1b[32m¬€¡≈–»“≈ »√–Œ ¿:\x1b[0m ");
    int index_player;
    while (!scanf_s("%d", &index_player) || getchar() != '\n' || index_player > *count_players || index_player < 1) {

        printf("\n \x1b[31m¬¬≈ƒ»“≈  Œ––≈ “ÕŒ≈ «Õ¿◊≈Õ»≈: \x1b[0m ");

    }
    return index_player - 1;
}


int Reading_and_calculating_the_size_STDIN(char* buffer) {

    fgets(buffer, 256, stdin);
    int size = strlen(buffer);
    buffer[size - 1] = '\0';

    return size;

}


void Adding_a_player(struct PLAYER** player, int* count_players) {

    char buffer[256];
    (*count_players)++;
    *player = realloc(*player, *count_players * sizeof(struct PLAYER));
    Checking_memory_allocationPLAYER(player);

    system("cls");

    printf("______________________________\n");
    printf("|   \x1b[32m   ƒŒ¡¿¬À≈Õ»≈ »√–Œ ¿     \x1b[0m|\n");
    printf("|____________________________|\n");


    printf("\n\x1b[32m ‚‚Â‰ËÚÂ ËÏˇ Ë„ÓÍ‡:\x1b[0m ");
    int size = Reading_and_calculating_the_size_STDIN(buffer);
    (*player)[*count_players - 1].name = malloc(sizeof(char) * size);
    Checking_memory_allocation((*player)[*count_players - 1].name);
    strcpy_s((*player)[*count_players - 1].name, size, buffer);

    (*player)[*count_players - 1].point = 0;
}


void Removing_a_player(struct PLAYER** player, int* count_players, int index) {


    free((*player)[index].name);
    (*count_players)--;

    *player = realloc(*player, *count_players * sizeof(struct PLAYER));
    if (*count_players != 0) {
        Checking_memory_allocationPLAYER(player);
    }

}



void Removing_a_player_and_input_index(struct PLAYER** player, int* count_players) {

    system("cls");

    printf("______________________________\n");
    printf("|   \x1b[32m   ”ƒ¿À≈Õ»≈ »√–Œ ¿       \x1b[0m|\n");
    printf("|____________________________|\n");


    Displaying_the_player_on_the_screen(player, count_players);

    printf("\n\n\x1b[32m¬€¡≈–»“≈ »√–Œ ¿,  Œ“Œ–Œ√Œ ’Œ“»“≈ ”ƒ¿À»“‹:\x1b[0m ");
    int index_player;
    while (!scanf_s("%d", &index_player) || getchar() != '\n' || index_player > *count_players || index_player < 1) {

        printf("\n\x1b[31m¬¬≈ƒ»“≈  Œ––≈ “ÕŒ≈ «Õ¿◊≈Õ»≈: \x1b[0m ");

    }

    Removing_a_player(player, count_players, index_player - 1);


}


void Position_with_the_up_arrow(int* position) {

    Beep(300, 300);
    (*position)--;
    if (*position < 1) {
        *position = 3;
    }

    Menu_player_display(*position);
}

void Position_with_the_down_arrow(int* position) {

    Beep(300, 300);
    (*position)++;
    if (*position > 3) {
        *position = 1;
    }

    Menu_player_display(*position);
}

int Menu_and_player_selection(struct PLAYER** player, int* count_players) {



    int position = 1, signal;
    Menu_player_display(position);

    while (1) {

        signal = _getch();

        if (signal == 72) {

            Position_with_the_up_arrow(&position);

        }
        else if (signal == 80) {

            Position_with_the_down_arrow(&position);

        }
        else if (signal == 13) {
            if (position == 1) {
                if (*count_players == 0) {
                    printf("\n\x1b[31mÕ≈“ »√–Œ Œ¬ :(  ƒÓ·‡‚¸ÚÂ Ë„ÓÍ‡!\x1b[0m");
                    Sleep(1000);
                }
                else {
                    return Player_withdrawal_and_selection(player, count_players);
                }
            }
            else if (position == 2) {
                Adding_a_player(player, count_players);
            }
            else {

                if (*count_players == 0) {
                    printf("\n\x1b[31mÕ≈“ »√–Œ Œ¬ :(  \x1b[0m");
                    Sleep(1000);
                }
                else {

                    Removing_a_player_and_input_index(player, count_players);

                }

            }
            Menu_player_display(position);
        }



    }



}


int Player_choice(char* filepath, struct PLAYER** player, int* count_players) {


    *player = Opening_the_file_and_rewriting_the_players(filepath, count_players);
    int player_number = Menu_and_player_selection(player, count_players);


    return player_number;
}



void Writing_space(FILE* fp) {

    char num = ' ';

    fwrite(&num, sizeof(char), 1, fp);

}


void Saving_the_results_to_a_file(struct PLAYER* player, int count_players, char* filepath) {

    FILE* fp = fopen(filepath, "w");
    Checking_the_file_open(fp);
    fprintf(fp, "%d", count_players);
    Writing_space(fp);

    for (int i = 0; i < count_players; i++) {

        fprintf(fp, "%s\n", player[i].name);
        fprintf(fp, "%d\n", player[i].point);


    }

    Fclose_and_checking(fp);
}


void Free_players(struct PLAYER** player, int count_players) {

    for (int i = 0; i < count_players; i++) {

        free((*player)[i].name);


    }

    free(*player);

}



void Game_implementation(char* filepath) {

    struct PLAYER* player;
    int count_players = 0;
    int index_player = Player_choice(filepath, &player, &count_players);
    Game(player[index_player].name, &player[index_player].point);

    Saving_the_results_to_a_file(player, count_players, filepath);
    Free_players(&player, count_players);
}


void Main_menu(char* filepath) {

    int position = 1;
    int signal;
    Menu_display(position);

    while (1) {

        signal = _getch();

        if (signal == 72) {
            Beep(300, 300);
            position--;
            if (position < 1) {
                position = 3;
            }
            Menu_display(position);
        }
        else if (signal == 80) {
            Beep(300, 300);
            position++;
            if (position > 3) {
                position = 1;
            }
            Menu_display(position);
        }
        else if (signal == 13) {
            if (position == 3) {
                return;
            }
            else if (position == 2) {
                Displaying_the_game_rules_on_the_screen();

            }
            else {
                Game_implementation(filepath);
            }
            Menu_display(position);
        }



    }

}
