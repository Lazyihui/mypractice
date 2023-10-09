#include <stdio.h>
#include "Vector2.h"

struct Book {
    char name[16];
    int price;
};

int main() {
    Vector2 v = Vector2_Zero();
    Vector2_Log(&v);

    // 注: `Book` 并不是类型, `struct Book` 才是类型 
    struct Book b;
    return 0;
}