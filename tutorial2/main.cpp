#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <primitives.h>

const int WINDOW_WIDTH = 640*2;
const int WINDOW_HEIGHT = 480;

void drawPointsDemo(int width, int height) {
  GLfloat size = 5.0f;

  for(GLfloat x = 0.0f; x <= 1.0f; x += 0.2f, size += 5) {
    Vertex v = {x, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    drawPoint(v, size);
  }
}

void drawGrid(GLfloat width, GLfloat height, GLfloat grid_width) {

  // horizontal lines
  for(float i = -height; i < height; i += grid_width) {
    Vertex v1 = {-width, i, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    Vertex v2 = { width, i, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    drawLineSegment(v1, v2, 1.0f);
  }

  // vertical lines
  for(float i = -width; i < width; i += grid_width) {
    Vertex v1 = {i, -height, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    Vertex v2 = {i,  height, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f};
    drawLineSegment(v1, v2, 1.0f);
  }
}

void drawLineDemo() {
  // draw a simple grid
  drawGrid(5.0f, 1.0f, 0.1f);

  // define the vertices and colors of the line segments
  Vertex v1 = {-3.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.7f};
  Vertex v2 = { 3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.7f};
  Vertex v3 = { 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.7f};
  Vertex v4 = {0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.7f};

  drawLineSegment(v1, v2, 10.0f);
  drawLineSegment(v3, v4, 10.0f);
  uint v_size = 4;
  Vertex vertices[v_size] = {v1, v3, v2, v4};
  drawLineStrip(vertices, v_size, 10.0f);
}

int main(void) {
  GLFWwindow* window;

  if (!glfwInit())
    exit(EXIT_FAILURE);

  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL dataviz",
                            NULL, NULL);

  if(!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  glEnable(GL_POINT_SMOOTH);
  glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  while(!glfwWindowShouldClose(window)) {
    float ratio;
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    ratio = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    // Setup the camera matrix for orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //drawPointsDemo(width, height);
    drawLineDemo();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}
