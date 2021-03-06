#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
/*
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
*/
#include <vector>
#include <map>
#include <set>
#include <list>
#include <string>
#include <assert.h>
#include <fstream>
#include <functional>
#include <atlstr.h>

using namespace std;

#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx9.h"
#include "ImGui/imgui_impl_win32.h"

#include "GlobalDefinition.h"

#include "System/Input/Input.h"
#include "System/Time.h"
#include "System/DX.h"
//#include "./system/Debug/Debug.h"

#include "Graphics/Data/DXDefinition.h"
#include "Graphics/Data/VertexTypes.h"
#include "Graphics/Data/Material.h"
#include "Graphics/Data/Light.h"
#include "Graphics/Data/Boundary.h"
#include "Graphics/Data/Hiding.h"

#include "Graphics/Interface/IDisplayObject.h"
//#include "Graphics/Interface/IUnitObject.h"
#include "Graphics/Interface/IScene.h"
#include "Graphics/Interface/IMap.h"
#include "Graphics/Shader/ShaderData.h"
#include "Graphics/Shader/IShader.h"

#include "Graphics/View/Camera.h"
#include "Graphics/View/Frustum.h"
#include "Graphics/View/Ray.h"

#include "Graphics/Model/X/SkinnedMeshHLSL.h"

#include "Manager/Assets.h"
#include "Manager/Objects.h"
#include "Manager/Scenes.h"
#include "Manager/Shaders.h"
#include "Manager/Rendering.h"
#include "Manager/GUI.h"

#include "Utility/BinaryFile.h"
#include "Utility/Path.h"
#include "Utility/String.h"
