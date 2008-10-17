// OGLRenderView.hpp
// KlayGE OpenGL渲染视图类 头文件
// Ver 3.3.0
// 版权所有(C) 龚敏敏, 2006
// Homepage: http://klayge.sourceforge.net
//
// 3.3.0
// 初次建立 (2006.5.31)
//
// 修改记录
/////////////////////////////////////////////////////////////////////////////////

#ifndef _OGLRENDERVIEW_HPP
#define _OGLRENDERVIEW_HPP

#include <KlayGE/RenderView.hpp>
#include <KlayGE/Texture.hpp>

#include <KlayGE/OpenGL/OGLTexture.hpp>

namespace KlayGE
{
	class OGLRenderView : public RenderView
	{
	public:
		OGLRenderView();
		virtual ~OGLRenderView();

		void Clear(float depth);
		void Clear(int32_t stencil);
		void Clear(float depth, int32_t stencil);

		GLuint OGLTexture() const
		{
			return tex_;
		}

	protected:
		void DoClear(uint32_t flags, Color const & clr, float depth, int32_t stencil);

	protected:
		GLuint tex_;
		GLuint fbo_;
	};

	typedef boost::shared_ptr<OGLRenderView> OGLRenderViewPtr;


	class OGLScreenColorRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLScreenColorRenderView(uint32_t width, uint32_t height, ElementFormat pf);

		void Clear(Color const & clr);
		void Clear(float depth);
		void Clear(int32_t stencil);
		void Clear(float depth, int32_t stencil);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);
	};

	typedef boost::shared_ptr<OGLScreenColorRenderView> OGLScreenColorRenderViewPtr;


	class OGLScreenDepthStencilRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLScreenDepthStencilRenderView(uint32_t width, uint32_t height, ElementFormat pf);

		void Clear(Color const & clr);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);
	};

	typedef boost::shared_ptr<OGLScreenDepthStencilRenderView> OGLScreenDepthStencilRenderViewPtr;


	class OGLTexture1DRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLTexture1DRenderView(Texture& texture_1d, int level);

		void Clear(Color const & clr);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);

	private:
		OGLTexture1D& texture_1d_;
		int level_;
	};

	typedef boost::shared_ptr<OGLTexture1DRenderView> OGLTexture1DRenderViewPtr;


	class OGLTexture2DRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLTexture2DRenderView(Texture& texture_2d, int level);

		void Clear(Color const & clr);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);

	private:
		OGLTexture2D& texture_2d_;
		int level_;
	};

	typedef boost::shared_ptr<OGLTexture2DRenderView> OGLTexture2DRenderViewPtr;


	class OGLTexture3DRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLTexture3DRenderView(Texture& texture_3d, uint32_t slice, int level);
		~OGLTexture3DRenderView();

		void Clear(Color const & clr);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);

		void OnUnbind(FrameBuffer& fb, uint32_t att);

	private:
		void CopyToSlice(uint32_t att);

	private:
		OGLTexture3D& texture_3d_;
		uint32_t slice_;
		int level_;
		int copy_to_tex_;
		GLuint tex_2d_;
	};

	typedef boost::shared_ptr<OGLTexture3DRenderView> OGLTexture3DRenderViewPtr;


	class OGLTextureCubeRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLTextureCubeRenderView(Texture& texture_cube, Texture::CubeFaces face, int level);

		void Clear(Color const & clr);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);

	private:
		OGLTextureCube& texture_cube_;
		Texture::CubeFaces face_;
		int level_;
	};

	typedef boost::shared_ptr<OGLTexture2DRenderView> OGLTexture2DRenderViewPtr;


	class OGLGraphicsBufferRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLGraphicsBufferRenderView(GraphicsBuffer& gb,
							uint32_t width, uint32_t height, ElementFormat pf);
		~OGLGraphicsBufferRenderView();

		void Clear(Color const & clr);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);

		void OnUnbind(FrameBuffer& fb, uint32_t att);

	private:
		void CopyToGB(uint32_t att);

	private:
		GraphicsBuffer& gbuffer_;
	};

	typedef boost::shared_ptr<OGLGraphicsBufferRenderView> OGLGraphicsBufferRenderViewPtr;


	class OGLDepthStencilRenderView : public OGLRenderView, boost::noncopyable
	{
	public:
		OGLDepthStencilRenderView(uint32_t width, uint32_t height, ElementFormat pf, uint32_t multi_sample);
		~OGLDepthStencilRenderView();

		void Clear(Color const & clr);

		void OnAttached(FrameBuffer& fb, uint32_t att);
		void OnDetached(FrameBuffer& fb, uint32_t att);

	private:
		uint32_t multi_sample_;
		GLuint rbo_;
	};

	typedef boost::shared_ptr<OGLDepthStencilRenderView> OGLDepthStencilRenderViewPtr;
}

#endif			// _OGLRENDERVIEW_HPP
