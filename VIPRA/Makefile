
BASE_DIR = ./Base
CODE_GEN_DIR = ${BASE_DIR}/code_generation

release:
	make build DEBUG=-DDEBUG_MODE=OFF PROF=-DPROF_MODE=ON DIR=build

debug:
	make build DEBUG=-DDEBUG_MODE=ON PROF=-DPROF_MODE=ON DIR=build_debug

profiling:
	make build DEBUG=-DDEBUG_MODE=OFF PROF=-DPROF_MODE=ON DIR=build

build: start_server build_gen_main run_gen_main build_sim

start_server:
	node ../VIPRA_Launcher/server/dist/index.js -noserver -nobuild

build_gen_main:
	cmake -B ${CODE_GEN_DIR}/${DIR} ${CODE_GEN_DIR} ${DEBUG}
	cmake --build ${CODE_GEN_DIR}/${DIR}

run_gen_main:
	${CODE_GEN_DIR}/generate_main main.cpp ../VIPRA_Launcher/server/dist/configuration/modules.json -noCompReq

build_sim:
	cmake -B ${DIR} . ${DEBUG} ${PROF}
	cmake --build ${DIR} -j
	
clean:
	rm -rf build
	rm -rf build_debug
	rm -f main.cpp
	rm -f output.json
	rm -f VIPRA_SIM
	rm -f gmon.out

.PHONY:
	start_server
	set_release
	build_gen_main
	run_gen_main
	build_sim
	clean