/*
	Copyright (C) 2012 Alexander Overvoorde

	Permission is hereby granted, free of charge, to any person obtaining a copy of
	this software and associated documentation files (the "Software"), to deal in
	the Software without restriction, including without limitation the rights to
	use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
	the Software, and to permit persons to whom the Software is furnished to do so,
	subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
	FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
	COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
	CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
*/

#include <GL/GL/Extensions.hpp>

#if defined( OOGL_PLATFORM_WINDOWS )
	WGLCREATECONTEXTATTRIBSARB wglCreateContextAttribsARB;
	WGLCHOOSEPIXELFORMATARB wglChoosePixelFormatARB;
	WGLSWAPINTERVALEXT wglSwapIntervalEXT;
#elif defined( OOGL_PLATFORM_LINUX )
	GLXCREATECONTEXTATTRIBSARB glXCreateContextAttribsARB;
	GLXSWAPINTERVALSGI glXSwapIntervalSGI;
#endif

GLCOMPILESHADER glCompileShader;
GLCREATESHADER glCreateShader;
GLDELETESHADER glDeleteShader;
GLGETSHADERIV glGetShaderiv;
GLGETSHADERINFOLOG glGetShaderInfoLog;
GLSHADERSOURCE glShaderSource;

GLCREATEPROGRAM glCreateProgram;
GLDELETEPROGRAM glDeleteProgram;
GLATTACHSHADER glAttachShader;
GLLINKPROGRAM glLinkProgram;
GLGETPROGRAMIV glGetProgramiv;
GLGETPROGRAMINFOLOG glGetProgramInfoLog;

GLGENBUFFERS glGenBuffers;
GLDELETEBUFFERS glDeleteBuffers;
GLBINDBUFFER glBindBuffer;
GLBUFFERDATA glBufferData;
GLBUFFERSUBDATA glBufferSubData;

namespace GL
{
	bool extensionsLoaded = false;

	inline void* LoadExtension( const char* name )
	{
#if defined( OOGL_PLATFORM_WINDOWS )
		return wglGetProcAddress( name );
#elif defined( OOGL_PLATFORM_LINUX )
		return (void*)glXGetProcAddress( (const GLubyte*)name );
#endif
	}

	void LoadExtensions()
	{
		if ( extensionsLoaded ) return;
		extensionsLoaded = true;

#if defined( OOGL_PLATFORM_WINDOWS )
		wglCreateContextAttribsARB = (WGLCREATECONTEXTATTRIBSARB)LoadExtension( "wglCreateContextAttribsARB" );
		wglChoosePixelFormatARB = (WGLCHOOSEPIXELFORMATARB)LoadExtension( "wglChoosePixelFormatARB" );
		wglSwapIntervalEXT = (WGLSWAPINTERVALEXT)LoadExtension( "wglSwapIntervalEXT" );
#elif defined( OOGL_PLATFORM_LINUX )
		glXCreateContextAttribsARB = (GLXCREATECONTEXTATTRIBSARB)LoadExtension( "glXCreateContextAttribsARB" );
		glXSwapIntervalSGI = (GLXSWAPINTERVALSGI)LoadExtension( "glXSwapIntervalSGI" );
#endif

		glCompileShader = (GLCOMPILESHADER)LoadExtension( "glCompileShader" );
		glCreateShader = (GLCREATESHADER)LoadExtension( "glCreateShader" );
		glDeleteShader = (GLDELETESHADER)LoadExtension( "glDeleteShader" );
		glGetShaderiv = (GLGETSHADERIV)LoadExtension( "glGetShaderiv" );
		glGetShaderInfoLog = (GLGETSHADERINFOLOG)LoadExtension( "glGetShaderInfoLog" );
		glShaderSource = (GLSHADERSOURCE)LoadExtension( "glShaderSource" );

		glCreateProgram = (GLCREATEPROGRAM)LoadExtension( "glCreateProgram" );
		glDeleteProgram = (GLDELETEPROGRAM)LoadExtension( "glDeleteProgram" );
		glAttachShader = (GLATTACHSHADER)LoadExtension( "glAttachShader" );
		glLinkProgram = (GLLINKPROGRAM)LoadExtension( "glLinkProgram" );
		glGetProgramiv = (GLGETPROGRAMIV)LoadExtension( "glGetProgramiv" );
		glGetProgramInfoLog = (GLGETPROGRAMINFOLOG)LoadExtension( "glGetProgramInfoLog" );

		glGenBuffers = (GLGENBUFFERS)LoadExtension( "glGenBuffers" );
		glDeleteBuffers = (GLDELETEBUFFERS)LoadExtension( "glDeleteBuffers" );
		glBindBuffer = (GLBINDBUFFER)LoadExtension( "glBindBuffer" );
		glBufferData = (GLBUFFERDATA)LoadExtension( "glBufferData" );
		glBufferSubData = (GLBUFFERSUBDATA)LoadExtension( "glBufferSubData" );
	}
}