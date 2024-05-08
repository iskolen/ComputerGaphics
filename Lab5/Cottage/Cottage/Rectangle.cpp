#include "pch.h"
#include "Rectangle.h"

Rectangle::Rectangle(const glm::vec3& topLeft, const glm::vec3& bottomRight)
    : m_topLeft(topLeft), m_bottomRight(bottomRight)
{
}

void Rectangle::Draw() const
{
    m_texture.BindTo();

    glBegin(GL_QUADS);

    // Top left corner
    glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(glm::value_ptr(m_topLeft));

    // Top right corner
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(m_bottomRight.x, m_topLeft.y, m_topLeft.z);

    // Bottom right corner
    glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(glm::value_ptr(m_bottomRight));

    // Bottom left corner
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(m_topLeft.x, m_bottomRight.y, m_topLeft.z);

    glEnd();
}

void Rectangle::SetTexture(BaseTexture const& texture)
{
    m_texture = texture;
}