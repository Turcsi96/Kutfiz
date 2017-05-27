cmake_minimum_required(VERSION 3.0.0)
project(diff)

add_compile_options(-lm)

add_executable(${PROJECT_NAME} diff.c)

find_package(Gnuplot)

target_link_libraries(${PROJECT_NAME} m)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

ADD_CUSTOM_COMMAND(COMMAND ${PROJECT_NAME} 
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		OUTPUT ${CMAKE_BINARY_DIR}/adat.dat
		BYPRODUCTS ${CMAKE_BINARY_DIR}/adat.dat
		DEPENDS ${PROJECT_NAME}
		COMMENT "Generate data set")

ADD_CUSTOM_TARGET(data ALL DEPENDS ${CMAKE_BINARY_DIR}/adat.dat
)


ADD_CUSTOM_TARGET(gnu_plotting)

ADD_DEPENDENCIES(gnu_plotting data)

ADD_CUSTOM_COMMAND(
		TARGET gnu_plotting
		COMMAND ${GNUPLOT} ../plotol.p
		OUTPUTS ${randommappanev}
		DEPENDS adat.dat
	
)

include(UseLATEX.cmake)

add_latex_document(../Mastro.tex
		INPUTS ../Mastro.tex
		IMAGES build/res.png
		DEPENDS ../Mastro.tex gnu_plotting
		TARGET_NAME dok
		FORCE_PDF
		)



