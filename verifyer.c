#include "code-decode.h"

int main(void){


    char* name_of_raw_letter;
    name_of_raw_letter = "RAW-LETTER";
    char* name_of_decrypted_letter;
    name_of_decrypted_letter = "decrypted_letter";

    int length_of_letter = determine_length_of_letter(name_of_raw_letter);
    
    
    char raw_letter_text[length_of_letter];
    char* pointer_raw_letter_text;

    char decrypted_letter_text[length_of_letter];
    char* pointer_decrypted_letter_text;

    pointer_raw_letter_text = read_letter(name_of_raw_letter, raw_letter_text);
    pointer_decrypted_letter_text = read_letter(name_of_decrypted_letter, decrypted_letter_text);

    if(is_matching_validly(pointer_raw_letter_text, pointer_decrypted_letter_text, length_of_letter)){
        printf("\nSUCCESS\nEncryption READY in encrypted_letter for persons.\ndecrypted_letter matches with RAW-LETTER!\n");
    }
    else{
        /*shouldn't be happening!*/
        printf("FAILURE\nPlease Fix some incompatabilities between encryptor.c & decryptor.c!\n");
    }
    return 0;
}