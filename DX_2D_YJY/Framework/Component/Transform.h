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
    shared_ptr<Transform> GetPatent() { return _parent; }

    Vector2& GetScale() { return _scale; }

    float& GetHp() { return _hp; }
    float& GetAnagle() { return _angle; }

   const Vector2& GetWorldPos()
    {
        Vector2 worldPos;
        XMFLOAT4X4 matrix;
        XMStoreFloat4x4(&matrix, _srtMatrix);
        worldPos._x = matrix._41;
        worldPos._y = matrix._42;

        return worldPos;
    }

   const Vector2& GetWorldScale()
   {
       if (_parent)
       {
           return Vector2(_scale._x * _parent->GetScale()._x, _scale._y * _parent->GetScale()._y);
           
       }
       return _scale;
   }




    Vector2	m_pos = { 0.0f,0.0f };
    float m_angle;

private:
    Vector2 _scale = { 1,1 };
    float _angle = { 0.0f };
    Vector2 _pos = { 0,0 };
    float _hp = { 0.0f };

    XMMATRIX _srtMatrix;
    shared_ptr<Transform> _parent = nullptr;
    shared_ptr<MatrixBuffer> _worldBuffer;

};

