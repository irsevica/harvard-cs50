#include <stdio.h>

int valid_triangle(float x, float y, float z);

int main(void)
{
    float x = 2;
    float y = 2;
    float z = 2;
    int result = valid_triangle(x , y, z);
    if (result == 0)
    {
        printf("INVALID triangle.\n");
    }
    else
    {
        printf("VALID triangle\n");
    }
}

int valid_triangle(float x, float y, float z)
{
    //must be positive float
    if ( x < 0 || y < 0 || z < 0)
    {
        return 0;
    }

    // ensure product of two sides always bigger than single side
    if ( x + y > z && y + z > x && x + z > y)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

