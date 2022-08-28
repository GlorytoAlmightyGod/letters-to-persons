#include "code-decode.h"

void display_CODE_of_the_letter(int number_on_letter){
    int alphabet_index;
    printf("-------------LETTER %d-------------", number_on_letter);
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c in encrypted_letter is %c in RAW-LETTER.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(decrypt_the_alphabet(alphabet_index, number_on_letter), true));
        printf("\n");
    }
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c in RAW-LETTER is to be %c on encrypted_letter.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(encrypt_the_alphabet(alphabet_index, number_on_letter), true));
        printf("\n");
    }
    printf("\n");
}

int main(void){
    display_CODE_of_the_letter(ENCRYPTION_NUMBER_ON_LETTER);
    return 0;
}