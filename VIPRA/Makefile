
BASE_DIR = ./Base
CODE_GEN_DIR = ${BASE_DIR}/code_generation

release:
	make build DEBUG=-DDEBUG_MODE=OFF

debug:
	make build DEBUG=-DDEBUG_MODE=ON

build: start_server build_gen_main run_gen_main build_sim

start_server:
	node ../VIPRA_Launcher/server/dist/index.js -noserver -nobuild

build_gen_main:
	cmake -B ${CODE_GEN_DIR}/build ${CODE_GEN_DIR} ${DEBUG}
	cmake --build ${CODE_GEN_DIR}/build

run_gen_main:
	${CODE_GEN_DIR}/generate_main main.cpp ../VIPRA_Launcher/server/dist/configuration/modules.json -noCompReq

build_sim:
	cmake -B build . ${DEBUG}
	cmake --build build
	
clean:
	rm -rf build
	rm main.cpp
	rm output.json
	rm VIPRA_SIM


.PHONY:
	start_server
	set_release
	build_gen_main
	run_gen_main
	build_sim
	clean
