#include "lib.h"
#include "console.h"

int main() {
    srand(time(NULL));
    Console::SetScreenBufferSize(98, 27);
    Console::SetWindowSize(98, 27);
    Console::DisableResizeWindow();
    return 0;
}