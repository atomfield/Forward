
#include "Window.h"

#include "GL.h"

#include "LinMath.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include "StbImage.h"

#define DEG_TO_RAD (M_PI / 180)

typedef struct tagPICTURE
{
	char* Data;

	int Width;

	int Height;

	int Channels;
} PICTURE;

static PICTURE LoadPicture(const char* Name)
{
	PICTURE Picture;

	Picture.Data = stbi_load(Name, &Picture.Width, &Picture.Height, &Picture.Channels, 4);

	return Picture;
}

static void FreePicture(PICTURE Picture)
{
	stbi_image_free(Picture.Data);
}

static const char* VertexShaderSource =
	"#version 460 core \n"

	"out gl_PerVertex \n"
	"{ \n"
	"	vec4 gl_Position;"
	"}; \n"

	"layout(location = 0) in vec3 Position;\n"
	"layout(location = 1) in vec3 Normal;\n"
	"layout(location = 2) in vec2 TexCoord;\n"

	"layout(location = 0) uniform mat4 ModelMatrix; \n"
	"layout(location = 1) uniform mat4 ViewMatrix; \n"
	"layout(location = 2) uniform mat4 ProjectionMatrix; \n"

	"layout(location = 0) out vec3 VertexNormal; \n"
	"layout(location = 1) out vec3 VertexPixelPosition; \n"
	"layout(location = 2) out vec2 VertexTexCoord; \n"

	"void main() \n"
	"{ \n"
	"	VertexNormal = mat3(transpose(inverse(ModelMatrix))) * Normal; \n"
	"	VertexPixelPosition = vec3(ModelMatrix * vec4(Position, 1.0)); \n"
	"	VertexTexCoord = TexCoord; \n"
	"	mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix; \n"
	"	gl_Position = MVP * vec4(Position, 1.0); \n"
	"} \n"
;

static const char* PixelShaderSource =
	"#version 460 core \n"

	"layout(location = 0) in vec3 VertexNormal; \n"
	"layout(location = 1) in vec3 VertexPixelPosition; \n"
	"layout(location = 2) in vec2 VertexTexCoord; \n"

	"layout(location = 0) out vec4 PixelColor; \n"

	"layout(location = 0) uniform sampler2D Texture; \n"
	"layout(location = 1) uniform vec3		ObjectColor; \n"
	"layout(location = 2) uniform vec3		LightColor; \n"
	"layout(location = 3) uniform vec3		LightPosition; \n"
	"layout(location = 4) uniform vec3		ViewPosition; \n"

	"void main() \n"
	"{ \n"
	"	float AmbientStrength = 0.2; \n"
	"	vec3 Ambient = AmbientStrength * LightColor; \n"

	"	vec3 Norm = normalize(VertexNormal); \n"
	"	vec3 LightDirection = normalize(LightPosition - VertexPixelPosition); \n"

	"	float DiffuseValue = max(dot(Norm, LightDirection), 0.0); \n"
	"	vec3 Diffuse = DiffuseValue * LightColor; \n"

	"	vec3 ViewDirection = normalize(ViewPosition - VertexPixelPosition); \n"
	"	vec3 ReflectDirection = reflect(-LightDirection, Norm); \n"

	"	float SpecularStrength = 1.0; \n"
	"	float SpecularValue = pow(max(dot(ViewDirection, ReflectDirection), 0.0), 32); \n"
	"	vec3 Specular = SpecularStrength * SpecularValue * LightColor; \n"

	"	vec3 Result = (Ambient + Diffuse + Specular) * ObjectColor; \n"
	"	PixelColor = vec4(Result, 1.0) * texture(Texture, VertexTexCoord); \n"
	"} \n"
;

static mat4x4 ModelMatrix;

static mat4x4 ViewMatrix;

static mat4x4 ProjectionMatrix;

static float Fov = 90.0f;

static float AspectRatio = 1280.0f / 720.0f;

static double GetTime()
{
	LARGE_INTEGER Counter;

	LARGE_INTEGER Frequency;

	QueryPerformanceCounter(&Counter);

	QueryPerformanceFrequency(&Frequency);

	return (double)Counter.QuadPart / (double)Frequency.QuadPart;
}

static void OnWindowResize(WINDOW Window, int Width, int Height)
{
	AspectRatio = (float)Width / (float)Height;

	mat4x4_identity(ProjectionMatrix);

	float Near = 0.1f;

	float Far = 4000.0f;

	float Top = Near * tanf(Fov / 2 * DEG_TO_RAD);

	float Bottom = -Top;

	float Right = AspectRatio * Top;

	float Left = -Right;

	mat4x4_frustum(ProjectionMatrix, Left, Right, Bottom, Top, Near, Far);

	glViewport(0, 0, Width, Height);

	glScissor(0, 0, Width, Height);
}

