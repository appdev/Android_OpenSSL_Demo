/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include "com_apkdv_openssl_AES.h"
#include "AES.h"


/* 宏定义begin */
//清0宏
#define MEM_ZERO(pDest, destSize) memset(pDest, 0, destSize)

#define LOG_TAG "onEvent"

const char *iv = "1234567890123456";

const char *key = "ABCDEFGHIJKLMNOP";


JNIEXPORT jstring JNICALL Java_com_apkdv_openssl_Tools_StringFromJNI(JNIEnv *env, jobject thiz) {


    return (*env)->NewStringUTF(env, "Hello from JNI !");
}


JNIEXPORT jstring JNICALL Java_com_apkdv_openssl_Tools_Encode
        (JNIEnv *env, jobject thiz, jstring strIn) {


    const char const *str = (*env)->GetStringUTFChars(env, strIn, NULL);

    char *strOut = NULL;

    char s_key[AES_BLOCK_SIZE + 1];

    char s_iv[AES_BLOCK_SIZE + 1];


    strcpy(s_key, key);

    strcpy(s_iv, iv);

    int len = S_AES_Encode(&strOut, str, (const unsigned char *) key, (const unsigned char *) iv);

    (*env)->ReleaseStringUTFChars(env, strIn, str);

    if (len > 0) {
        jstring jOut = (*env)->NewStringUTF(env, strOut);

        free(strOut);

        return jOut;
    }

    return (*env)->NewStringUTF(env, "");
}

JNIEXPORT jstring JNICALL Java_com_apkdv_openssl_Tools_Decode
        (JNIEnv *env, jobject thiz, jstring strIn) {


    const char const *str = (*env)->GetStringUTFChars(env, strIn, NULL);
    char s_key[AES_BLOCK_SIZE + 1];

    char s_iv[AES_BLOCK_SIZE + 1];


    strcpy(s_key, key);

    strcpy(s_iv, iv);


    char *strOut = NULL;

    int len = S_AES_Decode(&strOut, str, (const unsigned char *) s_key,
                           (const unsigned char *) s_iv);


    (*env)->ReleaseStringUTFChars(env, strIn, str);

    if (len > 0) {
        jstring jOut = (*env)->NewStringUTF(env, strOut);

        free(strOut);

        return jOut;
    }

    return (*env)->NewStringUTF(env, "");
}

