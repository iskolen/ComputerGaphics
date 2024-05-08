#include "pch.h"
#include "Thor.h"

Thor::Thor()
{
}

void Thor::Draw() const
{
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m_shininess);
    glColor3f(0.0f, 0.5f, 1.0f);

    const float alphaStep = 2.0f * static_cast<float>(M_PI) / m_numMajor;
    const float betaStep = 2.0f * static_cast<float>(M_PI) / m_numMinor;

    for (int i = 0; i < m_numMajor; ++i)
    {
        const float alpha0 = i * alphaStep;
        const float alpha1 = alpha0 + alphaStep;

        const float x0 = std::cos(alpha0);
        const float y0 = std::sin(alpha0);
        const float x1 = std::cos(alpha1);
        const float y1 = std::sin(alpha1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= m_numMinor; ++j)
        {
            const float beta = j * betaStep;
            const float cosBeta = std::cos(beta);
            const float radius = m_minorRadius * cosBeta + m_majorRadius;
            const float z = m_minorRadius * std::sin(beta);

            glNormal3f(x0 * cosBeta, y0 * cosBeta, z / m_minorRadius);
            glVertex3f(x0 * radius, y0 * radius, z);

            glNormal3f(x1 * cosBeta, y1 * cosBeta, z / m_minorRadius);
            glVertex3f(x1 * radius, y1 * radius, z);
        }
        glEnd();
    }
}