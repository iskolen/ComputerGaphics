#pragma once
#include "BaseWindow.h"
#include "Cottage.h"
#include "BaseTexture.h"
#include "TextureLoader.h"
#include "Street.h"

class Window : public BaseWindow
{
public:
	Window(int w, int h, const char* title);

private:
	void OnMouseButton(int button, int action, [[maybe_unused]] int mods) override;
	void OnMouseMove(double x, double y) override;
	void RotateCamera(double xAngleRadians, double yAngleRadians);
	void OnResize(int width, int height) override;
	void OnRunStart() override;
	void Draw(int width, int height) override;
	void SetupCameraMatrix();
	void LoadTextures();
	void SetupTextures();

	TextureLoader m_textureLoader;
	Cottage m_cottage;
	Street m_street;

	bool m_leftButtonPressed = false;
	glm::dvec2 m_mousePos = {};
	glm::dmat4x4 m_cameraMatrix = glm::lookAt(
		glm::dvec3{ 0.0, 7.0f, -5.0f },
		glm::dvec3{ 0.0, 0.0, 0.0 },
		glm::dvec3{ 0.0, 1.0, 0.0 });

	BaseTexture m_wallTexture;
	BaseTexture m_roofTexture;
	BaseTexture m_pillarTexture;
	BaseTexture m_wallForCanopyTexture;
	BaseTexture m_garageDoorTexture;
	BaseTexture m_frontDoorTexture;
	BaseTexture m_windowTexture;

	BaseTexture m_grassTexture;
};