#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10
#define MAX_MATERIAL_LEN 20

typedef struct Cornice {
    int length;
    int ceilingWidth;
    int wallHeight;
    char material[MAX_MATERIAL_LEN];
} cornice_t;

int getRandomNumber(int min, int max);
void generateRandomString(char *buffer, int maxLen);
void fill_array(cornice_t *cornices, int size);
void print_cornice(cornice_t cornice);
void print_array(cornice_t *cornices, int size);

int main(void) {
    cornice_t cornices[SIZE];
    srand((unsigned int)time(NULL));

    fill_array(cornices, SIZE);
    print_array(cornices, SIZE);

    return 0;
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generateRandomString(char *buffer, int maxLen) {
    static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length = getRandomNumber(4, maxLen - 1);

    for (int i = 0; i < length; i++) {
        buffer[i] = alphabet[rand() % (int)(sizeof(alphabet) - 1)];
    }
    buffer[length] = '\0';
}

void fill_array(cornice_t *cornices, int size) {
    for (int i = 0; i < size; i++) {
        cornices[i].length = getRandomNumber(1, 10);
        cornices[i].ceilingWidth = getRandomNumber(1, 5);
        cornices[i].wallHeight = getRandomNumber(2, 8);
        generateRandomString(cornices[i].material, MAX_MATERIAL_LEN);
    }
}

void print_cornice(cornice_t cornice) {
    printf("| %d || %d || %d || %s |\n",
           cornice.length,
           cornice.ceilingWidth,
           cornice.wallHeight,
           cornice.material);
}

void print_array(cornice_t *cornices, int size) {
    for (int i = 0; i < size; i++) {
        print_cornice(cornices[i]);
    }
}