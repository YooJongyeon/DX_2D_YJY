#pragma once
class Quad
{
public:

    Quad(wstring file, wstring vs = L"Shaders/TextureVertexShader.hlsl", wstring ps = L"Shaders/TexturePixelShader.hlsl");
    ~Quad();

    virtual void Update();
    virtual void Render();

    virtual void CreateData();

    shared_ptr<Transform> GetTransform() { return _transform; }
    void SetParent(shared_ptr<Transform> parent) { _transform->SetParent(parent); }
    const Vector2& GetHalfSize() { return _halfSize; }

    

protected:
    Quad() {}

    shared_ptr<Transform> _transform;

    // Texture
    shared_ptr<Texture> _texture;

    // Mesh
    vector<VertexUV> _vertices;
    vector<UINT> _indicies;
    shared_ptr<VertexBuffer>    _vertexBuffer;
    shared_ptr<IndexBuffer>     _indexBuffer;

    // Material
    shared_ptr<VertexShader>    _vertexShader;
    shared_ptr<PixelShader>     _pixelShader;

    Vector2 _halfSize = { 1,1 };

};

