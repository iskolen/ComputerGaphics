#pragma once
#include "Cuboid.h"
#include "Pyramid.h"
#include "Rectangle.h"
#include "BaseTexture.h"

class Cottage
{
public:
	explicit Cottage();

	void Draw() const;
	void SetWallTextures(BaseTexture const& texture);
	void SetRoofTextures(BaseTexture const& texture);
	void SetPillarTextures(BaseTexture const& texture);
	void SetWallForCanopyTextures(BaseTexture const& texture);
	void SetGarageDoorTexture(BaseTexture const& texture);
	void SetFrontDoorTexture(BaseTexture const& texture);
	void SetWindowTextures(BaseTexture const& texture);

private:
	Cuboid m_mainWall;
	Pyramid m_mainRoof;

	Pyramid m_canopy1;
	Cuboid m_canopy2;
	Cuboid m_canopy3;

	Cuboid m_canopyPillar1;
	Cuboid m_canopyPillar2;

	Cuboid m_garageDoor;
	Cuboid m_frontDoor;

	Cuboid m_window1;
	Cuboid m_window2;
	Cuboid m_window3;
	Cuboid m_window4;
};
