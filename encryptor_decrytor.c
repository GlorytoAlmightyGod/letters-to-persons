#include <stdio.h>



int decrypt(int rank_of_an_aphabet, int number_on_letter){
    return ((rank_of_an_aphabet - 1 + number_on_letter*number_on_letter)%26 + number_on_letter)%26 + 1;
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

void display_decryption_of_the_letter(int current_letter_number){

}
void display_decryption_encryption_of_the_letter(int current_letter_number){
    int alphabet_index;
    printf("-------------LETTER %d-------------", current_letter_number);
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%d on THIS_LETTER is %d in Reality.", alphabet_index, decrypt(alphabet_index, current_letter_number));
        printf("\n");
    }
    printf("\n");
    for(alphabet_index = 1 ; alphabet_index <= 26 ; alphabet_index++){
        printf("%d in Reality is %d on THIS_LETTER.", alphabet_index, encrypt(alphabet_index, current_letter_number));
        printf("\n");
    }
    printf("\n");
}

int main(void){
    display_decryption_encryption_of_the_letter(30);
    return 0;
}
