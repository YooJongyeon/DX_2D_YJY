#pragma once

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define PI 3.141592

#define DEVICE Device::GetInstance()->GetDevice()
#define DEVICE_CONTEXT Device::GetInstance()->GetDeviceContext()

#define DELTA_TIME Time::GetInstance()->GetDeltamTime();

#define KEY_PRESS(k) InputManger::GetInstance()->Press(k)
#define KEY_Down(k)  InputManger::GetInstance()->Down(k)
#define KEY_Up(k)    InputManger::GetInstance()->Up(k)
#define MOUSE_POS    InputManger::GetInstance()->GetMousePos()

#define SMAPLER_STATE   StateManager::GetInstance()->GetSamplerState()
#define ALPHA_STATE     StateManager::GetInstance()->GetAlphaState()
#define ADDITVE_STATE   StateManager::GetInstance()->GetAdditiveState()
#define BLEND_STATE     StateManager::GetInstance()->GetBlendState()
#define CULL_MODE_STATE StateManager::GetInstance()->GetRastizerState()

using Float2 = XMFLOAT2;
using Float3 = XMFLOAT3;
using Matrix = XMMATRIX;
using Float4x4 = XMFLOAT4X4;
