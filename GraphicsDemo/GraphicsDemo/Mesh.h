#pragma once
#ifndef __MESH_H__
#define __MESH_H__

#include "Vertices.h"
#include "Shader.h"
#include "Texture.h"
#include "Physics.h"
#include "Audio.h"
#include "Animation.h"
#include "Camera.h"
#include "Dependencies/glew/include/GL/glew.h"
#include "Dependencies/SDL2/include/SDL.h"

class Mesh
{
public:
	Mesh();
	~Mesh();

	void CreateMesh(Vertex* verts, GLuint numOfVertices, unsigned int* indices, GLuint numOfIndices);
	void Draw(glm::mat4 proj, glm::mat4 view);

	Shader& GetShaderComponent()			{ return shaderComponent; }
	Texture& GetTextureComponent()			{ return m_textureComponent; }
	Audio& GetAudioComponent()				{ return m_audioComponent; }
	Physics& GetPhysicsComponent()			{ return m_physicsComponent; }
	Animation& GetAnimationComponent()		{ return m_animationComponent; }

	void SetTextureId(char* texId);
	char* GetTextureId() const;

private:
	enum { POSITION_VB, COLOR_VB, UV_VB, ELEMENT_VB, TOTAL_BUFFERS };

	char* m_texId;
	GLuint m_numOfVertices, m_numOfIndices;
	GLuint m_vao;
	GLuint m_vbo[TOTAL_BUFFERS];

private:
	glm::mat4 model;

	Shader shaderComponent;
	Texture m_textureComponent;
	Audio m_audioComponent;
	Physics m_physicsComponent;
	Animation m_animationComponent;
};

#endif // !__MESH_H__