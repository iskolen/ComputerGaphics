#pragma once
class Sector
{
public:
	Sector(
		float radius, 
		float startAngle, 
		float endAngle, 
		float zTop, 
		float zBottom, 
		float xStart, 
		float yStart
	);
	void Draw(const glm::vec3& color) const;

private:
	void CalculateAndSetNormal(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2) const;
	void DrawQuadVertices(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3) const;

	float m_radius;
	float m_startAngle;
	float m_endAngle;
	float m_zTop;
	float m_zBottom;
	float m_xStart;
	float m_yStart;
};

