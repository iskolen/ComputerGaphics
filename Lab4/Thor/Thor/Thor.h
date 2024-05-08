#pragma once

class Thor
{
public:
	explicit Thor();
	void Draw() const;

private:
	float m_shininess = 1;

	int m_numMajor = 200;
	int m_numMinor = 100;
	float m_majorRadius = 0.5f;
	float m_minorRadius = 0.2f;
};