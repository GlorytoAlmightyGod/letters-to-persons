#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXIMUM_SIZE 10000
size_t letter_size = 0;

char raw_letter_text[MAXIMUM_SIZE];
char encrypted_letter_text[MAXIMUM_SIZE];
char decrypted_encrypted_letter_text[MAXIMUM_SIZE];

char convert_to_alphabet(int my_number, bool upper_case){
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

void display_decryption_encryption_of_the_letter(int number_on_letter){
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


void read_raw_letter(int number_on_letter){
    FILE *file = fopen("raw_letter", "r");
    int my_alphabet;
    letter_size = 0;
    while ((my_alphabet = fgetc(file)) != EOF){
        raw_letter_text[letter_size++] = (char) my_alphabet;
    }
    raw_letter_text[letter_size] = '\0';
}

void encrypt_the_letter(int number_on_letter){
    int my_index;
    for(my_index = 0; my_index < letter_size; my_index++){
        char my_character = raw_letter_text[my_index];
        int my_number = my_character;
        if(my_number >= 65 && my_number <= 90){
            encrypted_letter_text[my_index] = convert_to_alphabet(encrypt_the_alphabet(my_number - 64, number_on_letter), true);
        }
        else if(my_number >= 97 && my_number <= 122){
            encrypted_letter_text[my_index] = convert_to_alphabet(encrypt_the_alphabet(my_number - 96, number_on_letter), false);
        }
        else{
            encrypted_letter_text[my_index] = raw_letter_text[my_index];
        }
    }
    encrypted_letter_text[my_index] = '\0';
}

void write_encrypted_letter(int number_on_letter){
    FILE *file = fopen("encrypted_letter", "w+");
    int return_val = fputs(encrypted_letter_text, file);
}


void read_encrypted_letter(int number_on_letter){
    FILE *file = fopen("encrypted_letter", "r");
    int my_alphabet;
    letter_size = 0;
    while ((my_alphabet = fgetc(file)) != EOF){
        encrypted_letter_text[letter_size++] = (char) my_alphabet;
    }
    encrypted_letter_text[letter_size] = '\0';
}

void decrypt_the_encrypted_letter(int number_on_letter){

}
void write_decrypted_encrypted_letter(int number_on_letter){
    FILE *file = fopen("decrypted_encrypted_letter", "w+");
    int return_val = fputs(decrypted_encrypted_letter_text, file);
}

void verify_decrypted_letter_with_raw_letter(int number_on_letter){

}



int main(void){
    int number_on_letter = 751;

    /*display_decryption_encryption_of_the_letter(number_on_letter);*/

    read_raw_letter(number_on_letter);
    encrypt_the_letter(number_on_letter);
    write_encrypted_letter(number_on_letter);
    read_encrypted_letter(number_on_letter);
    decrypt_the_encrypted_letter(number_on_letter);

    return 0;
}
