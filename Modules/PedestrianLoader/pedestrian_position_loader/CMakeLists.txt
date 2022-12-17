file(GLOB
pedestrian_position_loader_srcs
*.cpp
*.hpp
*/*.cpp
*/*.hpp
)

target_sources(
${PROJECT_NAME}
PRIVATE
${pedestrian_position_loader_srcs}
)
