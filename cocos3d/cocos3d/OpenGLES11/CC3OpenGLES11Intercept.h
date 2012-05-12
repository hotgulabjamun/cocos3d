/*
 * CC3OpenGLES11Intercept.h
 *
 * cocos3d 0.7.1
 * Author: Bill Hollings
 * Copyright (c) 2010-2012 The Brenwill Workshop Ltd. All rights reserved.
 * http://www.brenwill.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * http://en.wikipedia.org/wiki/MIT_License
 *
 * See header file CC3OpenGLES11Intercept.h for full API documentation.
 */

/** @file */	// Doxygen marker

/**
 * This file adds the ability to intercept all OpenGL ES 1.1 gl* calls in order to
 * log the call to stdout, using printf, before actually making the call into the
 * OpenGL ES 1.1 library. The result is a log trace of all gl* calls, including
 * the parameters used in each call.
 *
 * Include this file at the top of any files that perform OopenGLES calls, or
 * in a header file that is subsequently included wherever GL calls are made.
 *
 * To be generically usable, this code is written in straight C. When including this
 * header in C++ (.cpp) or Objective-C++ (.mm) files, wrap the include statement in
 * an extern "C" declaration, as follows:
 *
 *   extern "C" {
 *     #include "CC3OpenGLES11Intercept.h"
 *   }
 *
 * This wrapping is NOT necessary when including this header in Objective-C (.m) files. 
 *
 * To enable logging all GL calls in any code that includes this file, set the compiler
 * switch GL_LOGGING_ENABLED to 1. This can be set either in code, or as a compiler
 * runtime parameter. Using a compiler runtime parameter is preferred.
 *
 * The call-intercepting behaviour is implemented by re-defining each gl* function
 * to an alias that generates the log entry before calling the original gl* function.
 * With the GL_LOGGING_ENABLED set to 0, this aliasing and redirecting is completely
 * skipped by the compiler. As a result, there is no runtime penalty incurred by this
 * code when GL_LOGGING_ENABLED is set to 0. You can safely leave this file included
 * in your header files at all times, even when building production code, provided
 * the GL_LOGGING_ENABLED switch is not set to 1.
 *
 * Logging all OpenGL libraries obviously incurs significant runtime overhead.
 * You should only set the GL_LOGGING_ENABLED switch to 1 when you specifically
 * need to log OpenGL calls. The default value of this switch is 0, so GL logging
 * is turned off by default.
 *
 * Use the compiler runtime parameter kPrintGLDataVertexCount to control how many
 * elements of the data should be logged when data is passed to GL calls as data
 * pointers (eg. glVertexPointer, glColorPointer, etc). The default value is 8.
 *
 * Since many of the GL pointer data functions accept offsets for the pointer when
 * used with data that has been bound, the compiler parameter kMinGLPointerAddress
 * sets the minimum value for a pointer to be considered an address rather than an
 * offset. For pointer values below this level, no attempt is made to extract data
 * at that address. The default value is 8192.
 *
 * Use the compiler parameter kPrintGLDataBufferDataCount to control how many elements
 * of the data should be logged when data is passed as buffer data (eg. glBufferData).
 * The default value is 64.
 */

#include <OpenGLES/ES1/gl.h>


