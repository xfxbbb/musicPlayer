#pragma once

struct ImageBuffer {
	ImageBuffer() :buffer{ nullptr }, buffer_size{ 0 }, width{ 0 }, height{ 0 } {}
	ImageBuffer(void* buffer, size_t size, int w, int h) :buffer{ buffer }, buffer_size{ size }, width{ w }, height{ h } {}
	void* buffer;
	size_t buffer_size;
	int width;
	int height;
};
