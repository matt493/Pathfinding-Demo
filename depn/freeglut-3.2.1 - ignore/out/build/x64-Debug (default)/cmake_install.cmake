# Install script for directory: M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/install/x64-Debug (default)")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/lib/freeglutd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/bin/freeglutd.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/bin/freeglutd.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/lib/freeglut_staticd.lib")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/GL" TYPE FILE FILES
    "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/include/GL/freeglut.h"
    "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/include/GL/freeglut_ucall.h"
    "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/include/GL/freeglut_ext.h"
    "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/include/GL/freeglut_std.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE RENAME "freeglut.pc" FILES "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/freeglut.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake"
         "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/CMakeFiles/Export/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT" TYPE FILE FILES "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/CMakeFiles/Export/lib/cmake/FreeGLUT/FreeGLUTTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT" TYPE FILE FILES "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/CMakeFiles/Export/lib/cmake/FreeGLUT/FreeGLUTTargets-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/FreeGLUT" TYPE FILE FILES
    "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/FreeGLUT/FreeGLUTConfig.cmake"
    "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/FreeGLUT/FreeGLUTConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "M:/STUDY/S3/CG/CG_project/depn/freeglut-3.2.1 - ignore/out/build/x64-Debug (default)/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
