########################################################
# cmake file for building Marlin example Package
# @author Jan Engels, Desy IT
CMAKE_MINIMUM_REQUIRED(VERSION 2.6 FATAL_ERROR)
########################################################


# project name
PROJECT( RDAnalysis )


# project version
SET( ${PROJECT_NAME}_VERSION_MAJOR 0 )
SET( ${PROJECT_NAME}_VERSION_MINOR 6 )
SET( ${PROJECT_NAME}_VERSION_PATCH 1 )



### DEPENDENCIES ############################################################

FIND_PACKAGE( ILCUTIL REQUIRED COMPONENTS ILCSOFT_CMAKE_MODULES )  

# load default settings from ILCSOFT_CMAKE_MODULES
INCLUDE( ilcsoft_default_settings )    


FIND_PACKAGE( Marlin 1.0 REQUIRED ) # minimum required Marlin version
INCLUDE_DIRECTORIES( ${Marlin_INCLUDE_DIRS} )
LINK_LIBRARIES( ${Marlin_LIBRARIES} )
ADD_DEFINITIONS( ${Marlin_DEFINITIONS} )   

FIND_PACKAGE( CLHEP REQUIRED )
INCLUDE_DIRECTORIES( ${CLHEP_INCLUDE_DIRS} )
LINK_LIBRARIES( ${CLHEP_LIBRARIES} )

FIND_PACKAGE( GSL 1.12 REQUIRED )
INCLUDE_DIRECTORIES( ${GSL_INCLUDE_DIRS} )
LINK_LIBRARIES( ${GSL_LIBRARIES} )


FIND_PACKAGE( ROOT 6 COMPONENTS ROOTVecOps ROOTDataFrame REQUIRED  )
IF( ROOT_FOUND )
    INCLUDE_DIRECTORIES( ${ROOT_INCLUDE_DIRS} )
    LINK_LIBRARIES( ${ROOT_LIBRARIES} )
    ADD_DEFINITIONS( -DMARLIN_USE_ROOT )
    MESSAGE( STATUS "ROOT -- found" )
    MESSAGE( STATUS "ROOT dizhi ${ROOT_INCLUDE_DIRS}")
    MESSAGE( STATUS "ROOT dizhi ${ROOT_LIBRARIES}")
ELSE()
    MESSAGE( STATUS "ROOT -- not found" )
ENDIF()


FIND_PACKAGE( AIDA )
IF( AIDA_FOUND )
    INCLUDE_DIRECTORIES( ${AIDA_INCLUDE_DIRS} )
    LINK_LIBRARIES( ${AIDA_LIBRARIES} )
    ADD_DEFINITIONS( -DMARLIN_USE_AIDA )
    MESSAGE( STATUS "AIDA -- found" )
ELSE()
    MESSAGE( STATUS "AIDA -- not found" )
ENDIF()

find_package(podio)
IF( podio_FOUND )
  INCLUDE_DIRECTORIES(${podio_INCLUDE_DIRS})
#  INCLUDE_DIRECTORIES( /cvmfs/sw.hsf.org/spackages7/podio/0.16.2/x86_64-centos7-gcc11.2.0-opt/cbwgc/include )
  LINK_LIBRARIES( ${podio_LIBRARIES} )
   MESSAGE( STATUS "podio -- found" )
ELSE()
   MESSAGE( STATUS "podio -- not found" )
ENDIF() 

#MESSAGE(STATUS "includes-------------------------- dataframe edm4hep: ${EDM4HEP_INCLUDE_DIRS}")

#find_package(EDM4HEP 0.7.2 REQUIRED)
find_package(EDM4HEP  REQUIRED)
IF( EDM4HEP_FOUND )
   INCLUDE_DIRECTORIES( /cvmfs/sw.hsf.org/spackages7/edm4hep/0.7.2/x86_64-centos7-gcc11.2.0-opt/nfdxp/include )
#    INCLUDE_DIRECTORIES( ${EDM4HEP_INCLUDE_DIRS} )
    LINK_LIBRARIES( ${EDM4HEP_LIBRARIES} )
   # ADD_DEFINITIONS( -DMARLIN_USE_EDM4HEP )
    MESSAGE( STATUS "EDM4HEP -- found" )
ELSE()
    MESSAGE( STATUS "EDM4HEP -- not found" )
ENDIF()

find_package(FastJet 3.4.0)
IF(FastJet_FOUND)
   INCLUDE_DIRECTORIES( ${FastJet_INCLUDE_DIRS} )
#  INCLUDE_DIRECTORIES( /cvmfs/sw.hsf.org/spackages7/fastjet/3.4.0/x86_64-centos7-gcc11.2.0-opt/r4z4v/include  ) 
  LINK_LIBRARIES( ${FastJet_LIBRARIES} )
   MESSAGE( STATUS "FastJet -- found" )
ELSE()
   MESSAGE( STATUS "FastJet -- not found" )
ENDIF() 


find_package(ONNX)
IF(ONNX_FOUND)
  INCLUDE_DIRECTORIES( ${ONNX_INCLUDE_DIRS} )
   LINK_LIBRARIES( ${ONNX_LIBRARIES} )
   MESSAGE( STATUS "onnx -- found" )
ELSE()
   MESSAGE( STATUS "onnx -- not found" )
ENDIF() 

#############################################################################




### DOCUMENTATION ###########################################################

OPTION( INSTALL_DOC "Set to OFF to skip build/install Documentation" OFF )

IF( INSTALL_DOC AND EXISTS "${PROJECT_SOURCE_DIR}/doc/CMakeLists.txt" )
    ADD_SUBDIRECTORY( ./doc )
ENDIF()



### LIBRARY #################################################################

# definitions to pass to the compiler
#ADD_DEFINITIONS( "-Wall -ansi -pedantic" )
#ADD_DEFINITIONS( "-Wno-long-long" )

# include directories
INCLUDE_DIRECTORIES( ./include )
INSTALL_DIRECTORY( ./include DESTINATION . FILES_MATCHING PATTERN "*.h" )

# add library
AUX_SOURCE_DIRECTORY( ./src library_sources )
ADD_SHARED_LIBRARY( ${PROJECT_NAME} ${library_sources} )
INSTALL_SHARED_LIBRARY( ${PROJECT_NAME} DESTINATION lib )

# display some variables and write them to cache
DISPLAY_STD_VARIABLES()

# generate and install following configuration files
GENERATE_PACKAGE_CONFIGURATION_FILES( RDAnalysisConfig.cmake RDAnalysisConfigVersion.cmake RDAnalysisLibDeps.cmake )


file(GLOB sources src/*.cc)
file(GLOB headers include/*.h)
target_include_directories(RDAnalysis PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
ROOT_GENERATE_DICTIONARY(MarlinKin_dict ${headers}  MODULE RDAnalysis LINKDEF LinkDef.h)
