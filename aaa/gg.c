#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <time.h> 
 
int my_strlen(char* str) 
{ 
    int i = 0; 
    while (str[i++]); 
 
    return --i; 
} 
 
int str_char(char* str, char letter) 
{ 
    for (int i = 0; i < my_strlen(str); i++) 
    { 
        if (str[i] == letter) return 0; 
    } 
    return 1;    
} 
 
void my_str_cpy(char* dest, char* source) 
{ 
    for (int i = 0; i < my_strlen(source); i++) dest[i] = source[i]; 
} 
 
int my_strcmp(char* p1, char* p2) 
{ 
    for (int i = 0; i < p1[i] || p2[i] ;i++) 
    { 
        if (p1[i] != p2[i]) return 1; 
    } 
    return 0; 
} 
 
int is_digit(char letter) 
{ 
    if (letter >= '0' && letter <= '8') return 1; 
    return 0; 
} 
 
int check_for_digit(char* input) 
{ 
    for (int i = 0; i < my_strlen(input); i++) 
    { 
        if (is_digit(input[i]) == 0) return 0; 
    } 
    return 1; 
} 
 
int chech_for_dupl(char* input) 
{ 
    for (int i  = 0; i < my_strlen(input); i++) 
    { 
        for (int j = i + 1; j < my_strlen(input); j++) 
        { 
            if (input[i] == input[j]) return 0; 
        } 
    } 
    return 1; 
} 
 
int well_placed(char* str, char* secret_code) 
{ 
    int counter = 0; 
    for (int i = 0; i < my_strlen(str); i++) 
    { 
        if (str[i] == secret_code[i]) counter++; 
    } 
    return counter; 
} 
 
int mis_placed(char* input, char* secret_code) 
{ 
    int counter = 0; 
    for (int i = 0; i < my_strlen(input); i++) 
    { 
        if (input[i] != secret_code[i]) 
        { 
            for (int j = 0; j < my_strlen(secret_code); j++) 
            { 
                if (input[i] == secret_code[j]) counter++; 
            } 
        } 
    } 
    return counter; 
} 
 
char* my_scanf() 
{ 
    char* str = calloc(10, sizeof(char)); 
    int i = 0; 
    char temp; 
    char prompt = '>'; 
    write (1, &prompt, 1); 
    fflush(stdout); 
    while(read(0, &temp, 1)) 
    { 
        if (temp == '\n') return str; 
        str[i++] = temp;  
    } 
    return NULL; 
} 
 
int* check_for_wi(char* input, char* secret_code) 
{ 
    if (my_strlen(input) != 4 || check_for_digit(input) == 0 || chech_for_dupl(input) == 0) return 0; 
    int* well_mis = calloc(3, sizeof(int)); 
    well_mis[0] = well_placed(input, secret_code); 
    well_mis[1] = mis_placed(input, secret_code); 
 
    return well_mis; 
} 
 
char* random_code_generate() 
{ 
    char* code = calloc(5, sizeof(char)); 
    srand(time(0)); 
    int i = 0; 
    char temp; 
    while (i < 4) 
    { 
        temp = rand() % 9 + 48; 
        if (str_char(code,temp) == 1) code[i++] = temp; 
    } 
 
    return code; 
} 
 
void game_round(int index) 
{ 
    printf("---\nRound %d\n", index); 
} 
 
void game_func(char* secret_code, int attempts) 
{ 
    printf("Will you find the secret code?\nPlease enter a valid guess\n"); 
    char* input; 
    int* arr; 
    for (int i = 0; i < attempts; i++) 
    { 
        printf("---\nRound %d\n", i); 
        input = my_scanf(); 
        if (input == NULL) return; 
        arr = check_for_wi(input, secret_code); 
        if (arr != 0 && arr[0] == 4) { 
            printf("Congratz! You did it!\n"); 
            return; 
        } 
        while (arr == 0) 
        { 
            free(input); 
            printf("Wrong input!\n"); 
            input = my_scanf(); 
            arr = check_for_wi(input, secret_code); 
            if (arr != 0 && arr[0] == 4) { 
                printf("Congratz! You did it!\n"); 
                return; 
            } 
        } 
        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", arr[0], arr[1]); 
        free(arr); 
        free(input); 
    } 
    // free(secret_code); 
    // free(arr); 
} 
 
int main(int argc, char** argv) 
{    
    if (argc == 0) return 1; 
    char* secret_code ; 
    int attempts = 10; 
    int code_flag = 0; 
    for (int i = 0; i < argc; i++) 
    { 
        if (my_strcmp(argv[i], "-c") == 0) 
        { 
            secret_code = calloc(5, sizeof(char)); 
            my_str_cpy(secret_code, argv[++i]);  
            code_flag++;
        }else if (my_strcmp(argv[i], "-t") == 0) attempts = atoi(argv[++i]);
    }
    if (code_flag == 0) secret_code = random_code_generate();game_func(secret_code, attempts);
    free(secret_code);    
    return 0;
}