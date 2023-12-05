#include <Application.hpp>

int main(const int argumentCount, const char * const * const argumentList)
{
	auto& app = LangYa::Application::GetInstance();

	app.Initialize();
	app.EventLoop();
	app.Save();
	app.Finalize();

	return 0;
}