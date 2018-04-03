/*****************************************************************************************
*                                                                                       *
* GHOUL                                                                                 *
* General Helpful Open Utility Library                                                  *
*                                                                                       *
* Copyright (c) 2012-2017                                                               *
*                                                                                       *
* Permission is hereby granted, free of charge, to any person obtaining a copy of this  *
* software and associated documentation files (the "Software"), to deal in the Software *
* without restriction, including without limitation the rights to use, copy, modify,    *
* merge, publish, distribute, sublicense, and/or sell copies of the Software, and to    *
* permit persons to whom the Software is furnished to do so, subject to the following   *
* conditions:                                                                           *
*                                                                                       *
* The above copyright notice and this permission notice shall be included in all copies *
* or substantial portions of the Software.                                              *
*                                                                                       *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,   *
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A         *
* PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT    *
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  *
* CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE  *
* OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                         *
****************************************************************************************/

#ifndef __OPENSPACE_MODULE_ROVER_TERRAIN_RENDERER___H__
#define __OPENSPACE_MODULE_ROVER_TERRAIN_RENDERER___H__

#include <ghoul/opengl/ghoul_gl.h>
#include <ghoul/glm.h>

namespace openspace {

class TextureArray {
public:
 TextureArray(glm::uvec3 dimensions, int size,
        GLenum format = (GLenum)GL_RGBA, GLenum internalFormat = (GLenum)GL_RGBA8, GLenum dataType = GL_UNSIGNED_BYTE,
  bool allocateData = true);

 //~TextureArray();

 void setType(GLenum type);
 void uploadTexture(const void* pixels);
 void allocateMemory();
 void determineTextureType();

 void bind() const;

 GLuint id();

private:
 glm::uvec3 _dimensions;
 int _counter;
 int _size;
 GLuint _id;
 GLenum _type, _dataType, _format, _internalFormat;

 void generateId();
 void initialize(bool allocateData);
};
}

#endif //__GHOUL___TEXTURE_ARRAY___H__
