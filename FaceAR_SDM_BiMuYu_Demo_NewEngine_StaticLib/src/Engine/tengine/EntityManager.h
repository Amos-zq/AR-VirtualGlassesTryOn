#pragma once


#include "Entity.h"
#include "xsystem/XSingleton.h"
#include <list>

namespace tezcat
{
	class RenderObject;
	class EntityManager : public XSingleton<EntityManager>
	{
	public:
		EntityManager();
		~EntityManager();

		//************************************
		// ������:  create
		// ����ֵ:  Entity *
		// ������:  Entity * parent
		// ������:  EntityType type
		// ����:    
		//************************************
		Entity *create(Entity *parent);

		//************************************
		// ������:  create
		// ����ֵ:  Entity *
		// ������:  EntityType type
		// ����:    
		//************************************
		Entity *create();

		//************************************
		// ������:  recycle
		// ����ֵ:  void
		// ������:  Entity * entity
		// ����:    
		//************************************
		void recycle(Entity *entity);


		//************************************
		// Method:    createModel
		// FullName:  tezcat::EntityManager::createModel
		// Access:    public 
		// Returns:   tezcat::Entity *
		// Qualifier:
		// Parameter: const std::string & name
		// Parameter: Entity * parent
		//************************************
		Entity *createModel(const std::string &name, Entity *parent = nullptr);

	private:
		std::list<Entity *> m_Entities;
	};
}
