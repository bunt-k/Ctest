#include <iostream>
#include <cstdlib>
#include <cstring>

void forward_null() {
    char* p = nullptr;
    *p = 'a';
}

void reverse_null(char* input) {
    *input = 12;
    if (input == nullptr)
        return;
}

void resource_leak() {
    char* p = static_cast<char*>(std::malloc(4));
    p[0] = 12;
}

void resource_leak_2() {
    char* p = static_cast<char*>(std::malloc(4));
    char* q = static_cast<char*>(std::malloc(12));
    if (!p || !q)
        return;
}

void use_after_free() {
    char* p = static_cast<char*>(std::malloc(4));
    std::free(p);
    *p = 'a';
}

struct BiggerThanPtr { int a, b, c, d; };

void size_check() {
    BiggerThanPtr* p = static_cast<BiggerThanPtr*>(std::malloc(sizeof(BiggerThanPtr*)));
}

int some_func();

void dead_code() {
    int x = some_func();
    if (x) {
        if (!x) {
            x++;
            return;
        }
    }
}

void reverse_negative() {
    int j = some_func();
    char buf[10];
    buf[j] = '\0';
    if (j < 0)
        return;
}

void uninit() {
    /*char* p;*/
    char p[10];
    //*p = 'a';
    p[0] = 'a';
}

void overrun_static() {
    char buf[10];
    for (int i = 0; i <= 10; ++i)
        buf[i] = '\0';
}

// Error codes
#define NO_MEM -1
#define OK 0
#define OTHER_ERROR -2

bool some_other_function();
bool yet_another_function();
void do_some_things(char*);

int paths() {
    char* p = static_cast<char*>(std::malloc(12));
    if (!p)
        return NO_MEM;

    if (!some_other_function()) {
        std::free(p);
        return OTHER_ERROR;
    }

    if (!yet_another_function()) {
        return OTHER_ERROR;
    }

    do_some_things(p);
    std::free(p);
    return OK;
}

int main() { 
    dead_code();
    return 0;
};
