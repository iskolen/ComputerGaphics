#pragma once

class BaseTexture
{
public:
    BaseTexture() = default;
    BaseTexture(GLuint texture);

    void Delete();
    void BindTo() const;

private:
    GLuint m_texture = 0;
};