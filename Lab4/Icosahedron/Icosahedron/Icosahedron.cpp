#include "pch.h"
#include "Icosahedron.h"

Icosahedron::Icosahedron(float size)
	: m_size(size)
{
	constexpr glm::vec4 defaultColor{ 1, 1, 1, 1 };
	for (size_t i = 0; i < 20; ++i)
	{
		SetSideColor(static_cast<IcosahedronSide>(i), defaultColor);
	}
}

void Icosahedron::Draw() const
{
	/*
	Список вершин для икосаэдра

	Вершина	x	y	z
	0		0	1	t
	1		0	1	-t
	2		1	t	0
	3		1	-t	0
	4		0	-1	-t
	5		0	-1	t
	6		t	0	1
	7		-t	0	1
	8		t	0	-1
	9		-t	0	-1
	10		-1	t	0
	11		-1	-t	0
	*/

	float t = (sqrtf(5) - 1) / 2;

	static float vertices[12][3] = 
	{
		{ 0, +1, t },   // Вершина 1
		{ 0, +1, -t },  // Вершина 2
		{ +1, t, 0 },   // Вершина 3
		{ +1, -t, 0 },  // Вершина 4
		{ 0, -1, -t },  // Вершина 5
		{ 0, -1, t },   // Вершина 6
		{ t, 0, +1 },   // Вершина 7
		{ -t, 0, +1 },  // Вершина 8
		{ t, 0, -1 },   // Вершина 9
		{ -t, 0, -1 },  // Вершина 10
		{ -1, t, 0 },   // Вершина 11
		{ -1, -t, 0 }   // Вершина 12
	};

	static constexpr unsigned char faces[20][3] =
	{
		{11, 4, 5},  // Грань 1
		{7, 11, 5},  // Грань 2
		{7, 5, 6},   // Грань 3
		{0, 7, 6},   // Грань 4
		{0, 6, 2},   // Грань 5
		{1, 0, 2},   // Грань 6
		{1, 2, 8},   // Грань 7
		{9, 1, 8},   // Грань 8
		{9, 8, 4},   // Грань 9
		{11, 9, 4},  // Грань 10
		{11, 7, 10}, // Грань 11
		{7, 0, 10},  // Грань 12
		{0, 1, 10},  // Грань 13
		{1, 9, 10},  // Грань 14
		{9, 11, 10}, // Грань 15
		{5, 4, 3},   // Грань 16
		{6, 5, 3},   // Грань 17
		{2, 6, 3},   // Грань 18
		{8, 2, 3},   // Грань 19
		{4, 8, 3}    // Грань 20
	};

	static size_t const faceCount = sizeof(faces) / sizeof(*faces);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

	glBegin(GL_TRIANGLES);
	{
		for (size_t face = 0; face < faceCount; ++face)
		{
			glColor4fv(glm::value_ptr(m_sideColors[face]));
			const unsigned char* facePoints = faces[face];

			auto p0 = glm::make_vec3(vertices[facePoints[0]]);
			auto p1 = glm::make_vec3(vertices[facePoints[1]]);
			auto p2 = glm::make_vec3(vertices[facePoints[2]]);

			// Найти векторное произведение между двумя векторами
			// Знать формулу диффузного освещения Ламберта и зеркального освещения Фонга
			// Как извлечь камеру наблю

			p0 *= m_size * 0.5f;
			p1 *= m_size * 0.5f;
			p2 *= m_size * 0.5f;

			auto v01 = p1 - p0;
			auto v02 = p2 - p0;
			auto normal = glm::normalize(glm::cross(v01, v02));

			glNormal3fv(glm::value_ptr(normal));

			glVertex3fv(glm::value_ptr(p0));
			glVertex3fv(glm::value_ptr(p1));
			glVertex3fv(glm::value_ptr(p2));
		}
	}
	glEnd();
}

void Icosahedron::SetSideColor(IcosahedronSide side, const glm::vec4& color)
{
	unsigned index = static_cast<unsigned>(side);
	m_sideColors[index] = color;
}

void Icosahedron::SetSpecularColor(glm::vec4 color)
{
	m_specularColor = color;
}

void Icosahedron::SetShininess(float shininess)
{
	m_shininess = shininess;
}