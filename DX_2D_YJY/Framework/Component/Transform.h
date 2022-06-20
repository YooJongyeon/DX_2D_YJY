#pragma once
class Transform
{
public:
    Transform();
    ~Transform();

    void UpdateWorldBuffer();
    void SetWorldBuffer(int slot = 0);

    Vector2& GetPos() { return _pos; }

    XMMATRIX* GetMatrix() { return&_srt_matrix; }
    void SetParent(XMMATRIX* matrix) { _parentMatrix = matrix; }

    Vector2& GetScale() { return _scale; }

    float& GetAnagle() { return _angle; }

    Vector2 GetWorldPos()
    {
        Vector2 worldPos;
        Float4x4 matrix;
        XMStoreFloat4x4(&matrix, _srt_matrix);
        worldPos.x = matrix._41;
        worldPos.y = matrix._42;
            
    }

    Vector2	m_pos = { 0.0f,0.0f };
    float m_angle;

private:
    Vector2 _scale = { 1,1 };
    float _angle = { 0.0f };
    Vector2 _pos = { 0,0 };

    XMMATRIX _srt_matrix;
    XMMATRIX* _parentMatrix = nullptr;
    shared_ptr<MatrixBuffer> _worldBuffer;

};

