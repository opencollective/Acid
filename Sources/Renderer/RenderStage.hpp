#pragma once

#include "Display/Display.hpp"
#include "Renderpass/Renderpass.hpp"
#include "Swapchain/DepthStencil.hpp"
#include "Swapchain/Swapchain.hpp"
#include "Swapchain/Framebuffers.hpp"

namespace fl
{
	class FL_EXPORT RenderStage
	{
	private:
		uint32_t m_lastWidth;
		uint32_t m_lastHeight;

		int m_stageIndex;
		RenderpassCreate *m_renderpassCreate;

		DepthStencil *m_depthStencil;
		Renderpass *m_renderpass;
		Framebuffers *m_framebuffers;

		std::vector<VkClearValue> m_clearValues;
		uint32_t m_imageAttachments;
		bool m_hasDepth;
		bool m_hasSwapchain;

		bool m_fitDisplaySize;
	public:
		RenderStage(const int &stageIndex, RenderpassCreate *renderpassCreate);

		~RenderStage();

		void Rebuild(Swapchain *swapchain);

		uint32_t GetWidth() const;

		uint32_t GetHeight() const;

		bool IsOutOfDate(const VkExtent2D &extent2D);

		DepthStencil *GetDepthStencil() const { return m_depthStencil; };

		Renderpass *GetRenderpass() const { return m_renderpass; };

		Framebuffers *GetFramebuffers() const { return m_framebuffers; };

		VkFramebuffer GetActiveFramebuffer(const uint32_t &activeSwapchainImage) const;

		std::vector<VkClearValue> GetClearValues() const { return m_clearValues; }

		uint32_t GetImageAttachments() const { return m_imageAttachments; }

		bool HasDepth() const { return m_hasDepth; }

		bool HasSwapchain() const { return m_hasSwapchain; }

		bool FitDisplaySize() const { return m_fitDisplaySize; }
	};
}