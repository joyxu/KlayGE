// Show.hpp
// KlayGE 播放引擎类 头文件
// Ver 2.0.0
// 版权所有(C) 龚敏敏, 2003
// Homepage: http://klayge.sourceforge.net
//
// 2.0.0
// 初次建立 (2003.9.3)
//
// 修改记录
/////////////////////////////////////////////////////////////////////

#ifndef _SHOW_HPP
#define _SHOW_HPP

#ifndef KLAYGE_CORE_SOURCE
#define KLAYGE_LIB_NAME KlayGE_Core
#include <KlayGE/config/auto_link.hpp>
#endif

#include <KlayGE/PreDeclare.hpp>

#include <string>

namespace KlayGE
{
	enum ShowState
	{
		SS_Unkown,
		SS_Uninit,
		SS_Stopped,
		SS_Paused,
		SS_Playing,
	};

	class KLAYGE_CORE_API ShowEngine
	{
	public:
		virtual ~ShowEngine();

		static ShowEnginePtr NullObject();

		bool CanPlay() const;
		bool CanStop() const;
		bool CanPause() const;
		bool IsInitialized() const;

		virtual bool IsComplete() = 0;

		virtual void Load(std::string const & fileName) = 0;
		virtual TexturePtr PresentTexture() = 0;

		void Play();
		void Stop();
		void Pause();

		virtual ShowState State(long timeout = -1) = 0;

	protected:
		ShowState	state_;

		virtual void DoPlay() = 0;
		virtual void DoStop() = 0;
		virtual void DoPause() = 0;
	};
}

#endif		// _SHOW_HPP
