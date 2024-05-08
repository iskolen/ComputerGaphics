#pragma once
#include "BaseTexture.h"

class Rectangle
{
public:
    explicit Rectangle(
        const glm::vec3& topLeft = glm::vec3(0.0f),
        const glm::vec3& bottomRight = glm::vec3(1.0f)
    );

    void Draw() const;
    void SetTexture(BaseTexture const& texture);

private:
    glm::vec3 m_topLeft;
    glm::vec3 m_bottomRight;

    BaseTexture m_texture;
};