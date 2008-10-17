// Viewport.hpp
// KlayGE 渲染视口类 头文件
// Ver 3.0.0
// 版权所有(C) 龚敏敏, 2003-2005
// Homepage: http://klayge.sourceforge.net
//
// 3.0.0
// camera改为指针 (2005.8.18)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#ifndef _VIEWPORT_HPP
#define _VIEWPORT_HPP

#ifndef KLAYGE_CORE_SOURCE
#define KLAYGE_LIB_NAME KlayGE_Core
#include <KlayGE/config/auto_link.hpp>
#endif

#include <KlayGE/PreDeclare.hpp>
#include <KlayGE/Util.hpp>
#include <KlayGE/Camera.hpp>

namespace KlayGE
{
	struct KLAYGE_CORE_API Viewport
	{
		Viewport()
			: camera(MakeSharedPtr<Camera>())
		{
		}
		Viewport(int _left, int _top, int _width, int _height)
			: left(_left), top(_top),
				width(_width), height(_height),
				camera(MakeSharedPtr<Camera>())
		{
		}

		int left;
		int top;
		int width;
		int height;

		CameraPtr camera;
	};
}

#endif			// _VIEWPORT_HPP
