#include <stdio.h>
#include "Vector2.h"

void Vector2_Log(Vector2 *ptr) {
    printf("Vector2: x=%f, y=%f\n", ptr->x, ptr->y);
}

Vector2 Vector2_Zero() {
    Vector2 v;
    v.x = 0;
    v.y = 0;
    return v;
}