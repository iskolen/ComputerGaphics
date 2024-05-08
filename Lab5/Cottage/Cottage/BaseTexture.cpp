#include "pch.h"
#include "BaseTexture.h"

BaseTexture::BaseTexture(GLuint texture)
    : m_texture(texture)
{
}

void BaseTexture::Delete()
{
	if (m_texture)
	{
		glDeleteTextures(1, &m_texture);
	}
}

void BaseTexture::BindTo() const
{
	if (m_texture)
	{
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}
}
