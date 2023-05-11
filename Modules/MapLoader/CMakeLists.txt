file(GLOB
maploader_srcs
*.cpp
*.hpp
*/*.cpp
*/*.hpp
)

target_sources(
${PROJECT_NAME}
PRIVATE
${maploader_srcs}
)
