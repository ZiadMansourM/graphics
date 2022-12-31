#version 330

// The texture holding the scene pixels
uniform sampler2D tex;

//iTime is a uniform variable that holds the time in seconds since the program started
uniform float iTime;

// Read "assets/shaders/fullscreen.vert" to know what "tex_coord" holds;
in vec2 tex_coord;
out vec4 frag_color;

//write main function that can simulate bloom effect
void main()
{		
	vec2 uv = tex_coord;
	vec2 resolution = vec2(1024,1024);
	float intensity = 0.5;
	float threshold = 0.5;
	float radius = 1.0;
	float strength = 0.5;

	vec2 texel = vec2(1.0) / resolution;
	vec2 coord = uv;

	vec4 color = vec4(0.0);

	float weight = 0.0;

	for(int x = -30; x <= 30; x++)
	{
		for(int y = -30; y <= 30; y++)
		{
			vec2 sample = vec2(x, y) * texel;
			vec4 sampleColor = texture(tex, coord + sample);
			float dist = distance(vec2(0.0), sample);
			weight += (1.0 - smoothstep(0.0, 1.0, dist / radius)) * (1.0 - threshold) + threshold;
			color += sampleColor * (1.0 - smoothstep(0.0, 1.0, dist / radius)) * (1.0 - threshold) + threshold;
		}
	}

	color /= weight;
	color = mix(color, texture(tex, uv), intensity);
	color = mix(color, vec4(1.0) - exp(-color * strength), intensity);

	frag_color = color;
}