
file(GLOB
  pedmodel_srcs
  *.cpp
  *.hpp
  */*.cpp
  */*.hpp
)

target_sources(
  ${EXE_NAME}
  PRIVATE
  ${pedmodel_srcs}
)
