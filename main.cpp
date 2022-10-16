#include "lib.h"
#include "console.h"

int main() {
    srand(time(NULL));

    Console::SetScreenBufferSize(62, 25);
    Console::SetWindowSize(62, 25);

    cout << "kiet_pullRequest" << endl;
    cout << "push2";

    return 0;
}