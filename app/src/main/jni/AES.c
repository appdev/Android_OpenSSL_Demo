#include "AES.h"
#include "base64.h"


#include <stdio.h>
#include <stdlib.h>


#include <openssl/aes.h>


void logAES() {
    AES_KEY aes;
    unsigned char key[AES_BLOCK_SIZE];        // AES_BLOCK_SIZE = 16
    unsigned char iv[AES_BLOCK_SIZE];        // init vector
    unsigned char *input_string;
    unsigned char *encrypt_string;
    unsigned char *decrypt_string;
    unsigned int len;        // encrypt length (in multiple of AES_BLOCK_SIZE)
    unsigned int i;

    char data[100];

    // AES_WriteMyLog("test");

    strcpy(data, "hello");

    // set the encryption length
    len = 0;
    if ((strlen(data) + 1) % AES_BLOCK_SIZE == 0) {
        len = strlen(data) + 1;
    } else {
        len = ((strlen(data) + 1) / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;
    }

    // set the input string
    input_string = (unsigned char *) calloc(len, sizeof(unsigned char));
    if (input_string == NULL) {
        //fprintf(stderr, "Unable to allocate memory for input_string\n");
        //exit(-1);
    }
    strncpy((char *) input_string, data, strlen(data));

    // Generate AES 128-bit key
    for (i = 0; i < 16; ++i) {
        key[i] = /*32*/ 'A' + i;
    }

    // Set encryption key
    /* for (i=0; i<AES_BLOCK_SIZE; ++i) {
     iv[i] = 0;
     }*/

    strcpy((char *) iv, "1234567890123456");

    if (AES_set_encrypt_key(key, 128, &aes) < 0) {
        //fprintf(stderr, "Unable to set encryption key in AES\n");
        //exit(-1);
    }

    // alloc encrypt_string
    encrypt_string = (unsigned char *) calloc(len, sizeof(unsigned char));
    if (encrypt_string == NULL) {
        //fprintf(stderr, "Unable to allocate memory for encrypt_string\n");
        //exit(-1);
    }

    // encrypt (iv will change)
    AES_cbc_encrypt(input_string, encrypt_string, len, &aes, iv, AES_ENCRYPT);

    // __android_log_print(ANDROID_LOG_INFO, "JNITag", "aes encrypted string = %s", encrypt_string);
    /* for (i=0; i<len; ++i) {
         __android_log_print(ANDROID_LOG_INFO, "JNITag", "%x%x", (encrypt_string[i] >> 4) & 0xf,
                             encrypt_string[i] & 0xf);
     }*/


    // __android_log_print(ANDROID_LOG_INFO, "JNITag","%.2X", *(src + i));

    /*
     
     // alloc decrypt_string
     decrypt_string = (unsigned char*)calloc(len, sizeof(unsigned char));
     if (decrypt_string == NULL) {
     //fprintf(stderr, "Unable to allocate memory for decrypt_string\n");
     //exit(-1);
     }
     
     // Set decryption key
     for (i=0; i<AES_BLOCK_SIZE; ++i) {
     iv[i] = 0;
     }
     if (AES_set_decrypt_key(key, 128, &aes) < 0) {
     //fprintf(stderr, "Unable to set decryption key in AES\n");
     //exit(-1);
     }
     
     // decrypt
     AES_cbc_encrypt(encrypt_string, decrypt_string, len, &aes, iv,
     AES_DECRYPT);
     
     // print
     printf("input_string = %s\n", input_string);
     printf("encrypted string = ");
     for (i=0; i<len; ++i) {
     printf("%x%x", (encrypt_string[i] >> 4) & 0xf,
     encrypt_string[i] & 0xf);
     }
     printf("\n");
     printf("decrypted string = %s\n", decrypt_string);
     
     */
}

//HEy8VunMxTT9r4zQd5QsNA==

int S_AES_Encode(char **strOut, const char *strIn, const unsigned char *key,
                 const unsigned char *iv) {
    AES_KEY aes;
    unsigned char vkey[AES_BLOCK_SIZE + 1];        // AES_BLOCK_SIZE = 16
    unsigned char viv[AES_BLOCK_SIZE + 1];        // init vector
    unsigned char *input_string;
    unsigned char *encrypt_string;
    //unsigned char* decrypt_string;
    unsigned int len;        // encrypt length (in multiple of AES_BLOCK_SIZE)

    len = 0;


    memcpy(vkey, key, AES_BLOCK_SIZE);

    memcpy(viv, iv, AES_BLOCK_SIZE);

    if ((strlen(strIn) + 1) % AES_BLOCK_SIZE == 0) {
        len = strlen(strIn) + 1;
    } else {
        len = ((strlen(strIn) + 1) / AES_BLOCK_SIZE + 1) * AES_BLOCK_SIZE;
    }


    // set the input string
    input_string = (unsigned char *) calloc(len + 1, sizeof(unsigned char));
    if (input_string == NULL) {
        //fprintf(stderr, "Unable to allocate memory for input_string\n");
        //exit(-1);
        return 0;
    }


    strncpy((char *) input_string, strIn, strlen(strIn));


    if (AES_set_encrypt_key(vkey, 128, &aes) < 0) {
        //fprintf(stderr, "Unable to set encryption key in AES\n");
        //exit(-1);
        return 0;
    }


    // alloc encrypt_string
    encrypt_string = (unsigned char *) calloc(len + 1, sizeof(unsigned char));
    if (encrypt_string == NULL) {
        //fprintf(stderr, "Unable to allocate memory for encrypt_string\n");
        //exit(-1);
        return 0;
    }



    // encrypt (iv will change)
    AES_cbc_encrypt(input_string, (unsigned char *) encrypt_string, len, &aes,
                    (unsigned char *) viv, AES_ENCRYPT);


    *strOut = AES_base64_encode(encrypt_string, len);


    return strlen(*strOut);
}

int S_AES_Decode(char **strOut, const char *strIn, const unsigned char *key,
                 const unsigned char *iv) {

    AES_KEY aes;
    //unsigned char key[AES_BLOCK_SIZE];        // AES_BLOCK_SIZE = 16
    //unsigned char iv[AES_BLOCK_SIZE];        // init vector
    unsigned char *input_string;
    unsigned char *encrypt_string;
    //unsigned char* decrypt_string;
    unsigned int len;        // encrypt length (in multiple of AES_BLOCK_SIZE)

    len = 0;

    unsigned char *data = AES_base64_decode(&len, strIn, strlen(strIn));

    if (AES_set_decrypt_key(key, 128, &aes) < 0) {
        //fprintf(stderr, "Unable to set decryption key in AES\n");
        //exit(-1);
        return 0;
    }

    *strOut = (unsigned char *) calloc(len, sizeof(unsigned char));
    if (*strOut == NULL) {
        //fprintf(stderr, "Unable to allocate memory for input_string\n");
        //exit(-1);
        return 0;
    }


    AES_cbc_encrypt(data, (unsigned char *) (*strOut), len, &aes, (unsigned char *) iv,
                    AES_DECRYPT);

    len = strlen((char *) (*strOut));

    return len;
}