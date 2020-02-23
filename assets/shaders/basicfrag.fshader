#version 330 core
// Interpolated values from the vertex shaders
in vec2 Texture_coordinate;
out vec4 color;

uniform sampler2D image1;
uniform sampler2D image2;

void main(){
  color = vec4(1,0,0,1);
    // Output color = color specified in the vertex shader,
    // interpolated between all 3 surrounding vertices
    vec4 tex_color = texture(image1, Texture_coordinate);
    if (tex_color.a < 0.1)
      discard;
    vec4 tex_n_color = texture(image2, Texture_coordinate);
    if (tex_n_color.a < 0.1)
        discard;
    float dotProduct = dot(tex_n_color, normalize(vec4(1.0f,0.0f, 0.0f, 0.0f)));
    // if (dotProduct < 0.3)
    // {
    //   color = tex_color * 0.6;
    // }
    // else
    // {
    //   color = tex_color;
    //   // color = vec4(dotProduct, 0, 0, 1);
    // }
    if (dotProduct > 0.5)
    {
      color = tex_color + vec4(0.1f,0.1f, 1.0f, 0.0f) * max(dotProduct, 0) * 5;
    }
    else
    {
      color = tex_color;
    }
  // color = vec4(1.0f,1.0f, 1.0f, 1.0f);
}
