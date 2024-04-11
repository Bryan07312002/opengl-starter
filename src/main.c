#include <GLFW/glfw3.h>
#include <stdio.h>

#define true 1

void resize_gl_viewport(GLFWwindow *_, int width, int height) {
  glViewport(0, 0, width, height);
}

void handle_input(GLFWwindow *window) {

  // Press ESC to exit
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main(void) {
  printf("Starting...\n");

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

  GLFWwindow *window =
      glfwCreateWindow(800, 800, "Hello world window", NULL, NULL);

  if (window == NULL) {
    printf("Failed to create GLFW window");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  glViewport(0, 0, 800, 800);

  // change window size viewport if window changes
  glfwSetFramebufferSizeCallback(window, resize_gl_viewport);

  // change background clear color
  glClearColor(.2f, .3f, .3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  while (!glfwWindowShouldClose(window)) {
    handle_input(window);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
