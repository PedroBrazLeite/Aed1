#include <stdio.h>

int main(int argc, char const *argv[])
{
    double a[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    for (size_t i = 0; i < 10; i++)
        printf("%f\n", *(a + i));
    return 0;
}
