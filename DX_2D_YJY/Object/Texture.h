#pragma once
class Texture
{
public:
    Texture(wstring file);
    ~Texture();

    void Update();
    void Render();

    XMFLOAT2& GetPos() { return _pos; }

    XMMATRIX* GetMatrix() { return& _srt_matrix; }
    void SetParent(XMMATRIX* matrix) { _parentMatrix = matrix; }

    XMFLOAT2& GetScale() { return _scale; }

    float& GetAnagle() { return _angle; }



private:
    void CreateVertices();
    

    XMFLOAT2 _scale = { 1,1 };
    float _angle = { 0.0f };
    XMFLOAT2 _pos = { 0,0 };

    XMMATRIX _srt_matrix;
    XMMATRIX* _parentMatrix = nullptr;
    shared_ptr<MatrixBuffer> _worldBuffer;

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

