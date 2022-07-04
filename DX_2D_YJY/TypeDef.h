#pragma once

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define PI 3.141592

#define RED XMFLOAT4(1,0,0,1)
#define GREEN XMFLOAT4(0,1,0,1)
#define BLUE XMFLOAT4(0,0,1,1)
#define WHITE XMFLOAT4(1,1,1,1)
#define BLACK XMFLOAT4(0,0,0,1)


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

#define ADD_VS(k)       ShaderManger::Getinstance()->AddVS(k)
#define ADD_PS(k)       ShaderManger::Getinstance()->AddPS(k)
 
typedef function<void()> CallBack;
