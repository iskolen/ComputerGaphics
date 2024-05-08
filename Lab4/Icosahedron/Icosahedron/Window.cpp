#include "pch.h"
#include "Window.h"
#include "DirectLight.h"

namespace
{
	constexpr double FIELD_OF_VIEW = 60 * M_PI / 180.0;
	constexpr double ICOSAHEDRON_SIZE = 1;

	constexpr double Z_NEAR = 0.1;
	constexpr double Z_FAR = 10;

	glm::dmat4x4 Orthonormalize(const glm::dmat4x4& m)
	{
		const auto normalizedMatrix = glm::orthonormalize(glm::dmat3x3{ m });
		return
		{
			glm::dvec4{ normalizedMatrix[0], 0.0 },
			glm::dvec4{ normalizedMatrix[1], 0.0 },
			glm::dvec4{ normalizedMatrix[2], 0.0 },
			m[3]
		};
	}

} // namespace

Window::Window(int w, int h, const char* title)
	: BaseWindow(w, h, title)
	, m_icosahedron(ICOSAHEDRON_SIZE)
{
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_1, { 1, 0, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_2, { 0, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_3, { 0, 0, 1, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_4, { 1, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_5, { 0, 1, 1, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_6, { 1, 0, 1, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_7, { 1, 0, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_8, { 0, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_9, { 0, 0, 1, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_10, { 1, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_11, { 0, 1, 1, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_12, { 1, 0, 1, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_13, { 1, 0, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_14, { 1, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_15, { 0, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_16, { 0, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_17, { 1, 0, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_18, { 0, 0, 1, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_19, { 1, 1, 0, 1 });
	m_icosahedron.SetSideColor(IcosahedronSide::SIDE_20, { 0, 1, 1, 1 });

	m_icosahedron.SetSpecularColor({ 1, 1, 1, 1 });
	m_icosahedron.SetShininess(4.0f);
}

void Window::OnMouseButton(int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_1)
	{
		m_leftButtonPressed = (action & GLFW_PRESS) != 0;
	}
}

void Window::OnMouseMove(double x, double y)
{
	const glm::dvec2 mousePos{ x, y };
	if (m_leftButtonPressed)
	{
		const auto windowSize = GetFramebufferSize();

		const auto mouseDelta = mousePos - m_mousePos;
		const double xAngle = mouseDelta.y * M_PI / windowSize.y;
		const double yAngle = mouseDelta.x * M_PI / windowSize.x;
		RotateCamera(xAngle, yAngle);
	}
	m_mousePos = mousePos;
}

void Window::RotateCamera(double xAngleRadians, double yAngleRadians)
{
	const glm::dvec3 xAxis
	{
		m_cameraMatrix[0][0], m_cameraMatrix[1][0], m_cameraMatrix[2][0]
	};
	const glm::dvec3 yAxis
	{
		m_cameraMatrix[0][1], m_cameraMatrix[1][1], m_cameraMatrix[2][1]
	};
	m_cameraMatrix = glm::rotate(m_cameraMatrix, xAngleRadians, xAxis);
	m_cameraMatrix = glm::rotate(m_cameraMatrix, yAngleRadians, yAxis);

	m_cameraMatrix = Orthonormalize(m_cameraMatrix);
}

void Window::OnResize(int width, int height)
{
	glViewport(0, 0, width, height);
	double aspect = double(width) / double(height);
	glMatrixMode(GL_PROJECTION);
	const auto proj = glm::perspective(FIELD_OF_VIEW, aspect, Z_NEAR, Z_FAR);
	glLoadMatrixd(&proj[0][0]);
	glMatrixMode(GL_MODELVIEW);
}

void Window::OnRunStart()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_DEPTH_TEST);

	DirectLight light{ { 0.0f, 0.0f, 2.0f } };
	light.SetDiffuseIntensity({ 0.5f, 0.5f, 0.5f, 1.0f });
	light.SetAmbientIntensity({ 0.0f, 0.0f, 0.0f, 1.0f });
	light.SetSpecularIntensity({ 0.3f, 0.3f, 0.3f, 1.0f });
	light.Apply(GL_LIGHT0);
}

void Window::Draw(int width, int height)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetupCameraMatrix();

	m_icosahedron.Draw();
}

void Window::SetupCameraMatrix()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(&m_cameraMatrix[0][0]);
}