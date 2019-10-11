cmake_minimum_required( VERSION 2.8 )
project ( EE569HW )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c99 -march=native -O3" )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR} )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )



############### dependencies ######################

include_directories( 
	${PROJECT_SOURCE_DIR}
)
add_library( HW3 SHARED
    	node_util.c
    	prune_util.c
    	slope_util.c
    	read_util.c
tsvq_util.c
tsvqe_util.c
voronoi_util.c
write_util.c
)



add_executable( tsvq tsvq.c )

target_link_libraries(tsvq 
	HW3 
)

add_executable( tsvqe tsvqe.c )
target_link_libraries(tsvqe 
	HW3 
)


add_executable( prune prune.c )
target_link_libraries(prune 
	HW3 
)

add_executable( select select.c )
target_link_libraries(select 
	HW3 
)