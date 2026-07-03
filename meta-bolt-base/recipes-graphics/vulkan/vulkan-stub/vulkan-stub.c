/*  Platform headers are included conditionally — define VK_USE_PLATFORM_*
 * via compiler flags (e.g. -DVK_USE_PLATFORM_WAYLAND_KHR) to enable the
 * corresponding platform stubs.  The recipe (vulkan-stub.bb) does this
 * automatically from DISTRO_FEATURES.
 *
 * Used at build time; replaced at runtime by the vendor libvulkan.so.
 */
#include <vulkan/vulkan.h>
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
#include <vulkan/vulkan_wayland.h>
#endif
#ifdef VK_USE_PLATFORM_XCB_KHR
#include <vulkan/vulkan_xcb.h>
#endif
#ifdef VK_USE_PLATFORM_XLIB_KHR
#include <vulkan/vulkan_xlib.h>
#endif
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
#include <vulkan/vulkan_xlib_xrandr.h>
#endif
#ifdef VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan_win32.h>
#endif
#ifdef VK_USE_PLATFORM_ANDROID_KHR
#include <vulkan/vulkan_android.h>
#endif
#ifdef VK_USE_PLATFORM_METAL_EXT
#include <vulkan/vulkan_metal.h>
#endif
#include <vulkan/vulkan_beta.h>
#pragma GCC diagnostic ignored "-Wunused-parameter"

