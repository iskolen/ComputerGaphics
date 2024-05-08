#include "pch.h"
#include "Diagram.h"

Diagram::Diagram()
    : m_sector1(0.7f, ToRadians(0), ToRadians(60), 0.1f, 0.0f, 0.05f, 0.0f),
    m_sector2(0.7f, ToRadians(60), ToRadians(90), 0.1f, 0.0f, 0.03f, 0.05f),
    m_sector3(0.7f, ToRadians(90), ToRadians(180), 0.15f, 0.0f, -0.02f, 0.02f),
    m_sector4(0.7f, ToRadians(180), ToRadians(225), 0.3f, 0.0f, -0.03f, -0.02f),
    m_sector5(0.7f, ToRadians(225), ToRadians(270), 0.1f, 0.0f, -0.02f, -0.05f),
    m_sector6(0.7f, ToRadians(270), ToRadians(360), 0.2f, 0.0f, 0.07f, -0.07f)
{
}

void Diagram::Draw() const
{
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);

    m_sector1.Draw(glm::vec3(0.0f, 1.0f, 0.0f));
    m_sector2.Draw(glm::vec3(1.0f, 1.0f, 0.0f));
    m_sector3.Draw(glm::vec3(1.0f, 0.0f, 0.0f));
    m_sector4.Draw(glm::vec3(1.0f, 1.0f, 0.0f));
    m_sector5.Draw(glm::vec3(0.0f, 0.0f, 1.0f));
    m_sector6.Draw(glm::vec3(1.0f, 0.0f, 0.0f));
}

float Diagram::ToRadians(float angle) const
{
    // y° = (y * π) / 180 - Перевод из градусов в радианы
    return static_cast<float>(angle) * static_cast<float>(M_PI) / 180.0f;
}
