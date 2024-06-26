// Renderer.h
#ifndef HELLO_TRIANGLE_APP_H
#define HELLO_TRIANGLE_APP_H

#include <vector>
#include <vulkan/vulkan.h>

class Renderer {
public:
  void run();

private:
  VkInstance instance;
  void initVulkan();
  void cleanup();
};

#endif // HELLO_TRIANGLE_APP_H