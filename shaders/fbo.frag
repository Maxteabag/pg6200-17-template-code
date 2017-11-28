#version 150

uniform sampler2D texture;

in vec2 tex_coord;

out vec4 res_colour;

void main(){
	vec4 colour = texture2D(texture, tex_coord.xy);
	res_colour = vec4(colour.xxx, 0.8f);

	// get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
   // float closestDepth = texture(shadowMap, projCoords.xy).r; 
}