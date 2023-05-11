file(GLOB
obstacle_srcs
*.cpp
*.hpp
*/*.cpp
*/*.hpp
)

target_sources(
${PROJECT_NAME}
PRIVATE
${obstacle_srcs}
)
