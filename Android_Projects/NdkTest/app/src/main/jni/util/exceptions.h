/*
 * Copyright 2016 Lukas Dresel
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

#include <jni.h>
#include <stdbool.h>

bool hasExceptionOccurred(JNIEnv *env);

void throwNewJNIException(JNIEnv *env, const char *classNameNotSignature, const char *message);

#define RETURN_ON_EXCEPTION(env, cleanup, defReturn) \
    do { \
        if(hasExceptionOccurred((env))) { \
        do { \
            cleanup \
           } while (0); \
        return defReturn; \
        } } while(0);


#endif





