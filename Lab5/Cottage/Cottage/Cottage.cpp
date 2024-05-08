#include "pch.h"
#include "Cottage.h"

// startPos, width, height, depth, textureScale

Cottage::Cottage()
    : m_mainWall(glm::vec3(-2.0f, 0.0f, -2.0f), 5, 2, 3, 1),
    m_mainRoof(glm::vec3(-2.5f, 2.0f, -1.5f), 6, 2, 4, 3),

    m_canopy1(glm::vec3(-2.0f, 1.5f, 0.0f), 2, 0.5f, 2, 1),
    m_canopy2(glm::vec3(-2.0f, 1.3f, 0.0f), 2.0f, 0.2f, 2.0f, 0.2f),

    m_canopyPillar1(glm::vec3(-2.0f, 0.0f, 0.0f), 0.2f, 1.3f, 0.2f, 1),
    m_canopyPillar2(glm::vec3(-0.2f, 0.0f, 0.0f), 0.2f, 1.3f, 0.2f, 1),

    m_garageDoor(glm::vec3(-1.7f, 0.0f, -1.95f), 1.25f, 1.25f, 0.05f, 1),
    m_frontDoor(glm::vec3(1.0f, 0.0f, -1.95f), 0.5f, 1.0f, 0.05f, 1),
    m_window1(glm::vec3(2.0f, 0.5f, -1.95f), 0.3f, 0.5f, 0.05f, 1),
    m_window2(glm::vec3(3.05f, 0.5f, -3.0f), 0.05f, 0.5f, 0.5f, 1),
    m_window3(glm::vec3(-2.05f, 0.5f, -3.0f), 0.05f, 0.5f, 0.5f, 1),
    m_window4(glm::vec3(2.0f, 0.5f, -5.05f), 0.3f, 0.5f, 0.05f, 1)
{
}

void Cottage::Draw() const
{
    m_mainWall.Draw();
    m_mainRoof.Draw();

    m_canopy1.Draw();
    m_canopy2.Draw();

    m_canopyPillar1.Draw();
    m_canopyPillar2.Draw();

    m_garageDoor.Draw();
    m_frontDoor.Draw();
    m_window1.Draw();
    m_window2.Draw();
    m_window3.Draw();
    m_window4.Draw();
}

void Cottage::SetWallTextures(BaseTexture const& texture)
{
    m_mainWall.SetTexture(texture);
}

void Cottage::SetRoofTextures(BaseTexture const& texture)
{
    m_mainRoof.SetTexture(texture);
    m_canopy1.SetTexture(texture);
}

void Cottage::SetPillarTextures(BaseTexture const& texture)
{
    m_canopyPillar1.SetTexture(texture);
    m_canopyPillar2.SetTexture(texture);
}

void Cottage::SetWallForCanopyTextures(BaseTexture const& texture)
{
    m_canopy2.SetTexture(texture);
}

void Cottage::SetGarageDoorTexture(BaseTexture const& texture)
{
    m_garageDoor.SetTexture(texture);
}

void Cottage::SetFrontDoorTexture(BaseTexture const& texture)
{
    m_frontDoor.SetTexture(texture);
}

void Cottage::SetWindowTextures(BaseTexture const& texture)
{
    m_window1.SetTexture(texture);
    m_window2.SetTexture(texture);
    m_window3.SetTexture(texture);
    m_window4.SetTexture(texture);
}
