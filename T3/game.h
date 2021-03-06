typedef struct
{
    int disp_sizeX;
    int disp_sizeY;
    player player1;
    char nomJeu[11];
}game;

void game_init(game *self)
{
    self->disp_sizeX = 800;
    self->disp_sizeY = 800;
    //strcpy(self->nomJeu,"nomDuJeu");
    /*
        stricpy 
        stricpy_s est spécifique à Microsoft.

    */
    self->nomJeu[0]='j';self->nomJeu[1]='e';self->nomJeu[2]='u';self->nomJeu[3]='\0';

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
 