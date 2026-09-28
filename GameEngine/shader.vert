#version 330 core
layout (location = 0) in vec3 aPos;

uniform vec2 uOffset;
uniform float uRotZ;

void main()
{
    float rotatedX = aPos.x * cos(uRotZ) - aPos.y * sin(uRotZ);
    float rotatedY = aPos.x * sin(uRotZ) + aPos.y * cos(uRotZ);

    gl_Position = vec4(rotatedX + uOffset.x, rotatedY + uOffset.y, aPos.z, 1.0);
}