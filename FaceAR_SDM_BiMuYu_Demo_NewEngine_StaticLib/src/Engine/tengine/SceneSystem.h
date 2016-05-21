#pragma once

#include "xsystem/XSingleton.h"
#include "Scene.h"
#include <vector>
#include <string>
#include <functional>

namespace tezcat
{
	class SceneSystem : public XSingleton<SceneSystem>
	{
	public:
		SceneSystem();
		~SceneSystem();

		//************************************
		// ������:  createScene
		// ����ֵ:  Scene *
		// ������:  const std::string & name
		// ������:  const std::function<void Scene *> & onbuild
		// ������:  const std::function<void Scene *> & ondestroy
		// ������:  const std::function<void Scene *> & onpush
		// ������:  const std::function<void Scene *> & onpop
		// ����:    
		//************************************
		Scene *createScene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);

		//************************************
		// ������:  replaceScene
		// ����ֵ:  Scene *
		// ������:  const std::string & name
		// ������:  const std::function<void Scene *> & onbuild
		// ������:  const std::function<void Scene *> & ondestroy
		// ������:  const std::function<void Scene *> & onpush
		// ������:  const std::function<void Scene *> & onpop
		// ����:    
		//************************************
		Scene *replaceScene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);

		//************************************
		// ������:  popScene
		// ����ֵ:  Scene *
		// ����:    
		//************************************
		Scene *popScene();

		//************************************
		// ������:  pushScene
		// ����ֵ:  Scene *
		// ������:  const std::string & name
		// ������:  const std::function<void Scene *> & onbuild
		// ������:  const std::function<void Scene *> & ondestroy
		// ������:  const std::function<void Scene *> & onpush
		// ������:  const std::function<void Scene *> & onpop
		// ����:    
		//************************************
		Scene *pushScene(
			const std::string &name,
			const std::function<void(Scene *)> &onbuild,
			const std::function<void(Scene *)> &ondestroy,
			const std::function<void(Scene *)> &onpush,
			const std::function<void(Scene *)> &onpop);

		//************************************
		// ������:  logic
		// ����ֵ:  void
		// ����:    
		//************************************
		void logic();

	private:
		Scene *m_CurrentScene;
		std::vector<Scene *> m_Scenes;
	};
}