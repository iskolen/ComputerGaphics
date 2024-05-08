#pragma once

enum class IcosahedronSide
{
	SIDE_1,
	SIDE_2,
	SIDE_3,
	SIDE_4,
	SIDE_5,
	SIDE_6,
	SIDE_7,
	SIDE_8,
	SIDE_9,
	SIDE_10,
	SIDE_11,
	SIDE_12,
	SIDE_13,
	SIDE_14,
	SIDE_15,
	SIDE_16,
	SIDE_17,
	SIDE_18,
	SIDE_19,
	SIDE_20
};

class Icosahedron
{
public:
	explicit Icosahedron(float size = 1);
	void Draw() const;

	void SetSideColor(IcosahedronSide side, const glm::vec4& color);
	void SetSpecularColor(glm::vec4 color);
	void SetShininess(float shininess);

private:
	float m_size;
	glm::vec4 m_sideColors[20];
	glm::vec4 m_specularColor = { 0, 0, 0, 1 };
	float m_shininess = 1;
};