
#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "game.h"



int main(void)
{
    
    
    game game1;
    game_init(&game1);
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        game_update(&game1);

        BeginDrawing();
        game_draw(&game1);
        EndDrawing();

    }
    
    // De-Initialization
    game_del(&game1);
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

  

    return 0;
}