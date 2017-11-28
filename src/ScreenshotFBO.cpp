#include "ScreenshotFBO.h"
#include "GLUtils/GLUtils.hpp"

ScreenshotFBO::ScreenshotFBO(unsigned int width, unsigned int height) {
	this->width = width;
	this->height = height;

	// Initialize Depth Texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr); //this is in the shadow texure comment block
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT_EXT, GL_TEXTURE_2D, texture, 0);
	glBindFramebuffer(GL_FRAMEBUFFER_EXT, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}


ScreenshotFBO::~ScreenshotFBO()
{
	glDeleteFramebuffersEXT(1, &fbo);
}

void ScreenshotFBO::bind() {
	glBindFramebufferEXT(GL_FRAMEBUFFER, fbo);
}

void ScreenshotFBO::unbind() {
	glBindFramebufferEXT(GL_FRAMEBUFFER, 0);
}