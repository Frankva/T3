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


  





int main(void)
{
   
    const int screenWidth{ 800 };
    const int screenHeight{ 450 };
    
    void draw( Texture2D,Vector2);
    void update(Vector2);
    // const string nomJeu{"Nem du jeu"};
    const char* nomJeu{ "Nom du jeu" };
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };

    


    InitWindow(screenWidth, screenHeight, nomJeu);
    Texture2D Perso = LoadTexture("img/perso0.png");


    SetTargetFPS(25);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update(ballPosition);

        BeginDrawing();
        DrawTexture(Perso, ballPosition.x,ballPosition.y,Color(BLACK));
        draw(Perso,ballPosition);
        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

  

    return 0;
}
void update(Vector2 ballPosition_)
{

    if (IsKeyDown(KEY_RIGHT))
        ballPosition_.x += 2.0;
    if (IsKeyDown(KEY_LEFT))
        ballPosition_.x -= 2.0;
    if (IsKeyDown(KEY_UP))
        ballPosition_.y -= 2.0;
    if (IsKeyDown(KEY_DOWN))
        ballPosition_.y += 2.0;

}

void draw(Texture2D Perso_, Vector2 ballPosition_)
{


    ClearBackground(RAYWHITE);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    DrawTextureEx(Perso_, ballPosition_, 0.0, 100, Color(BLACK));




};
