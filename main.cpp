#include "GAME.h"


int main() {
    srand(time(NULL));

    Console* console = new Console(1312, 700, L"Cross The Road", false, Graphics::GetColor(Color::brightwhite, Color::black)); 
    
    GAME::Run(); 
    delete console; 
    system("pause >nul"); 
    return 0;
}
