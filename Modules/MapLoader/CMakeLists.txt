file(GLOB
maploader_srcs
*.cpp
*.hpp
*/*.cpp
*/*.hpp
)

target_sources(
${EXE_NAME}
PRIVATE
${maploader_srcs}
)
