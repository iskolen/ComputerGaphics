#include "pch.h"
#include "Street.h"

Street::Street()
	:m_grass(glm::vec3(-25.0f, -0.2f, 25.0f), 50, 0.2, 50, 10)
{
}

void Street::Draw() const
{
	m_grass.Draw();
}

void Street::SetGrassTextures(BaseTexture const& texture)
{
	m_grass.SetTexture(texture);
}
