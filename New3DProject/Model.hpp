#ifndef MODEL_HPP
#define MODEL_HPP

#include <d3d11.h>
#include <DirectXMath.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace DirectX;
using namespace std;

struct Face
{
	int vIndex1, vIndex2, vIndex3;
	int tIndex1, tIndex2, tIndex3;
	int nIndex1, nIndex2, nIndex3;
};

class Model
{
public:
	Model();
	Model(const Model &);
	~Model();

	bool Initialize(ID3D11Device*);
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	bool loadDataStructures(string fileName, vector<XMFLOAT3> &vertices, vector<XMFLOAT2> &texcoords, vector<XMFLOAT3> &normals, vector<Face> &faces, bool rightHanded = false);

private:
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

	bool InitializeBuffers(ID3D11Device*);
	bool InitializeBuffersNEW(ID3D11Device*);
	void RenderBuffers(ID3D11DeviceContext*);
};

#endif /* MODEL_HPP */