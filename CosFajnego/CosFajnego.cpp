#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define CZERWONY   "\x1b[31m"
#define ZIELONY    "\x1b[32m"
#define NIEBIESKI  "\x1b[34m"
#define ZOLTY      "\x1b[33m"
#define PURPUROWY  "\x1b[35m"
#define CYJAN      "\x1b[36m"
#define BIALY      "\x1b[37m"
#define JASNY_CZERWONY "\x1b[91m"
#define JASNY_ZIELONY "\x1b[92m"
#define JASNY_NIEBIESKI "\x1b[94m"
#define RESET      "\x1b[0m"
#define DELAY 25
#define SIZE 15


void wypiszTablice(int** tablica) {
    system("cls");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            switch (tablica[i][j]) {
            case 1:
                printf(CZERWONY"%2d "RESET, tablica[i][j]);
                break;
            case 2:
                printf(ZIELONY"%2d "RESET, tablica[i][j]);
                break;
            case 3:
                printf(NIEBIESKI"%2d "RESET, tablica[i][j]);
                break;
            case 4:
                printf(ZOLTY"%2d "RESET, tablica[i][j]);
                break;
            case 5:
                printf(PURPUROWY"%2d "RESET, tablica[i][j]);
                break;
            case 6:
                printf(CYJAN"%2d "RESET, tablica[i][j]);
                break;
            case 7:
                printf(BIALY"%2d "RESET, tablica[i][j]);
                break;
            case 8:
                printf(JASNY_CZERWONY"%2d "RESET, tablica[i][j]);
                break;
            case 9:
                printf(JASNY_ZIELONY"%2d "RESET, tablica[i][j]);
                break;
            case 0:
                printf(JASNY_NIEBIESKI"%2d "RESET, tablica[i][j]);
                break;
            }
        }
        printf("\n");
    }
}

int main() {

    int wzorek[15][15] = {
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 5, 5, 1, 1, 1, 5, 5, 1, 1, 0, 0},
        {0, 1, 1, 5, 5, 5, 1, 1, 1, 5, 5, 5, 1, 1, 0},
        {1, 1, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 1, 1},
        {1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1},
        {1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1},
        {1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1},
        {1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1},
        {0, 1, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 0},
        {0, 0, 1, 1, 5, 5, 5, 5, 5, 5, 5, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 5, 5, 5, 5, 5, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 5, 5, 5, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 5, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0}
    };


    // Inicjalizacja generatora liczb pseudolosowych
    srand(time(NULL));

    // Alokacja dynamiczna pamiêci dla tablicy
    int** tablica = (int**)malloc(SIZE * sizeof(int*));
    for (int i = 0; i < SIZE; ++i) {
        tablica[i] = (int*)malloc(SIZE * sizeof(int));
    }

    // Wype³nianie tablicy losowymi liczbami od 0 do 9
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            tablica[i][j] = (rand() % 9) +1;
        }
    }

    // Wyœwietlenie tablicy
    wypiszTablice(tablica);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            while (tablica[i][j] != wzorek[i][j]) {
                if (tablica[i][j] == 9) {
                    Sleep(DELAY);
                    tablica[i][j] = 0;
                    wypiszTablice(tablica);
                    
                } else {
                    Sleep(DELAY);
                    tablica[i][j]++;
                    wypiszTablice(tablica);
                }
            }
        }
    }

    // Zwolnienie zaalokowanej pamiêci
    for (int i = 0; i < SIZE; ++i) {
        free(tablica[i]);
    }
    free(tablica);

    return 0;
}
