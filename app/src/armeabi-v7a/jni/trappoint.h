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
 
//
// Created by Lukas on 8/6/2015.
//

#ifndef NDKTEST_TRAPPOINT_H
#define NDKTEST_TRAPPOINT_H


#include <stdint.h>

#include "../../main/jni/hooking/trappoint_interface.h"
#include "../../main/jni/util/list.h"
#include "abi.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct ThumbCodeInfo
{
    uint16_t preserved;
    uint16_t trap_instruction;
} ThumbCodeInfo;

typedef struct ArmCodeInfo
{
    uint32_t preserved;
    uint32_t trap_instruction;
} ArmCodeInfo;

struct TrapPointInfo
{
    HOOKCALLBACK handler;
    void*                   handler_args;

    struct InstructionInfo  target;

    uint32_t                instr_size;

    uint32_t                trapping_method;
    union
    {
        ThumbCodeInfo       thumbCode;
        ArmCodeInfo         armCode;
    };

    struct list_head        installed;
};

#ifdef __cplusplus
}
#endif

#endif //NDKTEST_TRAPPOINT_H

