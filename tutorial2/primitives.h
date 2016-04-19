#include <stdlib.h>
#include <GLFW/glfw3.h>

typedef struct {
  GLfloat x, y, z;
  GLfloat r, g, b, a;
} Vertex;

void drawPoint(Vertex v, GLfloat size);

void drawPointsDemo(int width, int height);
