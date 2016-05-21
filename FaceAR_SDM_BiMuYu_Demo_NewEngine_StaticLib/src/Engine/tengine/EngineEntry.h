#pragma once

#include <thread>
#include <string>

namespace tezcat
{

	class EngineEntry
	{
	public:
		EngineEntry();
		~EngineEntry();

		void init(const std::string &res_dir);

		//************************************
		// ������:  render
		// ����ֵ:  void
		// ����:    
		//************************************
		void render();

		//************************************
		// ������:  logic
		// ����ֵ:  void
		// ����:    
		//************************************
		void logic();


	public:
		EngineEntry(const EngineEntry &other) = delete;
		EngineEntry &operator = (const EngineEntry &other) = delete;

	private:
		bool m_EngineClose;

		std::thread m_RenderThread;
		std::thread m_LogicThread;
	};
}