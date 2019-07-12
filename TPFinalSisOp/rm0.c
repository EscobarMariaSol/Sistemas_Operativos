#define _POSIX_C_SOURCE 200809L

#include <...>

void rm0(const char *file) {
    // ...
}

int main(int argc, char *argv[]) {
    rm0(argv[1]);
}
