#include <iostream>
#include <stdio.h>

#include <GLFW/glfw3.h>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
