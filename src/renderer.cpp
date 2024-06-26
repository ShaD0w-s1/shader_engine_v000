#include <vulkan/vulkan.h> // Vulkan 库

#include <stdexcept>  // 异常库
#include <vector>     // 向量库

// 设备扩展列表
const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG // 如果不是调试模式，则禁用验证层
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

// 定义一个类，用于管理 Vulkan 应用程序
class Renderer {
public:
  void run() {
    initVulkan();
    cleanup();
  }

private:
  VkInstance instance; // Vulkan 实例

  // 初始化 Vulkan 库
  void initVulkan() {
    createInstance(); // 创建 Vulkan 实例
    pickPhysicalDevice();
  }

  // 创建 Vulkan 实例
  void createInstance() {

    if (enableValidationLayers &&
        !checkValidationLayerSupport()) // 如果验证层启用，但不支持验证层
    {
      throw std::runtime_error(
          "validation_layers_requested,but_not_available"); // 抛出异常
    }

    VkApplicationInfo appInfo = {};                        // 应用程序信息
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;    // 结构体类型
    appInfo.pApplicationName = "Hello Triangle";           // 应用程序名称
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0); // 应用程序版本
    appInfo.pEngineName = "No Engine";                     // 引擎名称
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);      // 引擎版本
    appInfo.apiVersion = VK_API_VERSION_1_0;               // Vulkan 版本

    VkInstanceCreateInfo createInfo = {}; // 创建 Vulkan 实例信息
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO; // 结构体类型
    createInfo.pApplicationInfo = &appInfo; // 应用程序信息

    if (enableValidationLayers) // 如果启用验证层
    {
      createInfo.enabledLayerCount =
          static_cast<uint32_t>(validationLayers.size()); // 启用的层数量
      createInfo.ppEnabledLayerNames = validationLayers.data(); // 启用的层列表
    }

    createInfo.enabledLayerCount = 0; // 启用的层数量

    VkResult result =
        vkCreateInstance(&createInfo, nullptr, &instance); // 创建 Vulkan 实例

    if (result != VK_SUCCESS) // 如果创建失败
    {
      throw std::runtime_error("failed to create instance!"); // 抛出异常
    }
  }

  // 选择物理设备
  void pickPhysicalDevice() {
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // 物理设备句柄
    uint32_t deviceCount = 0;                         // 设备数量
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr); // 获取设备数量
    if (deviceCount == 0) // 如果没有设备
    {
      throw std::runtime_error(
          "failed to find GPUs with Vulkan support!"); // 抛出异常
    }
    std::vector<VkPhysicalDevice> devices(deviceCount); // 设备列表
    vkEnumeratePhysicalDevices(instance, &deviceCount,
                               devices.data()); // 获取设备列表
    for (const auto &device : devices)          // 遍历设备列表
    {
      if (isDeviceSuitable(device)) // 如果设备合适
      {
        physicalDevice = device; // 设置物理设备句柄
        break;                   // 退出循环
      }
    }
    if (physicalDevice == VK_NULL_HANDLE) // 如果没有找到合适的设备
    {
      throw std::runtime_error("failed to find a suitable GPU!"); // 抛出异常
    }
  }

  // 检查是否支持验证层
  bool checkValidationLayerSupport() {
    uint32_t layerCount;                                      // 验证层数量
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr); // 获取验证层数量
    std::vector<VkLayerProperties> availableLayers(layerCount); // 验证层列表
    vkEnumerateInstanceLayerProperties(
        &layerCount, availableLayers.data()); // 获取验证层列表

    for (const char *layerName : validationLayers) // 遍历验证层列表
    {
      bool layerFound = false; // 是否找到验证层
      for (const auto &layerProperties : availableLayers) // 遍历可用验证层列表
      {
        if (strcmp(layerName, layerProperties.layerName) == 0) // 如果找到验证层
        {
          layerFound = true; // 设置找到验证层标志
          break;             // 退出循环
        }
      }
      if (!layerFound) // 如果没有找到验证层
      {
        return false; // 返回 false
      }
    }
    return true; // 返回 true
  }

  // 检查设备是否合适
  bool isDeviceSuitable(VkPhysicalDevice device) { return true; };

  // 清理函数
  void cleanup() {
    vkDestroyInstance(instance, nullptr); // 销毁 Vulkan 实例
  }
};