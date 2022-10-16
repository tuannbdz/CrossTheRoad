#include "lib.h"
#include "console.h"

int main() {
    srand(time(NULL));
    Console::SetScreenBufferSize(80, 25);
    Console::SetWindowSize(80, 25);
    cout << "TPush";
    return 0;
}