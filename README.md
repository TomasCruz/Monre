Monre - multithreaded OpenGL (ES 2.0) .NET rendering engine
=====

Licensed under the MIT license, see LICENSE.md for details.




Monre is a 3D rendering engine primarily intended for running OpenGL ES 2.0 games on Windows. It is, however, intended to provide a generic framework for any kind of C/C++ OpenGL application, using any version of OpenGL. It is a lightweight tool designed to help with development, testing, debugging and portability checking of native C/C++ parts of Android and iOS games.

It was initially developed using vs2008. vs2012 solution and project files were also added. Porting to other versions of Visual Studio shouldn't be too problematic.



MonreDemoApplication description
---------------------------------------------------------

Reusable parts of MonreDemoApplication are projects OpenGLForm and ThreadManager.
- OpenGLForm contains inherited Win Form enabled for OpenGL rendering. It can also go full screen.
- ThreadManager is a collection of classes for managing threads used in application. Some of classes are abstract and some are ready to use as they are.

More detailed description of Monre projects, and how to use Monre can be found at https://github.com/TomasCruz/Monre/wiki/Monre-tutorial

Other projects in MonreDemoApplication:
- NativeApp contains native code for rendering a pyramid. It doesn't depend on any library, but an application using the engine might do so. Anything in NativeApp apart from NativeApplication and NativeException (which are obviously specific) can be reused. LoadUtil is specifically made to load OpenGL ES 2.0 functions, all of them and nothing but them, and is made out of GL Load library of Unofficial OpenGL SDK basically by removing it's portability to keep things simple and contained in one class (well, more of a glorified function really). However, any library can be used for things like in Monre Util classes, it would be a matter of adding one or more native projects to the solution.
- WrappedNativeApp is a .NET wrapper project.
- ApplicationDll provides specific form (enabling customization of icon and such) and inherited ThreadWrapper classes.
- OpenGLFormApplication is a top level project, containing the start form (for setting application parameters)

Last two projects can be merged in one, and can be written in any .NET language.