int __stdcall Entry (_In_ HINSTANCE Instance, _In_opt_ HINSTANCE PrevInstance, _In_ STRING CommandLine, _In_ int ShowCommand)
{
	UNREFERENCED_PARAMETER(Instance);

	UNREFERENCED_PARAMETER(PrevInstance);

	UNREFERENCED_PARAMETER(CommandLine);

	UNREFERENCED_PARAMETER(ShowCommand);

	int Error = ERROR_SUCCESS;

	WINDOW Window = NULL;

	WINDOWCONFIG WindowConfig =
	{
		.Title		= TEXT("OpenGL Demo"),
		.Width		= 1280,
		.Height		= 720,
	};

	Error = NewWindow(&WindowConfig, &Window);
	if (Error != ERROR_SUCCESS)
	{
		goto Exit;
	}

	MakeCurrent(Window);

	LoadGL();

	SetWindowResizeCallback(Window, OnWindowResize);

	glEnable(GL_MULTISAMPLE);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	static const float Vertices[] =
	{
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};
	
	unsigned int VertexBuffer;

	glCreateBuffers(1, &VertexBuffer);
	
	glNamedBufferStorage(VertexBuffer, sizeof(Vertices), Vertices, GL_DYNAMIC_STORAGE_BIT);

	unsigned int VertexArray;

	glCreateVertexArrays(1, &VertexArray);
	
	glVertexArrayVertexBuffer(VertexArray, 0, VertexBuffer, 0, sizeof(float) * 8);
	
	glEnableVertexArrayAttrib(VertexArray, 0);

	glEnableVertexArrayAttrib(VertexArray, 1);

	glEnableVertexArrayAttrib(VertexArray, 2);
	
	glVertexArrayAttribFormat(VertexArray, 0, 3, GL_FLOAT, GL_FALSE, 0);
	
	glVertexArrayAttribFormat(VertexArray, 1, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3);

	glVertexArrayAttribFormat(VertexArray, 2, 2, GL_FLOAT, GL_FALSE, sizeof(float)*6);
	
	glVertexArrayAttribBinding(VertexArray, 0, 0);

	glVertexArrayAttribBinding(VertexArray, 1, 0);

	glVertexArrayAttribBinding(VertexArray, 2, 0);

	unsigned int VertexShader = glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &VertexShaderSource);
	
	unsigned int PixelShader = glCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &PixelShaderSource);

	unsigned int Pipeline;

	glCreateProgramPipelines(1, &Pipeline);

	glUseProgramStages(Pipeline, GL_VERTEX_SHADER_BIT, VertexShader);

	glUseProgramStages(Pipeline, GL_FRAGMENT_SHADER_BIT, PixelShader);

	unsigned int Texture0;

	glGenTextures(1, &Texture0);

	glBindTexture(GL_TEXTURE_2D, Texture0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	PICTURE Picture = LoadPicture("assets/fastfall.jpg");

	GLenum InternalFormat = GL_RGBA;
	
	if (Picture.Channels == 3)
	{
		InternalFormat = GL_RGB;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, InternalFormat, Picture.Width, Picture.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Picture.Data);
	
	glGenerateMipmap(GL_TEXTURE_2D);

	FreePicture(Picture);

	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

	vec3 CameraPosition = { 0.0, 0.0, -3.0 };

	while (!Closed(Window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mat4x4_identity(ModelMatrix);

		mat4x4_rotate(ModelMatrix, ModelMatrix, 0.5, 1.0, 0.0, GetTime());

		mat4x4_identity(ViewMatrix);

		mat4x4_translate(ViewMatrix, CameraPosition[0], CameraPosition[1], CameraPosition[2]);

		glBindProgramPipeline(Pipeline);

		// Vertex shader //

		glProgramUniformMatrix4fv(VertexShader, 0, 1, GL_FALSE, (float*)ModelMatrix);
		
		glProgramUniformMatrix4fv(VertexShader, 1, 1, GL_FALSE, (float*)ViewMatrix);

		glProgramUniformMatrix4fv(VertexShader, 2, 1, GL_FALSE, (float*)ProjectionMatrix);

		// Pixel shader //

		glProgramUniform1i(PixelShader, 0, 0);

		glProgramUniform3f(PixelShader, 1, 1.0, 1.0, 1.0);

		glProgramUniform3f(PixelShader, 2, 0.9, 0.8, 0.8);

		glProgramUniform3f(PixelShader, 3, 0.0, 0.0, 1.0);

		glProgramUniform3fv(PixelShader, 4, 1, (float*)CameraPosition);

		glBindVertexArray(VertexArray);

		glBindTextureUnit(0, Texture0);

		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		glBindVertexArray(0);
		
		glBindProgramPipeline(0);

		Present(Window);
		
		PollEvents();
	}

	DeleteWindow(Window);

Exit:

	return(0);
}
