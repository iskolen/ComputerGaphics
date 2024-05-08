#pragma once
#include "BaseTexture.h"

class TextureLoader
{
public:
	BaseTexture LoadTexture2D(std::string const& fileName) const;

private:
	GLenum m_wrapS = GL_REPEAT;
	GLenum m_wrapT = GL_REPEAT;
	GLenum m_minFilter = GL_NEAREST;
	GLenum m_magFilter = GL_NEAREST;
};

