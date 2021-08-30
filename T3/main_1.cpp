/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>

using namespace std;

class game
{
    const int Perso = 0;
    const int screenWidth{ 800 };
    const int screenHeight{ 450 };
    Texture2D Perso = LoadTexture("img\perso0.png");
    // const string nomJeu{"Nem du jeu"};
    const char* nomJeu{ "Nom du jeu" };
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

public:
    game() {


        InitWindow(screenWidth, screenHeight, nomJeu);



        SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
        //--------------------------------------------------------------------------------------

        // Main game loop
        while (!WindowShouldClose())    // Detect window close button or ESC key
        {
            update();

            BeginDrawing();
            draw();
            EndDrawing();

        }

        // De-Initialization
        //--------------------------------------------------------------------------------------
        CloseWindow();        // Close window and OpenGL context
        //--------------------------------------------------------------------------------------

    }


    void update()
    {

        if (IsKeyDown(KEY_RIGHT))
            ballPosition.x += 2.0;
        if (IsKeyDown(KEY_LEFT))
            ballPosition.x -= 2.0;
        if (IsKeyDown(KEY_UP))
            ballPosition.y -= 2.0;
        if (IsKeyDown(KEY_DOWN))
            ballPosition.y += 2.0;

    }

    void draw()
    {


        ClearBackground(RAYWHITE);

        DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

        DrawCircleV(ballPosition, 50, MAROON);


    }



};




int main(void)
{

    game game1;



    return 0;
}