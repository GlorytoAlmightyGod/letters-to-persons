#include "code-decode.h"

int main(int argc, char* argv[]){
    
    int encryption_number_on_letter;
    sscanf(argv[1], "%d", &encryption_number_on_letter);

    char* name_of_raw_letter;
    name_of_raw_letter = argv[2];

    char* name_of_encrypted_letter;
    name_of_encrypted_letter = argv[3];

    int length_of_letter = determine_length_of_letter(name_of_raw_letter);
    
    
    char raw_letter_text[length_of_letter];
    char* pointer_raw_letter_text;

    char encrypted_text[length_of_letter];
    char* pointer_encrypted_text;

    pointer_raw_letter_text = read_letter(name_of_raw_letter, raw_letter_text);
    pointer_encrypted_text = encrypt_the_letter(raw_letter_text, encrypted_text, length_of_letter, encryption_number_on_letter);
    write_letter(name_of_encrypted_letter, encrypted_text, length_of_letter);

    display_text(pointer_raw_letter_text, length_of_letter);
    display_text(pointer_encrypted_text, length_of_letter);



    return 0;
}
