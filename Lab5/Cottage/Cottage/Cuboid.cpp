#include "pch.h"
#include "Cuboid.h"

Cuboid::Cuboid(const glm::vec3& startPos, float width, float height, float depth, float textureScale)
    : m_startPos(startPos), m_width(width), m_height(height), m_depth(depth), m_textureScale(textureScale)
{
}

void Cuboid::CalculateAndSetNormal(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2) const
{
    glm::vec3 v01 = p1 - p0;
    glm::vec3 v02 = p2 - p0;
    glm::vec3 normal = glm::normalize(glm::cross(v01, v02));
    glNormal3fv(glm::value_ptr(normal));
}

void Cuboid::DrawQuad(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3) const
{
    CalculateAndSetNormal(p0, p1, p2);
    glTexCoord2f(0.0f, m_textureScale);
    glVertex3fv(glm::value_ptr(p0));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(glm::value_ptr(p1));
    glTexCoord2f(m_textureScale, 0.0f);
    glVertex3fv(glm::value_ptr(p2));
    glTexCoord2f(m_textureScale, m_textureScale);
    glVertex3fv(glm::value_ptr(p3));
}

void Cuboid::Draw() const
{
    m_texture.BindTo();

    glm::vec3 frontBottomLeft = m_startPos;
    glm::vec3 frontTopLeft = m_startPos + glm::vec3(0.0f, m_height, 0.0f);
    glm::vec3 frontTopRight = m_startPos + glm::vec3(m_width, m_height, 0.0f);
    glm::vec3 frontBottomRight = m_startPos + glm::vec3(m_width, 0.0f, 0.0f);

    glm::vec3 backBottomLeft = m_startPos + glm::vec3(0.0f, 0.0f, -m_depth);
    glm::vec3 backTopLeft = m_startPos + glm::vec3(0.0f, m_height, -m_depth);
    glm::vec3 backTopRight = m_startPos + glm::vec3(m_width, m_height, -m_depth);
    glm::vec3 backBottomRight = m_startPos + glm::vec3(m_width, 0.0f, -m_depth);

    glBegin(GL_QUADS);

    DrawQuad(frontTopLeft, frontBottomLeft, frontBottomRight, frontTopRight);
    DrawQuad(backTopRight, backBottomRight, backBottomLeft, backTopLeft);
    DrawQuad(backTopLeft, frontTopLeft, frontTopRight, backTopRight);
    DrawQuad(frontBottomRight, frontBottomLeft, backBottomLeft, backBottomRight);
    DrawQuad(backTopLeft, backBottomLeft, frontBottomLeft, frontTopLeft);
    DrawQuad(frontTopRight, frontBottomRight, backBottomRight, backTopRight);

    glEnd();
}

void Cuboid::SetTexture(BaseTexture const& texture)
{
    m_texture = texture;
}