#ifndef __CSTRING_H_INCLUDED__
#define __CSTRING_H_INCLUDED__

#include "sds/sds.c"

typedef struct string_s {
    char* buf;
    size_t length;
    char** tokens;
    int tokenCount;
} string, String;

const char Path_AltDirectorySeparatorChar = '/';
const char Path_DirectorySeparatorChar = '\\';
const char Path_PathSeparator = ';';
const char Path_VolumeSeparatorChar = ':';

String String_NewFromEmpty();
String String_NewFromBuffer(const char* input);
String String_Free(String* str);
void String_ToUpper(char* dst, const char* input);
void String_ToUpperAssignment(String* input);
void String_ToLower(char* dst, const char* input);
void String_ToLowerAssignment(String* input);
void String_CopyTo(String* src, String* dst, int length);
String String_Split(String* str, const char* delimiter);
void String_FreeSplits(String* splits);
String String_Join(char** argv, int argc, char* delimiter);

#endif /* __CSTRING_H_INCLUDED__ */