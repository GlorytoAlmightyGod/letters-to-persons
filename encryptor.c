#include "code-decode.h"

int main(void){

    char* name_of_raw_letter;
    name_of_raw_letter = "RAW-LETTER";
    char* name_of_encrypted_letter;
    name_of_encrypted_letter = "encrypted_letter";

    int length_of_letter = determine_length_of_letter(name_of_raw_letter);
    
    
    char raw_letter_text[length_of_letter];
    char* pointer_raw_letter_text;

    char encrypted_text[length_of_letter];
    char* pointer_encrypted_text;

    pointer_raw_letter_text = read_letter(name_of_raw_letter, raw_letter_text);
    pointer_encrypted_text = encrypt_the_letter(raw_letter_text, encrypted_text, length_of_letter, ENCRYPTION_NUMBER_ON_LETTER);
    write_letter(name_of_encrypted_letter, encrypted_text, length_of_letter);

    display_text(pointer_raw_letter_text, length_of_letter);
    display_text(pointer_encrypted_text, length_of_letter);



    return 0;
}
