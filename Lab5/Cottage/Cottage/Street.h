#pragma once
#include "Cuboid.h"
#include "Pyramid.h"
#include "BaseTexture.h"

class Street
{
public:
	explicit Street();

	void Draw() const;
	void SetGrassTextures(BaseTexture const& texture);

private:
	Cuboid m_grass;
};

