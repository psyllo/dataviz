#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <primitives.h>

void drawPoint(Vertex v, GLfloat size) {
  glPointSize(size);
  glBegin(GL_POINTS);
  glColor4f(v.r, v.g, v.b, v.a);
  glVertex3f(v.x, v.y, v.z);
  glEnd();
}

void drawPointsDemo(int width, int height) {
  GLfloat size = 5.0f;

  for(GLfloat x = 0.0f; x <= 1.0f; x += 0.2f, size += 5) {
    Vertex v = {x, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    drawPoint(v, size);
  }
}
