#include "lib.h"
#include "console.h"

int main() {
    srand(time(NULL));
    Console::SetScreenBufferSize(80, 25);
    Console::SetWindowSize(80, 25);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cout << i << '\n';
    return 0;
}