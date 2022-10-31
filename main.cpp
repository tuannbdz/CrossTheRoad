#include "lib.h"
<<<<<<< Updated upstream
#include "console.h"
=======
#include "Console.h" //not supposed to include them here so this is temporary
#include "Graphics.h"
#include "Menu.h"
>>>>>>> Stashed changes

int main() {
    srand(time(NULL));
    bool gameStarts = 0; 

<<<<<<< Updated upstream
    Console::SetScreenBufferSize(62, 25);
    Console::SetWindowSize(62, 25);
    
    cout << "hello world";
=======
    Console* console = new Console(1312, 700, L"Cross The Road", false, Graphics::GetColor(Color::brightwhite, Color::black)); 
    
    Menu menu;
    menu.Run(); //will be in Game class
     
    delete console; 
>>>>>>> Stashed changes

    return 0;
}
