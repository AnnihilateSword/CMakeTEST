#include "Message.hpp"

#include <cstdlib>
#include <iostream>

#include <GLFW/glfw3.h>

int main()
{
  Message say_hello("Hello, CMake World!");

  std::cout << say_hello << std::endl;

  Message say_goodbye("Goodbye, CMake World");

  std::cout << say_goodbye << std::endl;

  // GLFW Example
  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit())
	  return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window)
  {
	  glfwTerminate();
	  return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
  {
	  /* Render here */
	  glClear(GL_COLOR_BUFFER_BIT);

	  /* Swap front and back buffers */
	  glfwSwapBuffers(window);

	  /* Poll for and process events */
	  glfwPollEvents();
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}
