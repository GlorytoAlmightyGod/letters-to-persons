#include "code-decode.h"

void display_CODE_of_the_letter(int number_on_letter){
    int alphabet_index;
    printf("-------------LETTER %d-------------", number_on_letter);
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c in the encryption is %c in Reality.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(decrypt_the_alphabet(alphabet_index, number_on_letter), true));
        printf("\n");
    }
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%c in Reality is to be %c on the Encryption.", convert_to_alphabet(alphabet_index, true), convert_to_alphabet(encrypt_the_alphabet(alphabet_index, number_on_letter), true));
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    int encryption_number_on_letter;
    sscanf(argv[1], "%d", &encryption_number_on_letter);
    display_CODE_of_the_letter(encryption_number_on_letter);
    return 0;
}