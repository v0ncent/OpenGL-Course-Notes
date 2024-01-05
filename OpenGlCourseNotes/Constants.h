# pragma once
const char* vertexShaderSource = "#version 330 core\n"  "layout (location = 0) in vec3 aPos;\n"  "void main()\n"  "{\n"  "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"  "}\0";
const char* fragmentShaderSource = "#version 330 core\n"  "out vec4 FragColor;\n"  "void main()\n"  "{\n"  "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"  "}\n\0";

const char* windowName = "OpenGLCourseNotes";

struct RGBColor {
	float R;
	float G;
	float B;
	float C;
};

RGBColor* backgroundColor = (struct RGBColor*)malloc(sizeof(struct RGBColor));