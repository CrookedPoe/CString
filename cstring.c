#include "cstring.h"

String String_NewFromEmpty() {
    String str;

    str.buf = sdsempty();
    str.length = sdslen(str.buf);

    return str;
}

String String_NewFromBuffer(const char* input) {
    String str;

    str.buf = sdsnew(input);
    str.length = sdslen(str.buf);
    str.tokens = NULL;
    str.tokenCount = 0;

    return str;
}

String String_Free(String* str) {
    sdsfree(str->buf);
    str->length = 0;
    str->tokens = NULL;
    str->tokenCount = 0;
}

void String_ToUpper(char* dst, const char* input) {
    while (*input) {
        *(dst++) = toupper(*(input++));
    }
}

void String_ToUpperAssignment(String* input) {
    while (*input->buf) {
        *(input->buf++) = toupper(*(input->buf));
    }
}

void String_ToLower(char* dst, const char* input) {
    while (*input) {
        *(dst++) = tolower(*(input++));
    }
}

void String_ToLowerAssignment(String* input) {
    while (*input->buf) {
        *(input->buf++) = tolower(*(input->buf));
    }
}

void String_CopyTo(String* src, String* dst, int length) {
    *dst = String_NewFromBuffer(src->buf);
    sdsrange(dst->buf, 0, length - 1);
}

String String_Split(String* str, const char* delimiter) {
    String this;

    this.tokens = sdssplitlen(str->buf, str->length, delimiter, strlen(delimiter), &this.tokenCount);

    return this;
}

void String_FreeSplits(String* splits) {
    sdsfreesplitres(splits->tokens, splits->tokenCount);
}

String String_Join(char** argv, int argc, char* delimiter) {
    return String_NewFromBuffer(sdsjoin(argv, argc, delimiter));
}