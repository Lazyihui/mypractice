#ifndef Vector2_H
#define Vector2_H

typedef struct Vector2Type {
    float x;
    float y;
} Vector2;

Vector2 Vector2_Zero();
void Vector2_Log(Vector2 *ptr);

#endif