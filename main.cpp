#include "lib.h"
#include "console.h"

int main() {
    srand(time(NULL));

    Console::SetScreenBufferSize(62, 25);
    Console::SetWindowSize(62, 25);
    int n;
    cin >> n;
    cout << n;
    cout << "kietPush2";
    return 0;
}