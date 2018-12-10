#include "stdafx.h"
#include "ObjMap.h"
#include "ObjLoader.h"

ObjMap::ObjMap()
{
	rayOffsetY = 5.0f;
}


ObjMap::~ObjMap()
{
	Rendering::Get()->RemoveRenderingObject(this);

	SAFE_RELEASE(mesh);

	material = NULL;
	for (auto p : materials)
		SAFE_DELETE(p);
}

void ObjMap::Init()
{
	shaderType = ST_Shadow;
	Rendering::Get()->AddRenderingObject(this);
}

void ObjMap::Load(wstring filePath, wstring fileName, D3DXMATRIX* transform)
{
	ObjLoader loader;
	mesh = loader.LoadMesh(filePath.c_str(), fileName.c_str(), transform, materials);
	loader.CreateSurface(surfaceVertices);
}

void ObjMap::Update()
{
	if (Input::ButtonDown(Input::RBUTTON))
	{
		D3DXVECTOR3 pos = Input::GetMousePosition();

		if (ComputeClickPosition(pos, pos.x, pos.y) == true)
		{
			Objects::GetPlayer()->SetPosition(&pos);
		}
	}
}

void ObjMap::Render()
{
	//Shaders::Get()->GetShader(shaderType)->Render(this);
}

void ObjMap::Render(IShader * pShader)
{
	for (size_t i = 0; i < materials.size(); ++i)
	{
		currentSubset = i;
		material = materials[i];
		
		pShader->Render(this);
	}
}

void ObjMap::Draw()
{
	mesh->DrawSubset(currentSubset);
}


bool ObjMap::ComputeHeight(float & height, const D3DXVECTOR3 & pos)
{
	Ray ray(
		D3DXVECTOR3(pos.x, pos.y + rayOffsetY, pos.z),
		D3DXVECTOR3(0, -1, 0));
	float distance;
	float currentHeight;
	float maxHeight = -99999;
	for (size_t i = 0; i < surfaceVertices.size(); i += 3)
	{
		if (D3DXIntersectTri(&surfaceVertices[i], &surfaceVertices[i + 1], &surfaceVertices[i + 2],
			&ray.position, &ray.direction, NULL, NULL, &distance))
		{
			currentHeight = ray.position.y - distance;

			if (currentHeight > maxHeight + FLT_EPSILON)
			{
				maxHeight = currentHeight;
				height = currentHeight;
			}
		}
	}
	
	if (maxHeight == -99999)
		return false;
	else
		return true;
}

bool ObjMap::ComputeClickPosition(D3DXVECTOR3 & vOut, WORD screenX, WORD screenY)
{
	Ray		ray = Ray::RayFromScreenToWorld(screenX, screenY);
	float	minDist = FLT_MAX;
	float	currentDist = 0;
	bool	bIntersect = false;

	for (int i = 0; i < surfaceVertices.size(); i += 3)
	{
		if (ray.IntersectTri(
			&surfaceVertices[i],
			&surfaceVertices[i + 1],
			&surfaceVertices[i + 2], &currentDist))
		{
			if (currentDist < minDist)
			{
				bIntersect = true;
				minDist = currentDist;
				vOut = ray.position + ray.direction * currentDist;
			}
		}
	}
	return bIntersect;
}



