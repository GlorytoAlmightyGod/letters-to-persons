#include "code-decode.h"

int main(void){

    char* name_of_encrypted_letter;
    name_of_encrypted_letter = "encrypted_letter";
    char* name_of_decrypted_letter;
    name_of_decrypted_letter = "decrypted_letter";

    int length_of_letter = determine_length_of_letter(name_of_encrypted_letter);
    
    
    char encrypted_letter_text[length_of_letter];
    char* pointer_encrypted_letter_text;

    char decrypted_text[length_of_letter];
    char* pointer_decrypted_text;

    pointer_encrypted_letter_text = read_letter(name_of_encrypted_letter, encrypted_letter_text);
    pointer_decrypted_text = decrypt_the_letter(encrypted_letter_text, decrypted_text, length_of_letter, ENCRYPTION_NUMBER_ON_LETTER);
    write_letter(name_of_decrypted_letter, decrypted_text, length_of_letter);

    display_text(pointer_encrypted_letter_text, length_of_letter);
    display_text(pointer_decrypted_text, length_of_letter);



    return 0;
}
