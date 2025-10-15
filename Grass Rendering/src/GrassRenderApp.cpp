#include <KMiniEngine.h>

class GrassRenderApp : public KMiniEngine::Application
{

}

KMiniEngine::Application* CreateApplication()
{
	return new GrassRenderApp();
}



