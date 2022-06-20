#include <stdio.h>
#include "cstring.c"

typedef struct globalInstance_s {
    String str_a;
    String str_b;
} GlobalInstance;

void Update(GlobalInstance* this) {

    printf("%s, %s\n", this->str_a.buf, this->str_b.buf);
    String_Free(&this->str_a);
    String_CopyTo(&this->str_b, &this->str_a, 5);
    printf("%s, %s\n", this->str_a.buf, this->str_b.buf);
    String_Free(&this->str_a);
    String_Free(&this->str_b);
}

int main() {
    GlobalInstance this;

    this.str_a = String_NewFromBuffer("Hello");
    this.str_b = String_NewFromBuffer("World!");

    Update(&this);

    return 0;
}