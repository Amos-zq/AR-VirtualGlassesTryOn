#pragma once


namespace tezcat
{
	class GlobalConfig
	{
	public:
		static void aspect()
		{
			Aspect = static_cast<float>(ScreenWidth) / static_cast<float>(ScreenHeight);
		}

		static unsigned int ScreenWidth;		//��Ļ��
		static unsigned int ScreenHeight;		//��Ļ��
		static float Aspect;					//����


		static float MainCameraFOV;				//�ӽǶ���
		static float MainCameraNear;			//��ƽ��
		static float MainCameraFar;				//Զƽ��
	};
}
