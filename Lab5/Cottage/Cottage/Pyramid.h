#pragma once
#include "BaseTexture.h"

class Pyramid
{
public:
    explicit Pyramid(
        const glm::vec3& startPos = glm::vec3(0.0f),
        float width = 1.0f,
        float height = 1.0f,
        float depth = 1.0f,
        float textureScale = 1.0f
    );

    void Draw() const;
    void SetTexture(BaseTexture const& texture);

private:
    void CalculateAndSetNormal(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2) const;

    void DrawQuad(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3) const;
    void DrawTriangle(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2) const;

    float m_width;
    float m_height;
    float m_depth;
    float m_textureScale;
    glm::vec3 m_startPos;

    BaseTexture m_texture;
};

