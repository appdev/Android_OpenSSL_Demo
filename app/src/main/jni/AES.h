#ifndef __SHAREGROUP_AES_H
#define __SHAREGROUP_AES_H

int S_AES_Encode(char **strOut, const char *strIn, const unsigned char *key,
                 const unsigned char *iv);

int S_AES_Decode(char **strOut, const char *strIn, const unsigned char *key,
                 const unsigned char *iv);


#endif