#include "KMiniEngine.h"

class GrassRenderApp : public KMiniEngine::Application
{
public:
	GrassRenderApp()
	{
	}
	~GrassRenderApp()
	{
	}
};

KMiniEngine::Application* KMiniEngine::CreateApplication()
{
	return new GrassRenderApp();
}

int main()
{
	return RunEngine();
}


