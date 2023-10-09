#include <stdio.h>

// typedef 相当于 `别名`
typedef int i32;

int main() {
    // 因为上面 typedef 了，所以这里可以直接用 i32 替代 int
    i32 a = 1;
    printf("a = %d\n", a);

    // 因此看lv1_header的例子，可以看到，typedef 可以用来简化代码

    return 0;
}