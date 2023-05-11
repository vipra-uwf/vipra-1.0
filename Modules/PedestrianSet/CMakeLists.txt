
file(GLOB
pedset_srcs
*.cpp
*.hpp
*/*.cpp
*/*.hpp
)

target_sources(
${PROJECT_NAME}
PRIVATE
${pedset_srcs}
)
