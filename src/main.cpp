#include <vulkan/vulkan.h> // Vulkan 库

#include <cstdlib>    // 标准库
#include <functional> // 函数库
#include <iostream>   // 标准输入输出库
#include <stdexcept>  // 标准异常库

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// 定义一个类，用于管理 Vulkan 应用程序
class HelloTriangleApplication {
public:
  void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
  }

private:
  void initWindow() {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // 不使用 OpenGL
  }

  // 初始化 Vulkan 库
  void initVulkan() {}

  void mainLoop() {}

  void cleanup() {}
};

int main() {
  HelloTriangleApplication app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}