/* ── Disabled-extension commands ─────────────────────────────────── */
#ifdef VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION
VkResult vkAcquireImageANDROID(VkDevice device, VkImage image, int nativeFenceFd, VkSemaphore semaphore, VkFence fence) { (void)device; (void)image; (void)nativeFenceFd; (void)semaphore; (void)fence; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION */

#ifdef VK_OHOS_NATIVE_BUFFER_SPEC_VERSION
VkResult vkAcquireImageOHOS(VkDevice device, VkImage image, int32_t nativeFenceFd, VkSemaphore semaphore, VkFence fence) { (void)device; (void)image; (void)nativeFenceFd; (void)semaphore; (void)fence; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_OHOS_NATIVE_BUFFER_SPEC_VERSION */

#ifdef VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION
VkResult vkGetSwapchainGrallocUsage2ANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, VkSwapchainImageUsageFlagsANDROID swapchainImageUsage, uint64_t* grallocConsumerUsage, uint64_t* grallocProducerUsage) { (void)device; (void)format; (void)imageUsage; (void)swapchainImageUsage; (void)grallocConsumerUsage; (void)grallocProducerUsage; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetSwapchainGrallocUsageANDROID(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, int* grallocUsage) { (void)device; (void)format; (void)imageUsage; (void)grallocUsage; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION */

#ifdef VK_OHOS_NATIVE_BUFFER_SPEC_VERSION
VkResult vkGetSwapchainGrallocUsageOHOS(VkDevice device, VkFormat format, VkImageUsageFlags imageUsage, uint64_t* grallocUsage) { (void)device; (void)format; (void)imageUsage; (void)grallocUsage; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_OHOS_NATIVE_BUFFER_SPEC_VERSION */

#ifdef VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION
VkResult vkQueueSignalReleaseImageANDROID(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int* pNativeFenceFd) { (void)queue; (void)waitSemaphoreCount; (void)pWaitSemaphores; (void)image; (void)pNativeFenceFd; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_ANDROID_NATIVE_BUFFER_SPEC_VERSION */

#ifdef VK_OHOS_NATIVE_BUFFER_SPEC_VERSION
VkResult vkQueueSignalReleaseImageOHOS(VkQueue queue, uint32_t waitSemaphoreCount, const VkSemaphore* pWaitSemaphores, VkImage image, int32_t* pNativeFenceFd) { (void)queue; (void)waitSemaphoreCount; (void)pWaitSemaphores; (void)image; (void)pNativeFenceFd; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_OHOS_NATIVE_BUFFER_SPEC_VERSION */


/* ── VulkanSC-only commands ───────────────────────────────────────── */
#ifdef VKSC_VERSION_1_0
void vkCmdRefreshObjectsKHR(VkCommandBuffer commandBuffer, const VkRefreshObjectListKHR* pRefreshObjects) { (void)commandBuffer; (void)pRefreshObjects; }
VkResult vkCreateSemaphoreSciSyncPoolNV(VkDevice device, const VkSemaphoreSciSyncPoolCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphoreSciSyncPoolNV* pSemaphorePool) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pSemaphorePool; return VK_ERROR_INITIALIZATION_FAILED; }
void vkDestroySemaphoreSciSyncPoolNV(VkDevice device, VkSemaphoreSciSyncPoolNV semaphorePool, const VkAllocationCallbacks* pAllocator) { (void)device; (void)semaphorePool; (void)pAllocator; }
void vkGetCommandPoolMemoryConsumption(VkDevice device, VkCommandPool commandPool, VkCommandBuffer commandBuffer, VkCommandPoolMemoryConsumption* pConsumption) { (void)device; (void)commandPool; (void)commandBuffer; (void)pConsumption; }
VkResult vkGetFaultData(VkDevice device, VkFaultQueryBehavior faultQueryBehavior, VkBool32* pUnrecordedFaults, uint32_t* pFaultCount, VkFaultData* pFaults) { (void)device; (void)faultQueryBehavior; (void)pUnrecordedFaults; (void)pFaultCount; (void)pFaults; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetFenceSciSyncFenceNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle) { (void)device; (void)pGetSciSyncHandleInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetFenceSciSyncObjNV(VkDevice device, const VkFenceGetSciSyncInfoNV* pGetSciSyncHandleInfo, void* pHandle) { (void)device; (void)pGetSciSyncHandleInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetMemorySciBufNV(VkDevice device, const VkMemoryGetSciBufInfoNV* pGetSciBufInfo, NvSciBufObj* pHandle) { (void)device; (void)pGetSciBufInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPhysicalDeviceExternalMemorySciBufPropertiesNV(VkPhysicalDevice physicalDevice, VkExternalMemoryHandleTypeFlagBits handleType, NvSciBufObj handle, VkMemorySciBufPropertiesNV* pMemorySciBufProperties) { (void)physicalDevice; (void)handleType; (void)handle; (void)pMemorySciBufProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceRefreshableObjectTypesKHR(VkPhysicalDevice physicalDevice, uint32_t* pRefreshableObjectTypeCount, VkObjectType* pRefreshableObjectTypes) { (void)physicalDevice; (void)pRefreshableObjectTypeCount; (void)pRefreshableObjectTypes; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSciBufAttributesNV(VkPhysicalDevice physicalDevice, NvSciBufAttrList pAttributes) { (void)physicalDevice; (void)pAttributes; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSciSyncAttributesNV(VkPhysicalDevice physicalDevice, const VkSciSyncAttributesInfoNV* pSciSyncAttributesInfo, NvSciSyncAttrList pAttributes) { (void)physicalDevice; (void)pSciSyncAttributesInfo; (void)pAttributes; return VK_SUCCESS; }
VkResult vkGetSemaphoreSciSyncObjNV(VkDevice device, const VkSemaphoreGetSciSyncInfoNV* pGetSciSyncInfo, void* pHandle) { (void)device; (void)pGetSciSyncInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkImportFenceSciSyncFenceNV(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) { (void)device; (void)pImportFenceSciSyncInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkImportFenceSciSyncObjNV(VkDevice device, const VkImportFenceSciSyncInfoNV* pImportFenceSciSyncInfo) { (void)device; (void)pImportFenceSciSyncInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkImportSemaphoreSciSyncObjNV(VkDevice device, const VkImportSemaphoreSciSyncInfoNV* pImportSemaphoreSciSyncInfo) { (void)device; (void)pImportSemaphoreSciSyncInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VKSC_VERSION_1_0 */


/* ── Standard Vulkan commands ─────────────────────────────────────── */
VkResult vkAcquireDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, VkDisplayKHR display) { (void)physicalDevice; (void)drmFd; (void)display; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkAcquireFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) { (void)device; (void)swapchain; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult vkAcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex) { (void)device; (void)pAcquireInfo; (void)pImageIndex; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) { (void)device; (void)swapchain; (void)timeout; (void)semaphore; (void)fence; (void)pImageIndex; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkAcquirePerformanceConfigurationINTEL(VkDevice device, const VkPerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, VkPerformanceConfigurationINTEL* pConfiguration) { (void)device; (void)pAcquireInfo; (void)pConfiguration; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkAcquireProfilingLockKHR(VkDevice device, const VkAcquireProfilingLockInfoKHR* pInfo) { (void)device; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkAcquireWinrtDisplayNV(VkPhysicalDevice physicalDevice, VkDisplayKHR display) { (void)physicalDevice; (void)display; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
VkResult vkAcquireXlibDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, VkDisplayKHR display) { (void)physicalDevice; (void)dpy; (void)display; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

VkResult vkAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo, VkCommandBuffer* pCommandBuffers) { (void)device; (void)pAllocateInfo; (void)pCommandBuffers; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkAllocateDescriptorSets(VkDevice device, const VkDescriptorSetAllocateInfo* pAllocateInfo, VkDescriptorSet* pDescriptorSets) { (void)device; (void)pAllocateInfo; (void)pDescriptorSets; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkAllocateMemory(VkDevice device, const VkMemoryAllocateInfo* pAllocateInfo, const VkAllocationCallbacks* pAllocator, VkDeviceMemory* pMemory) { (void)device; (void)pAllocateInfo; (void)pAllocator; (void)pMemory; return VK_ERROR_INITIALIZATION_FAILED; }
void vkAntiLagUpdateAMD(VkDevice device, const VkAntiLagDataAMD* pData) { (void)device; (void)pData; }
VkResult vkBeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo) { (void)commandBuffer; (void)pBeginInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindAccelerationStructureMemoryNV(VkDevice device, uint32_t bindInfoCount, const VkBindAccelerationStructureMemoryInfoNV* pBindInfos) { (void)device; (void)bindInfoCount; (void)pBindInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset) { (void)device; (void)buffer; (void)memory; (void)memoryOffset; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindBufferMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) { (void)device; (void)bindInfoCount; (void)pBindInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindBufferMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindBufferMemoryInfo* pBindInfos) { (void)device; (void)bindInfoCount; (void)pBindInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindDataGraphPipelineSessionMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindDataGraphPipelineSessionMemoryInfoARM* pBindInfos) { (void)device; (void)bindInfoCount; (void)pBindInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset) { (void)device; (void)image; (void)memory; (void)memoryOffset; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) { (void)device; (void)bindInfoCount; (void)pBindInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindImageMemory2KHR(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos) { (void)device; (void)bindInfoCount; (void)pBindInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindOpticalFlowSessionImageNV(VkDevice device, VkOpticalFlowSessionNV session, VkOpticalFlowSessionBindingPointNV bindingPoint, VkImageView view, VkImageLayout layout) { (void)device; (void)session; (void)bindingPoint; (void)view; (void)layout; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindTensorMemoryARM(VkDevice device, uint32_t bindInfoCount, const VkBindTensorMemoryInfoARM* pBindInfos) { (void)device; (void)bindInfoCount; (void)pBindInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBindVideoSessionMemoryKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const VkBindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos) { (void)device; (void)videoSession; (void)bindSessionMemoryInfoCount; (void)pBindSessionMemoryInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBuildAccelerationStructuresKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) { (void)device; (void)deferredOperation; (void)infoCount; (void)pInfos; (void)ppBuildRangeInfos; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkBuildMicromapsEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) { (void)device; (void)deferredOperation; (void)infoCount; (void)pInfos; return VK_ERROR_INITIALIZATION_FAILED; }
void vkCmdBeginConditionalRenderingEXT(VkCommandBuffer commandBuffer, const VkConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin) { (void)commandBuffer; (void)pConditionalRenderingBegin; }
void vkCmdBeginCustomResolveEXT(VkCommandBuffer commandBuffer, const VkBeginCustomResolveInfoEXT* pBeginCustomResolveInfo) { (void)commandBuffer; (void)pBeginCustomResolveInfo; }
void vkCmdBeginDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) { (void)commandBuffer; (void)pLabelInfo; }
void vkCmdBeginPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileBeginInfoQCOM* pPerTileBeginInfo) { (void)commandBuffer; (void)pPerTileBeginInfo; }
void vkCmdBeginQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags) { (void)commandBuffer; (void)queryPool; (void)query; (void)flags; }
void vkCmdBeginQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, VkQueryControlFlags flags, uint32_t index) { (void)commandBuffer; (void)queryPool; (void)query; (void)flags; (void)index; }
void vkCmdBeginRenderPass(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, VkSubpassContents contents) { (void)commandBuffer; (void)pRenderPassBegin; (void)contents; }
void vkCmdBeginRenderPass2(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) { (void)commandBuffer; (void)pRenderPassBegin; (void)pSubpassBeginInfo; }
void vkCmdBeginRenderPass2KHR(VkCommandBuffer commandBuffer, const VkRenderPassBeginInfo* pRenderPassBegin, const VkSubpassBeginInfo* pSubpassBeginInfo) { (void)commandBuffer; (void)pRenderPassBegin; (void)pSubpassBeginInfo; }
void vkCmdBeginRendering(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) { (void)commandBuffer; (void)pRenderingInfo; }
void vkCmdBeginRenderingKHR(VkCommandBuffer commandBuffer, const VkRenderingInfo* pRenderingInfo) { (void)commandBuffer; (void)pRenderingInfo; }
void vkCmdBeginTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) { (void)commandBuffer; (void)firstCounterBuffer; (void)counterBufferCount; (void)pCounterBuffers; (void)pCounterBufferOffsets; }
void vkCmdBeginVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoBeginCodingInfoKHR* pBeginInfo) { (void)commandBuffer; (void)pBeginInfo; }
void vkCmdBindDescriptorBufferEmbeddedSamplers2EXT(VkCommandBuffer commandBuffer, const VkBindDescriptorBufferEmbeddedSamplersInfoEXT* pBindDescriptorBufferEmbeddedSamplersInfo) { (void)commandBuffer; (void)pBindDescriptorBufferEmbeddedSamplersInfo; }
void vkCmdBindDescriptorBufferEmbeddedSamplersEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set) { (void)commandBuffer; (void)pipelineBindPoint; (void)layout; (void)set; }
void vkCmdBindDescriptorBuffersEXT(VkCommandBuffer commandBuffer, uint32_t bufferCount, const VkDescriptorBufferBindingInfoEXT* pBindingInfos) { (void)commandBuffer; (void)bufferCount; (void)pBindingInfos; }
void vkCmdBindDescriptorSets(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets) { (void)commandBuffer; (void)pipelineBindPoint; (void)layout; (void)firstSet; (void)descriptorSetCount; (void)pDescriptorSets; (void)dynamicOffsetCount; (void)pDynamicOffsets; }
void vkCmdBindDescriptorSets2(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) { (void)commandBuffer; (void)pBindDescriptorSetsInfo; }
void vkCmdBindDescriptorSets2KHR(VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfo* pBindDescriptorSetsInfo) { (void)commandBuffer; (void)pBindDescriptorSetsInfo; }
void vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) { (void)commandBuffer; (void)buffer; (void)offset; (void)indexType; }
void vkCmdBindIndexBuffer2(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) { (void)commandBuffer; (void)buffer; (void)offset; (void)size; (void)indexType; }
void vkCmdBindIndexBuffer2KHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType) { (void)commandBuffer; (void)buffer; (void)offset; (void)size; (void)indexType; }
void vkCmdBindInvocationMaskHUAWEI(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) { (void)commandBuffer; (void)imageView; (void)imageLayout; }
void vkCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) { (void)commandBuffer; (void)pipelineBindPoint; (void)pipeline; }
void vkCmdBindPipelineShaderGroupNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline, uint32_t groupIndex) { (void)commandBuffer; (void)pipelineBindPoint; (void)pipeline; (void)groupIndex; }
void vkCmdBindResourceHeapEXT(VkCommandBuffer commandBuffer, const VkBindHeapInfoEXT* pBindInfo) { (void)commandBuffer; (void)pBindInfo; }
void vkCmdBindSamplerHeapEXT(VkCommandBuffer commandBuffer, const VkBindHeapInfoEXT* pBindInfo) { (void)commandBuffer; (void)pBindInfo; }
void vkCmdBindShadersEXT(VkCommandBuffer commandBuffer, uint32_t stageCount, const VkShaderStageFlagBits* pStages, const VkShaderEXT* pShaders) { (void)commandBuffer; (void)stageCount; (void)pStages; (void)pShaders; }
void vkCmdBindShadingRateImageNV(VkCommandBuffer commandBuffer, VkImageView imageView, VkImageLayout imageLayout) { (void)commandBuffer; (void)imageView; (void)imageLayout; }
void vkCmdBindTileMemoryQCOM(VkCommandBuffer commandBuffer, const VkTileMemoryBindInfoQCOM* pTileMemoryBindInfo) { (void)commandBuffer; (void)pTileMemoryBindInfo; }
void vkCmdBindTransformFeedbackBuffersEXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes) { (void)commandBuffer; (void)firstBinding; (void)bindingCount; (void)pBuffers; (void)pOffsets; (void)pSizes; }
void vkCmdBindVertexBuffers(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets) { (void)commandBuffer; (void)firstBinding; (void)bindingCount; (void)pBuffers; (void)pOffsets; }
void vkCmdBindVertexBuffers2(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) { (void)commandBuffer; (void)firstBinding; (void)bindingCount; (void)pBuffers; (void)pOffsets; (void)pSizes; (void)pStrides; }
void vkCmdBindVertexBuffers2EXT(VkCommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const VkBuffer* pBuffers, const VkDeviceSize* pOffsets, const VkDeviceSize* pSizes, const VkDeviceSize* pStrides) { (void)commandBuffer; (void)firstBinding; (void)bindingCount; (void)pBuffers; (void)pOffsets; (void)pSizes; (void)pStrides; }
void vkCmdBlitImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageBlit* pRegions, VkFilter filter) { (void)commandBuffer; (void)srcImage; (void)srcImageLayout; (void)dstImage; (void)dstImageLayout; (void)regionCount; (void)pRegions; (void)filter; }
void vkCmdBlitImage2(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) { (void)commandBuffer; (void)pBlitImageInfo; }
void vkCmdBlitImage2KHR(VkCommandBuffer commandBuffer, const VkBlitImageInfo2* pBlitImageInfo) { (void)commandBuffer; (void)pBlitImageInfo; }
void vkCmdBuildAccelerationStructureNV(VkCommandBuffer commandBuffer, const VkAccelerationStructureInfoNV* pInfo, VkBuffer instanceData, VkDeviceSize instanceOffset, VkBool32 update, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkBuffer scratch, VkDeviceSize scratchOffset) { (void)commandBuffer; (void)pInfo; (void)instanceData; (void)instanceOffset; (void)update; (void)dst; (void)src; (void)scratch; (void)scratchOffset; }
void vkCmdBuildAccelerationStructuresIndirectKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkDeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides, const uint32_t* const* ppMaxPrimitiveCounts) { (void)commandBuffer; (void)infoCount; (void)pInfos; (void)pIndirectDeviceAddresses; (void)pIndirectStrides; (void)ppMaxPrimitiveCounts; }
void vkCmdBuildAccelerationStructuresKHR(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkAccelerationStructureBuildGeometryInfoKHR* pInfos, const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos) { (void)commandBuffer; (void)infoCount; (void)pInfos; (void)ppBuildRangeInfos; }
void vkCmdBuildClusterAccelerationStructureIndirectNV(VkCommandBuffer commandBuffer, const VkClusterAccelerationStructureCommandsInfoNV* pCommandInfos) { (void)commandBuffer; (void)pCommandInfos; }
void vkCmdBuildMicromapsEXT(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkMicromapBuildInfoEXT* pInfos) { (void)commandBuffer; (void)infoCount; (void)pInfos; }
void vkCmdBuildPartitionedAccelerationStructuresNV(VkCommandBuffer commandBuffer, const VkBuildPartitionedAccelerationStructureInfoNV* pBuildInfo) { (void)commandBuffer; (void)pBuildInfo; }
void vkCmdClearAttachments(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkClearAttachment* pAttachments, uint32_t rectCount, const VkClearRect* pRects) { (void)commandBuffer; (void)attachmentCount; (void)pAttachments; (void)rectCount; (void)pRects; }
void vkCmdClearColorImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearColorValue* pColor, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) { (void)commandBuffer; (void)image; (void)imageLayout; (void)pColor; (void)rangeCount; (void)pRanges; }
void vkCmdClearDepthStencilImage(VkCommandBuffer commandBuffer, VkImage image, VkImageLayout imageLayout, const VkClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const VkImageSubresourceRange* pRanges) { (void)commandBuffer; (void)image; (void)imageLayout; (void)pDepthStencil; (void)rangeCount; (void)pRanges; }
void vkCmdControlVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoCodingControlInfoKHR* pCodingControlInfo) { (void)commandBuffer; (void)pCodingControlInfo; }
void vkCmdConvertCooperativeVectorMatrixNV(VkCommandBuffer commandBuffer, uint32_t infoCount, const VkConvertCooperativeVectorMatrixInfoNV* pInfos) { (void)commandBuffer; (void)infoCount; (void)pInfos; }
void vkCmdCopyAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureInfoKHR* pInfo) { (void)commandBuffer; (void)pInfo; }
void vkCmdCopyAccelerationStructureNV(VkCommandBuffer commandBuffer, VkAccelerationStructureNV dst, VkAccelerationStructureNV src, VkCopyAccelerationStructureModeKHR mode) { (void)commandBuffer; (void)dst; (void)src; (void)mode; }
void vkCmdCopyAccelerationStructureToMemoryKHR(VkCommandBuffer commandBuffer, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) { (void)commandBuffer; (void)pInfo; }
void vkCmdCopyBuffer(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferCopy* pRegions) { (void)commandBuffer; (void)srcBuffer; (void)dstBuffer; (void)regionCount; (void)pRegions; }
void vkCmdCopyBuffer2(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) { (void)commandBuffer; (void)pCopyBufferInfo; }
void vkCmdCopyBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferInfo2* pCopyBufferInfo) { (void)commandBuffer; (void)pCopyBufferInfo; }
void vkCmdCopyBufferToImage(VkCommandBuffer commandBuffer, VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkBufferImageCopy* pRegions) { (void)commandBuffer; (void)srcBuffer; (void)dstImage; (void)dstImageLayout; (void)regionCount; (void)pRegions; }
void vkCmdCopyBufferToImage2(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) { (void)commandBuffer; (void)pCopyBufferToImageInfo; }
void vkCmdCopyBufferToImage2KHR(VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo) { (void)commandBuffer; (void)pCopyBufferToImageInfo; }
void vkCmdCopyImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageCopy* pRegions) { (void)commandBuffer; (void)srcImage; (void)srcImageLayout; (void)dstImage; (void)dstImageLayout; (void)regionCount; (void)pRegions; }
void vkCmdCopyImage2(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) { (void)commandBuffer; (void)pCopyImageInfo; }
void vkCmdCopyImage2KHR(VkCommandBuffer commandBuffer, const VkCopyImageInfo2* pCopyImageInfo) { (void)commandBuffer; (void)pCopyImageInfo; }
void vkCmdCopyImageToBuffer(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer, uint32_t regionCount, const VkBufferImageCopy* pRegions) { (void)commandBuffer; (void)srcImage; (void)srcImageLayout; (void)dstBuffer; (void)regionCount; (void)pRegions; }
void vkCmdCopyImageToBuffer2(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) { (void)commandBuffer; (void)pCopyImageToBufferInfo; }
void vkCmdCopyImageToBuffer2KHR(VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo) { (void)commandBuffer; (void)pCopyImageToBufferInfo; }
void vkCmdCopyMemoryIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryIndirectInfoKHR* pCopyMemoryIndirectInfo) { (void)commandBuffer; (void)pCopyMemoryIndirectInfo; }
void vkCmdCopyMemoryIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) { (void)commandBuffer; (void)copyBufferAddress; (void)copyCount; (void)stride; }
void vkCmdCopyMemoryToAccelerationStructureKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) { (void)commandBuffer; (void)pInfo; }
void vkCmdCopyMemoryToImageIndirectKHR(VkCommandBuffer commandBuffer, const VkCopyMemoryToImageIndirectInfoKHR* pCopyMemoryToImageIndirectInfo) { (void)commandBuffer; (void)pCopyMemoryToImageIndirectInfo; }
void vkCmdCopyMemoryToImageIndirectNV(VkCommandBuffer commandBuffer, VkDeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, VkImage dstImage, VkImageLayout dstImageLayout, const VkImageSubresourceLayers* pImageSubresources) { (void)commandBuffer; (void)copyBufferAddress; (void)copyCount; (void)stride; (void)dstImage; (void)dstImageLayout; (void)pImageSubresources; }
void vkCmdCopyMemoryToMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMemoryToMicromapInfoEXT* pInfo) { (void)commandBuffer; (void)pInfo; }
void vkCmdCopyMicromapEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapInfoEXT* pInfo) { (void)commandBuffer; (void)pInfo; }
void vkCmdCopyMicromapToMemoryEXT(VkCommandBuffer commandBuffer, const VkCopyMicromapToMemoryInfoEXT* pInfo) { (void)commandBuffer; (void)pInfo; }
void vkCmdCopyQueryPoolResults(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize stride, VkQueryResultFlags flags) { (void)commandBuffer; (void)queryPool; (void)firstQuery; (void)queryCount; (void)dstBuffer; (void)dstOffset; (void)stride; (void)flags; }
void vkCmdCopyTensorARM(VkCommandBuffer commandBuffer, const VkCopyTensorInfoARM* pCopyTensorInfo) { (void)commandBuffer; (void)pCopyTensorInfo; }
void vkCmdCuLaunchKernelNVX(VkCommandBuffer commandBuffer, const VkCuLaunchInfoNVX* pLaunchInfo) { (void)commandBuffer; (void)pLaunchInfo; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
void vkCmdCudaLaunchKernelNV(VkCommandBuffer commandBuffer, const VkCudaLaunchInfoNV* pLaunchInfo) { (void)commandBuffer; (void)pLaunchInfo; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

void vkCmdDebugMarkerBeginEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) { (void)commandBuffer; (void)pMarkerInfo; }
void vkCmdDebugMarkerEndEXT(VkCommandBuffer commandBuffer) { (void)commandBuffer; }
void vkCmdDebugMarkerInsertEXT(VkCommandBuffer commandBuffer, const VkDebugMarkerMarkerInfoEXT* pMarkerInfo) { (void)commandBuffer; (void)pMarkerInfo; }
void vkCmdDecodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoDecodeInfoKHR* pDecodeInfo) { (void)commandBuffer; (void)pDecodeInfo; }
void vkCmdDecompressMemoryEXT(VkCommandBuffer commandBuffer, const VkDecompressMemoryInfoEXT* pDecompressMemoryInfoEXT) { (void)commandBuffer; (void)pDecompressMemoryInfoEXT; }
void vkCmdDecompressMemoryIndirectCountEXT(VkCommandBuffer commandBuffer, VkMemoryDecompressionMethodFlagsEXT decompressionMethod, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t maxDecompressionCount, uint32_t stride) { (void)commandBuffer; (void)decompressionMethod; (void)indirectCommandsAddress; (void)indirectCommandsCountAddress; (void)maxDecompressionCount; (void)stride; }
void vkCmdDecompressMemoryIndirectCountNV(VkCommandBuffer commandBuffer, VkDeviceAddress indirectCommandsAddress, VkDeviceAddress indirectCommandsCountAddress, uint32_t stride) { (void)commandBuffer; (void)indirectCommandsAddress; (void)indirectCommandsCountAddress; (void)stride; }
void vkCmdDecompressMemoryNV(VkCommandBuffer commandBuffer, uint32_t decompressRegionCount, const VkDecompressMemoryRegionNV* pDecompressMemoryRegions) { (void)commandBuffer; (void)decompressRegionCount; (void)pDecompressMemoryRegions; }
void vkCmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { (void)commandBuffer; (void)groupCountX; (void)groupCountY; (void)groupCountZ; }
void vkCmdDispatchBase(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { (void)commandBuffer; (void)baseGroupX; (void)baseGroupY; (void)baseGroupZ; (void)groupCountX; (void)groupCountY; (void)groupCountZ; }
void vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { (void)commandBuffer; (void)baseGroupX; (void)baseGroupY; (void)baseGroupZ; (void)groupCountX; (void)groupCountY; (void)groupCountZ; }
void vkCmdDispatchDataGraphARM(VkCommandBuffer commandBuffer, VkDataGraphPipelineSessionARM session, const VkDataGraphPipelineDispatchInfoARM* pInfo) { (void)commandBuffer; (void)session; (void)pInfo; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
void vkCmdDispatchGraphAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, const VkDispatchGraphCountInfoAMDX* pCountInfo) { (void)commandBuffer; (void)scratch; (void)scratchSize; (void)pCountInfo; }
void vkCmdDispatchGraphIndirectAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, const VkDispatchGraphCountInfoAMDX* pCountInfo) { (void)commandBuffer; (void)scratch; (void)scratchSize; (void)pCountInfo; }
void vkCmdDispatchGraphIndirectCountAMDX(VkCommandBuffer commandBuffer, VkDeviceAddress scratch, VkDeviceSize scratchSize, VkDeviceAddress countInfo) { (void)commandBuffer; (void)scratch; (void)scratchSize; (void)countInfo; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

void vkCmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) { (void)commandBuffer; (void)buffer; (void)offset; }
void vkCmdDispatchTileQCOM(VkCommandBuffer commandBuffer, const VkDispatchTileInfoQCOM* pDispatchTileInfo) { (void)commandBuffer; (void)pDispatchTileInfo; }
void vkCmdDraw(VkCommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) { (void)commandBuffer; (void)vertexCount; (void)instanceCount; (void)firstVertex; (void)firstInstance; }
void vkCmdDrawClusterHUAWEI(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { (void)commandBuffer; (void)groupCountX; (void)groupCountY; (void)groupCountZ; }
void vkCmdDrawClusterIndirectHUAWEI(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset) { (void)commandBuffer; (void)buffer; (void)offset; }
void vkCmdDrawIndexed(VkCommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) { (void)commandBuffer; (void)indexCount; (void)instanceCount; (void)firstIndex; (void)vertexOffset; (void)firstInstance; }
void vkCmdDrawIndexedIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)drawCount; (void)stride; }
void vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawIndexedIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)drawCount; (void)stride; }
void vkCmdDrawIndirectByteCountEXT(VkCommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, VkBuffer counterBuffer, VkDeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) { (void)commandBuffer; (void)instanceCount; (void)firstInstance; (void)counterBuffer; (void)counterBufferOffset; (void)counterOffset; (void)vertexStride; }
void vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawIndirectCountAMD(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) { (void)commandBuffer; (void)groupCountX; (void)groupCountY; (void)groupCountZ; }
void vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkBuffer countBuffer, VkDeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)countBuffer; (void)countBufferOffset; (void)maxDrawCount; (void)stride; }
void vkCmdDrawMeshTasksIndirectEXT(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)drawCount; (void)stride; }
void vkCmdDrawMeshTasksIndirectNV(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride) { (void)commandBuffer; (void)buffer; (void)offset; (void)drawCount; (void)stride; }
void vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask) { (void)commandBuffer; (void)taskCount; (void)firstTask; }
void vkCmdDrawMultiEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) { (void)commandBuffer; (void)drawCount; (void)pVertexInfo; (void)instanceCount; (void)firstInstance; (void)stride; }
void vkCmdDrawMultiIndexedEXT(VkCommandBuffer commandBuffer, uint32_t drawCount, const VkMultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset) { (void)commandBuffer; (void)drawCount; (void)pIndexInfo; (void)instanceCount; (void)firstInstance; (void)stride; (void)pVertexOffset; }
void vkCmdEncodeVideoKHR(VkCommandBuffer commandBuffer, const VkVideoEncodeInfoKHR* pEncodeInfo) { (void)commandBuffer; (void)pEncodeInfo; }
void vkCmdEndConditionalRenderingEXT(VkCommandBuffer commandBuffer) { (void)commandBuffer; }
void vkCmdEndDebugUtilsLabelEXT(VkCommandBuffer commandBuffer) { (void)commandBuffer; }
void vkCmdEndPerTileExecutionQCOM(VkCommandBuffer commandBuffer, const VkPerTileEndInfoQCOM* pPerTileEndInfo) { (void)commandBuffer; (void)pPerTileEndInfo; }
void vkCmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query) { (void)commandBuffer; (void)queryPool; (void)query; }
void vkCmdEndQueryIndexedEXT(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query, uint32_t index) { (void)commandBuffer; (void)queryPool; (void)query; (void)index; }
void vkCmdEndRenderPass(VkCommandBuffer commandBuffer) { (void)commandBuffer; }
void vkCmdEndRenderPass2(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) { (void)commandBuffer; (void)pSubpassEndInfo; }
void vkCmdEndRenderPass2KHR(VkCommandBuffer commandBuffer, const VkSubpassEndInfo* pSubpassEndInfo) { (void)commandBuffer; (void)pSubpassEndInfo; }
void vkCmdEndRendering(VkCommandBuffer commandBuffer) { (void)commandBuffer; }
void vkCmdEndRendering2EXT(VkCommandBuffer commandBuffer, const VkRenderingEndInfoKHR* pRenderingEndInfo) { (void)commandBuffer; (void)pRenderingEndInfo; }
void vkCmdEndRendering2KHR(VkCommandBuffer commandBuffer, const VkRenderingEndInfoKHR* pRenderingEndInfo) { (void)commandBuffer; (void)pRenderingEndInfo; }
void vkCmdEndRenderingKHR(VkCommandBuffer commandBuffer) { (void)commandBuffer; }
void vkCmdEndTransformFeedbackEXT(VkCommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const VkBuffer* pCounterBuffers, const VkDeviceSize* pCounterBufferOffsets) { (void)commandBuffer; (void)firstCounterBuffer; (void)counterBufferCount; (void)pCounterBuffers; (void)pCounterBufferOffsets; }
void vkCmdEndVideoCodingKHR(VkCommandBuffer commandBuffer, const VkVideoEndCodingInfoKHR* pEndCodingInfo) { (void)commandBuffer; (void)pEndCodingInfo; }
void vkCmdExecuteCommands(VkCommandBuffer commandBuffer, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) { (void)commandBuffer; (void)commandBufferCount; (void)pCommandBuffers; }
void vkCmdExecuteGeneratedCommandsEXT(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo) { (void)commandBuffer; (void)isPreprocessed; (void)pGeneratedCommandsInfo; }
void vkCmdExecuteGeneratedCommandsNV(VkCommandBuffer commandBuffer, VkBool32 isPreprocessed, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) { (void)commandBuffer; (void)isPreprocessed; (void)pGeneratedCommandsInfo; }
void vkCmdFillBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data) { (void)commandBuffer; (void)dstBuffer; (void)dstOffset; (void)size; (void)data; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
void vkCmdInitializeGraphScratchMemoryAMDX(VkCommandBuffer commandBuffer, VkPipeline executionGraph, VkDeviceAddress scratch, VkDeviceSize scratchSize) { (void)commandBuffer; (void)executionGraph; (void)scratch; (void)scratchSize; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

void vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer commandBuffer, const VkDebugUtilsLabelEXT* pLabelInfo) { (void)commandBuffer; (void)pLabelInfo; }
void vkCmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents) { (void)commandBuffer; (void)contents; }
void vkCmdNextSubpass2(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) { (void)commandBuffer; (void)pSubpassBeginInfo; (void)pSubpassEndInfo; }
void vkCmdNextSubpass2KHR(VkCommandBuffer commandBuffer, const VkSubpassBeginInfo* pSubpassBeginInfo, const VkSubpassEndInfo* pSubpassEndInfo) { (void)commandBuffer; (void)pSubpassBeginInfo; (void)pSubpassEndInfo; }
void vkCmdOpticalFlowExecuteNV(VkCommandBuffer commandBuffer, VkOpticalFlowSessionNV session, const VkOpticalFlowExecuteInfoNV* pExecuteInfo) { (void)commandBuffer; (void)session; (void)pExecuteInfo; }
void vkCmdPipelineBarrier(VkCommandBuffer commandBuffer, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) { (void)commandBuffer; (void)srcStageMask; (void)dstStageMask; (void)dependencyFlags; (void)memoryBarrierCount; (void)pMemoryBarriers; (void)bufferMemoryBarrierCount; (void)pBufferMemoryBarriers; (void)imageMemoryBarrierCount; (void)pImageMemoryBarriers; }
void vkCmdPipelineBarrier2(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) { (void)commandBuffer; (void)pDependencyInfo; }
void vkCmdPipelineBarrier2KHR(VkCommandBuffer commandBuffer, const VkDependencyInfo* pDependencyInfo) { (void)commandBuffer; (void)pDependencyInfo; }
void vkCmdPreprocessGeneratedCommandsEXT(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoEXT* pGeneratedCommandsInfo, VkCommandBuffer stateCommandBuffer) { (void)commandBuffer; (void)pGeneratedCommandsInfo; (void)stateCommandBuffer; }
void vkCmdPreprocessGeneratedCommandsNV(VkCommandBuffer commandBuffer, const VkGeneratedCommandsInfoNV* pGeneratedCommandsInfo) { (void)commandBuffer; (void)pGeneratedCommandsInfo; }
void vkCmdPushConstants(VkCommandBuffer commandBuffer, VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues) { (void)commandBuffer; (void)layout; (void)stageFlags; (void)offset; (void)size; (void)pValues; }
void vkCmdPushConstants2(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) { (void)commandBuffer; (void)pPushConstantsInfo; }
void vkCmdPushConstants2KHR(VkCommandBuffer commandBuffer, const VkPushConstantsInfo* pPushConstantsInfo) { (void)commandBuffer; (void)pPushConstantsInfo; }
void vkCmdPushDataEXT(VkCommandBuffer commandBuffer, const VkPushDataInfoEXT* pPushDataInfo) { (void)commandBuffer; (void)pPushDataInfo; }
void vkCmdPushDescriptorSet(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) { (void)commandBuffer; (void)pipelineBindPoint; (void)layout; (void)set; (void)descriptorWriteCount; (void)pDescriptorWrites; }
void vkCmdPushDescriptorSet2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) { (void)commandBuffer; (void)pPushDescriptorSetInfo; }
void vkCmdPushDescriptorSet2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetInfo* pPushDescriptorSetInfo) { (void)commandBuffer; (void)pPushDescriptorSetInfo; }
void vkCmdPushDescriptorSetKHR(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites) { (void)commandBuffer; (void)pipelineBindPoint; (void)layout; (void)set; (void)descriptorWriteCount; (void)pDescriptorWrites; }
void vkCmdPushDescriptorSetWithTemplate(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) { (void)commandBuffer; (void)descriptorUpdateTemplate; (void)layout; (void)set; (void)pData; }
void vkCmdPushDescriptorSetWithTemplate2(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) { (void)commandBuffer; (void)pPushDescriptorSetWithTemplateInfo; }
void vkCmdPushDescriptorSetWithTemplate2KHR(VkCommandBuffer commandBuffer, const VkPushDescriptorSetWithTemplateInfo* pPushDescriptorSetWithTemplateInfo) { (void)commandBuffer; (void)pPushDescriptorSetWithTemplateInfo; }
void vkCmdPushDescriptorSetWithTemplateKHR(VkCommandBuffer commandBuffer, VkDescriptorUpdateTemplate descriptorUpdateTemplate, VkPipelineLayout layout, uint32_t set, const void* pData) { (void)commandBuffer; (void)descriptorUpdateTemplate; (void)layout; (void)set; (void)pData; }
void vkCmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) { (void)commandBuffer; (void)event; (void)stageMask; }
void vkCmdResetEvent2(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) { (void)commandBuffer; (void)event; (void)stageMask; }
void vkCmdResetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags2 stageMask) { (void)commandBuffer; (void)event; (void)stageMask; }
void vkCmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) { (void)commandBuffer; (void)queryPool; (void)firstQuery; (void)queryCount; }
void vkCmdResolveImage(VkCommandBuffer commandBuffer, VkImage srcImage, VkImageLayout srcImageLayout, VkImage dstImage, VkImageLayout dstImageLayout, uint32_t regionCount, const VkImageResolve* pRegions) { (void)commandBuffer; (void)srcImage; (void)srcImageLayout; (void)dstImage; (void)dstImageLayout; (void)regionCount; (void)pRegions; }
void vkCmdResolveImage2(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) { (void)commandBuffer; (void)pResolveImageInfo; }
void vkCmdResolveImage2KHR(VkCommandBuffer commandBuffer, const VkResolveImageInfo2* pResolveImageInfo) { (void)commandBuffer; (void)pResolveImageInfo; }
void vkCmdSetAlphaToCoverageEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToCoverageEnable) { (void)commandBuffer; (void)alphaToCoverageEnable; }
void vkCmdSetAlphaToOneEnableEXT(VkCommandBuffer commandBuffer, VkBool32 alphaToOneEnable) { (void)commandBuffer; (void)alphaToOneEnable; }
void vkCmdSetAttachmentFeedbackLoopEnableEXT(VkCommandBuffer commandBuffer, VkImageAspectFlags aspectMask) { (void)commandBuffer; (void)aspectMask; }
void vkCmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]) { (void)commandBuffer; (void)blendConstants; }
void vkCmdSetCheckpointNV(VkCommandBuffer commandBuffer, const void* pCheckpointMarker) { (void)commandBuffer; (void)pCheckpointMarker; }
void vkCmdSetCoarseSampleOrderNV(VkCommandBuffer commandBuffer, VkCoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const VkCoarseSampleOrderCustomNV* pCustomSampleOrders) { (void)commandBuffer; (void)sampleOrderType; (void)customSampleOrderCount; (void)pCustomSampleOrders; }
void vkCmdSetColorBlendAdvancedEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendAdvancedEXT* pColorBlendAdvanced) { (void)commandBuffer; (void)firstAttachment; (void)attachmentCount; (void)pColorBlendAdvanced; }
void vkCmdSetColorBlendEnableEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkBool32* pColorBlendEnables) { (void)commandBuffer; (void)firstAttachment; (void)attachmentCount; (void)pColorBlendEnables; }
void vkCmdSetColorBlendEquationEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorBlendEquationEXT* pColorBlendEquations) { (void)commandBuffer; (void)firstAttachment; (void)attachmentCount; (void)pColorBlendEquations; }
void vkCmdSetColorWriteEnableEXT(VkCommandBuffer commandBuffer, uint32_t attachmentCount, const VkBool32* pColorWriteEnables) { (void)commandBuffer; (void)attachmentCount; (void)pColorWriteEnables; }
void vkCmdSetColorWriteMaskEXT(VkCommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const VkColorComponentFlags* pColorWriteMasks) { (void)commandBuffer; (void)firstAttachment; (void)attachmentCount; (void)pColorWriteMasks; }
void vkCmdSetComputeOccupancyPriorityNV(VkCommandBuffer commandBuffer, const VkComputeOccupancyPriorityParametersNV* pParameters) { (void)commandBuffer; (void)pParameters; }
void vkCmdSetConservativeRasterizationModeEXT(VkCommandBuffer commandBuffer, VkConservativeRasterizationModeEXT conservativeRasterizationMode) { (void)commandBuffer; (void)conservativeRasterizationMode; }
void vkCmdSetCoverageModulationModeNV(VkCommandBuffer commandBuffer, VkCoverageModulationModeNV coverageModulationMode) { (void)commandBuffer; (void)coverageModulationMode; }
void vkCmdSetCoverageModulationTableEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageModulationTableEnable) { (void)commandBuffer; (void)coverageModulationTableEnable; }
void vkCmdSetCoverageModulationTableNV(VkCommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable) { (void)commandBuffer; (void)coverageModulationTableCount; (void)pCoverageModulationTable; }
void vkCmdSetCoverageReductionModeNV(VkCommandBuffer commandBuffer, VkCoverageReductionModeNV coverageReductionMode) { (void)commandBuffer; (void)coverageReductionMode; }
void vkCmdSetCoverageToColorEnableNV(VkCommandBuffer commandBuffer, VkBool32 coverageToColorEnable) { (void)commandBuffer; (void)coverageToColorEnable; }
void vkCmdSetCoverageToColorLocationNV(VkCommandBuffer commandBuffer, uint32_t coverageToColorLocation) { (void)commandBuffer; (void)coverageToColorLocation; }
void vkCmdSetCullMode(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) { (void)commandBuffer; (void)cullMode; }
void vkCmdSetCullModeEXT(VkCommandBuffer commandBuffer, VkCullModeFlags cullMode) { (void)commandBuffer; (void)cullMode; }
void vkCmdSetDepthBias(VkCommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) { (void)commandBuffer; (void)depthBiasConstantFactor; (void)depthBiasClamp; (void)depthBiasSlopeFactor; }
void vkCmdSetDepthBias2EXT(VkCommandBuffer commandBuffer, const VkDepthBiasInfoEXT* pDepthBiasInfo) { (void)commandBuffer; (void)pDepthBiasInfo; }
void vkCmdSetDepthBiasEnable(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) { (void)commandBuffer; (void)depthBiasEnable; }
void vkCmdSetDepthBiasEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBiasEnable) { (void)commandBuffer; (void)depthBiasEnable; }
void vkCmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds) { (void)commandBuffer; (void)minDepthBounds; (void)maxDepthBounds; }
void vkCmdSetDepthBoundsTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) { (void)commandBuffer; (void)depthBoundsTestEnable; }
void vkCmdSetDepthBoundsTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthBoundsTestEnable) { (void)commandBuffer; (void)depthBoundsTestEnable; }
void vkCmdSetDepthClampEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClampEnable) { (void)commandBuffer; (void)depthClampEnable; }
void vkCmdSetDepthClampRangeEXT(VkCommandBuffer commandBuffer, VkDepthClampModeEXT depthClampMode, const VkDepthClampRangeEXT* pDepthClampRange) { (void)commandBuffer; (void)depthClampMode; (void)pDepthClampRange; }
void vkCmdSetDepthClipEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthClipEnable) { (void)commandBuffer; (void)depthClipEnable; }
void vkCmdSetDepthClipNegativeOneToOneEXT(VkCommandBuffer commandBuffer, VkBool32 negativeOneToOne) { (void)commandBuffer; (void)negativeOneToOne; }
void vkCmdSetDepthCompareOp(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) { (void)commandBuffer; (void)depthCompareOp; }
void vkCmdSetDepthCompareOpEXT(VkCommandBuffer commandBuffer, VkCompareOp depthCompareOp) { (void)commandBuffer; (void)depthCompareOp; }
void vkCmdSetDepthTestEnable(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) { (void)commandBuffer; (void)depthTestEnable; }
void vkCmdSetDepthTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthTestEnable) { (void)commandBuffer; (void)depthTestEnable; }
void vkCmdSetDepthWriteEnable(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) { (void)commandBuffer; (void)depthWriteEnable; }
void vkCmdSetDepthWriteEnableEXT(VkCommandBuffer commandBuffer, VkBool32 depthWriteEnable) { (void)commandBuffer; (void)depthWriteEnable; }
void vkCmdSetDescriptorBufferOffsets2EXT(VkCommandBuffer commandBuffer, const VkSetDescriptorBufferOffsetsInfoEXT* pSetDescriptorBufferOffsetsInfo) { (void)commandBuffer; (void)pSetDescriptorBufferOffsetsInfo; }
void vkCmdSetDescriptorBufferOffsetsEXT(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const VkDeviceSize* pOffsets) { (void)commandBuffer; (void)pipelineBindPoint; (void)layout; (void)firstSet; (void)setCount; (void)pBufferIndices; (void)pOffsets; }
void vkCmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask) { (void)commandBuffer; (void)deviceMask; }
void vkCmdSetDeviceMaskKHR(VkCommandBuffer commandBuffer, uint32_t deviceMask) { (void)commandBuffer; (void)deviceMask; }
void vkCmdSetDiscardRectangleEXT(VkCommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const VkRect2D* pDiscardRectangles) { (void)commandBuffer; (void)firstDiscardRectangle; (void)discardRectangleCount; (void)pDiscardRectangles; }
void vkCmdSetDiscardRectangleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 discardRectangleEnable) { (void)commandBuffer; (void)discardRectangleEnable; }
void vkCmdSetDiscardRectangleModeEXT(VkCommandBuffer commandBuffer, VkDiscardRectangleModeEXT discardRectangleMode) { (void)commandBuffer; (void)discardRectangleMode; }
void vkCmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask) { (void)commandBuffer; (void)event; (void)stageMask; }
void vkCmdSetEvent2(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) { (void)commandBuffer; (void)event; (void)pDependencyInfo; }
void vkCmdSetEvent2KHR(VkCommandBuffer commandBuffer, VkEvent event, const VkDependencyInfo* pDependencyInfo) { (void)commandBuffer; (void)event; (void)pDependencyInfo; }
void vkCmdSetExclusiveScissorEnableNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkBool32* pExclusiveScissorEnables) { (void)commandBuffer; (void)firstExclusiveScissor; (void)exclusiveScissorCount; (void)pExclusiveScissorEnables; }
void vkCmdSetExclusiveScissorNV(VkCommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const VkRect2D* pExclusiveScissors) { (void)commandBuffer; (void)firstExclusiveScissor; (void)exclusiveScissorCount; (void)pExclusiveScissors; }
void vkCmdSetExtraPrimitiveOverestimationSizeEXT(VkCommandBuffer commandBuffer, float extraPrimitiveOverestimationSize) { (void)commandBuffer; (void)extraPrimitiveOverestimationSize; }
void vkCmdSetFragmentShadingRateEnumNV(VkCommandBuffer commandBuffer, VkFragmentShadingRateNV shadingRate, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) { (void)commandBuffer; (void)shadingRate; (void)combinerOps; }
void vkCmdSetFragmentShadingRateKHR(VkCommandBuffer commandBuffer, const VkExtent2D* pFragmentSize, const VkFragmentShadingRateCombinerOpKHR combinerOps[2]) { (void)commandBuffer; (void)pFragmentSize; (void)combinerOps; }
void vkCmdSetFrontFace(VkCommandBuffer commandBuffer, VkFrontFace frontFace) { (void)commandBuffer; (void)frontFace; }
void vkCmdSetFrontFaceEXT(VkCommandBuffer commandBuffer, VkFrontFace frontFace) { (void)commandBuffer; (void)frontFace; }
void vkCmdSetLineRasterizationModeEXT(VkCommandBuffer commandBuffer, VkLineRasterizationModeEXT lineRasterizationMode) { (void)commandBuffer; (void)lineRasterizationMode; }
void vkCmdSetLineStipple(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) { (void)commandBuffer; (void)lineStippleFactor; (void)lineStipplePattern; }
void vkCmdSetLineStippleEXT(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) { (void)commandBuffer; (void)lineStippleFactor; (void)lineStipplePattern; }
void vkCmdSetLineStippleEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stippledLineEnable) { (void)commandBuffer; (void)stippledLineEnable; }
void vkCmdSetLineStippleKHR(VkCommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern) { (void)commandBuffer; (void)lineStippleFactor; (void)lineStipplePattern; }
void vkCmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth) { (void)commandBuffer; (void)lineWidth; }
void vkCmdSetLogicOpEXT(VkCommandBuffer commandBuffer, VkLogicOp logicOp) { (void)commandBuffer; (void)logicOp; }
void vkCmdSetLogicOpEnableEXT(VkCommandBuffer commandBuffer, VkBool32 logicOpEnable) { (void)commandBuffer; (void)logicOpEnable; }
void vkCmdSetPatchControlPointsEXT(VkCommandBuffer commandBuffer, uint32_t patchControlPoints) { (void)commandBuffer; (void)patchControlPoints; }
VkResult vkCmdSetPerformanceMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceMarkerInfoINTEL* pMarkerInfo) { (void)commandBuffer; (void)pMarkerInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCmdSetPerformanceOverrideINTEL(VkCommandBuffer commandBuffer, const VkPerformanceOverrideInfoINTEL* pOverrideInfo) { (void)commandBuffer; (void)pOverrideInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCmdSetPerformanceStreamMarkerINTEL(VkCommandBuffer commandBuffer, const VkPerformanceStreamMarkerInfoINTEL* pMarkerInfo) { (void)commandBuffer; (void)pMarkerInfo; return VK_ERROR_INITIALIZATION_FAILED; }
void vkCmdSetPolygonModeEXT(VkCommandBuffer commandBuffer, VkPolygonMode polygonMode) { (void)commandBuffer; (void)polygonMode; }
void vkCmdSetPrimitiveRestartEnable(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) { (void)commandBuffer; (void)primitiveRestartEnable; }
void vkCmdSetPrimitiveRestartEnableEXT(VkCommandBuffer commandBuffer, VkBool32 primitiveRestartEnable) { (void)commandBuffer; (void)primitiveRestartEnable; }
void vkCmdSetPrimitiveTopology(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) { (void)commandBuffer; (void)primitiveTopology; }
void vkCmdSetPrimitiveTopologyEXT(VkCommandBuffer commandBuffer, VkPrimitiveTopology primitiveTopology) { (void)commandBuffer; (void)primitiveTopology; }
void vkCmdSetProvokingVertexModeEXT(VkCommandBuffer commandBuffer, VkProvokingVertexModeEXT provokingVertexMode) { (void)commandBuffer; (void)provokingVertexMode; }
void vkCmdSetRasterizationSamplesEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits rasterizationSamples) { (void)commandBuffer; (void)rasterizationSamples; }
void vkCmdSetRasterizationStreamEXT(VkCommandBuffer commandBuffer, uint32_t rasterizationStream) { (void)commandBuffer; (void)rasterizationStream; }
void vkCmdSetRasterizerDiscardEnable(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) { (void)commandBuffer; (void)rasterizerDiscardEnable; }
void vkCmdSetRasterizerDiscardEnableEXT(VkCommandBuffer commandBuffer, VkBool32 rasterizerDiscardEnable) { (void)commandBuffer; (void)rasterizerDiscardEnable; }
void vkCmdSetRayTracingPipelineStackSizeKHR(VkCommandBuffer commandBuffer, uint32_t pipelineStackSize) { (void)commandBuffer; (void)pipelineStackSize; }
void vkCmdSetRenderingAttachmentLocations(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) { (void)commandBuffer; (void)pLocationInfo; }
void vkCmdSetRenderingAttachmentLocationsKHR(VkCommandBuffer commandBuffer, const VkRenderingAttachmentLocationInfo* pLocationInfo) { (void)commandBuffer; (void)pLocationInfo; }
void vkCmdSetRenderingInputAttachmentIndices(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) { (void)commandBuffer; (void)pInputAttachmentIndexInfo; }
void vkCmdSetRenderingInputAttachmentIndicesKHR(VkCommandBuffer commandBuffer, const VkRenderingInputAttachmentIndexInfo* pInputAttachmentIndexInfo) { (void)commandBuffer; (void)pInputAttachmentIndexInfo; }
void vkCmdSetRepresentativeFragmentTestEnableNV(VkCommandBuffer commandBuffer, VkBool32 representativeFragmentTestEnable) { (void)commandBuffer; (void)representativeFragmentTestEnable; }
void vkCmdSetSampleLocationsEXT(VkCommandBuffer commandBuffer, const VkSampleLocationsInfoEXT* pSampleLocationsInfo) { (void)commandBuffer; (void)pSampleLocationsInfo; }
void vkCmdSetSampleLocationsEnableEXT(VkCommandBuffer commandBuffer, VkBool32 sampleLocationsEnable) { (void)commandBuffer; (void)sampleLocationsEnable; }
void vkCmdSetSampleMaskEXT(VkCommandBuffer commandBuffer, VkSampleCountFlagBits samples, const VkSampleMask* pSampleMask) { (void)commandBuffer; (void)samples; (void)pSampleMask; }
void vkCmdSetScissor(VkCommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const VkRect2D* pScissors) { (void)commandBuffer; (void)firstScissor; (void)scissorCount; (void)pScissors; }
void vkCmdSetScissorWithCount(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) { (void)commandBuffer; (void)scissorCount; (void)pScissors; }
void vkCmdSetScissorWithCountEXT(VkCommandBuffer commandBuffer, uint32_t scissorCount, const VkRect2D* pScissors) { (void)commandBuffer; (void)scissorCount; (void)pScissors; }
void vkCmdSetShadingRateImageEnableNV(VkCommandBuffer commandBuffer, VkBool32 shadingRateImageEnable) { (void)commandBuffer; (void)shadingRateImageEnable; }
void vkCmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask) { (void)commandBuffer; (void)faceMask; (void)compareMask; }
void vkCmdSetStencilOp(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { (void)commandBuffer; (void)faceMask; (void)failOp; (void)passOp; (void)depthFailOp; (void)compareOp; }
void vkCmdSetStencilOpEXT(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, VkStencilOp failOp, VkStencilOp passOp, VkStencilOp depthFailOp, VkCompareOp compareOp) { (void)commandBuffer; (void)faceMask; (void)failOp; (void)passOp; (void)depthFailOp; (void)compareOp; }
void vkCmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference) { (void)commandBuffer; (void)faceMask; (void)reference; }
void vkCmdSetStencilTestEnable(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) { (void)commandBuffer; (void)stencilTestEnable; }
void vkCmdSetStencilTestEnableEXT(VkCommandBuffer commandBuffer, VkBool32 stencilTestEnable) { (void)commandBuffer; (void)stencilTestEnable; }
void vkCmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask) { (void)commandBuffer; (void)faceMask; (void)writeMask; }
void vkCmdSetTessellationDomainOriginEXT(VkCommandBuffer commandBuffer, VkTessellationDomainOrigin domainOrigin) { (void)commandBuffer; (void)domainOrigin; }
void vkCmdSetVertexInputEXT(VkCommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const VkVertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount, const VkVertexInputAttributeDescription2EXT* pVertexAttributeDescriptions) { (void)commandBuffer; (void)vertexBindingDescriptionCount; (void)pVertexBindingDescriptions; (void)vertexAttributeDescriptionCount; (void)pVertexAttributeDescriptions; }
void vkCmdSetViewport(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewport* pViewports) { (void)commandBuffer; (void)firstViewport; (void)viewportCount; (void)pViewports; }
void vkCmdSetViewportShadingRatePaletteNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkShadingRatePaletteNV* pShadingRatePalettes) { (void)commandBuffer; (void)firstViewport; (void)viewportCount; (void)pShadingRatePalettes; }
void vkCmdSetViewportSwizzleNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportSwizzleNV* pViewportSwizzles) { (void)commandBuffer; (void)firstViewport; (void)viewportCount; (void)pViewportSwizzles; }
void vkCmdSetViewportWScalingEnableNV(VkCommandBuffer commandBuffer, VkBool32 viewportWScalingEnable) { (void)commandBuffer; (void)viewportWScalingEnable; }
void vkCmdSetViewportWScalingNV(VkCommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const VkViewportWScalingNV* pViewportWScalings) { (void)commandBuffer; (void)firstViewport; (void)viewportCount; (void)pViewportWScalings; }
void vkCmdSetViewportWithCount(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) { (void)commandBuffer; (void)viewportCount; (void)pViewports; }
void vkCmdSetViewportWithCountEXT(VkCommandBuffer commandBuffer, uint32_t viewportCount, const VkViewport* pViewports) { (void)commandBuffer; (void)viewportCount; (void)pViewports; }
void vkCmdSubpassShadingHUAWEI(VkCommandBuffer commandBuffer) { (void)commandBuffer; }
void vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer, VkDeviceAddress indirectDeviceAddress) { (void)commandBuffer; (void)indirectDeviceAddress; }
void vkCmdTraceRaysIndirectKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, VkDeviceAddress indirectDeviceAddress) { (void)commandBuffer; (void)pRaygenShaderBindingTable; (void)pMissShaderBindingTable; (void)pHitShaderBindingTable; (void)pCallableShaderBindingTable; (void)indirectDeviceAddress; }
void vkCmdTraceRaysKHR(VkCommandBuffer commandBuffer, const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable, const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) { (void)commandBuffer; (void)pRaygenShaderBindingTable; (void)pMissShaderBindingTable; (void)pHitShaderBindingTable; (void)pCallableShaderBindingTable; (void)width; (void)height; (void)depth; }
void vkCmdTraceRaysNV(VkCommandBuffer commandBuffer, VkBuffer raygenShaderBindingTableBuffer, VkDeviceSize raygenShaderBindingOffset, VkBuffer missShaderBindingTableBuffer, VkDeviceSize missShaderBindingOffset, VkDeviceSize missShaderBindingStride, VkBuffer hitShaderBindingTableBuffer, VkDeviceSize hitShaderBindingOffset, VkDeviceSize hitShaderBindingStride, VkBuffer callableShaderBindingTableBuffer, VkDeviceSize callableShaderBindingOffset, VkDeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) { (void)commandBuffer; (void)raygenShaderBindingTableBuffer; (void)raygenShaderBindingOffset; (void)missShaderBindingTableBuffer; (void)missShaderBindingOffset; (void)missShaderBindingStride; (void)hitShaderBindingTableBuffer; (void)hitShaderBindingOffset; (void)hitShaderBindingStride; (void)callableShaderBindingTableBuffer; (void)callableShaderBindingOffset; (void)callableShaderBindingStride; (void)width; (void)height; (void)depth; }
void vkCmdUpdateBuffer(VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData) { (void)commandBuffer; (void)dstBuffer; (void)dstOffset; (void)dataSize; (void)pData; }
void vkCmdUpdatePipelineIndirectBufferNV(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) { (void)commandBuffer; (void)pipelineBindPoint; (void)pipeline; }
void vkCmdWaitEvents(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const VkMemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount, const VkBufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const VkImageMemoryBarrier* pImageMemoryBarriers) { (void)commandBuffer; (void)eventCount; (void)pEvents; (void)srcStageMask; (void)dstStageMask; (void)memoryBarrierCount; (void)pMemoryBarriers; (void)bufferMemoryBarrierCount; (void)pBufferMemoryBarriers; (void)imageMemoryBarrierCount; (void)pImageMemoryBarriers; }
void vkCmdWaitEvents2(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) { (void)commandBuffer; (void)eventCount; (void)pEvents; (void)pDependencyInfos; }
void vkCmdWaitEvents2KHR(VkCommandBuffer commandBuffer, uint32_t eventCount, const VkEvent* pEvents, const VkDependencyInfo* pDependencyInfos) { (void)commandBuffer; (void)eventCount; (void)pEvents; (void)pDependencyInfos; }
void vkCmdWriteAccelerationStructuresPropertiesKHR(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) { (void)commandBuffer; (void)accelerationStructureCount; (void)pAccelerationStructures; (void)queryType; (void)queryPool; (void)firstQuery; }
void vkCmdWriteAccelerationStructuresPropertiesNV(VkCommandBuffer commandBuffer, uint32_t accelerationStructureCount, const VkAccelerationStructureNV* pAccelerationStructures, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) { (void)commandBuffer; (void)accelerationStructureCount; (void)pAccelerationStructures; (void)queryType; (void)queryPool; (void)firstQuery; }
void vkCmdWriteBufferMarker2AMD(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { (void)commandBuffer; (void)stage; (void)dstBuffer; (void)dstOffset; (void)marker; }
void vkCmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) { (void)commandBuffer; (void)pipelineStage; (void)dstBuffer; (void)dstOffset; (void)marker; }
void vkCmdWriteMicromapsPropertiesEXT(VkCommandBuffer commandBuffer, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, VkQueryPool queryPool, uint32_t firstQuery) { (void)commandBuffer; (void)micromapCount; (void)pMicromaps; (void)queryType; (void)queryPool; (void)firstQuery; }
void vkCmdWriteTimestamp(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage, VkQueryPool queryPool, uint32_t query) { (void)commandBuffer; (void)pipelineStage; (void)queryPool; (void)query; }
void vkCmdWriteTimestamp2(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) { (void)commandBuffer; (void)stage; (void)queryPool; (void)query; }
void vkCmdWriteTimestamp2KHR(VkCommandBuffer commandBuffer, VkPipelineStageFlags2 stage, VkQueryPool queryPool, uint32_t query) { (void)commandBuffer; (void)stage; (void)queryPool; (void)query; }
VkResult vkCompileDeferredNV(VkDevice device, VkPipeline pipeline, uint32_t shader) { (void)device; (void)pipeline; (void)shader; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkConvertCooperativeVectorMatrixNV(VkDevice device, const VkConvertCooperativeVectorMatrixInfoNV* pInfo) { (void)device; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureInfoKHR* pInfo) { (void)device; (void)deferredOperation; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyAccelerationStructureToMemoryKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyAccelerationStructureToMemoryInfoKHR* pInfo) { (void)device; (void)deferredOperation; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyImageToImage(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) { (void)device; (void)pCopyImageToImageInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyImageToImageEXT(VkDevice device, const VkCopyImageToImageInfo* pCopyImageToImageInfo) { (void)device; (void)pCopyImageToImageInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyImageToMemory(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) { (void)device; (void)pCopyImageToMemoryInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyImageToMemoryEXT(VkDevice device, const VkCopyImageToMemoryInfo* pCopyImageToMemoryInfo) { (void)device; (void)pCopyImageToMemoryInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyMemoryToAccelerationStructureKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToAccelerationStructureInfoKHR* pInfo) { (void)device; (void)deferredOperation; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyMemoryToImage(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) { (void)device; (void)pCopyMemoryToImageInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyMemoryToImageEXT(VkDevice device, const VkCopyMemoryToImageInfo* pCopyMemoryToImageInfo) { (void)device; (void)pCopyMemoryToImageInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyMemoryToMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMemoryToMicromapInfoEXT* pInfo) { (void)device; (void)deferredOperation; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyMicromapEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapInfoEXT* pInfo) { (void)device; (void)deferredOperation; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCopyMicromapToMemoryEXT(VkDevice device, VkDeferredOperationKHR deferredOperation, const VkCopyMicromapToMemoryInfoEXT* pInfo) { (void)device; (void)deferredOperation; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateAccelerationStructureKHR(VkDevice device, const VkAccelerationStructureCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureKHR* pAccelerationStructure) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pAccelerationStructure; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateAccelerationStructureNV(VkDevice device, const VkAccelerationStructureCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkAccelerationStructureNV* pAccelerationStructure) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pAccelerationStructure; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_ANDROID_KHR
VkResult vkCreateAndroidSurfaceKHR(VkInstance instance, const VkAndroidSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

VkResult vkCreateBuffer(VkDevice device, const VkBufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBuffer* pBuffer) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pBuffer; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult vkCreateBufferCollectionFUCHSIA(VkDevice device, const VkBufferCollectionCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferCollectionFUCHSIA* pCollection) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pCollection; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

VkResult vkCreateBufferView(VkDevice device, const VkBufferViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkBufferView* pView) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pView; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pCommandPool; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { (void)device; (void)pipelineCache; (void)createInfoCount; (void)pCreateInfos; (void)pAllocator; (void)pPipelines; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateCuFunctionNVX(VkDevice device, const VkCuFunctionCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuFunctionNVX* pFunction) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pFunction; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateCuModuleNVX(VkDevice device, const VkCuModuleCreateInfoNVX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCuModuleNVX* pModule) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pModule; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
VkResult vkCreateCudaFunctionNV(VkDevice device, const VkCudaFunctionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaFunctionNV* pFunction) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pFunction; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateCudaModuleNV(VkDevice device, const VkCudaModuleCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkCudaModuleNV* pModule) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pModule; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

VkResult vkCreateDataGraphPipelineSessionARM(VkDevice device, const VkDataGraphPipelineSessionCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDataGraphPipelineSessionARM* pSession) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pSession; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDataGraphPipelinesARM(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkDataGraphPipelineCreateInfoARM* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { (void)device; (void)deferredOperation; (void)pipelineCache; (void)createInfoCount; (void)pCreateInfos; (void)pAllocator; (void)pPipelines; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pCallback; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pMessenger; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDeferredOperationKHR(VkDevice device, const VkAllocationCallbacks* pAllocator, VkDeferredOperationKHR* pDeferredOperation) { (void)device; (void)pAllocator; (void)pDeferredOperation; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDescriptorPool(VkDevice device, const VkDescriptorPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorPool* pDescriptorPool) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pDescriptorPool; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDescriptorSetLayout(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorSetLayout* pSetLayout) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pSetLayout; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDescriptorUpdateTemplate(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pDescriptorUpdateTemplate; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDescriptorUpdateTemplateKHR(VkDevice device, const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pDescriptorUpdateTemplate; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) { (void)physicalDevice; (void)pCreateInfo; (void)pAllocator; (void)pDevice; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
VkResult vkCreateDirectFBSurfaceEXT(VkInstance instance, const VkDirectFBSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_DIRECTFB_EXT */

VkResult vkCreateDisplayModeKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, const VkDisplayModeCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDisplayModeKHR* pMode) { (void)physicalDevice; (void)display; (void)pCreateInfo; (void)pAllocator; (void)pMode; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateDisplayPlaneSurfaceKHR(VkInstance instance, const VkDisplaySurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateEvent(VkDevice device, const VkEventCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkEvent* pEvent) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pEvent; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
VkResult vkCreateExecutionGraphPipelinesAMDX(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkExecutionGraphPipelineCreateInfoAMDX* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { (void)device; (void)pipelineCache; (void)createInfoCount; (void)pCreateInfos; (void)pAllocator; (void)pPipelines; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

VkResult vkCreateExternalComputeQueueNV(VkDevice device, const VkExternalComputeQueueCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkExternalComputeQueueNV* pExternalQueue) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pExternalQueue; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateFence(VkDevice device, const VkFenceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pFence; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateFramebuffer(VkDevice device, const VkFramebufferCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkFramebuffer* pFramebuffer) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pFramebuffer; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { (void)device; (void)pipelineCache; (void)createInfoCount; (void)pCreateInfos; (void)pAllocator; (void)pPipelines; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateHeadlessSurfaceEXT(VkInstance instance, const VkHeadlessSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_IOS_MVK
VkResult vkCreateIOSSurfaceMVK(VkInstance instance, const VkIOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_IOS_MVK */

VkResult vkCreateImage(VkDevice device, const VkImageCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImage* pImage) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pImage; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult vkCreateImagePipeSurfaceFUCHSIA(VkInstance instance, const VkImagePipeSurfaceCreateInfoFUCHSIA* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

VkResult vkCreateImageView(VkDevice device, const VkImageViewCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkImageView* pView) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pView; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateIndirectCommandsLayoutEXT(VkDevice device, const VkIndirectCommandsLayoutCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutEXT* pIndirectCommandsLayout) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pIndirectCommandsLayout; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateIndirectCommandsLayoutNV(VkDevice device, const VkIndirectCommandsLayoutCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectCommandsLayoutNV* pIndirectCommandsLayout) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pIndirectCommandsLayout; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateIndirectExecutionSetEXT(VkDevice device, const VkIndirectExecutionSetCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkIndirectExecutionSetEXT* pIndirectExecutionSet) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pIndirectExecutionSet; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) { (void)pCreateInfo; (void)pAllocator; (void)pInstance; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_MACOS_MVK
VkResult vkCreateMacOSSurfaceMVK(VkInstance instance, const VkMacOSSurfaceCreateInfoMVK* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_MACOS_MVK */

#ifdef VK_USE_PLATFORM_METAL_EXT
VkResult vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_METAL_EXT */

VkResult vkCreateMicromapEXT(VkDevice device, const VkMicromapCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkMicromapEXT* pMicromap) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pMicromap; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateOpticalFlowSessionNV(VkDevice device, const VkOpticalFlowSessionCreateInfoNV* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkOpticalFlowSessionNV* pSession) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pSession; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreatePipelineBinariesKHR(VkDevice device, const VkPipelineBinaryCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineBinaryHandlesInfoKHR* pBinaries) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pBinaries; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreatePipelineCache(VkDevice device, const VkPipelineCacheCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineCache* pPipelineCache) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pPipelineCache; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreatePipelineLayout(VkDevice device, const VkPipelineLayoutCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPipelineLayout* pPipelineLayout) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pPipelineLayout; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreatePrivateDataSlot(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pPrivateDataSlot; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreatePrivateDataSlotEXT(VkDevice device, const VkPrivateDataSlotCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkPrivateDataSlot* pPrivateDataSlot) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pPrivateDataSlot; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateQueryPool(VkDevice device, const VkQueryPoolCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkQueryPool* pQueryPool) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pQueryPool; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateRayTracingPipelinesKHR(VkDevice device, VkDeferredOperationKHR deferredOperation, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { (void)device; (void)deferredOperation; (void)pipelineCache; (void)createInfoCount; (void)pCreateInfos; (void)pAllocator; (void)pPipelines; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateRayTracingPipelinesNV(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount, const VkRayTracingPipelineCreateInfoNV* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines) { (void)device; (void)pipelineCache; (void)createInfoCount; (void)pCreateInfos; (void)pAllocator; (void)pPipelines; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateRenderPass(VkDevice device, const VkRenderPassCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pRenderPass; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateRenderPass2(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pRenderPass; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateRenderPass2KHR(VkDevice device, const VkRenderPassCreateInfo2* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkRenderPass* pRenderPass) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pRenderPass; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateSampler(VkDevice device, const VkSamplerCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSampler* pSampler) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pSampler; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateSamplerYcbcrConversion(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pYcbcrConversion; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateSamplerYcbcrConversionKHR(VkDevice device, const VkSamplerYcbcrConversionCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSamplerYcbcrConversion* pYcbcrConversion) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pYcbcrConversion; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_SCREEN_QNX
VkResult vkCreateScreenSurfaceQNX(VkInstance instance, const VkScreenSurfaceCreateInfoQNX* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_SCREEN_QNX */

VkResult vkCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pSemaphore; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pShaderModule; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateShadersEXT(VkDevice device, uint32_t createInfoCount, const VkShaderCreateInfoEXT* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkShaderEXT* pShaders) { (void)device; (void)createInfoCount; (void)pCreateInfos; (void)pAllocator; (void)pShaders; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateSharedSwapchainsKHR(VkDevice device, uint32_t swapchainCount, const VkSwapchainCreateInfoKHR* pCreateInfos, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchains) { (void)device; (void)swapchainCount; (void)pCreateInfos; (void)pAllocator; (void)pSwapchains; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_GGP
VkResult vkCreateStreamDescriptorSurfaceGGP(VkInstance instance, const VkStreamDescriptorSurfaceCreateInfoGGP* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_GGP */

#ifdef VK_USE_PLATFORM_OHOS
VkResult vkCreateSurfaceOHOS(VkInstance instance, const VkSurfaceCreateInfoOHOS* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_OHOS */

VkResult vkCreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pSwapchain; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateTensorARM(VkDevice device, const VkTensorCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorARM* pTensor) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pTensor; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateTensorViewARM(VkDevice device, const VkTensorViewCreateInfoARM* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkTensorViewARM* pView) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pView; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateValidationCacheEXT(VkDevice device, const VkValidationCacheCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkValidationCacheEXT* pValidationCache) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pValidationCache; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_VI_NN
VkResult vkCreateViSurfaceNN(VkInstance instance, const VkViSurfaceCreateInfoNN* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_VI_NN */

VkResult vkCreateVideoSessionKHR(VkDevice device, const VkVideoSessionCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionKHR* pVideoSession) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pVideoSession; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkCreateVideoSessionParametersKHR(VkDevice device, const VkVideoSessionParametersCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkVideoSessionParametersKHR* pVideoSessionParameters) { (void)device; (void)pCreateInfo; (void)pAllocator; (void)pVideoSessionParameters; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
VkResult vkCreateWaylandSurfaceKHR(VkInstance instance, const VkWaylandSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkCreateWin32SurfaceKHR(VkInstance instance, const VkWin32SurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
VkResult vkCreateXcbSurfaceKHR(VkInstance instance, const VkXcbSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_XLIB_KHR
VkResult vkCreateXlibSurfaceKHR(VkInstance instance, const VkXlibSurfaceCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface) { (void)instance; (void)pCreateInfo; (void)pAllocator; (void)pSurface; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_XLIB_KHR */

VkResult vkDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) { (void)device; (void)pNameInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkDebugMarkerSetObjectTagEXT(VkDevice device, const VkDebugMarkerObjectTagInfoEXT* pTagInfo) { (void)device; (void)pTagInfo; return VK_ERROR_INITIALIZATION_FAILED; }
void vkDebugReportMessageEXT(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage) { (void)instance; (void)flags; (void)objectType; (void)object; (void)location; (void)messageCode; (void)pLayerPrefix; (void)pMessage; }
VkResult vkDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation) { (void)device; (void)operation; return VK_ERROR_INITIALIZATION_FAILED; }
void vkDestroyAccelerationStructureKHR(VkDevice device, VkAccelerationStructureKHR accelerationStructure, const VkAllocationCallbacks* pAllocator) { (void)device; (void)accelerationStructure; (void)pAllocator; }
void vkDestroyAccelerationStructureNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, const VkAllocationCallbacks* pAllocator) { (void)device; (void)accelerationStructure; (void)pAllocator; }
void vkDestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator) { (void)device; (void)buffer; (void)pAllocator; }
#ifdef VK_USE_PLATFORM_FUCHSIA
void vkDestroyBufferCollectionFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkAllocationCallbacks* pAllocator) { (void)device; (void)collection; (void)pAllocator; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

void vkDestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator) { (void)device; (void)bufferView; (void)pAllocator; }
void vkDestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator) { (void)device; (void)commandPool; (void)pAllocator; }
void vkDestroyCuFunctionNVX(VkDevice device, VkCuFunctionNVX function, const VkAllocationCallbacks* pAllocator) { (void)device; (void)function; (void)pAllocator; }
void vkDestroyCuModuleNVX(VkDevice device, VkCuModuleNVX module, const VkAllocationCallbacks* pAllocator) { (void)device; (void)module; (void)pAllocator; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
void vkDestroyCudaFunctionNV(VkDevice device, VkCudaFunctionNV function, const VkAllocationCallbacks* pAllocator) { (void)device; (void)function; (void)pAllocator; }
void vkDestroyCudaModuleNV(VkDevice device, VkCudaModuleNV module, const VkAllocationCallbacks* pAllocator) { (void)device; (void)module; (void)pAllocator; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

void vkDestroyDataGraphPipelineSessionARM(VkDevice device, VkDataGraphPipelineSessionARM session, const VkAllocationCallbacks* pAllocator) { (void)device; (void)session; (void)pAllocator; }
void vkDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) { (void)instance; (void)callback; (void)pAllocator; }
void vkDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger, const VkAllocationCallbacks* pAllocator) { (void)instance; (void)messenger; (void)pAllocator; }
void vkDestroyDeferredOperationKHR(VkDevice device, VkDeferredOperationKHR operation, const VkAllocationCallbacks* pAllocator) { (void)device; (void)operation; (void)pAllocator; }
void vkDestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator) { (void)device; (void)descriptorPool; (void)pAllocator; }
void vkDestroyDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout, const VkAllocationCallbacks* pAllocator) { (void)device; (void)descriptorSetLayout; (void)pAllocator; }
void vkDestroyDescriptorUpdateTemplate(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) { (void)device; (void)descriptorUpdateTemplate; (void)pAllocator; }
void vkDestroyDescriptorUpdateTemplateKHR(VkDevice device, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const VkAllocationCallbacks* pAllocator) { (void)device; (void)descriptorUpdateTemplate; (void)pAllocator; }
void vkDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) { (void)device; (void)pAllocator; }
void vkDestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator) { (void)device; (void)event; (void)pAllocator; }
void vkDestroyExternalComputeQueueNV(VkDevice device, VkExternalComputeQueueNV externalQueue, const VkAllocationCallbacks* pAllocator) { (void)device; (void)externalQueue; (void)pAllocator; }
void vkDestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator) { (void)device; (void)fence; (void)pAllocator; }
void vkDestroyFramebuffer(VkDevice device, VkFramebuffer framebuffer, const VkAllocationCallbacks* pAllocator) { (void)device; (void)framebuffer; (void)pAllocator; }
void vkDestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator) { (void)device; (void)image; (void)pAllocator; }
void vkDestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator) { (void)device; (void)imageView; (void)pAllocator; }
void vkDestroyIndirectCommandsLayoutEXT(VkDevice device, VkIndirectCommandsLayoutEXT indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) { (void)device; (void)indirectCommandsLayout; (void)pAllocator; }
void vkDestroyIndirectCommandsLayoutNV(VkDevice device, VkIndirectCommandsLayoutNV indirectCommandsLayout, const VkAllocationCallbacks* pAllocator) { (void)device; (void)indirectCommandsLayout; (void)pAllocator; }
void vkDestroyIndirectExecutionSetEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, const VkAllocationCallbacks* pAllocator) { (void)device; (void)indirectExecutionSet; (void)pAllocator; }
void vkDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) { (void)instance; (void)pAllocator; }
void vkDestroyMicromapEXT(VkDevice device, VkMicromapEXT micromap, const VkAllocationCallbacks* pAllocator) { (void)device; (void)micromap; (void)pAllocator; }
void vkDestroyOpticalFlowSessionNV(VkDevice device, VkOpticalFlowSessionNV session, const VkAllocationCallbacks* pAllocator) { (void)device; (void)session; (void)pAllocator; }
void vkDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) { (void)device; (void)pipeline; (void)pAllocator; }
void vkDestroyPipelineBinaryKHR(VkDevice device, VkPipelineBinaryKHR pipelineBinary, const VkAllocationCallbacks* pAllocator) { (void)device; (void)pipelineBinary; (void)pAllocator; }
void vkDestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator) { (void)device; (void)pipelineCache; (void)pAllocator; }
void vkDestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator) { (void)device; (void)pipelineLayout; (void)pAllocator; }
void vkDestroyPrivateDataSlot(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) { (void)device; (void)privateDataSlot; (void)pAllocator; }
void vkDestroyPrivateDataSlotEXT(VkDevice device, VkPrivateDataSlot privateDataSlot, const VkAllocationCallbacks* pAllocator) { (void)device; (void)privateDataSlot; (void)pAllocator; }
void vkDestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator) { (void)device; (void)queryPool; (void)pAllocator; }
void vkDestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator) { (void)device; (void)renderPass; (void)pAllocator; }
void vkDestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator) { (void)device; (void)sampler; (void)pAllocator; }
void vkDestroySamplerYcbcrConversion(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) { (void)device; (void)ycbcrConversion; (void)pAllocator; }
void vkDestroySamplerYcbcrConversionKHR(VkDevice device, VkSamplerYcbcrConversion ycbcrConversion, const VkAllocationCallbacks* pAllocator) { (void)device; (void)ycbcrConversion; (void)pAllocator; }
void vkDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) { (void)device; (void)semaphore; (void)pAllocator; }
void vkDestroyShaderEXT(VkDevice device, VkShaderEXT shader, const VkAllocationCallbacks* pAllocator) { (void)device; (void)shader; (void)pAllocator; }
void vkDestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator) { (void)device; (void)shaderModule; (void)pAllocator; }
void vkDestroySurfaceKHR(VkInstance instance, VkSurfaceKHR surface, const VkAllocationCallbacks* pAllocator) { (void)instance; (void)surface; (void)pAllocator; }
void vkDestroySwapchainKHR(VkDevice device, VkSwapchainKHR swapchain, const VkAllocationCallbacks* pAllocator) { (void)device; (void)swapchain; (void)pAllocator; }
void vkDestroyTensorARM(VkDevice device, VkTensorARM tensor, const VkAllocationCallbacks* pAllocator) { (void)device; (void)tensor; (void)pAllocator; }
void vkDestroyTensorViewARM(VkDevice device, VkTensorViewARM tensorView, const VkAllocationCallbacks* pAllocator) { (void)device; (void)tensorView; (void)pAllocator; }
void vkDestroyValidationCacheEXT(VkDevice device, VkValidationCacheEXT validationCache, const VkAllocationCallbacks* pAllocator) { (void)device; (void)validationCache; (void)pAllocator; }
void vkDestroyVideoSessionKHR(VkDevice device, VkVideoSessionKHR videoSession, const VkAllocationCallbacks* pAllocator) { (void)device; (void)videoSession; (void)pAllocator; }
void vkDestroyVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkAllocationCallbacks* pAllocator) { (void)device; (void)videoSessionParameters; (void)pAllocator; }
VkResult vkDeviceWaitIdle(VkDevice device) { (void)device; return VK_SUCCESS; }
VkResult vkDisplayPowerControlEXT(VkDevice device, VkDisplayKHR display, const VkDisplayPowerInfoEXT* pDisplayPowerInfo) { (void)device; (void)display; (void)pDisplayPowerInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkEndCommandBuffer(VkCommandBuffer commandBuffer) { (void)commandBuffer; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) { (void)physicalDevice; (void)pLayerName; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkLayerProperties* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkEnumerateInstanceExtensionProperties(const char* pLayerName, uint32_t* pPropertyCount, VkExtensionProperties* pProperties) { (void)pLayerName; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties) { (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkEnumerateInstanceVersion(uint32_t* pApiVersion) { (void)pApiVersion; return VK_SUCCESS; }
VkResult vkEnumeratePhysicalDeviceGroups(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) { (void)instance; (void)pPhysicalDeviceGroupCount; (void)pPhysicalDeviceGroupProperties; return VK_SUCCESS; }
VkResult vkEnumeratePhysicalDeviceGroupsKHR(VkInstance instance, uint32_t* pPhysicalDeviceGroupCount, VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties) { (void)instance; (void)pPhysicalDeviceGroupCount; (void)pPhysicalDeviceGroupProperties; return VK_SUCCESS; }
VkResult vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterARM* pCounters, VkPerformanceCounterDescriptionARM* pCounterDescriptions) { (void)physicalDevice; (void)queueFamilyIndex; (void)pCounterCount; (void)pCounters; (void)pCounterDescriptions; return VK_SUCCESS; }
VkResult vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, VkPerformanceCounterKHR* pCounters, VkPerformanceCounterDescriptionKHR* pCounterDescriptions) { (void)physicalDevice; (void)queueFamilyIndex; (void)pCounterCount; (void)pCounters; (void)pCounterDescriptions; return VK_SUCCESS; }
VkResult vkEnumeratePhysicalDevices(VkInstance instance, uint32_t* pPhysicalDeviceCount, VkPhysicalDevice* pPhysicalDevices) { (void)instance; (void)pPhysicalDeviceCount; (void)pPhysicalDevices; return VK_SUCCESS; }
#ifdef VK_USE_PLATFORM_METAL_EXT
void vkExportMetalObjectsEXT(VkDevice device, VkExportMetalObjectsInfoEXT* pMetalObjectsInfo) { (void)device; (void)pMetalObjectsInfo; }
#endif /* VK_USE_PLATFORM_METAL_EXT */

VkResult vkFlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) { (void)device; (void)memoryRangeCount; (void)pMemoryRanges; return VK_SUCCESS; }
void vkFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount, const VkCommandBuffer* pCommandBuffers) { (void)device; (void)commandPool; (void)commandBufferCount; (void)pCommandBuffers; }
VkResult vkFreeDescriptorSets(VkDevice device, VkDescriptorPool descriptorPool, uint32_t descriptorSetCount, const VkDescriptorSet* pDescriptorSets) { (void)device; (void)descriptorPool; (void)descriptorSetCount; (void)pDescriptorSets; return VK_ERROR_INITIALIZATION_FAILED; }
void vkFreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator) { (void)device; (void)memory; (void)pAllocator; }
void vkGetAccelerationStructureBuildSizesKHR(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkAccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) { (void)device; (void)buildType; (void)pBuildInfo; (void)pMaxPrimitiveCounts; (void)pSizeInfo; }
VkDeviceAddress vkGetAccelerationStructureDeviceAddressKHR(VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo) { (void)device; (void)pInfo; return (VkDeviceAddress)0; }
VkResult vkGetAccelerationStructureHandleNV(VkDevice device, VkAccelerationStructureNV accelerationStructure, size_t dataSize, void* pData) { (void)device; (void)accelerationStructure; (void)dataSize; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetAccelerationStructureMemoryRequirementsNV(VkDevice device, const VkAccelerationStructureMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2KHR* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
VkResult vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkAccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData) { (void)device; (void)pInfo; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_ANDROID_KHR
VkResult vkGetAndroidHardwareBufferPropertiesANDROID(VkDevice device, const struct AHardwareBuffer* buffer, VkAndroidHardwareBufferPropertiesANDROID* pProperties) { (void)device; (void)buffer; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult vkGetBufferCollectionPropertiesFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, VkBufferCollectionPropertiesFUCHSIA* pProperties) { (void)device; (void)collection; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

VkDeviceAddress vkGetBufferDeviceAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { (void)device; (void)pInfo; return (VkDeviceAddress)0; }
VkDeviceAddress vkGetBufferDeviceAddressEXT(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { (void)device; (void)pInfo; return (VkDeviceAddress)0; }
VkDeviceAddress vkGetBufferDeviceAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { (void)device; (void)pInfo; return (VkDeviceAddress)0; }
void vkGetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements) { (void)device; (void)buffer; (void)pMemoryRequirements; }
void vkGetBufferMemoryRequirements2(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
void vkGetBufferMemoryRequirements2KHR(VkDevice device, const VkBufferMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
uint64_t vkGetBufferOpaqueCaptureAddress(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { (void)device; (void)pInfo; return (uint64_t)0; }
uint64_t vkGetBufferOpaqueCaptureAddressKHR(VkDevice device, const VkBufferDeviceAddressInfo* pInfo) { (void)device; (void)pInfo; return (uint64_t)0; }
VkResult vkGetBufferOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkBufferCaptureDescriptorDataInfoEXT* pInfo, void* pData) { (void)device; (void)pInfo; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetCalibratedTimestampsEXT(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) { (void)device; (void)timestampCount; (void)pTimestampInfos; (void)pTimestamps; (void)pMaxDeviation; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetCalibratedTimestampsKHR(VkDevice device, uint32_t timestampCount, const VkCalibratedTimestampInfoKHR* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation) { (void)device; (void)timestampCount; (void)pTimestampInfos; (void)pTimestamps; (void)pMaxDeviation; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetClusterAccelerationStructureBuildSizesNV(VkDevice device, const VkClusterAccelerationStructureInputInfoNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) { (void)device; (void)pInfo; (void)pSizeInfo; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
VkResult vkGetCudaModuleCacheNV(VkDevice device, VkCudaModuleNV module, size_t* pCacheSize, void* pCacheData) { (void)device; (void)module; (void)pCacheSize; (void)pCacheData; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

VkResult vkGetDataGraphPipelineAvailablePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t* pPropertiesCount, VkDataGraphPipelinePropertyARM* pProperties) { (void)device; (void)pPipelineInfo; (void)pPropertiesCount; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDataGraphPipelinePropertiesARM(VkDevice device, const VkDataGraphPipelineInfoARM* pPipelineInfo, uint32_t propertiesCount, VkDataGraphPipelinePropertyQueryResultARM* pProperties) { (void)device; (void)pPipelineInfo; (void)propertiesCount; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDataGraphPipelineSessionBindPointRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionBindPointRequirementsInfoARM* pInfo, uint32_t* pBindPointRequirementCount, VkDataGraphPipelineSessionBindPointRequirementARM* pBindPointRequirements) { (void)device; (void)pInfo; (void)pBindPointRequirementCount; (void)pBindPointRequirements; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetDataGraphPipelineSessionMemoryRequirementsARM(VkDevice device, const VkDataGraphPipelineSessionMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
uint32_t vkGetDeferredOperationMaxConcurrencyKHR(VkDevice device, VkDeferredOperationKHR operation) { (void)device; (void)operation; return (uint32_t)0; }
VkResult vkGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation) { (void)device; (void)operation; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetDescriptorEXT(VkDevice device, const VkDescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor) { (void)device; (void)pDescriptorInfo; (void)dataSize; (void)pDescriptor; }
void vkGetDescriptorSetHostMappingVALVE(VkDevice device, VkDescriptorSet descriptorSet, void** ppData) { (void)device; (void)descriptorSet; (void)ppData; }
void vkGetDescriptorSetLayoutBindingOffsetEXT(VkDevice device, VkDescriptorSetLayout layout, uint32_t binding, VkDeviceSize* pOffset) { (void)device; (void)layout; (void)binding; (void)pOffset; }
void vkGetDescriptorSetLayoutHostMappingInfoVALVE(VkDevice device, const VkDescriptorSetBindingReferenceVALVE* pBindingReference, VkDescriptorSetLayoutHostMappingInfoVALVE* pHostMapping) { (void)device; (void)pBindingReference; (void)pHostMapping; }
void vkGetDescriptorSetLayoutSizeEXT(VkDevice device, VkDescriptorSetLayout layout, VkDeviceSize* pLayoutSizeInBytes) { (void)device; (void)layout; (void)pLayoutSizeInBytes; }
void vkGetDescriptorSetLayoutSupport(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) { (void)device; (void)pCreateInfo; (void)pSupport; }
void vkGetDescriptorSetLayoutSupportKHR(VkDevice device, const VkDescriptorSetLayoutCreateInfo* pCreateInfo, VkDescriptorSetLayoutSupport* pSupport) { (void)device; (void)pCreateInfo; (void)pSupport; }
void vkGetDeviceAccelerationStructureCompatibilityKHR(VkDevice device, const VkAccelerationStructureVersionInfoKHR* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) { (void)device; (void)pVersionInfo; (void)pCompatibility; }
void vkGetDeviceBufferMemoryRequirements(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
void vkGetDeviceBufferMemoryRequirementsKHR(VkDevice device, const VkDeviceBufferMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
uint64_t vkGetDeviceCombinedImageSamplerIndexNVX(VkDevice device, uint64_t imageViewIndex, uint64_t samplerIndex) { (void)device; (void)imageViewIndex; (void)samplerIndex; return (uint64_t)0; }
VkResult vkGetDeviceFaultInfoEXT(VkDevice device, VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) { (void)device; (void)pFaultCounts; (void)pFaultInfo; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetDeviceGroupPeerMemoryFeatures(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) { (void)device; (void)heapIndex; (void)localDeviceIndex; (void)remoteDeviceIndex; (void)pPeerMemoryFeatures; }
void vkGetDeviceGroupPeerMemoryFeaturesKHR(VkDevice device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, VkPeerMemoryFeatureFlags* pPeerMemoryFeatures) { (void)device; (void)heapIndex; (void)localDeviceIndex; (void)remoteDeviceIndex; (void)pPeerMemoryFeatures; }
VkResult vkGetDeviceGroupPresentCapabilitiesKHR(VkDevice device, VkDeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities) { (void)device; (void)pDeviceGroupPresentCapabilities; return VK_SUCCESS; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkGetDeviceGroupSurfacePresentModes2EXT(VkDevice device, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkDeviceGroupPresentModeFlagsKHR* pModes) { (void)device; (void)pSurfaceInfo; (void)pModes; return VK_SUCCESS; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult vkGetDeviceGroupSurfacePresentModesKHR(VkDevice device, VkSurfaceKHR surface, VkDeviceGroupPresentModeFlagsKHR* pModes) { (void)device; (void)surface; (void)pModes; return VK_SUCCESS; }
void vkGetDeviceImageMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
void vkGetDeviceImageMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
void vkGetDeviceImageSparseMemoryRequirements(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { (void)device; (void)pInfo; (void)pSparseMemoryRequirementCount; (void)pSparseMemoryRequirements; }
void vkGetDeviceImageSparseMemoryRequirementsKHR(VkDevice device, const VkDeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { (void)device; (void)pInfo; (void)pSparseMemoryRequirementCount; (void)pSparseMemoryRequirements; }
void vkGetDeviceImageSubresourceLayout(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) { (void)device; (void)pInfo; (void)pLayout; }
void vkGetDeviceImageSubresourceLayoutKHR(VkDevice device, const VkDeviceImageSubresourceInfo* pInfo, VkSubresourceLayout2* pLayout) { (void)device; (void)pInfo; (void)pLayout; }
void vkGetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes) { (void)device; (void)memory; (void)pCommittedMemoryInBytes; }
uint64_t vkGetDeviceMemoryOpaqueCaptureAddress(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) { (void)device; (void)pInfo; return (uint64_t)0; }
uint64_t vkGetDeviceMemoryOpaqueCaptureAddressKHR(VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo) { (void)device; (void)pInfo; return (uint64_t)0; }
void vkGetDeviceMicromapCompatibilityEXT(VkDevice device, const VkMicromapVersionInfoEXT* pVersionInfo, VkAccelerationStructureCompatibilityKHR* pCompatibility) { (void)device; (void)pVersionInfo; (void)pCompatibility; }
PFN_vkVoidFunction vkGetDeviceProcAddr(VkDevice device, const char* pName) { (void)device; (void)pName; return NULL; }
void vkGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) { (void)device; (void)queueFamilyIndex; (void)queueIndex; (void)pQueue; }
void vkGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) { (void)device; (void)pQueueInfo; (void)pQueue; }
VkResult vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(VkDevice device, VkRenderPass renderpass, VkExtent2D* pMaxWorkgroupSize) { (void)device; (void)renderpass; (void)pMaxWorkgroupSize; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetDeviceTensorMemoryRequirementsARM(VkDevice device, const VkDeviceTensorMemoryRequirementsARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
VkResult vkGetDisplayModeProperties2KHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModeProperties2KHR* pProperties) { (void)physicalDevice; (void)display; (void)pPropertyCount; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDisplayModePropertiesKHR(VkPhysicalDevice physicalDevice, VkDisplayKHR display, uint32_t* pPropertyCount, VkDisplayModePropertiesKHR* pProperties) { (void)physicalDevice; (void)display; (void)pPropertyCount; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDisplayPlaneCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkDisplayPlaneInfo2KHR* pDisplayPlaneInfo, VkDisplayPlaneCapabilities2KHR* pCapabilities) { (void)physicalDevice; (void)pDisplayPlaneInfo; (void)pCapabilities; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDisplayPlaneCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkDisplayModeKHR mode, uint32_t planeIndex, VkDisplayPlaneCapabilitiesKHR* pCapabilities) { (void)physicalDevice; (void)mode; (void)planeIndex; (void)pCapabilities; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDisplayPlaneSupportedDisplaysKHR(VkPhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, VkDisplayKHR* pDisplays) { (void)physicalDevice; (void)planeIndex; (void)pDisplayCount; (void)pDisplays; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDrmDisplayEXT(VkPhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, VkDisplayKHR* display) { (void)physicalDevice; (void)drmFd; (void)connectorId; (void)display; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetDynamicRenderingTilePropertiesQCOM(VkDevice device, const VkRenderingInfo* pRenderingInfo, VkTilePropertiesQCOM* pProperties) { (void)device; (void)pRenderingInfo; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetEncodedVideoSessionParametersKHR(VkDevice device, const VkVideoEncodeSessionParametersGetInfoKHR* pVideoSessionParametersInfo, VkVideoEncodeSessionParametersFeedbackInfoKHR* pFeedbackInfo, size_t* pDataSize, void* pData) { (void)device; (void)pVideoSessionParametersInfo; (void)pFeedbackInfo; (void)pDataSize; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetEventStatus(VkDevice device, VkEvent event) { (void)device; (void)event; return VK_EVENT_RESET; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
VkResult vkGetExecutionGraphPipelineNodeIndexAMDX(VkDevice device, VkPipeline executionGraph, const VkPipelineShaderStageNodeCreateInfoAMDX* pNodeInfo, uint32_t* pNodeIndex) { (void)device; (void)executionGraph; (void)pNodeInfo; (void)pNodeIndex; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetExecutionGraphPipelineScratchSizeAMDX(VkDevice device, VkPipeline executionGraph, VkExecutionGraphPipelineScratchSizeAMDX* pSizeInfo) { (void)device; (void)executionGraph; (void)pSizeInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_ENABLE_BETA_EXTENSIONS */

void vkGetExternalComputeQueueDataNV(VkExternalComputeQueueNV externalQueue, VkExternalComputeQueueDataParamsNV* params, void* pData) { (void)externalQueue; (void)params; (void)pData; }
VkResult vkGetFenceFdKHR(VkDevice device, const VkFenceGetFdInfoKHR* pGetFdInfo, int* pFd) { (void)device; (void)pGetFdInfo; (void)pFd; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetFenceStatus(VkDevice device, VkFence fence) { (void)device; (void)fence; return VK_NOT_READY; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkGetFenceWin32HandleKHR(VkDevice device, const VkFenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { (void)device; (void)pGetWin32HandleInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult vkGetFramebufferTilePropertiesQCOM(VkDevice device, VkFramebuffer framebuffer, uint32_t* pPropertiesCount, VkTilePropertiesQCOM* pProperties) { (void)device; (void)framebuffer; (void)pPropertiesCount; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetGeneratedCommandsMemoryRequirementsEXT(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoEXT* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
void vkGetGeneratedCommandsMemoryRequirementsNV(VkDevice device, const VkGeneratedCommandsMemoryRequirementsInfoNV* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
VkResult vkGetImageDrmFormatModifierPropertiesEXT(VkDevice device, VkImage image, VkImageDrmFormatModifierPropertiesEXT* pProperties) { (void)device; (void)image; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements) { (void)device; (void)image; (void)pMemoryRequirements; }
void vkGetImageMemoryRequirements2(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
void vkGetImageMemoryRequirements2KHR(VkDevice device, const VkImageMemoryRequirementsInfo2* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
VkResult vkGetImageOpaqueCaptureDataEXT(VkDevice device, uint32_t imageCount, const VkImage* pImages, VkHostAddressRangeEXT* pDatas) { (void)device; (void)imageCount; (void)pImages; (void)pDatas; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetImageOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageCaptureDescriptorDataInfoEXT* pInfo, void* pData) { (void)device; (void)pInfo; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetImageSparseMemoryRequirements(VkDevice device, VkImage image, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements* pSparseMemoryRequirements) { (void)device; (void)image; (void)pSparseMemoryRequirementCount; (void)pSparseMemoryRequirements; }
void vkGetImageSparseMemoryRequirements2(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { (void)device; (void)pInfo; (void)pSparseMemoryRequirementCount; (void)pSparseMemoryRequirements; }
void vkGetImageSparseMemoryRequirements2KHR(VkDevice device, const VkImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, VkSparseImageMemoryRequirements2* pSparseMemoryRequirements) { (void)device; (void)pInfo; (void)pSparseMemoryRequirementCount; (void)pSparseMemoryRequirements; }
void vkGetImageSubresourceLayout(VkDevice device, VkImage image, const VkImageSubresource* pSubresource, VkSubresourceLayout* pLayout) { (void)device; (void)image; (void)pSubresource; (void)pLayout; }
void vkGetImageSubresourceLayout2(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) { (void)device; (void)image; (void)pSubresource; (void)pLayout; }
void vkGetImageSubresourceLayout2EXT(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) { (void)device; (void)image; (void)pSubresource; (void)pLayout; }
void vkGetImageSubresourceLayout2KHR(VkDevice device, VkImage image, const VkImageSubresource2* pSubresource, VkSubresourceLayout2* pLayout) { (void)device; (void)image; (void)pSubresource; (void)pLayout; }
VkResult vkGetImageViewAddressNVX(VkDevice device, VkImageView imageView, VkImageViewAddressPropertiesNVX* pProperties) { (void)device; (void)imageView; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
uint64_t vkGetImageViewHandle64NVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) { (void)device; (void)pInfo; return (uint64_t)0; }
uint32_t vkGetImageViewHandleNVX(VkDevice device, const VkImageViewHandleInfoNVX* pInfo) { (void)device; (void)pInfo; return (uint32_t)0; }
VkResult vkGetImageViewOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData) { (void)device; (void)pInfo; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
PFN_vkVoidFunction vkGetInstanceProcAddr(VkInstance instance, const char* pName) { (void)instance; (void)pName; return NULL; }
void vkGetLatencyTimingsNV(VkDevice device, VkSwapchainKHR swapchain, VkGetLatencyMarkerInfoNV* pLatencyMarkerInfo) { (void)device; (void)swapchain; (void)pLatencyMarkerInfo; }
#ifdef VK_USE_PLATFORM_ANDROID_KHR
VkResult vkGetMemoryAndroidHardwareBufferANDROID(VkDevice device, const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo, struct AHardwareBuffer** pBuffer) { (void)device; (void)pInfo; (void)pBuffer; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

VkResult vkGetMemoryFdKHR(VkDevice device, const VkMemoryGetFdInfoKHR* pGetFdInfo, int* pFd) { (void)device; (void)pGetFdInfo; (void)pFd; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetMemoryFdPropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, int fd, VkMemoryFdPropertiesKHR* pMemoryFdProperties) { (void)device; (void)handleType; (void)fd; (void)pMemoryFdProperties; return VK_SUCCESS; }
VkResult vkGetMemoryHostPointerPropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, VkMemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties) { (void)device; (void)handleType; (void)pHostPointer; (void)pMemoryHostPointerProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_METAL_EXT
VkResult vkGetMemoryMetalHandleEXT(VkDevice device, const VkMemoryGetMetalHandleInfoEXT* pGetMetalHandleInfo, void** pHandle) { (void)device; (void)pGetMetalHandleInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetMemoryMetalHandlePropertiesEXT(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, const void* pHandle, VkMemoryMetalHandlePropertiesEXT* pMemoryMetalHandleProperties) { (void)device; (void)handleType; (void)pHandle; (void)pMemoryMetalHandleProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_METAL_EXT */

#ifdef VK_USE_PLATFORM_OHOS
VkResult vkGetMemoryNativeBufferOHOS(VkDevice device, const VkMemoryGetNativeBufferInfoOHOS* pInfo, struct OH_NativeBuffer** pBuffer) { (void)device; (void)pInfo; (void)pBuffer; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_OHOS */

VkResult vkGetMemoryRemoteAddressNV(VkDevice device, const VkMemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, VkRemoteAddressNV* pAddress) { (void)device; (void)pMemoryGetRemoteAddressInfo; (void)pAddress; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkGetMemoryWin32HandleKHR(VkDevice device, const VkMemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { (void)device; (void)pGetWin32HandleInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetMemoryWin32HandleNV(VkDevice device, VkDeviceMemory memory, VkExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle) { (void)device; (void)memory; (void)handleType; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetMemoryWin32HandlePropertiesKHR(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, VkMemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties) { (void)device; (void)handleType; (void)handle; (void)pMemoryWin32HandleProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult vkGetMemoryZirconHandleFUCHSIA(VkDevice device, const VkMemoryGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) { (void)device; (void)pGetZirconHandleInfo; (void)pZirconHandle; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetMemoryZirconHandlePropertiesFUCHSIA(VkDevice device, VkExternalMemoryHandleTypeFlagBits handleType, zx_handle_t zirconHandle, VkMemoryZirconHandlePropertiesFUCHSIA* pMemoryZirconHandleProperties) { (void)device; (void)handleType; (void)zirconHandle; (void)pMemoryZirconHandleProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

void vkGetMicromapBuildSizesEXT(VkDevice device, VkAccelerationStructureBuildTypeKHR buildType, const VkMicromapBuildInfoEXT* pBuildInfo, VkMicromapBuildSizesInfoEXT* pSizeInfo) { (void)device; (void)buildType; (void)pBuildInfo; (void)pSizeInfo; }
#ifdef VK_USE_PLATFORM_OHOS
VkResult vkGetNativeBufferPropertiesOHOS(VkDevice device, const struct OH_NativeBuffer* buffer, VkNativeBufferPropertiesOHOS* pProperties) { (void)device; (void)buffer; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_OHOS */

void vkGetPartitionedAccelerationStructuresBuildSizesNV(VkDevice device, const VkPartitionedAccelerationStructureInstancesInputNV* pInfo, VkAccelerationStructureBuildSizesInfoKHR* pSizeInfo) { (void)device; (void)pInfo; (void)pSizeInfo; }
VkResult vkGetPastPresentationTimingEXT(VkDevice device, const VkPastPresentationTimingInfoEXT* pPastPresentationTimingInfo, VkPastPresentationTimingPropertiesEXT* pPastPresentationTimingProperties) { (void)device; (void)pPastPresentationTimingInfo; (void)pPastPresentationTimingProperties; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPastPresentationTimingGOOGLE(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pPresentationTimingCount, VkPastPresentationTimingGOOGLE* pPresentationTimings) { (void)device; (void)swapchain; (void)pPresentationTimingCount; (void)pPresentationTimings; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPerformanceParameterINTEL(VkDevice device, VkPerformanceParameterTypeINTEL parameter, VkPerformanceValueINTEL* pValue) { (void)device; (void)parameter; (void)pValue; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) { (void)physicalDevice; (void)pTimeDomainCount; (void)pTimeDomains; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceCalibrateableTimeDomainsKHR(VkPhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, VkTimeDomainKHR* pTimeDomains) { (void)physicalDevice; (void)pTimeDomainCount; (void)pTimeDomains; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixFlexibleDimensionsPropertiesNV* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesKHR* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeMatrixPropertiesNV* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceCooperativeVectorPropertiesNV(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkCooperativeVectorPropertiesNV* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkDeviceSize vkGetPhysicalDeviceDescriptorSizeEXT(VkPhysicalDevice physicalDevice, VkDescriptorType descriptorType) { (void)physicalDevice; (void)descriptorType; return (VkDeviceSize)0; }
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
VkBool32 vkGetPhysicalDeviceDirectFBPresentationSupportEXT(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, IDirectFB* dfb) { (void)physicalDevice; (void)queueFamilyIndex; (void)dfb; return (VkBool32)0; }
#endif /* VK_USE_PLATFORM_DIRECTFB_EXT */

VkResult vkGetPhysicalDeviceDisplayPlaneProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlaneProperties2KHR* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceDisplayPlanePropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPlanePropertiesKHR* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceDisplayProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayProperties2KHR* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceDisplayPropertiesKHR(VkPhysicalDevice physicalDevice, uint32_t* pPropertyCount, VkDisplayPropertiesKHR* pProperties) { (void)physicalDevice; (void)pPropertyCount; (void)pProperties; return VK_SUCCESS; }
void vkGetPhysicalDeviceExternalBufferProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) { (void)physicalDevice; (void)pExternalBufferInfo; (void)pExternalBufferProperties; }
void vkGetPhysicalDeviceExternalBufferPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo, VkExternalBufferProperties* pExternalBufferProperties) { (void)physicalDevice; (void)pExternalBufferInfo; (void)pExternalBufferProperties; }
void vkGetPhysicalDeviceExternalFenceProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) { (void)physicalDevice; (void)pExternalFenceInfo; (void)pExternalFenceProperties; }
void vkGetPhysicalDeviceExternalFencePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo, VkExternalFenceProperties* pExternalFenceProperties) { (void)physicalDevice; (void)pExternalFenceInfo; (void)pExternalFenceProperties; }
VkResult vkGetPhysicalDeviceExternalImageFormatPropertiesNV(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkExternalMemoryHandleTypeFlagsNV externalHandleType, VkExternalImageFormatPropertiesNV* pExternalImageFormatProperties) { (void)physicalDevice; (void)format; (void)type; (void)tiling; (void)usage; (void)flags; (void)externalHandleType; (void)pExternalImageFormatProperties; return VK_SUCCESS; }
void vkGetPhysicalDeviceExternalSemaphoreProperties(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) { (void)physicalDevice; (void)pExternalSemaphoreInfo; (void)pExternalSemaphoreProperties; }
void vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, VkExternalSemaphoreProperties* pExternalSemaphoreProperties) { (void)physicalDevice; (void)pExternalSemaphoreInfo; (void)pExternalSemaphoreProperties; }
void vkGetPhysicalDeviceExternalTensorPropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceExternalTensorInfoARM* pExternalTensorInfo, VkExternalTensorPropertiesARM* pExternalTensorProperties) { (void)physicalDevice; (void)pExternalTensorInfo; (void)pExternalTensorProperties; }
void vkGetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures) { (void)physicalDevice; (void)pFeatures; }
void vkGetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) { (void)physicalDevice; (void)pFeatures; }
void vkGetPhysicalDeviceFeatures2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures) { (void)physicalDevice; (void)pFeatures; }
void vkGetPhysicalDeviceFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties* pFormatProperties) { (void)physicalDevice; (void)format; (void)pFormatProperties; }
void vkGetPhysicalDeviceFormatProperties2(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) { (void)physicalDevice; (void)format; (void)pFormatProperties; }
void vkGetPhysicalDeviceFormatProperties2KHR(VkPhysicalDevice physicalDevice, VkFormat format, VkFormatProperties2* pFormatProperties) { (void)physicalDevice; (void)format; (void)pFormatProperties; }
VkResult vkGetPhysicalDeviceFragmentShadingRatesKHR(VkPhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, VkPhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates) { (void)physicalDevice; (void)pFragmentShadingRateCount; (void)pFragmentShadingRates; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties* pImageFormatProperties) { (void)physicalDevice; (void)format; (void)type; (void)tiling; (void)usage; (void)flags; (void)pImageFormatProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) { (void)physicalDevice; (void)pImageFormatInfo; (void)pImageFormatProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo, VkImageFormatProperties2* pImageFormatProperties) { (void)physicalDevice; (void)pImageFormatInfo; (void)pImageFormatProperties; return VK_SUCCESS; }
void vkGetPhysicalDeviceMemoryProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties* pMemoryProperties) { (void)physicalDevice; (void)pMemoryProperties; }
void vkGetPhysicalDeviceMemoryProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) { (void)physicalDevice; (void)pMemoryProperties; }
void vkGetPhysicalDeviceMemoryProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceMemoryProperties2* pMemoryProperties) { (void)physicalDevice; (void)pMemoryProperties; }
void vkGetPhysicalDeviceMultisamplePropertiesEXT(VkPhysicalDevice physicalDevice, VkSampleCountFlagBits samples, VkMultisamplePropertiesEXT* pMultisampleProperties) { (void)physicalDevice; (void)samples; (void)pMultisampleProperties; }
VkResult vkGetPhysicalDeviceOpticalFlowImageFormatsNV(VkPhysicalDevice physicalDevice, const VkOpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, VkOpticalFlowImageFormatPropertiesNV* pImageFormatProperties) { (void)physicalDevice; (void)pOpticalFlowImageFormatInfo; (void)pFormatCount; (void)pImageFormatProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDevicePresentRectanglesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pRectCount, VkRect2D* pRects) { (void)physicalDevice; (void)surface; (void)pRectCount; (void)pRects; return VK_SUCCESS; }
void vkGetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties) { (void)physicalDevice; (void)pProperties; }
void vkGetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) { (void)physicalDevice; (void)pProperties; }
void vkGetPhysicalDeviceProperties2KHR(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties) { (void)physicalDevice; (void)pProperties; }
void vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* pQueueFamilyDataGraphProcessingEngineInfo, VkQueueFamilyDataGraphProcessingEnginePropertiesARM* pQueueFamilyDataGraphProcessingEngineProperties) { (void)physicalDevice; (void)pQueueFamilyDataGraphProcessingEngineInfo; (void)pQueueFamilyDataGraphProcessingEngineProperties; }
VkResult vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pQueueFamilyDataGraphPropertyCount, VkQueueFamilyDataGraphPropertiesARM* pQueueFamilyDataGraphProperties) { (void)physicalDevice; (void)queueFamilyIndex; (void)pQueueFamilyDataGraphPropertyCount; (void)pQueueFamilyDataGraphProperties; return VK_SUCCESS; }
void vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(VkPhysicalDevice physicalDevice, const VkQueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses) { (void)physicalDevice; (void)pPerformanceQueryCreateInfo; (void)pNumPasses; }
void vkGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties* pQueueFamilyProperties) { (void)physicalDevice; (void)pQueueFamilyPropertyCount; (void)pQueueFamilyProperties; }
void vkGetPhysicalDeviceQueueFamilyProperties2(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) { (void)physicalDevice; (void)pQueueFamilyPropertyCount; (void)pQueueFamilyProperties; }
void vkGetPhysicalDeviceQueueFamilyProperties2KHR(VkPhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, VkQueueFamilyProperties2* pQueueFamilyProperties) { (void)physicalDevice; (void)pQueueFamilyPropertyCount; (void)pQueueFamilyProperties; }
#ifdef VK_USE_PLATFORM_SCREEN_QNX
VkBool32 vkGetPhysicalDeviceScreenPresentationSupportQNX(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct _screen_window* window) { (void)physicalDevice; (void)queueFamilyIndex; (void)window; return (VkBool32)0; }
#endif /* VK_USE_PLATFORM_SCREEN_QNX */

void vkGetPhysicalDeviceSparseImageFormatProperties(VkPhysicalDevice physicalDevice, VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, uint32_t* pPropertyCount, VkSparseImageFormatProperties* pProperties) { (void)physicalDevice; (void)format; (void)type; (void)samples; (void)usage; (void)tiling; (void)pPropertyCount; (void)pProperties; }
void vkGetPhysicalDeviceSparseImageFormatProperties2(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) { (void)physicalDevice; (void)pFormatInfo; (void)pPropertyCount; (void)pProperties; }
void vkGetPhysicalDeviceSparseImageFormatProperties2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, VkSparseImageFormatProperties2* pProperties) { (void)physicalDevice; (void)pFormatInfo; (void)pPropertyCount; (void)pProperties; }
VkResult vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(VkPhysicalDevice physicalDevice, uint32_t* pCombinationCount, VkFramebufferMixedSamplesCombinationNV* pCombinations) { (void)physicalDevice; (void)pCombinationCount; (void)pCombinations; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSurfaceCapabilities2EXT(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilities2EXT* pSurfaceCapabilities) { (void)physicalDevice; (void)surface; (void)pSurfaceCapabilities; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, VkSurfaceCapabilities2KHR* pSurfaceCapabilities) { (void)physicalDevice; (void)pSurfaceInfo; (void)pSurfaceCapabilities; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSurfaceCapabilitiesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR* pSurfaceCapabilities) { (void)physicalDevice; (void)surface; (void)pSurfaceCapabilities; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSurfaceFormats2KHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, VkSurfaceFormat2KHR* pSurfaceFormats) { (void)physicalDevice; (void)pSurfaceInfo; (void)pSurfaceFormatCount; (void)pSurfaceFormats; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pSurfaceFormatCount, VkSurfaceFormatKHR* pSurfaceFormats) { (void)physicalDevice; (void)surface; (void)pSurfaceFormatCount; (void)pSurfaceFormats; return VK_SUCCESS; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkGetPhysicalDeviceSurfacePresentModes2EXT(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) { (void)physicalDevice; (void)pSurfaceInfo; (void)pPresentModeCount; (void)pPresentModes; return VK_SUCCESS; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult vkGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, uint32_t* pPresentModeCount, VkPresentModeKHR* pPresentModes) { (void)physicalDevice; (void)surface; (void)pPresentModeCount; (void)pPresentModes; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceSurfaceSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, VkSurfaceKHR surface, VkBool32* pSupported) { (void)physicalDevice; (void)queueFamilyIndex; (void)surface; (void)pSupported; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceToolProperties(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) { (void)physicalDevice; (void)pToolCount; (void)pToolProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceToolPropertiesEXT(VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) { (void)physicalDevice; (void)pToolCount; (void)pToolProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceVideoCapabilitiesKHR(VkPhysicalDevice physicalDevice, const VkVideoProfileInfoKHR* pVideoProfile, VkVideoCapabilitiesKHR* pCapabilities) { (void)physicalDevice; (void)pVideoProfile; (void)pCapabilities; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* pQualityLevelInfo, VkVideoEncodeQualityLevelPropertiesKHR* pQualityLevelProperties) { (void)physicalDevice; (void)pQualityLevelInfo; (void)pQualityLevelProperties; return VK_SUCCESS; }
VkResult vkGetPhysicalDeviceVideoFormatPropertiesKHR(VkPhysicalDevice physicalDevice, const VkPhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, VkVideoFormatPropertiesKHR* pVideoFormatProperties) { (void)physicalDevice; (void)pVideoFormatInfo; (void)pVideoFormatPropertyCount; (void)pVideoFormatProperties; return VK_SUCCESS; }
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
VkBool32 vkGetPhysicalDeviceWaylandPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, struct wl_display* display) { (void)physicalDevice; (void)queueFamilyIndex; (void)display; return (VkBool32)0; }
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
VkBool32 vkGetPhysicalDeviceWin32PresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex) { (void)physicalDevice; (void)queueFamilyIndex; return (VkBool32)0; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
VkBool32 vkGetPhysicalDeviceXcbPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, xcb_connection_t* connection, xcb_visualid_t visual_id) { (void)physicalDevice; (void)queueFamilyIndex; (void)connection; (void)visual_id; return (VkBool32)0; }
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_XLIB_KHR
VkBool32 vkGetPhysicalDeviceXlibPresentationSupportKHR(VkPhysicalDevice physicalDevice, uint32_t queueFamilyIndex, Display* dpy, VisualID visualID) { (void)physicalDevice; (void)queueFamilyIndex; (void)dpy; (void)visualID; return (VkBool32)0; }
#endif /* VK_USE_PLATFORM_XLIB_KHR */

VkResult vkGetPipelineBinaryDataKHR(VkDevice device, const VkPipelineBinaryDataInfoKHR* pInfo, VkPipelineBinaryKeyKHR* pPipelineBinaryKey, size_t* pPipelineBinaryDataSize, void* pPipelineBinaryData) { (void)device; (void)pInfo; (void)pPipelineBinaryKey; (void)pPipelineBinaryDataSize; (void)pPipelineBinaryData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData) { (void)device; (void)pipelineCache; (void)pDataSize; (void)pData; return VK_SUCCESS; }
VkResult vkGetPipelineExecutableInternalRepresentationsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, VkPipelineExecutableInternalRepresentationKHR* pInternalRepresentations) { (void)device; (void)pExecutableInfo; (void)pInternalRepresentationCount; (void)pInternalRepresentations; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPipelineExecutablePropertiesKHR(VkDevice device, const VkPipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, VkPipelineExecutablePropertiesKHR* pProperties) { (void)device; (void)pPipelineInfo; (void)pExecutableCount; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPipelineExecutableStatisticsKHR(VkDevice device, const VkPipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, VkPipelineExecutableStatisticKHR* pStatistics) { (void)device; (void)pExecutableInfo; (void)pStatisticCount; (void)pStatistics; return VK_ERROR_INITIALIZATION_FAILED; }
VkDeviceAddress vkGetPipelineIndirectDeviceAddressNV(VkDevice device, const VkPipelineIndirectDeviceAddressInfoNV* pInfo) { (void)device; (void)pInfo; return (VkDeviceAddress)0; }
void vkGetPipelineIndirectMemoryRequirementsNV(VkDevice device, const VkComputePipelineCreateInfo* pCreateInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pCreateInfo; (void)pMemoryRequirements; }
VkResult vkGetPipelineKeyKHR(VkDevice device, const VkPipelineCreateInfoKHR* pPipelineCreateInfo, VkPipelineBinaryKeyKHR* pPipelineKey) { (void)device; (void)pPipelineCreateInfo; (void)pPipelineKey; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetPipelinePropertiesEXT(VkDevice device, const VkPipelineInfoEXT* pPipelineInfo, VkBaseOutStructure* pPipelineProperties) { (void)device; (void)pPipelineInfo; (void)pPipelineProperties; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) { (void)device; (void)objectType; (void)objectHandle; (void)privateDataSlot; (void)pData; }
void vkGetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t* pData) { (void)device; (void)objectType; (void)objectHandle; (void)privateDataSlot; (void)pData; }
VkResult vkGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags) { (void)device; (void)queryPool; (void)firstQuery; (void)queryCount; (void)dataSize; (void)pData; (void)stride; (void)flags; return VK_NOT_READY; }
void vkGetQueueCheckpointData2NV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointData2NV* pCheckpointData) { (void)queue; (void)pCheckpointDataCount; (void)pCheckpointData; }
void vkGetQueueCheckpointDataNV(VkQueue queue, uint32_t* pCheckpointDataCount, VkCheckpointDataNV* pCheckpointData) { (void)queue; (void)pCheckpointDataCount; (void)pCheckpointData; }
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
VkResult vkGetRandROutputDisplayEXT(VkPhysicalDevice physicalDevice, Display* dpy, RROutput rrOutput, VkDisplayKHR* pDisplay) { (void)physicalDevice; (void)dpy; (void)rrOutput; (void)pDisplay; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

VkResult vkGetRayTracingCaptureReplayShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) { (void)device; (void)pipeline; (void)firstGroup; (void)groupCount; (void)dataSize; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetRayTracingShaderGroupHandlesKHR(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) { (void)device; (void)pipeline; (void)firstGroup; (void)groupCount; (void)dataSize; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetRayTracingShaderGroupHandlesNV(VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData) { (void)device; (void)pipeline; (void)firstGroup; (void)groupCount; (void)dataSize; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkDeviceSize vkGetRayTracingShaderGroupStackSizeKHR(VkDevice device, VkPipeline pipeline, uint32_t group, VkShaderGroupShaderKHR groupShader) { (void)device; (void)pipeline; (void)group; (void)groupShader; return (VkDeviceSize)0; }
VkResult vkGetRefreshCycleDurationGOOGLE(VkDevice device, VkSwapchainKHR swapchain, VkRefreshCycleDurationGOOGLE* pDisplayTimingProperties) { (void)device; (void)swapchain; (void)pDisplayTimingProperties; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity) { (void)device; (void)renderPass; (void)pGranularity; }
void vkGetRenderingAreaGranularity(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) { (void)device; (void)pRenderingAreaInfo; (void)pGranularity; }
void vkGetRenderingAreaGranularityKHR(VkDevice device, const VkRenderingAreaInfo* pRenderingAreaInfo, VkExtent2D* pGranularity) { (void)device; (void)pRenderingAreaInfo; (void)pGranularity; }
VkResult vkGetSamplerOpaqueCaptureDescriptorDataEXT(VkDevice device, const VkSamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData) { (void)device; (void)pInfo; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_SCREEN_QNX
VkResult vkGetScreenBufferPropertiesQNX(VkDevice device, const struct _screen_buffer* buffer, VkScreenBufferPropertiesQNX* pProperties) { (void)device; (void)buffer; (void)pProperties; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_SCREEN_QNX */

VkResult vkGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) { (void)device; (void)semaphore; (void)pValue; return VK_SUCCESS; }
VkResult vkGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) { (void)device; (void)semaphore; (void)pValue; return VK_SUCCESS; }
VkResult vkGetSemaphoreFdKHR(VkDevice device, const VkSemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd) { (void)device; (void)pGetFdInfo; (void)pFd; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkGetSemaphoreWin32HandleKHR(VkDevice device, const VkSemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle) { (void)device; (void)pGetWin32HandleInfo; (void)pHandle; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult vkGetSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkSemaphoreGetZirconHandleInfoFUCHSIA* pGetZirconHandleInfo, zx_handle_t* pZirconHandle) { (void)device; (void)pGetZirconHandleInfo; (void)pZirconHandle; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

VkResult vkGetShaderBinaryDataEXT(VkDevice device, VkShaderEXT shader, size_t* pDataSize, void* pData) { (void)device; (void)shader; (void)pDataSize; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetShaderInfoAMD(VkDevice device, VkPipeline pipeline, VkShaderStageFlagBits shaderStage, VkShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo) { (void)device; (void)pipeline; (void)shaderStage; (void)infoType; (void)pInfoSize; (void)pInfo; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetShaderModuleCreateInfoIdentifierEXT(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModuleIdentifierEXT* pIdentifier) { (void)device; (void)pCreateInfo; (void)pIdentifier; }
void vkGetShaderModuleIdentifierEXT(VkDevice device, VkShaderModule shaderModule, VkShaderModuleIdentifierEXT* pIdentifier) { (void)device; (void)shaderModule; (void)pIdentifier; }
VkResult vkGetSwapchainCounterEXT(VkDevice device, VkSwapchainKHR swapchain, VkSurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue) { (void)device; (void)swapchain; (void)counter; (void)pCounterValue; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetSwapchainImagesKHR(VkDevice device, VkSwapchainKHR swapchain, uint32_t* pSwapchainImageCount, VkImage* pSwapchainImages) { (void)device; (void)swapchain; (void)pSwapchainImageCount; (void)pSwapchainImages; return VK_SUCCESS; }
VkResult vkGetSwapchainStatusKHR(VkDevice device, VkSwapchainKHR swapchain) { (void)device; (void)swapchain; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetSwapchainTimeDomainPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimeDomainPropertiesEXT* pSwapchainTimeDomainProperties, uint64_t* pTimeDomainsCounter) { (void)device; (void)swapchain; (void)pSwapchainTimeDomainProperties; (void)pTimeDomainsCounter; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetSwapchainTimingPropertiesEXT(VkDevice device, VkSwapchainKHR swapchain, VkSwapchainTimingPropertiesEXT* pSwapchainTimingProperties, uint64_t* pSwapchainTimingPropertiesCounter) { (void)device; (void)swapchain; (void)pSwapchainTimingProperties; (void)pSwapchainTimingPropertiesCounter; return VK_ERROR_INITIALIZATION_FAILED; }
void vkGetTensorMemoryRequirementsARM(VkDevice device, const VkTensorMemoryRequirementsInfoARM* pInfo, VkMemoryRequirements2* pMemoryRequirements) { (void)device; (void)pInfo; (void)pMemoryRequirements; }
VkResult vkGetTensorOpaqueCaptureDataARM(VkDevice device, uint32_t tensorCount, const VkTensorARM* pTensors, VkHostAddressRangeEXT* pDatas) { (void)device; (void)tensorCount; (void)pTensors; (void)pDatas; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetTensorOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorCaptureDescriptorDataInfoARM* pInfo, void* pData) { (void)device; (void)pInfo; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetTensorViewOpaqueCaptureDescriptorDataARM(VkDevice device, const VkTensorViewCaptureDescriptorDataInfoARM* pInfo, void* pData) { (void)device; (void)pInfo; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetValidationCacheDataEXT(VkDevice device, VkValidationCacheEXT validationCache, size_t* pDataSize, void* pData) { (void)device; (void)validationCache; (void)pDataSize; (void)pData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkGetVideoSessionMemoryRequirementsKHR(VkDevice device, VkVideoSessionKHR videoSession, uint32_t* pMemoryRequirementsCount, VkVideoSessionMemoryRequirementsKHR* pMemoryRequirements) { (void)device; (void)videoSession; (void)pMemoryRequirementsCount; (void)pMemoryRequirements; return VK_SUCCESS; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkGetWinrtDisplayNV(VkPhysicalDevice physicalDevice, uint32_t deviceRelativeId, VkDisplayKHR* pDisplay) { (void)physicalDevice; (void)deviceRelativeId; (void)pDisplay; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult vkImportFenceFdKHR(VkDevice device, const VkImportFenceFdInfoKHR* pImportFenceFdInfo) { (void)device; (void)pImportFenceFdInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkImportFenceWin32HandleKHR(VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo) { (void)device; (void)pImportFenceWin32HandleInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult vkImportSemaphoreFdKHR(VkDevice device, const VkImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo) { (void)device; (void)pImportSemaphoreFdInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkImportSemaphoreWin32HandleKHR(VkDevice device, const VkImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo) { (void)device; (void)pImportSemaphoreWin32HandleInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult vkImportSemaphoreZirconHandleFUCHSIA(VkDevice device, const VkImportSemaphoreZirconHandleInfoFUCHSIA* pImportSemaphoreZirconHandleInfo) { (void)device; (void)pImportSemaphoreZirconHandleInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

VkResult vkInitializePerformanceApiINTEL(VkDevice device, const VkInitializePerformanceApiInfoINTEL* pInitializeInfo) { (void)device; (void)pInitializeInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkInvalidateMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges) { (void)device; (void)memoryRangeCount; (void)pMemoryRanges; return VK_SUCCESS; }
VkResult vkLatencySleepNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepInfoNV* pSleepInfo) { (void)device; (void)swapchain; (void)pSleepInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkMapMemory(VkDevice device, VkDeviceMemory memory, VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ppData) { (void)device; (void)memory; (void)offset; (void)size; (void)flags; (void)ppData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkMapMemory2(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) { (void)device; (void)pMemoryMapInfo; (void)ppData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkMapMemory2KHR(VkDevice device, const VkMemoryMapInfo* pMemoryMapInfo, void** ppData) { (void)device; (void)pMemoryMapInfo; (void)ppData; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkMergePipelineCaches(VkDevice device, VkPipelineCache dstCache, uint32_t srcCacheCount, const VkPipelineCache* pSrcCaches) { (void)device; (void)dstCache; (void)srcCacheCount; (void)pSrcCaches; return VK_SUCCESS; }
VkResult vkMergeValidationCachesEXT(VkDevice device, VkValidationCacheEXT dstCache, uint32_t srcCacheCount, const VkValidationCacheEXT* pSrcCaches) { (void)device; (void)dstCache; (void)srcCacheCount; (void)pSrcCaches; return VK_ERROR_INITIALIZATION_FAILED; }
void vkQueueBeginDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) { (void)queue; (void)pLabelInfo; }
VkResult vkQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence) { (void)queue; (void)bindInfoCount; (void)pBindInfo; (void)fence; return VK_ERROR_INITIALIZATION_FAILED; }
void vkQueueEndDebugUtilsLabelEXT(VkQueue queue) { (void)queue; }
void vkQueueInsertDebugUtilsLabelEXT(VkQueue queue, const VkDebugUtilsLabelEXT* pLabelInfo) { (void)queue; (void)pLabelInfo; }
void vkQueueNotifyOutOfBandNV(VkQueue queue, const VkOutOfBandQueueTypeInfoNV* pQueueTypeInfo) { (void)queue; (void)pQueueTypeInfo; }
VkResult vkQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) { (void)queue; (void)pPresentInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkQueueSetPerformanceConfigurationINTEL(VkQueue queue, VkPerformanceConfigurationINTEL configuration) { (void)queue; (void)configuration; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) { (void)queue; (void)submitCount; (void)pSubmits; (void)fence; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) { (void)queue; (void)submitCount; (void)pSubmits; (void)fence; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) { (void)queue; (void)submitCount; (void)pSubmits; (void)fence; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkQueueWaitIdle(VkQueue queue) { (void)queue; return VK_SUCCESS; }
VkResult vkRegisterCustomBorderColorEXT(VkDevice device, const VkSamplerCustomBorderColorCreateInfoEXT* pBorderColor, VkBool32 requestIndex, uint32_t* pIndex) { (void)device; (void)pBorderColor; (void)requestIndex; (void)pIndex; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkRegisterDeviceEventEXT(VkDevice device, const VkDeviceEventInfoEXT* pDeviceEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { (void)device; (void)pDeviceEventInfo; (void)pAllocator; (void)pFence; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkRegisterDisplayEventEXT(VkDevice device, VkDisplayKHR display, const VkDisplayEventInfoEXT* pDisplayEventInfo, const VkAllocationCallbacks* pAllocator, VkFence* pFence) { (void)device; (void)display; (void)pDisplayEventInfo; (void)pAllocator; (void)pFence; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkReleaseCapturedPipelineDataKHR(VkDevice device, const VkReleaseCapturedPipelineDataInfoKHR* pInfo, const VkAllocationCallbacks* pAllocator) { (void)device; (void)pInfo; (void)pAllocator; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkReleaseDisplayEXT(VkPhysicalDevice physicalDevice, VkDisplayKHR display) { (void)physicalDevice; (void)display; return VK_ERROR_INITIALIZATION_FAILED; }
#ifdef VK_USE_PLATFORM_WIN32_KHR
VkResult vkReleaseFullScreenExclusiveModeEXT(VkDevice device, VkSwapchainKHR swapchain) { (void)device; (void)swapchain; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VkResult vkReleasePerformanceConfigurationINTEL(VkDevice device, VkPerformanceConfigurationINTEL configuration) { (void)device; (void)configuration; return VK_ERROR_INITIALIZATION_FAILED; }
void vkReleaseProfilingLockKHR(VkDevice device) { (void)device; }
VkResult vkReleaseSwapchainImagesEXT(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) { (void)device; (void)pReleaseInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkReleaseSwapchainImagesKHR(VkDevice device, const VkReleaseSwapchainImagesInfoKHR* pReleaseInfo) { (void)device; (void)pReleaseInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) { (void)commandBuffer; (void)flags; return VK_SUCCESS; }
VkResult vkResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) { (void)device; (void)commandPool; (void)flags; return VK_SUCCESS; }
VkResult vkResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags) { (void)device; (void)descriptorPool; (void)flags; return VK_SUCCESS; }
VkResult vkResetEvent(VkDevice device, VkEvent event) { (void)device; (void)event; return VK_SUCCESS; }
VkResult vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences) { (void)device; (void)fenceCount; (void)pFences; return VK_SUCCESS; }
void vkResetQueryPool(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) { (void)device; (void)queryPool; (void)firstQuery; (void)queryCount; }
void vkResetQueryPoolEXT(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount) { (void)device; (void)queryPool; (void)firstQuery; (void)queryCount; }
#ifdef VK_USE_PLATFORM_FUCHSIA
VkResult vkSetBufferCollectionBufferConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkBufferConstraintsInfoFUCHSIA* pBufferConstraintsInfo) { (void)device; (void)collection; (void)pBufferConstraintsInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkSetBufferCollectionImageConstraintsFUCHSIA(VkDevice device, VkBufferCollectionFUCHSIA collection, const VkImageConstraintsInfoFUCHSIA* pImageConstraintsInfo) { (void)device; (void)collection; (void)pImageConstraintsInfo; return VK_ERROR_INITIALIZATION_FAILED; }
#endif /* VK_USE_PLATFORM_FUCHSIA */

VkResult vkSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) { (void)device; (void)pNameInfo; return VK_SUCCESS; }
VkResult vkSetDebugUtilsObjectTagEXT(VkDevice device, const VkDebugUtilsObjectTagInfoEXT* pTagInfo) { (void)device; (void)pTagInfo; return VK_SUCCESS; }
void vkSetDeviceMemoryPriorityEXT(VkDevice device, VkDeviceMemory memory, float priority) { (void)device; (void)memory; (void)priority; }
VkResult vkSetEvent(VkDevice device, VkEvent event) { (void)device; (void)event; return VK_ERROR_INITIALIZATION_FAILED; }
void vkSetHdrMetadataEXT(VkDevice device, uint32_t swapchainCount, const VkSwapchainKHR* pSwapchains, const VkHdrMetadataEXT* pMetadata) { (void)device; (void)swapchainCount; (void)pSwapchains; (void)pMetadata; }
void vkSetLatencyMarkerNV(VkDevice device, VkSwapchainKHR swapchain, const VkSetLatencyMarkerInfoNV* pLatencyMarkerInfo) { (void)device; (void)swapchain; (void)pLatencyMarkerInfo; }
VkResult vkSetLatencySleepModeNV(VkDevice device, VkSwapchainKHR swapchain, const VkLatencySleepModeInfoNV* pSleepModeInfo) { (void)device; (void)swapchain; (void)pSleepModeInfo; return VK_ERROR_INITIALIZATION_FAILED; }
void vkSetLocalDimmingAMD(VkDevice device, VkSwapchainKHR swapChain, VkBool32 localDimmingEnable) { (void)device; (void)swapChain; (void)localDimmingEnable; }
VkResult vkSetPrivateData(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) { (void)device; (void)objectType; (void)objectHandle; (void)privateDataSlot; (void)data; return VK_SUCCESS; }
VkResult vkSetPrivateDataEXT(VkDevice device, VkObjectType objectType, uint64_t objectHandle, VkPrivateDataSlot privateDataSlot, uint64_t data) { (void)device; (void)objectType; (void)objectHandle; (void)privateDataSlot; (void)data; return VK_SUCCESS; }
VkResult vkSetSwapchainPresentTimingQueueSizeEXT(VkDevice device, VkSwapchainKHR swapchain, uint32_t size) { (void)device; (void)swapchain; (void)size; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { (void)device; (void)pSignalInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo) { (void)device; (void)pSignalInfo; return VK_ERROR_INITIALIZATION_FAILED; }
void vkSubmitDebugUtilsMessageEXT(VkInstance instance, VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageTypes, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData) { (void)instance; (void)messageSeverity; (void)messageTypes; (void)pCallbackData; }
VkResult vkTransitionImageLayout(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) { (void)device; (void)transitionCount; (void)pTransitions; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkTransitionImageLayoutEXT(VkDevice device, uint32_t transitionCount, const VkHostImageLayoutTransitionInfo* pTransitions) { (void)device; (void)transitionCount; (void)pTransitions; return VK_ERROR_INITIALIZATION_FAILED; }
void vkTrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) { (void)device; (void)commandPool; (void)flags; }
void vkTrimCommandPoolKHR(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags) { (void)device; (void)commandPool; (void)flags; }
void vkUninitializePerformanceApiINTEL(VkDevice device) { (void)device; }
void vkUnmapMemory(VkDevice device, VkDeviceMemory memory) { (void)device; (void)memory; }
VkResult vkUnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) { (void)device; (void)pMemoryUnmapInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkUnmapMemory2KHR(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo) { (void)device; (void)pMemoryUnmapInfo; return VK_ERROR_INITIALIZATION_FAILED; }
void vkUnregisterCustomBorderColorEXT(VkDevice device, uint32_t index) { (void)device; (void)index; }
void vkUpdateDescriptorSetWithTemplate(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) { (void)device; (void)descriptorSet; (void)descriptorUpdateTemplate; (void)pData; }
void vkUpdateDescriptorSetWithTemplateKHR(VkDevice device, VkDescriptorSet descriptorSet, VkDescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData) { (void)device; (void)descriptorSet; (void)descriptorUpdateTemplate; (void)pData; }
void vkUpdateDescriptorSets(VkDevice device, uint32_t descriptorWriteCount, const VkWriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const VkCopyDescriptorSet* pDescriptorCopies) { (void)device; (void)descriptorWriteCount; (void)pDescriptorWrites; (void)descriptorCopyCount; (void)pDescriptorCopies; }
void vkUpdateIndirectExecutionSetPipelineEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetPipelineEXT* pExecutionSetWrites) { (void)device; (void)indirectExecutionSet; (void)executionSetWriteCount; (void)pExecutionSetWrites; }
void vkUpdateIndirectExecutionSetShaderEXT(VkDevice device, VkIndirectExecutionSetEXT indirectExecutionSet, uint32_t executionSetWriteCount, const VkWriteIndirectExecutionSetShaderEXT* pExecutionSetWrites) { (void)device; (void)indirectExecutionSet; (void)executionSetWriteCount; (void)pExecutionSetWrites; }
VkResult vkUpdateVideoSessionParametersKHR(VkDevice device, VkVideoSessionParametersKHR videoSessionParameters, const VkVideoSessionParametersUpdateInfoKHR* pUpdateInfo) { (void)device; (void)videoSessionParameters; (void)pUpdateInfo; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout) { (void)device; (void)fenceCount; (void)pFences; (void)waitAll; (void)timeout; return VK_SUCCESS; }
VkResult vkWaitForPresent2KHR(VkDevice device, VkSwapchainKHR swapchain, const VkPresentWait2InfoKHR* pPresentWait2Info) { (void)device; (void)swapchain; (void)pPresentWait2Info; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkWaitForPresentKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t presentId, uint64_t timeout) { (void)device; (void)swapchain; (void)presentId; (void)timeout; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) { (void)device; (void)pWaitInfo; (void)timeout; return VK_SUCCESS; }
VkResult vkWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) { (void)device; (void)pWaitInfo; (void)timeout; return VK_SUCCESS; }
VkResult vkWriteAccelerationStructuresPropertiesKHR(VkDevice device, uint32_t accelerationStructureCount, const VkAccelerationStructureKHR* pAccelerationStructures, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) { (void)device; (void)accelerationStructureCount; (void)pAccelerationStructures; (void)queryType; (void)dataSize; (void)pData; (void)stride; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkWriteMicromapsPropertiesEXT(VkDevice device, uint32_t micromapCount, const VkMicromapEXT* pMicromaps, VkQueryType queryType, size_t dataSize, void* pData, size_t stride) { (void)device; (void)micromapCount; (void)pMicromaps; (void)queryType; (void)dataSize; (void)pData; (void)stride; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkWriteResourceDescriptorsEXT(VkDevice device, uint32_t resourceCount, const VkResourceDescriptorInfoEXT* pResources, const VkHostAddressRangeEXT* pDescriptors) { (void)device; (void)resourceCount; (void)pResources; (void)pDescriptors; return VK_ERROR_INITIALIZATION_FAILED; }
VkResult vkWriteSamplerDescriptorsEXT(VkDevice device, uint32_t samplerCount, const VkSamplerCreateInfo* pSamplers, const VkHostAddressRangeEXT* pDescriptors) { (void)device; (void)samplerCount; (void)pSamplers; (void)pDescriptors; return VK_ERROR_INITIALIZATION_FAILED; }
