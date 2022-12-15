file(GLOB
obstacle_srcs
*.cpp
*.hpp
*/*.cpp
*/*.hpp
)

target_sources(
${EXE_NAME}
PRIVATE
${obstacle_srcs}
)
