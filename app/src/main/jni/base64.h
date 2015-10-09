#ifndef __BASE64__H
#define __BASE64__H

char *AES_base64_encode(const unsigned char *data, int data_len);

unsigned char *AES_base64_decode(int *ret_len, const char *data, int data_len);

#endif
