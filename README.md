# PURPOSE
_THIS_ Repository(Project) is created for the PURPOSE of ENCRYPTION.
Encrypting simple letters we want to send persons such as Family and Friends.
It is designed in a way to facilitate ease of encrypting any piece of written text.

# USAGE Guidelines

**Environment**
Linux environment is recommended as _THIS_ Project consists of shell scripts.
Manually Compiling .c files can also be accomplished by taking a peek in **clean_up** & **run_me_please**.

**Installation**
It is pretty straightforward.
STEP 1 : Download _THIS_ repository onto the system using the following command on the terminal.
**git clone https://GlorytoAlmightyGod@github.com/GlorytoAlmightyGod/letters-to-persons**

STEP 2 : Once the Cloning is complete. Change the working directory to the aforementioned repository by the following command.
**cd letters-to-persons**

STEP 3 : Grant Execution permissions to the following files.
clean_up & run_me_please
_THIS_ can be done by the following commands on the terminal.
PLEASE check the content in the files in case of TRUST-PROBLEMS from the Author.
**chmod +x clean_up**
**chmod +x run_me_please**
Once done, Congratulations, you have successfully completed the installation phase.


**Running**
STEP 1 : Create the RAW-LETTER.
**_(Type or) Paste and then Save the message you want to encrypt for the persons in the file RAW-LETTER._**
# PLEASE MAKE SURE THAT THERE ARE BLANK LINES at the end of the _THIS FILE_.
_THIS_ STEP requires manual intervention as it is specific to each person-what they would choose to encrypt.

STEP 2 : Execute the run_me_please with the following command.
**./run_me_please**
When Prompted, Enter any number that you would like to give as an INPUT_FOR_FORMULA to perform Encryption.

**ACCESSING the ENCRYPTED_LETTER**
SIMPLY OPEN the encrypted_letter file which is generated post-run.
Copy the content and send it to the person who is to decipher what you are trying to say through the letter.


# WORKING




# CONTRIBUTING

Make sure to execute the clean_up script before performing any commits.
The aforesaid can be accomplished by simply executing the following command on the terminal.
**./clean_up**

Here(raw_letter), i will be writing the actual text message i would like persons to know.
this(encrypted_letter) will be written by the encryptor_decryptor.c file using the raw_letter file as the input.
this letter(decrypted_encrypted_letter) will be generated using the encryptor_decryptor.c file taking encrypted_letter as the input.
decrypted_encrypted_letter is to be the exact replica of the raw_letter.
