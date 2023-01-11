file(GLOB
calm_pedestrian_loader_srcs
*.cpp
*.hpp
*/*.cpp
*/*.hpp
)

target_sources(
${PROJECT_NAME}
PRIVATE
${calm_pedestrian_loader_srcs}
)
