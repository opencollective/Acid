#pragma once

#include "Display/Display.hpp"
#include "Scenes/ICamera.hpp"
#include "Maths/Vector4.hpp"
#include "Buffers/CommandBuffer.hpp"
#include "Pipelines/PipelineCreate.hpp"

namespace fl
{
	/// <summary>
	/// Represents a sub-renderer in the engine.
	/// </summary>
	class FL_EXPORT IRenderer
	{
	private:
		bool m_enabled;
		GraphicsStage m_graphicsStage;
	public:
		/// <summary>
		/// Creates a new renderer.
		/// </summary>
		/// <param name="graphicsStage"> The graphics stage this renderer will be used in. </param>
		IRenderer(const GraphicsStage &graphicsStage) :
			m_enabled(true),
			m_graphicsStage(graphicsStage)
		{
		}

		/// <summary>
		/// Deconstructor for the renderer.
		/// </summary>
		virtual ~IRenderer()
		{
		}

		/// <summary>
		/// Called when the renderer is needed to be rendered.
		/// </summary>
		/// <param name="clipPlane"> The current clip plane. </param>
		/// <param name="camera"> The camera to be used when rendering. </param>
		virtual void Render(const CommandBuffer &commandBuffer, const Vector4 &clipPlane, const ICamera &camera) = 0;

		bool IsEnabled() const { return m_enabled; };

		void SetEnabled(const bool &enable) { m_enabled = enable; }

		GraphicsStage GetGraphicsStage() const { return m_graphicsStage; }
	};
}