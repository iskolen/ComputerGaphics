#include "pch.h"
#include "Sector.h"

Sector::Sector(float radius, float startAngle, float endAngle, float zTop, float zBottom, float xStart, float yStart)
    :m_radius(radius), 
    m_startAngle(startAngle),
    m_endAngle(endAngle),
    m_zTop(zTop),
    m_zBottom(zBottom),
    m_xStart(xStart),
    m_yStart(yStart)
{
}

void Sector::Draw(const glm::vec3& color) const
{
    glColor3fv(glm::value_ptr(color));
    
    glm::vec3 p0, p1, p2, p3;

    // Верхняя
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(m_xStart, m_yStart, m_zTop);

    for (int i = 0; i <= NUM_SEGMENTS; ++i)
    {
        float angle = m_startAngle + (m_endAngle - m_startAngle) * static_cast<float>(i) / static_cast<float>(NUM_SEGMENTS);
        float x = m_radius * std::cos(angle) + m_xStart;
        float y = m_radius * std::sin(angle) + m_yStart;

        float angleNext = m_startAngle + (m_endAngle - m_startAngle) * static_cast<float>(i + 1) / static_cast<float>(NUM_SEGMENTS);
        float xNext = m_radius * std::cos(angleNext) + m_xStart;
        float yNext = m_radius * std::sin(angleNext) + m_yStart;

        p0 = glm::vec3(m_xStart, m_yStart, m_zTop);
        p1 = glm::vec3(x, y, m_zTop);
        p2 = glm::vec3(xNext, yNext, m_zTop);

        CalculateAndSetNormal(p0, p1, p2);

        glVertex3f(x, y, m_zTop);
    }
    glEnd();

    // Нижняя
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(m_xStart, m_yStart, m_zBottom);

    for (int i = NUM_SEGMENTS; i >= 0; --i)
    {
        float angle = m_startAngle + (m_endAngle - m_startAngle) * static_cast<float>(i) / static_cast<float>(NUM_SEGMENTS);
        float x = m_radius * std::cos(angle) + m_xStart;
        float y = m_radius * std::sin(angle) + m_yStart;

        float angleNext = m_startAngle + (m_endAngle - m_startAngle) * static_cast<float>(i - 1) / static_cast<float>(NUM_SEGMENTS);
        float xNext = m_radius * std::cos(angleNext) + m_xStart;
        float yNext = m_radius * std::sin(angleNext) + m_yStart;

        p0 = glm::vec3(m_xStart, m_yStart, m_zBottom);
        p1 = glm::vec3(x, y, m_zBottom);
        p2 = glm::vec3(xNext, yNext, m_zBottom);

        CalculateAndSetNormal(p0, p1, p2);

        glVertex3f(x, y, m_zBottom);
    }
    glEnd();

    // Задняя стенка
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= NUM_SEGMENTS; ++i)
    {
        float angle = m_startAngle + (m_endAngle - m_startAngle) * static_cast<float>(i) / static_cast<float>(NUM_SEGMENTS);
        float x = m_radius * std::cos(angle) + m_xStart;
        float y = m_radius * std::sin(angle) + m_yStart;

        float angleNext = m_startAngle + (m_endAngle - m_startAngle) * static_cast<float>(i + 1) / static_cast<float>(NUM_SEGMENTS);
        float xNext = m_radius * std::cos(angleNext) + m_xStart;
        float yNext = m_radius * std::sin(angleNext) + m_yStart;

        p0 = glm::vec3(x, y, m_zTop);
        p1 = glm::vec3(x, y, m_zBottom);
        p2 = glm::vec3(xNext, yNext, m_zTop);

        CalculateAndSetNormal(p0, p1, p2);

        glVertex3f(x, y, m_zTop);
        glVertex3f(x, y, m_zBottom);
    }
    glEnd();

    float leftWallXEnd = m_radius * std::cos(m_startAngle) + m_xStart;
    float leftWallYEnd = m_radius * std::sin(m_startAngle) + m_yStart;

    // Левая боковая поверхность
    glBegin(GL_QUADS);
    p0 = glm::vec3(m_xStart, m_yStart, m_zTop);
    p1 = glm::vec3(m_xStart, m_yStart, m_zBottom);
    p2 = glm::vec3(leftWallXEnd, leftWallYEnd, m_zBottom);
    p3 = glm::vec3(leftWallXEnd, leftWallYEnd, m_zTop);

    CalculateAndSetNormal(p0, p1, p2);
    DrawQuadVertices(p0, p1, p2, p3);
    glEnd();

    float rightWallXEnd = m_radius * std::cos(m_endAngle) + m_xStart;
    float rightWallYEnd = m_radius * std::sin(m_endAngle) + m_yStart;

    // Правая боковая поверхность
    glBegin(GL_QUADS);
    p0 = glm::vec3(rightWallXEnd, rightWallYEnd, m_zTop);
    p1 = glm::vec3(rightWallXEnd, rightWallYEnd, m_zBottom);
    p2 = glm::vec3(m_xStart, m_yStart, m_zBottom);
    p3 = glm::vec3(m_xStart, m_yStart, m_zTop);

    CalculateAndSetNormal(p0, p1, p2);
    DrawQuadVertices(p0, p1, p2, p3);
    glEnd();
}

void Sector::CalculateAndSetNormal(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2) const
{
    auto v01 = p1 - p0;
    auto v02 = p2 - p0;
    auto normal = glm::normalize(glm::cross(v01, v02));
    glNormal3fv(glm::value_ptr(normal));
}

// Разобратся с освещением

void Sector::DrawQuadVertices(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3) const
{
    glVertex3fv(glm::value_ptr(p0));
    glVertex3fv(glm::value_ptr(p1));
    glVertex3fv(glm::value_ptr(p2));
    glVertex3fv(glm::value_ptr(p3));
}