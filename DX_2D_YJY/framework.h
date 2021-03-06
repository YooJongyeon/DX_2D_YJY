// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <wrl/client.h>
#include <string>
#include <memory>
#include <functional>
#include <time.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib,"dxguid.lib")

using namespace DirectX;
using namespace std;

// DirectX Tex
#include "../DirectXTex/DirectXTex.h";

// DirectWrite
#include <d2d1_1.h>
#include <dwrite.h>

#pragma comment(lib,"d2d1.lib")
#pragma comment(lib, "dwrite.lib")

//ImGui
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx11.h"
#include "../ImGui/imgui_impl_win32.h"

// Types
#include "TypeDef.h"

// Device
#include "Framework/Device/Device.h"

//Math
#include "Framework/Math/Vector2.h"

// Render
#include "Framework/Render/VertexLayOuts.h"
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/Shader.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"
#include "Framework/Render/ShaderManger.h"

// Coomponent
#include "Framework/Component/Transform.h"

//Utillty
#include "Framework/Utillty/Utillity.h"
#include "Framework/Utillty/Time.h"
#include "Framework/Utillty/InputManger.h"
#include "Framework/Utillty/BinaryWriter.h"
#include "Framework/Utillty/BinaryReader.h"
#include"Framework/Utillty/DirectWrite.h"

// Camera
#include "Framework/Camera/Camera.h"

// Collider
#include "Framework/Collider/Collider.h"
#include "Framework/Collider/CircleCollider.h"
#include "Framework/Collider/RectCollider.h"

// Texture
#include "Framework/Texture/SRV.h"
#include "Framework/Texture/SamplerState.h"
#include "Framework/Texture/BlendState.h"
#include"Framework/Texture/RasterizerState.h"
#include "Framework/Texture/StateManager.h"
#include "Framework/Texture/Texture.h"

//Animation
#include "Framework/Animation/Action.h"

// BagicObject
#include "Object/BagicObject/Quad.h"
#include "Object/BagicObject/Sprite.h"
#include "Object/BagicObject/Effect.h"
#include "Object/BagicObject/EffectManager.h"
#include "Object/UI/Bulton.h"

//Obj
#include "Object/GameObject/Player.h"
#include "Object/GameObject/Revolver.h"
#include "Object/GameObject/Bullet.h"
#include "Object/GameObject/Monster.h"
#include "Object/Zelda/Zelda.h"
#include "Object/Dungreed/Character.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"



