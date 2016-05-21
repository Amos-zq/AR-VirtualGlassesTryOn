#pragma once

#include <string>
#include <vector>
#include <functional>

namespace tezcat
{
	class Entity;
	class ModelManager;
	class Camera;
	class Entity;
	class Scene
	{
	public:
		Scene(const std::string &name);
		Scene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);
		~Scene();

		//************************************
		// ������:  addChild
		// ����ֵ:  void
		// ������:  Entity * entity
		// ����:    
		//************************************
		void addChild(Entity *entity);

		//************************************
		// ������:  getName
		// ����ֵ:  const std::string &
		// ����:    
		//************************************
		const std::string &getName() const { return m_Name; }

		//************************************
		// ������:  logic
		// ����ֵ:  void
		// ����:    
		//************************************
		void logic();

		//************************************
		// ������:  onBuild
		// ����ֵ:  void
		// ����:    
		//************************************
		void onBuild();

		//************************************
		// ������:  onDestroy
		// ����ֵ:  void
		// ����:    
		//************************************
		void onDestroy();

		//************************************
		// ������:  onPush
		// ����ֵ:  void
		// ����:    
		//************************************
		void onPush();

		//************************************
		// ������:  onPop
		// ����ֵ:  void
		// ����:    
		//************************************
		void onPop();

		//************************************
		// Method:    getCameras
		// FullName:  tezcat::Scene::getCameras
		// Access:    public 
		// Returns:   std::vector<Camera *> &
		// Qualifier:
		//************************************
		std::vector<Camera *> &getCameras() { return m_Cameras; }

	private:
		std::function<void(Scene *)> OnBuild;
		std::function<void(Scene *)> OnDestroy;
		std::function<void(Scene *)> OnPush;
		std::function<void(Scene *)> OnPop;

	private:
		friend class SceneSystem;
		std::string m_Name;
		Entity *m_TheWorld;
		std::vector<Camera *> m_Cameras;
		std::vector<std::pair<std::vector<Entity *>::iterator, std::vector<Entity *>::iterator>> m_EntityStack;
		std::vector<Entity *>::iterator m_CurrentIt, m_CurrentEnd;
	};
}