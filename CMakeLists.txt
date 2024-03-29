################################################################################
###  CMakeLists.txt for gallery analysis executables
################################################################################
###
###  Usage:
###  1) edit the EXECUTABLE section adding executable names ("targets"),
###     the header paths they need, and the libraries they link to
###  2) create a build directory and run `cmake` from there:
###      
###      mkdir -p build
###      cd build
###      cmake ..
###      make
###      
###  This CMakeLists.txt file was configured to use:
###  - C++ compiler: /cvmfs/larsoft.opensciencegrid.org/products/gcc/v7_3_0/Linux64bit+2.6-2.12/bin/g++ with standard C++17
###  - C compiler:   /cvmfs/larsoft.opensciencegrid.org/products/gcc/v7_3_0/Linux64bit+2.6-2.12/bin/gcc
###  - build type:   Prof
###
################################################################################
cmake_minimum_required(VERSION 3.1)

# ensure that the right compiler is used (may fail miserably):
set(CMAKE_BUILD_TYPE   "Prof" )
set(CMAKE_C_COMPILER   "/cvmfs/larsoft.opensciencegrid.org/products/gcc/v7_3_0/Linux64bit+2.6-2.12/bin/gcc" )
set(CMAKE_CXX_COMPILER "/cvmfs/larsoft.opensciencegrid.org/products/gcc/v7_3_0/Linux64bit+2.6-2.12/bin/g++" )
set(CMAKE_CXX_STANDARD "17" )

project(gallery_SCEcorrections CXX)


# install in the same directory as the source
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

#
# include directories
#
include_directories($ENV{BOOST_INC})
include_directories($ENV{ROOT_INC} $ENV{CLHEP_INC})
include_directories($ENV{CETLIB_INC} $ENV{CETLIB_EXCEPT_INC} $ENV{CANVAS_INC} $ENV{CANVAS_ROOT_IO_INC})
include_directories($ENV{FHICLCPP_INC} $ENV{MESSAGEFACILITY_INC})
include_directories($ENV{GALLERY_INC})
include_directories($ENV{NUSIMDATA_INC} $ENV{LARCOREOBJ_INC} $ENV{LARDATAOBJ_INC})
include_directories($ENV{LARCOREALG_INC} $ENV{LARDATAALG_INC})

include_directories($ENV{SBNDCODE_INC})

include_directories($ENV{HEP_CONCURRENCY_INC})

#
# link directories and libraries
#
set(ROOT_LIBDIRS $ENV{ROOTSYS}/lib )
set(GALLERY_LIBDIRS
  ${ROOT_LIBDIRS}
  $ENV{FHICLCPP_LIB} $ENV{MESSAGEFACILITY_LIB}
  $ENV{CETLIB_EXCEPT_LIB} $ENV{CETLIB_LIB}
  $ENV{CANVAS_ROOT_IO_LIB} $ENV{CANVAS_LIB}
  $ENV{GALLERY_LIB} $ENV{HEP_CONCURRENCY_LIB}
  )
set(LARSOFTOBJ_LIBDIRS $ENV{NUSIMDATA_LIB} $ENV{LARCOREOBJ_LIB} $ENV{LARDATAOBJ_LIB})
set(LARSOFT_LIBDIRS $ENV{CLHEP_LIB_DIR} $ENV{LARCOREALG_LIB} $ENV{LARDATAALG_LIB})
set(SBNDCODE_LIBDIRS $ENV{SBNDCODE_LIB})

link_directories(${GALLERY_LIBDIRS} ${LARSOFTOBJ_LIBDIRS} ${LARSOFT_LIBDIRS} ${SBNDCODE_LIBDIRS})

set(GALLERY_LIBS fhiclcpp MF_MessageLogger canvas cetlib_except cetlib gallery hep_concurrency)
set(ROOT_CORELIBS Core RIO Net Hist Graf Graf3d Gpad Tree Rint Postscript Matrix Physics MathCore Thread MultiProc pthread)
set(LARSOFTOBJ_LIBS nusimdata_SimulationBase larcoreobj_SummaryData lardataobj_RawData lardataobj_OpticalDetectorData lardataobj_RecoBase lardataobj_AnalysisBase lardataobj_MCBase lardataobj_Simulation)

set(SBNDGEOMETRY_LIBS larcorealg_Geometry)
set(SBNDDETINFO_LIBS lardataalg_DetectorInfo)

################################################################################
###  EXECUTABLE DIRECTIVES
################################################################################
add_executable(gallery_SCEcorrections gallery_SCEcorrections.cpp)
target_link_libraries(gallery_SCEcorrections
  ${ROOT_CORELIBS} ${GALLERY_LIBS} ${LARSOFTOBJ_LIBS}
  ${SBNDGEOMETRY_LIBS} # if using geometry
  ${SBNDDETINFO_LIBS}  # if using LAr properties, detector clocks or detector properties
  )
install(TARGETS gallery_SCEcorrections DESTINATION .)
