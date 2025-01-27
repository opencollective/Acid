# All of these will be set as PUBLIC sources to Acid
set(_temp_acid_headers
		StdAfx.hpp
		Acid.hpp
#		Animations/Animation/Animation.hpp
#		Animations/Animation/AnimationLoader.hpp
#		Animations/Animation/Keyframe.hpp
#		Animations/Animation/JointTransform.hpp
#		Animations/Animator.hpp
#		Animations/Geometry/GeometryLoader.hpp
#		Animations/Geometry/VertexAnimated.hpp
#		Animations/MeshAnimated.hpp
#		Animations/Skeleton/Joint.hpp
#		Animations/Skeleton/SkeletonLoader.hpp
#		Animations/Skin/SkinLoader.hpp
#		Animations/Skin/VertexWeights.hpp
		Audio/Audio.hpp
		Audio/Sound.hpp
		Audio/SoundBuffer.hpp
		Bitmaps/Png/BitmapPng.hpp
		Bitmaps/Bitmap.hpp
		Devices/Instance.hpp
		Devices/Joysticks.hpp
		Devices/Keyboard.hpp
		Devices/LogicalDevice.hpp
		Devices/Monitor.hpp
		Devices/Mouse.hpp
		Devices/PhysicalDevice.hpp
		Devices/Surface.hpp
		Devices/Window.hpp
		Emitters/Emitter.hpp
		Emitters/EmitterCircle.hpp
		Emitters/EmitterLine.hpp
		Emitters/EmitterPoint.hpp
		Emitters/EmitterSphere.hpp
		Engine/App.hpp
		Engine/Engine.hpp
		Engine/Log.hpp
		Engine/Module.hpp
		Files/Zip/miniz.h
		Files/Zip/ZipArchive.hpp
		Files/Zip/ZipEntry.hpp
		Files/Zip/ZipException.hpp
		Files/Json/Json.hpp
		Files/Node.hpp
		Files/NodeReturn.hpp
		Files/File.hpp
		Files/Files.hpp
		Files/FileObserver.hpp
		Fonts/FontMetafile.hpp
		Fonts/FontType.hpp
		Fonts/Geometry.hpp
		Fonts/Outline.hpp
		Fonts/SubrenderFonts.hpp
		Fonts/SubrenderFonts2.hpp
		Fonts/Text.hpp
		Gizmos/Gizmo.hpp
		Gizmos/Gizmos.hpp
		Gizmos/GizmoType.hpp
		Gizmos/SubrenderGizmos.hpp
		Guis/Gui.hpp
		Guis/SubrenderGuis.hpp
		Helpers/ConstExpr.hpp
		Helpers/Delegate.hpp
		Helpers/EnumClass.hpp
		Helpers/Factory.hpp
		Helpers/Future.hpp
		Helpers/NonCopyable.hpp
		Helpers/Reference.hpp
		Helpers/RingBuffer.hpp
		Helpers/String.hpp
		Helpers/ThreadPool.hpp
		Helpers/TypeInfo.hpp
		Inputs/Axis.hpp
		Inputs/AxisButton.hpp
		Inputs/AxisCompound.hpp
		Inputs/AxisJoystick.hpp
		Inputs/Button.hpp
		Inputs/ButtonCompound.hpp
		Inputs/ButtonJoystick.hpp
		Inputs/ButtonKeyboard.hpp
		Inputs/ButtonMouse.hpp
		Inputs/HatJoystick.hpp
		Inputs/InputDelay.hpp
		Lights/Fog.hpp
		Lights/Light.hpp
		Materials/Material.hpp
		Materials/MaterialDefault.hpp
		Materials/PipelineMaterial.hpp
		Maths/Colour.hpp
		Maths/ElapsedTime.hpp
		Maths/Interpolation/SmoothFloat.hpp
		Maths/Maths.hpp
		Maths/Matrix2.hpp
		Maths/Matrix3.hpp
		Maths/Matrix4.hpp
		Maths/Noise/Noise.hpp
		Maths/Quaternion.hpp
		Maths/Time.hpp
		Maths/Transform.hpp
		Maths/Vector2.hpp
		Maths/Vector3.hpp
		Maths/Vector4.hpp
		Maths/Visual/Driver.hpp
		Maths/Visual/DriverBounce.hpp
		Maths/Visual/DriverConstant.hpp
		Maths/Visual/DriverFade.hpp
		Maths/Visual/DriverLinear.hpp
		Maths/Visual/DriverSinwave.hpp
		Maths/Visual/DriverSlide.hpp
		Meshes/Mesh.hpp
		Meshes/MeshRender.hpp
		Meshes/SubrenderMeshes.hpp
		Models/Gltf/ModelGltf.hpp
		Models/Model.hpp
		Models/ModelRegister.hpp
		Models/Obj/ModelObj.hpp
		Models/Shapes/MeshPattern.hpp
		Models/Shapes/MeshSimple.hpp
		Models/Shapes/ModelCube.hpp
		Models/Shapes/ModelCylinder.hpp
		Models/Shapes/ModelDisk.hpp
		Models/Shapes/ModelRectangle.hpp
		Models/Shapes/ModelSphere.hpp
		Models/VertexDefault.hpp
		Network/Ftp/Ftp.hpp
		Network/Ftp/FtpDataChannel.hpp
		Network/Ftp/FtpResponse.hpp
		Network/Ftp/FtpResponseDirectory.hpp
		Network/Ftp/FtpResponseListing.hpp
		Network/Http/Http.hpp
		Network/Http/HttpRequest.hpp
		Network/Http/HttpResponse.hpp
		Network/IpAddress.hpp
		Network/Packet.hpp
		Network/Socket.hpp
		Network/SocketSelector.hpp
		Network/Tcp/TcpListener.hpp
		Network/Tcp/TcpSocket.hpp
		Network/Udp/UdpSocket.hpp
		Particles/Particle.hpp
		Particles/Particles.hpp
		Particles/ParticleSystem.hpp
		Particles/ParticleType.hpp
		Particles/SubrenderParticles.hpp
		Physics/Colliders/Collider.hpp
		Physics/Colliders/ColliderCapsule.hpp
		Physics/Colliders/ColliderCone.hpp
		Physics/Colliders/ColliderConvexHull.hpp
		Physics/Colliders/ColliderCube.hpp
		Physics/Colliders/ColliderCylinder.hpp
		Physics/Colliders/ColliderHeightfield.hpp
		Physics/Colliders/ColliderSphere.hpp
		Physics/CollisionObject.hpp
		Physics/Force.hpp
		Physics/Frustum.hpp
		Physics/KinematicCharacter.hpp
		Physics/Ray.hpp
		Physics/Rigidbody.hpp
		Post/Deferred/SubrenderDeferred.hpp
		Post/Filters/FilterBlit.hpp
		Post/Filters/FilterBlur.hpp
		Post/Filters/FilterCrt.hpp
		Post/Filters/FilterDarken.hpp
		Post/Filters/FilterDefault.hpp
		Post/Filters/FilterDof.hpp
		Post/Filters/FilterEmboss.hpp
		Post/Filters/FilterFxaa.hpp
		Post/Filters/FilterGrain.hpp
		Post/Filters/FilterGrey.hpp
		Post/Filters/FilterLensflare.hpp
		Post/Filters/FilterNegative.hpp
		Post/Filters/FilterPixel.hpp
		Post/Filters/FilterSepia.hpp
		Post/Filters/FilterSsao.hpp
		Post/Filters/FilterTiltshift.hpp
		Post/Filters/FilterTone.hpp
		Post/Filters/FilterVignette.hpp
		Post/Filters/FilterWobble.hpp
		Post/Pipelines/PipelineBlur.hpp
		Post/PostFilter.hpp
		Post/PostPipeline.hpp
		Graphics/Buffers/Buffer.hpp
		Graphics/Buffers/InstanceBuffer.hpp
		Graphics/Buffers/PushHandler.hpp
		Graphics/Buffers/StorageBuffer.hpp
		Graphics/Buffers/StorageHandler.hpp
		Graphics/Buffers/UniformBuffer.hpp
		Graphics/Buffers/UniformHandler.hpp
		Graphics/Commands/CommandBuffer.hpp
		Graphics/Commands/CommandPool.hpp
		Graphics/Descriptors/Descriptor.hpp
		Graphics/Descriptors/DescriptorSet.hpp
		Graphics/Descriptors/DescriptorsHandler.hpp
		Graphics/Images/Image.hpp
		Graphics/Images/Image2d.hpp
		Graphics/Images/ImageCube.hpp
		Graphics/Images/ImageDepth.hpp
		Graphics/Pipelines/Pipeline.hpp
		Graphics/Pipelines/PipelineCompute.hpp
		Graphics/Pipelines/PipelineGraphics.hpp
		Graphics/Pipelines/Shader.hpp
		Graphics/Graphics.hpp
		Graphics/Renderer.hpp
		Graphics/Renderpass/Framebuffers.hpp
		Graphics/Renderpass/Renderpass.hpp
		Graphics/Renderpass/Swapchain.hpp
		Graphics/RenderStage.hpp
		Graphics/Subrender.hpp
		Graphics/SubrenderHolder.hpp
		Resources/Resource.hpp
		Resources/Resources.hpp
		Scenes/Camera.hpp
		Scenes/Component.hpp
		Scenes/ComponentRegister.hpp
		Scenes/Entity.hpp
		Scenes/EntityPrefab.hpp
		Scenes/Scene.hpp
		Scenes/ScenePhysics.hpp
		Scenes/Scenes.hpp
		Scenes/SceneStructure.hpp
		Shadows/ShadowBox.hpp
		Shadows/ShadowRender.hpp
		Shadows/Shadows.hpp
		Shadows/SubrenderShadows.hpp
		Skyboxes/MaterialSkybox.hpp
		Timers/Timers.hpp
		Uis/Inputs/UiInputBoolean.hpp
		Uis/Inputs/UiInputButton.hpp
		Uis/Inputs/UiInputDropdown.hpp
		Uis/Inputs/UiInputGrabber.hpp
		Uis/Inputs/UiInputRadio.hpp
		Uis/Inputs/UiInputSlider.hpp
		Uis/Inputs/UiInputText.hpp
		Uis/UiTransform.hpp
		Uis/UiPanel.hpp
		Uis/UiObject.hpp
		Uis/Uis.hpp
		Uis/UiScrollBar.hpp
		Uis/UiSection.hpp
		Uis/UiStartLogo.hpp
		)
