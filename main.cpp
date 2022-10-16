#include "lib.h"
#include "console.h"

int main() {
    srand(time(NULL));

    Console::SetScreenBufferSize(62, 25);
    Console::SetWindowSize(62, 25);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[100];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++)  cout << a[i] << '\n';
    }
    cout << "kietCommitMaster";
    return 0;
}