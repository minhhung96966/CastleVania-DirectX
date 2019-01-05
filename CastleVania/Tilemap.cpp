#include "Tilemap.h"


Tilemap::Tilemap()
{
}

void Tilemap::Init(const char* tilesheetPath, const char* matrixPath)
{
	ifstream fs(matrixPath);
	
	fs >> numMatrixRows >> numMatrixCols >> tileWidth >> tileHeight >> numTilesheetCols;

	
	matrix = new int*[numMatrixRows];

	for (int rowIndex = 0; rowIndex < numMatrixRows; rowIndex++)
	{
		matrix[rowIndex] = new int[numMatrixCols];
		for (int colIndex = 0; colIndex < numMatrixCols; colIndex++) {
			fs >> matrix[rowIndex][colIndex];
		}
	}
}


void Tilemap::Init(const char* folderPath)
{
	string folderPathString = string(folderPath);
	string tilesheetPathString = folderPathString.append("/tilesheet.png");

	//Chuyen qua lai kieu LPCWSTR
	wstring ws = stringToWstring(tilesheetPathString);
	LPCWSTR tilesheetPath = ws.c_str();

	TextureManager::GetInstance()->Add(TEXTURE_TILESHEET, tilesheetPath, 0);

	string folderPathString_ = string(folderPath);
	string matrixPathString = folderPathString_.append("/matrix.dat");

	Init(tilesheetPathString.c_str(), matrixPathString.c_str());
}

void Tilemap::Render(Camera * camera)
{
	int mapHeight = numMatrixRows * tileHeight;
	int tileLeft, tileRight, tileTop, tileBottom;
	tileLeft = camera->getLeft() / tileWidth;
	tileRight = camera->getRight() / tileWidth;
	tileTop = (mapHeight - camera->getTop()) / tileHeight;
	tileBottom = (mapHeight - camera->getBottom()) / tileHeight;

	//Dieu kien rang buoc chong loi vuot qua index
	if (tileLeft < 0) tileLeft = 0;
	if (tileTop < 0) tileTop = 0;
	if (tileRight >= numMatrixCols) tileRight = numMatrixCols - 1;
	if (tileBottom >= numMatrixRows) tileBottom = numMatrixRows - 1;
	
	for (size_t rowIndex = tileTop; rowIndex <= tileBottom; rowIndex++)
	{
		for (size_t columnIndex = tileLeft; columnIndex <= tileRight; columnIndex++)
		{
			int xWorldOfTile = columnIndex * tileWidth;
			int yWorldOfTile = mapHeight - rowIndex * tileHeight;

			float xViewOfTile = 0;
			float yViewOfTile = 0;

			camera->convertWorldToView(xWorldOfTile, yWorldOfTile, xViewOfTile, yViewOfTile);

			int tileValue = matrix[rowIndex][columnIndex];

			int xTileInTileSheet = tileWidth * (tileValue % numTilesheetCols);
			int yTileInTileSheet = tileHeight * (tileValue / numTilesheetCols);
			int widthTileInTilesheet = tileWidth;
			int heightTileInTilesheet = tileHeight;

			RECT rectCrop;
			SetRect(&rectCrop,
				xTileInTileSheet, 
				yTileInTileSheet,
				xTileInTileSheet + widthTileInTilesheet, 
				yTileInTileSheet + heightTileInTilesheet); 

			//Hình tilesheet
			LPDIRECT3DTEXTURE9 tilesheet = TextureManager::GetInstance()->Get(TEXTURE_TILESHEET);

			CGame::GetInstance()->GetSprite()->Draw(tilesheet,
						&rectCrop,
						&D3DXVECTOR3(0, 0, 0),
						&D3DXVECTOR3(xViewOfTile, yViewOfTile, 0),
						D3DCOLOR_XRGB(255, 255, 255));
		}
	}
}

int Tilemap::getWorldHeight()
{
	return numMatrixRows * tileHeight;
}


Tilemap::~Tilemap()
{
}
