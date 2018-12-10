#pragma once

class ShaderCube : public IDisplayObject
{
	typedef VERTEX_PNT VertexType;
private:
	
	vector<VertexType> vertices;

public:
	ShaderCube();
	~ShaderCube();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Render(IShader* pShader) override;
	virtual void Draw() override;
	
};