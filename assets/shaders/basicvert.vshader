#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 texture_coordinate;

uniform mat4 ortho;

// // Notice that the "1" here equals the "1" in glVertexAttribPointer
// layout(location = 1) in vec3 vertexColor;

// // Values that stay constant for the whole mesh.
// uniform mat4 MVP;

// //Output data ; will be interpolated for each fragment.
out vec2 Texture_coordinate;

void main(){

	// Output position of the vertex, in clip space : MVP * position
	gl_Position =  ortho * vec4(vertexPosition_modelspace,1);

      // The color of each vertex will be interpolated
      // to produce the color of each fragment
			Texture_coordinate = texture_coordinate;
}
