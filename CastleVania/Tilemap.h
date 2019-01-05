#pragma once
#include "TextureManager.h"
#include <fstream>
#include "GameUtils.h"
#include "Camera.h"
#include "Game.h"

class Tilemap
{
	int numMatrixRows, numMatrixCols;
	int tileWidth, tileHeight;
	int numTilesheetCols;

	int** matrix;
public:
	void Init(const char* tilesheetPath, const char* matrixPath);
	void Init(const char* folderPath);

	void Render(Camera* camera);

	int getWorldHeight();

	Tilemap();
	~Tilemap();
};

