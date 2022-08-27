#include <stdio.h>
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

int decrypt(int rank_of_an_aphabet, int number_on_letter){
    return ((rank_of_an_aphabet - 1 + number_on_letter)%26 + number_on_letter)%26 + 1;
}
int encrypt(int rank_of_an_aphabet, int number_on_letter){
    int alphabet_index;
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        if(decrypt(alphabet_index, number_on_letter) == rank_of_an_aphabet){
            return alphabet_index;
        }
    }
    /*IF i am seeing THIS, THEN ONE-TO-ONE MAP of set of alphabets is NOT being satisfied!*/
    printf("PLEASE Correct the Decrypt-Formula.");
    return -1;
}

void display_decryption_encryption_of_the_letter(int current_letter_number){
    int alphabet_index;
    printf("-------------LETTER %d-------------", current_letter_number);
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c on ENCRYPTED_LETTER is %c in Reality.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(decrypt(alphabet_index, current_letter_number), true));
        printf("\n");
    }
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c in Reality is to be %c on ENCRYPTED_LETTER.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(encrypt(alphabet_index, current_letter_number), true));
        printf("\n");
    }
    printf("\n");
}

int main(void){
    display_decryption_encryption_of_the_letter(2);
    return 0;
}