set(_temp_acid_sources
		StdAfx.cpp
#		Animations/Animation/Animation.cpp
#		Animations/Animation/AnimationLoader.cpp
#		Animations/Animation/Keyframe.cpp
#		Animations/Animation/JointTransform.cpp
#		Animations/Animator.cpp
#		Animations/Geometry/GeometryLoader.cpp
#		Animations/MeshAnimated.cpp
#		Animations/Skeleton/Joint.cpp
#		Animations/Skeleton/SkeletonLoader.cpp
#		Animations/Skin/SkinLoader.cpp
#		Animations/Skin/VertexWeights.cpp
		Audio/Audio.cpp
		Audio/Sound.cpp
		Audio/SoundBuffer.cpp
		Bitmaps/Png/BitmapPng.cpp
		Devices/Instance.cpp
		Devices/Joysticks.cpp
		Devices/Keyboard.cpp
		Devices/LogicalDevice.cpp
		Devices/Monitor.cpp
		Devices/Mouse.cpp
		Devices/PhysicalDevice.cpp
		Devices/Surface.cpp
		Devices/Window.cpp
		Emitters/EmitterCircle.cpp
		Emitters/EmitterLine.cpp
		Emitters/EmitterPoint.cpp
		Emitters/EmitterSphere.cpp
		Engine/Engine.cpp
		Engine/Log.cpp
		Files/Json/Json.cpp
		Files/Node.cpp
		Files/NodeReturn.cpp
		Files/Zip/miniz.c
		Files/Zip/ZipArchive.cpp
		Files/Zip/ZipEntry.cpp
		Files/File.cpp
		Files/Files.cpp
		Files/FileObserver.cpp
		Fonts/FontMetafile.cpp
		Fonts/FontType.cpp
		Fonts/Geometry.cpp
		Fonts/Outline.cpp
		Fonts/SubrenderFonts.cpp
		Fonts/SubrenderFonts2.cpp
		Fonts/Text.cpp
		Gizmos/Gizmo.cpp
		Gizmos/Gizmos.cpp
		Gizmos/GizmoType.cpp
		Gizmos/SubrenderGizmos.cpp
		Guis/Gui.cpp
		Guis/SubrenderGuis.cpp
		Helpers/String.cpp
		Helpers/ThreadPool.cpp
		Inputs/AxisButton.cpp
		Inputs/AxisCompound.cpp
		Inputs/AxisJoystick.cpp
		Inputs/ButtonCompound.cpp
		Inputs/ButtonJoystick.cpp
		Inputs/ButtonKeyboard.cpp
		Inputs/ButtonMouse.cpp
		Inputs/HatJoystick.cpp
		Inputs/InputDelay.cpp
		Lights/Fog.cpp
		Lights/Light.cpp
		Materials/MaterialDefault.cpp
		Materials/PipelineMaterial.cpp
		Maths/Colour.cpp
		Maths/ElapsedTime.cpp
		Maths/Maths.cpp
		Maths/Matrix2.cpp
		Maths/Matrix3.cpp
		Maths/Matrix4.cpp
		Maths/Noise/Noise.cpp
		Maths/Quaternion.cpp
		Maths/Time.cpp
		Maths/Transform.cpp
		Maths/Vector2.cpp
		Maths/Vector3.cpp
		Maths/Vector4.cpp
		Meshes/Mesh.cpp
		Meshes/MeshRender.cpp
		Meshes/SubrenderMeshes.cpp
		Models/Gltf/ModelGltf.cpp
		Models/Model.cpp
		Models/ModelRegister.cpp
		Models/Obj/ModelObj.cpp
		Models/Shapes/MeshPattern.cpp
		Models/Shapes/MeshSimple.cpp
		Models/Shapes/ModelCube.cpp
		Models/Shapes/ModelCylinder.cpp
		Models/Shapes/ModelDisk.cpp
		Models/Shapes/ModelRectangle.cpp
		Models/Shapes/ModelSphere.cpp
		Network/Ftp/Ftp.cpp
		Network/Ftp/FtpDataChannel.cpp
		Network/Ftp/FtpResponse.cpp
		Network/Ftp/FtpResponseDirectory.cpp
		Network/Ftp/FtpResponseListing.cpp
		Network/Http/Http.cpp
		Network/Http/HttpRequest.cpp
		Network/Http/HttpResponse.cpp
		Network/IpAddress.cpp
		Network/Packet.cpp
		Network/Socket.cpp
		Network/SocketSelector.cpp
		Network/Tcp/TcpListener.cpp
		Network/Tcp/TcpSocket.cpp
		Network/Udp/UdpSocket.cpp
		Particles/Particle.cpp
		Particles/Particles.cpp
		Particles/ParticleSystem.cpp
		Particles/ParticleType.cpp
		Particles/SubrenderParticles.cpp
		Physics/Colliders/Collider.cpp
		Physics/Colliders/ColliderCapsule.cpp
		Physics/Colliders/ColliderCone.cpp
		Physics/Colliders/ColliderConvexHull.cpp
		Physics/Colliders/ColliderCube.cpp
		Physics/Colliders/ColliderCylinder.cpp
		Physics/Colliders/ColliderHeightfield.cpp
		Physics/Colliders/ColliderSphere.cpp
		Physics/CollisionObject.cpp
		Physics/Force.cpp
		Physics/Frustum.cpp
		Physics/KinematicCharacter.cpp
		Physics/Ray.cpp
		Physics/Rigidbody.cpp
		Post/Deferred/SubrenderDeferred.cpp
		Post/Filters/FilterBlit.cpp
		Post/Filters/FilterBlur.cpp
		Post/Filters/FilterCrt.cpp
		Post/Filters/FilterDarken.cpp
		Post/Filters/FilterDefault.cpp
		Post/Filters/FilterDof.cpp
		Post/Filters/FilterEmboss.cpp
		Post/Filters/FilterFxaa.cpp
		Post/Filters/FilterGrain.cpp
		Post/Filters/FilterGrey.cpp
		Post/Filters/FilterLensflare.cpp
		Post/Filters/FilterNegative.cpp
		Post/Filters/FilterPixel.cpp
		Post/Filters/FilterSepia.cpp
		Post/Filters/FilterSsao.cpp
		Post/Filters/FilterTiltshift.cpp
		Post/Filters/FilterTone.cpp
		Post/Filters/FilterVignette.cpp
		Post/Filters/FilterWobble.cpp
		Post/Pipelines/PipelineBlur.cpp
		Post/PostFilter.cpp
		Graphics/Buffers/Buffer.cpp
		Graphics/Buffers/InstanceBuffer.cpp
		Graphics/Buffers/PushHandler.cpp
		Graphics/Buffers/StorageBuffer.cpp
		Graphics/Buffers/StorageHandler.cpp
		Graphics/Buffers/UniformBuffer.cpp
		Graphics/Buffers/UniformHandler.cpp
		Graphics/Commands/CommandBuffer.cpp
		Graphics/Commands/CommandPool.cpp
		Graphics/Descriptors/DescriptorSet.cpp
		Graphics/Descriptors/DescriptorsHandler.cpp
		Graphics/Images/Image.cpp
		Graphics/Images/Image2d.cpp
		Graphics/Images/ImageCube.cpp
		Graphics/Images/ImageDepth.cpp
		Graphics/Pipelines/PipelineCompute.cpp
		Graphics/Pipelines/PipelineGraphics.cpp
		Graphics/Pipelines/Shader.cpp
		Graphics/Graphics.cpp
		Graphics/Renderpass/Framebuffers.cpp
		Graphics/Renderpass/Renderpass.cpp
		Graphics/Renderpass/Swapchain.cpp
		Graphics/RenderStage.cpp
		Graphics/SubrenderHolder.cpp
		Resources/Resources.cpp
		Scenes/ComponentRegister.cpp
		Scenes/Entity.cpp
		Scenes/EntityPrefab.cpp
		Scenes/ScenePhysics.cpp
		Scenes/Scenes.cpp
		Scenes/SceneStructure.cpp
		Shadows/ShadowBox.cpp
		Shadows/ShadowRender.cpp
		Shadows/Shadows.cpp
		Shadows/SubrenderShadows.cpp
		Skyboxes/MaterialSkybox.cpp
		Timers/Timers.cpp
		Uis/Inputs/UiInputBoolean.cpp
		Uis/Inputs/UiInputButton.cpp
		Uis/Inputs/UiInputDropdown.cpp
		Uis/Inputs/UiInputGrabber.cpp
		Uis/Inputs/UiInputRadio.cpp
		Uis/Inputs/UiInputSlider.cpp
		Uis/Inputs/UiInputText.cpp
		Uis/UiTransform.cpp
		Uis/UiPanel.cpp
		Uis/UiObject.cpp
		Uis/Uis.cpp
		Uis/UiScrollBar.cpp
		Uis/UiSection.cpp
		Uis/UiStartLogo.cpp
		)

# Adds the precompiled header
include(PrecompiledHeader)
add_precompiled_header(Acid
		StdAfx.hpp
		SOURCE_CXX
		StdAfx.cpp
		FORCEINCLUDE
		)
		
# Directory that Acid resources can be found.
get_filename_component(CURRENT_PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} PATH)
set(ACID_RESOURCES_DIR "${CURRENT_PARENT_DIR}/Resources")

# Adds a CMake generated config file
configure_file(Config.hpp.in ${CMAKE_CURRENT_SOURCE_DIR}/Config.hpp)

# Sets all headers as PUBLIC sources for Acid
# The BUILD/INSTALL interface generator expressions are for the EXPORT command
# Otherwise it wouldn't know where to look for them
foreach(_acid_header IN LISTS _temp_acid_headers)
	target_sources(Acid PRIVATE
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${_acid_header}>
			$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/${_acid_header}>
			)
endforeach()
# Sets all sources (cpp) as PRIVATE sources for Acid
# An INSTALL_INTERFACE isn't needed, as cpp files aren't installed
foreach(_acid_source IN LISTS _temp_acid_sources)
	target_sources(Acid PRIVATE
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/${_acid_source}>
			)
endforeach()