extern const GLubyte* glGetStringLogged(GLenum name);
extern GLboolean glIsBufferLogged(GLuint buffer);
extern GLboolean glIsEnabledLogged(GLenum cap);
extern GLboolean glIsTextureLogged(GLuint texture);
extern GLenum glGetErrorLogged(void);
extern void glActiveTextureLogged(GLenum texture);
extern void glAlphaFuncLogged(GLenum func, GLclampf ref);
extern void glAlphaFuncxLogged(GLenum func, GLclampx ref);
extern void glBindBufferLogged(GLenum target, GLuint buffer);
extern void glBindTextureLogged(GLenum target, GLuint texture);
extern void glBlendFuncLogged(GLenum sfactor, GLenum dfactor);
extern void glBufferDataLogged(GLenum target, GLsizeiptr size, const GLvoid *data, GLenum usage);
extern void glBufferSubDataLogged(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid *data);
extern void glClearColorLogged(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
extern void glClearColorxLogged(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
extern void glClearDepthfLogged(GLclampf depth);
extern void glClearDepthxLogged(GLclampx depth);
extern void glClearLogged(GLbitfield mask);
extern void glClearStencilLogged(GLint s);
extern void glClientActiveTextureLogged(GLenum texture);
extern void glClipPlanefLogged(GLenum plane, const GLfloat *equation);
extern void glClipPlanexLogged(GLenum plane, const GLfixed *equation);
extern void glColor4fLogged(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
extern void glColor4ubLogged(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
extern void glColor4xLogged(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
extern void glColorMaskLogged(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
extern void glColorPointerLogged(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glCompressedTexImage2DLogged(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
extern void glCompressedTexSubImage2DLogged(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
extern void glCopyTexImage2DLogged(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
extern void glCopyTexSubImage2DLogged(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
extern void glCullFaceLogged(GLenum mode);
extern void glDeleteBuffersLogged(GLsizei n, const GLuint *buffers);
extern void glDeleteTexturesLogged(GLsizei n, const GLuint *textures);
extern void glDepthFuncLogged(GLenum func);
extern void glDepthMaskLogged(GLboolean flag);
extern void glDepthRangefLogged(GLclampf zNear, GLclampf zFar);
extern void glDepthRangexLogged(GLclampx zNear, GLclampx zFar);
extern void glDisableClientStateLogged(GLenum array);
extern void glDisableLogged(GLenum cap);
extern void glDrawArraysLogged(GLenum mode, GLint first, GLsizei count);
extern void glDrawElementsLogged(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
extern void glEnableClientStateLogged(GLenum array);
extern void glEnableLogged(GLenum cap);
extern void glFinishLogged(void);
extern void glFlushLogged(void);
extern void glFogfLogged(GLenum pname, GLfloat param);
extern void glFogfvLogged(GLenum pname, const GLfloat *params);
extern void glFogxLogged(GLenum pname, GLfixed param);
extern void glFogxvLogged(GLenum pname, const GLfixed *params);
extern void glFrontFaceLogged(GLenum mode);
extern void glFrustumfLogged(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
extern void glFrustumxLogged(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
extern void glGenBuffersLogged(GLsizei n, GLuint *buffers);
extern void glGenTexturesLogged(GLsizei n, GLuint *textures);
extern void glGetBooleanvLogged(GLenum pname, GLboolean *params);
extern void glGetBufferParameterivLogged(GLenum target, GLenum pname, GLint *params);
extern void glGetClipPlanefLogged(GLenum pname, GLfloat *equation);
extern void glGetClipPlanexLogged(GLenum pname, GLfixed eqn[4]);
extern void glGetFixedvLogged(GLenum pname, GLfixed *params);
extern void glGetFloatvLogged(GLenum pname, GLfloat *params);
extern void glGetIntegervLogged(GLenum pname, GLint *params);
extern void glGetLightfvLogged(GLenum light, GLenum pname, GLfloat *params);
extern void glGetLightxvLogged(GLenum light, GLenum pname, GLfixed *params);
extern void glGetMaterialfvLogged(GLenum face, GLenum pname, GLfloat *params);
extern void glGetMaterialxvLogged(GLenum face, GLenum pname, GLfixed *params);
extern void glGetPointervLogged(GLenum pname, void **params);
extern void glGetTexEnvfvLogged(GLenum env, GLenum pname, GLfloat *params);
extern void glGetTexEnvivLogged(GLenum env, GLenum pname, GLint *params);
extern void glGetTexEnvxvLogged(GLenum env, GLenum pname, GLfixed *params);
extern void glGetTexParameterfvLogged(GLenum target, GLenum pname, GLfloat *params);
extern void glGetTexParameterivLogged(GLenum target, GLenum pname, GLint *params);
extern void glGetTexParameterxvLogged(GLenum target, GLenum pname, GLfixed *params);
extern void glHintLogged(GLenum target, GLenum mode);
extern void glLightfLogged(GLenum light, GLenum pname, GLfloat param);
extern void glLightfvLogged(GLenum light, GLenum pname, const GLfloat *params);
extern void glLightModelfLogged(GLenum pname, GLfloat param);
extern void glLightModelfvLogged(GLenum pname, const GLfloat *params);
extern void glLightModelxLogged(GLenum pname, GLfixed param);
extern void glLightModelxvLogged(GLenum pname, const GLfixed *params);
extern void glLightxLogged(GLenum light, GLenum pname, GLfixed param);
extern void glLightxvLogged(GLenum light, GLenum pname, const GLfixed *params);
extern void glLineWidthLogged(GLfloat width);
extern void glLineWidthxLogged(GLfixed width);
extern void glLoadIdentityLogged(void);
extern void glLoadMatrixfLogged(const GLfloat *m);
extern void glLoadMatrixxLogged(const GLfixed *m);
extern void glLogicOpLogged(GLenum opcode);
extern void glMaterialfLogged(GLenum face, GLenum pname, GLfloat param);
extern void glMaterialfvLogged(GLenum face, GLenum pname, const GLfloat *params);
extern void glMaterialxLogged(GLenum face, GLenum pname, GLfixed param);
extern void glMaterialxvLogged(GLenum face, GLenum pname, const GLfixed *params);
extern void glMatrixModeLogged(GLenum mode);
extern void glMultiTexCoord4fLogged(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void glMultiTexCoord4xLogged(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
extern void glMultMatrixfLogged(const GLfloat *m);
extern void glMultMatrixxLogged(const GLfixed *m);
extern void glNormal3fLogged(GLfloat nx, GLfloat ny, GLfloat nz);
extern void glNormal3xLogged(GLfixed nx, GLfixed ny, GLfixed nz);
extern void glNormalPointerLogged(GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glOrthofLogged(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar);
extern void glOrthoxLogged(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed zNear, GLfixed zFar);
extern void glPixelStoreiLogged(GLenum pname, GLint param);
extern void glPointParameterfLogged(GLenum pname, GLfloat param);
extern void glPointParameterfvLogged(GLenum pname, const GLfloat *params);
extern void glPointParameterxLogged(GLenum pname, GLfixed param);
extern void glPointParameterxvLogged(GLenum pname, const GLfixed *params);
extern void glPointSizeLogged(GLfloat size);
extern void glPointSizexLogged(GLfixed size);
extern void glPolygonOffsetLogged(GLfloat factor, GLfloat units);
extern void glPolygonOffsetxLogged(GLfixed factor, GLfixed units);
extern void glPopMatrixLogged(void);
extern void glPushMatrixLogged(void);
extern void glReadPixelsLogged(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
extern void glRotatefLogged(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
extern void glRotatexLogged(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
extern void glSampleCoverageLogged(GLclampf value, GLboolean invert);
extern void glSampleCoveragexLogged(GLclampx value, GLboolean invert);
extern void glScalefLogged(GLfloat x, GLfloat y, GLfloat z);
extern void glScalexLogged(GLfixed x, GLfixed y, GLfixed z);
extern void glScissorLogged(GLint x, GLint y, GLsizei width, GLsizei height);
extern void glShadeModelLogged(GLenum mode);
extern void glStencilFuncLogged(GLenum func, GLint ref, GLuint mask);
extern void glStencilMaskLogged(GLuint mask);
extern void glStencilOpLogged(GLenum fail, GLenum zfail, GLenum zpass);
extern void glTexCoordPointerLogged(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glTexEnvfLogged(GLenum target, GLenum pname, GLfloat param);
extern void glTexEnvfvLogged(GLenum target, GLenum pname, const GLfloat *params);
extern void glTexEnviLogged(GLenum target, GLenum pname, GLint param);
extern void glTexEnvivLogged(GLenum target, GLenum pname, const GLint *params);
extern void glTexEnvxLogged(GLenum target, GLenum pname, GLfixed param);
extern void glTexEnvxvLogged(GLenum target, GLenum pname, const GLfixed *params);
extern void glTexImage2DLogged(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTexParameterfLogged(GLenum target, GLenum pname, GLfloat param);
extern void glTexParameterfvLogged(GLenum target, GLenum pname, const GLfloat *params);
extern void glTexParameteriLogged(GLenum target, GLenum pname, GLint param);
extern void glTexParameterivLogged(GLenum target, GLenum pname, const GLint *params);
extern void glTexParameterxLogged(GLenum target, GLenum pname, GLfixed param);
extern void glTexParameterxvLogged(GLenum target, GLenum pname, const GLfixed *params);
extern void glTexSubImage2DLogged(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
extern void glTranslatefLogged(GLfloat x, GLfloat y, GLfloat z);
extern void glTranslatexLogged(GLfixed x, GLfixed y, GLfixed z);
extern void glVertexPointerLogged(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glViewportLogged(GLint x, GLint y, GLsizei width, GLsizei height);
extern void gTexEnvfvLogged(GLenum target, GLenum pname, const GLfloat *params);


extern void glCurrentPaletteMatrixOESLogged(GLuint matrixpaletteindex);
extern void glDrawTexfOESLogged(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height);
extern void glDrawTexfvOESLogged(const GLfloat *coords);
extern void glDrawTexiOESLogged(GLint x, GLint y, GLint z, GLint width, GLint height);
extern void glDrawTexivOESLogged(const GLint *coords);
extern void glDrawTexsOESLogged(GLshort x, GLshort y, GLshort z, GLshort width, GLshort height);
extern void glDrawTexsvOESLogged(const GLshort *coords);
extern void glDrawTexxOESLogged(GLfixed x, GLfixed y, GLfixed z, GLfixed width, GLfixed height);
extern void glDrawTexxvOESLogged(const GLfixed *coords);
extern void glLoadPaletteFromModelViewMatrixOESLogged(void);
extern void glMatrixIndexPointerOESLogged(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glPointSizePointerOESLogged(GLenum type, GLsizei stride, const GLvoid *pointer);
extern void glWeightPointerOESLogged(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);


extern GLboolean glIsFramebufferOESLogged(GLuint framebuffer);
extern GLboolean glIsRenderbufferOESLogged(GLuint renderbuffer);
extern GLboolean glUnmapBufferOESLogged(GLenum target);
extern GLenum glCheckFramebufferStatusOESLogged(GLenum target);
extern void glBindFramebufferOESLogged(GLenum target, GLuint framebuffer);
extern void glBindRenderbufferOESLogged(GLenum target, GLuint renderbuffer);
extern void glBlendEquationOESLogged(GLenum mode);
extern void glDeleteFramebuffersOESLogged(GLsizei n, const GLuint* framebuffers);
extern void glDeleteRenderbuffersOESLogged(GLsizei n, const GLuint* renderbuffers);
extern void glFramebufferRenderbufferOESLogged(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
extern void glFramebufferTexture2DOESLogged(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
extern void glGenerateMipmapOESLogged(GLenum target);
extern void glGenFramebuffersOESLogged(GLsizei n, GLuint* framebuffers);
extern void glGenRenderbuffersOESLogged(GLsizei n, GLuint* renderbuffers);
extern void glGetBufferPointervOESLogged(GLenum target, GLenum pname, GLvoid **params);
extern void glGetFramebufferAttachmentParameterivOESLogged(GLenum target, GLenum attachment, GLenum pname, GLint* params);
extern void glGetRenderbufferParameterivOESLogged(GLenum target, GLenum pname, GLint* params);
extern void glRenderbufferStorageOESLogged(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
extern GLvoid* glMapBufferOESLogged(GLenum target, GLenum access);


#ifndef GL_LOGGING_ENABLED
#	define GL_LOGGING_ENABLED		0
#endif

#if defined(GL_LOGGING_ENABLED) && GL_LOGGING_ENABLED
 
#pragma mark OpenGLES base

#define glActiveTexture glActiveTextureLogged
#define glAlphaFunc glAlphaFuncLogged
#define glAlphaFuncx glAlphaFuncxLogged
#define glBindBuffer glBindBufferLogged
#define glBindTexture glBindTextureLogged
#define glBlendFunc glBlendFuncLogged
#define glBufferData glBufferDataLogged
#define glBufferSubData glBufferSubDataLogged
#define glClear glClearLogged
#define glClearColor glClearColorLogged
#define glClearColorx glClearColorxLogged
#define glClearDepthf glClearDepthfLogged
#define glClearDepthx glClearDepthxLogged
#define glClearStencil glClearStencilLogged
#define glClientActiveTexture glClientActiveTextureLogged
#define glClipPlanef glClipPlanefLogged
#define glClipPlanex glClipPlanexLogged
#define glColor4f glColor4fLogged
#define glColor4ub glColor4ubLogged
#define glColor4x glColor4xLogged
#define glColorMask glColorMaskLogged
#define glColorPointer glColorPointerLogged
#define glCompressedTexImage2D glCompressedTexImage2DLogged
#define glCompressedTexSubImage2D glCompressedTexSubImage2DLogged
#define glCopyTexImage2D glCopyTexImage2DLogged
#define glCopyTexSubImage2D glCopyTexSubImage2DLogged
#define glCullFace glCullFaceLogged
#define glDeleteBuffers glDeleteBuffersLogged
#define glDeleteTextures glDeleteTexturesLogged
#define glDepthFunc glDepthFuncLogged
#define glDepthMask glDepthMaskLogged
#define glDepthRangef glDepthRangefLogged
#define glDepthRangex glDepthRangexLogged
#define glDisable glDisableLogged
#define glDisableClientState glDisableClientStateLogged
#define glDrawArrays glDrawArraysLogged
#define glDrawElements glDrawElementsLogged
#define glEnable glEnableLogged
#define glEnableClientState glEnableClientStateLogged
#define glFinish glFinishLogged
#define glFlush glFlushLogged
#define glFogf glFogfLogged
#define glFogfv glFogfvLogged
#define glFogx glFogxLogged
#define glFogxv glFogxvLogged
#define glFrontFace glFrontFaceLogged
#define glFrustumf glFrustumfLogged
#define glFrustumx glFrustumxLogged
#define glGenBuffers glGenBuffersLogged
#define glGenTextures glGenTexturesLogged
#define glGetBooleanv glGetBooleanvLogged
#define glGetBufferParameteriv glGetBufferParameterivLogged
#define glGetClipPlanef glGetClipPlanefLogged
#define glGetClipPlanex glGetClipPlanexLogged
#define glGetError glGetErrorLogged
#define glGetFixedv glGetFixedvLogged
#define glGetFloatv glGetFloatvLogged
#define glGetIntegerv glGetIntegervLogged
#define glGetLightfv glGetLightfvLogged
#define glGetLightxv glGetLightxvLogged
#define glGetMaterialfv glGetMaterialfvLogged
#define glGetMaterialxv glGetMaterialxvLogged
#define glGetPointerv glGetPointervLogged
#define glGetString glGetStringLogged
#define glGetTexEnvfv glGetTexEnvfvLogged
#define glGetTexEnviv glGetTexEnvivLogged
#define glGetTexEnvxv glGetTexEnvxvLogged
#define glGetTexParameterfv glGetTexParameterfvLogged
#define glGetTexParameteriv glGetTexParameterivLogged
#define glGetTexParameterxv glGetTexParameterxvLogged
#define glHint glHintLogged
#define glIsBuffer glIsBufferLogged
#define glIsEnabled glIsEnabledLogged
#define glIsTexture glIsTextureLogged
#define glLightf glLightfLogged
#define glLightfv glLightfvLogged
#define glLightModelf glLightModelfLogged
#define glLightModelfv glLightModelfvLogged
#define glLightModelx glLightModelxLogged
#define glLightModelxv glLightModelxvLogged
#define glLightx glLightxLogged
#define glLightxv glLightxvLogged
#define glLineWidth glLineWidthLogged
#define glLineWidthx glLineWidthxLogged
#define glLoadIdentity glLoadIdentityLogged
#define glLoadMatrixf glLoadMatrixfLogged
#define glLoadMatrixx glLoadMatrixxLogged
#define glLogicOp glLogicOpLogged
#define glMaterialf glMaterialfLogged
#define glMaterialfv glMaterialfvLogged
#define glMaterialx glMaterialxLogged
#define glMaterialxv glMaterialxvLogged
#define glMatrixMode glMatrixModeLogged
#define glMultiTexCoord4f glMultiTexCoord4fLogged
#define glMultiTexCoord4x glMultiTexCoord4xLogged
#define glMultMatrixf glMultMatrixfLogged
#define glMultMatrixx glMultMatrixxLogged
#define glNormal3f glNormal3fLogged
#define glNormal3x glNormal3xLogged
#define glNormalPointer glNormalPointerLogged
#define glOrthof glOrthofLogged
#define glOrthox glOrthoxLogged
#define glPixelStorei glPixelStoreiLogged
#define glPointParameterf glPointParameterfLogged
#define glPointParameterfv glPointParameterfvLogged
#define glPointParameterx glPointParameterxLogged
#define glPointParameterxv glPointParameterxvLogged
#define glPointSize glPointSizeLogged
#define glPointSizex glPointSizexLogged
#define glPolygonOffset glPolygonOffsetLogged
#define glPolygonOffsetx glPolygonOffsetxLogged
#define glPopMatrix glPopMatrixLogged
#define glPushMatrix glPushMatrixLogged
#define glReadPixels glReadPixelsLogged
#define glRotatef glRotatefLogged
#define glRotatex glRotatexLogged
#define glSampleCoverage glSampleCoverageLogged
#define glSampleCoveragex glSampleCoveragexLogged
#define glScalef glScalefLogged
#define glScalex glScalexLogged
#define glScissor glScissorLogged
#define glShadeModel glShadeModelLogged
#define glStencilFunc glStencilFuncLogged
#define glStencilMask glStencilMaskLogged
#define glStencilOp glStencilOpLogged
#define glTexCoordPointer glTexCoordPointerLogged
#define glTexEnvf glTexEnvfLogged
#define glTexEnvfv glTexEnvfvLogged
#define glTexEnvi glTexEnviLogged
#define glTexEnviv glTexEnvivLogged
#define glTexEnvx glTexEnvxLogged
#define glTexEnvxv glTexEnvxvLogged
#define glTexImage2D glTexImage2DLogged
#define glTexParameterf glTexParameterfLogged
#define glTexParameterfv glTexParameterfvLogged
#define glTexParameteri glTexParameteriLogged
#define glTexParameteriv glTexParameterivLogged
#define glTexParameterx glTexParameterxLogged
#define glTexParameterxv glTexParameterxvLogged
#define glTexSubImage2D glTexSubImage2DLogged
#define glTranslatef glTranslatefLogged
#define glTranslatex glTranslatexLogged
#define glVertexPointer glVertexPointerLogged
#define glViewport glViewportLogged
extern const glubyt


#pragma mark OpenGLES extensions from gl.h base file


#define glCurrentPaletteMatrixOES glCurrentPaletteMatrixOESLogged
#define glDrawTexfOES glDrawTexfOESLogged
#define glDrawTexfvOES glDrawTexfvOESLogged
#define glDrawTexiOES glDrawTexiOESLogged
#define glDrawTexivOES glDrawTexivOESLogged
#define glDrawTexsOES glDrawTexsOESLogged
#define glDrawTexsvOES glDrawTexsvOESLogged
#define glDrawTexxOES glDrawTexxOESLogged
#define glDrawTexxvOES glDrawTexxvOESLogged
#define glLoadPaletteFromModelViewMatrixOES glLoadPaletteFromModelViewMatrixOESLogged
#define glMatrixIndexPointerOES glMatrixIndexPointerOESLogged
#define glPointSizePointerOES glPointSizePointerOESLogged
#define glWeightPointerOES glWeightPointerOESLogged


#pragma mark OpenGLES extensions from glext.h extensions file


#define glBindFramebufferOES glBindFramebufferOESLogged
#define glBindRenderbufferOES glBindRenderbufferOESLogged
#define glBlendEquationOES glBlendEquationOESLogged
#define glCheckFramebufferStatusOES glCheckFramebufferStatusOESLogged
#define glDeleteFramebuffersOES glDeleteFramebuffersOESLogged
#define glDeleteRenderbuffersOES glDeleteRenderbuffersOESLogged
#define glFramebufferRenderbufferOES glFramebufferRenderbufferOESLogged
#define glFramebufferTexture2DOES glFramebufferTexture2DOESLogged
#define glGenerateMipmapOES glGenerateMipmapOESLogged
#define glGenFramebuffersOES glGenFramebuffersOESLogged
#define glGenRenderbuffersOES glGenRenderbuffersOESLogged
#define glGetBufferPointervOES glGetBufferPointervOESLogged
#define glGetFramebufferAttachmentParameterivOES glGetFramebufferAttachmentParameterivOESLogged
#define glGetRenderbufferParameterivOES glGetRenderbufferParameterivOESLogged
#define glIsFramebufferOES glIsFramebufferOESLogged
#define glIsRenderbufferOES glIsRenderbufferOESLogged
#define glMapBufferOES glMapBufferOESLogged
#define glRenderbufferStorageOES glRenderbufferStorageOESLogged
#define glUnmapBufferOES glUnmapBufferOESLogged

#endif
