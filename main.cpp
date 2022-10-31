#include "lib.h"
#include "Console.h" //not supposed to include them here so this is temporary
#include "Graphics.h"
#include "Menu.h"

int main() {
    srand(time(NULL));

    Console* console = new Console(1312, 700, L"Cross The Road", false, Graphics::GetColor(Color::brightwhite, Color::black)); 
    
    Menu menu;
    menu.Run(); //will be in Game class
     
    delete console; 

    return 0;
}
