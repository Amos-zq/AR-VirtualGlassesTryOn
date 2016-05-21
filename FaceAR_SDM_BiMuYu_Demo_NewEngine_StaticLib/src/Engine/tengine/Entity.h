#pragma once

#include <cstdint>
#include <functional>
#include <cassert>
#include <unordered_set>
#include <vector>
#include <algorithm>

#include "xsystem/XIDCreator.h"
#include "xsystem/XComponentWapper.h"

#include "RenderObject.h"
#include "Transform.h"

namespace tezcat
{
	class Entity
	{
	public:
		Entity(Entity *parent = nullptr);
		~Entity();

		//
		//��̬���
		//************************************
		// ������:  hasStatic
		// ����ֵ:  bool
		// ����:
		//************************************
		template<typename XCom>
		bool hasStatic()
		{
			return m_StaticComponent.hasComponent<XCom>();
		}

		//************************************
		// ������:  getStatic
		// ����ֵ:  XCom *
		// ����:
		//************************************
		template<typename XCom>
		XCom *getStatic()
		{
			return m_StaticComponent.getComponent<XCom>();
		}

		//************************************
		// ������:  attachStatic
		// ����ֵ:  void
		// ������:  XCom * com
		// ����:
		//************************************
		template<typename XCom>
		void attachStatic(XCom *com)
		{
			m_StaticComponent.attachComponent<XCom>(com);
		}

		//************************************
		// ������:  detachStatic
		// ����ֵ:  void
		// ����:
		//************************************
		template<typename XCom>
		void detachStatic()
		{
			m_StaticComponent.detachComponent<XCom>();
		}

		//
		//��̬���
		//************************************
		// ������:  hasDynamic
		// ����ֵ:  bool
		// ����:
		//************************************
		template<typename XCom>
		bool hasDynamic()
		{
			return m_DynamicComponent.hasComponent<XCom>();
		}

		//************************************
		// ������:  getDynamic
		// ����ֵ:  XCom *
		// ����:
		//************************************
		template<typename XCom>
		XCom *getDynamic()
		{
			return m_DynamicComponent.getComponent<XCom>();
		}

		//************************************
		// ������:  attachDynamic
		// ����ֵ:  void
		// ������:  XCom * com
		// ����:
		//************************************
		template<typename XCom>
		void attachDynamic(XCom *com)
		{
			m_DynamicComponent.attachComponent<XCom>(com);
		}

		//************************************
		// ������:  detachDynamic
		// ����ֵ:  void
		// ����:
		//************************************
		template<typename XCom>
		void detachDynamic()
		{
			m_DynamicComponent.detachComponent<XCom>();
		}


		//************************************
		// ������:  updataDynamicComponent
		// ����ֵ:  void
		// ����:
		//************************************
		void updataDynamicComponent()
		{
// 			auto it = m_DynamicComponent.getLogic()->resetIterator();
// 			while (it->hasNext())
// 			{
// 				if (OnUpdataDynamicComponent)
// 				{
// 					OnUpdataDynamicComponent(it->value());
// 				}
// 				it->value()->logic();
// 				it->next();
// 			}

			auto begin = m_DynamicComponent.getLogic().begin();
			auto end = m_DynamicComponent.getLogic().end();
			while (begin != end)
			{
				(*begin)->logic();
				++begin;
			}
		}

		//************************************
		// ������:  addChild
		// ����ֵ:  void
		// ������:  XEntity * entity
		// ����:
		//************************************
		void addChild(Entity *entity)
		{
			assert(entity->getParent() == nullptr);
			entity->setParent(this);
			entity->getRenderObject()->getTransform()->setParent(this->m_RenderObject->getTransform());
			m_Children.push_back(entity);
		}

		//************************************
		// ������:  removeChild
		// ����ֵ:  void
		// ������:  XEntity * entity
		// ����:
		//************************************
		void removeChild(Entity *entity)
		{
			assert(entity->getParent() == this);
			entity->setParent(nullptr);
			m_Children.erase(std::remove(m_Children.begin(), m_Children.end(), entity));
		}

