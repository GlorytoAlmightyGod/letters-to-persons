#include <stdio.h>
#define ENCRYPTION_NUMBER_ON_LETTER 14

typedef enum { false, true } boolean;

char convert_to_alphabet(int my_number, boolean upper_case){
    char my_alphabet; 
    if(upper_case){
        my_alphabet =  my_number + 64;
    }
    else{
        my_alphabet =  my_number + 96;
    }
    return my_alphabet;
}

int decrypt_the_alphabet(int rank_of_an_aphabet, int number_on_letter){
    return ((rank_of_an_aphabet - 1 + number_on_letter)%26 + number_on_letter)%26 + 1;
}
int encrypt_the_alphabet(int rank_of_an_aphabet, int number_on_letter){
    int alphabet_index;
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        if(decrypt_the_alphabet(alphabet_index, number_on_letter) == rank_of_an_aphabet){
            return alphabet_index;
        }
    }
    /*IF i am seeing THIS, THEN ONE-TO-ONE MAP of set of alphabets is NOT being satisfied!*/
    printf("PLEASE Correct the Decrypt-Formula.%d", rank_of_an_aphabet);
    return -1;
}

int determine_length_of_letter(char filename[]){
    FILE *file = fopen(filename, "r");
    int my_alphabet, my_index = -1;
    while ((my_alphabet = fgetc(file)) != EOF){
        my_index++;
    }
    fclose(file);
    return my_index;
}

char* read_letter(char filename[], char text[]){
    FILE *file = fopen(filename, "r");
    int my_alphabet, my_index = 0;
    while ((my_alphabet = fgetc(file)) != EOF){
        text[my_index++] = (char) my_alphabet;
    }
    fclose(file);
    return text;
}

char* encrypt_the_letter(char input_text[], char output_text[], int length_of_input_text, int encryption_number){
    for(int my_index = 0; my_index < length_of_input_text; my_index++){
        char my_character = input_text[my_index];
        int my_number = my_character;
        if(my_number >= 65 && my_number <= 90){
            output_text[my_index] = convert_to_alphabet(encrypt_the_alphabet(my_number - 64, encryption_number), true);
        }
        else if(my_number >= 97 && my_number <= 122){
            output_text[my_index] = convert_to_alphabet(encrypt_the_alphabet(my_number - 96, encryption_number), false);
        }
        else{
            output_text[my_index] = my_character;
        }
    }
    return output_text;
}

char* decrypt_the_letter(char input_text[], char output_text[], int length_of_input_text, int encryption_number){
    for(int my_index = 0; my_index < length_of_input_text; my_index++){
        char my_character = input_text[my_index];
        int my_number = my_character;
        if(my_number >= 65 && my_number <= 90){
            output_text[my_index] = convert_to_alphabet(decrypt_the_alphabet(my_number - 64, encryption_number), true);
        }
        else if(my_number >= 97 && my_number <= 122){
            output_text[my_index] = convert_to_alphabet(decrypt_the_alphabet(my_number - 96, encryption_number), false);
        }
        else{
            output_text[my_index] = my_character;
        }
    }
    return output_text;
}

void write_letter(char filename[], char text[], int length_of_text){
    FILE *file = fopen(filename, "w+");
    fwrite(text, length_of_text, 1, file);
}

void display_text(char text[], int length_of_text){
    for(int my_index = 0; my_index < length_of_text;my_index++){
        printf("%c", text[my_index]);
    }
    printf("\n");
    printf("\n");
}

void display_CODE_of_the_letter(int number_on_letter){
    int alphabet_index;
    printf("-------------LETTER %d-------------", number_on_letter);
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c in encrypted_letter is %c in raw_letter.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(decrypt_the_alphabet(alphabet_index, number_on_letter), true));
        printf("\n");
    }
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c in raw_letter is to be %c on encrypted_letter.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(encrypt_the_alphabet(alphabet_index, number_on_letter), true));
        printf("\n");
    }
    printf("\n");
}