#pragma once

#include "xsystem/XSingleton.h"
#include "EntityManager.h"
#include <string>



namespace tezcat
{	
	class Entity;
	class MeshManager;
	class ImageManager;
	class ShaderManager;
	class GLTextureManager;
	class GLTextureCube;
	class GLTexture2D;
	class Program;
	class MaterialManager;
	class UniversalMaterial;
	class ResourceSystem : public XSingleton<ResourceSystem>
	{
	public:
		ResourceSystem();
		~ResourceSystem();

		//************************************
		// ������:  loadConfiguration
		// ����ֵ:  void
		// ������:  const std::string & root_path
		// ������:  const std::string & relative_path
		// ����:    
		//************************************
		void loadConfiguration(const std::string &root_path, const std::string &relative_path);

		//************************************
		// ������:  getResRootPath
		// ����ֵ:  std::string
		// ����:    
		//************************************
		std::string getResRootPath() const { return m_ResRootPath; }

		//==================================================================
		//
		//	Model
		//
	public:
		//************************************
		// ������:	createModel
		// ȫ��:		tezcat::ResourceSystem::createModel
		// Ȩ��:		public 
		// ����ֵ:   tezcat::Entity *
		// �޶���:	
		// ����:		const std::string & name
		// ����:		const int & pass_id
		// ����:		
		//************************************
		Entity *createModel(const std::string &name, const int &pass_id);

		//************************************
		// ������:	createModelFromPackage
		// ȫ��:		tezcat::ResourceSystem::createModelFromPackage
		// Ȩ��:		public 
		// ����ֵ:   tezcat::Entity *
		// �޶���:	
		// ����:		const std::string & pack_name
		// ����:		
		//************************************
		Entity *createModelFromPackage(const std::string &pack_name);

		//************************************
		// ������:  createSkyBox
		// ����ֵ:  tezcat::Entity *
		// ������:  const std::string & name
		// ����:    
		//************************************
		Entity *createSkyBox();

		//************************************
		// ������:  createCamera
		// ����ֵ:  tezcat::Entity * 
		// ������:  const std::string & name
		// ����:    
		//************************************
		Entity *createCamera(const std::string &name);

		//======================================================
		//
		//	Texture
		//
	public:
		GLTexture2D *createTexture2D(const std::string &file);

		//************************************
		// Method:    createCubeTexture
		// FullName:  tezcat::ResourceSystem::createCubeTexture
		// Access:    public 
		// Returns:   tezcat::GLTextureCube *
		// Qualifier:
		// Parameter: const std::string & name
		// Parameter: const std::string & positive_x
		// Parameter: const std::string & negative_x
		// Parameter: const std::string & positive_y
		// Parameter: const std::string & negative_y
		// Parameter: const std::string & positive_z
		// Parameter: const std::string & negative_z
		//************************************
		GLTextureCube *createCubeMap(
			const std::string &name,
			const std::string &positive_x, const std::string &negative_x,
			const std::string &positive_y, const std::string &negative_y,
			const std::string &positive_z, const std::string &negative_z);

		//************************************
		// Method:    createCubeTexture
		// FullName:  tezcat::ResourceSystem::createCubeTexture
		// Access:    public 
		// Returns:   tezcat::GLTextureCube *
		// Qualifier:
		// Parameter: const std::string & cubemap_name
		//************************************
		GLTextureCube *createCubeMapFromPackage(const std::string &cubemap_name);

		//************************************
		// Method:    createTexture2D
		// FullName:  tezcat::ResourceSystem::createTexture2D
		// Access:    public 
		// Returns:   tezcat::GLTexture2D *
		// Qualifier:
		// Parameter: const std::string & name
		//************************************
		GLTexture2D *createTexture2DFromPackage(const std::string &pack_dot_name);

		//========================================================
		//
		//	Shader
		//
	public:
		Program *createProgram(
			const std::string &name,
			const int &queue_id,
			const std::string &vs,
			const std::string &fs,
			const std::string &gs = "",
			const std::string &tcs = "",
			const std::string &tes = "");

