#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>


void Checking_arguments(int argc) {

    if (argc != 2) {

        printf("\x1b[31mошибка:НЕТ ДОСТУПА К ФАЙЛУ \x1b[0m");
        exit(1);
    }

}

void  Checking_the_file_open(FILE* fp) {

    if (fp == NULL) {
        perror("\x1b[31mошибка: НЕ УДАЛОСЬ ОТКРЫТЬ ФАЙЛ\x1b[0m");
        exit(1);
    }

}

void  Fclose_and_checking(FILE* fp) {

    if (fclose(fp) == EOF) {
        perror("\x1b[31mошибка: НЕ УДАЛОСЬ ЗАКРЫТЬ ФАЙЛ\x1b[0m");
        exit(1);
    }

}

void  Fseek_and_checkingCUR(FILE* fp, int i) {

    if (fseek(fp, sizeof(char) * i, SEEK_CUR) != 0) {

        perror("\x1b[31mне удалось закрыть файл\x1b[0m");
        exit(1);
    }

}


void  Checking_memory_allocation(char* str) {

    if (str == NULL) {
        perror("\x1b[31mОшибка выделения памяти\x1b[0m");
        exit(1);
    }

}


void  Checking_memory_allocationPLAYER(struct PLAYER* str) {

    if (str == NULL) {
        perror("\x1b[31mОшибка выделения памяти\x1b[0m");
        exit(1);
    }

}