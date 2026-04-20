#include <stdio.h>
#include <locale.h>
#include"Checking.h"
#include"Main_menu.h"


int main(int argc, char** argv) {
    
    setlocale(LC_ALL, "");
    Checking_arguments(argc);
    char* filepath = argv[1];
    Main_menu(filepath);


    return 0;
}
