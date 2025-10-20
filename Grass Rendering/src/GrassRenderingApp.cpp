#include "KMiniEngine.h"


class GrassRenderApp : public Application
{
public:
	GrassRenderApp()
	{
	}
	~GrassRenderApp()
	{
	}

	void Run() override
	{
		while (true)
		{
		}
	}
};

Application* CreateApplication()
{
	return new GrassRenderApp();
}

int main()
{
	return RunEngine();
}


