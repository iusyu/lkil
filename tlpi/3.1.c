#include "lib/tlpi_hdr.h"

const char* filepath = "./t.txt";


int main(int argc, char* argv[]) {
    const char* errstr = strerror(10);

    printf("%s. \n", errstr);

    return 0;
}