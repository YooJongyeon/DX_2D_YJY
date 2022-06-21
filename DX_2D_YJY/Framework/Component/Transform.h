#pragma once
class Transform
{
public:
    Transform();
    ~Transform();

    void UpdateWorldBuffer();
    void SetWorldBuffer(int slot = 0);

    Vector2& GetPos() { return _pos; }
    void SetPos(Vector2& pos) { _pos = pos; }

    const XMMATRIX& GetMatrix() { return _srtMatrix; }
    void SetParent(shared_ptr<Transform> transform) { _parent = transform; }

    Vector2& GetScale() { return _scale; }

    float& GetAnagle() { return _angle; }

    Vector2 GetWorldPos()
    {
        Vector2 worldPos;
        XMFLOAT4X4 matrix;
        XMStoreFloat4x4(&matrix, _srtMatrix);
        worldPos._x = matrix._41;
        worldPos._y = matrix._42;

        return worldPos;
    }

    Vector2	m_pos = { 0.0f,0.0f };
    float m_angle;

private:
    Vector2 _scale = { 1,1 };
    float _angle = { 0.0f };
    Vector2 _pos = { 0,0 };

    XMMATRIX _srtMatrix;
    shared_ptr<Transform> _parent = nullptr;
    shared_ptr<MatrixBuffer> _worldBuffer;

};

