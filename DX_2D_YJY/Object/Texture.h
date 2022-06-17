#pragma once
class Texture
{
public:
    Texture(wstring file);
    ~Texture();

    void Update();
    void Render();

    shared_ptr<Transform> GetTransform() { return _transform; }


private:
    void CreateVertices();
    
    shared_ptr<Transform> _transform;

    float _angle = { 0.0f };
    shared_ptr<MatrixBuffer> _viewBuffer;
    XMFLOAT2 _cameraPos = { 0,0 };

    vector<VertexUV> _vertices;
    vector<UINT> _indicies;

    shared_ptr<VertexShader>    _vertexShader;
    shared_ptr<PixelShader>     _pixelShader;

    shared_ptr<VertexBuffer>    _vertexBuffer;
    shared_ptr<IndexBuffer>     _indexBuffer;
    shared_ptr<SRV>             _srv;
  

};

