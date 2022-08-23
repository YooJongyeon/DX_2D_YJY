#pragma once
class Transform
{
public:
    Transform();
    ~Transform();

    void UpdateWorldBuffer();
    void SetMatrixBuffer(int slot = 0);

    Vector2& GetPos() { return _pos; }
    Vector2& GetScale() { return _scale; }
    float& GetAngle() { return _angle; }

    Vector2 GetWorldPos()
    {
        Vector2 worldPos;
        XMFLOAT4X4 matrix;
        XMStoreFloat4x4(&matrix, _srtMatrix);
        worldPos.x = matrix._41;
        worldPos.y = matrix._42;

        return (worldPos);
    }

    Vector2 GetWorldScale()
    {
        if (_parent)
            return Vector2(_scale.x * _parent->GetScale().x, _scale.y * _parent->GetScale().y);
        return _scale;
    }

    const XMMATRIX& GetMatrix() { return _srtMatrix; }

    void SetParent(shared_ptr<Transform> transform) { _parent = transform; }
    shared_ptr<Transform> GetParent() { return _parent; }

private:
    Vector2 _scale = { 1,1 };
    float _angle = { 0.0f };
    Vector2 _pos = { 0,0 };

    XMMATRIX _srtMatrix;
    shared_ptr<Transform> _parent = nullptr;
    shared_ptr<MatrixBuffer> _worldBuffer;

};

