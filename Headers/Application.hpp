#pragma once

namespace LangYa {
	class Application {
		static Application* Instance{nullptr};

	public:
		Application() = delete;

		static Application& GetInstance() {
			// TODO Construction

			return *Instance;
		}

		bool Initialize()
		{
		}

		void EventLoop() {
		}

		void Save() {
		}

		bool Finalize() {
		}
	};
}