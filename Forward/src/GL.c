
#include "GL.h"

static BOOL GLLoaded = FALSE;

static HMODULE GLModule = NULL;

typedef void (*GLproc)(void);

static inline GLproc LoadGLProc(const char* Name)
{
	GLproc Proc = (GLproc)GetProcAddress(GLModule, Name);

	if (Proc == NULL)
	{
		Proc = (GLproc)wglGetProcAddress(Name);
	}

	return Proc;
}

int LoadGL()
{
	int Error = ERROR_SUCCESS;

	if (GLLoaded)
	{
		goto Exit;
	}

	GLModule = LoadLibrary(TEXT("opengl32.dll"));

	__glActiveShaderProgram =
		(PFNGLACTIVESHADERPROGRAMPROC)LoadGLProc("glActiveShaderProgram");
	__glActiveTexture =
		(PFNGLACTIVETEXTUREPROC)LoadGLProc("glActiveTexture");
	__glAttachShader =
		(PFNGLATTACHSHADERPROC)LoadGLProc("glAttachShader");
	__glBeginConditionalRender =
		(PFNGLBEGINCONDITIONALRENDERPROC)LoadGLProc("glBeginConditionalRender");
	__glBeginQuery =
		(PFNGLBEGINQUERYPROC)LoadGLProc("glBeginQuery");
	__glBeginQueryIndexed =
		(PFNGLBEGINQUERYINDEXEDPROC)LoadGLProc("glBeginQueryIndexed");
	__glBeginTransformFeedback =
		(PFNGLBEGINTRANSFORMFEEDBACKPROC)LoadGLProc("glBeginTransformFeedback");
	__glBindAttribLocation =
		(PFNGLBINDATTRIBLOCATIONPROC)LoadGLProc("glBindAttribLocation");
	__glBindBuffer =
		(PFNGLBINDBUFFERPROC)LoadGLProc("glBindBuffer");
	__glBindBufferBase =
		(PFNGLBINDBUFFERBASEPROC)LoadGLProc("glBindBufferBase");
	__glBindBufferRange =
		(PFNGLBINDBUFFERRANGEPROC)LoadGLProc("glBindBufferRange");
	__glBindBuffersBase =
		(PFNGLBINDBUFFERSBASEPROC)LoadGLProc("glBindBuffersBase");
	__glBindBuffersRange =
		(PFNGLBINDBUFFERSRANGEPROC)LoadGLProc("glBindBuffersRange");
	__glBindFragDataLocation =
		(PFNGLBINDFRAGDATALOCATIONPROC)LoadGLProc("glBindFragDataLocation");
	__glBindFragDataLocationIndexed =
		(PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)LoadGLProc("glBindFragDataLocationIndexed");
	__glBindFramebuffer =
		(PFNGLBINDFRAMEBUFFERPROC)LoadGLProc("glBindFramebuffer");
	__glBindImageTexture =
		(PFNGLBINDIMAGETEXTUREPROC)LoadGLProc("glBindImageTexture");
	__glBindImageTextures =
		(PFNGLBINDIMAGETEXTURESPROC)LoadGLProc("glBindImageTextures");
	__glBindProgramPipeline =
		(PFNGLBINDPROGRAMPIPELINEPROC)LoadGLProc("glBindProgramPipeline");
	__glBindRenderbuffer =
		(PFNGLBINDRENDERBUFFERPROC)LoadGLProc("glBindRenderbuffer");
	__glBindSampler =
		(PFNGLBINDSAMPLERPROC)LoadGLProc("glBindSampler");
	__glBindSamplers =
		(PFNGLBINDSAMPLERSPROC)LoadGLProc("glBindSamplers");
	__glBindTexture =
		(PFNGLBINDTEXTUREPROC)LoadGLProc("glBindTexture");
	__glBindTextureUnit =
		(PFNGLBINDTEXTUREUNITPROC)LoadGLProc("glBindTextureUnit");
	__glBindTextures =
		(PFNGLBINDTEXTURESPROC)LoadGLProc("glBindTextures");
	__glBindTransformFeedback =
		(PFNGLBINDTRANSFORMFEEDBACKPROC)LoadGLProc("glBindTransformFeedback");
	__glBindVertexArray =
		(PFNGLBINDVERTEXARRAYPROC)LoadGLProc("glBindVertexArray");
	__glBindVertexBuffer =
		(PFNGLBINDVERTEXBUFFERPROC)LoadGLProc("glBindVertexBuffer");
	__glBindVertexBuffers =
		(PFNGLBINDVERTEXBUFFERSPROC)LoadGLProc("glBindVertexBuffers");
	__glBlendColor =
		(PFNGLBLENDCOLORPROC)LoadGLProc("glBlendColor");
	__glBlendEquation =
		(PFNGLBLENDEQUATIONPROC)LoadGLProc("glBlendEquation");
	__glBlendEquationSeparate =
		(PFNGLBLENDEQUATIONSEPARATEPROC)LoadGLProc("glBlendEquationSeparate");
	__glBlendEquationSeparatei =
		(PFNGLBLENDEQUATIONSEPARATEIPROC)LoadGLProc("glBlendEquationSeparatei");
	__glBlendEquationi =
		(PFNGLBLENDEQUATIONIPROC)LoadGLProc("glBlendEquationi");
	__glBlendFunc =
		(PFNGLBLENDFUNCPROC)LoadGLProc("glBlendFunc");
	__glBlendFuncSeparate =
		(PFNGLBLENDFUNCSEPARATEPROC)LoadGLProc("glBlendFuncSeparate");
	__glBlendFuncSeparatei =
		(PFNGLBLENDFUNCSEPARATEIPROC)LoadGLProc("glBlendFuncSeparatei");
	__glBlendFunci =
		(PFNGLBLENDFUNCIPROC)LoadGLProc("glBlendFunci");
	__glBlitFramebuffer =
		(PFNGLBLITFRAMEBUFFERPROC)LoadGLProc("glBlitFramebuffer");
	__glBlitNamedFramebuffer =
		(PFNGLBLITNAMEDFRAMEBUFFERPROC)LoadGLProc("glBlitNamedFramebuffer");
	__glBufferData =
		(PFNGLBUFFERDATAPROC)LoadGLProc("glBufferData");
	__glBufferStorage =
		(PFNGLBUFFERSTORAGEPROC)LoadGLProc("glBufferStorage");
	__glBufferSubData =
		(PFNGLBUFFERSUBDATAPROC)LoadGLProc("glBufferSubData");
	__glCheckFramebufferStatus =
		(PFNGLCHECKFRAMEBUFFERSTATUSPROC)LoadGLProc("glCheckFramebufferStatus");
	__glCheckNamedFramebufferStatus =
		(PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)LoadGLProc("glCheckNamedFramebufferStatus");
	__glClampColor =
		(PFNGLCLAMPCOLORPROC)LoadGLProc("glClampColor");
	__glClear =
		(PFNGLCLEARPROC)LoadGLProc("glClear");
	__glClearBufferData =
		(PFNGLCLEARBUFFERDATAPROC)LoadGLProc("glClearBufferData");
	__glClearBufferSubData =
		(PFNGLCLEARBUFFERSUBDATAPROC)LoadGLProc("glClearBufferSubData");
	__glClearBufferfi =
		(PFNGLCLEARBUFFERFIPROC)LoadGLProc("glClearBufferfi");
	__glClearBufferfv =
		(PFNGLCLEARBUFFERFVPROC)LoadGLProc("glClearBufferfv");
	__glClearBufferiv =
		(PFNGLCLEARBUFFERIVPROC)LoadGLProc("glClearBufferiv");
	__glClearBufferuiv =
		(PFNGLCLEARBUFFERUIVPROC)LoadGLProc("glClearBufferuiv");
	__glClearColor =
		(PFNGLCLEARCOLORPROC)LoadGLProc("glClearColor");
	__glClearDepth =
		(PFNGLCLEARDEPTHPROC)LoadGLProc("glClearDepth");
	__glClearDepthf =
		(PFNGLCLEARDEPTHFPROC)LoadGLProc("glClearDepthf");
	__glClearNamedBufferData =
		(PFNGLCLEARNAMEDBUFFERDATAPROC)LoadGLProc("glClearNamedBufferData");
	__glClearNamedBufferSubData =
		(PFNGLCLEARNAMEDBUFFERSUBDATAPROC)LoadGLProc("glClearNamedBufferSubData");
	__glClearNamedFramebufferfi =
		(PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)LoadGLProc("glClearNamedFramebufferfi");
	__glClearNamedFramebufferfv =
		(PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)LoadGLProc("glClearNamedFramebufferfv");
	__glClearNamedFramebufferiv =
		(PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)LoadGLProc("glClearNamedFramebufferiv");
	__glClearNamedFramebufferuiv =
		(PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)LoadGLProc("glClearNamedFramebufferuiv");
	__glClearStencil =
		(PFNGLCLEARSTENCILPROC)LoadGLProc("glClearStencil");
	__glClearTexImage =
		(PFNGLCLEARTEXIMAGEPROC)LoadGLProc("glClearTexImage");
	__glClearTexSubImage =
		(PFNGLCLEARTEXSUBIMAGEPROC)LoadGLProc("glClearTexSubImage");
	__glClientWaitSync =
		(PFNGLCLIENTWAITSYNCPROC)LoadGLProc("glClientWaitSync");
	__glClipControl =
		(PFNGLCLIPCONTROLPROC)LoadGLProc("glClipControl");
	__glColorMask =
		(PFNGLCOLORMASKPROC)LoadGLProc("glColorMask");
	__glColorMaski =
		(PFNGLCOLORMASKIPROC)LoadGLProc("glColorMaski");
	__glCompileShader =
		(PFNGLCOMPILESHADERPROC)LoadGLProc("glCompileShader");
	__glCompressedTexImage1D =
		(PFNGLCOMPRESSEDTEXIMAGE1DPROC)LoadGLProc("glCompressedTexImage1D");
	__glCompressedTexImage2D =
		(PFNGLCOMPRESSEDTEXIMAGE2DPROC)LoadGLProc("glCompressedTexImage2D");
	__glCompressedTexImage3D =
		(PFNGLCOMPRESSEDTEXIMAGE3DPROC)LoadGLProc("glCompressedTexImage3D");
	__glCompressedTexSubImage1D =
		(PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)LoadGLProc("glCompressedTexSubImage1D");
	__glCompressedTexSubImage2D =
		(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)LoadGLProc("glCompressedTexSubImage2D");
	__glCompressedTexSubImage3D =
		(PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)LoadGLProc("glCompressedTexSubImage3D");
	__glCompressedTextureSubImage1D =
		(PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)LoadGLProc("glCompressedTextureSubImage1D");
	__glCompressedTextureSubImage2D =
		(PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)LoadGLProc("glCompressedTextureSubImage2D");
	__glCompressedTextureSubImage3D =
		(PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)LoadGLProc("glCompressedTextureSubImage3D");
	__glCopyBufferSubData =
		(PFNGLCOPYBUFFERSUBDATAPROC)LoadGLProc("glCopyBufferSubData");
	__glCopyImageSubData =
		(PFNGLCOPYIMAGESUBDATAPROC)LoadGLProc("glCopyImageSubData");
	__glCopyNamedBufferSubData =
		(PFNGLCOPYNAMEDBUFFERSUBDATAPROC)LoadGLProc("glCopyNamedBufferSubData");
	__glCopyTexImage1D =
		(PFNGLCOPYTEXIMAGE1DPROC)LoadGLProc("glCopyTexImage1D");
	__glCopyTexImage2D =
		(PFNGLCOPYTEXIMAGE2DPROC)LoadGLProc("glCopyTexImage2D");
	__glCopyTexSubImage1D =
		(PFNGLCOPYTEXSUBIMAGE1DPROC)LoadGLProc("glCopyTexSubImage1D");
	__glCopyTexSubImage2D =
		(PFNGLCOPYTEXSUBIMAGE2DPROC)LoadGLProc("glCopyTexSubImage2D");
	__glCopyTexSubImage3D =
		(PFNGLCOPYTEXSUBIMAGE3DPROC)LoadGLProc("glCopyTexSubImage3D");
	__glCopyTextureSubImage1D =
		(PFNGLCOPYTEXTURESUBIMAGE1DPROC)LoadGLProc("glCopyTextureSubImage1D");
	__glCopyTextureSubImage2D =
		(PFNGLCOPYTEXTURESUBIMAGE2DPROC)LoadGLProc("glCopyTextureSubImage2D");
	__glCopyTextureSubImage3D =
		(PFNGLCOPYTEXTURESUBIMAGE3DPROC)LoadGLProc("glCopyTextureSubImage3D");
	__glCreateBuffers =
		(PFNGLCREATEBUFFERSPROC)LoadGLProc("glCreateBuffers");
	__glCreateFramebuffers =
		(PFNGLCREATEFRAMEBUFFERSPROC)LoadGLProc("glCreateFramebuffers");
	__glCreateProgram =
		(PFNGLCREATEPROGRAMPROC)LoadGLProc("glCreateProgram");
	__glCreateProgramPipelines =
		(PFNGLCREATEPROGRAMPIPELINESPROC)LoadGLProc("glCreateProgramPipelines");
	__glCreateQueries =
		(PFNGLCREATEQUERIESPROC)LoadGLProc("glCreateQueries");
	__glCreateRenderbuffers =
		(PFNGLCREATERENDERBUFFERSPROC)LoadGLProc("glCreateRenderbuffers");
	__glCreateSamplers =
		(PFNGLCREATESAMPLERSPROC)LoadGLProc("glCreateSamplers");
	__glCreateShader =
		(PFNGLCREATESHADERPROC)LoadGLProc("glCreateShader");
	__glCreateShaderProgramv =
		(PFNGLCREATESHADERPROGRAMVPROC)LoadGLProc("glCreateShaderProgramv");
	__glCreateTextures =
		(PFNGLCREATETEXTURESPROC)LoadGLProc("glCreateTextures");
	__glCreateTransformFeedbacks =
		(PFNGLCREATETRANSFORMFEEDBACKSPROC)LoadGLProc("glCreateTransformFeedbacks");
	__glCreateVertexArrays =
		(PFNGLCREATEVERTEXARRAYSPROC)LoadGLProc("glCreateVertexArrays");
	__glCullFace =
		(PFNGLCULLFACEPROC)LoadGLProc("glCullFace");
	__glDebugMessageCallback =
		(PFNGLDEBUGMESSAGECALLBACKPROC)LoadGLProc("glDebugMessageCallback");
	__glDebugMessageControl =
		(PFNGLDEBUGMESSAGECONTROLPROC)LoadGLProc("glDebugMessageControl");
	__glDebugMessageInsert =
		(PFNGLDEBUGMESSAGEINSERTPROC)LoadGLProc("glDebugMessageInsert");
	__glDeleteBuffers =
		(PFNGLDELETEBUFFERSPROC)LoadGLProc("glDeleteBuffers");
	__glDeleteFramebuffers =
		(PFNGLDELETEFRAMEBUFFERSPROC)LoadGLProc("glDeleteFramebuffers");
	__glDeleteProgram =
		(PFNGLDELETEPROGRAMPROC)LoadGLProc("glDeleteProgram");
	__glDeleteProgramPipelines =
		(PFNGLDELETEPROGRAMPIPELINESPROC)LoadGLProc("glDeleteProgramPipelines");
	__glDeleteQueries =
		(PFNGLDELETEQUERIESPROC)LoadGLProc("glDeleteQueries");
	__glDeleteRenderbuffers =
		(PFNGLDELETERENDERBUFFERSPROC)LoadGLProc("glDeleteRenderbuffers");
	__glDeleteSamplers =
		(PFNGLDELETESAMPLERSPROC)LoadGLProc("glDeleteSamplers");
	__glDeleteShader =
		(PFNGLDELETESHADERPROC)LoadGLProc("glDeleteShader");
	__glDeleteSync =
		(PFNGLDELETESYNCPROC)LoadGLProc("glDeleteSync");
	__glDeleteTextures =
		(PFNGLDELETETEXTURESPROC)LoadGLProc("glDeleteTextures");
	__glDeleteTransformFeedbacks =
		(PFNGLDELETETRANSFORMFEEDBACKSPROC)LoadGLProc("glDeleteTransformFeedbacks");
	__glDeleteVertexArrays =
		(PFNGLDELETEVERTEXARRAYSPROC)LoadGLProc("glDeleteVertexArrays");
	__glDepthFunc =
		(PFNGLDEPTHFUNCPROC)LoadGLProc("glDepthFunc");
	__glDepthMask =
		(PFNGLDEPTHMASKPROC)LoadGLProc("glDepthMask");
	__glDepthRange =
		(PFNGLDEPTHRANGEPROC)LoadGLProc("glDepthRange");
	__glDepthRangeArrayv =
		(PFNGLDEPTHRANGEARRAYVPROC)LoadGLProc("glDepthRangeArrayv");
	__glDepthRangeIndexed =
		(PFNGLDEPTHRANGEINDEXEDPROC)LoadGLProc("glDepthRangeIndexed");
	__glDepthRangef =
		(PFNGLDEPTHRANGEFPROC)LoadGLProc("glDepthRangef");
	__glDetachShader =
		(PFNGLDETACHSHADERPROC)LoadGLProc("glDetachShader");
	__glDisable =
		(PFNGLDISABLEPROC)LoadGLProc("glDisable");
	__glDisableVertexArrayAttrib =
		(PFNGLDISABLEVERTEXARRAYATTRIBPROC)LoadGLProc("glDisableVertexArrayAttrib");
	__glDisableVertexAttribArray =
		(PFNGLDISABLEVERTEXATTRIBARRAYPROC)LoadGLProc("glDisableVertexAttribArray");
	__glDisablei =
		(PFNGLDISABLEIPROC)LoadGLProc("glDisablei");
	__glDispatchCompute =
		(PFNGLDISPATCHCOMPUTEPROC)LoadGLProc("glDispatchCompute");
	__glDispatchComputeIndirect =
		(PFNGLDISPATCHCOMPUTEINDIRECTPROC)LoadGLProc("glDispatchComputeIndirect");
	__glDrawArrays =
		(PFNGLDRAWARRAYSPROC)LoadGLProc("glDrawArrays");
	__glDrawArraysIndirect =
		(PFNGLDRAWARRAYSINDIRECTPROC)LoadGLProc("glDrawArraysIndirect");
	__glDrawArraysInstanced =
		(PFNGLDRAWARRAYSINSTANCEDPROC)LoadGLProc("glDrawArraysInstanced");
	__glDrawArraysInstancedBaseInstance =
		(PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)LoadGLProc("glDrawArraysInstancedBaseInstance");
	__glDrawBuffer =
		(PFNGLDRAWBUFFERPROC)LoadGLProc("glDrawBuffer");
	__glDrawBuffers =
		(PFNGLDRAWBUFFERSPROC)LoadGLProc("glDrawBuffers");
	__glDrawElements =
		(PFNGLDRAWELEMENTSPROC)LoadGLProc("glDrawElements");
	__glDrawElementsBaseVertex =
		(PFNGLDRAWELEMENTSBASEVERTEXPROC)LoadGLProc("glDrawElementsBaseVertex");
	__glDrawElementsIndirect =
		(PFNGLDRAWELEMENTSINDIRECTPROC)LoadGLProc("glDrawElementsIndirect");
	__glDrawElementsInstanced =
		(PFNGLDRAWELEMENTSINSTANCEDPROC)LoadGLProc("glDrawElementsInstanced");
	__glDrawElementsInstancedBaseInstance =
		(PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)LoadGLProc("glDrawElementsInstancedBaseInstance");
	__glDrawElementsInstancedBaseVertex =
		(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)LoadGLProc("glDrawElementsInstancedBaseVertex");
	__glDrawElementsInstancedBaseVertexBaseInstance =
		(PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)LoadGLProc("glDrawElementsInstancedBaseVertexBaseInstance");
	__glDrawRangeElements =
		(PFNGLDRAWRANGEELEMENTSPROC)LoadGLProc("glDrawRangeElements");
	__glDrawRangeElementsBaseVertex =
		(PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)LoadGLProc("glDrawRangeElementsBaseVertex");
	__glDrawTransformFeedback =
		(PFNGLDRAWTRANSFORMFEEDBACKPROC)LoadGLProc("glDrawTransformFeedback");
	__glDrawTransformFeedbackInstanced =
		(PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)LoadGLProc("glDrawTransformFeedbackInstanced");
	__glDrawTransformFeedbackStream =
		(PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)LoadGLProc("glDrawTransformFeedbackStream");
	__glDrawTransformFeedbackStreamInstanced =
		(PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)LoadGLProc("glDrawTransformFeedbackStreamInstanced");
	__glEnable =
		(PFNGLENABLEPROC)LoadGLProc("glEnable");
	__glEnableVertexArrayAttrib =
		(PFNGLENABLEVERTEXARRAYATTRIBPROC)LoadGLProc("glEnableVertexArrayAttrib");
	__glEnableVertexAttribArray =
		(PFNGLENABLEVERTEXATTRIBARRAYPROC)LoadGLProc("glEnableVertexAttribArray");
	__glEnablei =
		(PFNGLENABLEIPROC)LoadGLProc("glEnablei");
	__glEndConditionalRender =
		(PFNGLENDCONDITIONALRENDERPROC)LoadGLProc("glEndConditionalRender");
	__glEndQuery =
		(PFNGLENDQUERYPROC)LoadGLProc("glEndQuery");
	__glEndQueryIndexed =
		(PFNGLENDQUERYINDEXEDPROC)LoadGLProc("glEndQueryIndexed");
	__glEndTransformFeedback =
		(PFNGLENDTRANSFORMFEEDBACKPROC)LoadGLProc("glEndTransformFeedback");
	__glFenceSync =
		(PFNGLFENCESYNCPROC)LoadGLProc("glFenceSync");
	__glFinish =
		(PFNGLFINISHPROC)LoadGLProc("glFinish");
	__glFlush =
		(PFNGLFLUSHPROC)LoadGLProc("glFlush");
	__glFlushMappedBufferRange =
		(PFNGLFLUSHMAPPEDBUFFERRANGEPROC)LoadGLProc("glFlushMappedBufferRange");
	__glFlushMappedNamedBufferRange =
		(PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)LoadGLProc("glFlushMappedNamedBufferRange");
	__glFramebufferParameteri =
		(PFNGLFRAMEBUFFERPARAMETERIPROC)LoadGLProc("glFramebufferParameteri");
	__glFramebufferParameteriMESA =
		(PFNGLFRAMEBUFFERPARAMETERIMESAPROC)LoadGLProc("glFramebufferParameteriMESA");
	__glFramebufferRenderbuffer =
		(PFNGLFRAMEBUFFERRENDERBUFFERPROC)LoadGLProc("glFramebufferRenderbuffer");
	__glFramebufferTexture =
		(PFNGLFRAMEBUFFERTEXTUREPROC)LoadGLProc("glFramebufferTexture");
	__glFramebufferTexture1D =
		(PFNGLFRAMEBUFFERTEXTURE1DPROC)LoadGLProc("glFramebufferTexture1D");
	__glFramebufferTexture2D =
		(PFNGLFRAMEBUFFERTEXTURE2DPROC)LoadGLProc("glFramebufferTexture2D");
	__glFramebufferTexture3D =
		(PFNGLFRAMEBUFFERTEXTURE3DPROC)LoadGLProc("glFramebufferTexture3D");
	__glFramebufferTextureLayer =
		(PFNGLFRAMEBUFFERTEXTURELAYERPROC)LoadGLProc("glFramebufferTextureLayer");
	__glFrontFace =
		(PFNGLFRONTFACEPROC)LoadGLProc("glFrontFace");
	__glGenBuffers =
		(PFNGLGENBUFFERSPROC)LoadGLProc("glGenBuffers");
	__glGenFramebuffers =
		(PFNGLGENFRAMEBUFFERSPROC)LoadGLProc("glGenFramebuffers");
	__glGenProgramPipelines =
		(PFNGLGENPROGRAMPIPELINESPROC)LoadGLProc("glGenProgramPipelines");
	__glGenQueries =
		(PFNGLGENQUERIESPROC)LoadGLProc("glGenQueries");
	__glGenRenderbuffers =
		(PFNGLGENRENDERBUFFERSPROC)LoadGLProc("glGenRenderbuffers");
	__glGenSamplers =
		(PFNGLGENSAMPLERSPROC)LoadGLProc("glGenSamplers");
	__glGenTextures =
		(PFNGLGENTEXTURESPROC)LoadGLProc("glGenTextures");
	__glGenTransformFeedbacks =
		(PFNGLGENTRANSFORMFEEDBACKSPROC)LoadGLProc("glGenTransformFeedbacks");
	__glGenVertexArrays =
		(PFNGLGENVERTEXARRAYSPROC)LoadGLProc("glGenVertexArrays");
	__glGenerateMipmap =
		(PFNGLGENERATEMIPMAPPROC)LoadGLProc("glGenerateMipmap");
	__glGenerateTextureMipmap =
		(PFNGLGENERATETEXTUREMIPMAPPROC)LoadGLProc("glGenerateTextureMipmap");
	__glGetActiveAtomicCounterBufferiv =
		(PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)LoadGLProc("glGetActiveAtomicCounterBufferiv");
	__glGetActiveAttrib =
		(PFNGLGETACTIVEATTRIBPROC)LoadGLProc("glGetActiveAttrib");
	__glGetActiveSubroutineName =
		(PFNGLGETACTIVESUBROUTINENAMEPROC)LoadGLProc("glGetActiveSubroutineName");
	__glGetActiveSubroutineUniformName =
		(PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)LoadGLProc("glGetActiveSubroutineUniformName");
	__glGetActiveSubroutineUniformiv =
		(PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)LoadGLProc("glGetActiveSubroutineUniformiv");
	__glGetActiveUniform =
		(PFNGLGETACTIVEUNIFORMPROC)LoadGLProc("glGetActiveUniform");
	__glGetActiveUniformBlockName =
		(PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)LoadGLProc("glGetActiveUniformBlockName");
	__glGetActiveUniformBlockiv =
		(PFNGLGETACTIVEUNIFORMBLOCKIVPROC)LoadGLProc("glGetActiveUniformBlockiv");
	__glGetActiveUniformName =
		(PFNGLGETACTIVEUNIFORMNAMEPROC)LoadGLProc("glGetActiveUniformName");
	__glGetActiveUniformsiv =
		(PFNGLGETACTIVEUNIFORMSIVPROC)LoadGLProc("glGetActiveUniformsiv");
	__glGetAttachedShaders =
		(PFNGLGETATTACHEDSHADERSPROC)LoadGLProc("glGetAttachedShaders");
	__glGetAttribLocation =
		(PFNGLGETATTRIBLOCATIONPROC)LoadGLProc("glGetAttribLocation");
	__glGetBooleani_v =
		(PFNGLGETBOOLEANI_VPROC)LoadGLProc("glGetBooleani_v");
	__glGetBooleanv =
		(PFNGLGETBOOLEANVPROC)LoadGLProc("glGetBooleanv");
	__glGetBufferParameteri64v =
		(PFNGLGETBUFFERPARAMETERI64VPROC)LoadGLProc("glGetBufferParameteri64v");
	__glGetBufferParameteriv =
		(PFNGLGETBUFFERPARAMETERIVPROC)LoadGLProc("glGetBufferParameteriv");
	__glGetBufferPointerv =
		(PFNGLGETBUFFERPOINTERVPROC)LoadGLProc("glGetBufferPointerv");
	__glGetBufferSubData =
		(PFNGLGETBUFFERSUBDATAPROC)LoadGLProc("glGetBufferSubData");
	__glGetCompressedTexImage =
		(PFNGLGETCOMPRESSEDTEXIMAGEPROC)LoadGLProc("glGetCompressedTexImage");
	__glGetCompressedTextureImage =
		(PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)LoadGLProc("glGetCompressedTextureImage");
	__glGetCompressedTextureSubImage =
		(PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)LoadGLProc("glGetCompressedTextureSubImage");
	__glGetDebugMessageLog =
		(PFNGLGETDEBUGMESSAGELOGPROC)LoadGLProc("glGetDebugMessageLog");
	__glGetDoublei_v =
		(PFNGLGETDOUBLEI_VPROC)LoadGLProc("glGetDoublei_v");
	__glGetDoublev =
		(PFNGLGETDOUBLEVPROC)LoadGLProc("glGetDoublev");
	__glGetError =
		(PFNGLGETERRORPROC)LoadGLProc("glGetError");
	__glGetFloati_v =
		(PFNGLGETFLOATI_VPROC)LoadGLProc("glGetFloati_v");
	__glGetFloatv =
		(PFNGLGETFLOATVPROC)LoadGLProc("glGetFloatv");
	__glGetFragDataIndex =
		(PFNGLGETFRAGDATAINDEXPROC)LoadGLProc("glGetFragDataIndex");
	__glGetFragDataLocation =
		(PFNGLGETFRAGDATALOCATIONPROC)LoadGLProc("glGetFragDataLocation");
	__glGetFramebufferAttachmentParameteriv =
		(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)LoadGLProc("glGetFramebufferAttachmentParameteriv");
	__glGetFramebufferParameteriv =
		(PFNGLGETFRAMEBUFFERPARAMETERIVPROC)LoadGLProc("glGetFramebufferParameteriv");
	__glGetFramebufferParameterivMESA =
		(PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC)LoadGLProc("glGetFramebufferParameterivMESA");
	__glGetGraphicsResetStatus =
		(PFNGLGETGRAPHICSRESETSTATUSPROC)LoadGLProc("glGetGraphicsResetStatus");
	__glGetInteger64i_v =
		(PFNGLGETINTEGER64I_VPROC)LoadGLProc("glGetInteger64i_v");
	__glGetInteger64v =
		(PFNGLGETINTEGER64VPROC)LoadGLProc("glGetInteger64v");
	__glGetIntegeri_v =
		(PFNGLGETINTEGERI_VPROC)LoadGLProc("glGetIntegeri_v");
	__glGetIntegerv =
		(PFNGLGETINTEGERVPROC)LoadGLProc("glGetIntegerv");
	__glGetInternalformati64v =
		(PFNGLGETINTERNALFORMATI64VPROC)LoadGLProc("glGetInternalformati64v");
	__glGetInternalformativ =
		(PFNGLGETINTERNALFORMATIVPROC)LoadGLProc("glGetInternalformativ");
	__glGetMultisamplefv =
		(PFNGLGETMULTISAMPLEFVPROC)LoadGLProc("glGetMultisamplefv");
	__glGetNamedBufferParameteri64v =
		(PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)LoadGLProc("glGetNamedBufferParameteri64v");
	__glGetNamedBufferParameteriv =
		(PFNGLGETNAMEDBUFFERPARAMETERIVPROC)LoadGLProc("glGetNamedBufferParameteriv");
	__glGetNamedBufferPointerv =
		(PFNGLGETNAMEDBUFFERPOINTERVPROC)LoadGLProc("glGetNamedBufferPointerv");
	__glGetNamedBufferSubData =
		(PFNGLGETNAMEDBUFFERSUBDATAPROC)LoadGLProc("glGetNamedBufferSubData");
	__glGetNamedFramebufferAttachmentParameteriv =
		(PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)LoadGLProc("glGetNamedFramebufferAttachmentParameteriv");
	__glGetNamedFramebufferParameteriv =
		(PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)LoadGLProc("glGetNamedFramebufferParameteriv");
	__glGetNamedRenderbufferParameteriv =
		(PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)LoadGLProc("glGetNamedRenderbufferParameteriv");
	__glGetObjectLabel =
		(PFNGLGETOBJECTLABELPROC)LoadGLProc("glGetObjectLabel");
	__glGetObjectPtrLabel =
		(PFNGLGETOBJECTPTRLABELPROC)LoadGLProc("glGetObjectPtrLabel");
	__glGetPointerv =
		(PFNGLGETPOINTERVPROC)LoadGLProc("glGetPointerv");
	__glGetProgramBinary =
		(PFNGLGETPROGRAMBINARYPROC)LoadGLProc("glGetProgramBinary");
	__glGetProgramInfoLog =
		(PFNGLGETPROGRAMINFOLOGPROC)LoadGLProc("glGetProgramInfoLog");
	__glGetProgramInterfaceiv =
		(PFNGLGETPROGRAMINTERFACEIVPROC)LoadGLProc("glGetProgramInterfaceiv");
	__glGetProgramPipelineInfoLog =
		(PFNGLGETPROGRAMPIPELINEINFOLOGPROC)LoadGLProc("glGetProgramPipelineInfoLog");
	__glGetProgramPipelineiv =
		(PFNGLGETPROGRAMPIPELINEIVPROC)LoadGLProc("glGetProgramPipelineiv");
	__glGetProgramResourceIndex =
		(PFNGLGETPROGRAMRESOURCEINDEXPROC)LoadGLProc("glGetProgramResourceIndex");
	__glGetProgramResourceLocation =
		(PFNGLGETPROGRAMRESOURCELOCATIONPROC)LoadGLProc("glGetProgramResourceLocation");
	__glGetProgramResourceLocationIndex =
		(PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)LoadGLProc("glGetProgramResourceLocationIndex");
	__glGetProgramResourceName =
		(PFNGLGETPROGRAMRESOURCENAMEPROC)LoadGLProc("glGetProgramResourceName");
	__glGetProgramResourceiv =
		(PFNGLGETPROGRAMRESOURCEIVPROC)LoadGLProc("glGetProgramResourceiv");
	__glGetProgramStageiv =
		(PFNGLGETPROGRAMSTAGEIVPROC)LoadGLProc("glGetProgramStageiv");
	__glGetProgramiv =
		(PFNGLGETPROGRAMIVPROC)LoadGLProc("glGetProgramiv");
	__glGetQueryBufferObjecti64v =
		(PFNGLGETQUERYBUFFEROBJECTI64VPROC)LoadGLProc("glGetQueryBufferObjecti64v");
	__glGetQueryBufferObjectiv =
		(PFNGLGETQUERYBUFFEROBJECTIVPROC)LoadGLProc("glGetQueryBufferObjectiv");
	__glGetQueryBufferObjectui64v =
		(PFNGLGETQUERYBUFFEROBJECTUI64VPROC)LoadGLProc("glGetQueryBufferObjectui64v");
	__glGetQueryBufferObjectuiv =
		(PFNGLGETQUERYBUFFEROBJECTUIVPROC)LoadGLProc("glGetQueryBufferObjectuiv");
	__glGetQueryIndexediv =
		(PFNGLGETQUERYINDEXEDIVPROC)LoadGLProc("glGetQueryIndexediv");
	__glGetQueryObjecti64v =
		(PFNGLGETQUERYOBJECTI64VPROC)LoadGLProc("glGetQueryObjecti64v");
	__glGetQueryObjectiv =
		(PFNGLGETQUERYOBJECTIVPROC)LoadGLProc("glGetQueryObjectiv");
	__glGetQueryObjectui64v =
		(PFNGLGETQUERYOBJECTUI64VPROC)LoadGLProc("glGetQueryObjectui64v");
	__glGetQueryObjectuiv =
		(PFNGLGETQUERYOBJECTUIVPROC)LoadGLProc("glGetQueryObjectuiv");
	__glGetQueryiv =
		(PFNGLGETQUERYIVPROC)LoadGLProc("glGetQueryiv");
	__glGetRenderbufferParameteriv =
		(PFNGLGETRENDERBUFFERPARAMETERIVPROC)LoadGLProc("glGetRenderbufferParameteriv");
	__glGetSamplerParameterIiv =
		(PFNGLGETSAMPLERPARAMETERIIVPROC)LoadGLProc("glGetSamplerParameterIiv");
	__glGetSamplerParameterIuiv =
		(PFNGLGETSAMPLERPARAMETERIUIVPROC)LoadGLProc("glGetSamplerParameterIuiv");
	__glGetSamplerParameterfv =
		(PFNGLGETSAMPLERPARAMETERFVPROC)LoadGLProc("glGetSamplerParameterfv");
	__glGetSamplerParameteriv =
		(PFNGLGETSAMPLERPARAMETERIVPROC)LoadGLProc("glGetSamplerParameteriv");
	__glGetShaderInfoLog =
		(PFNGLGETSHADERINFOLOGPROC)LoadGLProc("glGetShaderInfoLog");
	__glGetShaderPrecisionFormat =
		(PFNGLGETSHADERPRECISIONFORMATPROC)LoadGLProc("glGetShaderPrecisionFormat");
	__glGetShaderSource =
		(PFNGLGETSHADERSOURCEPROC)LoadGLProc("glGetShaderSource");
	__glGetShaderiv =
		(PFNGLGETSHADERIVPROC)LoadGLProc("glGetShaderiv");
	__glGetString =
		(PFNGLGETSTRINGPROC)LoadGLProc("glGetString");
	__glGetStringi =
		(PFNGLGETSTRINGIPROC)LoadGLProc("glGetStringi");
	__glGetSubroutineIndex =
		(PFNGLGETSUBROUTINEINDEXPROC)LoadGLProc("glGetSubroutineIndex");
	__glGetSubroutineUniformLocation =
		(PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)LoadGLProc("glGetSubroutineUniformLocation");
	__glGetSynciv =
		(PFNGLGETSYNCIVPROC)LoadGLProc("glGetSynciv");
	__glGetTexImage =
		(PFNGLGETTEXIMAGEPROC)LoadGLProc("glGetTexImage");
	__glGetTexLevelParameterfv =
		(PFNGLGETTEXLEVELPARAMETERFVPROC)LoadGLProc("glGetTexLevelParameterfv");
	__glGetTexLevelParameteriv =
		(PFNGLGETTEXLEVELPARAMETERIVPROC)LoadGLProc("glGetTexLevelParameteriv");
	__glGetTexParameterIiv =
		(PFNGLGETTEXPARAMETERIIVPROC)LoadGLProc("glGetTexParameterIiv");
	__glGetTexParameterIuiv =
		(PFNGLGETTEXPARAMETERIUIVPROC)LoadGLProc("glGetTexParameterIuiv");
	__glGetTexParameterfv =
		(PFNGLGETTEXPARAMETERFVPROC)LoadGLProc("glGetTexParameterfv");
	__glGetTexParameteriv =
		(PFNGLGETTEXPARAMETERIVPROC)LoadGLProc("glGetTexParameteriv");
	__glGetTextureImage =
		(PFNGLGETTEXTUREIMAGEPROC)LoadGLProc("glGetTextureImage");
	__glGetTextureLevelParameterfv =
		(PFNGLGETTEXTURELEVELPARAMETERFVPROC)LoadGLProc("glGetTextureLevelParameterfv");
	__glGetTextureLevelParameteriv =
		(PFNGLGETTEXTURELEVELPARAMETERIVPROC)LoadGLProc("glGetTextureLevelParameteriv");
	__glGetTextureParameterIiv =
		(PFNGLGETTEXTUREPARAMETERIIVPROC)LoadGLProc("glGetTextureParameterIiv");
	__glGetTextureParameterIuiv =
		(PFNGLGETTEXTUREPARAMETERIUIVPROC)LoadGLProc("glGetTextureParameterIuiv");
	__glGetTextureParameterfv =
		(PFNGLGETTEXTUREPARAMETERFVPROC)LoadGLProc("glGetTextureParameterfv");
	__glGetTextureParameteriv =
		(PFNGLGETTEXTUREPARAMETERIVPROC)LoadGLProc("glGetTextureParameteriv");
	__glGetTextureSubImage =
		(PFNGLGETTEXTURESUBIMAGEPROC)LoadGLProc("glGetTextureSubImage");
	__glGetTransformFeedbackVarying =
		(PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)LoadGLProc("glGetTransformFeedbackVarying");
	__glGetTransformFeedbacki64_v =
		(PFNGLGETTRANSFORMFEEDBACKI64_VPROC)LoadGLProc("glGetTransformFeedbacki64_v");
	__glGetTransformFeedbacki_v =
		(PFNGLGETTRANSFORMFEEDBACKI_VPROC)LoadGLProc("glGetTransformFeedbacki_v");
	__glGetTransformFeedbackiv =
		(PFNGLGETTRANSFORMFEEDBACKIVPROC)LoadGLProc("glGetTransformFeedbackiv");
	__glGetUniformBlockIndex =
		(PFNGLGETUNIFORMBLOCKINDEXPROC)LoadGLProc("glGetUniformBlockIndex");
	__glGetUniformIndices =
		(PFNGLGETUNIFORMINDICESPROC)LoadGLProc("glGetUniformIndices");
	__glGetUniformLocation =
		(PFNGLGETUNIFORMLOCATIONPROC)LoadGLProc("glGetUniformLocation");
	__glGetUniformSubroutineuiv =
		(PFNGLGETUNIFORMSUBROUTINEUIVPROC)LoadGLProc("glGetUniformSubroutineuiv");
	__glGetUniformdv =
		(PFNGLGETUNIFORMDVPROC)LoadGLProc("glGetUniformdv");
	__glGetUniformfv =
		(PFNGLGETUNIFORMFVPROC)LoadGLProc("glGetUniformfv");
	__glGetUniformiv =
		(PFNGLGETUNIFORMIVPROC)LoadGLProc("glGetUniformiv");
	__glGetUniformuiv =
		(PFNGLGETUNIFORMUIVPROC)LoadGLProc("glGetUniformuiv");
	__glGetVertexArrayIndexed64iv =
		(PFNGLGETVERTEXARRAYINDEXED64IVPROC)LoadGLProc("glGetVertexArrayIndexed64iv");
	__glGetVertexArrayIndexediv =
		(PFNGLGETVERTEXARRAYINDEXEDIVPROC)LoadGLProc("glGetVertexArrayIndexediv");
	__glGetVertexArrayiv =
		(PFNGLGETVERTEXARRAYIVPROC)LoadGLProc("glGetVertexArrayiv");
	__glGetVertexAttribIiv =
		(PFNGLGETVERTEXATTRIBIIVPROC)LoadGLProc("glGetVertexAttribIiv");
	__glGetVertexAttribIuiv =
		(PFNGLGETVERTEXATTRIBIUIVPROC)LoadGLProc("glGetVertexAttribIuiv");
	__glGetVertexAttribLdv =
		(PFNGLGETVERTEXATTRIBLDVPROC)LoadGLProc("glGetVertexAttribLdv");
	__glGetVertexAttribPointerv =
		(PFNGLGETVERTEXATTRIBPOINTERVPROC)LoadGLProc("glGetVertexAttribPointerv");
	__glGetVertexAttribdv =
		(PFNGLGETVERTEXATTRIBDVPROC)LoadGLProc("glGetVertexAttribdv");
	__glGetVertexAttribfv =
		(PFNGLGETVERTEXATTRIBFVPROC)LoadGLProc("glGetVertexAttribfv");
	__glGetVertexAttribiv =
		(PFNGLGETVERTEXATTRIBIVPROC)LoadGLProc("glGetVertexAttribiv");
	__glGetnCompressedTexImage =
		(PFNGLGETNCOMPRESSEDTEXIMAGEPROC)LoadGLProc("glGetnCompressedTexImage");
	__glGetnTexImage =
		(PFNGLGETNTEXIMAGEPROC)LoadGLProc("glGetnTexImage");
	__glGetnUniformdv =
		(PFNGLGETNUNIFORMDVPROC)LoadGLProc("glGetnUniformdv");
	__glGetnUniformfv =
		(PFNGLGETNUNIFORMFVPROC)LoadGLProc("glGetnUniformfv");
	__glGetnUniformiv =
		(PFNGLGETNUNIFORMIVPROC)LoadGLProc("glGetnUniformiv");
	__glGetnUniformuiv =
		(PFNGLGETNUNIFORMUIVPROC)LoadGLProc("glGetnUniformuiv");
	__glHint =
		(PFNGLHINTPROC)LoadGLProc("glHint");
	__glInvalidateBufferData =
		(PFNGLINVALIDATEBUFFERDATAPROC)LoadGLProc("glInvalidateBufferData");
	__glInvalidateBufferSubData =
		(PFNGLINVALIDATEBUFFERSUBDATAPROC)LoadGLProc("glInvalidateBufferSubData");
	__glInvalidateFramebuffer =
		(PFNGLINVALIDATEFRAMEBUFFERPROC)LoadGLProc("glInvalidateFramebuffer");
	__glInvalidateNamedFramebufferData =
		(PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)LoadGLProc("glInvalidateNamedFramebufferData");
	__glInvalidateNamedFramebufferSubData =
		(PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)LoadGLProc("glInvalidateNamedFramebufferSubData");
	__glInvalidateSubFramebuffer =
		(PFNGLINVALIDATESUBFRAMEBUFFERPROC)LoadGLProc("glInvalidateSubFramebuffer");
	__glInvalidateTexImage =
		(PFNGLINVALIDATETEXIMAGEPROC)LoadGLProc("glInvalidateTexImage");
	__glInvalidateTexSubImage =
		(PFNGLINVALIDATETEXSUBIMAGEPROC)LoadGLProc("glInvalidateTexSubImage");
	__glIsBuffer =
		(PFNGLISBUFFERPROC)LoadGLProc("glIsBuffer");
	__glIsEnabled =
		(PFNGLISENABLEDPROC)LoadGLProc("glIsEnabled");
	__glIsEnabledi =
		(PFNGLISENABLEDIPROC)LoadGLProc("glIsEnabledi");
	__glIsFramebuffer =
		(PFNGLISFRAMEBUFFERPROC)LoadGLProc("glIsFramebuffer");
	__glIsProgram =
		(PFNGLISPROGRAMPROC)LoadGLProc("glIsProgram");
	__glIsProgramPipeline =
		(PFNGLISPROGRAMPIPELINEPROC)LoadGLProc("glIsProgramPipeline");
	__glIsQuery =
		(PFNGLISQUERYPROC)LoadGLProc("glIsQuery");
	__glIsRenderbuffer =
		(PFNGLISRENDERBUFFERPROC)LoadGLProc("glIsRenderbuffer");
	__glIsSampler =
		(PFNGLISSAMPLERPROC)LoadGLProc("glIsSampler");
	__glIsShader =
		(PFNGLISSHADERPROC)LoadGLProc("glIsShader");
	__glIsSync =
		(PFNGLISSYNCPROC)LoadGLProc("glIsSync");
	__glIsTexture =
		(PFNGLISTEXTUREPROC)LoadGLProc("glIsTexture");
	__glIsTransformFeedback =
		(PFNGLISTRANSFORMFEEDBACKPROC)LoadGLProc("glIsTransformFeedback");
	__glIsVertexArray =
		(PFNGLISVERTEXARRAYPROC)LoadGLProc("glIsVertexArray");
	__glLineWidth =
		(PFNGLLINEWIDTHPROC)LoadGLProc("glLineWidth");
	__glLinkProgram =
		(PFNGLLINKPROGRAMPROC)LoadGLProc("glLinkProgram");
	__glLogicOp =
		(PFNGLLOGICOPPROC)LoadGLProc("glLogicOp");
	__glMapBuffer =
		(PFNGLMAPBUFFERPROC)LoadGLProc("glMapBuffer");
	__glMapBufferRange =
		(PFNGLMAPBUFFERRANGEPROC)LoadGLProc("glMapBufferRange");
	__glMapNamedBuffer =
		(PFNGLMAPNAMEDBUFFERPROC)LoadGLProc("glMapNamedBuffer");
	__glMapNamedBufferRange =
		(PFNGLMAPNAMEDBUFFERRANGEPROC)LoadGLProc("glMapNamedBufferRange");
	__glMemoryBarrier =
		(PFNGLMEMORYBARRIERPROC)LoadGLProc("glMemoryBarrier");
	__glMemoryBarrierByRegion =
		(PFNGLMEMORYBARRIERBYREGIONPROC)LoadGLProc("glMemoryBarrierByRegion");
	__glMinSampleShading =
		(PFNGLMINSAMPLESHADINGPROC)LoadGLProc("glMinSampleShading");
	__glMultiDrawArrays =
		(PFNGLMULTIDRAWARRAYSPROC)LoadGLProc("glMultiDrawArrays");
	__glMultiDrawArraysIndirect =
		(PFNGLMULTIDRAWARRAYSINDIRECTPROC)LoadGLProc("glMultiDrawArraysIndirect");
	__glMultiDrawArraysIndirectCount =
		(PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC)LoadGLProc("glMultiDrawArraysIndirectCount");
	__glMultiDrawElements =
		(PFNGLMULTIDRAWELEMENTSPROC)LoadGLProc("glMultiDrawElements");
	__glMultiDrawElementsBaseVertex =
		(PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)LoadGLProc("glMultiDrawElementsBaseVertex");
	__glMultiDrawElementsIndirect =
		(PFNGLMULTIDRAWELEMENTSINDIRECTPROC)LoadGLProc("glMultiDrawElementsIndirect");
	__glMultiDrawElementsIndirectCount =
		(PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC)LoadGLProc("glMultiDrawElementsIndirectCount");
	__glNamedBufferData =
		(PFNGLNAMEDBUFFERDATAPROC)LoadGLProc("glNamedBufferData");
	__glNamedBufferStorage =
		(PFNGLNAMEDBUFFERSTORAGEPROC)LoadGLProc("glNamedBufferStorage");
	__glNamedBufferSubData =
		(PFNGLNAMEDBUFFERSUBDATAPROC)LoadGLProc("glNamedBufferSubData");
	__glNamedFramebufferDrawBuffer =
		(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)LoadGLProc("glNamedFramebufferDrawBuffer");
	__glNamedFramebufferDrawBuffers =
		(PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)LoadGLProc("glNamedFramebufferDrawBuffers");
	__glNamedFramebufferParameteri =
		(PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)LoadGLProc("glNamedFramebufferParameteri");
	__glNamedFramebufferReadBuffer =
		(PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)LoadGLProc("glNamedFramebufferReadBuffer");
	__glNamedFramebufferRenderbuffer =
		(PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)LoadGLProc("glNamedFramebufferRenderbuffer");
	__glNamedFramebufferTexture =
		(PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)LoadGLProc("glNamedFramebufferTexture");
	__glNamedFramebufferTextureLayer =
		(PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)LoadGLProc("glNamedFramebufferTextureLayer");
	__glNamedRenderbufferStorage =
		(PFNGLNAMEDRENDERBUFFERSTORAGEPROC)LoadGLProc("glNamedRenderbufferStorage");
	__glNamedRenderbufferStorageMultisample =
		(PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)LoadGLProc("glNamedRenderbufferStorageMultisample");
	__glObjectLabel =
		(PFNGLOBJECTLABELPROC)LoadGLProc("glObjectLabel");
	__glObjectPtrLabel =
		(PFNGLOBJECTPTRLABELPROC)LoadGLProc("glObjectPtrLabel");
	__glPatchParameterfv =
		(PFNGLPATCHPARAMETERFVPROC)LoadGLProc("glPatchParameterfv");
	__glPatchParameteri =
		(PFNGLPATCHPARAMETERIPROC)LoadGLProc("glPatchParameteri");
	__glPauseTransformFeedback =
		(PFNGLPAUSETRANSFORMFEEDBACKPROC)LoadGLProc("glPauseTransformFeedback");
	__glPixelStoref =
		(PFNGLPIXELSTOREFPROC)LoadGLProc("glPixelStoref");
	__glPixelStorei =
		(PFNGLPIXELSTOREIPROC)LoadGLProc("glPixelStorei");
	__glPointParameterf =
		(PFNGLPOINTPARAMETERFPROC)LoadGLProc("glPointParameterf");
	__glPointParameterfv =
		(PFNGLPOINTPARAMETERFVPROC)LoadGLProc("glPointParameterfv");
	__glPointParameteri =
		(PFNGLPOINTPARAMETERIPROC)LoadGLProc("glPointParameteri");
	__glPointParameteriv =
		(PFNGLPOINTPARAMETERIVPROC)LoadGLProc("glPointParameteriv");
	__glPointSize =
		(PFNGLPOINTSIZEPROC)LoadGLProc("glPointSize");
	__glPolygonMode =
		(PFNGLPOLYGONMODEPROC)LoadGLProc("glPolygonMode");
	__glPolygonOffset =
		(PFNGLPOLYGONOFFSETPROC)LoadGLProc("glPolygonOffset");
	__glPolygonOffsetClamp =
		(PFNGLPOLYGONOFFSETCLAMPPROC)LoadGLProc("glPolygonOffsetClamp");
	__glPopDebugGroup =
		(PFNGLPOPDEBUGGROUPPROC)LoadGLProc("glPopDebugGroup");
	__glPrimitiveRestartIndex =
		(PFNGLPRIMITIVERESTARTINDEXPROC)LoadGLProc("glPrimitiveRestartIndex");
	__glProgramBinary =
		(PFNGLPROGRAMBINARYPROC)LoadGLProc("glProgramBinary");
	__glProgramParameteri =
		(PFNGLPROGRAMPARAMETERIPROC)LoadGLProc("glProgramParameteri");
	__glProgramUniform1d =
		(PFNGLPROGRAMUNIFORM1DPROC)LoadGLProc("glProgramUniform1d");
	__glProgramUniform1dv =
		(PFNGLPROGRAMUNIFORM1DVPROC)LoadGLProc("glProgramUniform1dv");
	__glProgramUniform1f =
		(PFNGLPROGRAMUNIFORM1FPROC)LoadGLProc("glProgramUniform1f");
	__glProgramUniform1fv =
		(PFNGLPROGRAMUNIFORM1FVPROC)LoadGLProc("glProgramUniform1fv");
	__glProgramUniform1i =
		(PFNGLPROGRAMUNIFORM1IPROC)LoadGLProc("glProgramUniform1i");
	__glProgramUniform1iv =
		(PFNGLPROGRAMUNIFORM1IVPROC)LoadGLProc("glProgramUniform1iv");
	__glProgramUniform1ui =
		(PFNGLPROGRAMUNIFORM1UIPROC)LoadGLProc("glProgramUniform1ui");
	__glProgramUniform1uiv =
		(PFNGLPROGRAMUNIFORM1UIVPROC)LoadGLProc("glProgramUniform1uiv");
	__glProgramUniform2d =
		(PFNGLPROGRAMUNIFORM2DPROC)LoadGLProc("glProgramUniform2d");
	__glProgramUniform2dv =
		(PFNGLPROGRAMUNIFORM2DVPROC)LoadGLProc("glProgramUniform2dv");
	__glProgramUniform2f =
		(PFNGLPROGRAMUNIFORM2FPROC)LoadGLProc("glProgramUniform2f");
	__glProgramUniform2fv =
		(PFNGLPROGRAMUNIFORM2FVPROC)LoadGLProc("glProgramUniform2fv");
	__glProgramUniform2i =
		(PFNGLPROGRAMUNIFORM2IPROC)LoadGLProc("glProgramUniform2i");
	__glProgramUniform2iv =
		(PFNGLPROGRAMUNIFORM2IVPROC)LoadGLProc("glProgramUniform2iv");
	__glProgramUniform2ui =
		(PFNGLPROGRAMUNIFORM2UIPROC)LoadGLProc("glProgramUniform2ui");
	__glProgramUniform2uiv =
		(PFNGLPROGRAMUNIFORM2UIVPROC)LoadGLProc("glProgramUniform2uiv");
	__glProgramUniform3d =
		(PFNGLPROGRAMUNIFORM3DPROC)LoadGLProc("glProgramUniform3d");
	__glProgramUniform3dv =
		(PFNGLPROGRAMUNIFORM3DVPROC)LoadGLProc("glProgramUniform3dv");
	__glProgramUniform3f =
		(PFNGLPROGRAMUNIFORM3FPROC)LoadGLProc("glProgramUniform3f");
	__glProgramUniform3fv =
		(PFNGLPROGRAMUNIFORM3FVPROC)LoadGLProc("glProgramUniform3fv");
	__glProgramUniform3i =
		(PFNGLPROGRAMUNIFORM3IPROC)LoadGLProc("glProgramUniform3i");
	__glProgramUniform3iv =
		(PFNGLPROGRAMUNIFORM3IVPROC)LoadGLProc("glProgramUniform3iv");
	__glProgramUniform3ui =
		(PFNGLPROGRAMUNIFORM3UIPROC)LoadGLProc("glProgramUniform3ui");
	__glProgramUniform3uiv =
		(PFNGLPROGRAMUNIFORM3UIVPROC)LoadGLProc("glProgramUniform3uiv");
	__glProgramUniform4d =
		(PFNGLPROGRAMUNIFORM4DPROC)LoadGLProc("glProgramUniform4d");
	__glProgramUniform4dv =
		(PFNGLPROGRAMUNIFORM4DVPROC)LoadGLProc("glProgramUniform4dv");
	__glProgramUniform4f =
		(PFNGLPROGRAMUNIFORM4FPROC)LoadGLProc("glProgramUniform4f");
	__glProgramUniform4fv =
		(PFNGLPROGRAMUNIFORM4FVPROC)LoadGLProc("glProgramUniform4fv");
	__glProgramUniform4i =
		(PFNGLPROGRAMUNIFORM4IPROC)LoadGLProc("glProgramUniform4i");
	__glProgramUniform4iv =
		(PFNGLPROGRAMUNIFORM4IVPROC)LoadGLProc("glProgramUniform4iv");
	__glProgramUniform4ui =
		(PFNGLPROGRAMUNIFORM4UIPROC)LoadGLProc("glProgramUniform4ui");
	__glProgramUniform4uiv =
		(PFNGLPROGRAMUNIFORM4UIVPROC)LoadGLProc("glProgramUniform4uiv");
	__glProgramUniformMatrix2dv =
		(PFNGLPROGRAMUNIFORMMATRIX2DVPROC)LoadGLProc("glProgramUniformMatrix2dv");
	__glProgramUniformMatrix2fv =
		(PFNGLPROGRAMUNIFORMMATRIX2FVPROC)LoadGLProc("glProgramUniformMatrix2fv");
	__glProgramUniformMatrix2x3dv =
		(PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)LoadGLProc("glProgramUniformMatrix2x3dv");
	__glProgramUniformMatrix2x3fv =
		(PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)LoadGLProc("glProgramUniformMatrix2x3fv");
	__glProgramUniformMatrix2x4dv =
		(PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)LoadGLProc("glProgramUniformMatrix2x4dv");
	__glProgramUniformMatrix2x4fv =
		(PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)LoadGLProc("glProgramUniformMatrix2x4fv");
	__glProgramUniformMatrix3dv =
		(PFNGLPROGRAMUNIFORMMATRIX3DVPROC)LoadGLProc("glProgramUniformMatrix3dv");
	__glProgramUniformMatrix3fv =
		(PFNGLPROGRAMUNIFORMMATRIX3FVPROC)LoadGLProc("glProgramUniformMatrix3fv");
	__glProgramUniformMatrix3x2dv =
		(PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)LoadGLProc("glProgramUniformMatrix3x2dv");
	__glProgramUniformMatrix3x2fv =
		(PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)LoadGLProc("glProgramUniformMatrix3x2fv");
	__glProgramUniformMatrix3x4dv =
		(PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)LoadGLProc("glProgramUniformMatrix3x4dv");
	__glProgramUniformMatrix3x4fv =
		(PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)LoadGLProc("glProgramUniformMatrix3x4fv");
	__glProgramUniformMatrix4dv =
		(PFNGLPROGRAMUNIFORMMATRIX4DVPROC)LoadGLProc("glProgramUniformMatrix4dv");
	__glProgramUniformMatrix4fv =
		(PFNGLPROGRAMUNIFORMMATRIX4FVPROC)LoadGLProc("glProgramUniformMatrix4fv");
	__glProgramUniformMatrix4x2dv =
		(PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)LoadGLProc("glProgramUniformMatrix4x2dv");
	__glProgramUniformMatrix4x2fv =
		(PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)LoadGLProc("glProgramUniformMatrix4x2fv");
	__glProgramUniformMatrix4x3dv =
		(PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)LoadGLProc("glProgramUniformMatrix4x3dv");
	__glProgramUniformMatrix4x3fv =
		(PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)LoadGLProc("glProgramUniformMatrix4x3fv");
	__glProvokingVertex =
		(PFNGLPROVOKINGVERTEXPROC)LoadGLProc("glProvokingVertex");
	__glPushDebugGroup =
		(PFNGLPUSHDEBUGGROUPPROC)LoadGLProc("glPushDebugGroup");
	__glQueryCounter =
		(PFNGLQUERYCOUNTERPROC)LoadGLProc("glQueryCounter");
	__glReadBuffer =
		(PFNGLREADBUFFERPROC)LoadGLProc("glReadBuffer");
	__glReadPixels =
		(PFNGLREADPIXELSPROC)LoadGLProc("glReadPixels");
	__glReadnPixels =
		(PFNGLREADNPIXELSPROC)LoadGLProc("glReadnPixels");
	__glReleaseShaderCompiler =
		(PFNGLRELEASESHADERCOMPILERPROC)LoadGLProc("glReleaseShaderCompiler");
	__glRenderbufferStorage =
		(PFNGLRENDERBUFFERSTORAGEPROC)LoadGLProc("glRenderbufferStorage");
	__glRenderbufferStorageMultisample =
		(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)LoadGLProc("glRenderbufferStorageMultisample");
	__glResumeTransformFeedback =
		(PFNGLRESUMETRANSFORMFEEDBACKPROC)LoadGLProc("glResumeTransformFeedback");
	__glSampleCoverage =
		(PFNGLSAMPLECOVERAGEPROC)LoadGLProc("glSampleCoverage");
	__glSampleMaski =
		(PFNGLSAMPLEMASKIPROC)LoadGLProc("glSampleMaski");
	__glSamplerParameterIiv =
		(PFNGLSAMPLERPARAMETERIIVPROC)LoadGLProc("glSamplerParameterIiv");
	__glSamplerParameterIuiv =
		(PFNGLSAMPLERPARAMETERIUIVPROC)LoadGLProc("glSamplerParameterIuiv");
	__glSamplerParameterf =
		(PFNGLSAMPLERPARAMETERFPROC)LoadGLProc("glSamplerParameterf");
	__glSamplerParameterfv =
		(PFNGLSAMPLERPARAMETERFVPROC)LoadGLProc("glSamplerParameterfv");
	__glSamplerParameteri =
		(PFNGLSAMPLERPARAMETERIPROC)LoadGLProc("glSamplerParameteri");
	__glSamplerParameteriv =
		(PFNGLSAMPLERPARAMETERIVPROC)LoadGLProc("glSamplerParameteriv");
	__glScissor =
		(PFNGLSCISSORPROC)LoadGLProc("glScissor");
	__glScissorArrayv =
		(PFNGLSCISSORARRAYVPROC)LoadGLProc("glScissorArrayv");
	__glScissorIndexed =
		(PFNGLSCISSORINDEXEDPROC)LoadGLProc("glScissorIndexed");
	__glScissorIndexedv =
		(PFNGLSCISSORINDEXEDVPROC)LoadGLProc("glScissorIndexedv");
	__glShaderBinary =
		(PFNGLSHADERBINARYPROC)LoadGLProc("glShaderBinary");
	__glShaderSource =
		(PFNGLSHADERSOURCEPROC)LoadGLProc("glShaderSource");
	__glShaderStorageBlockBinding =
		(PFNGLSHADERSTORAGEBLOCKBINDINGPROC)LoadGLProc("glShaderStorageBlockBinding");
	__glSpecializeShader =
		(PFNGLSPECIALIZESHADERPROC)LoadGLProc("glSpecializeShader");
	__glStencilFunc =
		(PFNGLSTENCILFUNCPROC)LoadGLProc("glStencilFunc");
	__glStencilFuncSeparate =
		(PFNGLSTENCILFUNCSEPARATEPROC)LoadGLProc("glStencilFuncSeparate");
	__glStencilMask =
		(PFNGLSTENCILMASKPROC)LoadGLProc("glStencilMask");
	__glStencilMaskSeparate =
		(PFNGLSTENCILMASKSEPARATEPROC)LoadGLProc("glStencilMaskSeparate");
	__glStencilOp =
		(PFNGLSTENCILOPPROC)LoadGLProc("glStencilOp");
	__glStencilOpSeparate =
		(PFNGLSTENCILOPSEPARATEPROC)LoadGLProc("glStencilOpSeparate");
	__glTexBuffer =
		(PFNGLTEXBUFFERPROC)LoadGLProc("glTexBuffer");
	__glTexBufferRange =
		(PFNGLTEXBUFFERRANGEPROC)LoadGLProc("glTexBufferRange");
	__glTexImage1D =
		(PFNGLTEXIMAGE1DPROC)LoadGLProc("glTexImage1D");
	__glTexImage2D =
		(PFNGLTEXIMAGE2DPROC)LoadGLProc("glTexImage2D");
	__glTexImage2DMultisample =
		(PFNGLTEXIMAGE2DMULTISAMPLEPROC)LoadGLProc("glTexImage2DMultisample");
	__glTexImage3D =
		(PFNGLTEXIMAGE3DPROC)LoadGLProc("glTexImage3D");
	__glTexImage3DMultisample =
		(PFNGLTEXIMAGE3DMULTISAMPLEPROC)LoadGLProc("glTexImage3DMultisample");
	__glTexParameterIiv =
		(PFNGLTEXPARAMETERIIVPROC)LoadGLProc("glTexParameterIiv");
	__glTexParameterIuiv =
		(PFNGLTEXPARAMETERIUIVPROC)LoadGLProc("glTexParameterIuiv");
	__glTexParameterf =
		(PFNGLTEXPARAMETERFPROC)LoadGLProc("glTexParameterf");
	__glTexParameterfv =
		(PFNGLTEXPARAMETERFVPROC)LoadGLProc("glTexParameterfv");
	__glTexParameteri =
		(PFNGLTEXPARAMETERIPROC)LoadGLProc("glTexParameteri");
	__glTexParameteriv =
		(PFNGLTEXPARAMETERIVPROC)LoadGLProc("glTexParameteriv");
	__glTexStorage1D =
		(PFNGLTEXSTORAGE1DPROC)LoadGLProc("glTexStorage1D");
	__glTexStorage2D =
		(PFNGLTEXSTORAGE2DPROC)LoadGLProc("glTexStorage2D");
	__glTexStorage2DMultisample =
		(PFNGLTEXSTORAGE2DMULTISAMPLEPROC)LoadGLProc("glTexStorage2DMultisample");
	__glTexStorage3D =
		(PFNGLTEXSTORAGE3DPROC)LoadGLProc("glTexStorage3D");
	__glTexStorage3DMultisample =
		(PFNGLTEXSTORAGE3DMULTISAMPLEPROC)LoadGLProc("glTexStorage3DMultisample");
	__glTexSubImage1D =
		(PFNGLTEXSUBIMAGE1DPROC)LoadGLProc("glTexSubImage1D");
	__glTexSubImage2D =
		(PFNGLTEXSUBIMAGE2DPROC)LoadGLProc("glTexSubImage2D");
	__glTexSubImage3D =
		(PFNGLTEXSUBIMAGE3DPROC)LoadGLProc("glTexSubImage3D");
	__glTextureBarrier =
		(PFNGLTEXTUREBARRIERPROC)LoadGLProc("glTextureBarrier");
	__glTextureBuffer =
		(PFNGLTEXTUREBUFFERPROC)LoadGLProc("glTextureBuffer");
	__glTextureBufferRange =
		(PFNGLTEXTUREBUFFERRANGEPROC)LoadGLProc("glTextureBufferRange");
	__glTextureParameterIiv =
		(PFNGLTEXTUREPARAMETERIIVPROC)LoadGLProc("glTextureParameterIiv");
	__glTextureParameterIuiv =
		(PFNGLTEXTUREPARAMETERIUIVPROC)LoadGLProc("glTextureParameterIuiv");
	__glTextureParameterf =
		(PFNGLTEXTUREPARAMETERFPROC)LoadGLProc("glTextureParameterf");
	__glTextureParameterfv =
		(PFNGLTEXTUREPARAMETERFVPROC)LoadGLProc("glTextureParameterfv");
	__glTextureParameteri =
		(PFNGLTEXTUREPARAMETERIPROC)LoadGLProc("glTextureParameteri");
	__glTextureParameteriv =
		(PFNGLTEXTUREPARAMETERIVPROC)LoadGLProc("glTextureParameteriv");
	__glTextureStorage1D =
		(PFNGLTEXTURESTORAGE1DPROC)LoadGLProc("glTextureStorage1D");
	__glTextureStorage2D =
		(PFNGLTEXTURESTORAGE2DPROC)LoadGLProc("glTextureStorage2D");
	__glTextureStorage2DMultisample =
		(PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)LoadGLProc("glTextureStorage2DMultisample");
	__glTextureStorage3D =
		(PFNGLTEXTURESTORAGE3DPROC)LoadGLProc("glTextureStorage3D");
	__glTextureStorage3DMultisample =
		(PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)LoadGLProc("glTextureStorage3DMultisample");
	__glTextureSubImage1D =
		(PFNGLTEXTURESUBIMAGE1DPROC)LoadGLProc("glTextureSubImage1D");
	__glTextureSubImage2D =
		(PFNGLTEXTURESUBIMAGE2DPROC)LoadGLProc("glTextureSubImage2D");
	__glTextureSubImage3D =
		(PFNGLTEXTURESUBIMAGE3DPROC)LoadGLProc("glTextureSubImage3D");
	__glTextureView =
		(PFNGLTEXTUREVIEWPROC)LoadGLProc("glTextureView");
	__glTransformFeedbackBufferBase =
		(PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)LoadGLProc("glTransformFeedbackBufferBase");
	__glTransformFeedbackBufferRange =
		(PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)LoadGLProc("glTransformFeedbackBufferRange");
	__glTransformFeedbackVaryings =
		(PFNGLTRANSFORMFEEDBACKVARYINGSPROC)LoadGLProc("glTransformFeedbackVaryings");
	__glUniform1d =
		(PFNGLUNIFORM1DPROC)LoadGLProc("glUniform1d");
	__glUniform1dv =
		(PFNGLUNIFORM1DVPROC)LoadGLProc("glUniform1dv");
	__glUniform1f =
		(PFNGLUNIFORM1FPROC)LoadGLProc("glUniform1f");
	__glUniform1fv =
		(PFNGLUNIFORM1FVPROC)LoadGLProc("glUniform1fv");
	__glUniform1i =
		(PFNGLUNIFORM1IPROC)LoadGLProc("glUniform1i");
	__glUniform1iv =
		(PFNGLUNIFORM1IVPROC)LoadGLProc("glUniform1iv");
	__glUniform1ui =
		(PFNGLUNIFORM1UIPROC)LoadGLProc("glUniform1ui");
	__glUniform1uiv =
		(PFNGLUNIFORM1UIVPROC)LoadGLProc("glUniform1uiv");
	__glUniform2d =
		(PFNGLUNIFORM2DPROC)LoadGLProc("glUniform2d");
	__glUniform2dv =
		(PFNGLUNIFORM2DVPROC)LoadGLProc("glUniform2dv");
	__glUniform2f =
		(PFNGLUNIFORM2FPROC)LoadGLProc("glUniform2f");
	__glUniform2fv =
		(PFNGLUNIFORM2FVPROC)LoadGLProc("glUniform2fv");
	__glUniform2i =
		(PFNGLUNIFORM2IPROC)LoadGLProc("glUniform2i");
	__glUniform2iv =
		(PFNGLUNIFORM2IVPROC)LoadGLProc("glUniform2iv");
	__glUniform2ui =
		(PFNGLUNIFORM2UIPROC)LoadGLProc("glUniform2ui");
	__glUniform2uiv =
		(PFNGLUNIFORM2UIVPROC)LoadGLProc("glUniform2uiv");
	__glUniform3d =
		(PFNGLUNIFORM3DPROC)LoadGLProc("glUniform3d");
	__glUniform3dv =
		(PFNGLUNIFORM3DVPROC)LoadGLProc("glUniform3dv");
	__glUniform3f =
		(PFNGLUNIFORM3FPROC)LoadGLProc("glUniform3f");
	__glUniform3fv =
		(PFNGLUNIFORM3FVPROC)LoadGLProc("glUniform3fv");
	__glUniform3i =
		(PFNGLUNIFORM3IPROC)LoadGLProc("glUniform3i");
	__glUniform3iv =
		(PFNGLUNIFORM3IVPROC)LoadGLProc("glUniform3iv");
	__glUniform3ui =
		(PFNGLUNIFORM3UIPROC)LoadGLProc("glUniform3ui");
	__glUniform3uiv =
		(PFNGLUNIFORM3UIVPROC)LoadGLProc("glUniform3uiv");
	__glUniform4d =
		(PFNGLUNIFORM4DPROC)LoadGLProc("glUniform4d");
	__glUniform4dv =
		(PFNGLUNIFORM4DVPROC)LoadGLProc("glUniform4dv");
	__glUniform4f =
		(PFNGLUNIFORM4FPROC)LoadGLProc("glUniform4f");
	__glUniform4fv =
		(PFNGLUNIFORM4FVPROC)LoadGLProc("glUniform4fv");
	__glUniform4i =
		(PFNGLUNIFORM4IPROC)LoadGLProc("glUniform4i");
	__glUniform4iv =
		(PFNGLUNIFORM4IVPROC)LoadGLProc("glUniform4iv");
	__glUniform4ui =
		(PFNGLUNIFORM4UIPROC)LoadGLProc("glUniform4ui");
	__glUniform4uiv =
		(PFNGLUNIFORM4UIVPROC)LoadGLProc("glUniform4uiv");
	__glUniformBlockBinding =
		(PFNGLUNIFORMBLOCKBINDINGPROC)LoadGLProc("glUniformBlockBinding");
	__glUniformMatrix2dv =
		(PFNGLUNIFORMMATRIX2DVPROC)LoadGLProc("glUniformMatrix2dv");
	__glUniformMatrix2fv =
		(PFNGLUNIFORMMATRIX2FVPROC)LoadGLProc("glUniformMatrix2fv");
	__glUniformMatrix2x3dv =
		(PFNGLUNIFORMMATRIX2X3DVPROC)LoadGLProc("glUniformMatrix2x3dv");
	__glUniformMatrix2x3fv =
		(PFNGLUNIFORMMATRIX2X3FVPROC)LoadGLProc("glUniformMatrix2x3fv");
	__glUniformMatrix2x4dv =
		(PFNGLUNIFORMMATRIX2X4DVPROC)LoadGLProc("glUniformMatrix2x4dv");
	__glUniformMatrix2x4fv =
		(PFNGLUNIFORMMATRIX2X4FVPROC)LoadGLProc("glUniformMatrix2x4fv");
	__glUniformMatrix3dv =
		(PFNGLUNIFORMMATRIX3DVPROC)LoadGLProc("glUniformMatrix3dv");
	__glUniformMatrix3fv =
		(PFNGLUNIFORMMATRIX3FVPROC)LoadGLProc("glUniformMatrix3fv");
	__glUniformMatrix3x2dv =
		(PFNGLUNIFORMMATRIX3X2DVPROC)LoadGLProc("glUniformMatrix3x2dv");
	__glUniformMatrix3x2fv =
		(PFNGLUNIFORMMATRIX3X2FVPROC)LoadGLProc("glUniformMatrix3x2fv");
	__glUniformMatrix3x4dv =
		(PFNGLUNIFORMMATRIX3X4DVPROC)LoadGLProc("glUniformMatrix3x4dv");
	__glUniformMatrix3x4fv =
		(PFNGLUNIFORMMATRIX3X4FVPROC)LoadGLProc("glUniformMatrix3x4fv");
	__glUniformMatrix4dv =
		(PFNGLUNIFORMMATRIX4DVPROC)LoadGLProc("glUniformMatrix4dv");
	__glUniformMatrix4fv =
		(PFNGLUNIFORMMATRIX4FVPROC)LoadGLProc("glUniformMatrix4fv");
	__glUniformMatrix4x2dv =
		(PFNGLUNIFORMMATRIX4X2DVPROC)LoadGLProc("glUniformMatrix4x2dv");
	__glUniformMatrix4x2fv =
		(PFNGLUNIFORMMATRIX4X2FVPROC)LoadGLProc("glUniformMatrix4x2fv");
	__glUniformMatrix4x3dv =
		(PFNGLUNIFORMMATRIX4X3DVPROC)LoadGLProc("glUniformMatrix4x3dv");
	__glUniformMatrix4x3fv =
		(PFNGLUNIFORMMATRIX4X3FVPROC)LoadGLProc("glUniformMatrix4x3fv");
	__glUniformSubroutinesuiv =
		(PFNGLUNIFORMSUBROUTINESUIVPROC)LoadGLProc("glUniformSubroutinesuiv");
	__glUnmapBuffer =
		(PFNGLUNMAPBUFFERPROC)LoadGLProc("glUnmapBuffer");
	__glUnmapNamedBuffer =
		(PFNGLUNMAPNAMEDBUFFERPROC)LoadGLProc("glUnmapNamedBuffer");
	__glUseProgram =
		(PFNGLUSEPROGRAMPROC)LoadGLProc("glUseProgram");
	__glUseProgramStages =
		(PFNGLUSEPROGRAMSTAGESPROC)LoadGLProc("glUseProgramStages");
	__glValidateProgram =
		(PFNGLVALIDATEPROGRAMPROC)LoadGLProc("glValidateProgram");
	__glValidateProgramPipeline =
		(PFNGLVALIDATEPROGRAMPIPELINEPROC)LoadGLProc("glValidateProgramPipeline");
	__glVertexArrayAttribBinding =
		(PFNGLVERTEXARRAYATTRIBBINDINGPROC)LoadGLProc("glVertexArrayAttribBinding");
	__glVertexArrayAttribFormat =
		(PFNGLVERTEXARRAYATTRIBFORMATPROC)LoadGLProc("glVertexArrayAttribFormat");
	__glVertexArrayAttribIFormat =
		(PFNGLVERTEXARRAYATTRIBIFORMATPROC)LoadGLProc("glVertexArrayAttribIFormat");
	__glVertexArrayAttribLFormat =
		(PFNGLVERTEXARRAYATTRIBLFORMATPROC)LoadGLProc("glVertexArrayAttribLFormat");
	__glVertexArrayBindingDivisor =
		(PFNGLVERTEXARRAYBINDINGDIVISORPROC)LoadGLProc("glVertexArrayBindingDivisor");
	__glVertexArrayElementBuffer =
		(PFNGLVERTEXARRAYELEMENTBUFFERPROC)LoadGLProc("glVertexArrayElementBuffer");
	__glVertexArrayVertexBuffer =
		(PFNGLVERTEXARRAYVERTEXBUFFERPROC)LoadGLProc("glVertexArrayVertexBuffer");
	__glVertexArrayVertexBuffers =
		(PFNGLVERTEXARRAYVERTEXBUFFERSPROC)LoadGLProc("glVertexArrayVertexBuffers");
	__glVertexAttrib1d =
		(PFNGLVERTEXATTRIB1DPROC)LoadGLProc("glVertexAttrib1d");
	__glVertexAttrib1dv =
		(PFNGLVERTEXATTRIB1DVPROC)LoadGLProc("glVertexAttrib1dv");
	__glVertexAttrib1f =
		(PFNGLVERTEXATTRIB1FPROC)LoadGLProc("glVertexAttrib1f");
	__glVertexAttrib1fv =
		(PFNGLVERTEXATTRIB1FVPROC)LoadGLProc("glVertexAttrib1fv");
	__glVertexAttrib1s =
		(PFNGLVERTEXATTRIB1SPROC)LoadGLProc("glVertexAttrib1s");
	__glVertexAttrib1sv =
		(PFNGLVERTEXATTRIB1SVPROC)LoadGLProc("glVertexAttrib1sv");
	__glVertexAttrib2d =
		(PFNGLVERTEXATTRIB2DPROC)LoadGLProc("glVertexAttrib2d");
	__glVertexAttrib2dv =
		(PFNGLVERTEXATTRIB2DVPROC)LoadGLProc("glVertexAttrib2dv");
	__glVertexAttrib2f =
		(PFNGLVERTEXATTRIB2FPROC)LoadGLProc("glVertexAttrib2f");
	__glVertexAttrib2fv =
		(PFNGLVERTEXATTRIB2FVPROC)LoadGLProc("glVertexAttrib2fv");
	__glVertexAttrib2s =
		(PFNGLVERTEXATTRIB2SPROC)LoadGLProc("glVertexAttrib2s");
	__glVertexAttrib2sv =
		(PFNGLVERTEXATTRIB2SVPROC)LoadGLProc("glVertexAttrib2sv");
	__glVertexAttrib3d =
		(PFNGLVERTEXATTRIB3DPROC)LoadGLProc("glVertexAttrib3d");
	__glVertexAttrib3dv =
		(PFNGLVERTEXATTRIB3DVPROC)LoadGLProc("glVertexAttrib3dv");
	__glVertexAttrib3f =
		(PFNGLVERTEXATTRIB3FPROC)LoadGLProc("glVertexAttrib3f");
	__glVertexAttrib3fv =
		(PFNGLVERTEXATTRIB3FVPROC)LoadGLProc("glVertexAttrib3fv");
	__glVertexAttrib3s =
		(PFNGLVERTEXATTRIB3SPROC)LoadGLProc("glVertexAttrib3s");
	__glVertexAttrib3sv =
		(PFNGLVERTEXATTRIB3SVPROC)LoadGLProc("glVertexAttrib3sv");
	__glVertexAttrib4Nbv =
		(PFNGLVERTEXATTRIB4NBVPROC)LoadGLProc("glVertexAttrib4Nbv");
	__glVertexAttrib4Niv =
		(PFNGLVERTEXATTRIB4NIVPROC)LoadGLProc("glVertexAttrib4Niv");
	__glVertexAttrib4Nsv =
		(PFNGLVERTEXATTRIB4NSVPROC)LoadGLProc("glVertexAttrib4Nsv");
	__glVertexAttrib4Nub =
		(PFNGLVERTEXATTRIB4NUBPROC)LoadGLProc("glVertexAttrib4Nub");
	__glVertexAttrib4Nubv =
		(PFNGLVERTEXATTRIB4NUBVPROC)LoadGLProc("glVertexAttrib4Nubv");
	__glVertexAttrib4Nuiv =
		(PFNGLVERTEXATTRIB4NUIVPROC)LoadGLProc("glVertexAttrib4Nuiv");
	__glVertexAttrib4Nusv =
		(PFNGLVERTEXATTRIB4NUSVPROC)LoadGLProc("glVertexAttrib4Nusv");
	__glVertexAttrib4bv =
		(PFNGLVERTEXATTRIB4BVPROC)LoadGLProc("glVertexAttrib4bv");
	__glVertexAttrib4d =
		(PFNGLVERTEXATTRIB4DPROC)LoadGLProc("glVertexAttrib4d");
	__glVertexAttrib4dv =
		(PFNGLVERTEXATTRIB4DVPROC)LoadGLProc("glVertexAttrib4dv");
	__glVertexAttrib4f =
		(PFNGLVERTEXATTRIB4FPROC)LoadGLProc("glVertexAttrib4f");
	__glVertexAttrib4fv =
		(PFNGLVERTEXATTRIB4FVPROC)LoadGLProc("glVertexAttrib4fv");
	__glVertexAttrib4iv =
		(PFNGLVERTEXATTRIB4IVPROC)LoadGLProc("glVertexAttrib4iv");
	__glVertexAttrib4s =
		(PFNGLVERTEXATTRIB4SPROC)LoadGLProc("glVertexAttrib4s");
	__glVertexAttrib4sv =
		(PFNGLVERTEXATTRIB4SVPROC)LoadGLProc("glVertexAttrib4sv");
	__glVertexAttrib4ubv =
		(PFNGLVERTEXATTRIB4UBVPROC)LoadGLProc("glVertexAttrib4ubv");
	__glVertexAttrib4uiv =
		(PFNGLVERTEXATTRIB4UIVPROC)LoadGLProc("glVertexAttrib4uiv");
	__glVertexAttrib4usv =
		(PFNGLVERTEXATTRIB4USVPROC)LoadGLProc("glVertexAttrib4usv");
	__glVertexAttribBinding =
		(PFNGLVERTEXATTRIBBINDINGPROC)LoadGLProc("glVertexAttribBinding");
	__glVertexAttribDivisor =
		(PFNGLVERTEXATTRIBDIVISORPROC)LoadGLProc("glVertexAttribDivisor");
	__glVertexAttribFormat =
		(PFNGLVERTEXATTRIBFORMATPROC)LoadGLProc("glVertexAttribFormat");
	__glVertexAttribI1i =
		(PFNGLVERTEXATTRIBI1IPROC)LoadGLProc("glVertexAttribI1i");
	__glVertexAttribI1iv =
		(PFNGLVERTEXATTRIBI1IVPROC)LoadGLProc("glVertexAttribI1iv");
	__glVertexAttribI1ui =
		(PFNGLVERTEXATTRIBI1UIPROC)LoadGLProc("glVertexAttribI1ui");
	__glVertexAttribI1uiv =
		(PFNGLVERTEXATTRIBI1UIVPROC)LoadGLProc("glVertexAttribI1uiv");
	__glVertexAttribI2i =
		(PFNGLVERTEXATTRIBI2IPROC)LoadGLProc("glVertexAttribI2i");
	__glVertexAttribI2iv =
		(PFNGLVERTEXATTRIBI2IVPROC)LoadGLProc("glVertexAttribI2iv");
	__glVertexAttribI2ui =
		(PFNGLVERTEXATTRIBI2UIPROC)LoadGLProc("glVertexAttribI2ui");
	__glVertexAttribI2uiv =
		(PFNGLVERTEXATTRIBI2UIVPROC)LoadGLProc("glVertexAttribI2uiv");
	__glVertexAttribI3i =
		(PFNGLVERTEXATTRIBI3IPROC)LoadGLProc("glVertexAttribI3i");
	__glVertexAttribI3iv =
		(PFNGLVERTEXATTRIBI3IVPROC)LoadGLProc("glVertexAttribI3iv");
	__glVertexAttribI3ui =
		(PFNGLVERTEXATTRIBI3UIPROC)LoadGLProc("glVertexAttribI3ui");
	__glVertexAttribI3uiv =
		(PFNGLVERTEXATTRIBI3UIVPROC)LoadGLProc("glVertexAttribI3uiv");
	__glVertexAttribI4bv =
		(PFNGLVERTEXATTRIBI4BVPROC)LoadGLProc("glVertexAttribI4bv");
	__glVertexAttribI4i =
		(PFNGLVERTEXATTRIBI4IPROC)LoadGLProc("glVertexAttribI4i");
	__glVertexAttribI4iv =
		(PFNGLVERTEXATTRIBI4IVPROC)LoadGLProc("glVertexAttribI4iv");
	__glVertexAttribI4sv =
		(PFNGLVERTEXATTRIBI4SVPROC)LoadGLProc("glVertexAttribI4sv");
	__glVertexAttribI4ubv =
		(PFNGLVERTEXATTRIBI4UBVPROC)LoadGLProc("glVertexAttribI4ubv");
	__glVertexAttribI4ui =
		(PFNGLVERTEXATTRIBI4UIPROC)LoadGLProc("glVertexAttribI4ui");
	__glVertexAttribI4uiv =
		(PFNGLVERTEXATTRIBI4UIVPROC)LoadGLProc("glVertexAttribI4uiv");
	__glVertexAttribI4usv =
		(PFNGLVERTEXATTRIBI4USVPROC)LoadGLProc("glVertexAttribI4usv");
	__glVertexAttribIFormat =
		(PFNGLVERTEXATTRIBIFORMATPROC)LoadGLProc("glVertexAttribIFormat");
	__glVertexAttribIPointer =
		(PFNGLVERTEXATTRIBIPOINTERPROC)LoadGLProc("glVertexAttribIPointer");
	__glVertexAttribL1d =
		(PFNGLVERTEXATTRIBL1DPROC)LoadGLProc("glVertexAttribL1d");
	__glVertexAttribL1dv =
		(PFNGLVERTEXATTRIBL1DVPROC)LoadGLProc("glVertexAttribL1dv");
	__glVertexAttribL2d =
		(PFNGLVERTEXATTRIBL2DPROC)LoadGLProc("glVertexAttribL2d");
	__glVertexAttribL2dv =
		(PFNGLVERTEXATTRIBL2DVPROC)LoadGLProc("glVertexAttribL2dv");
	__glVertexAttribL3d =
		(PFNGLVERTEXATTRIBL3DPROC)LoadGLProc("glVertexAttribL3d");
	__glVertexAttribL3dv =
		(PFNGLVERTEXATTRIBL3DVPROC)LoadGLProc("glVertexAttribL3dv");
	__glVertexAttribL4d =
		(PFNGLVERTEXATTRIBL4DPROC)LoadGLProc("glVertexAttribL4d");
	__glVertexAttribL4dv =
		(PFNGLVERTEXATTRIBL4DVPROC)LoadGLProc("glVertexAttribL4dv");
	__glVertexAttribLFormat =
		(PFNGLVERTEXATTRIBLFORMATPROC)LoadGLProc("glVertexAttribLFormat");
	__glVertexAttribLPointer =
		(PFNGLVERTEXATTRIBLPOINTERPROC)LoadGLProc("glVertexAttribLPointer");
	__glVertexAttribP1ui =
		(PFNGLVERTEXATTRIBP1UIPROC)LoadGLProc("glVertexAttribP1ui");
	__glVertexAttribP1uiv =
		(PFNGLVERTEXATTRIBP1UIVPROC)LoadGLProc("glVertexAttribP1uiv");
	__glVertexAttribP2ui =
		(PFNGLVERTEXATTRIBP2UIPROC)LoadGLProc("glVertexAttribP2ui");
	__glVertexAttribP2uiv =
		(PFNGLVERTEXATTRIBP2UIVPROC)LoadGLProc("glVertexAttribP2uiv");
	__glVertexAttribP3ui =
		(PFNGLVERTEXATTRIBP3UIPROC)LoadGLProc("glVertexAttribP3ui");
	__glVertexAttribP3uiv =
		(PFNGLVERTEXATTRIBP3UIVPROC)LoadGLProc("glVertexAttribP3uiv");
	__glVertexAttribP4ui =
		(PFNGLVERTEXATTRIBP4UIPROC)LoadGLProc("glVertexAttribP4ui");
	__glVertexAttribP4uiv =
		(PFNGLVERTEXATTRIBP4UIVPROC)LoadGLProc("glVertexAttribP4uiv");
	__glVertexAttribPointer =
		(PFNGLVERTEXATTRIBPOINTERPROC)LoadGLProc("glVertexAttribPointer");
	__glVertexBindingDivisor =
		(PFNGLVERTEXBINDINGDIVISORPROC)LoadGLProc("glVertexBindingDivisor");
	__glViewport =
		(PFNGLVIEWPORTPROC)LoadGLProc("glViewport");
	__glViewportArrayv =
		(PFNGLVIEWPORTARRAYVPROC)LoadGLProc("glViewportArrayv");
	__glViewportIndexedf =
		(PFNGLVIEWPORTINDEXEDFPROC)LoadGLProc("glViewportIndexedf");
	__glViewportIndexedfv =
		(PFNGLVIEWPORTINDEXEDFVPROC)LoadGLProc("glViewportIndexedfv");
	__glWaitSync =
		(PFNGLWAITSYNCPROC)LoadGLProc("glWaitSync");

	GLLoaded = TRUE;

Exit:

	return(Error);
}

