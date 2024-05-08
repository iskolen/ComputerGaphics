#pragma once
#include "Sector.h"

class Diagram
{
public:
	explicit Diagram();
	void Draw() const;

private:
	float m_shininess = 1;

	Sector m_sector1;
	Sector m_sector2;
	Sector m_sector3;
	Sector m_sector4;
	Sector m_sector5;
	Sector m_sector6;

	float ToRadians(float angle) const;
};