		//************************************
		// ������:  removeSelf
		// ����ֵ:  void
		// ����:
		//************************************
		void removeSelf() { m_Parent->removeChild(this); }

		std::vector<Entity *> &getChildren() { return m_Children; }

		//************************************
		// ������:  hasChild
		// ����ֵ:  bool
		// ����:
		//************************************
		const bool hasChild() const { return !m_Children.empty(); }

		//************************************
		// ������:  getGlobalID
		// ����ֵ:  size_t &
		// ����:
		//************************************
		const size_t &getGlobalID() { return m_GlobalID; }

		//************************************
		// ������:  getGroupID
		// ����ֵ:  size_t &
		// ����:
		//************************************
		const size_t &getGroupID() { return m_GroupID; }

		//************************************
		// ������:  getIDInGroup
		// ����ֵ:  size_t &
		// ����:
		//************************************
		const size_t &getIDInGroup() { return m_IDInGroup; }

		//************************************
		// ������:  getParent
		// ����ֵ:  tezcat::Entity *
		// ����:
		//************************************
		Entity *getParent() const { return m_Parent; }

		//************************************
		// ������:  setParent
		// ����ֵ:  void
		// ������:  Entity * val
		// ����:
		//************************************
		void setParent(Entity * val) { m_Parent = val; }

		//************************************
		// ������:  buildEntity
		// ����ֵ:  void
		// ����:
		//************************************
		void buildEntity()
		{
// 			auto it = m_DynamicComponent.getLogic()->resetIterator();
// 			while (it->hasNext())
// 			{
// 				it->value()->buildComponent(&m_DynamicComponent, &m_StaticComponent);
// 				it->next();
// 			}
//
// 			it = m_StaticComponent.getLogic()->resetIterator();
// 			while (it->hasNext())
// 			{
// 				it->value()->buildComponent(&m_DynamicComponent, &m_StaticComponent);
// 				it->next();
// 			}

			auto begin = m_DynamicComponent.getLogic().begin();
			auto end = m_DynamicComponent.getLogic().end();
			while (begin != end)
			{
				(*begin)->buildComponent(&m_DynamicComponent, &m_StaticComponent);
				++begin;
			}

			begin = m_StaticComponent.getLogic().begin();
			end = m_StaticComponent.getLogic().end();
			while (begin != end)
			{
				(*begin)->buildComponent(&m_DynamicComponent, &m_StaticComponent);
				++begin;
			}
		}

		void sort(const glm::vec3 &std_value)
		{
// 			std::sort(m_Children.begin(), m_Children.end(), [&](Entity *first, Entity *second)
// 			{
// 				return first->getRenderObject()->getTransform()->getPosition()
// 			});
		}

	public:
		void addStringTag(const std::string &tag)
		{
			m_StringTags.insert(tag);
		}

		void removeStringTag(const std::string &tag)
		{
			m_StringTags.erase(tag);
		}

		bool hasStringTag(const std::string &tag)
		{
			return m_StringTags.find(tag) != m_StringTags.end();
		}

		void setName(const std::string &name)
		{
			m_Name = name;
		}

		void setRenderObject(RenderObject *render_object)
		{
			m_RenderObject = render_object;
		}

		RenderObject *getRenderObject() { return m_RenderObject; }

	private:
		RenderObject *m_RenderObject;

	private:
		XComponentWapper m_DynamicComponent;					//��̬���
		XComponentWapper m_StaticComponent;						//��̬���

		size_t m_GlobalID;										//ȫ��ID
		size_t m_GroupID;										//��ID;
		size_t m_IDInGroup;										//����ID;
		Entity *m_Parent;										//���ڵ�
		std::string m_Name;

		std::vector<Entity *> m_Children;

	private:
		std::unordered_set<std::string> m_StringTags;
	};
}
