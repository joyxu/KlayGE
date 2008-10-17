// OALAudioFactory.cpp
// KlayGE OpenAL音频引擎抽象工厂类 实现文件
// Ver 2.0.3
// 版权所有(C) 龚敏敏, 2003-2004
// Homepage: http://klayge.sourceforge.net
//
// 2.0.3
// 改为template实现 (2004.3.4)
//
// 2.0.0
// 初次建立 (2003.8.15)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#include <KlayGE/KlayGE.hpp>
#include <KlayGE/Util.hpp>
#include <KlayGE/AudioFactory.hpp>

#include <KlayGE/OpenAL/OALAudio.hpp>
#include <KlayGE/OpenAL/OALAudioFactory.hpp>

extern "C"
{
	KlayGE::AudioFactoryPtr const & AudioFactoryInstance()
	{
		static KlayGE::AudioFactoryPtr af = KlayGE::MakeSharedPtr<KlayGE::ConcreteAudioFactory<KlayGE::OALAudioEngine,
			KlayGE::OALSoundBuffer, KlayGE::OALMusicBuffer> >(L"OpenAL Audio Factory");
		return af;
	}

	std::string const & Name()
	{
		static std::string const name("OpenAL");
		return name;
	}
}
