#include <raylib.h>
#include <raymath.h>

typedef struct Bullet {
    Vector2 moveAxis;
    float moveSpeed;
    Vector2 pos;
    float radius;
    Color color;
} Bullet;

typedef struct RoleEntity {
    Vector2 moveAxis;
    float moveSpeed;
    Vector2 pos;
    int width;
    int height;
    Color color;
} RoleEntity;

void RoleEntity_Input(RoleEntity *role) {
    Vector2 moveInput = {0}; //??
    if (IsKeyDown(KEY_W)) {
        moveInput.y = -1;
    }
    if (IsKeyDown(KEY_S)) {
        moveInput.y = 1;
    }
    if (IsKeyDown(KEY_A)) {
        moveInput.x = -1;
    }
    if (IsKeyDown(KEY_D)) {
        moveInput.x = 1;
    }
    role->moveAxis = Vector2Normalize(moveInput);
}
void RoleEntity_InputG(RoleEntity *role) {
    Vector2 moveInput = role->moveAxis;

    if (role->pos.x < 0) {
            moveInput.x = 1;
    }

   if (role->pos.x > 900) {
       moveInput.x = -1;
   }

   if (moveInput.x==0){
       moveInput.x=1;//
   }

    role->moveAxis = Vector2Normalize(moveInput);
}

void RoleEntity_InputB(Bullet *Bullet) {
    Vector2 moveInput = {0}; //??
    if (IsKeyDown(KEY_K)) {
        moveInput.y = -1;
    }
    Bullet->moveAxis = Vector2Normalize(moveInput);
}

//!!
void RoleEntity_Move(RoleEntity *role, float dt) {
    Vector2 dir = Vector2Scale(role->moveAxis, role->moveSpeed * dt);
    role->pos = Vector2Add(dir, role->pos);
}

void RoleEntity_MoveG(RoleEntity *role, float dt) {
    Vector2 dir = Vector2Scale(role->moveAxis, role->moveSpeed * dt);
    role->pos = Vector2Add(dir, role->pos);
}

void RoleEntity_MoveB(Bullet *Bullet, float dt) {
    Vector2 dir = Vector2Scale(Bullet->moveAxis, Bullet->moveSpeed * dt);
    Bullet->pos = Vector2Add(dir, Bullet->pos);
}



void RoleEntity_DrawB(Bullet *Bullet) {
    DrawCircle(Bullet->pos.x, Bullet->pos.y, Bullet->radius, Bullet->color);
}

void RoleEntity_Draw(RoleEntity *role) {
    DrawRectangle(role->pos.x, role->pos.y, role->width, role->height, role->color);
}

int main(void) {
    InitWindow(800, 450, "cyh");

    RoleEntity role = {
        .moveAxis =(Vector2) {0}, .pos = {.x = 40, .y = 20}, .height = 50, .width = 50, .moveSpeed = 100, .color = GREEN};
    RoleEntity role1 = {
        .moveAxis =(Vector2) {0}, .pos = {.x = 40, .y = 320}, .height = 50, .width = 50, .moveSpeed = 150, .color = RED};
    

    //  Bullet Bullet1[10000];
     
     
     
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        float dt = GetFrameTime(); //?
        // RoleEntity_Draw(&role1);
        RoleEntity_Draw(&role);
        // RoleEntity_DrawB(&Bullet);
        // RoleEntity_Input(&role1);
        RoleEntity_InputG(&role);
        // RoleEntity_InputB(&Bullet);
        // RoleEntity_Move(&role1, dt);s
        RoleEntity_MoveG(&role, dt);
        // RoleEntity_MoveB(&Bullet,dt);
        TextFormat("Delta Time : %f ", dt);


        EndDrawing();
    }

    CloseWindow();

    return 0;
}