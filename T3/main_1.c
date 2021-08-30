
#include "raylib.h"
#include <stdio.h>
#include <string.h>


typedef struct
{
    Vector2 pos;
    Vector2 size;
    double speed;
    Texture2D sprite[3];
    Texture2D *current_sprite;

}player;

void player_init(player *self)
{
    self->pos.x = 0;
    self->pos.y = 0;
    self->size.x = 80;
    self->size.y = 103;
    self->speed = 3.0;
    self->sprite[0] = LoadTexture("img/perso0.png"); // face
    self->sprite[1] = LoadTexture("img/perso1.png"); // right
    self->sprite[2] = LoadTexture("img/perso2.png"); // back
    self->current_sprite = &(self->sprite[0]);
}
void player_del(player *self)
{
    for (int i; i < 2; i++)
    {
        UnloadTexture(self->sprite[i]);
    }
    
    
}

void player_do_input(player *self)
{
    if (IsKeyDown(KEY_RIGHT))
    {
        self->pos.x += self->speed;
        self->current_sprite = &(self->sprite[1]);
    }
    if (IsKeyDown(KEY_LEFT))
    {
        self->pos.x -= self->speed;
        self->current_sprite = &(self->sprite[0]);
    }
    if (IsKeyDown(KEY_UP))
    {
        self->pos.y -= self->speed;
        self->current_sprite = &(self->sprite[2]);
    }
    if (IsKeyDown(KEY_DOWN))
    {
        self->pos.y += self->speed;
        self->current_sprite = &(self->sprite[0]);
    }

}



void player_update(player *self)
{
    player_do_input(self);
}


typedef struct
{
    int disp_sizeX;
    int disp_sizeY;
    player player1;
    char nomJeu[];
}game;

void game_init(game *self)
{
    self->disp_sizeX = 800;
    self->disp_sizeY = 800;
    strcpy(self->nomJeu,"nomDuJeu");
    InitWindow(self->disp_sizeX, self->disp_sizeY, self->nomJeu);
    SetTargetFPS(60);  
    player_init(&(self->player1));
}
void game_del(game *self)
{
    player_del(&(self->player1));
}
void game_update(game *self)
{
    player_update(&(self->player1));
}
void game_draw(game *self)
{
    ClearBackground(RAYWHITE);
    DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
    DrawTexture(*(self->player1.current_sprite),self->player1.pos.x,self->player1.pos.y,WHITE);
    
}
 

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