		//************************************
		// ������:	createProgramFromPackage
		// ȫ��:		tezcat::ResourceSystem::createProgramFromPackage
		// Ȩ��:		public 
		// ����ֵ:   tezcat::Program *
		// �޶���:	
		// ����:		const std::string & pack_name
		// ����:		
		//************************************
		Program *createProgramFromPackage(const std::string &pack_name);

		//************************************
		// ������:	confirmShaderIsLoaded
		// ȫ��:		tezcat::ResourceSystem::confirmShaderIsLoaded
		// Ȩ��:		public 
		// ����ֵ:   bool
		// �޶���:	
		// ����:		const std::string & pack_name
		// ����:		
		//************************************
		bool confirmShaderIsLoaded(const std::string &pack_name);

		//======================================================
		//
		//	Material
		//
	public:

		//************************************
		// ������:	createUniversalMaterialFromPackage
		// ȫ��:		tezcat::ResourceSystem::createUniversalMaterialFromPackage
		// Ȩ��:		public 
		// ����ֵ:   tezcat::UniversalMaterial *
		// �޶���:	
		// ����:		const std::string & pack_name
		// ����:		
		//************************************
		UniversalMaterial *createUniversalMaterialFromPackage(const std::string &pack_name);

		//************************************
		// ������:	createUniversalMaterialGroupFromPackage
		// ȫ��:		tezcat::ResourceSystem::createUniversalMaterialGroupFromPackage
		// Ȩ��:		public 
		// ����ֵ:   std::unordered_map<std::string, UniversalMaterial *> *
		// �޶���:	
		// ����:		const std::string & pack_name
		// ����:		
		//************************************
		std::unordered_map<std::string, UniversalMaterial *> *createUniversalMaterialGroupFromPackage(const std::string &pack_name);

		//************************************
		// ������:	getMaterialManager
		// ȫ��:		tezcat::ResourceSystem::getMaterialManager
		// Ȩ��:		public 
		// ����ֵ:   tezcat::MaterialManager *
		// �޶���:	
		// ����:		
		//************************************
		MaterialManager *getMaterialManager() { return m_MaterialManager; }

	private:

		//************************************
		// ������:	loadTextureFromPackage
		// ȫ��:		tezcat::ResourceSystem::loadTextureFromPackage
		// Ȩ��:		private 
		// ����ֵ:   void
		// �޶���:	
		// ����:		const std::string & pack_file
		// ����:		
		//************************************
		void loadTextureFromPackage(const std::string &pack_file);

		//************************************
		// ������:	loadMaterialFromPackage
		// ȫ��:		tezcat::ResourceSystem::loadMaterialFromPackage
		// Ȩ��:		private 
		// ����ֵ:   void
		// �޶���:	
		// ����:		const std::string & pack_file
		// ����:		
		//************************************
		void loadMaterialFromPackage(const std::string &pack_file);

		//************************************
		// ������:	loadModelFromPackage
		// ȫ��:		tezcat::ResourceSystem::loadModelFromPackage
		// Ȩ��:		private 
		// ����ֵ:   void
		// �޶���:	
		// ����:		const std::string & pack_name
		// ����:		
		//************************************
		void loadModelFromPackage(const std::string &pack_file);

		//************************************
		// ������:	loadShaderFromPackage
		// ȫ��:		tezcat::ResourceSystem::loadShaderFromPackage
		// Ȩ��:		private 
		// ����ֵ:   void
		// �޶���:	
		// ����:		const std::string & pack_file
		// ����:		
		//************************************
		void loadShaderFromPackage(const std::string &pack_file);

	private:
		MeshManager *m_MeshManager;
		ImageManager *m_ImageManager;
		ShaderManager *m_ShaderManager;
		GLTextureManager *m_GLTextureManager;
		MaterialManager *m_MaterialManager;

		//��Դ��·��
		std::string m_ResRootPath;
	};
}