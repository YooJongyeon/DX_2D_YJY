#pragma once
class Transform
{
public:
    Transform();
    ~Transform();

    void UpdateWorldBuffer();
    void SetWorldBuffer(int slot = 0);

    XMFLOAT2& GetPos() { return _pos; }

    XMMATRIX* GetMatrix() { return&_srt_matrix; }
    void SetParent(XMMATRIX* matrix) { _parentMatrix = matrix; }

    XMFLOAT2& GetScale() { return _scale; }

    float& GetAnagle() { return _angle; }

    

private:
    XMFLOAT2 _scale = { 1,1 };
    float _angle = { 0.0f };
    XMFLOAT2 _pos = { 0,0 };

    XMMATRIX _srt_matrix;
    XMMATRIX* _parentMatrix = nullptr;
    shared_ptr<MatrixBuffer> _worldBuffer;

};

