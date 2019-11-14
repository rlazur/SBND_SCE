# Install script for directory: /sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./gallery_SCEcorrections" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./gallery_SCEcorrections")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./gallery_SCEcorrections"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE FILES "/sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build/gallery_SCEcorrections")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./gallery_SCEcorrections" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./gallery_SCEcorrections")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./gallery_SCEcorrections"
         OLD_RPATH "/cvmfs/larsoft.opensciencegrid.org/products/root/v6_16_00/Linux64bit+2.6-2.12-e17-prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/fhiclcpp/v4_09_03/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/messagefacility/v2_04_03/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/cetlib_except/v1_03_03/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/cetlib/v3_07_02/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/canvas_root_io/v1_03_04/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/canvas/v3_07_04/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/gallery/v1_12_04/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/hep_concurrency/v1_03_03/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/nusimdata/v1_17_01/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/larcoreobj/v08_05_01/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/lardataobj/v08_04_06/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/clhep/v2_4_1_0b/Linux64bit+2.6-2.12-e17-prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/larcorealg/v08_14_00/slf6.x86_64.e17.prof/lib:/cvmfs/larsoft.opensciencegrid.org/products/lardataalg/v08_08_01/slf6.x86_64.e17.prof/lib:/cvmfs/sbnd.opensciencegrid.org/products/sbnd/sbndcode/v08_27_00/slf6.x86_64.e17.prof/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./gallery_SCEcorrections")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/sbnd/app/users/rlazur/work/SCEvalidation/SBND_SCE/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