PFNGLACTIVESHADERPROGRAMPROC                            __glActiveShaderProgram;
PFNGLACTIVETEXTUREPROC                                  __glActiveTexture;
PFNGLATTACHSHADERPROC                                   __glAttachShader;
PFNGLBEGINCONDITIONALRENDERPROC                         __glBeginConditionalRender;
PFNGLBEGINQUERYPROC                                     __glBeginQuery;
PFNGLBEGINQUERYINDEXEDPROC                              __glBeginQueryIndexed;
PFNGLBEGINTRANSFORMFEEDBACKPROC                         __glBeginTransformFeedback;
PFNGLBINDATTRIBLOCATIONPROC                             __glBindAttribLocation;
PFNGLBINDBUFFERPROC                                     __glBindBuffer;
PFNGLBINDBUFFERBASEPROC                                 __glBindBufferBase;
PFNGLBINDBUFFERRANGEPROC                                __glBindBufferRange;
PFNGLBINDBUFFERSBASEPROC                                __glBindBuffersBase;
PFNGLBINDBUFFERSRANGEPROC                               __glBindBuffersRange;
PFNGLBINDFRAGDATALOCATIONPROC                           __glBindFragDataLocation;
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC                    __glBindFragDataLocationIndexed;
PFNGLBINDFRAMEBUFFERPROC                                __glBindFramebuffer;
PFNGLBINDIMAGETEXTUREPROC                               __glBindImageTexture;
PFNGLBINDIMAGETEXTURESPROC                              __glBindImageTextures;
PFNGLBINDPROGRAMPIPELINEPROC                            __glBindProgramPipeline;
PFNGLBINDRENDERBUFFERPROC                               __glBindRenderbuffer;
PFNGLBINDSAMPLERPROC                                    __glBindSampler;
PFNGLBINDSAMPLERSPROC                                   __glBindSamplers;
PFNGLBINDTEXTUREPROC                                    __glBindTexture;
PFNGLBINDTEXTUREUNITPROC                                __glBindTextureUnit;
PFNGLBINDTEXTURESPROC                                   __glBindTextures;
PFNGLBINDTRANSFORMFEEDBACKPROC                          __glBindTransformFeedback;
PFNGLBINDVERTEXARRAYPROC                                __glBindVertexArray;
PFNGLBINDVERTEXBUFFERPROC                               __glBindVertexBuffer;
PFNGLBINDVERTEXBUFFERSPROC                              __glBindVertexBuffers;
PFNGLBLENDCOLORPROC                                     __glBlendColor;
PFNGLBLENDEQUATIONPROC                                  __glBlendEquation;
PFNGLBLENDEQUATIONSEPARATEPROC                          __glBlendEquationSeparate;
PFNGLBLENDEQUATIONSEPARATEIPROC                         __glBlendEquationSeparatei;
PFNGLBLENDEQUATIONIPROC                                 __glBlendEquationi;
PFNGLBLENDFUNCPROC                                      __glBlendFunc;
PFNGLBLENDFUNCSEPARATEPROC                              __glBlendFuncSeparate;
PFNGLBLENDFUNCSEPARATEIPROC                             __glBlendFuncSeparatei;
PFNGLBLENDFUNCIPROC                                     __glBlendFunci;
PFNGLBLITFRAMEBUFFERPROC                                __glBlitFramebuffer;
PFNGLBLITNAMEDFRAMEBUFFERPROC                           __glBlitNamedFramebuffer;
PFNGLBUFFERDATAPROC                                     __glBufferData;
PFNGLBUFFERSTORAGEPROC                                  __glBufferStorage;
PFNGLBUFFERSUBDATAPROC                                  __glBufferSubData;
PFNGLCHECKFRAMEBUFFERSTATUSPROC                         __glCheckFramebufferStatus;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC                    __glCheckNamedFramebufferStatus;
PFNGLCLAMPCOLORPROC                                     __glClampColor;
PFNGLCLEARPROC                                          __glClear;
PFNGLCLEARBUFFERDATAPROC                                __glClearBufferData;
PFNGLCLEARBUFFERSUBDATAPROC                             __glClearBufferSubData;
PFNGLCLEARBUFFERFIPROC                                  __glClearBufferfi;
PFNGLCLEARBUFFERFVPROC                                  __glClearBufferfv;
PFNGLCLEARBUFFERIVPROC                                  __glClearBufferiv;
PFNGLCLEARBUFFERUIVPROC                                 __glClearBufferuiv;
PFNGLCLEARCOLORPROC                                     __glClearColor;
PFNGLCLEARDEPTHPROC                                     __glClearDepth;
PFNGLCLEARDEPTHFPROC                                    __glClearDepthf;
PFNGLCLEARNAMEDBUFFERDATAPROC                           __glClearNamedBufferData;
PFNGLCLEARNAMEDBUFFERSUBDATAPROC                        __glClearNamedBufferSubData;
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC                        __glClearNamedFramebufferfi;
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC                        __glClearNamedFramebufferfv;
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC                        __glClearNamedFramebufferiv;
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC                       __glClearNamedFramebufferuiv;
PFNGLCLEARSTENCILPROC                                   __glClearStencil;
PFNGLCLEARTEXIMAGEPROC                                  __glClearTexImage;
PFNGLCLEARTEXSUBIMAGEPROC                               __glClearTexSubImage;
PFNGLCLIENTWAITSYNCPROC                                 __glClientWaitSync;
PFNGLCLIPCONTROLPROC                                    __glClipControl;
PFNGLCOLORMASKPROC                                      __glColorMask;
PFNGLCOLORMASKIPROC                                     __glColorMaski;
PFNGLCOMPILESHADERPROC                                  __glCompileShader;
PFNGLCOMPRESSEDTEXIMAGE1DPROC                           __glCompressedTexImage1D;
PFNGLCOMPRESSEDTEXIMAGE2DPROC                           __glCompressedTexImage2D;
PFNGLCOMPRESSEDTEXIMAGE3DPROC                           __glCompressedTexImage3D;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                        __glCompressedTexSubImage1D;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                        __glCompressedTexSubImage2D;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                        __glCompressedTexSubImage3D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC                    __glCompressedTextureSubImage1D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC                    __glCompressedTextureSubImage2D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC                    __glCompressedTextureSubImage3D;
PFNGLCOPYBUFFERSUBDATAPROC                              __glCopyBufferSubData;
PFNGLCOPYIMAGESUBDATAPROC                               __glCopyImageSubData;
PFNGLCOPYNAMEDBUFFERSUBDATAPROC                         __glCopyNamedBufferSubData;
PFNGLCOPYTEXIMAGE1DPROC                                 __glCopyTexImage1D;
PFNGLCOPYTEXIMAGE2DPROC                                 __glCopyTexImage2D;
PFNGLCOPYTEXSUBIMAGE1DPROC                              __glCopyTexSubImage1D;
PFNGLCOPYTEXSUBIMAGE2DPROC                              __glCopyTexSubImage2D;
PFNGLCOPYTEXSUBIMAGE3DPROC                              __glCopyTexSubImage3D;
PFNGLCOPYTEXTURESUBIMAGE1DPROC                          __glCopyTextureSubImage1D;
PFNGLCOPYTEXTURESUBIMAGE2DPROC                          __glCopyTextureSubImage2D;
PFNGLCOPYTEXTURESUBIMAGE3DPROC                          __glCopyTextureSubImage3D;
PFNGLCREATEBUFFERSPROC                                  __glCreateBuffers;
PFNGLCREATEFRAMEBUFFERSPROC                             __glCreateFramebuffers;
PFNGLCREATEPROGRAMPROC                                  __glCreateProgram;
PFNGLCREATEPROGRAMPIPELINESPROC                         __glCreateProgramPipelines;
PFNGLCREATEQUERIESPROC                                  __glCreateQueries;
PFNGLCREATERENDERBUFFERSPROC                            __glCreateRenderbuffers;
PFNGLCREATESAMPLERSPROC                                 __glCreateSamplers;
PFNGLCREATESHADERPROC                                   __glCreateShader;
PFNGLCREATESHADERPROGRAMVPROC                           __glCreateShaderProgramv;
PFNGLCREATETEXTURESPROC                                 __glCreateTextures;
PFNGLCREATETRANSFORMFEEDBACKSPROC                       __glCreateTransformFeedbacks;
PFNGLCREATEVERTEXARRAYSPROC                             __glCreateVertexArrays;
PFNGLCULLFACEPROC                                       __glCullFace;
PFNGLDEBUGMESSAGECALLBACKPROC                           __glDebugMessageCallback;
PFNGLDEBUGMESSAGECONTROLPROC                            __glDebugMessageControl;
PFNGLDEBUGMESSAGEINSERTPROC                             __glDebugMessageInsert;
PFNGLDELETEBUFFERSPROC                                  __glDeleteBuffers;
PFNGLDELETEFRAMEBUFFERSPROC                             __glDeleteFramebuffers;
PFNGLDELETEPROGRAMPROC                                  __glDeleteProgram;
PFNGLDELETEPROGRAMPIPELINESPROC                         __glDeleteProgramPipelines;
PFNGLDELETEQUERIESPROC                                  __glDeleteQueries;
PFNGLDELETERENDERBUFFERSPROC                            __glDeleteRenderbuffers;
PFNGLDELETESAMPLERSPROC                                 __glDeleteSamplers;
PFNGLDELETESHADERPROC                                   __glDeleteShader;
PFNGLDELETESYNCPROC                                     __glDeleteSync;
PFNGLDELETETEXTURESPROC                                 __glDeleteTextures;
PFNGLDELETETRANSFORMFEEDBACKSPROC                       __glDeleteTransformFeedbacks;
PFNGLDELETEVERTEXARRAYSPROC                             __glDeleteVertexArrays;
PFNGLDEPTHFUNCPROC                                      __glDepthFunc;
PFNGLDEPTHMASKPROC                                      __glDepthMask;
PFNGLDEPTHRANGEPROC                                     __glDepthRange;
PFNGLDEPTHRANGEARRAYVPROC                               __glDepthRangeArrayv;
PFNGLDEPTHRANGEINDEXEDPROC                              __glDepthRangeIndexed;
PFNGLDEPTHRANGEFPROC                                    __glDepthRangef;
PFNGLDETACHSHADERPROC                                   __glDetachShader;
PFNGLDISABLEPROC                                        __glDisable;
PFNGLDISABLEVERTEXARRAYATTRIBPROC                       __glDisableVertexArrayAttrib;
PFNGLDISABLEVERTEXATTRIBARRAYPROC                       __glDisableVertexAttribArray;
PFNGLDISABLEIPROC                                       __glDisablei;
PFNGLDISPATCHCOMPUTEPROC                                __glDispatchCompute;
PFNGLDISPATCHCOMPUTEINDIRECTPROC                        __glDispatchComputeIndirect;
PFNGLDRAWARRAYSPROC                                     __glDrawArrays;
PFNGLDRAWARRAYSINDIRECTPROC                             __glDrawArraysIndirect;
PFNGLDRAWARRAYSINSTANCEDPROC                            __glDrawArraysInstanced;
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC                __glDrawArraysInstancedBaseInstance;
PFNGLDRAWBUFFERPROC                                     __glDrawBuffer;
PFNGLDRAWBUFFERSPROC                                    __glDrawBuffers;
PFNGLDRAWELEMENTSPROC                                   __glDrawElements;
PFNGLDRAWELEMENTSBASEVERTEXPROC                         __glDrawElementsBaseVertex;
PFNGLDRAWELEMENTSINDIRECTPROC                           __glDrawElementsIndirect;
PFNGLDRAWELEMENTSINSTANCEDPROC                          __glDrawElementsInstanced;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC              __glDrawElementsInstancedBaseInstance;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC                __glDrawElementsInstancedBaseVertex;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC    __glDrawElementsInstancedBaseVertexBaseInstance;
PFNGLDRAWRANGEELEMENTSPROC                              __glDrawRangeElements;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC                    __glDrawRangeElementsBaseVertex;
PFNGLDRAWTRANSFORMFEEDBACKPROC                          __glDrawTransformFeedback;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC                 __glDrawTransformFeedbackInstanced;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC                    __glDrawTransformFeedbackStream;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC           __glDrawTransformFeedbackStreamInstanced;
PFNGLENABLEPROC                                         __glEnable;
PFNGLENABLEVERTEXARRAYATTRIBPROC                        __glEnableVertexArrayAttrib;
PFNGLENABLEVERTEXATTRIBARRAYPROC                        __glEnableVertexAttribArray;
PFNGLENABLEIPROC                                        __glEnablei;
PFNGLENDCONDITIONALRENDERPROC                           __glEndConditionalRender;
PFNGLENDQUERYPROC                                       __glEndQuery;
PFNGLENDQUERYINDEXEDPROC                                __glEndQueryIndexed;
PFNGLENDTRANSFORMFEEDBACKPROC                           __glEndTransformFeedback;
PFNGLFENCESYNCPROC                                      __glFenceSync;
PFNGLFINISHPROC                                         __glFinish;
PFNGLFLUSHPROC                                          __glFlush;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC                         __glFlushMappedBufferRange;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC                    __glFlushMappedNamedBufferRange;
PFNGLFRAMEBUFFERPARAMETERIPROC                          __glFramebufferParameteri;
PFNGLFRAMEBUFFERPARAMETERIMESAPROC                      __glFramebufferParameteriMESA;
PFNGLFRAMEBUFFERRENDERBUFFERPROC                        __glFramebufferRenderbuffer;
PFNGLFRAMEBUFFERTEXTUREPROC                             __glFramebufferTexture;
PFNGLFRAMEBUFFERTEXTURE1DPROC                           __glFramebufferTexture1D;
PFNGLFRAMEBUFFERTEXTURE2DPROC                           __glFramebufferTexture2D;
PFNGLFRAMEBUFFERTEXTURE3DPROC                           __glFramebufferTexture3D;
PFNGLFRAMEBUFFERTEXTURELAYERPROC                        __glFramebufferTextureLayer;
PFNGLFRONTFACEPROC                                      __glFrontFace;
PFNGLGENBUFFERSPROC                                     __glGenBuffers;
PFNGLGENFRAMEBUFFERSPROC                                __glGenFramebuffers;
PFNGLGENPROGRAMPIPELINESPROC                            __glGenProgramPipelines;
PFNGLGENQUERIESPROC                                     __glGenQueries;
PFNGLGENRENDERBUFFERSPROC                               __glGenRenderbuffers;
PFNGLGENSAMPLERSPROC                                    __glGenSamplers;
PFNGLGENTEXTURESPROC                                    __glGenTextures;
PFNGLGENTRANSFORMFEEDBACKSPROC                          __glGenTransformFeedbacks;
PFNGLGENVERTEXARRAYSPROC                                __glGenVertexArrays;
PFNGLGENERATEMIPMAPPROC                                 __glGenerateMipmap;
PFNGLGENERATETEXTUREMIPMAPPROC                          __glGenerateTextureMipmap;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC                 __glGetActiveAtomicCounterBufferiv;
PFNGLGETACTIVEATTRIBPROC                                __glGetActiveAttrib;
PFNGLGETACTIVESUBROUTINENAMEPROC                        __glGetActiveSubroutineName;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC                 __glGetActiveSubroutineUniformName;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC                   __glGetActiveSubroutineUniformiv;
PFNGLGETACTIVEUNIFORMPROC                               __glGetActiveUniform;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC                      __glGetActiveUniformBlockName;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC                        __glGetActiveUniformBlockiv;
PFNGLGETACTIVEUNIFORMNAMEPROC                           __glGetActiveUniformName;
PFNGLGETACTIVEUNIFORMSIVPROC                            __glGetActiveUniformsiv;
PFNGLGETATTACHEDSHADERSPROC                             __glGetAttachedShaders;
PFNGLGETATTRIBLOCATIONPROC                              __glGetAttribLocation;
PFNGLGETBOOLEANI_VPROC                                  __glGetBooleani_v;
PFNGLGETBOOLEANVPROC                                    __glGetBooleanv;
PFNGLGETBUFFERPARAMETERI64VPROC                         __glGetBufferParameteri64v;
PFNGLGETBUFFERPARAMETERIVPROC                           __glGetBufferParameteriv;
PFNGLGETBUFFERPOINTERVPROC                              __glGetBufferPointerv;
PFNGLGETBUFFERSUBDATAPROC                               __glGetBufferSubData;
PFNGLGETCOMPRESSEDTEXIMAGEPROC                          __glGetCompressedTexImage;
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC                      __glGetCompressedTextureImage;
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC                   __glGetCompressedTextureSubImage;
PFNGLGETDEBUGMESSAGELOGPROC                             __glGetDebugMessageLog;
PFNGLGETDOUBLEI_VPROC                                   __glGetDoublei_v;
PFNGLGETDOUBLEVPROC                                     __glGetDoublev;
PFNGLGETERRORPROC                                       __glGetError;
PFNGLGETFLOATI_VPROC                                    __glGetFloati_v;
PFNGLGETFLOATVPROC                                      __glGetFloatv;
PFNGLGETFRAGDATAINDEXPROC                               __glGetFragDataIndex;
PFNGLGETFRAGDATALOCATIONPROC                            __glGetFragDataLocation;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC            __glGetFramebufferAttachmentParameteriv;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC                      __glGetFramebufferParameteriv;
PFNGLGETFRAMEBUFFERPARAMETERIVMESAPROC                  __glGetFramebufferParameterivMESA;
PFNGLGETGRAPHICSRESETSTATUSPROC                         __glGetGraphicsResetStatus;
PFNGLGETINTEGER64I_VPROC                                __glGetInteger64i_v;
PFNGLGETINTEGER64VPROC                                  __glGetInteger64v;
PFNGLGETINTEGERI_VPROC                                  __glGetIntegeri_v;
PFNGLGETINTEGERVPROC                                    __glGetIntegerv;
PFNGLGETINTERNALFORMATI64VPROC                          __glGetInternalformati64v;
PFNGLGETINTERNALFORMATIVPROC                            __glGetInternalformativ;
PFNGLGETMULTISAMPLEFVPROC                               __glGetMultisamplefv;
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC                    __glGetNamedBufferParameteri64v;
PFNGLGETNAMEDBUFFERPARAMETERIVPROC                      __glGetNamedBufferParameteriv;
PFNGLGETNAMEDBUFFERPOINTERVPROC                         __glGetNamedBufferPointerv;
PFNGLGETNAMEDBUFFERSUBDATAPROC                          __glGetNamedBufferSubData;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC       __glGetNamedFramebufferAttachmentParameteriv;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC                 __glGetNamedFramebufferParameteriv;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC                __glGetNamedRenderbufferParameteriv;
PFNGLGETOBJECTLABELPROC                                 __glGetObjectLabel;
PFNGLGETOBJECTPTRLABELPROC                              __glGetObjectPtrLabel;
PFNGLGETPOINTERVPROC                                    __glGetPointerv;
PFNGLGETPROGRAMBINARYPROC                               __glGetProgramBinary;
PFNGLGETPROGRAMINFOLOGPROC                              __glGetProgramInfoLog;
PFNGLGETPROGRAMINTERFACEIVPROC                          __glGetProgramInterfaceiv;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC                      __glGetProgramPipelineInfoLog;
PFNGLGETPROGRAMPIPELINEIVPROC                           __glGetProgramPipelineiv;
PFNGLGETPROGRAMRESOURCEINDEXPROC                        __glGetProgramResourceIndex;
PFNGLGETPROGRAMRESOURCELOCATIONPROC                     __glGetProgramResourceLocation;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC                __glGetProgramResourceLocationIndex;
PFNGLGETPROGRAMRESOURCENAMEPROC                         __glGetProgramResourceName;
PFNGLGETPROGRAMRESOURCEIVPROC                           __glGetProgramResourceiv;
PFNGLGETPROGRAMSTAGEIVPROC                              __glGetProgramStageiv;
PFNGLGETPROGRAMIVPROC                                   __glGetProgramiv;
PFNGLGETQUERYBUFFEROBJECTI64VPROC                       __glGetQueryBufferObjecti64v;
PFNGLGETQUERYBUFFEROBJECTIVPROC                         __glGetQueryBufferObjectiv;
PFNGLGETQUERYBUFFEROBJECTUI64VPROC                      __glGetQueryBufferObjectui64v;
PFNGLGETQUERYBUFFEROBJECTUIVPROC                        __glGetQueryBufferObjectuiv;
PFNGLGETQUERYINDEXEDIVPROC                              __glGetQueryIndexediv;
PFNGLGETQUERYOBJECTI64VPROC                             __glGetQueryObjecti64v;
PFNGLGETQUERYOBJECTIVPROC                               __glGetQueryObjectiv;
PFNGLGETQUERYOBJECTUI64VPROC                            __glGetQueryObjectui64v;
PFNGLGETQUERYOBJECTUIVPROC                              __glGetQueryObjectuiv;
PFNGLGETQUERYIVPROC                                     __glGetQueryiv;
PFNGLGETRENDERBUFFERPARAMETERIVPROC                     __glGetRenderbufferParameteriv;
PFNGLGETSAMPLERPARAMETERIIVPROC                         __glGetSamplerParameterIiv;
PFNGLGETSAMPLERPARAMETERIUIVPROC                        __glGetSamplerParameterIuiv;
PFNGLGETSAMPLERPARAMETERFVPROC                          __glGetSamplerParameterfv;
PFNGLGETSAMPLERPARAMETERIVPROC                          __glGetSamplerParameteriv;
PFNGLGETSHADERINFOLOGPROC                               __glGetShaderInfoLog;
PFNGLGETSHADERPRECISIONFORMATPROC                       __glGetShaderPrecisionFormat;
PFNGLGETSHADERSOURCEPROC                                __glGetShaderSource;
PFNGLGETSHADERIVPROC                                    __glGetShaderiv;
PFNGLGETSTRINGPROC                                      __glGetString;
PFNGLGETSTRINGIPROC                                     __glGetStringi;
PFNGLGETSUBROUTINEINDEXPROC                             __glGetSubroutineIndex;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC                   __glGetSubroutineUniformLocation;
PFNGLGETSYNCIVPROC                                      __glGetSynciv;
PFNGLGETTEXIMAGEPROC                                    __glGetTexImage;
PFNGLGETTEXLEVELPARAMETERFVPROC                         __glGetTexLevelParameterfv;
PFNGLGETTEXLEVELPARAMETERIVPROC                         __glGetTexLevelParameteriv;
PFNGLGETTEXPARAMETERIIVPROC                             __glGetTexParameterIiv;
PFNGLGETTEXPARAMETERIUIVPROC                            __glGetTexParameterIuiv;
PFNGLGETTEXPARAMETERFVPROC                              __glGetTexParameterfv;
PFNGLGETTEXPARAMETERIVPROC                              __glGetTexParameteriv;
PFNGLGETTEXTUREIMAGEPROC                                __glGetTextureImage;
PFNGLGETTEXTURELEVELPARAMETERFVPROC                     __glGetTextureLevelParameterfv;
PFNGLGETTEXTURELEVELPARAMETERIVPROC                     __glGetTextureLevelParameteriv;
PFNGLGETTEXTUREPARAMETERIIVPROC                         __glGetTextureParameterIiv;
PFNGLGETTEXTUREPARAMETERIUIVPROC                        __glGetTextureParameterIuiv;
PFNGLGETTEXTUREPARAMETERFVPROC                          __glGetTextureParameterfv;
PFNGLGETTEXTUREPARAMETERIVPROC                          __glGetTextureParameteriv;
PFNGLGETTEXTURESUBIMAGEPROC                             __glGetTextureSubImage;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC                    __glGetTransformFeedbackVarying;
PFNGLGETTRANSFORMFEEDBACKI64_VPROC                      __glGetTransformFeedbacki64_v;
PFNGLGETTRANSFORMFEEDBACKI_VPROC                        __glGetTransformFeedbacki_v;
PFNGLGETTRANSFORMFEEDBACKIVPROC                         __glGetTransformFeedbackiv;
PFNGLGETUNIFORMBLOCKINDEXPROC                           __glGetUniformBlockIndex;
PFNGLGETUNIFORMINDICESPROC                              __glGetUniformIndices;
PFNGLGETUNIFORMLOCATIONPROC                             __glGetUniformLocation;
PFNGLGETUNIFORMSUBROUTINEUIVPROC                        __glGetUniformSubroutineuiv;
PFNGLGETUNIFORMDVPROC                                   __glGetUniformdv;
PFNGLGETUNIFORMFVPROC                                   __glGetUniformfv;
PFNGLGETUNIFORMIVPROC                                   __glGetUniformiv;
PFNGLGETUNIFORMUIVPROC                                  __glGetUniformuiv;
PFNGLGETVERTEXARRAYINDEXED64IVPROC                      __glGetVertexArrayIndexed64iv;
PFNGLGETVERTEXARRAYINDEXEDIVPROC                        __glGetVertexArrayIndexediv;
PFNGLGETVERTEXARRAYIVPROC                               __glGetVertexArrayiv;
PFNGLGETVERTEXATTRIBIIVPROC                             __glGetVertexAttribIiv;
PFNGLGETVERTEXATTRIBIUIVPROC                            __glGetVertexAttribIuiv;
PFNGLGETVERTEXATTRIBLDVPROC                             __glGetVertexAttribLdv;
PFNGLGETVERTEXATTRIBPOINTERVPROC                        __glGetVertexAttribPointerv;
PFNGLGETVERTEXATTRIBDVPROC                              __glGetVertexAttribdv;
PFNGLGETVERTEXATTRIBFVPROC                              __glGetVertexAttribfv;
PFNGLGETVERTEXATTRIBIVPROC                              __glGetVertexAttribiv;
PFNGLGETNCOMPRESSEDTEXIMAGEPROC                         __glGetnCompressedTexImage;
PFNGLGETNTEXIMAGEPROC                                   __glGetnTexImage;
PFNGLGETNUNIFORMDVPROC                                  __glGetnUniformdv;
PFNGLGETNUNIFORMFVPROC                                  __glGetnUniformfv;
PFNGLGETNUNIFORMIVPROC                                  __glGetnUniformiv;
PFNGLGETNUNIFORMUIVPROC                                 __glGetnUniformuiv;
PFNGLHINTPROC                                           __glHint;
PFNGLINVALIDATEBUFFERDATAPROC                           __glInvalidateBufferData;
PFNGLINVALIDATEBUFFERSUBDATAPROC                        __glInvalidateBufferSubData;
PFNGLINVALIDATEFRAMEBUFFERPROC                          __glInvalidateFramebuffer;
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC                 __glInvalidateNamedFramebufferData;
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC              __glInvalidateNamedFramebufferSubData;
PFNGLINVALIDATESUBFRAMEBUFFERPROC                       __glInvalidateSubFramebuffer;
PFNGLINVALIDATETEXIMAGEPROC                             __glInvalidateTexImage;
PFNGLINVALIDATETEXSUBIMAGEPROC                          __glInvalidateTexSubImage;
PFNGLISBUFFERPROC                                       __glIsBuffer;
PFNGLISENABLEDPROC                                      __glIsEnabled;
PFNGLISENABLEDIPROC                                     __glIsEnabledi;
PFNGLISFRAMEBUFFERPROC                                  __glIsFramebuffer;
PFNGLISPROGRAMPROC                                      __glIsProgram;
PFNGLISPROGRAMPIPELINEPROC                              __glIsProgramPipeline;
PFNGLISQUERYPROC                                        __glIsQuery;
PFNGLISRENDERBUFFERPROC                                 __glIsRenderbuffer;
PFNGLISSAMPLERPROC                                      __glIsSampler;
PFNGLISSHADERPROC                                       __glIsShader;
PFNGLISSYNCPROC                                         __glIsSync;
PFNGLISTEXTUREPROC                                      __glIsTexture;
PFNGLISTRANSFORMFEEDBACKPROC                            __glIsTransformFeedback;
PFNGLISVERTEXARRAYPROC                                  __glIsVertexArray;
PFNGLLINEWIDTHPROC                                      __glLineWidth;
PFNGLLINKPROGRAMPROC                                    __glLinkProgram;
PFNGLLOGICOPPROC                                        __glLogicOp;
PFNGLMAPBUFFERPROC                                      __glMapBuffer;
PFNGLMAPBUFFERRANGEPROC                                 __glMapBufferRange;
PFNGLMAPNAMEDBUFFERPROC                                 __glMapNamedBuffer;
PFNGLMAPNAMEDBUFFERRANGEPROC                            __glMapNamedBufferRange;
PFNGLMEMORYBARRIERPROC                                  __glMemoryBarrier;
PFNGLMEMORYBARRIERBYREGIONPROC                          __glMemoryBarrierByRegion;
PFNGLMINSAMPLESHADINGPROC                               __glMinSampleShading;
PFNGLMULTIDRAWARRAYSPROC                                __glMultiDrawArrays;
PFNGLMULTIDRAWARRAYSINDIRECTPROC                        __glMultiDrawArraysIndirect;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC                   __glMultiDrawArraysIndirectCount;
PFNGLMULTIDRAWELEMENTSPROC                              __glMultiDrawElements;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC                    __glMultiDrawElementsBaseVertex;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC                      __glMultiDrawElementsIndirect;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC                 __glMultiDrawElementsIndirectCount;
PFNGLNAMEDBUFFERDATAPROC                                __glNamedBufferData;
PFNGLNAMEDBUFFERSTORAGEPROC                             __glNamedBufferStorage;
PFNGLNAMEDBUFFERSUBDATAPROC                             __glNamedBufferSubData;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC                     __glNamedFramebufferDrawBuffer;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC                    __glNamedFramebufferDrawBuffers;
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC                     __glNamedFramebufferParameteri;
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC                     __glNamedFramebufferReadBuffer;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC                   __glNamedFramebufferRenderbuffer;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC                        __glNamedFramebufferTexture;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC                   __glNamedFramebufferTextureLayer;
PFNGLNAMEDRENDERBUFFERSTORAGEPROC                       __glNamedRenderbufferStorage;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC            __glNamedRenderbufferStorageMultisample;
PFNGLOBJECTLABELPROC                                    __glObjectLabel;
PFNGLOBJECTPTRLABELPROC                                 __glObjectPtrLabel;
PFNGLPATCHPARAMETERFVPROC                               __glPatchParameterfv;
PFNGLPATCHPARAMETERIPROC                                __glPatchParameteri;
PFNGLPAUSETRANSFORMFEEDBACKPROC                         __glPauseTransformFeedback;
PFNGLPIXELSTOREFPROC                                    __glPixelStoref;
PFNGLPIXELSTOREIPROC                                    __glPixelStorei;
PFNGLPOINTPARAMETERFPROC                                __glPointParameterf;
PFNGLPOINTPARAMETERFVPROC                               __glPointParameterfv;
PFNGLPOINTPARAMETERIPROC                                __glPointParameteri;
PFNGLPOINTPARAMETERIVPROC                               __glPointParameteriv;
PFNGLPOINTSIZEPROC                                      __glPointSize;
PFNGLPOLYGONMODEPROC                                    __glPolygonMode;
PFNGLPOLYGONOFFSETPROC                                  __glPolygonOffset;
PFNGLPOLYGONOFFSETCLAMPPROC                             __glPolygonOffsetClamp;
PFNGLPOPDEBUGGROUPPROC                                  __glPopDebugGroup;
PFNGLPRIMITIVERESTARTINDEXPROC                          __glPrimitiveRestartIndex;
PFNGLPROGRAMBINARYPROC                                  __glProgramBinary;
PFNGLPROGRAMPARAMETERIPROC                              __glProgramParameteri;
PFNGLPROGRAMUNIFORM1DPROC                               __glProgramUniform1d;
PFNGLPROGRAMUNIFORM1DVPROC                              __glProgramUniform1dv;
PFNGLPROGRAMUNIFORM1FPROC                               __glProgramUniform1f;
PFNGLPROGRAMUNIFORM1FVPROC                              __glProgramUniform1fv;
PFNGLPROGRAMUNIFORM1IPROC                               __glProgramUniform1i;
PFNGLPROGRAMUNIFORM1IVPROC                              __glProgramUniform1iv;
PFNGLPROGRAMUNIFORM1UIPROC                              __glProgramUniform1ui;
PFNGLPROGRAMUNIFORM1UIVPROC                             __glProgramUniform1uiv;
PFNGLPROGRAMUNIFORM2DPROC                               __glProgramUniform2d;
PFNGLPROGRAMUNIFORM2DVPROC                              __glProgramUniform2dv;
PFNGLPROGRAMUNIFORM2FPROC                               __glProgramUniform2f;
PFNGLPROGRAMUNIFORM2FVPROC                              __glProgramUniform2fv;
PFNGLPROGRAMUNIFORM2IPROC                               __glProgramUniform2i;
PFNGLPROGRAMUNIFORM2IVPROC                              __glProgramUniform2iv;
PFNGLPROGRAMUNIFORM2UIPROC                              __glProgramUniform2ui;
PFNGLPROGRAMUNIFORM2UIVPROC                             __glProgramUniform2uiv;
PFNGLPROGRAMUNIFORM3DPROC                               __glProgramUniform3d;
PFNGLPROGRAMUNIFORM3DVPROC                              __glProgramUniform3dv;
PFNGLPROGRAMUNIFORM3FPROC                               __glProgramUniform3f;
PFNGLPROGRAMUNIFORM3FVPROC                              __glProgramUniform3fv;
PFNGLPROGRAMUNIFORM3IPROC                               __glProgramUniform3i;
PFNGLPROGRAMUNIFORM3IVPROC                              __glProgramUniform3iv;
PFNGLPROGRAMUNIFORM3UIPROC                              __glProgramUniform3ui;
PFNGLPROGRAMUNIFORM3UIVPROC                             __glProgramUniform3uiv;
PFNGLPROGRAMUNIFORM4DPROC                               __glProgramUniform4d;
PFNGLPROGRAMUNIFORM4DVPROC                              __glProgramUniform4dv;
PFNGLPROGRAMUNIFORM4FPROC                               __glProgramUniform4f;
PFNGLPROGRAMUNIFORM4FVPROC                              __glProgramUniform4fv;
PFNGLPROGRAMUNIFORM4IPROC                               __glProgramUniform4i;
PFNGLPROGRAMUNIFORM4IVPROC                              __glProgramUniform4iv;
PFNGLPROGRAMUNIFORM4UIPROC                              __glProgramUniform4ui;
PFNGLPROGRAMUNIFORM4UIVPROC                             __glProgramUniform4uiv;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC                        __glProgramUniformMatrix2dv;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC                        __glProgramUniformMatrix2fv;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC                      __glProgramUniformMatrix2x3dv;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC                      __glProgramUniformMatrix2x3fv;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC                      __glProgramUniformMatrix2x4dv;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC                      __glProgramUniformMatrix2x4fv;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC                        __glProgramUniformMatrix3dv;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC                        __glProgramUniformMatrix3fv;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC                      __glProgramUniformMatrix3x2dv;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC                      __glProgramUniformMatrix3x2fv;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC                      __glProgramUniformMatrix3x4dv;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC                      __glProgramUniformMatrix3x4fv;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC                        __glProgramUniformMatrix4dv;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC                        __glProgramUniformMatrix4fv;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC                      __glProgramUniformMatrix4x2dv;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC                      __glProgramUniformMatrix4x2fv;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC                      __glProgramUniformMatrix4x3dv;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC                      __glProgramUniformMatrix4x3fv;
PFNGLPROVOKINGVERTEXPROC                                __glProvokingVertex;
PFNGLPUSHDEBUGGROUPPROC                                 __glPushDebugGroup;
PFNGLQUERYCOUNTERPROC                                   __glQueryCounter;
PFNGLREADBUFFERPROC                                     __glReadBuffer;
PFNGLREADPIXELSPROC                                     __glReadPixels;
PFNGLREADNPIXELSPROC                                    __glReadnPixels;
PFNGLRELEASESHADERCOMPILERPROC                          __glReleaseShaderCompiler;
PFNGLRENDERBUFFERSTORAGEPROC                            __glRenderbufferStorage;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC                 __glRenderbufferStorageMultisample;
PFNGLRESUMETRANSFORMFEEDBACKPROC                        __glResumeTransformFeedback;
PFNGLSAMPLECOVERAGEPROC                                 __glSampleCoverage;
PFNGLSAMPLEMASKIPROC                                    __glSampleMaski;
PFNGLSAMPLERPARAMETERIIVPROC                            __glSamplerParameterIiv;
PFNGLSAMPLERPARAMETERIUIVPROC                           __glSamplerParameterIuiv;
PFNGLSAMPLERPARAMETERFPROC                              __glSamplerParameterf;
PFNGLSAMPLERPARAMETERFVPROC                             __glSamplerParameterfv;
PFNGLSAMPLERPARAMETERIPROC                              __glSamplerParameteri;
PFNGLSAMPLERPARAMETERIVPROC                             __glSamplerParameteriv;
PFNGLSCISSORPROC                                        __glScissor;
PFNGLSCISSORARRAYVPROC                                  __glScissorArrayv;
PFNGLSCISSORINDEXEDPROC                                 __glScissorIndexed;
PFNGLSCISSORINDEXEDVPROC                                __glScissorIndexedv;
PFNGLSHADERBINARYPROC                                   __glShaderBinary;
PFNGLSHADERSOURCEPROC                                   __glShaderSource;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC                      __glShaderStorageBlockBinding;
PFNGLSPECIALIZESHADERPROC                               __glSpecializeShader;
PFNGLSTENCILFUNCPROC                                    __glStencilFunc;
PFNGLSTENCILFUNCSEPARATEPROC                            __glStencilFuncSeparate;
PFNGLSTENCILMASKPROC                                    __glStencilMask;
PFNGLSTENCILMASKSEPARATEPROC                            __glStencilMaskSeparate;
PFNGLSTENCILOPPROC                                      __glStencilOp;
PFNGLSTENCILOPSEPARATEPROC                              __glStencilOpSeparate;
PFNGLTEXBUFFERPROC                                      __glTexBuffer;
PFNGLTEXBUFFERRANGEPROC                                 __glTexBufferRange;
PFNGLTEXIMAGE1DPROC                                     __glTexImage1D;
PFNGLTEXIMAGE2DPROC                                     __glTexImage2D;
PFNGLTEXIMAGE2DMULTISAMPLEPROC                          __glTexImage2DMultisample;
PFNGLTEXIMAGE3DPROC                                     __glTexImage3D;
PFNGLTEXIMAGE3DMULTISAMPLEPROC                          __glTexImage3DMultisample;
PFNGLTEXPARAMETERIIVPROC                                __glTexParameterIiv;
PFNGLTEXPARAMETERIUIVPROC                               __glTexParameterIuiv;
PFNGLTEXPARAMETERFPROC                                  __glTexParameterf;
PFNGLTEXPARAMETERFVPROC                                 __glTexParameterfv;
PFNGLTEXPARAMETERIPROC                                  __glTexParameteri;
PFNGLTEXPARAMETERIVPROC                                 __glTexParameteriv;
PFNGLTEXSTORAGE1DPROC                                   __glTexStorage1D;
PFNGLTEXSTORAGE2DPROC                                   __glTexStorage2D;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC                        __glTexStorage2DMultisample;
PFNGLTEXSTORAGE3DPROC                                   __glTexStorage3D;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC                        __glTexStorage3DMultisample;
PFNGLTEXSUBIMAGE1DPROC                                  __glTexSubImage1D;
PFNGLTEXSUBIMAGE2DPROC                                  __glTexSubImage2D;
PFNGLTEXSUBIMAGE3DPROC                                  __glTexSubImage3D;
PFNGLTEXTUREBARRIERPROC                                 __glTextureBarrier;
PFNGLTEXTUREBUFFERPROC                                  __glTextureBuffer;
PFNGLTEXTUREBUFFERRANGEPROC                             __glTextureBufferRange;
PFNGLTEXTUREPARAMETERIIVPROC                            __glTextureParameterIiv;
PFNGLTEXTUREPARAMETERIUIVPROC                           __glTextureParameterIuiv;
PFNGLTEXTUREPARAMETERFPROC                              __glTextureParameterf;
PFNGLTEXTUREPARAMETERFVPROC                             __glTextureParameterfv;
PFNGLTEXTUREPARAMETERIPROC                              __glTextureParameteri;
PFNGLTEXTUREPARAMETERIVPROC                             __glTextureParameteriv;
PFNGLTEXTURESTORAGE1DPROC                               __glTextureStorage1D;
PFNGLTEXTURESTORAGE2DPROC                               __glTextureStorage2D;
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC                    __glTextureStorage2DMultisample;
PFNGLTEXTURESTORAGE3DPROC                               __glTextureStorage3D;
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC                    __glTextureStorage3DMultisample;
PFNGLTEXTURESUBIMAGE1DPROC                              __glTextureSubImage1D;
PFNGLTEXTURESUBIMAGE2DPROC                              __glTextureSubImage2D;
PFNGLTEXTURESUBIMAGE3DPROC                              __glTextureSubImage3D;
PFNGLTEXTUREVIEWPROC                                    __glTextureView;
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC                    __glTransformFeedbackBufferBase;
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC                   __glTransformFeedbackBufferRange;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC                      __glTransformFeedbackVaryings;
PFNGLUNIFORM1DPROC                                      __glUniform1d;
PFNGLUNIFORM1DVPROC                                     __glUniform1dv;
PFNGLUNIFORM1FPROC                                      __glUniform1f;
PFNGLUNIFORM1FVPROC                                     __glUniform1fv;
PFNGLUNIFORM1IPROC                                      __glUniform1i;
PFNGLUNIFORM1IVPROC                                     __glUniform1iv;
PFNGLUNIFORM1UIPROC                                     __glUniform1ui;
PFNGLUNIFORM1UIVPROC                                    __glUniform1uiv;
PFNGLUNIFORM2DPROC                                      __glUniform2d;
PFNGLUNIFORM2DVPROC                                     __glUniform2dv;
PFNGLUNIFORM2FPROC                                      __glUniform2f;
PFNGLUNIFORM2FVPROC                                     __glUniform2fv;
PFNGLUNIFORM2IPROC                                      __glUniform2i;
PFNGLUNIFORM2IVPROC                                     __glUniform2iv;
PFNGLUNIFORM2UIPROC                                     __glUniform2ui;
PFNGLUNIFORM2UIVPROC                                    __glUniform2uiv;
PFNGLUNIFORM3DPROC                                      __glUniform3d;
PFNGLUNIFORM3DVPROC                                     __glUniform3dv;
PFNGLUNIFORM3FPROC                                      __glUniform3f;
PFNGLUNIFORM3FVPROC                                     __glUniform3fv;
PFNGLUNIFORM3IPROC                                      __glUniform3i;
PFNGLUNIFORM3IVPROC                                     __glUniform3iv;
PFNGLUNIFORM3UIPROC                                     __glUniform3ui;
PFNGLUNIFORM3UIVPROC                                    __glUniform3uiv;
PFNGLUNIFORM4DPROC                                      __glUniform4d;
PFNGLUNIFORM4DVPROC                                     __glUniform4dv;
PFNGLUNIFORM4FPROC                                      __glUniform4f;
PFNGLUNIFORM4FVPROC                                     __glUniform4fv;
PFNGLUNIFORM4IPROC                                      __glUniform4i;
PFNGLUNIFORM4IVPROC                                     __glUniform4iv;
PFNGLUNIFORM4UIPROC                                     __glUniform4ui;
PFNGLUNIFORM4UIVPROC                                    __glUniform4uiv;
PFNGLUNIFORMBLOCKBINDINGPROC                            __glUniformBlockBinding;
PFNGLUNIFORMMATRIX2DVPROC                               __glUniformMatrix2dv;
PFNGLUNIFORMMATRIX2FVPROC                               __glUniformMatrix2fv;
PFNGLUNIFORMMATRIX2X3DVPROC                             __glUniformMatrix2x3dv;
PFNGLUNIFORMMATRIX2X3FVPROC                             __glUniformMatrix2x3fv;
PFNGLUNIFORMMATRIX2X4DVPROC                             __glUniformMatrix2x4dv;
PFNGLUNIFORMMATRIX2X4FVPROC                             __glUniformMatrix2x4fv;
PFNGLUNIFORMMATRIX3DVPROC                               __glUniformMatrix3dv;
PFNGLUNIFORMMATRIX3FVPROC                               __glUniformMatrix3fv;
PFNGLUNIFORMMATRIX3X2DVPROC                             __glUniformMatrix3x2dv;
PFNGLUNIFORMMATRIX3X2FVPROC                             __glUniformMatrix3x2fv;
PFNGLUNIFORMMATRIX3X4DVPROC                             __glUniformMatrix3x4dv;
PFNGLUNIFORMMATRIX3X4FVPROC                             __glUniformMatrix3x4fv;
PFNGLUNIFORMMATRIX4DVPROC                               __glUniformMatrix4dv;
PFNGLUNIFORMMATRIX4FVPROC                               __glUniformMatrix4fv;
PFNGLUNIFORMMATRIX4X2DVPROC                             __glUniformMatrix4x2dv;
PFNGLUNIFORMMATRIX4X2FVPROC                             __glUniformMatrix4x2fv;
PFNGLUNIFORMMATRIX4X3DVPROC                             __glUniformMatrix4x3dv;
PFNGLUNIFORMMATRIX4X3FVPROC                             __glUniformMatrix4x3fv;
PFNGLUNIFORMSUBROUTINESUIVPROC                          __glUniformSubroutinesuiv;
PFNGLUNMAPBUFFERPROC                                    __glUnmapBuffer;
PFNGLUNMAPNAMEDBUFFERPROC                               __glUnmapNamedBuffer;
PFNGLUSEPROGRAMPROC                                     __glUseProgram;
PFNGLUSEPROGRAMSTAGESPROC                               __glUseProgramStages;
PFNGLVALIDATEPROGRAMPROC                                __glValidateProgram;
PFNGLVALIDATEPROGRAMPIPELINEPROC                        __glValidateProgramPipeline;
PFNGLVERTEXARRAYATTRIBBINDINGPROC                       __glVertexArrayAttribBinding;
PFNGLVERTEXARRAYATTRIBFORMATPROC                        __glVertexArrayAttribFormat;
PFNGLVERTEXARRAYATTRIBIFORMATPROC                       __glVertexArrayAttribIFormat;
PFNGLVERTEXARRAYATTRIBLFORMATPROC                       __glVertexArrayAttribLFormat;
PFNGLVERTEXARRAYBINDINGDIVISORPROC                      __glVertexArrayBindingDivisor;
PFNGLVERTEXARRAYELEMENTBUFFERPROC                       __glVertexArrayElementBuffer;
PFNGLVERTEXARRAYVERTEXBUFFERPROC                        __glVertexArrayVertexBuffer;
PFNGLVERTEXARRAYVERTEXBUFFERSPROC                       __glVertexArrayVertexBuffers;
PFNGLVERTEXATTRIB1DPROC                                 __glVertexAttrib1d;
PFNGLVERTEXATTRIB1DVPROC                                __glVertexAttrib1dv;
PFNGLVERTEXATTRIB1FPROC                                 __glVertexAttrib1f;
PFNGLVERTEXATTRIB1FVPROC                                __glVertexAttrib1fv;
PFNGLVERTEXATTRIB1SPROC                                 __glVertexAttrib1s;
PFNGLVERTEXATTRIB1SVPROC                                __glVertexAttrib1sv;
PFNGLVERTEXATTRIB2DPROC                                 __glVertexAttrib2d;
PFNGLVERTEXATTRIB2DVPROC                                __glVertexAttrib2dv;
PFNGLVERTEXATTRIB2FPROC                                 __glVertexAttrib2f;
PFNGLVERTEXATTRIB2FVPROC                                __glVertexAttrib2fv;
PFNGLVERTEXATTRIB2SPROC                                 __glVertexAttrib2s;
PFNGLVERTEXATTRIB2SVPROC                                __glVertexAttrib2sv;
PFNGLVERTEXATTRIB3DPROC                                 __glVertexAttrib3d;
PFNGLVERTEXATTRIB3DVPROC                                __glVertexAttrib3dv;
PFNGLVERTEXATTRIB3FPROC                                 __glVertexAttrib3f;
PFNGLVERTEXATTRIB3FVPROC                                __glVertexAttrib3fv;
PFNGLVERTEXATTRIB3SPROC                                 __glVertexAttrib3s;
PFNGLVERTEXATTRIB3SVPROC                                __glVertexAttrib3sv;
PFNGLVERTEXATTRIB4NBVPROC                               __glVertexAttrib4Nbv;
PFNGLVERTEXATTRIB4NIVPROC                               __glVertexAttrib4Niv;
PFNGLVERTEXATTRIB4NSVPROC                               __glVertexAttrib4Nsv;
PFNGLVERTEXATTRIB4NUBPROC                               __glVertexAttrib4Nub;
PFNGLVERTEXATTRIB4NUBVPROC                              __glVertexAttrib4Nubv;
PFNGLVERTEXATTRIB4NUIVPROC                              __glVertexAttrib4Nuiv;
PFNGLVERTEXATTRIB4NUSVPROC                              __glVertexAttrib4Nusv;
PFNGLVERTEXATTRIB4BVPROC                                __glVertexAttrib4bv;
PFNGLVERTEXATTRIB4DPROC                                 __glVertexAttrib4d;
PFNGLVERTEXATTRIB4DVPROC                                __glVertexAttrib4dv;
PFNGLVERTEXATTRIB4FPROC                                 __glVertexAttrib4f;
PFNGLVERTEXATTRIB4FVPROC                                __glVertexAttrib4fv;
PFNGLVERTEXATTRIB4IVPROC                                __glVertexAttrib4iv;
PFNGLVERTEXATTRIB4SPROC                                 __glVertexAttrib4s;
PFNGLVERTEXATTRIB4SVPROC                                __glVertexAttrib4sv;
PFNGLVERTEXATTRIB4UBVPROC                               __glVertexAttrib4ubv;
PFNGLVERTEXATTRIB4UIVPROC                               __glVertexAttrib4uiv;
PFNGLVERTEXATTRIB4USVPROC                               __glVertexAttrib4usv;
PFNGLVERTEXATTRIBBINDINGPROC                            __glVertexAttribBinding;
PFNGLVERTEXATTRIBDIVISORPROC                            __glVertexAttribDivisor;
PFNGLVERTEXATTRIBFORMATPROC                             __glVertexAttribFormat;
PFNGLVERTEXATTRIBI1IPROC                                __glVertexAttribI1i;
PFNGLVERTEXATTRIBI1IVPROC                               __glVertexAttribI1iv;
PFNGLVERTEXATTRIBI1UIPROC                               __glVertexAttribI1ui;
PFNGLVERTEXATTRIBI1UIVPROC                              __glVertexAttribI1uiv;
PFNGLVERTEXATTRIBI2IPROC                                __glVertexAttribI2i;
PFNGLVERTEXATTRIBI2IVPROC                               __glVertexAttribI2iv;
PFNGLVERTEXATTRIBI2UIPROC                               __glVertexAttribI2ui;
PFNGLVERTEXATTRIBI2UIVPROC                              __glVertexAttribI2uiv;
PFNGLVERTEXATTRIBI3IPROC                                __glVertexAttribI3i;
PFNGLVERTEXATTRIBI3IVPROC                               __glVertexAttribI3iv;
PFNGLVERTEXATTRIBI3UIPROC                               __glVertexAttribI3ui;
PFNGLVERTEXATTRIBI3UIVPROC                              __glVertexAttribI3uiv;
PFNGLVERTEXATTRIBI4BVPROC                               __glVertexAttribI4bv;
PFNGLVERTEXATTRIBI4IPROC                                __glVertexAttribI4i;
PFNGLVERTEXATTRIBI4IVPROC                               __glVertexAttribI4iv;
PFNGLVERTEXATTRIBI4SVPROC                               __glVertexAttribI4sv;
PFNGLVERTEXATTRIBI4UBVPROC                              __glVertexAttribI4ubv;
PFNGLVERTEXATTRIBI4UIPROC                               __glVertexAttribI4ui;
PFNGLVERTEXATTRIBI4UIVPROC                              __glVertexAttribI4uiv;
PFNGLVERTEXATTRIBI4USVPROC                              __glVertexAttribI4usv;
PFNGLVERTEXATTRIBIFORMATPROC                            __glVertexAttribIFormat;
PFNGLVERTEXATTRIBIPOINTERPROC                           __glVertexAttribIPointer;
PFNGLVERTEXATTRIBL1DPROC                                __glVertexAttribL1d;
PFNGLVERTEXATTRIBL1DVPROC                               __glVertexAttribL1dv;
PFNGLVERTEXATTRIBL2DPROC                                __glVertexAttribL2d;
PFNGLVERTEXATTRIBL2DVPROC                               __glVertexAttribL2dv;
PFNGLVERTEXATTRIBL3DPROC                                __glVertexAttribL3d;
PFNGLVERTEXATTRIBL3DVPROC                               __glVertexAttribL3dv;
PFNGLVERTEXATTRIBL4DPROC                                __glVertexAttribL4d;
PFNGLVERTEXATTRIBL4DVPROC                               __glVertexAttribL4dv;
PFNGLVERTEXATTRIBLFORMATPROC                            __glVertexAttribLFormat;
PFNGLVERTEXATTRIBLPOINTERPROC                           __glVertexAttribLPointer;
PFNGLVERTEXATTRIBP1UIPROC                               __glVertexAttribP1ui;
PFNGLVERTEXATTRIBP1UIVPROC                              __glVertexAttribP1uiv;
PFNGLVERTEXATTRIBP2UIPROC                               __glVertexAttribP2ui;
PFNGLVERTEXATTRIBP2UIVPROC                              __glVertexAttribP2uiv;
PFNGLVERTEXATTRIBP3UIPROC                               __glVertexAttribP3ui;
PFNGLVERTEXATTRIBP3UIVPROC                              __glVertexAttribP3uiv;
PFNGLVERTEXATTRIBP4UIPROC                               __glVertexAttribP4ui;
PFNGLVERTEXATTRIBP4UIVPROC                              __glVertexAttribP4uiv;
PFNGLVERTEXATTRIBPOINTERPROC                            __glVertexAttribPointer;
PFNGLVERTEXBINDINGDIVISORPROC                           __glVertexBindingDivisor;
PFNGLVIEWPORTPROC                                       __glViewport;
PFNGLVIEWPORTARRAYVPROC                                 __glViewportArrayv;
PFNGLVIEWPORTINDEXEDFPROC                               __glViewportIndexedf;
PFNGLVIEWPORTINDEXEDFVPROC                              __glViewportIndexedfv;
PFNGLWAITSYNCPROC                                       __glWaitSync;
