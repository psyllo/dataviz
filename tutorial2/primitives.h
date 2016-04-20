#include <stdlib.h>
#include <GLFW/glfw3.h>

typedef struct {
  GLfloat x, y, z;
  GLfloat r, g, b, a;
} Vertex;

void drawPoint(Vertex v, GLfloat size);
void drawLineSegment(Vertex v1, Vertex v2, GLfloat width);
void drawLineStrip(Vertex v[], uint v_size, GLfloat width);
