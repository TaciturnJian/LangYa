#pragma once

#include <LangYa/SentryLib/Sensor.hpp>

namespace LangYa {
	class AutoAimModule {
	public:
		void SetCamera();
		void SetMLModel();
		void SetEmbeddingSoftwareSensor();
		void SetFilter();
		void SetTracker();
		void GetTarget();
	};
}