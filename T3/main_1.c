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


int main(void)
{
   
    const int screenWidth = 800 ;
    const int screenHeight = 450 ;
    
    void draw( Texture2D,Vector2);
    void update(double *ptrx,double *ptry);
    // const str ing nomJeu{"Nem du jeu"};
    char nomJeu[] = "Nom du jeu" ;
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
   
    double x = 0;
    double y = 0;
    double *ptrx = &x;
    double *ptry = &y;

    InitWindow(screenWidth, screenHeight, nomJeu);
    Texture2D Perso = LoadTexture("img/perso0.png");


    SetTargetFPS(25);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        update(ptrx,ptry);

        BeginDrawing();
        DrawTexture(Perso,(int)x,(int)y,BLACK);
        draw(Perso,ballPosition);
        EndDrawing();

    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

  

    return 0;
}
void update(double *ptrx, double *ptry)
{

    if (IsKeyDown(KEY_RIGHT))
        *ptrx += 3.0;
    if (IsKeyDown(KEY_LEFT))
        *ptrx -= 3.0;
    if (IsKeyDown(KEY_UP))
        *ptry -= 3.0;
    if (IsKeyDown(KEY_DOWN))
        *ptry += 3.0;

}

void draw(Texture2D Perso_, Vector2 ballPosition_)
{


    ClearBackground(RAYWHITE);

    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

    DrawTextureEx(Perso_, ballPosition_, 0.0, 100,BLACK);




};
