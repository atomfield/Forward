
#include "Window.h"

#include "GL.h"

static const char* VertexShaderSource =
	"#version 460 core \n"

	"out gl_PerVertex \n"
	"{ \n"
	"	vec4 gl_Position;"
	"}; \n"

	"layout(location = 0) in vec3 Position;\n"
	"layout(location = 1) in vec3 Color;\n"

	"layout(location = 0) out vec3 VertexColor; \n"

	"void main() \n"
	"{ \n"
	"	VertexColor = Color; \n"
	"	gl_Position = vec4(Position, 1.0); \n"
	"} \n"
;

static const char* PixelShaderSource =
	"#version 460 core \n"

	"layout(location = 0) in vec3 VertexColor; \n"
	
	"layout(location = 0) out vec4 PixelColor; \n"

	"void main() \n"
	"{ \n"
	"	PixelColor = vec4(VertexColor * 0.5 + 0.5, 1.0); \n"
	"} \n"
;

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

	static const float Vertices[] =
	{
		-0.5f, -0.5f, 0.0f,		1.0, 0.0, 0.0,
		 0.5f, -0.5f, 0.0f,		0.0, 1.0, 0.0,
		-0.5f,  0.5f, 0.0f,		0.0, 0.0, 1.0,
		 0.5f,  0.5f, 0.0f,		1.0, 0.0, 1.0,
	};

	static const unsigned int Indices[] =
	{
		0, 1, 2,
		1, 2, 3,
	};
	
	unsigned int VertexBuffer;
	unsigned int IndexBuffer;

	glCreateBuffers(1, &VertexBuffer);
	
	glNamedBufferStorage(VertexBuffer, sizeof(Vertices), Vertices, GL_DYNAMIC_STORAGE_BIT);

	glCreateBuffers(1, &IndexBuffer);
	
	glNamedBufferStorage(IndexBuffer, sizeof(Indices), Indices, GL_DYNAMIC_STORAGE_BIT);

	unsigned int VertexArray;

	glCreateVertexArrays(1, &VertexArray);
	
	glVertexArrayVertexBuffer(VertexArray, 0, VertexBuffer, 0, sizeof(float) * 6);
	
	glVertexArrayElementBuffer(VertexArray, IndexBuffer);

	glEnableVertexArrayAttrib(VertexArray, 0);

	glEnableVertexArrayAttrib(VertexArray, 1);
	
	glVertexArrayAttribFormat(VertexArray, 0, 3, GL_FLOAT, GL_FALSE, 0);
	
	glVertexArrayAttribFormat(VertexArray, 1, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3);
	
	glVertexArrayAttribBinding(VertexArray, 0, 0);

	glVertexArrayAttribBinding(VertexArray, 1, 0);

	unsigned int VertexShader = glCreateShaderProgramv(GL_VERTEX_SHADER, 1, &VertexShaderSource);
	
	unsigned int PixelShader = glCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &PixelShaderSource);

	unsigned int Pipeline;

	glCreateProgramPipelines(1, &Pipeline);

	glUseProgramStages(Pipeline, GL_VERTEX_SHADER_BIT, VertexShader);

	glUseProgramStages(Pipeline, GL_FRAGMENT_SHADER_BIT, PixelShader);

	glClearColor(0.1f, 0.1f, 0.2f, 1.0f);

	while (!Closed(Window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBindProgramPipeline(Pipeline);
		glBindVertexArray(VertexArray);
		
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
		
		glBindVertexArray(0);
		glBindProgramPipeline(0);

		Present(Window);
		PollEvents();
	}

	DeleteWindow(Window);

Exit:

	return(0);
}
