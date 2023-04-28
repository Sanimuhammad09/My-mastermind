
#include "my_mastermind.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
int myStrcmp(char *first, char *second){
    int i = 0;
    while (first[i] != '\0' && second[i] != '\0' && first[i] == second[i]){
        i++;
    }
    return first[i]-second[i];
}
int my_is_digit(char* alpha){
    int i = 0;
    while (alpha[i] != '\0'){
        if (alpha[i] >= 48 && alpha[i] <= 55){
            i++;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int my_length(char* a){
    int length = 0;
    while (a[length] != '\0'){
        length++;
    }
    return length;
}
int random_number(int min, int max){
    int result = 0;
    int low = 0;
    int hi = 0;
    low = min;
    hi = max + 1;
    srand(time(NULL));
    result = (rand() % (hi-low)) + low;
    return result;
}

int main (int argc, char *argv[]){
    int rounds;
    char *secret_code = malloc(6);
    int well=0;
    int miss=0;
    char dat[100];
    int w;
    printf("Will you find the secret code?\nPlease enter a valid guess\n---\nRound 0\n");
    if(argc==5){
        if(myStrcmp(argv[1], "-c")==0 && my_is_digit(argv[2]) && myStrcmp(argv[3], "-t")==0 && my_is_digit(argv[4])){
            secret_code = argv[2];
            rounds = atoi(argv[4]);
        }
    }
    if(argc==3){
        if(myStrcmp(argv[1], "-c")==0 && my_is_digit(argv[2])){
            secret_code = argv[2];
            rounds = 10;
        }
        if(myStrcmp(argv[1], "-t")==0 && my_is_digit(argv[2])){
            rounds = atoi(argv[2]);
        }
    }
    if (argc==1){
        rounds = 10;
        *secret_code = random_number(1000, 7777);
    }
    for (w = 1; w <= rounds; w++) {
        read(0,dat,5);
        int f = 0;
        while (dat[f] !='\n'){
            if(dat[f]== secret_code[f] && dat[f] >= 30  && dat[f]<=55){
                well++;
            }
            int g=0;
            while(secret_code[g]!='\0'){
                if(f != g && dat[f]==secret_code[g] && dat[f] >= 30  && dat[f]<=55){
                    miss++;
                }
                g++;
            }
            f++;
        }
        if(well==4){
            printf("Congratz! You did it!\n");
            break;
        }
        if (dat[f]=='\n'){
            return -1;
        }
        printf("Well placed pieces: %d\nMisplaced pieces: %d\n---\nRound %d\n",well,miss, w);
        well = miss =0;
    }
    if (w>rounds){
        printf("You didn't get the answer try again some other time\n");
    }
}