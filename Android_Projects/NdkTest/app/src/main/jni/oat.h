//
// Created by Lukas on 8/16/2015.
//

#ifndef NDKTEST_OAT_H
#define NDKTEST_OAT_H

#include <stdint.h>
#include <stdbool.h>

typedef enum OatClassType {
    kOatClassAllCompiled = 0,   // OatClass is followed by an OatMethodOffsets for each method.
    kOatClassSomeCompiled = 1,  // A bitmap of which OatMethodOffsets are present follows the OatClass.
    kOatClassNoneCompiled = 2,  // All methods are interpretted so no OatMethodOffsets are necessary.
    kOatClassMax = 3,
} OatClassType;

typedef enum InstructionSet
{
    kNone,
    kArm,
    kArm64,
    kThumb2,
    kX86,
    kX86_64,
    kMips,
    kMips64
} InstructionSet;

typedef enum InstructionSetFeatures
{
    kHwDiv  = 0x1,              // Supports hardware divide.
    kHwLpae = 0x2,              // Supports Large Physical Address Extension.
} InstructionSetFeatures;

typedef struct OatHeader
{
    uint8_t                 magic_[4];
    uint8_t                 version_[4];
    uint32_t                adler32_checksum_;
    InstructionSet          instruction_set_;
    InstructionSetFeatures  instruction_set_features_;
    uint32_t                dex_file_count_;
    uint32_t                executable_offset_;
    uint32_t                interpreter_to_interpreter_bridge_offset_;
    uint32_t                interpreter_to_compiled_code_bridge_offset_;
    uint32_t                jni_dlsym_lookup_offset_;
    uint32_t                portable_imt_conflict_trampoline_offset_;
    uint32_t                portable_resolution_trampoline_offset_;
    uint32_t                portable_to_interpreter_bridge_offset_;
    uint32_t                quick_generic_jni_trampoline_offset_;
    uint32_t                quick_imt_conflict_trampoline_offset_;
    uint32_t                quick_resolution_trampoline_offset_;
    uint32_t                quick_to_interpreter_bridge_offset_;
    // The amount that the image this oat is associated with has been patched.
    int32_t                 image_patch_delta_;
    uint32_t                image_file_location_oat_checksum_;
    uint32_t                image_file_location_oat_data_begin_;
    uint32_t                key_value_store_size_;
    uint8_t                 key_value_store_[0];  // note variable width data at end
} OatHeader;

const char* oat_header_GetStoreValueByKey(OatHeader* this, const char* key);
bool oat_header_GetStoreKeyValuePairByIndex(OatHeader* this, size_t index, const char** key, const char** value);
size_t oat_header_GetHeaderSize(OatHeader* this);

#endif //NDKTEST_OAT_H
