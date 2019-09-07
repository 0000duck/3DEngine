#include "engine.h"

Engine::Engine()
{
	shaderProgram = new Shader;
	scene = new Scene;
}

Engine::~Engine()
{
	delete shaderProgram;
	shaderProgram = nullptr;

	delete scene;
	scene = nullptr;
}

void Engine::initEngine()
{
    initializeOpenGLFunctions();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glClearColor(
            scene->background_color[0],
			scene->background_color[1],
			scene->background_color[2],
			scene->background_color[3]);

	shaderProgram->loadShader();
}

void Engine::setScene(Scene &scene)
{
	this->scene = &scene;
}

void Engine::loadObjects()
{
	for(int i = 0; i < scene->objects.size(); ++i)
	{
		scene->objects[i].loadObj();
	}

}

