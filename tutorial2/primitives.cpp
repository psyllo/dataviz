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

void drawLineSegment(Vertex v1, Vertex v2, GLfloat width) {
  glLineWidth(width);
  glBegin(GL_LINES);

  glColor4f(v1.r, v1.g, v1.b, v1.a);
  glVertex3f(v1.x, v1.y, v1.z);
  glColor4f(v2.r, v2.g, v2.b, v2.a);
  glVertex3f(v2.x, v2.y, v2.z);

  glEnd();
}

void drawLineStrip(Vertex v[], uint v_size, GLfloat width) {
  glLineWidth(width);
  glBegin(GL_LINE_STRIP);

  for(uint i = 0; i < v_size; i++) {
    glColor4f(v[i].r, v[i].g, v[i].b, v[i].a);
    glVertex3f(v[i].x, v[i].y, v[i].z);
  }

  glEnd();
}
