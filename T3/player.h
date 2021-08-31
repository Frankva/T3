
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
