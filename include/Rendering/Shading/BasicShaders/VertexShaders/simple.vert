#version 330 core

layout(location = 0) in vec3 aPos;

uniform mat4 modelTransformationMatrix;

out vec3 FragPos;

void main()
{
    FragPos = vec3(modelTransformationMatrix * vec4(aPos, 1.0));
    gl_Position = vec4(FragPos, 1.0);
}

