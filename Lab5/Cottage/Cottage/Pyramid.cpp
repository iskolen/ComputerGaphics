#include "pch.h"
#include "Pyramid.h"

Pyramid::Pyramid(const glm::vec3& startPos, float width, float height, float depth, float textureScale)
    : m_startPos(startPos), m_width(width), m_height(height), m_depth(depth), m_textureScale(textureScale)
{
}

void Pyramid::Draw() const
{
    m_texture.BindTo();

    glm::vec3 frontLeft = m_startPos;
    glm::vec3 frontRight = m_startPos + glm::vec3(m_width, 0.0f, 0.0f);
    glm::vec3 backLeft = m_startPos + glm::vec3(0.0f, 0.0f, -m_depth);
    glm::vec3 backRight = m_startPos + glm::vec3(m_width, 0.0f, -m_depth);
    glm::vec3 top = m_startPos + glm::vec3(m_width / 2, m_height, -m_depth / 2);

    DrawTriangle(top, frontLeft, frontRight);
    DrawTriangle(top, backLeft, frontLeft);
    DrawTriangle(top, backRight, backLeft);
    DrawTriangle(top, frontRight, backRight);

    DrawQuad(frontLeft, backLeft, backRight, frontRight);

}
void Pyramid::SetTexture(BaseTexture const& texture)
{
    m_texture = texture;
}

void Pyramid::CalculateAndSetNormal(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2) const
{
    glm::vec3 v01 = p1 - p0;
    glm::vec3 v02 = p2 - p0;
    glm::vec3 normal = glm::normalize(glm::cross(v01, v02));
    glNormal3fv(glm::value_ptr(normal));
}

void Pyramid::DrawQuad(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3) const
{
    glBegin(GL_QUADS);

    CalculateAndSetNormal(p0, p1, p2);
    glTexCoord2f(0.0f, m_textureScale);
    glVertex3fv(glm::value_ptr(p0));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(glm::value_ptr(p1));
    glTexCoord2f(m_textureScale, 0.0f);
    glVertex3fv(glm::value_ptr(p2));
    glTexCoord2f(m_textureScale, m_textureScale);
    glVertex3fv(glm::value_ptr(p3));

    glEnd();
}

void Pyramid::DrawTriangle(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2) const
{
    glBegin(GL_TRIANGLES);
    
    CalculateAndSetNormal(p0, p1, p2);
    glTexCoord2f(0.0f, m_textureScale);
    glVertex3fv(glm::value_ptr(p0));
    glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(glm::value_ptr(p1));
    glTexCoord2f(m_textureScale, 0.0f);
    glVertex3fv(glm::value_ptr(p2));

    glEnd();
}